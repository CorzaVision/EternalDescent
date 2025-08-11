// SnakeDungeonVisualizerTest.cpp - Test the SnakeDungeonVisualizer functionality
#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "SnakeDungeonVisualizer.h"
#include "SnakePathGenerator.h"

/**
 * Basic test to verify that SnakeDungeonVisualizer can be created and generates dungeons
 */
void TestSnakeDungeonVisualizerBasic()
{
    UE_LOG(LogTemp, Warning, TEXT("🧪 Starting SnakeDungeonVisualizer Basic Test"));
    
    // Test creating the visualizer
    UWorld* TestWorld = nullptr;
    if (GEngine && GEngine->GetWorldFromContextObjectChecked(GEngine))
    {
        TestWorld = GEngine->GetWorldFromContextObjectChecked(GEngine);
    }
    
    if (!TestWorld)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ No valid world found for testing"));
        return;
    }
    
    // Spawn the visualizer actor
    FActorSpawnParameters SpawnParams;
    SpawnParams.Name = TEXT("TestSnakeVisualizer");
    
    ASnakeDungeonVisualizer* Visualizer = TestWorld->SpawnActor<ASnakeDungeonVisualizer>(SpawnParams);
    
    if (!Visualizer)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Failed to spawn SnakeDungeonVisualizer"));
        return;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("✅ Successfully spawned SnakeDungeonVisualizer"));
    
    // Test basic property access
    Visualizer->RandomSeed = 12345;
    Visualizer->GridSizeX = 45;
    Visualizer->GridSizeY = 45;
    Visualizer->VisualizationScale = 100.0f;
    Visualizer->bVerboseLogging = true;
    
    UE_LOG(LogTemp, Warning, TEXT("✅ Successfully set visualizer properties"));
    
    // Test generation
    Visualizer->GenerateAndVisualize();
    
    // Check if generation was successful
    FSnakeGenerationResult Result = Visualizer->GetCurrentResult();
    
    if (!Result.bGenerationSuccessful)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Generation failed: %s"), *Result.FailureReason);
        Visualizer->Destroy();
        return;
    }
    
    if (Result.Rooms.Num() != 25)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Expected 25 rooms, got %d"), Result.Rooms.Num());
        Visualizer->Destroy();
        return;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("✅ Generation successful with %d rooms in %dms"), 
        Result.Rooms.Num(), Result.GenerationTimeMs);
    
    // Test regeneration with new seed
    Visualizer->RegenerateWithNewSeed();
    
    FSnakeGenerationResult NewResult = Visualizer->GetCurrentResult();
    if (NewResult.bGenerationSuccessful)
    {
        UE_LOG(LogTemp, Warning, TEXT("✅ Regeneration successful with %d rooms"), 
            NewResult.Rooms.Num());
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Regeneration failed: %s"), *NewResult.FailureReason);
    }
    
    // Test clearing visualization
    Visualizer->ClearVisualization();
    UE_LOG(LogTemp, Warning, TEXT("✅ Successfully cleared visualization"));
    
    // Clean up
    Visualizer->Destroy();
    
    UE_LOG(LogTemp, Warning, TEXT("🎉 SnakeDungeonVisualizer Basic Test COMPLETED"));
}

/**
 * Performance test to ensure visualizer meets timing requirements
 */
