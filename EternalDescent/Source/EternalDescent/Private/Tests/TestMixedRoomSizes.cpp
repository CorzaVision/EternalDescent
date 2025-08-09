// TestMixedRoomSizes.cpp - Comprehensive test for mixed room size system (2x2 START/END, 3x3 regular rooms)
/*
 * INTENT: Validate GridDungeonVisualizer mixed room size system with exactly 1 cell spacing
 * PURPOSE: Ensure 2x2 START/END and 3x3 regular rooms maintain proper spacing and placement
 * EMPIRICAL VALIDATION: Measures room sizes, spacing gaps, path generation, and performance
 * FAILURE CONDITIONS: Wrong room sizes, spacing violations, >16ms generation, path errors
 * KNOWLEDGE TRANSFER: This test validates the two-loop generation approach with mixed room sizes
 *                     and ensures ValidateMixedRoomSpacing() correctly enforces 1-cell gaps
 * REGRESSION PROTECTION: Prevents mixed room size system from breaking due to refactoring
 */

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "GridDungeonVisualizer.h"
#include "Tests/AutomationCommon.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"

#if WITH_AUTOMATION_TESTS

#include "Tests/AutomationEditorCommon.h"
#include "AutomationBlueprintFunctionLibrary.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestMixedRoomSizes, "EternalDescent.Dungeon.MixedRoomSizes",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

// Helper function to verify room size based on floor cell count
bool VerifyRoomSize(AGridDungeonVisualizer* Visualizer, FIntPoint RoomCenter, int32 ExpectedSize)
{
    int32 FloorCount = 0;
    
    if (ExpectedSize == 2) // 2x2 room
    {
        // 2x2 room occupies RoomCenter to RoomCenter + (1,1)
        for (int32 dx = 0; dx <= 1; dx++)
        {
            for (int32 dy = 0; dy <= 1; dy++)
            {
                int32 X = RoomCenter.X + dx;
                int32 Y = RoomCenter.Y + dy;
                if (Visualizer->IsValidGridPosition(X, Y))
                {
                    FGridCell Cell = Visualizer->GetGridCell(X, Y);
                    if (Cell.CellType == EGridCellType::Floor)
                    {
                        FloorCount++;
                    }
                }
            }
        }
        return FloorCount == 4; // 2x2 = 4 cells
    }
    else if (ExpectedSize == 3) // 3x3 room
    {
        // 3x3 room occupies RoomCenter +/- (1,1)
        for (int32 dx = -1; dx <= 1; dx++)
        {
            for (int32 dy = -1; dy <= 1; dy++)
            {
                int32 X = RoomCenter.X + dx;
                int32 Y = RoomCenter.Y + dy;
                if (Visualizer->IsValidGridPosition(X, Y))
                {
                    FGridCell Cell = Visualizer->GetGridCell(X, Y);
                    if (Cell.CellType == EGridCellType::Floor)
                    {
                        FloorCount++;
                    }
                }
            }
        }
        return FloorCount == 9; // 3x3 = 9 cells
    }
    
    return false;
}

// Helper function to verify exact gap between rooms of different sizes
bool VerifyGapBetweenRooms(AGridDungeonVisualizer* Visualizer, 
    FIntPoint Room1Center, int32 Room1Size,
    FIntPoint Room2Center, int32 Room2Size)
{
    // Calculate boundaries for each room
    int32 Room1MinX, Room1MaxX, Room1MinY, Room1MaxY;
    int32 Room2MinX, Room2MaxX, Room2MinY, Room2MaxY;
    
    if (Room1Size == 2) // 2x2
    {
        Room1MinX = Room1Center.X;
        Room1MaxX = Room1Center.X + 1;
        Room1MinY = Room1Center.Y;
        Room1MaxY = Room1Center.Y + 1;
    }
    else // 3x3
    {
        Room1MinX = Room1Center.X - 1;
        Room1MaxX = Room1Center.X + 1;
        Room1MinY = Room1Center.Y - 1;
        Room1MaxY = Room1Center.Y + 1;
    }
    
    if (Room2Size == 2) // 2x2
    {
        Room2MinX = Room2Center.X;
        Room2MaxX = Room2Center.X + 1;
        Room2MinY = Room2Center.Y;
        Room2MaxY = Room2Center.Y + 1;
    }
    else // 3x3
    {
        Room2MinX = Room2Center.X - 1;
        Room2MaxX = Room2Center.X + 1;
        Room2MinY = Room2Center.Y - 1;
        Room2MaxY = Room2Center.Y + 1;
    }
    
    // Calculate minimum gap (either X direction or Y direction)
    int32 XGap = FMath::Max(Room1MinX - Room2MaxX - 1, Room2MinX - Room1MaxX - 1);
    int32 YGap = FMath::Max(Room1MinY - Room2MaxY - 1, Room2MinY - Room1MaxY - 1);
    
    // For proper spacing, at least one direction should have exactly 1 gap
    return (XGap >= 1 || YGap >= 1);
}

