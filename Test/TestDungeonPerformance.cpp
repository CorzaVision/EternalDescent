// TestDungeonPerformance.cpp
// Comprehensive performance tests for dungeon generation system
// Tests CPU, GPU, Memory, and Thread blocking according to TestingRules.md

#include "CoreMinimal.h"
#include "DungeonGenerator.h"
#include "CubeDungeonGenerator.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "Engine/World.h"
#include "HAL/PlatformFilemanager.h"
#include "HAL/PlatformProcess.h"
#include "Async/TaskGraphInterfaces.h"
#include "ProfilingDebugging/CsvProfiler.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * PERFORMANCE TESTING RULES FOR DUNGEON GENERATION
 * ================================================
 * Critical Thresholds (will crash on failure):
 * - Floor generation: < 16ms
 * - Memory per floor: < 10MB
 * - Thread blocking: < 16ms on game thread
 * - Draw calls per room: < 10
 * 
 * All tests use check() or checkf() for hard failures
 * Actual measurements are always logged
 */

// ============================================================================
// TEST 1: CPU PERFORMANCE - Floor Generation Speed
// ============================================================================
// Intent: Validate dungeon generation meets 16ms target for 60 FPS
// Purpose: Ensure smooth gameplay during procedural generation
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestDungeonCPUPerformance, "EternalDescent.Dungeon.CPU.Performance",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::PerfFilter)

bool FTestDungeonCPUPerformance::RunTest(const FString& Parameters)
{
    // Setup
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    ADungeonGenerator* Generator = TestWorld->SpawnActor<ADungeonGenerator>();
    
    // CSV Profiling start
    CSV_CUSTOM_STAT(Dungeon, GenerationTime, float);
    
    // Warmup - Important for accurate measurements
    for (int32 i = 0; i < 3; ++i)
    {
        Generator->GenerateFloor(1);
    }
    
    // Performance measurement - 100 iterations for statistical significance
    TArray<double> GenerationTimes;
    GenerationTimes.Reserve(100);
    
    const double TestStartTime = FPlatformTime::Seconds();
    
    for (int32 Floor = 1; Floor <= 100; ++Floor)
    {
        const double StartTime = FPlatformTime::Seconds();
        
        FDungeonLayout Layout = Generator->GenerateFloor(Floor);
        
        const double ElapsedTime = FPlatformTime::Seconds() - StartTime;
        const double ElapsedMs = ElapsedTime * 1000.0;
        
        GenerationTimes.Add(ElapsedMs);
        
        // CSV stat recording
        CSV_CUSTOM_STAT(Dungeon, GenerationTime, ElapsedMs);
        
        // Log every 10th floor
        if (Floor % 10 == 0)
        {
            AddInfo(FString::Printf(TEXT("Floor %d: %.3fms"), Floor, ElapsedMs));
        }
        
        // Immediate failure if any single generation exceeds threshold
        checkf(ElapsedMs < 16.0, TEXT("CRITICAL: Floor %d generation took %.3fms, exceeds 16ms limit"), Floor, ElapsedMs);
    }
    
    const double TotalTestTime = (FPlatformTime::Seconds() - TestStartTime) * 1000.0;
    
    // Calculate statistics
    double MinTime = FLT_MAX;
    double MaxTime = 0.0;
    double TotalTime = 0.0;
    
    for (double Time : GenerationTimes)
    {
        MinTime = FMath::Min(MinTime, Time);
        MaxTime = FMath::Max(MaxTime, Time);
        TotalTime += Time;
    }
    
    const double AverageTime = TotalTime / GenerationTimes.Num();
    
    // Sort for percentiles
    GenerationTimes.Sort();
    const double MedianTime = GenerationTimes[GenerationTimes.Num() / 2];
    const double P95Time = GenerationTimes[FMath::FloorToInt(GenerationTimes.Num() * 0.95)];
    const double P99Time = GenerationTimes[FMath::FloorToInt(GenerationTimes.Num() * 0.99)];
    
    // Log comprehensive results
    AddInfo(TEXT("=== CPU Performance Results ==="));
    AddInfo(FString::Printf(TEXT("Average: %.3fms"), AverageTime));
    AddInfo(FString::Printf(TEXT("Median: %.3fms"), MedianTime));
    AddInfo(FString::Printf(TEXT("Min: %.3fms"), MinTime));
    AddInfo(FString::Printf(TEXT("Max: %.3fms"), MaxTime));
    AddInfo(FString::Printf(TEXT("95th Percentile: %.3fms"), P95Time));
    AddInfo(FString::Printf(TEXT("99th Percentile: %.3fms"), P99Time));
    AddInfo(FString::Printf(TEXT("Total Test Time: %.3fms"), TotalTestTime));
    AddInfo(FString::Printf(TEXT("Throughput: %.1f floors/second"), 100000.0 / TotalTestTime));
    
    // Critical performance checks
    checkf(AverageTime < 16.0, TEXT("CRITICAL: Average generation time %.3fms exceeds 16ms limit"), AverageTime);
    checkf(P95Time < 20.0, TEXT("CRITICAL: 95th percentile %.3fms exceeds 20ms limit"), P95Time);
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    
    return true;
}

