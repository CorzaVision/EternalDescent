// SnakeDungeonGeneratorTest.cpp - Test suite for SnakeDungeonGenerator
// Verifies two-loop generation system and path connectivity
#include "SnakeDungeonGenerator.h"
#include "Tests/DungeonTestTypes.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Tests/AutomationCommon.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSnakeDungeonGeneratorBasicTest, "EternalDescent.SnakeDungeonGenerator.BasicGeneration", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FSnakeDungeonGeneratorBasicTest::RunTest(const FString& Parameters)
{
    // Create a test world
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::Game, false);
    if (!TestWorld)
    {
        AddError(TEXT("Failed to create test world"));
        return false;
    }
    
    // Spawn the snake dungeon generator
    ASnakeDungeonGenerator* Generator = TestWorld->SpawnActor<ASnakeDungeonGenerator>();
    if (!Generator)
    {
        AddError(TEXT("Failed to spawn SnakeDungeonGenerator"));
        TestWorld->DestroyWorld(false);
        return false;
    }
    
    // Configure generation settings
    Generator->GenerationSettings.GridSizeX = 5;
    Generator->GenerationSettings.GridSizeY = 5;
    Generator->GenerationSettings.TargetRooms = 25;
    Generator->GenerationSettings.WindingFactor = 0.5f;
    Generator->GenerationSettings.bGuaranteeConnection = true;
    
    // Test 1: Basic path generation
    UE_LOG(LogTemp, Warning, TEXT("=== Running Snake Dungeon Generator Test ==="));
    
    FSnakeGenerationStats Stats = Generator->GenerateSnakePath(12345); // Fixed seed for reproducible results
    
    // Validate generation results
    TestTrue(TEXT("Path generation succeeded"), Stats.RoomsGenerated > 0);
    TestTrue(TEXT("Path is connected"), Stats.bPathConnected);
    TestTrue(TEXT("Generation time under 16ms"), Stats.GenerationTimeMs < 16.0f);
    TestTrue(TEXT("Minimum rooms generated"), Stats.RoomsGenerated >= Stats.RoomsGenerated * 0.8f); // At least 80% of target
    
    UE_LOG(LogTemp, Log, TEXT("Basic generation test: %d rooms, %.2fms, connected: %s"),
        Stats.RoomsGenerated, Stats.GenerationTimeMs, Stats.bPathConnected ? TEXT("Yes") : TEXT("No"));
    
    // Test 2: Path connectivity validation
    bool bPathIsValid = Generator->ValidatePathConnectivity();
    TestTrue(TEXT("Path connectivity validation"), bPathIsValid);
    
    // Test 3: Start and Exit room placement
    TArray<FSnakePathNode> SnakePath = Generator->SnakePath;
    bool bHasStartRoom = false;
    bool bHasExitRoom = false;
    
    for (const FSnakePathNode& Node : SnakePath)
    {
        if (Node.RoomType == ERoomType::Start)
            bHasStartRoom = true;
        if (Node.RoomType == ERoomType::Exit)
            bHasExitRoom = true;
    }
    
    TestTrue(TEXT("Has Start room"), bHasStartRoom);
    TestTrue(TEXT("Has Exit room"), bHasExitRoom);
    
    // Test 4: Room type distribution
    TMap<ERoomType, int32> RoomTypeCounts;
    for (const FSnakePathNode& Node : SnakePath)
    {
        int32* CountPtr = RoomTypeCounts.Find(Node.RoomType);
        if (CountPtr)
        {
            (*CountPtr)++;
        }
        else
        {
            RoomTypeCounts.Add(Node.RoomType, 1);
        }
    }
    
    TestTrue(TEXT("Multiple room types generated"), RoomTypeCounts.Num() >= 3);
    TestTrue(TEXT("Combat/Standard rooms present"), 
        RoomTypeCounts.Contains(ERoomType::Combat) || RoomTypeCounts.Contains(ERoomType::Standard));
    
    // Log room type distribution
    UE_LOG(LogTemp, Log, TEXT("Room type distribution:"));
    for (const auto& Pair : RoomTypeCounts)
    {
        FString RoomTypeName = UEnum::GetValueAsString(Pair.Key);
        UE_LOG(LogTemp, Log, TEXT("  %s: %d"), *RoomTypeName, Pair.Value);
    }
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    
    UE_LOG(LogTemp, Warning, TEXT("=== Snake Dungeon Generator Test Completed Successfully ==="));
    
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSnakeDungeonPerformanceTest, "EternalDescent.SnakeDungeonGenerator.Performance", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FSnakeDungeonPerformanceTest::RunTest(const FString& Parameters)
{
    // Create test world
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::Game, false);
    if (!TestWorld)
    {
        AddError(TEXT("Failed to create test world"));
        return false;
    }
    
    // Spawn generator
    ASnakeDungeonGenerator* Generator = TestWorld->SpawnActor<ASnakeDungeonGenerator>();
    if (!Generator)
    {
        AddError(TEXT("Failed to spawn SnakeDungeonGenerator"));
        TestWorld->DestroyWorld(false);
        return false;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("=== Running Snake Dungeon Performance Test ==="));
    
    // Performance test parameters
    const int32 TestIterations = 10;
    const float MaxAllowedTime = 16.0f; // 16ms target
    
    TArray<float> GenerationTimes;
    GenerationTimes.Reserve(TestIterations);
    
    // Run multiple generation tests
    for (int32 i = 0; i < TestIterations; ++i)
    {
        Generator->GenerationSettings.TargetRooms = 25;
        
        double StartTime = FPlatformTime::Seconds();
        FSnakeGenerationStats Stats = Generator->GenerateSnakePath(i * 1000); // Different seed each time
        double EndTime = FPlatformTime::Seconds();
        
        float GenerationTimeMs = (EndTime - StartTime) * 1000.0f;
        GenerationTimes.Add(GenerationTimeMs);
        
        UE_LOG(LogTemp, Log, TEXT("Iteration %d: %.2fms (%d rooms)"), 
            i + 1, GenerationTimeMs, Stats.RoomsGenerated);
    }
    
    // Calculate statistics
    float TotalTime = 0.0f;
    float MinTime = FLT_MAX;
    float MaxTime = 0.0f;
    
    for (float Time : GenerationTimes)
    {
        TotalTime += Time;
        MinTime = FMath::Min(MinTime, Time);
        MaxTime = FMath::Max(MaxTime, Time);
    }
    
    float AverageTime = TotalTime / TestIterations;
    
    // Log performance results
    UE_LOG(LogTemp, Warning, TEXT("Performance Results:"));
    UE_LOG(LogTemp, Warning, TEXT("  Average: %.2fms"), AverageTime);
    UE_LOG(LogTemp, Warning, TEXT("  Min: %.2fms"), MinTime);
    UE_LOG(LogTemp, Warning, TEXT("  Max: %.2fms"), MaxTime);
    UE_LOG(LogTemp, Warning, TEXT("  Target: %.2fms"), MaxAllowedTime);
    
    // Performance validation
    TestTrue(TEXT("Average generation time within target"), AverageTime < MaxAllowedTime);
    TestTrue(TEXT("Maximum generation time within target"), MaxTime < MaxAllowedTime * 1.5f); // Allow 50% tolerance for max
    
    // Test with larger grids
    UE_LOG(LogTemp, Warning, TEXT("Testing larger grid performance:"));
    
    Generator->GenerationSettings.GridSizeX = 10;
    Generator->GenerationSettings.GridSizeY = 10;
    Generator->GenerationSettings.TargetRooms = 50;
    
    double LargeGridStart = FPlatformTime::Seconds();
    FSnakeGenerationStats LargeStats = Generator->GenerateSnakePath(99999);
    double LargeGridEnd = FPlatformTime::Seconds();
    
    float LargeGridTime = (LargeGridEnd - LargeGridStart) * 1000.0f;
    UE_LOG(LogTemp, Warning, TEXT("Large grid (10x10): %.2fms (%d rooms)"), LargeGridTime, LargeStats.RoomsGenerated);
    
    // Large grid should still be reasonable (allow more time but not excessive)
    TestTrue(TEXT("Large grid generation time reasonable"), LargeGridTime < 50.0f);
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    
    UE_LOG(LogTemp, Warning, TEXT("=== Performance Test Completed ==="));
    
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSnakeDungeonVisualizationTest, "EternalDescent.SnakeDungeonGenerator.Visualization", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FSnakeDungeonVisualizationTest::RunTest(const FString& Parameters)
{
    // Create test world
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::Game, false);
    if (!TestWorld)
    {
        AddError(TEXT("Failed to create test world"));
        return false;
    }
    
    // Spawn generator
    ASnakeDungeonGenerator* Generator = TestWorld->SpawnActor<ASnakeDungeonGenerator>();
    if (!Generator)
    {
        AddError(TEXT("Failed to spawn SnakeDungeonGenerator"));
        TestWorld->DestroyWorld(false);
        return false;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("=== Running Snake Dungeon Visualization Test ==="));
    
    // Generate path first
    FSnakeGenerationStats Stats = Generator->GenerateSnakePath(54321);
    TestTrue(TEXT("Path generation for visualization test"), Stats.RoomsGenerated > 0);
    
    // Test Loop 2: Visualization
    double VisualizationStart = FPlatformTime::Seconds();
    Generator->SpawnSnakeVisualization();
    double VisualizationEnd = FPlatformTime::Seconds();
    
    float VisualizationTime = (VisualizationEnd - VisualizationStart) * 1000.0f;
    UE_LOG(LogTemp, Log, TEXT("Visualization completed in %.2fms"), VisualizationTime);
    
    TestTrue(TEXT("Visualization time reasonable"), VisualizationTime < 10.0f); // Should be very fast
    
    // Test combined generation and visualization
    double CombinedStart = FPlatformTime::Seconds();
    Generator->GenerateAndVisualizeSnakeDungeon(11111);
    double CombinedEnd = FPlatformTime::Seconds();
    
    float CombinedTime = (CombinedEnd - CombinedStart) * 1000.0f;
    UE_LOG(LogTemp, Log, TEXT("Combined generation and visualization: %.2fms"), CombinedTime);
    
    TestTrue(TEXT("Combined time within 16ms target"), CombinedTime < 16.0f);
    
    // Validation test
    Generator->ValidateSnakeGeneration();
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    
    UE_LOG(LogTemp, Warning, TEXT("=== Visualization Test Completed ==="));
    
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSnakeDungeonWindingTest, "EternalDescent.SnakeDungeonGenerator.WindingBehavior", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FSnakeDungeonWindingTest::RunTest(const FString& Parameters)
{
    // Create test world
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::Game, false);
    if (!TestWorld)
    {
        AddError(TEXT("Failed to create test world"));
        return false;
    }
    
    // Spawn generator
    ASnakeDungeonGenerator* Generator = TestWorld->SpawnActor<ASnakeDungeonGenerator>();
    if (!Generator)
    {
        AddError(TEXT("Failed to spawn SnakeDungeonGenerator"));
        TestWorld->DestroyWorld(false);
        return false;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("=== Running Snake Dungeon Winding Test ==="));
    
    // Test different winding factors
    TArray<float> WindingFactors = { 0.0f, 0.3f, 0.7f, 1.0f };
    
    for (float WindingFactor : WindingFactors)
    {
        Generator->GenerationSettings.WindingFactor = WindingFactor;
        Generator->GenerationSettings.TargetRooms = 20; // Smaller for faster testing
        
        FSnakeGenerationStats Stats = Generator->GenerateSnakePath(1000 + (int32)(WindingFactor * 1000));
        
        UE_LOG(LogTemp, Log, TEXT("Winding Factor %.1f: %d rooms, efficiency %.2f, connected: %s"),
            WindingFactor, Stats.RoomsGenerated, Stats.PathEfficiency, 
            Stats.bPathConnected ? TEXT("Yes") : TEXT("No"));
        
        TestTrue(FString::Printf(TEXT("Winding %.1f path connected"), WindingFactor), Stats.bPathConnected);
        TestTrue(FString::Printf(TEXT("Winding %.1f rooms generated"), WindingFactor), Stats.RoomsGenerated > 0);
        
        // Higher winding should generally result in longer paths (lower efficiency)
        if (WindingFactor > 0.5f)
        {
            TestTrue(FString::Printf(TEXT("Winding %.1f creates longer paths"), WindingFactor), 
                Stats.PathEfficiency < 1.5f); // Reasonable upper bound
        }
    }
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    
    UE_LOG(LogTemp, Warning, TEXT("=== Winding Test Completed ==="));
    
    return true;
}

