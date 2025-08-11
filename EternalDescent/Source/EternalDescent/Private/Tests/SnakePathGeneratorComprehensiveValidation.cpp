/*
 * SnakePathGeneratorComprehensiveValidation.cpp - Comprehensive validation test for SnakePathGenerator backend
 * 
 * INTENT: Provide complete empirical validation of SnakePathGenerator's core dungeon generation requirements
 * PURPOSE: Single authoritative test that validates ALL critical generation characteristics
 * EMPIRICAL VALIDATION: Measures all aspects with checkf() for critical thresholds and precise timing
 * FAILURE CONDITIONS: Any violation of: 25 rooms, diagonal movement, wrong room types, spacing violations, performance >16ms
 * KNOWLEDGE TRANSFER: This test replaces multiple smaller tests with one comprehensive validation
 *                     Ensures SnakePathGenerator backend meets ALL dungeon generation requirements
 * REGRESSION PROTECTION: Guards against any algorithmic regression in the core generation system
 */

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "Tests/AutomationCommon.h"
#include "Misc/AutomationTest.h"
#include "SnakePathGenerator.h"
#include "HAL/PlatformMemory.h"

/*
 * INTENT: Comprehensive validation of ALL SnakePathGenerator requirements in a single test
 * PURPOSE: Authoritative test that validates every critical aspect of dungeon generation
 * EMPIRICAL VALIDATION: Tests 100 generations with different seeds, measures all metrics empirically
 * FAILURE CONDITIONS: Any generation != 25 rooms, diagonal movement, wrong spacing, >16ms performance
 * KNOWLEDGE TRANSFER: This is THE test that validates SnakePathGenerator backend correctness
 *                     Success here means the backend is production-ready for dungeon generation
 * REGRESSION PROTECTION: Catches any algorithmic changes that violate core requirements
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSnakePathGeneratorComprehensiveValidationTest, 
    "EternalDescent.SnakePathGenerator.ComprehensiveValidation", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FSnakePathGeneratorComprehensiveValidationTest::RunTest(const FString& Parameters)
{
    UE_LOG(LogTemp, Warning, TEXT("🔍 ===== SNAKE PATH GENERATOR COMPREHENSIVE VALIDATION ====="));
    
    // Create generator instance
    USnakePathGenerator* Generator = NewObject<USnakePathGenerator>(GetTransientPackage());
    if (!ensure(IsValid(Generator)))
    {
        AddError(TEXT("CRITICAL: Failed to create SnakePathGenerator instance"));
        return false;
    }
    
    // Configure comprehensive test parameters
    FSnakeGenerationConfig Config;
    Config.RequiredRoomCount = 25;
    Config.GridSizeX = 45;
    Config.GridSizeY = 45;
    Config.RoomGap = 1;
    Config.MaxRetries = 3000;
    Config.bAutoCalculateGridSize = false; // Use fixed size for consistency
    Config.bVerboseLogging = false; // Keep logs clean for comprehensive test
    
    // Comprehensive testing parameters
    const int32 ValidationRuns = 100; // Test 100 different seeds for reliability
    const int32 DeterministicTestSeed = 12345; // Fixed seed for deterministic validation
    
    // Statistical tracking arrays
    TArray<double> GenerationTimes;
    TArray<int32> RetryCountHistory;
    TArray<int32> BacktrackCountHistory;
    TArray<bool> SuccessRateHistory;
    
    GenerationTimes.Reserve(ValidationRuns);
    RetryCountHistory.Reserve(ValidationRuns);
    BacktrackCountHistory.Reserve(ValidationRuns);
    SuccessRateHistory.Reserve(ValidationRuns);
    
    // Memory baseline for leak detection
    const SIZE_T BaselineMemory = FPlatformMemory::GetStats().UsedPhysical;
    
    UE_LOG(LogTemp, Warning, TEXT("🔧 Test Configuration:"));
    UE_LOG(LogTemp, Warning, TEXT("   Validation Runs: %d"), ValidationRuns);
    UE_LOG(LogTemp, Warning, TEXT("   Grid Size: %dx%d"), Config.GridSizeX, Config.GridSizeY);
    UE_LOG(LogTemp, Warning, TEXT("   Required Rooms: %d"), Config.RequiredRoomCount);
    UE_LOG(LogTemp, Warning, TEXT("   Room Gap: %d cell(s)"), Config.RoomGap);
    
    // ===== COMPREHENSIVE VALIDATION LOOP =====
    int32 SuccessfulRuns = 0;
    int32 TotalSpacingViolations = 0;
    int32 TotalDiagonalMovements = 0;
    int32 TotalRoomTypeViolations = 0;
    int32 TotalBoundaryViolations = 0;
    
    for (int32 TestRun = 0; TestRun < ValidationRuns; ++TestRun)
    {
        // Use different seed for each run to test reliability
        const int32 TestSeed = (TestRun == 0) ? DeterministicTestSeed : (TestRun * 1000 + 42);
        
        // ===== PERFORMANCE MEASUREMENT =====
        const double StartTime = FPlatformTime::Seconds();
        FSnakeGenerationResult Result = Generator->GenerateSnakePath(Config, TestSeed);
        const double EndTime = FPlatformTime::Seconds();
        
        const double GenerationTimeMs = (EndTime - StartTime) * 1000.0;
        
        // ===== CRITICAL: GENERATION SUCCESS CHECK =====
        if (!Result.bGenerationSuccessful)
        {
            SuccessRateHistory.Add(false);
            UE_LOG(LogTemp, Error, TEXT("❌ Run %d FAILED: %s"), TestRun + 1, *Result.FailureReason);
            continue; // Skip detailed validation for failed runs
        }
        
        SuccessfulRuns++;
        SuccessRateHistory.Add(true);
        GenerationTimes.Add(GenerationTimeMs);
        RetryCountHistory.Add(Result.RetryCount);
        BacktrackCountHistory.Add(Result.BacktrackCount);
        
        // ===== CRITICAL CHECK 1: EXACT 25 ROOM GENERATION =====
        checkf(Result.Rooms.Num() == 25, 
            TEXT("CRITICAL: Run %d generated %d rooms, must be EXACTLY 25"), TestRun + 1, Result.Rooms.Num());
        checkf(Result.PathSequence.Num() == 25, 
            TEXT("CRITICAL: Run %d path sequence %d length, must be EXACTLY 25"), TestRun + 1, Result.PathSequence.Num());
        
        // ===== CRITICAL CHECK 2: PERFORMANCE REQUIREMENT =====
        checkf(GenerationTimeMs < 16.0, 
            TEXT("CRITICAL: Run %d took %.3fms, exceeds 16ms performance limit"), TestRun + 1, GenerationTimeMs);
        
        // ===== VALIDATION 1: ROOM TYPES VALIDATION =====
        int32 RunRoomTypeViolations = 0;
        
        // START room must be 2x2
        if (Result.Rooms[0].RoomSize != ESnakeRoomSize::Small_2x2 || !Result.Rooms[0].bIsStartRoom)
        {
            RunRoomTypeViolations++;
            UE_LOG(LogTemp, Error, TEXT("ROOM TYPE VIOLATION: Run %d START room incorrect type or flags"), TestRun + 1);
        }
        
        // END room must be 2x2
        if (Result.Rooms[24].RoomSize != ESnakeRoomSize::Small_2x2 || !Result.Rooms[24].bIsEndRoom)
        {
            RunRoomTypeViolations++;
            UE_LOG(LogTemp, Error, TEXT("ROOM TYPE VIOLATION: Run %d END room incorrect type or flags"), TestRun + 1);
        }
        
        // Middle rooms must be 3x3
        for (int32 i = 1; i < 24; ++i)
        {
            if (Result.Rooms[i].RoomSize != ESnakeRoomSize::Standard_3x3)
            {
                RunRoomTypeViolations++;
                UE_LOG(LogTemp, Error, TEXT("ROOM TYPE VIOLATION: Run %d Room %d is not 3x3"), TestRun + 1, i);
            }
        }
        
        TotalRoomTypeViolations += RunRoomTypeViolations;
        
        // ===== VALIDATION 2: NO DIAGONAL MOVEMENT =====
        int32 RunDiagonalMovements = 0;
        
        for (int32 i = 1; i < Result.PathSequence.Num(); ++i)
        {
            const FIntPoint& PrevPos = Result.PathSequence[i - 1];
            const FIntPoint& CurrentPos = Result.PathSequence[i];
            
            const int32 StepX = FMath::Abs(CurrentPos.X - PrevPos.X);
            const int32 StepY = FMath::Abs(CurrentPos.Y - PrevPos.Y);
            
            // Check for diagonal movement (both X and Y change)
            if (StepX > 0 && StepY > 0)
            {
                RunDiagonalMovements++;
                UE_LOG(LogTemp, Error, TEXT("DIAGONAL VIOLATION: Run %d Step %d->%d from (%d,%d) to (%d,%d)"), 
                    TestRun + 1, i-1, i, PrevPos.X, PrevPos.Y, CurrentPos.X, CurrentPos.Y);
            }
            
            // Validate reasonable step sizes (3-12 cells as per implementation)
            const int32 TotalStepSize = StepX + StepY;
            if (TotalStepSize > 0)
            {
                checkf(TotalStepSize >= 3 && TotalStepSize <= 12, 
                    TEXT("CRITICAL: Run %d invalid step size %d"), TestRun + 1, TotalStepSize);
            }
        }
        
        TotalDiagonalMovements += RunDiagonalMovements;
        
        // ===== VALIDATION 3: ROOM SPACING REQUIREMENTS =====
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
                
                // Spacing valid if EITHER X OR Y distance meets requirement
                const bool bValidSpacing = (ActualDistX >= RequiredDistance || ActualDistY >= RequiredDistance);
                
                if (!bValidSpacing)
                {
                    RunSpacingViolations++;
                    UE_LOG(LogTemp, Error, TEXT("SPACING VIOLATION: Run %d Rooms %d and %d - Distance(%d,%d) < Required(%d)"), 
                        TestRun + 1, i, j, ActualDistX, ActualDistY, RequiredDistance);
                }
            }
        }
        
        TotalSpacingViolations += RunSpacingViolations;
        
        // ===== VALIDATION 4: GRID BOUNDARIES =====
        int32 RunBoundaryViolations = 0;
        
        for (int32 i = 0; i < Result.Rooms.Num(); ++i)
        {
            const FSnakeRoomData& Room = Result.Rooms[i];
            const int32 RoomSize = static_cast<int32>(Room.RoomSize);
            
            bool bInBounds = true;
            if (RoomSize == 2) // 2x2 room
            {
                bInBounds = (Room.Center.X >= 0 && Room.Center.X + 1 < Result.GridSizeX &&
                            Room.Center.Y >= 0 && Room.Center.Y + 1 < Result.GridSizeY);
            }
            else // 3x3 room
            {
                bInBounds = (Room.Center.X - 1 >= 0 && Room.Center.X + 1 < Result.GridSizeX &&
                            Room.Center.Y - 1 >= 0 && Room.Center.Y + 1 < Result.GridSizeY);
            }
            
            if (!bInBounds)
            {
                RunBoundaryViolations++;
                UE_LOG(LogTemp, Error, TEXT("BOUNDARY VIOLATION: Run %d Room %d (%dx%d) at (%d,%d) out of bounds"), 
                    TestRun + 1, i, RoomSize, RoomSize, Room.Center.X, Room.Center.Y);
            }
        }
        
        TotalBoundaryViolations += RunBoundaryViolations;
        
        // ===== VALIDATION 5: PATH CONNECTIVITY =====
        // Verify all rooms are connected via the path sequence
        if (Result.PathSequence.Num() > 0)
        {
            TSet<FIntPoint> PathPositions;
            for (const FIntPoint& PathPos : Result.PathSequence)
            {
                PathPositions.Add(PathPos);
            }
            
            // Verify all room centers are in the path
            for (int32 i = 0; i < Result.Rooms.Num(); ++i)
            {
                if (!PathPositions.Contains(Result.Rooms[i].Center))
                {
                    UE_LOG(LogTemp, Error, TEXT("CONNECTIVITY VIOLATION: Run %d Room %d center not in path"), TestRun + 1, i);
                }
            }
        }
        
        // Log progress every 25 runs
        if ((TestRun + 1) % 25 == 0)
        {
            const float CurrentSuccessRate = (float)SuccessfulRuns / (TestRun + 1) * 100.0f;
            UE_LOG(LogTemp, Log, TEXT("🔍 Validation progress: %d/%d runs, %.1f%% success rate"), 
                TestRun + 1, ValidationRuns, CurrentSuccessRate);
        }
    }
    
    // ===== CRITICAL SUCCESS RATE CHECK =====
    const float OverallSuccessRate = (float)SuccessfulRuns / ValidationRuns * 100.0f;
    checkf(OverallSuccessRate >= 98.0f, 
        TEXT("CRITICAL: Success rate %.1f%% below 98%% threshold (%d/%d)"), 
        OverallSuccessRate, SuccessfulRuns, ValidationRuns);
    
    // ===== CRITICAL VALIDATION CHECKS =====
    checkf(TotalRoomTypeViolations == 0, 
        TEXT("CRITICAL: %d room type violations across all runs"), TotalRoomTypeViolations);
    checkf(TotalDiagonalMovements == 0, 
        TEXT("CRITICAL: %d diagonal movements detected across all runs"), TotalDiagonalMovements);
    checkf(TotalSpacingViolations == 0, 
        TEXT("CRITICAL: %d spacing violations across all runs"), TotalSpacingViolations);
    checkf(TotalBoundaryViolations == 0, 
        TEXT("CRITICAL: %d boundary violations across all runs"), TotalBoundaryViolations);
    
    // ===== PERFORMANCE STATISTICS ANALYSIS =====
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
        
        // Calculate percentiles
        const double P95Time = GenerationTimes[static_cast<int32>(GenerationTimes.Num() * 0.95)];
        const double P99Time = GenerationTimes[static_cast<int32>(GenerationTimes.Num() * 0.99)];
        
        // Count fast runs (≤16ms)
        int32 FastRuns = 0;
        for (double Time : GenerationTimes)
        {
            if (Time <= 16.0) FastRuns++;
        }
        const float FastRate = (float)FastRuns / GenerationTimes.Num() * 100.0f;
        
        // Log comprehensive empirical results
        AddInfo(FString::Printf(TEXT("Comprehensive validation: %d/%d success, Avg=%.2fms, P95=%.2fms, P99=%.2fms"), 
            SuccessfulRuns, ValidationRuns, AvgTime, P95Time, P99Time));
        
        UE_LOG(LogTemp, Warning, TEXT("📊 COMPREHENSIVE VALIDATION STATISTICS:"));
        UE_LOG(LogTemp, Warning, TEXT("   Success Rate: %.1f%% (%d/%d)"), OverallSuccessRate, SuccessfulRuns, ValidationRuns);
        UE_LOG(LogTemp, Warning, TEXT("   Performance:"));
        UE_LOG(LogTemp, Warning, TEXT("     Min Time: %.2fms"), MinTime);
        UE_LOG(LogTemp, Warning, TEXT("     Avg Time: %.2fms"), AvgTime);
        UE_LOG(LogTemp, Warning, TEXT("     Median Time: %.2fms"), MedianTime);
        UE_LOG(LogTemp, Warning, TEXT("     95th Percentile: %.2fms"), P95Time);
        UE_LOG(LogTemp, Warning, TEXT("     99th Percentile: %.2fms"), P99Time);
        UE_LOG(LogTemp, Warning, TEXT("     Max Time: %.2fms"), MaxTime);
        UE_LOG(LogTemp, Warning, TEXT("     Fast Runs (≤16ms): %.1f%% (%d/%d)"), FastRate, FastRuns, GenerationTimes.Num());
        
        UE_LOG(LogTemp, Warning, TEXT("   Quality Validation:"));
        UE_LOG(LogTemp, Warning, TEXT("     Room Type Violations: %d"), TotalRoomTypeViolations);
        UE_LOG(LogTemp, Warning, TEXT("     Diagonal Movements: %d"), TotalDiagonalMovements);
        UE_LOG(LogTemp, Warning, TEXT("     Spacing Violations: %d"), TotalSpacingViolations);
        UE_LOG(LogTemp, Warning, TEXT("     Boundary Violations: %d"), TotalBoundaryViolations);
        
        // Analyze retry/backtrack statistics
        if (RetryCountHistory.Num() > 0)
        {
            RetryCountHistory.Sort();
            int32 TotalRetries = 0;
            for (int32 Retries : RetryCountHistory)
            {
                TotalRetries += Retries;
            }
            const int32 AvgRetries = TotalRetries / RetryCountHistory.Num();
            const int32 MaxRetries = RetryCountHistory[RetryCountHistory.Num() - 1];
            
            BacktrackCountHistory.Sort();
            int32 TotalBacktracks = 0;
            for (int32 Backtracks : BacktrackCountHistory)
            {
                TotalBacktracks += Backtracks;
            }
            const int32 AvgBacktracks = TotalBacktracks / BacktrackCountHistory.Num();
            const int32 MaxBacktracks = BacktrackCountHistory[BacktrackCountHistory.Num() - 1];
            
            UE_LOG(LogTemp, Warning, TEXT("   Algorithm Efficiency:"));
            UE_LOG(LogTemp, Warning, TEXT("     Avg Retries: %d (Max: %d)"), AvgRetries, MaxRetries);
            UE_LOG(LogTemp, Warning, TEXT("     Avg Backtracks: %d (Max: %d)"), AvgBacktracks, MaxBacktracks);
        }
    }
    
    // ===== DETERMINISTIC BEHAVIOR TEST =====
    UE_LOG(LogTemp, Warning, TEXT("🎯 Testing deterministic behavior..."));
    
    FSnakeGenerationResult FirstResult = Generator->GenerateSnakePath(Config, DeterministicTestSeed);
    FSnakeGenerationResult SecondResult = Generator->GenerateSnakePath(Config, DeterministicTestSeed);
    
    if (!ensure(FirstResult.bGenerationSuccessful && SecondResult.bGenerationSuccessful))
    {
        AddError(TEXT("Deterministic test generations failed"));
        return false;
    }
    
    // Verify same seed produces same layout
    bool bSameLayout = true;
    if (FirstResult.PathSequence.Num() == SecondResult.PathSequence.Num())
    {
        for (int32 i = 0; i < FirstResult.PathSequence.Num(); ++i)
        {
            if (FirstResult.PathSequence[i] != SecondResult.PathSequence[i])
            {
                bSameLayout = false;
                break;
            }
        }
    }
    else
    {
        bSameLayout = false;
    }
    
    if (!ensure(bSameLayout))
    {
        AddError(TEXT("DETERMINISTIC VIOLATION: Same seed produced different layouts"));
        return false;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("✅ Deterministic behavior verified"));
    
    // ===== MEMORY LEAK CHECK =====
    const SIZE_T FinalMemory = FPlatformMemory::GetStats().UsedPhysical;
    const SIZE_T MemoryGrowth = FinalMemory - BaselineMemory;
    
    AddInfo(FString::Printf(TEXT("Memory usage: %d KB growth after %d generations"), 
        MemoryGrowth / 1024, ValidationRuns));
    
    // Allow reasonable memory growth but catch leaks
    if (MemoryGrowth > 20 * 1024 * 1024) // 20MB threshold
    {
        AddWarning(FString::Printf(TEXT("High memory growth detected: %d MB"), MemoryGrowth / (1024 * 1024)));
    }
    
    UE_LOG(LogTemp, Warning, TEXT("✅ ===== COMPREHENSIVE VALIDATION COMPLETED ====="));
    UE_LOG(LogTemp, Warning, TEXT("✅ All validation criteria PASSED:"));
    UE_LOG(LogTemp, Warning, TEXT("✅   - %d/%d runs successful (%.1f%%)"), SuccessfulRuns, ValidationRuns, OverallSuccessRate);
    UE_LOG(LogTemp, Warning, TEXT("✅   - ALL generations produced exactly 25 rooms"));
    UE_LOG(LogTemp, Warning, TEXT("✅   - NO diagonal movement detected"));
    UE_LOG(LogTemp, Warning, TEXT("✅   - ALL room types correct (START/END 2x2, others 3x3)"));
    UE_LOG(LogTemp, Warning, TEXT("✅   - ALL spacing requirements met (1-cell gap minimum)"));
    UE_LOG(LogTemp, Warning, TEXT("✅   - ALL rooms within grid boundaries"));
    UE_LOG(LogTemp, Warning, TEXT("✅   - ALL generations under 16ms performance target"));
    UE_LOG(LogTemp, Warning, TEXT("✅   - Deterministic behavior verified"));
    UE_LOG(LogTemp, Warning, TEXT("✅ SnakePathGenerator backend is PRODUCTION READY"));
    
    return true;
}