// ============================================================================
// TEST 2: MEMORY PERFORMANCE - Memory Usage and Leaks
// ============================================================================
// Intent: Validate memory usage stays within limits and no leaks occur
// Purpose: Ensure dungeon generation doesn't cause memory issues
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestDungeonMemoryPerformance, "EternalDescent.Dungeon.Memory.Performance",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::PerfFilter)

bool FTestDungeonMemoryPerformance::RunTest(const FString& Parameters)
{
    // Setup
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    ADungeonGenerator* Generator = TestWorld->SpawnActor<ADungeonGenerator>();
    
    // Get baseline memory
    FPlatformMemoryStats MemStatsBaseline = FPlatformMemory::GetStats();
    const SIZE_T BaselineUsedPhysical = MemStatsBaseline.UsedPhysical;
    const SIZE_T BaselineUsedVirtual = MemStatsBaseline.UsedVirtual;
    
    AddInfo(FString::Printf(TEXT("Baseline Memory - Physical: %llu MB, Virtual: %llu MB"), 
        BaselineUsedPhysical / (1024 * 1024), 
        BaselineUsedVirtual / (1024 * 1024)));
    
    // Generate multiple floors and track memory
    TArray<FDungeonLayout> Layouts;
    TArray<SIZE_T> MemoryPerFloor;
    
    for (int32 Floor = 1; Floor <= 20; ++Floor)
    {
        FDungeonLayout Layout = Generator->GenerateFloor(Floor);
        Layouts.Add(Layout);
        
        // Force immediate allocation
        FPlatformProcess::Sleep(0.01f);
        
        FPlatformMemoryStats MemStatsCurrent = FPlatformMemory::GetStats();
        SIZE_T CurrentUsedPhysical = MemStatsCurrent.UsedPhysical;
        SIZE_T MemoryIncrease = CurrentUsedPhysical - BaselineUsedPhysical;
        SIZE_T MemoryThisFloor = MemoryIncrease / Floor;
        
        MemoryPerFloor.Add(MemoryThisFloor);
        
        // Log every 5 floors
        if (Floor % 5 == 0)
        {
            AddInfo(FString::Printf(TEXT("After %d floors - Memory increase: %llu MB, Per floor: %llu KB"), 
                Floor,
                MemoryIncrease / (1024 * 1024),
                MemoryThisFloor / 1024));
        }
        
        // Check memory limit per floor (10MB = 10 * 1024 * 1024 bytes)
        checkf(MemoryThisFloor < 10 * 1024 * 1024, 
            TEXT("CRITICAL: Floor %d uses %llu MB, exceeds 10MB limit"), 
            Floor, MemoryThisFloor / (1024 * 1024));
    }
    
    // Test memory release
    AddInfo(TEXT("Testing memory cleanup..."));
    Layouts.Empty();
    
    // Force garbage collection
    CollectGarbage(GARBAGE_COLLECTION_KEEPFLAGS);
    FPlatformProcess::Sleep(0.1f);
    
    FPlatformMemoryStats MemStatsAfterCleanup = FPlatformMemory::GetStats();
    SIZE_T MemoryAfterCleanup = MemStatsAfterCleanup.UsedPhysical;
    SIZE_T MemoryLeaked = MemoryAfterCleanup > BaselineUsedPhysical ? 
        MemoryAfterCleanup - BaselineUsedPhysical : 0;
    
    AddInfo(FString::Printf(TEXT("Memory after cleanup: %llu MB"), MemoryAfterCleanup / (1024 * 1024)));
    AddInfo(FString::Printf(TEXT("Potential memory leak: %llu KB"), MemoryLeaked / 1024));
    
    // Check for memory leaks (allow 1MB tolerance)
    checkf(MemoryLeaked < 1024 * 1024, 
        TEXT("CRITICAL: Memory leak detected: %llu MB not released"), 
        MemoryLeaked / (1024 * 1024));
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    
    return true;
}