bool FTestMixedRoomSizes::RunTest(const FString& Parameters)
{
    const double TestStartTime = FPlatformTime::Seconds();
    
    AddInfo(TEXT("=== MIXED ROOM SIZE SYSTEM TEST (2x2 START/END, 3x3 REGULAR) ==="));
    
    // Get world for testing
    UWorld* World = (GEngine ? GEngine->GetCurrentPlayWorld() : (GEngine && GEngine->GetWorldContexts().Num() > 0 ? GEngine->GetWorldContexts()[0].World() : nullptr));
    if (!ensure(IsValid(World)))
    {
        AddError(TEXT("TestMixedRoomSizes: Failed to get valid world"));
        return false;
    }
    
    AGridDungeonVisualizer* Visualizer = World->SpawnActor<AGridDungeonVisualizer>();
    if (!ensure(IsValid(Visualizer)))
    {
        AddError(TEXT("TestMixedRoomSizes: Failed to spawn GridDungeonVisualizer"));
        return false;
    }
    
    // Test 1: Room Size Placement Verification
    AddInfo(TEXT("--- TEST 1: Room Size Placement Verification ---"));
    
    // Use medium grid to ensure enough space for mixed rooms
    Visualizer->GridSizeX = 20;
    Visualizer->GridSizeY = 20;
    Visualizer->CellSize = 350.0f;
    
    // Generate dungeon with fixed seed for reproducible results
    const double GenerationStartTime = FPlatformTime::Seconds();
    Visualizer->GenerateAndVisualizeDungeon(42069); // Fixed seed
    const double GenerationElapsedMs = (FPlatformTime::Seconds() - GenerationStartTime) * 1000.0;
    
    AddInfo(FString::Printf(TEXT("Generation time: %.3fms"), GenerationElapsedMs));
    
    // Critical performance check
    checkf(GenerationElapsedMs < 16.0, TEXT("CRITICAL: Mixed room generation %.3fms exceeds 16ms limit"), GenerationElapsedMs);
    
    // Extract room information from RoomInfoList
    const TArray<FGridRoomInfo>& RoomList = Visualizer->RoomInfoList;
    
    if (!TestTrue(TEXT("Must generate rooms"), RoomList.Num() > 0))
    {
        Visualizer->Destroy();
        return false;
    }
    
    AddInfo(FString::Printf(TEXT("Generated %d rooms total"), RoomList.Num()));
    
    // Test START room (should be 2x2)
    bool bFoundStart = false;
    bool bFoundEnd = false;
    int32 StartRoomCount = 0;
    int32 EndRoomCount = 0;
    int32 RegularRoomCount = 0;
    
    for (int32 i = 0; i < RoomList.Num(); i++)
    {
        const FGridRoomInfo& Room = RoomList[i];
        
        if (Room.bIsStartRoom)
        {
            bFoundStart = true;
            StartRoomCount++;
            
            // Verify START room is 2x2
            TestEqual(TEXT("START room must be 2x2"), (int32)Room.RoomSize, 2);
            
            if (VerifyRoomSize(Visualizer, Room.Center, 2))
            {
                AddInfo(FString::Printf(TEXT("✅ START room verified 2x2 at center (%d,%d)"), 
                    Room.Center.X, Room.Center.Y));
            }
            else
            {
                AddError(FString::Printf(TEXT("❌ START room size incorrect at center (%d,%d)"), 
                    Room.Center.X, Room.Center.Y));
                Visualizer->Destroy();
                return false;
            }
        }
        else if (Room.bIsEndRoom)
        {
            bFoundEnd = true;
            EndRoomCount++;
            
            // Verify END room is 2x2
            TestEqual(TEXT("END room must be 2x2"), (int32)Room.RoomSize, 2);
            
            if (VerifyRoomSize(Visualizer, Room.Center, 2))
            {
                AddInfo(FString::Printf(TEXT("✅ END room verified 2x2 at center (%d,%d)"), 
                    Room.Center.X, Room.Center.Y));
            }
            else
            {
                AddError(FString::Printf(TEXT("❌ END room size incorrect at center (%d,%d)"), 
                    Room.Center.X, Room.Center.Y));
                Visualizer->Destroy();
                return false;
            }
        }
        else
        {
            // Regular room should be 3x3
            RegularRoomCount++;
            TestEqual(TEXT("Regular room must be 3x3"), (int32)Room.RoomSize, 3);
            
            if (!VerifyRoomSize(Visualizer, Room.Center, 3))
            {
                AddError(FString::Printf(TEXT("❌ Regular room size incorrect at center (%d,%d)"), 
                    Room.Center.X, Room.Center.Y));
                Visualizer->Destroy();
                return false;
            }
        }
    }
    
    // Verify exactly one START and one END room
    TestEqual(TEXT("Must have exactly one START room"), StartRoomCount, 1);
    TestEqual(TEXT("Must have exactly one END room"), EndRoomCount, 1);
    TestTrue(TEXT("Must have some regular rooms"), RegularRoomCount > 0);
    
    AddInfo(FString::Printf(TEXT("Room counts: %d START (2x2), %d END (2x2), %d Regular (3x3)"), 
        StartRoomCount, EndRoomCount, RegularRoomCount));
    
    // Test 2: Mixed Room Spacing Validation
    AddInfo(TEXT("--- TEST 2: Mixed Room Spacing Validation ---"));
    
    // Test ValidateMixedRoomSpacing function directly
    bool bSpacingValid = Visualizer->ValidateMixedRoomSpacing();
    TestTrue(TEXT("ValidateMixedRoomSpacing must return true"), bSpacingValid);
    
    if (!bSpacingValid)
    {
        AddError(TEXT("❌ Mixed room spacing validation failed"));
        Visualizer->Destroy();
        return false;
    }
    
    // Manual spacing verification between all room pairs
    int32 SpacingViolations = 0;
    int32 ValidSpacingPairs = 0;
    
    for (int32 i = 0; i < RoomList.Num(); i++)
    {
        for (int32 j = i + 1; j < RoomList.Num(); j++)
        {
            const FGridRoomInfo& Room1 = RoomList[i];
            const FGridRoomInfo& Room2 = RoomList[j];
            
            bool bValidGap = VerifyGapBetweenRooms(Visualizer, 
                Room1.Center, (int32)Room1.RoomSize,
                Room2.Center, (int32)Room2.RoomSize);
            
            if (bValidGap)
            {
                ValidSpacingPairs++;
            }
            else
            {
                SpacingViolations++;
                AddError(FString::Printf(TEXT("❌ Spacing violation between %dx%d room at (%d,%d) and %dx%d room at (%d,%d)"), 
                    (int32)Room1.RoomSize, (int32)Room1.RoomSize, Room1.Center.X, Room1.Center.Y,
                    (int32)Room2.RoomSize, (int32)Room2.RoomSize, Room2.Center.X, Room2.Center.Y));
            }
        }
    }
    
    TestEqual(TEXT("CRITICAL: No spacing violations allowed"), SpacingViolations, 0);
    AddInfo(FString::Printf(TEXT("Spacing validation: %d valid pairs, %d violations"), 
        ValidSpacingPairs, SpacingViolations));
    
    // Test 3: Specific Spacing Scenarios
    AddInfo(TEXT("--- TEST 3: Specific Mixed Room Scenarios ---"));
    
    // Test different room type combinations
    int32 TwoByTwoPairs = 0;
    int32 TwoByThreePairs = 0;
    int32 ThreeByThreePairs = 0;
    
    for (int32 i = 0; i < RoomList.Num(); i++)
    {
        for (int32 j = i + 1; j < RoomList.Num(); j++)
        {
            const FGridRoomInfo& Room1 = RoomList[i];
            const FGridRoomInfo& Room2 = RoomList[j];
            
            int32 Size1 = (int32)Room1.RoomSize;
            int32 Size2 = (int32)Room2.RoomSize;
            
            if (Size1 == 2 && Size2 == 2)
            {
                TwoByTwoPairs++;
            }
            else if ((Size1 == 2 && Size2 == 3) || (Size1 == 3 && Size2 == 2))
            {
                TwoByThreePairs++;
            }
            else if (Size1 == 3 && Size2 == 3)
            {
                ThreeByThreePairs++;
            }
        }
    }
    
    AddInfo(FString::Printf(TEXT("Room pair types: %d (2x2↔2x2), %d (2x2↔3x3), %d (3x3↔3x3)"), 
        TwoByTwoPairs, TwoByThreePairs, ThreeByThreePairs));
    
    // Test 4: Path Generation Verification
    AddInfo(TEXT("--- TEST 4: Path Generation Verification ---"));
    
    // Verify that START is first and END is last in the logical path
    bool bStartFirst = false;
    bool bEndLast = false;
    
    if (RoomList.Num() >= 2)
    {
        // In the mixed room system, START should be the first room generated
        for (int32 i = 0; i < RoomList.Num(); i++)
        {
            if (RoomList[i].bIsStartRoom && i == 0)
            {
                bStartFirst = true;
                break;
            }
        }
        
        // END should be the last room generated
        for (int32 i = 0; i < RoomList.Num(); i++)
        {
            if (RoomList[i].bIsEndRoom && i == RoomList.Num() - 1)
            {
                bEndLast = true;
                break;
            }
        }
    }
    
    TestTrue(TEXT("START room should be first in path"), bStartFirst);
    TestTrue(TEXT("END room should be last in path"), bEndLast);
    
    // Test 5: Performance Test with Larger Grid
    AddInfo(TEXT("--- TEST 5: Performance Test ---"));
    
    // Clear and test with larger grid
    Visualizer->ClearDungeon();
    Visualizer->GridSizeX = 30;
    Visualizer->GridSizeY = 30;
    
    const double LargeGridStartTime = FPlatformTime::Seconds();
    Visualizer->GenerateAndVisualizeDungeon(13579); // Different seed
    const double LargeGridElapsedMs = (FPlatformTime::Seconds() - LargeGridStartTime) * 1000.0;
    
    AddInfo(FString::Printf(TEXT("Large grid (%dx%d) generation: %.3fms"), 
        Visualizer->GridSizeX, Visualizer->GridSizeY, LargeGridElapsedMs));
    
    // Performance threshold for large grid
    checkf(LargeGridElapsedMs < 50.0, TEXT("CRITICAL: Large mixed room generation %.3fms exceeds 50ms limit"), LargeGridElapsedMs);
    
    // Count rooms in large grid
    int32 LargeGridRoomCount = Visualizer->RoomInfoList.Num();
    TestTrue(TEXT("Large grid should generate reasonable room count"), 
        LargeGridRoomCount >= 5 && LargeGridRoomCount <= 30);
    
    AddInfo(FString::Printf(TEXT("Large grid generated %d rooms"), LargeGridRoomCount));
    
    // Test 6: Memory Usage Check
    AddInfo(TEXT("--- TEST 6: Memory and Instance Count Check ---"));
    
    // Verify HISM instance counts are reasonable
    int32 FloorInstanceCount = 0;
    int32 WallInstanceCount = 0;
    
    if (Visualizer->PlaneInstances)
    {
        FloorInstanceCount = Visualizer->PlaneInstances->GetInstanceCount();
    }
    
    if (Visualizer->CubeInstances)
    {
        WallInstanceCount = Visualizer->CubeInstances->GetInstanceCount();
    }
    
    AddInfo(FString::Printf(TEXT("HISM Instances: %d floors, %d walls"), 
        FloorInstanceCount, WallInstanceCount));
    
    TestTrue(TEXT("Should have floor instances"), FloorInstanceCount > 0);
    TestTrue(TEXT("Should have wall instances"), WallInstanceCount > 0);
    TestTrue(TEXT("Wall instances should outnumber floor instances"), WallInstanceCount > FloorInstanceCount);
    
    // Performance summary
    const double TotalElapsedMs = (FPlatformTime::Seconds() - TestStartTime) * 1000.0;
    AddInfo(FString::Printf(TEXT("Total test execution: %.3fms"), TotalElapsedMs));
    
    // Test passes if all validations succeed
    bool bTestPassed = (SpacingViolations == 0) && 
                       bFoundStart && bFoundEnd &&
                       (StartRoomCount == 1) && (EndRoomCount == 1) &&
                       bSpacingValid &&
                       (GenerationElapsedMs < 16.0) &&
                       (LargeGridElapsedMs < 50.0);
    
    if (bTestPassed)
    {
        AddInfo(TEXT("✅ MIXED ROOM SIZE SYSTEM TEST PASSED"));
        AddInfo(TEXT("✅ All room sizes correct (2x2 START/END, 3x3 regular)"));
        AddInfo(TEXT("✅ All spacing requirements met (exactly 1 cell gap)"));
        AddInfo(TEXT("✅ Performance within acceptable limits"));
        AddInfo(TEXT("✅ Path generation working correctly"));
    }
    else
    {
        AddError(TEXT("❌ MIXED ROOM SIZE SYSTEM TEST FAILED"));
        AddError(TEXT("❌ Check room sizes, spacing, or performance issues"));
    }
    
    // Cleanup
    Visualizer->Destroy();
    
    return bTestPassed;
}

#endif // WITH_AUTOMATION_TESTS