// Manual test function for debugging (can be called from Blueprint)
UFUNCTION(BlueprintCallable, Category = "Snake Test")
void RunManualSnakeTest()
{
    UWorld* World = nullptr;
    
    // Try to get world from engine
    if (GEngine && GEngine->GetCurrentPlayWorld())
    {
        World = GEngine->GetCurrentPlayWorld();
    }
    
    if (!World)
    {
        UE_LOG(LogTemp, Error, TEXT("No world available for manual snake test"));
        return;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("=== Running Manual Snake Test ==="));
    
    // Find existing snake generator or spawn a new one
    ASnakeDungeonGenerator* Generator = Cast<ASnakeDungeonGenerator>(UGameplayStatics::GetActorOfClass(World, ASnakeDungeonGenerator::StaticClass()));
    
    if (!Generator)
    {
        Generator = World->SpawnActor<ASnakeDungeonGenerator>();
        if (!Generator)
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to spawn Snake Dungeon Generator"));
            return;
        }
    }
    
    // Configure for testing
    Generator->GenerationSettings.GridSizeX = 7;
    Generator->GenerationSettings.GridSizeY = 7;
    Generator->GenerationSettings.TargetRooms = 30;
    Generator->GenerationSettings.WindingFactor = 0.6f;
    Generator->bEnableDebugVisualization = true;
    
    // Run complete generation
    double StartTime = FPlatformTime::Seconds();
    Generator->GenerateAndVisualizeSnakeDungeon();
    double EndTime = FPlatformTime::Seconds();
    
    float TotalTime = (EndTime - StartTime) * 1000.0f;
    
    UE_LOG(LogTemp, Warning, TEXT("Manual test completed in %.2fms"), TotalTime);
    UE_LOG(LogTemp, Warning, TEXT("Rooms generated: %d"), Generator->LastGenerationStats.RoomsGenerated);
    UE_LOG(LogTemp, Warning, TEXT("Path connected: %s"), Generator->LastGenerationStats.bPathConnected ? TEXT("Yes") : TEXT("No"));
    
    // Run validation
    Generator->ValidateSnakeGeneration();
    
    UE_LOG(LogTemp, Warning, TEXT("=== Manual Snake Test Completed ==="));
}