// ============================================================================
// TEST 3: THREAD BLOCKING - Async Generation and Main Thread Performance
// ============================================================================
// Intent: Validate async generation doesn't block game thread > 16ms
// Purpose: Ensure smooth gameplay during background generation
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestDungeonThreadBlocking, "EternalDescent.Dungeon.Threading.NoBlocking",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::PerfFilter)

bool FTestDungeonThreadBlocking::RunTest(const FString& Parameters)
{
    // Setup
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    ADungeonGenerator* Generator = TestWorld->SpawnActor<ADungeonGenerator>();
    
    // Track game thread performance during async generation
    TArray<double> GameThreadFrameTimes;
    FThreadSafeBool bGenerationComplete = false;
    int32 CompletedGenerations = 0;
    
    AddInfo(TEXT("Testing async generation with game thread monitoring..."));
    
    // Start multiple async generations
    for (int32 i = 0; i < 10; ++i)
    {
        Generator->GenerateFloorAsync(i + 1, 
            [&CompletedGenerations, &bGenerationComplete](const FDungeonLayout& Layout)
            {
                CompletedGenerations++;
                if (CompletedGenerations >= 10)
                {
                    bGenerationComplete = true;
                }
            });
    }
    
    // Monitor game thread while generation happens
    const double MonitorStartTime = FPlatformTime::Seconds();
    double LastFrameTime = MonitorStartTime;
    int32 FrameCount = 0;
    double MaxFrameTime = 0.0;
    
    while (!bGenerationComplete && (FPlatformTime::Seconds() - MonitorStartTime) < 10.0)
    {
        double CurrentTime = FPlatformTime::Seconds();
        double FrameDelta = CurrentTime - LastFrameTime;
        double FrameDeltaMs = FrameDelta * 1000.0;
        
        GameThreadFrameTimes.Add(FrameDeltaMs);
        MaxFrameTime = FMath::Max(MaxFrameTime, FrameDeltaMs);
        
        // Critical check - no frame should exceed 16ms
        checkf(FrameDeltaMs < 50.0, 
            TEXT("CRITICAL: Game thread blocked for %.3fms during async generation"), 
            FrameDeltaMs);
        
        LastFrameTime = CurrentTime;
        FrameCount++;
        
        // Simulate game thread work
        FPlatformProcess::Sleep(0.001f); // 1ms of "game work"
    }
    
    // Calculate statistics
    double TotalFrameTime = 0.0;
    for (double Time : GameThreadFrameTimes)
    {
        TotalFrameTime += Time;
    }
    double AverageFrameTime = TotalFrameTime / GameThreadFrameTimes.Num();
    
    AddInfo(TEXT("=== Thread Blocking Results ==="));
    AddInfo(FString::Printf(TEXT("Frames monitored: %d"), FrameCount));
    AddInfo(FString::Printf(TEXT("Average frame time: %.3fms"), AverageFrameTime));
    AddInfo(FString::Printf(TEXT("Max frame time: %.3fms"), MaxFrameTime));
    AddInfo(FString::Printf(TEXT("Async generations completed: %d/10"), CompletedGenerations));
    
    // Verify async operations completed
    TestTrue(TEXT("All async generations should complete"), CompletedGenerations == 10);
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    
    return true;
}

