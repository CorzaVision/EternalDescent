// QuickSnakeTest.cpp - DEPRECATED - Quick validation test for SnakeDungeonGenerator
// 
// *** DEPRECATION NOTICE ***
// This file has been DEPRECATED in favor of GridDungeonVisualizer as the unified dungeon generation system.
// All functions in this file are DISABLED to prevent conflicts with the unified GridDungeonVisualizer system.
// 
// GridDungeonVisualizer is now the ONLY dungeon generation system used in EternalDescent.
// See CPUPerformanceTest.cpp and other GridDungeonVisualizer tests for current test implementations.
//
// DO NOT RE-ENABLE THESE FUNCTIONS - They will cause conflicts with the unified system.
//
/*
// Minimal test to verify basic functionality without full automation framework
#include "SnakeDungeonGenerator.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

/**
 * Quick validation function to test SnakeDungeonGenerator basic functionality
 * Can be called from Blueprint or during development
 */
// UFUNCTION(BlueprintCallable, Category = "Snake Test", CallInEditor = true)
void TestSnakeDungeonGeneratorBasic()
{
    UE_LOG(LogTemp, Warning, TEXT("=== Quick Snake Dungeon Generator Test ==="));
    
    // Try to get current world
    UWorld* World = nullptr;
    
    #if WITH_EDITOR
    // In editor, try to get the editor world
    if (GEngine && GEngine->GetWorldContexts().Num() > 0)
    {
        for (const FWorldContext& Context : GEngine->GetWorldContexts())
        {
            if (Context.World() && Context.WorldType == EWorldType::Editor)
            {
                World = Context.World();
                break;
            }
        }
    }
    #else
    // In game, get game world
    if (UGameInstance* GameInstance = UGameInstance::GetGameInstance())
    {
        World = GameInstance->GetWorld();
    }
    #endif
    
    if (!World)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ No world available for snake test"));
        return;
    }
    
    UE_LOG(LogTemp, Log, TEXT("✅ Found world for testing"));
    
    // Test 1: Class instantiation
    ASnakeDungeonGenerator* Generator = NewObject<ASnakeDungeonGenerator>();
    if (!Generator)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Failed to create SnakeDungeonGenerator object"));
        return;
    }
    
    UE_LOG(LogTemp, Log, TEXT("✅ SnakeDungeonGenerator object created"));
    
    // Test 2: Basic settings configuration
    Generator->GenerationSettings.GridSizeX = 5;
    Generator->GenerationSettings.GridSizeY = 5;
    Generator->GenerationSettings.TargetRooms = 20; // Smaller for quick test
    Generator->GenerationSettings.WindingFactor = 0.5f;
    Generator->GenerationSettings.bGuaranteeConnection = true;
    
    UE_LOG(LogTemp, Log, TEXT("✅ Generation settings configured"));
    
    // Test 3: Path generation (Loop 1)
    double StartTime = FPlatformTime::Seconds();
    FSnakeGenerationStats Stats = Generator->GenerateSnakePath(12345); // Fixed seed
    double EndTime = FPlatformTime::Seconds();
    
    float GenerationTimeMs = (EndTime - StartTime) * 1000.0f;
    
    UE_LOG(LogTemp, Warning, TEXT("Loop 1 Results:"));
    UE_LOG(LogTemp, Warning, TEXT("  Generation Time: %.2fms"), GenerationTimeMs);
    UE_LOG(LogTemp, Warning, TEXT("  Rooms Generated: %d"), Stats.RoomsGenerated);
    UE_LOG(LogTemp, Warning, TEXT("  Path Connected: %s"), Stats.bPathConnected ? TEXT("Yes") : TEXT("No"));
    UE_LOG(LogTemp, Warning, TEXT("  Path Length: %d"), Stats.PathLength);
    UE_LOG(LogTemp, Warning, TEXT("  Backtrack Count: %d"), Stats.BacktrackCount);
    
    // Validation checks
    bool bTestPassed = true;
    
    if (Stats.RoomsGenerated == 0)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ No rooms generated"));
        bTestPassed = false;
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("✅ Rooms generated successfully"));
    }
    
    if (!Stats.bPathConnected)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Path not connected"));
        bTestPassed = false;
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("✅ Path connectivity validated"));
    }
    
    if (GenerationTimeMs > 20.0f) // Allow extra tolerance for debug builds
    {
        UE_LOG(LogTemp, Warning, TEXT("⚠️ Generation time %.2fms exceeds target"), GenerationTimeMs);
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("✅ Generation time within acceptable range"));
    }
    
    // Test 4: Room type validation
    TMap<ERoomType, int32> RoomTypeCounts;
    bool bHasStartRoom = false;
    bool bHasExitRoom = false;
    
    for (const FSnakePathNode& Node : Generator->SnakePath)
    {
        // Count room types
        int32* CountPtr = RoomTypeCounts.Find(Node.RoomType);
        if (CountPtr)
        {
            (*CountPtr)++;
        }
        else
        {
            RoomTypeCounts.Add(Node.RoomType, 1);
        }
        
        // Check for required rooms
        if (Node.RoomType == ERoomType::Start) bHasStartRoom = true;
        if (Node.RoomType == ERoomType::Exit) bHasExitRoom = true;
    }
    
    if (!bHasStartRoom)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ No Start room found"));
        bTestPassed = false;
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("✅ Start room present"));
    }
    
    if (!bHasExitRoom)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ No Exit room found"));
        bTestPassed = false;
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("✅ Exit room present"));
    }
    
    // Log room distribution
    UE_LOG(LogTemp, Log, TEXT("Room Type Distribution:"));
    for (const auto& Pair : RoomTypeCounts)
    {
        FString RoomTypeName = UEnum::GetValueAsString(Pair.Key);
        UE_LOG(LogTemp, Log, TEXT("  %s: %d"), *RoomTypeName, Pair.Value);
    }
    
    // Test 5: Utility functions
    bool bUtilityTestsPassed = true;
    
    // Test grid position validation
    if (!Generator->IsValidSnakePosition(FIntVector(2, 2, 0)))
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Valid position rejected by IsValidSnakePosition"));
        bUtilityTestsPassed = false;
    }
    
    if (Generator->IsValidSnakePosition(FIntVector(-1, -1, 0)))
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Invalid position accepted by IsValidSnakePosition"));
        bUtilityTestsPassed = false;
    }
    
    if (bUtilityTestsPassed)
    {
        UE_LOG(LogTemp, Log, TEXT("✅ Utility functions working correctly"));
    }
    
    // Test 6: Path validation
    bool bPathValidationPassed = Generator->ValidatePathConnectivity();
    if (bPathValidationPassed)
    {
        UE_LOG(LogTemp, Log, TEXT("✅ Path validation successful"));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Path validation failed"));
        bTestPassed = false;
    }
    
    // Final test result
    if (bTestPassed)
    {
        UE_LOG(LogTemp, Warning, TEXT("🎉 SNAKE DUNGEON GENERATOR TEST PASSED"));
        UE_LOG(LogTemp, Warning, TEXT("Generated %d rooms in %.2fms with guaranteed connectivity"), 
            Stats.RoomsGenerated, GenerationTimeMs);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("❌ SNAKE DUNGEON GENERATOR TEST FAILED"));
    }
    
    UE_LOG(LogTemp, Warning, TEXT("=== Quick Snake Test Completed ==="));
}

