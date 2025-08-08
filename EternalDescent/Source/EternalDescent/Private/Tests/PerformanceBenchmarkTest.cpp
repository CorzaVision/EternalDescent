// PerformanceBenchmarkTest.cpp - Comprehensive performance testing for 25-room generation
#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "GridDungeonVisualizer.h"
#include "Tests/AutomationCommon.h"
#include "Engine/World.h"
#include "HAL/PlatformFilemanager.h"
#include "Misc/FileHelper.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"

#if WITH_AUTOMATION_TESTS

#include "Tests/AutomationEditorCommon.h"

// Performance Metrics Structure
struct FPerformanceMetrics
{
    double GenerationTimeMs;
    double MemoryUsedMB;
    int32 InstanceCount;
    int32 RoomCount;
    int32 GridSize;
    FString TestName;
};

// Test 1: Generation Speed Benchmark
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGenerationSpeedTest, "EternalDescent.Performance.GenerationSpeed", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::PerfFilter)

bool FGenerationSpeedTest::RunTest(const FString& Parameters)
{
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    UE_LOG(LogTemp, Warning, TEXT("PERFORMANCE TEST: GENERATION SPEED"));
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    if (!TestWorld)
    {
        AddError(TEXT("Failed to create test world"));
        return false;
    }
    
    AGridDungeonVisualizer* Visualizer = TestWorld->SpawnActor<AGridDungeonVisualizer>();
    if (!Visualizer)
    {
        AddError(TEXT("Failed to spawn GridDungeonVisualizer"));
        TestWorld->DestroyWorld(false);
        return false;
    }
    
    // Test configurations
    TArray<TPair<int32, FString>> TestConfigs = {
        {10, TEXT("Small (10x10)")},
        {20, TEXT("Medium (20x20)")},
        {30, TEXT("Standard (30x30)")},
        {35, TEXT("Expanded (35x35)")},
        {50, TEXT("Large (50x50)")},
        {75, TEXT("Very Large (75x75)")},
        {100, TEXT("Massive (100x100)")}
    };
    
    TArray<FPerformanceMetrics> Metrics;
    const int32 IterationsPerSize = 10;
    
    for (const auto& Config : TestConfigs)
    {
        int32 GridSize = Config.Key;
        FString SizeName = Config.Value;
        
        UE_LOG(LogTemp, Warning, TEXT("\nTesting %s grid..."), *SizeName);
        
        Visualizer->GridSizeX = GridSize;
        Visualizer->GridSizeY = GridSize;
        
        double TotalTime = 0.0;
        double MinTime = DBL_MAX;
        double MaxTime = 0.0;
        
        for (int32 i = 0; i < IterationsPerSize; ++i)
        {
            // Measure generation time
            double StartTime = FPlatformTime::Seconds();
            Visualizer->GenerateAndVisualizeDungeon(i * 1337);
            double EndTime = FPlatformTime::Seconds();
            
            double ElapsedMs = (EndTime - StartTime) * 1000.0;
            TotalTime += ElapsedMs;
            MinTime = FMath::Min(MinTime, ElapsedMs);
            MaxTime = FMath::Max(MaxTime, ElapsedMs);
            
            // Clear for next iteration
            Visualizer->ClearDungeon();
        }
        
        double AverageTime = TotalTime / IterationsPerSize;
        
        // Record metrics
        FPerformanceMetrics Metric;
        Metric.GenerationTimeMs = AverageTime;
        Metric.GridSize = GridSize;
        Metric.TestName = SizeName;
        Metrics.Add(Metric);
        
        UE_LOG(LogTemp, Warning, TEXT("  Average: %.2f ms"), AverageTime);
        UE_LOG(LogTemp, Warning, TEXT("  Min: %.2f ms, Max: %.2f ms"), MinTime, MaxTime);
        
        // Performance targets
        double TargetTime = 16.0; // 60 FPS target
        if (GridSize <= 35) // Standard grid sizes
        {
            if (AverageTime > TargetTime)
            {
                AddWarning(FString::Printf(TEXT("%s: %.2f ms exceeds 16ms target"), *SizeName, AverageTime));
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("  ✅ PASS: Within 60 FPS target"));
            }
        }
    }
    
    // Generate summary
    UE_LOG(LogTemp, Warning, TEXT("\n========================================"));
    UE_LOG(LogTemp, Warning, TEXT("GENERATION SPEED SUMMARY"));
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    
    for (const FPerformanceMetrics& Metric : Metrics)
    {
        UE_LOG(LogTemp, Warning, TEXT("%s: %.2f ms"), *Metric.TestName, Metric.GenerationTimeMs);
    }
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    
    // Pass if standard size (30x30) is under 16ms
    bool bPass = Metrics[2].GenerationTimeMs < 16.0;
    TestTrue(TEXT("Standard grid (30x30) should generate in under 16ms"), bPass);
    
    return bPass;
}

