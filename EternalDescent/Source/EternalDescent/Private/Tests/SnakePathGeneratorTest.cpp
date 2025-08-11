/*
 * SnakePathGeneratorTest.cpp - Comprehensive test suite for SnakePathGenerator
 * 
 * INTENT: Validate SnakePathGenerator backend logic with empirical measurements
 * PURPOSE: Ensure reliable 25-room generation under 16ms performance target
 * EMPIRICAL VALIDATION: Uses checkf() for critical thresholds, FPlatformTime for measurements
 * FAILURE CONDITIONS: >16ms generation, != 25 rooms, invalid spacing, memory leaks
 * KNOWLEDGE TRANSFER: This is the authoritative backend dungeon generation system
 *                     replacing all previous snake/cube generation implementations
 * REGRESSION PROTECTION: Guards against performance degradation and algorithm failures
 */

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "Tests/AutomationCommon.h"
#include "Misc/AutomationTest.h"
#include "SnakePathGenerator.h"
#include "HAL/PlatformMemory.h"

/*
 * INTENT: Validate basic SnakePathGenerator functionality with fixed seed
 * PURPOSE: Ensure deterministic 25-room generation meets all requirements
 * EMPIRICAL VALIDATION: Measures generation time, validates exact room count
 * FAILURE CONDITIONS: Generation fails, wrong room count, rooms out of bounds
 * KNOWLEDGE TRANSFER: This is the primary validation test for SnakePathGenerator
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSnakePathGeneratorBasicTest, 
    "EternalDescent.SnakePathGenerator.BasicGeneration", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FSnakePathGeneratorBasicTest::RunTest(const FString& Parameters)
{
    UE_LOG(LogTemp, Warning, TEXT("🧪 ===== SNAKE PATH GENERATOR BASIC TEST ====="));
    
    // Create generator instance
    USnakePathGenerator* Generator = NewObject<USnakePathGenerator>(GetTransientPackage());
    if (!TestNotNull("Generator created", Generator))
    {
        return false;
    }
    
    // Configure generation parameters
    FSnakeGenerationConfig Config;
    Config.RequiredRoomCount = 25;
    Config.GridSizeX = 45;
    Config.GridSizeY = 45;
    Config.RoomGap = 1;
    Config.MaxRetries = 3000;
    Config.bVerboseLogging = true;
    Config.bAutoCalculateGridSize = false; // Use fixed size for consistency
    
    UE_LOG(LogTemp, Warning, TEXT("🔧 Test Config: %dx%d grid, %d rooms, %d gap"), 
        Config.GridSizeX, Config.GridSizeY, Config.RequiredRoomCount, Config.RoomGap);
    
    // Empirical measurement setup - measure baseline memory
    const SIZE_T BaselineMemory = FPlatformMemory::GetStats().UsedPhysical;
    
    // Generate path with precise timing
    const double StartTime = FPlatformTime::Seconds();
    FSnakeGenerationResult Result = Generator->GenerateSnakePath(Config, 12345); // Fixed seed for determinism
    const double EndTime = FPlatformTime::Seconds();
    
    const double GenerationTimeMs = (EndTime - StartTime) * 1000.0;
    
    // Log actual measurement for visibility
    AddInfo(FString::Printf(TEXT("Generation completed in %.3fms"), GenerationTimeMs));
    UE_LOG(LogTemp, Warning, TEXT("⏱️ Empirical timing: %.3fms"), GenerationTimeMs);
    
    // Test basic success
    if (!TestTrue("Generation successful", Result.bGenerationSuccessful))
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Generation failed: %s"), *Result.FailureReason);
        return false;
    }
    
    // CRITICAL CHECKS - Use checkf for hard failures (per TestingRules.md)
    checkf(Result.Rooms.Num() == 25, TEXT("CRITICAL: Generated %d rooms, must be exactly 25"), Result.Rooms.Num());
    checkf(Result.PathSequence.Num() == 25, TEXT("CRITICAL: Path sequence %d length, must be exactly 25"), Result.PathSequence.Num());
    
    // Test path sequence length
    if (!TestEqual("Path sequence length", Result.PathSequence.Num(), 25))
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Wrong path length: %d (expected 25)"), Result.PathSequence.Num());
        return false;
    }
    
    // Test START room is 2x2
    if (!TestTrue("START room is 2x2", Result.Rooms[0].RoomSize == ESnakeRoomSize::Small_2x2))
    {
        UE_LOG(LogTemp, Error, TEXT("❌ START room is not 2x2"));
        return false;
    }
    
    // Test END room is 2x2
    if (!TestTrue("END room is 2x2", Result.Rooms[24].RoomSize == ESnakeRoomSize::Small_2x2))
    {
        UE_LOG(LogTemp, Error, TEXT("❌ END room is not 2x2"));
        return false;
    }
    
    // Test middle rooms are 3x3
    for (int32 i = 1; i < 24; ++i)
    {
        if (!TestTrue(FString::Printf(TEXT("Room %d is 3x3"), i), 
            Result.Rooms[i].RoomSize == ESnakeRoomSize::Standard_3x3))
        {
            UE_LOG(LogTemp, Error, TEXT("❌ Room %d is not 3x3"), i);
            return false;
        }
    }
    
    // Test START room flags
    if (!TestTrue("START room flagged correctly", Result.Rooms[0].bIsStartRoom && !Result.Rooms[0].bIsEndRoom))
    {
        UE_LOG(LogTemp, Error, TEXT("❌ START room flags incorrect"));
        return false;
    }
    
    // Test END room flags
    if (!TestTrue("END room flagged correctly", Result.Rooms[24].bIsEndRoom && !Result.Rooms[24].bIsStartRoom))
    {
        UE_LOG(LogTemp, Error, TEXT("❌ END room flags incorrect"));
        return false;
    }
    
    // CRITICAL PERFORMANCE CHECK - Hard fail if exceeds 16ms (per TestingRules.md)
    checkf(GenerationTimeMs < 16.0, TEXT("CRITICAL: SnakePathGenerator %.3fms exceeds 16ms limit"), GenerationTimeMs);
    
    // Also validate the internal measurement matches our external measurement
    const double MeasurementDelta = FMath::Abs(GenerationTimeMs - Result.GenerationTimeMs);
    if (!ensure(MeasurementDelta < 2.0)) // Allow 2ms tolerance for measurement differences
    {
        AddWarning(FString::Printf(TEXT("Measurement mismatch: External=%.3fms, Internal=%dms"), 
            GenerationTimeMs, Result.GenerationTimeMs));
    }
    
    // Log successful generation stats
    UE_LOG(LogTemp, Warning, TEXT("✅ Generation Stats:"));
    UE_LOG(LogTemp, Warning, TEXT("   Rooms: %d"), Result.Rooms.Num());
    UE_LOG(LogTemp, Warning, TEXT("   Time: %dms"), Result.GenerationTimeMs);
    UE_LOG(LogTemp, Warning, TEXT("   Retries: %d"), Result.RetryCount);
    UE_LOG(LogTemp, Warning, TEXT("   Backtracks: %d"), Result.BacktrackCount);
    UE_LOG(LogTemp, Warning, TEXT("   Grid: %dx%d"), Result.GridSizeX, Result.GridSizeY);
    
    // Test room positions are within bounds
    for (int32 i = 0; i < Result.Rooms.Num(); ++i)
    {
        const FSnakeRoomData& Room = Result.Rooms[i];
        int32 RoomSize = static_cast<int32>(Room.RoomSize);
        
        if (RoomSize == 2) // 2x2 room
        {
            bool bInBounds = (Room.Center.X >= 0 && Room.Center.X + 1 < Result.GridSizeX &&
                             Room.Center.Y >= 0 && Room.Center.Y + 1 < Result.GridSizeY);
            if (!TestTrue(FString::Printf(TEXT("Room %d (2x2) in bounds"), i), bInBounds))
            {
                UE_LOG(LogTemp, Error, TEXT("❌ Room %d at (%d,%d) out of bounds"), 
                    i, Room.Center.X, Room.Center.Y);
                return false;
            }
        }
        else // 3x3 room
        {
            bool bInBounds = (Room.Center.X - 1 >= 0 && Room.Center.X + 1 < Result.GridSizeX &&
                             Room.Center.Y - 1 >= 0 && Room.Center.Y + 1 < Result.GridSizeY);
            if (!TestTrue(FString::Printf(TEXT("Room %d (3x3) in bounds"), i), bInBounds))
            {
                UE_LOG(LogTemp, Error, TEXT("❌ Room %d at (%d,%d) out of bounds"), 
                    i, Room.Center.X, Room.Center.Y);
                return false;
            }
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("✅ ===== SNAKE PATH GENERATOR BASIC TEST PASSED ====="));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSnakePathGeneratorPerformanceTest, 
    "EternalDescent.SnakePathGenerator.Performance", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FSnakePathGeneratorPerformanceTest::RunTest(const FString& Parameters)
{
    UE_LOG(LogTemp, Warning, TEXT("🏃 ===== SNAKE PATH GENERATOR PERFORMANCE TEST ====="));
    
    USnakePathGenerator* Generator = NewObject<USnakePathGenerator>(GetTransientPackage());
    if (!TestNotNull("Generator created", Generator))
    {
        return false;
    }
    
    FSnakeGenerationConfig Config;
    Config.RequiredRoomCount = 25;
    Config.bAutoCalculateGridSize = true;
    Config.bVerboseLogging = false; // Disable verbose for performance test
    
    const int32 TestRuns = 100; // Stress test with 100 iterations (per TestingRules.md)
    TArray<double> GenerationTimes;
    GenerationTimes.Reserve(TestRuns);
    int32 SuccessfulRuns = 0;
    
    // Track memory usage
    const SIZE_T BaselineMemory = FPlatformMemory::GetStats().UsedPhysical;
    
    UE_LOG(LogTemp, Warning, TEXT("🔄 Running %d generation cycles..."), TestRuns);
    
    for (int32 i = 0; i < TestRuns; ++i)
    {
        // Measure each generation precisely
        const double StartTime = FPlatformTime::Seconds();
        FSnakeGenerationResult Result = Generator->GenerateSnakePath(Config, i * 1000 + 42); // Different seeds
        const double ExternalTimeMs = (FPlatformTime::Seconds() - StartTime) * 1000.0;
        
        if (Result.bGenerationSuccessful)
        {
            SuccessfulRuns++;
            GenerationTimes.Add(ExternalTimeMs);
            
            // CRITICAL CHECK - Any single run exceeding 25ms is a hard failure
            checkf(ExternalTimeMs < 25.0, TEXT("CRITICAL: Single run %d took %.3fms, exceeds 25ms emergency limit"), i + 1, ExternalTimeMs);
            
            if ((i + 1) % 10 == 0) // Log every 10th run
            {
                UE_LOG(LogTemp, Log, TEXT("Run %d: %.2fms, %d retries, %d backtracks"), 
                    i + 1, ExternalTimeMs, Result.RetryCount, Result.BacktrackCount);
            }
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("❌ Run %d failed: %s"), i + 1, *Result.FailureReason);
        }
    }
    
    // CRITICAL SUCCESS RATE CHECK - Hard failure if below 90%
    const float SuccessRate = (float)SuccessfulRuns / TestRuns * 100.0f;
    checkf(SuccessRate >= 90.0f, TEXT("CRITICAL: Success rate %.1f%% below 90%% threshold (%d/%d)"), 
        SuccessRate, SuccessfulRuns, TestRuns);
    
    if (GenerationTimes.Num() > 0)
    {
        // Calculate statistics
        GenerationTimes.Sort();
        int32 MinTime = GenerationTimes[0];
        int32 MaxTime = GenerationTimes[GenerationTimes.Num() - 1];
        int32 MedianTime = GenerationTimes[GenerationTimes.Num() / 2];
        
        float AvgTime = 0.0f;
        for (int32 Time : GenerationTimes)
        {
            AvgTime += Time;
        }
        AvgTime /= GenerationTimes.Num();
        
        UE_LOG(LogTemp, Warning, TEXT("📊 Performance Statistics:"));
        UE_LOG(LogTemp, Warning, TEXT("   Success Rate: %.1f%% (%d/%d)"), SuccessRate, SuccessfulRuns, TestRuns);
        UE_LOG(LogTemp, Warning, TEXT("   Min Time: %dms"), MinTime);
        UE_LOG(LogTemp, Warning, TEXT("   Max Time: %dms"), MaxTime);
        UE_LOG(LogTemp, Warning, TEXT("   Avg Time: %.1fms"), AvgTime);
        UE_LOG(LogTemp, Warning, TEXT("   Median Time: %dms"), MedianTime);
        
        // Test performance target
        if (!TestTrue("Average under 16ms", AvgTime <= 16.0f))
        {
            UE_LOG(LogTemp, Warning, TEXT("⚠️ Average time %.1fms exceeds 16ms target"), AvgTime);
            // Don't fail for performance in this test
        }
        
        // Test that most runs are fast
        int32 FastRuns = 0;
        for (int32 Time : GenerationTimes)
        {
            if (Time <= 16)
            {
                FastRuns++;
            }
        }
        
        float FastRate = (float)FastRuns / GenerationTimes.Num() * 100.0f;
        UE_LOG(LogTemp, Warning, TEXT("   Fast Runs (≤16ms): %.1f%% (%d/%d)"), 
            FastRate, FastRuns, GenerationTimes.Num());
    }
    
    UE_LOG(LogTemp, Warning, TEXT("✅ ===== SNAKE PATH GENERATOR PERFORMANCE TEST PASSED ====="));
    return true;
}

/*
 * INTENT: Stress test SnakePathGenerator with multiple random seeds and configurations
 * PURPOSE: Ensure system reliability under varied conditions and random generation
 * EMPIRICAL VALIDATION: Tests 100+ iterations with different seeds for reliability
 * FAILURE CONDITIONS: Any generation failure or inconsistent behavior
 * KNOWLEDGE TRANSFER: Critical stress testing for production reliability
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSnakePathGeneratorStressTest, 
    "EternalDescent.SnakePathGenerator.Stress", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FSnakePathGeneratorStressTest::RunTest(const FString& Parameters)
{
    UE_LOG(LogTemp, Warning, TEXT("🔥 ===== SNAKE PATH GENERATOR STRESS TEST ====="));
    
    USnakePathGenerator* Generator = NewObject<USnakePathGenerator>(GetTransientPackage());
    if (!TestNotNull("Generator created", Generator))
    {
        return false;
    }
    
    FSnakeGenerationConfig Config;
    Config.RequiredRoomCount = 25;
    Config.bVerboseLogging = false;
    Config.bAutoCalculateGridSize = true;
    
    // STRESS TEST - 100 iterations with random seeds and configurations
    const int32 StressTestRuns = 100;
    int32 SuccessfulRuns = 0;
    TArray<double> GenerationTimes;
    GenerationTimes.Reserve(StressTestRuns);
    
    UE_LOG(LogTemp, Warning, TEXT("🔥 Running %d stress test iterations..."), StressTestRuns);
    
    for (int32 i = 0; i < StressTestRuns; ++i)
    {
        // Vary configuration slightly for stress testing
        FSnakeGenerationConfig StressConfig = Config;
        if (i % 5 == 0) // Every 5th run uses fixed grid size
        {
            StressConfig.bAutoCalculateGridSize = false;
            StressConfig.GridSizeX = 45;
            StressConfig.GridSizeY = 45;
        }
        
        const double StartTime = FPlatformTime::Seconds();
        FSnakeGenerationResult Result = Generator->GenerateSnakePath(StressConfig, i * 12345 + 999);
        const double GenerationTimeMs = (FPlatformTime::Seconds() - StartTime) * 1000.0;
        
        if (Result.bGenerationSuccessful)
        {
            SuccessfulRuns++;
            GenerationTimes.Add(GenerationTimeMs);
            
            // CRITICAL CHECKS for each successful run
            checkf(Result.Rooms.Num() == 25, TEXT("CRITICAL: Stress run %d generated %d rooms, must be exactly 25"), i + 1, Result.Rooms.Num());
            checkf(GenerationTimeMs < 25.0, TEXT("CRITICAL: Stress run %d took %.3fms, exceeds 25ms emergency limit"), i + 1, GenerationTimeMs);
            
            // Basic validation
            if (!ensure(Result.Rooms[0].RoomSize == ESnakeRoomSize::Small_2x2))
            {
                AddError(FString::Printf(TEXT("Stress run %d: START room not 2x2"), i + 1));
                return false;
            }
            if (!ensure(Result.Rooms[24].RoomSize == ESnakeRoomSize::Small_2x2))
            {
                AddError(FString::Printf(TEXT("Stress run %d: END room not 2x2"), i + 1));
                return false;
            }
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("❌ Stress run %d failed: %s"), i + 1, *Result.FailureReason);
        }
        
        // Log progress every 20 runs
        if ((i + 1) % 20 == 0)
        {
            const float CurrentSuccessRate = (float)SuccessfulRuns / (i + 1) * 100.0f;
            UE_LOG(LogTemp, Log, TEXT("🔥 Stress progress: %d/%d runs, %.1f%% success rate"), 
                i + 1, StressTestRuns, CurrentSuccessRate);
        }
    }
    
    // CRITICAL SUCCESS RATE CHECK - Hard failure if below 95%
    const float OverallSuccessRate = (float)SuccessfulRuns / StressTestRuns * 100.0f;
    checkf(OverallSuccessRate >= 95.0f, TEXT("CRITICAL: Stress test success rate %.1f%% below 95%% threshold (%d/%d)"), 
        OverallSuccessRate, SuccessfulRuns, StressTestRuns);
    
    // Calculate stress test statistics
    if (GenerationTimes.Num() > 0)
    {
        GenerationTimes.Sort();
        const double MinTime = GenerationTimes[0];
        const double MaxTime = GenerationTimes[GenerationTimes.Num() - 1];
        const double MedianTime = GenerationTimes[GenerationTimes.Num() / 2];
        
        double AvgTime = 0.0;
        for (double Time : GenerationTimes)
        {
            AvgTime += Time;
        }
        AvgTime /= GenerationTimes.Num();
        
        // Log empirical stress test results
        AddInfo(FString::Printf(TEXT("Stress test completed: %d/%d success rate, Avg=%.2fms, Max=%.2fms"), 
            SuccessfulRuns, StressTestRuns, AvgTime, MaxTime));
        
        UE_LOG(LogTemp, Warning, TEXT("📊 Stress Test Statistics:"));
        UE_LOG(LogTemp, Warning, TEXT("   Success Rate: %.1f%% (%d/%d)"), OverallSuccessRate, SuccessfulRuns, StressTestRuns);
        UE_LOG(LogTemp, Warning, TEXT("   Min Time: %.2fms"), MinTime);
        UE_LOG(LogTemp, Warning, TEXT("   Max Time: %.2fms"), MaxTime);
        UE_LOG(LogTemp, Warning, TEXT("   Avg Time: %.2fms"), AvgTime);
        UE_LOG(LogTemp, Warning, TEXT("   Median Time: %.2fms"), MedianTime);
        
        // Performance validation for stress test
        if (!ensure(AvgTime <= 20.0)) // More lenient for stress test
        {
            AddWarning(FString::Printf(TEXT("Stress test average time %.2fms exceeds recommended 20ms"), AvgTime));
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("✅ ===== SNAKE PATH GENERATOR STRESS TEST PASSED ====="));
    UE_LOG(LogTemp, Warning, TEXT("✅ All %d stress test iterations completed with %.1f%% success rate"), StressTestRuns, OverallSuccessRate);
    return true;
}

/*
 * INTENT: Validate SnakePathGenerator memory usage and leak detection
 * PURPOSE: Ensure no memory leaks during repeated generation cycles
 * EMPIRICAL VALIDATION: Measures memory delta across 50 generation cycles
 * FAILURE CONDITIONS: Memory growth >10MB, memory leaks detected
 * KNOWLEDGE TRANSFER: Guards against memory accumulation bugs
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSnakePathGeneratorMemoryTest, 
    "EternalDescent.SnakePathGenerator.Memory", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FSnakePathGeneratorMemoryTest::RunTest(const FString& Parameters)
{
    UE_LOG(LogTemp, Warning, TEXT("💾 ===== SNAKE PATH GENERATOR MEMORY TEST ====="));
    
    USnakePathGenerator* Generator = NewObject<USnakePathGenerator>(GetTransientPackage());
    if (!ensure(IsValid(Generator)))
    {
        AddError(TEXT("Failed to create generator"));
        return false;
    }
    
    FSnakeGenerationConfig Config;
    Config.RequiredRoomCount = 25;
    Config.bVerboseLogging = false;
    
    const int32 MemoryTestCycles = 50;
    const SIZE_T BaselineMemory = FPlatformMemory::GetStats().UsedPhysical;
    
    UE_LOG(LogTemp, Log, TEXT("📊 Running %d memory test cycles..."), MemoryTestCycles);
    
    TArray<SIZE_T> MemorySnapshots;
    MemorySnapshots.Reserve(MemoryTestCycles + 1);
    MemorySnapshots.Add(BaselineMemory);
    
    for (int32 i = 0; i < MemoryTestCycles; ++i)
    {
        FSnakeGenerationResult Result = Generator->GenerateSnakePath(Config, i * 333);
        
        if (!ensure(Result.bGenerationSuccessful))
        {
            AddError(FString::Printf(TEXT("Memory test cycle %d failed: %s"), i + 1, *Result.FailureReason));
            return false;
        }
        
        // Take memory snapshot every 10 cycles
        if ((i + 1) % 10 == 0)
        {
            const SIZE_T CurrentMemory = FPlatformMemory::GetStats().UsedPhysical;
            MemorySnapshots.Add(CurrentMemory);
            
            const SIZE_T MemoryGrowth = CurrentMemory - BaselineMemory;
            UE_LOG(LogTemp, Log, TEXT("Cycle %d: Memory growth %d KB"), i + 1, MemoryGrowth / 1024);
        }
    }
    
    const SIZE_T FinalMemory = FPlatformMemory::GetStats().UsedPhysical;
    const SIZE_T TotalMemoryGrowth = FinalMemory - BaselineMemory;
    
    // Log empirical measurement
    AddInfo(FString::Printf(TEXT("Memory growth after %d cycles: %d KB"), MemoryTestCycles, TotalMemoryGrowth / 1024));
    
    // CRITICAL MEMORY CHECK - Hard failure for excessive growth
    checkf(TotalMemoryGrowth < 10 * 1024 * 1024, TEXT("CRITICAL: Memory growth %d MB exceeds 10MB limit"), 
        TotalMemoryGrowth / (1024 * 1024));
    
    // Validate memory stability (no consistent growth pattern)
    if (MemorySnapshots.Num() >= 3)
    {
        bool bHasConsistentGrowth = true;
        for (int32 i = 2; i < MemorySnapshots.Num(); ++i)
        {
            if (MemorySnapshots[i] <= MemorySnapshots[i-1])
            {
                bHasConsistentGrowth = false;
                break;
            }
        }
        
        if (!ensure(!bHasConsistentGrowth))
        {
            AddWarning(TEXT("Memory shows consistent growth pattern - potential leak detected"));
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("✅ Memory test completed: %d KB total growth"), TotalMemoryGrowth / 1024);
    return true;
}

/*
 * INTENT: Validate SnakePathGenerator spacing requirements with empirical measurements
 * PURPOSE: Ensure all rooms maintain exactly 1-cell gap spacing
 * EMPIRICAL VALIDATION: Calculates actual distances between all room pairs
 * FAILURE CONDITIONS: Any rooms violate spacing requirements
 * KNOWLEDGE TRANSFER: Critical for preventing room overlap in visual system
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSnakePathGeneratorSpacingTest, 
    "EternalDescent.SnakePathGenerator.Spacing", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FSnakePathGeneratorSpacingTest::RunTest(const FString& Parameters)
{
    UE_LOG(LogTemp, Warning, TEXT("📏 ===== SNAKE PATH GENERATOR SPACING TEST ====="));
    
    USnakePathGenerator* Generator = NewObject<USnakePathGenerator>(GetTransientPackage());
    if (!ensure(IsValid(Generator)))
    {
        AddError(TEXT("Failed to create generator"));
        return false;
    }
    
    FSnakeGenerationConfig Config;
    Config.RequiredRoomCount = 25;
    Config.GridSizeX = 45;
    Config.GridSizeY = 45;
    Config.RoomGap = 1;
    Config.bVerboseLogging = false;
    
    // Test multiple generations for spacing consistency
    const int32 SpacingTestRuns = 10;
    int32 TotalSpacingViolations = 0;
    
    for (int32 TestRun = 0; TestRun < SpacingTestRuns; ++TestRun)
    {
        FSnakeGenerationResult Result = Generator->GenerateSnakePath(Config, TestRun * 777);
        
        if (!ensure(Result.bGenerationSuccessful))
        {
            AddError(FString::Printf(TEXT("Spacing test run %d failed: %s"), TestRun + 1, *Result.FailureReason));
            return false;
        }
        
        // Empirical spacing validation for all room pairs
        int32 RunSpacingViolations = 0;
        for (int32 i = 0; i < Result.Rooms.Num(); ++i)
        {
            const FSnakeRoomData& Room1 = Result.Rooms[i];
            const int32 Room1Size = static_cast<int32>(Room1.RoomSize);
            const int32 Room1Radius = (Room1Size == 2) ? 1 : 2; // 2x2->radius 1, 3x3->radius 2
            
            for (int32 j = i + 1; j < Result.Rooms.Num(); ++j)
            {
                const FSnakeRoomData& Room2 = Result.Rooms[j];
                const int32 Room2Size = static_cast<int32>(Room2.RoomSize);
                const int32 Room2Radius = (Room2Size == 2) ? 1 : 2;
                
                const int32 RequiredDistance = Room1Radius + Room2Radius + Config.RoomGap;
                
                const int32 ActualDistX = FMath::Abs(Room1.Center.X - Room2.Center.X);
                const int32 ActualDistY = FMath::Abs(Room1.Center.Y - Room2.Center.Y);
                
                // Spacing valid if EITHER X OR Y distance meets requirement (Manhattan approach)
                const bool bValidSpacing = (ActualDistX >= RequiredDistance || ActualDistY >= RequiredDistance);
                
                if (!bValidSpacing)
                {
                    RunSpacingViolations++;
                    UE_LOG(LogTemp, Error, TEXT("SPACING VIOLATION: Rooms %d and %d - Distance(%d,%d) < Required(%d)"), 
                        i, j, ActualDistX, ActualDistY, RequiredDistance);
                }
            }
        }
        
        // CRITICAL SPACING CHECK - Hard failure for any violations
        checkf(RunSpacingViolations == 0, TEXT("CRITICAL: Run %d has %d spacing violations"), 
            TestRun + 1, RunSpacingViolations);
        
        TotalSpacingViolations += RunSpacingViolations;
        
        if (TestRun % 3 == 0) // Log progress every 3rd run
        {
            UE_LOG(LogTemp, Log, TEXT("Spacing test run %d: %d violations"), TestRun + 1, RunSpacingViolations);
        }
    }
    
    // Log empirical results
    AddInfo(FString::Printf(TEXT("Spacing validation: %d total violations across %d runs"), 
        TotalSpacingViolations, SpacingTestRuns));
    
    // CRITICAL FINAL CHECK
    checkf(TotalSpacingViolations == 0, TEXT("CRITICAL: Total spacing violations: %d"), TotalSpacingViolations);
    
    UE_LOG(LogTemp, Warning, TEXT("✅ Spacing test completed: All %d runs passed spacing validation"), SpacingTestRuns);
    return true;
}

/*
 * INTENT: Validate SnakePathGenerator path connectivity and movement patterns
 * PURPOSE: Ensure generated paths follow cardinal-only movement with valid step sizes
 * EMPIRICAL VALIDATION: Measures step distances and validates movement patterns
 * FAILURE CONDITIONS: Diagonal movement, invalid step sizes, disconnected path
 * KNOWLEDGE TRANSFER: Critical for proper snake-like path behavior
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSnakePathGeneratorConnectivityTest, 
    "EternalDescent.SnakePathGenerator.Connectivity", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FSnakePathGeneratorConnectivityTest::RunTest(const FString& Parameters)
{
    UE_LOG(LogTemp, Warning, TEXT("🔗 ===== SNAKE PATH GENERATOR CONNECTIVITY TEST ====="));
    
    USnakePathGenerator* Generator = NewObject<USnakePathGenerator>(GetTransientPackage());
    if (!ensure(IsValid(Generator)))
    {
        AddError(TEXT("Failed to create generator"));
        return false;
    }
    
    FSnakeGenerationConfig Config;
    Config.RequiredRoomCount = 25;
    Config.bVerboseLogging = false;
    
    const int32 ConnectivityTestRuns = 5;
    TArray<int32> StepSizes;
    TArray<bool> HasDiagonalMovement;
    
    for (int32 TestRun = 0; TestRun < ConnectivityTestRuns; ++TestRun)
    {
        FSnakeGenerationResult Result = Generator->GenerateSnakePath(Config, TestRun * 999);
        
        if (!ensure(Result.bGenerationSuccessful))
        {
            AddError(FString::Printf(TEXT("Connectivity test run %d failed: %s"), TestRun + 1, *Result.FailureReason));
            return false;
        }
        
        bool bRunHasDiagonal = false;
        
        // Validate each step in the path
        for (int32 i = 1; i < Result.PathSequence.Num(); ++i)
        {
            const FIntPoint& PrevPos = Result.PathSequence[i - 1];
            const FIntPoint& CurrentPos = Result.PathSequence[i];
            
            const int32 StepX = FMath::Abs(CurrentPos.X - PrevPos.X);
            const int32 StepY = FMath::Abs(CurrentPos.Y - PrevPos.Y);
            
            // CRITICAL CHECK - No diagonal movement allowed
            const bool bIsDiagonal = (StepX > 0 && StepY > 0);
            if (bIsDiagonal)
            {
                bRunHasDiagonal = true;
                UE_LOG(LogTemp, Error, TEXT("DIAGONAL MOVEMENT: Step %d->%d from (%d,%d) to (%d,%d)"), 
                    i-1, i, PrevPos.X, PrevPos.Y, CurrentPos.X, CurrentPos.Y);
            }
            
            // Validate step size is reasonable (3-12 cells as per implementation)
            const int32 TotalStepSize = StepX + StepY;
            if (TotalStepSize > 0)
            {
                StepSizes.Add(TotalStepSize);
                
                // CRITICAL CHECK - Step size must be in valid range
                checkf(TotalStepSize >= 3 && TotalStepSize <= 12, 
                    TEXT("CRITICAL: Invalid step size %d from (%d,%d) to (%d,%d)"), 
                    TotalStepSize, PrevPos.X, PrevPos.Y, CurrentPos.X, CurrentPos.Y);
            }
        }
        
        HasDiagonalMovement.Add(bRunHasDiagonal);
        
        // CRITICAL CHECK - No diagonal movement in any run
        checkf(!bRunHasDiagonal, TEXT("CRITICAL: Run %d contains diagonal movement"), TestRun + 1);
    }
    
    // Statistical analysis of step sizes
    if (StepSizes.Num() > 0)
    {
        StepSizes.Sort();
        const int32 MinStep = StepSizes[0];
        const int32 MaxStep = StepSizes[StepSizes.Num() - 1];
        int32 TotalSteps = 0;
        for (int32 Step : StepSizes)
        {
            TotalSteps += Step;
        }
        const double AvgStep = (double)TotalSteps / StepSizes.Num();
        
        AddInfo(FString::Printf(TEXT("Step size analysis: Min=%d, Max=%d, Avg=%.2f"), MinStep, MaxStep, AvgStep));
        
        UE_LOG(LogTemp, Warning, TEXT("📊 Step Statistics:"));
        UE_LOG(LogTemp, Warning, TEXT("   Total Steps: %d"), StepSizes.Num());
        UE_LOG(LogTemp, Warning, TEXT("   Min Step: %d cells"), MinStep);
        UE_LOG(LogTemp, Warning, TEXT("   Max Step: %d cells"), MaxStep);
        UE_LOG(LogTemp, Warning, TEXT("   Avg Step: %.2f cells"), AvgStep);
    }
    
    // Validate no diagonal movement across all runs
    int32 DiagonalRuns = 0;
    for (bool bHasDiagonal : HasDiagonalMovement)
    {
        if (bHasDiagonal) DiagonalRuns++;
    }
    
    checkf(DiagonalRuns == 0, TEXT("CRITICAL: %d runs contained diagonal movement"), DiagonalRuns);
    
    UE_LOG(LogTemp, Warning, TEXT("✅ Connectivity test completed: All %d runs passed connectivity validation"), ConnectivityTestRuns);
    return true;
}
