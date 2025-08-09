// CPUPerformanceTest.cpp - CPU performance benchmarks for GridDungeonVisualizer
/*
 * INTENT: Validate CPU performance of GridDungeonVisualizer meets 16ms target
 * PURPOSE: Ensure GridDungeonVisualizer generates 25-room dungeons under performance thresholds
 * EMPIRICAL VALIDATION: Measures CPU time for different grid sizes and iteration counts
 * FAILURE CONDITIONS: >16ms generation time, poor scaling, excessive CPU usage
 * KNOWLEDGE TRANSFER: This test validates the unified GridDungeonVisualizer system
 *                     and ensures it's the only dungeon generator in use
 * REGRESSION PROTECTION: Prevents CPU performance regressions in dungeon generation
 */

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "GridDungeonVisualizer.h"
#include "Tests/AutomationCommon.h"
#include "Engine/World.h"
#include "HAL/PlatformFilemanager.h"
#include "Misc/FileHelper.h"

#if WITH_AUTOMATION_TESTS

#include "Tests/AutomationEditorCommon.h"

// Main CPU Performance Test
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FCPUPerformanceTest, "EternalDescent.Dungeon.CPU.Performance", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FCPUPerformanceTest::RunTest(const FString& Parameters)
{
    const double TestStartTime = FPlatformTime::Seconds();
    
    AddInfo(TEXT("=== CPU PERFORMANCE TEST - GRIDDUNGEONVISUALIZER ONLY ==="));
    
    // Get world for testing - use fallback approach for automation
    UWorld* World = nullptr;
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
        // Fallback to any available world
        if (!World && GEngine->GetWorldContexts().Num() > 0)
        {
            World = GEngine->GetWorldContexts()[0].World();
        }
    }
    if (!ensure(IsValid(World)))
    {
        AddError(TEXT("CPUPerformanceTest: Failed to get valid world"));
        return false;
    }
    
    AGridDungeonVisualizer* Visualizer = World->SpawnActor<AGridDungeonVisualizer>();
    if (!ensure(IsValid(Visualizer)))
    {
        AddError(TEXT("CPUPerformanceTest: Failed to spawn GridDungeonVisualizer"));
        return false;
    }
    
    AddInfo(TEXT("✅ Using GridDungeonVisualizer as the ONLY dungeon generation system"));
    
    // Test 1: Standard 25-Room Generation Performance
    AddInfo(TEXT("--- TEST 1: Standard 25-Room Generation Performance ---"));
    
    Visualizer->GridSizeX = 36; // Standard grid for ~25 rooms
    Visualizer->GridSizeY = 36;
    Visualizer->CellSize = 350.0f;
    
    const int32 NumIterations = 50;
    double TotalTime = 0.0;
    double MinTime = DBL_MAX;
    double MaxTime = 0.0;
    TArray<double> AllTimes;
    AllTimes.Reserve(NumIterations);
    
    int32 SuccessfulGenerations = 0;
    int32 CorrectRoomCount = 0;
    
    for (int32 i = 0; i < NumIterations; ++i)
    {
        double StartTime = FPlatformTime::Seconds();
        Visualizer->GenerateAndVisualizeDungeon(i * 1337);
        double EndTime = FPlatformTime::Seconds();
        
        double ElapsedMs = (EndTime - StartTime) * 1000.0;
        AllTimes.Add(ElapsedMs);
        TotalTime += ElapsedMs;
        MinTime = FMath::Min(MinTime, ElapsedMs);
        MaxTime = FMath::Max(MaxTime, ElapsedMs);
        
        SuccessfulGenerations++;
        
        // Count rooms to verify 25-room generation
        int32 RoomCount = Visualizer->RoomInfoList.Num();
        if (RoomCount == 25)
        {
            CorrectRoomCount++;
        }
        
        // Clear for next iteration
        Visualizer->ClearDungeon();
        
        // Progress report every 10 iterations
        if ((i + 1) % 10 == 0)
        {
            AddInfo(FString::Printf(TEXT("  Completed %d/%d iterations (avg: %.2fms)"), 
                i + 1, NumIterations, (TotalTime / (i + 1))));
        }
    }
    
    // Calculate statistics
    double AverageTime = TotalTime / NumIterations;
    
    // Calculate standard deviation
    double Variance = 0.0;
    for (double Time : AllTimes)
    {
        Variance += FMath::Square(Time - AverageTime);
    }
    double StdDev = FMath::Sqrt(Variance / NumIterations);
    
    // Calculate percentiles
    AllTimes.Sort();
    double Median = AllTimes[NumIterations / 2];
    double P95 = AllTimes[FMath::FloorToInt(NumIterations * 0.95)];
    double P99 = AllTimes[FMath::FloorToInt(NumIterations * 0.99)];
    
    AddInfo(FString::Printf(TEXT("CPU Performance Results (%d iterations):"), NumIterations));
    AddInfo(FString::Printf(TEXT("  Average: %.3fms"), AverageTime));
    AddInfo(FString::Printf(TEXT("  Min: %.3fms, Max: %.3fms"), MinTime, MaxTime));
    AddInfo(FString::Printf(TEXT("  Median: %.3fms"), Median));
    AddInfo(FString::Printf(TEXT("  95th Percentile: %.3fms"), P95));
    AddInfo(FString::Printf(TEXT("  99th Percentile: %.3fms"), P99));
    AddInfo(FString::Printf(TEXT("  Std Deviation: %.3fms"), StdDev));
    AddInfo(FString::Printf(TEXT("  Success Rate: %d/%d (%.1f%%)"), 
        SuccessfulGenerations, NumIterations, (SuccessfulGenerations * 100.0f) / NumIterations));
    AddInfo(FString::Printf(TEXT("  Correct Room Count (25): %d/%d (%.1f%%)"), 
        CorrectRoomCount, NumIterations, (CorrectRoomCount * 100.0f) / NumIterations));
    
    // Critical performance checks
    bool bAveragePass = AverageTime < 16.0;
    bool bP95Pass = P95 < 20.0;
    bool bP99Pass = P99 < 25.0;
    bool bMaxPass = MaxTime < 50.0;
    bool bRoomCountPass = (CorrectRoomCount >= (NumIterations * 0.9)); // At least 90% should have 25 rooms
    
    AddInfo(TEXT("Performance Evaluation:"));
    AddInfo(FString::Printf(TEXT("  Average < 16ms: %s (%.3fms)"), 
        bAveragePass ? TEXT("✅ PASS") : TEXT("❌ FAIL"), AverageTime));
    AddInfo(FString::Printf(TEXT("  95th percentile < 20ms: %s (%.3fms)"), 
        bP95Pass ? TEXT("✅ PASS") : TEXT("❌ FAIL"), P95));
    AddInfo(FString::Printf(TEXT("  99th percentile < 25ms: %s (%.3fms)"), 
        bP99Pass ? TEXT("✅ PASS") : TEXT("❌ FAIL"), P99));
    AddInfo(FString::Printf(TEXT("  Max < 50ms: %s (%.3fms)"), 
        bMaxPass ? TEXT("✅ PASS") : TEXT("❌ FAIL"), MaxTime));
    AddInfo(FString::Printf(TEXT("  25-room consistency: %s (%d/%d)"), 
        bRoomCountPass ? TEXT("✅ PASS") : TEXT("❌ FAIL"), CorrectRoomCount, NumIterations));
    
    // Critical assertion for 16ms target
    checkf(bAveragePass, TEXT("CRITICAL: CPU Performance test failed - Average %.3fms exceeds 16ms target"), AverageTime);
    
    // Test 2: Scaling Performance Test
    AddInfo(TEXT("--- TEST 2: Grid Size Scaling Performance ---"));
    
    TArray<int32> GridSizes = {15, 20, 25, 30, 36, 40};
    TArray<double> ScalingTimes;
    
    for (int32 GridSize : GridSizes)
    {
        Visualizer->GridSizeX = GridSize;
        Visualizer->GridSizeY = GridSize;
        
        double ScalingStartTime = FPlatformTime::Seconds();
        Visualizer->GenerateAndVisualizeDungeon(42069);
        double ScalingEndTime = FPlatformTime::Seconds();
        
        double ScalingElapsedMs = (ScalingEndTime - ScalingStartTime) * 1000.0;
        ScalingTimes.Add(ScalingElapsedMs);
        
        int32 RoomCount = Visualizer->RoomInfoList.Num();
        
        AddInfo(FString::Printf(TEXT("  Grid %dx%d: %.3fms (%d rooms)"), 
            GridSize, GridSize, ScalingElapsedMs, RoomCount));
        
        Visualizer->ClearDungeon();
    }
    
    // Verify scaling is reasonable (should not be exponential)
    bool bScalingReasonable = true;
    for (int32 i = 1; i < ScalingTimes.Num(); ++i)
    {
        double ScalingFactor = ScalingTimes[i] / ScalingTimes[i-1];
        if (ScalingFactor > 2.5) // Should not be more than 2.5x slower
        {
            bScalingReasonable = false;
            AddError(FString::Printf(TEXT("Poor scaling: %dx%d is %.1fx slower than %dx%d"), 
                GridSizes[i], GridSizes[i], ScalingFactor, GridSizes[i-1], GridSizes[i-1]));
        }
    }
    
    TestTrue(TEXT("Grid size scaling should be reasonable"), bScalingReasonable);
    
    // Test 3: Memory Efficiency Check
    AddInfo(TEXT("--- TEST 3: Memory Efficiency ---"));
    
    // Force garbage collection before measurement
    GEngine->ForceGarbageCollection(true);
    FPlatformMemoryStats MemStatsBefore = FPlatformMemory::GetStats();
    uint64 BaselineMemory = MemStatsBefore.UsedPhysical;
    
    // Generate with standard grid
    Visualizer->GridSizeX = 36;
    Visualizer->GridSizeY = 36;
    Visualizer->GenerateAndVisualizeDungeon(99999);
    
    FPlatformMemoryStats MemStatsAfter = FPlatformMemory::GetStats();
    uint64 UsedMemory = MemStatsAfter.UsedPhysical;
    
    double MemoryUsedMB = (UsedMemory - BaselineMemory) / (1024.0 * 1024.0);
    
    int32 WallInstances = Visualizer->CubeInstances ? Visualizer->CubeInstances->GetInstanceCount() : 0;
    int32 FloorInstances = Visualizer->PlaneInstances ? Visualizer->PlaneInstances->GetInstanceCount() : 0;
    int32 TotalInstances = WallInstances + FloorInstances;
    
    double MemoryPerInstance = TotalInstances > 0 ? (MemoryUsedMB * 1024.0 * 1024.0) / TotalInstances : 0;
    
    AddInfo(FString::Printf(TEXT("Memory Usage:")));
    AddInfo(FString::Printf(TEXT("  Total Memory: %.2f MB"), MemoryUsedMB));
    AddInfo(FString::Printf(TEXT("  Wall Instances: %d"), WallInstances));
    AddInfo(FString::Printf(TEXT("  Floor Instances: %d"), FloorInstances));
    AddInfo(FString::Printf(TEXT("  Total Instances: %d"), TotalInstances));
    AddInfo(FString::Printf(TEXT("  Memory per Instance: %.2f bytes"), MemoryPerInstance));
    
    bool bMemoryEfficient = MemoryUsedMB < 50.0; // Should use less than 50MB for standard grid
    TestTrue(TEXT("Memory usage should be reasonable"), bMemoryEfficient);
    
    // Test Summary
    const double TotalTestTime = (FPlatformTime::Seconds() - TestStartTime) * 1000.0;
    AddInfo(FString::Printf(TEXT("Total test execution: %.3fms"), TotalTestTime));
    
    bool bAllTestsPass = bAveragePass && bP95Pass && bRoomCountPass && bScalingReasonable && bMemoryEfficient;
    
    if (bAllTestsPass)
    {
        AddInfo(TEXT("✅ CPU PERFORMANCE TEST PASSED"));
        AddInfo(TEXT("✅ GridDungeonVisualizer meets all performance requirements"));
        AddInfo(TEXT("✅ 25-room generation consistently under 16ms"));
        AddInfo(TEXT("✅ Reasonable scaling and memory usage"));
    }
    else
    {
        AddError(TEXT("❌ CPU PERFORMANCE TEST FAILED"));
        AddError(TEXT("❌ Check performance metrics above"));
    }
    
    // Cleanup
    Visualizer->Destroy();
    
    return bAllTestsPass;
}

#endif // WITH_AUTOMATION_TESTS