// Test 2: Memory Usage Benchmark
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMemoryUsageTest, "EternalDescent.Performance.MemoryUsage", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::PerfFilter)

bool FMemoryUsageTest::RunTest(const FString& Parameters)
{
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    UE_LOG(LogTemp, Warning, TEXT("PERFORMANCE TEST: MEMORY USAGE"));
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    if (!TestWorld)
    {
        AddError(TEXT("Failed to create test world"));
        return false;
    }
    
    AGridDungeonVisualizer* Visualizer = TestWorld->SpawnActor<AGridDungeonVisualizer>();
    if (!Visualizer)
    {
        AddError(TEXT("Failed to spawn GridDungeonVisualizer"));
        TestWorld->DestroyWorld(false);
        return false;
    }
    
    // Force garbage collection before test
    GEngine->ForceGarbageCollection(true);
    
    // Get baseline memory
    FPlatformMemoryStats MemStatsBefore = FPlatformMemory::GetStats();
    uint64 BaselineMemory = MemStatsBefore.UsedPhysical;
    
    // Test different grid sizes
    TArray<int32> GridSizes = {30, 35, 50, 75, 100};
    
    for (int32 GridSize : GridSizes)
    {
        Visualizer->GridSizeX = GridSize;
        Visualizer->GridSizeY = GridSize;
        
        // Generate dungeon
        Visualizer->GenerateAndVisualizeDungeon(12345);
        
        // Get memory after generation
        FPlatformMemoryStats MemStatsAfter = FPlatformMemory::GetStats();
        uint64 UsedMemory = MemStatsAfter.UsedPhysical;
        
        // Calculate memory delta
        double MemoryUsedMB = (UsedMemory - BaselineMemory) / (1024.0 * 1024.0);
        
        // Get instance counts
        int32 WallInstances = Visualizer->CubeInstances ? Visualizer->CubeInstances->GetInstanceCount() : 0;
        int32 FloorInstances = Visualizer->PlaneInstances ? Visualizer->PlaneInstances->GetInstanceCount() : 0;
        int32 TotalInstances = WallInstances + FloorInstances;
        
        // Calculate memory per instance
        double MemoryPerInstance = TotalInstances > 0 ? (MemoryUsedMB * 1024.0 * 1024.0) / TotalInstances : 0;
        
        UE_LOG(LogTemp, Warning, TEXT("\nGrid %dx%d:"), GridSize, GridSize);
        UE_LOG(LogTemp, Warning, TEXT("  Memory Used: %.2f MB"), MemoryUsedMB);
        UE_LOG(LogTemp, Warning, TEXT("  Wall Instances: %d"), WallInstances);
        UE_LOG(LogTemp, Warning, TEXT("  Floor Instances: %d"), FloorInstances);
        UE_LOG(LogTemp, Warning, TEXT("  Total Instances: %d"), TotalInstances);
        UE_LOG(LogTemp, Warning, TEXT("  Memory per Instance: %.2f bytes"), MemoryPerInstance);
        
        // Clear for next test
        Visualizer->ClearDungeon();
        GEngine->ForceGarbageCollection(true);
        
        // Reset baseline
        MemStatsBefore = FPlatformMemory::GetStats();
        BaselineMemory = MemStatsBefore.UsedPhysical;
    }
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    
    return true;
}

// Test 3: HISM Instance Performance
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FHISMPerformanceTest, "EternalDescent.Performance.HISMInstances", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::PerfFilter)