void TestSnakeDungeonVisualizerPerformance()
{
    UE_LOG(LogTemp, Warning, TEXT("🧪 Starting SnakeDungeonVisualizer Performance Test"));
    
    UWorld* TestWorld = nullptr;
    if (GEngine && GEngine->GetWorldFromContextObjectChecked(GEngine))
    {
        TestWorld = GEngine->GetWorldFromContextObjectChecked(GEngine);
    }
    
    if (!TestWorld)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ No valid world found for performance testing"));
        return;
    }
    
    // Test multiple generations for performance consistency
    const int32 TestIterations = 10;
    int32 SuccessfulGenerations = 0;
    double TotalGenerationTime = 0.0;
    double MaxGenerationTime = 0.0;
    double MinGenerationTime = DBL_MAX;
    
    for (int32 i = 0; i < TestIterations; ++i)
    {
        // Spawn new visualizer for each test
        FActorSpawnParameters SpawnParams;
        SpawnParams.Name = FName(*FString::Printf(TEXT("PerfTestVisualizer_%d"), i));
        
        ASnakeDungeonVisualizer* Visualizer = TestWorld->SpawnActor<ASnakeDungeonVisualizer>(SpawnParams);
        
        if (!Visualizer)
        {
            UE_LOG(LogTemp, Error, TEXT("❌ Failed to spawn visualizer for iteration %d"), i);
            continue;
        }
        
        // Set test parameters
        Visualizer->RandomSeed = i + 1000; // Different seed each time
        Visualizer->bVerboseLogging = false; // Reduce log spam
        
        // Measure generation time
        double StartTime = FPlatformTime::Seconds();
        Visualizer->GenerateAndVisualize();
        double EndTime = FPlatformTime::Seconds();
        
        double GenerationTime = (EndTime - StartTime) * 1000.0; // Convert to milliseconds
        
        FSnakeGenerationResult Result = Visualizer->GetCurrentResult();
        
        if (Result.bGenerationSuccessful)
        {
            SuccessfulGenerations++;
            TotalGenerationTime += GenerationTime;
            MaxGenerationTime = FMath::Max(MaxGenerationTime, GenerationTime);
            MinGenerationTime = FMath::Min(MinGenerationTime, GenerationTime);
            
            UE_LOG(LogTemp, Log, TEXT("Iteration %d: %dms (Backend: %dms, Rooms: %d)"), 
                i, (int32)GenerationTime, Result.GenerationTimeMs, Result.Rooms.Num());
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("❌ Iteration %d failed: %s"), i, *Result.FailureReason);
        }
        
        // Clean up
        Visualizer->Destroy();
    }
    
    // Calculate statistics
    if (SuccessfulGenerations > 0)
    {
        double AverageTime = TotalGenerationTime / SuccessfulGenerations;
        
        UE_LOG(LogTemp, Warning, TEXT("📊 PERFORMANCE RESULTS:"));
        UE_LOG(LogTemp, Warning, TEXT("   Successful Generations: %d/%d"), SuccessfulGenerations, TestIterations);
        UE_LOG(LogTemp, Warning, TEXT("   Average Time: %.1fms"), AverageTime);
        UE_LOG(LogTemp, Warning, TEXT("   Min Time: %.1fms"), MinGenerationTime);
        UE_LOG(LogTemp, Warning, TEXT("   Max Time: %.1fms"), MaxGenerationTime);
        
        // Check performance targets
        // Note: This includes both backend generation AND visualization setup
        const double TARGET_TIME_MS = 100.0; // More lenient for full visualization
        
        if (AverageTime <= TARGET_TIME_MS)
        {
            UE_LOG(LogTemp, Warning, TEXT("✅ Performance target met (%.1fms <= %.1fms)"), 
                AverageTime, TARGET_TIME_MS);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("⚠️ Performance target exceeded (%.1fms > %.1fms)"), 
                AverageTime, TARGET_TIME_MS);
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("❌ No successful generations in performance test"));
    }
    
    UE_LOG(LogTemp, Warning, TEXT("🎉 SnakeDungeonVisualizer Performance Test COMPLETED"));
}

// Console command implementations
static FAutoConsoleCommand TestSnakeVisualizerBasicCommand(
    TEXT("Test.SnakeVisualizer.Basic"),
    TEXT("Test basic SnakeDungeonVisualizer functionality"),
    FConsoleCommandDelegate::CreateStatic(TestSnakeDungeonVisualizerBasic)
);

static FAutoConsoleCommand TestSnakeVisualizerPerformanceCommand(
    TEXT("Test.SnakeVisualizer.Performance"),
    TEXT("Test SnakeDungeonVisualizer performance and timing"),
    FConsoleCommandDelegate::CreateStatic(TestSnakeDungeonVisualizerPerformance)
);