/**
 * Test different winding factors
 */
UFUNCTION(BlueprintCallable, Category = "Snake Test", CallInEditor = true)
void TestSnakeWindingFactors()
{
    UE_LOG(LogTemp, Warning, TEXT("=== Testing Snake Winding Factors ==="));
    
    TArray<float> TestWindingFactors = { 0.0f, 0.3f, 0.7f, 1.0f };
    
    for (float WindingFactor : TestWindingFactors)
    {
        ASnakeDungeonGenerator* Generator = NewObject<ASnakeDungeonGenerator>();
        Generator->GenerationSettings.GridSizeX = 6;
        Generator->GenerationSettings.GridSizeY = 6;
        Generator->GenerationSettings.TargetRooms = 15;
        Generator->GenerationSettings.WindingFactor = WindingFactor;
        
        FSnakeGenerationStats Stats = Generator->GenerateSnakePath(1000 + (int32)(WindingFactor * 1000));
        
        UE_LOG(LogTemp, Warning, TEXT("Winding Factor %.1f: %d rooms, efficiency %.2f, %.2fms"), 
            WindingFactor, Stats.RoomsGenerated, Stats.PathEfficiency, Stats.GenerationTimeMs);
    }
    
    UE_LOG(LogTemp, Warning, TEXT("=== Winding Factor Test Completed ==="));
}

/**
 * Performance stress test
 */
UFUNCTION(BlueprintCallable, Category = "Snake Test", CallInEditor = true)
void TestSnakePerformance()
{
    UE_LOG(LogTemp, Warning, TEXT("=== Snake Performance Test ==="));
    
    const int32 TestIterations = 5;
    TArray<float> GenerationTimes;
    GenerationTimes.Reserve(TestIterations);
    
    for (int32 i = 0; i < TestIterations; ++i)
    {
        ASnakeDungeonGenerator* Generator = NewObject<ASnakeDungeonGenerator>();
        Generator->GenerationSettings.TargetRooms = 25;
        
        double StartTime = FPlatformTime::Seconds();
        FSnakeGenerationStats Stats = Generator->GenerateSnakePath(i * 100);
        double EndTime = FPlatformTime::Seconds();
        
        float GenerationTimeMs = (EndTime - StartTime) * 1000.0f;
        GenerationTimes.Add(GenerationTimeMs);
        
        UE_LOG(LogTemp, Log, TEXT("Run %d: %.2fms (%d rooms)"), i + 1, GenerationTimeMs, Stats.RoomsGenerated);
    }
    
    // Calculate averages
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
    
    UE_LOG(LogTemp, Warning, TEXT("Performance Results:"));
    UE_LOG(LogTemp, Warning, TEXT("  Average: %.2fms"), AverageTime);
    UE_LOG(LogTemp, Warning, TEXT("  Min: %.2fms"), MinTime);
    UE_LOG(LogTemp, Warning, TEXT("  Max: %.2fms"), MaxTime);
    UE_LOG(LogTemp, Warning, TEXT("  Target: 16.0ms"));
    
    if (AverageTime < 16.0f)
    {
        UE_LOG(LogTemp, Warning, TEXT("✅ Performance target achieved"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("⚠️ Performance target missed"));
    }
    
    UE_LOG(LogTemp, Warning, TEXT("=== Performance Test Completed ==="));
}
*/

// END OF DEPRECATED SnakeDungeonGenerator TESTS
// Use GridDungeonVisualizer tests instead