bool FHISMPerformanceTest::RunTest(const FString& Parameters)
{
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    UE_LOG(LogTemp, Warning, TEXT("PERFORMANCE TEST: HISM INSTANCE BATCHING"));
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    if (!TestWorld)
    {
        AddError(TEXT("Failed to create test world"));
        return false;
    }
    
    AGridDungeonVisualizer* Visualizer = TestWorld->SpawnActor<AGridDungeonVisualizer>();
    if (!Visualizer)
    {
        AddError(TEXT("Failed to spawn GridDungeonVisualizer"));
        TestWorld->DestroyWorld(false);
        return false;
    }
    
    // Test with different instance counts
    TArray<int32> InstanceCounts = {100, 500, 1000, 2500, 5000, 10000};
    
    for (int32 TargetInstances : InstanceCounts)
    {
        UE_LOG(LogTemp, Warning, TEXT("\nTesting %d instances..."), TargetInstances);
        
        // Calculate grid size to get approximate instance count
        int32 ApproxGridSize = FMath::Sqrt((float)TargetInstances * 2); // *2 because ~50% are walls
        Visualizer->GridSizeX = ApproxGridSize;
        Visualizer->GridSizeY = ApproxGridSize;
        
        // Measure time to add instances
        double StartTime = FPlatformTime::Seconds();
        Visualizer->GenerateAndVisualizeDungeon(99999);
        double EndTime = FPlatformTime::Seconds();
        
        double ElapsedMs = (EndTime - StartTime) * 1000.0;
        int32 ActualInstances = Visualizer->CubeInstances->GetInstanceCount();
        
        // Calculate instances per millisecond
        double InstancesPerMs = ActualInstances / ElapsedMs;
        
        UE_LOG(LogTemp, Warning, TEXT("  Time: %.2f ms"), ElapsedMs);
        UE_LOG(LogTemp, Warning, TEXT("  Actual Instances: %d"), ActualInstances);
        UE_LOG(LogTemp, Warning, TEXT("  Performance: %.0f instances/ms"), InstancesPerMs);
        
        // Test batch update performance
        double UpdateStartTime = FPlatformTime::Seconds();
        Visualizer->CubeInstances->MarkRenderStateDirty();
        double UpdateEndTime = FPlatformTime::Seconds();
        
        double UpdateTimeMs = (UpdateEndTime - UpdateStartTime) * 1000.0;
        UE_LOG(LogTemp, Warning, TEXT("  Render State Update: %.3f ms"), UpdateTimeMs);
        
        // Clear for next test
        Visualizer->ClearDungeon();
    }
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    
    return true;
}

// Test 4: Stress Test - Maximum Rooms
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FStressTestMaxRooms, "EternalDescent.Performance.StressTest", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::StressFilter)