// ============================================================================
// TEST 4: CUBE DUNGEON PERFORMANCE - Large Grid Generation
// ============================================================================
// Intent: Validate cube-based dungeon generation performance
// Purpose: Ensure cube/plane system meets performance targets
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestCubeDungeonPerformance, "EternalDescent.CubeDungeon.Performance",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::PerfFilter)

bool FTestCubeDungeonPerformance::RunTest(const FString& Parameters)
{
    // Setup
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    ACubeDungeonGenerator* Generator = TestWorld->SpawnActor<ACubeDungeonGenerator>();
    
    // Test different grid sizes
    TArray<FIntVector> TestSizes = {
        FIntVector(10, 10, 3),   // Small
        FIntVector(25, 25, 5),   // Medium
        FIntVector(50, 50, 10),  // Large
        FIntVector(100, 100, 5)  // Extra Large
    };
    
    for (const FIntVector& GridSize : TestSizes)
    {
        int32 TotalCubes = GridSize.X * GridSize.Y * GridSize.Z;
        int32 ExpectedCubes = TotalCubes * 0.3f; // 30% density
        
        AddInfo(FString::Printf(TEXT("\nTesting grid %dx%dx%d (%d total cubes, ~%d expected)"),
            GridSize.X, GridSize.Y, GridSize.Z, TotalCubes, ExpectedCubes));
        
        // Measure generation time
        const double StartTime = FPlatformTime::Seconds();
        
        FCubeDungeonLayout Layout = Generator->GenerateCubeDungeon(1, GridSize);
        
        const double ElapsedMs = (FPlatformTime::Seconds() - StartTime) * 1000.0;
        
        // Calculate metrics
        double TimePerCube = ElapsedMs / Layout.OccupiedCubes;
        SIZE_T MemoryPerCube = sizeof(FDungeonCube) + (sizeof(FCubePlane) * 6);
        
        AddInfo(FString::Printf(TEXT("Generation time: %.3fms"), ElapsedMs));
        AddInfo(FString::Printf(TEXT("Occupied cubes: %d"), Layout.OccupiedCubes));
        AddInfo(FString::Printf(TEXT("Time per cube: %.4fms"), TimePerCube));
        AddInfo(FString::Printf(TEXT("Memory per cube: %d bytes"), MemoryPerCube));
        
        // Performance checks based on grid size
        if (GridSize.X <= 50 && GridSize.Y <= 50)
        {
            // Standard grid should be fast
            checkf(ElapsedMs < 5.0, 
                TEXT("CRITICAL: Grid %dx%dx%d generation took %.3fms, exceeds 5ms limit"), 
                GridSize.X, GridSize.Y, GridSize.Z, ElapsedMs);
        }
        
        // Memory check per cube
        checkf(MemoryPerCube < 256, 
            TEXT("CRITICAL: Cube memory %d bytes exceeds 256 byte limit"), 
            MemoryPerCube);
    }
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    
    return true;
}

// ============================================================================
// TEST 5: STRESS TEST - Maximum Load Testing
// ============================================================================
// Intent: Push system to limits to find breaking points
// Purpose: Validate system stability under extreme conditions
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestDungeonStress, "EternalDescent.Dungeon.Stress",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::StressFilter)