bool FStressTestMaxRooms::RunTest(const FString& Parameters)
{
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    UE_LOG(LogTemp, Warning, TEXT("STRESS TEST: MAXIMUM PERFORMANCE"));
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    if (!TestWorld)
    {
        AddError(TEXT("Failed to create test world"));
        return false;
    }
    
    AGridDungeonVisualizer* Visualizer = TestWorld->SpawnActor<AGridDungeonVisualizer>();
    if (!Visualizer)
    {
        AddError(TEXT("Failed to spawn GridDungeonVisualizer"));
        TestWorld->DestroyWorld(false);
        return false;
    }
    
    // Stress test parameters
    const int32 NumIterations = 100;
    const int32 GridSize = 35; // Standard 25-room size
    
    Visualizer->GridSizeX = GridSize;
    Visualizer->GridSizeY = GridSize;
    
    UE_LOG(LogTemp, Warning, TEXT("Running %d iterations of 25-room generation..."), NumIterations);
    
    double TotalTime = 0.0;
    double MinTime = DBL_MAX;
    double MaxTime = 0.0;
    int32 FailureCount = 0;
    
    TArray<double> AllTimes;
    AllTimes.Reserve(NumIterations);
    
    for (int32 i = 0; i < NumIterations; ++i)
    {
        double StartTime = FPlatformTime::Seconds();
        Visualizer->GenerateAndVisualizeDungeon(i);
        double EndTime = FPlatformTime::Seconds();
        
        double ElapsedMs = (EndTime - StartTime) * 1000.0;
        AllTimes.Add(ElapsedMs);
        TotalTime += ElapsedMs;
        MinTime = FMath::Min(MinTime, ElapsedMs);
        MaxTime = FMath::Max(MaxTime, ElapsedMs);
        
        // Count rooms
        int32 RoomCount = 0;
        TArray<bool> Visited;
        Visited.SetNum(Visualizer->GridSizeX * Visualizer->GridSizeY);
        
        for (int32 Y = 0; Y < Visualizer->GridSizeY; ++Y)
        {
            for (int32 X = 0; X < Visualizer->GridSizeX; ++X)
            {
                int32 Index = Y * Visualizer->GridSizeX + X;
                if (!Visited[Index])
                {
                    FGridCell Cell = Visualizer->GetGridCell(X, Y);
                    if (Cell.CellType == EGridCellType::Floor)
                    {
                        // Simple flood fill count
                        TQueue<FIntPoint> Queue;
                        Queue.Enqueue(FIntPoint(X, Y));
                        Visited[Index] = true;
                        int32 RoomSize = 0;
                        
                        FIntPoint Current;
                        while (Queue.Dequeue(Current))
                        {
                            RoomSize++;
                            
                            TArray<FIntPoint> Neighbors = {
                                FIntPoint(Current.X + 1, Current.Y),
                                FIntPoint(Current.X - 1, Current.Y),
                                FIntPoint(Current.X, Current.Y + 1),
                                FIntPoint(Current.X, Current.Y - 1)
                            };
                            
                            for (const FIntPoint& Neighbor : Neighbors)
                            {
                                if (Visualizer->IsValidGridPosition(Neighbor.X, Neighbor.Y))
                                {
                                    int32 NeighborIndex = Neighbor.Y * Visualizer->GridSizeX + Neighbor.X;
                                    if (!Visited[NeighborIndex])
                                    {
                                        FGridCell NeighborCell = Visualizer->GetGridCell(Neighbor.X, Neighbor.Y);
                                        if (NeighborCell.CellType == EGridCellType::Floor)
                                        {
                                            Queue.Enqueue(Neighbor);
                                            Visited[NeighborIndex] = true;
                                        }
                                    }
                                }
                            }
                        }
                        
                        if (RoomSize >= 4) RoomCount++;
                    }
                }
            }
        }
        
        if (RoomCount != 25)
        {
            FailureCount++;
            UE_LOG(LogTemp, Error, TEXT("Iteration %d: Generated %d rooms instead of 25"), i, RoomCount);
        }
        
        // Clear for next iteration
        Visualizer->ClearDungeon();
        
        // Progress report every 10 iterations
        if ((i + 1) % 10 == 0)
        {
            UE_LOG(LogTemp, Warning, TEXT("  Completed %d/%d iterations..."), i + 1, NumIterations);
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
    
    UE_LOG(LogTemp, Warning, TEXT("\n========================================"));
    UE_LOG(LogTemp, Warning, TEXT("STRESS TEST RESULTS"));
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    UE_LOG(LogTemp, Warning, TEXT("Iterations: %d"), NumIterations);
    UE_LOG(LogTemp, Warning, TEXT("Average Time: %.2f ms"), AverageTime);
    UE_LOG(LogTemp, Warning, TEXT("Min Time: %.2f ms"), MinTime);
    UE_LOG(LogTemp, Warning, TEXT("Max Time: %.2f ms"), MaxTime);
    UE_LOG(LogTemp, Warning, TEXT("Median: %.2f ms"), Median);
    UE_LOG(LogTemp, Warning, TEXT("95th Percentile: %.2f ms"), P95);
    UE_LOG(LogTemp, Warning, TEXT("99th Percentile: %.2f ms"), P99);
    UE_LOG(LogTemp, Warning, TEXT("Std Deviation: %.2f ms"), StdDev);
    UE_LOG(LogTemp, Warning, TEXT("Success Rate: %.1f%% (%d/%d)"), 
        (NumIterations - FailureCount) * 100.0f / NumIterations, 
        NumIterations - FailureCount, NumIterations);
    
    // Performance evaluation
    bool bPassAverage = AverageTime < 16.0;
    bool bPassP95 = P95 < 20.0;
    bool bPassSuccess = FailureCount == 0;
    
    UE_LOG(LogTemp, Warning, TEXT("\nPerformance Evaluation:"));
    UE_LOG(LogTemp, Warning, TEXT("  Average < 16ms: %s"), bPassAverage ? TEXT("✅ PASS") : TEXT("❌ FAIL"));
    UE_LOG(LogTemp, Warning, TEXT("  95th percentile < 20ms: %s"), bPassP95 ? TEXT("✅ PASS") : TEXT("❌ FAIL"));
    UE_LOG(LogTemp, Warning, TEXT("  100%% Success: %s"), bPassSuccess ? TEXT("✅ PASS") : TEXT("❌ FAIL"));
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    
    TestTrue(TEXT("Stress test should pass all criteria"), bPassAverage && bPassP95 && bPassSuccess);
    return bPassAverage && bPassP95 && bPassSuccess;
}

#endif // WITH_AUTOMATION_TESTS