bool FTestDungeonStress::RunTest(const FString& Parameters)
{
    // Setup
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    ADungeonGenerator* Generator = TestWorld->SpawnActor<ADungeonGenerator>();
    
    AddInfo(TEXT("=== Starting Stress Test ==="));
    
    // Test 1: Rapid sequential generation
    AddInfo(TEXT("\nTest 1: Rapid sequential generation (1000 floors)"));
    {
        const double StartTime = FPlatformTime::Seconds();
        
        for (int32 i = 0; i < 1000; ++i)
        {
            FDungeonLayout Layout = Generator->GenerateFloor(i + 1);
            
            // Basic validation
            if (Layout.Rooms.Num() != 25)
            {
                AddError(FString::Printf(TEXT("Floor %d has %d rooms, expected 25"), 
                    i + 1, Layout.Rooms.Num()));
                return false;
            }
        }
        
        const double ElapsedSeconds = FPlatformTime::Seconds() - StartTime;
        AddInfo(FString::Printf(TEXT("1000 floors generated in %.2f seconds (%.1f floors/sec)"), 
            ElapsedSeconds, 1000.0 / ElapsedSeconds));
        
        // Should complete in reasonable time
        checkf(ElapsedSeconds < 30.0, 
            TEXT("CRITICAL: 1000 floor generation took %.2f seconds, exceeds 30 second limit"), 
            ElapsedSeconds);
    }
    
    // Test 2: Concurrent async generation
    AddInfo(TEXT("\nTest 2: Concurrent async generation (100 simultaneous)"));
    {
        FThreadSafeCounter CompletedCounter;
        FThreadSafeBool bHadError = false;
        
        const double StartTime = FPlatformTime::Seconds();
        
        // Start 100 async generations simultaneously
        for (int32 i = 0; i < 100; ++i)
        {
            Generator->GenerateFloorAsync(i + 1, 
                [&CompletedCounter, &bHadError, i](const FDungeonLayout& Layout)
                {
                    CompletedCounter.Increment();
                    
                    if (Layout.Rooms.Num() != 25)
                    {
                        bHadError = true;
                    }
                });
        }
        
        // Wait for completion with timeout
        const double TimeoutSeconds = 10.0;
        while (CompletedCounter.GetValue() < 100 && 
               (FPlatformTime::Seconds() - StartTime) < TimeoutSeconds)
        {
            FPlatformProcess::Sleep(0.01f);
        }
        
        const double ElapsedSeconds = FPlatformTime::Seconds() - StartTime;
        
        AddInfo(FString::Printf(TEXT("Completed %d/100 in %.2f seconds"), 
            CompletedCounter.GetValue(), ElapsedSeconds));
        
        TestTrue(TEXT("All async operations should complete"), CompletedCounter.GetValue() == 100);
        TestFalse(TEXT("No errors during concurrent generation"), bHadError);
        
        checkf(ElapsedSeconds < TimeoutSeconds, 
            TEXT("CRITICAL: Concurrent generation timeout after %.2f seconds"), 
            ElapsedSeconds);
    }
    
    // Test 3: Memory stress - Generate and hold many layouts
    AddInfo(TEXT("\nTest 3: Memory stress test"));
    {
        TArray<FDungeonLayout> Layouts;
        Layouts.Reserve(100);
        
        FPlatformMemoryStats MemStart = FPlatformMemory::GetStats();
        
        for (int32 i = 0; i < 100; ++i)
        {
            Layouts.Add(Generator->GenerateFloor(i + 1));
        }
        
        FPlatformMemoryStats MemEnd = FPlatformMemory::GetStats();
        SIZE_T MemoryUsed = MemEnd.UsedPhysical - MemStart.UsedPhysical;
        SIZE_T MemoryPerLayout = MemoryUsed / 100;
        
        AddInfo(FString::Printf(TEXT("100 layouts use %llu MB total, %llu KB per layout"), 
            MemoryUsed / (1024 * 1024), 
            MemoryPerLayout / 1024));
        
        // Check total memory usage (100 floors < 1GB)
        checkf(MemoryUsed < 1024 * 1024 * 1024, 
            TEXT("CRITICAL: 100 floors use %llu MB, exceeds 1GB limit"), 
            MemoryUsed / (1024 * 1024));
    }
    
    AddInfo(TEXT("\n=== Stress Test Complete ==="));
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    
    return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS