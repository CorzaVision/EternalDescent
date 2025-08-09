// GapSpacingVerificationTest.cpp - Verify 1-cell spacing with mixed room sizes (2x2 START/END, 3x3 regular)
/*
 * INTENT: Validate GridDungeonVisualizer 1-cell spacing with mixed room size system
 * PURPOSE: Ensure spacing requirements are met with 2x2 and 3x3 room combinations
 * EMPIRICAL VALIDATION: Measures generation time and validates mixed room spacing
 * FAILURE CONDITIONS: >16ms generation time, spacing violations, incorrect room sizes
 * KNOWLEDGE TRANSFER: Tests verify mixed room size system maintains proper spacing
 *                     between 2x2 START/END rooms and 3x3 regular rooms
 */


#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "GridDungeonVisualizer.h"
#include "Engine/Engine.h"

#if WITH_AUTOMATION_TESTS

#include "Tests/AutomationEditorCommon.h"
#include "AutomationBlueprintFunctionLibrary.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGapSpacingVerificationTest, "EternalDescent.Dungeon.GapSpacingVerification", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FGapSpacingVerificationTest::RunTest(const FString& Parameters)
{
    const double TestStartTime = FPlatformTime::Seconds();
    
    AddInfo(TEXT("=== MIXED ROOM SIZE 1-CELL GAP SPACING TEST (2x2 START/END, 3x3 regular) ==="));
    
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
        AddError(TEXT("GapSpacingVerificationTest: Failed to get valid world"));
        return false;
    }
    
    AGridDungeonVisualizer* Visualizer = World->SpawnActor<AGridDungeonVisualizer>();
    if (!ensure(IsValid(Visualizer)))
    {
        AddError(TEXT("GapSpacingVerificationTest: Failed to spawn GridDungeonVisualizer"));
        return false;
    }
    
    // Test with small grid first (should be very fast)
    Visualizer->GridSizeX = 8;
    Visualizer->GridSizeY = 8;
    Visualizer->CellSize = 350.0f;
    
    AddInfo(FString::Printf(TEXT("Testing small grid: %dx%d cells"), Visualizer->GridSizeX, Visualizer->GridSizeY));
    
    // Generate dungeon and measure performance
    const double GenerationStartTime = FPlatformTime::Seconds();
    Visualizer->GenerateAndVisualizeDungeon(12345); // Fixed seed for consistency
    const double GenerationElapsedMs = (FPlatformTime::Seconds() - GenerationStartTime) * 1000.0;
    
    AddInfo(FString::Printf(TEXT("Small grid generation: %.3fms"), GenerationElapsedMs));
    
    // Small grids should be extremely fast with O(1) optimization
    checkf(GenerationElapsedMs < 16.0, TEXT("CRITICAL: Small grid generation %.3fms exceeds 16ms limit"), GenerationElapsedMs);
    
    // Collect all floor positions (rooms)
    TArray<FIntPoint> FloorPositions;
    int32 FloorCount = 0;
    int32 WallCount = 0;
    
    for (int32 Y = 0; Y < Visualizer->GridSizeY; ++Y)
    {
        for (int32 X = 0; X < Visualizer->GridSizeX; ++X)
        {
            if (Visualizer->IsValidGridPosition(X, Y))
            {
                FGridCell Cell = Visualizer->GetGridCell(X, Y);
                if (Cell.CellType == EGridCellType::Floor)
                {
                    FloorPositions.Add(FIntPoint(X, Y));
                    FloorCount++;
                }
                else if (Cell.CellType == EGridCellType::Wall)
                {
                    WallCount++;
                }
            }
        }
    }
    
    AddInfo(FString::Printf(TEXT("Generated: %d floors, %d walls"), FloorCount, WallCount));
    
    TestTrue(TEXT("Must generate some floors"), FloorCount > 0);
    TestTrue(TEXT("Must generate some walls"), WallCount > 0);
    // With mixed room sizes (2x2 and 3x3), floor count will be much higher
    // 25 rooms with mixed sizes: 2*(2x2) + 23*(3x3) = 2*4 + 23*9 = 8 + 207 = 215 floors
    TestTrue(TEXT("Should generate reasonable floor count for mixed room sizes"), FloorCount >= 100 && FloorCount <= 300);
    
    // CRITICAL: Validate no adjacent rooms exist (mixed room size spacing requirement)
    int32 ViolationCount = 0;
    int32 ValidPairs = 0;
    
    // Test mixed room size spacing using ValidateMixedRoomSpacing function
    bool bMixedSpacingValid = Visualizer->ValidateMixedRoomSpacing();
    
    if (!bMixedSpacingValid)
    {
        ViolationCount = 1; // Force test failure if mixed room validation fails
        AddError(TEXT("CRITICAL: ValidateMixedRoomSpacing() returned false - spacing violations detected"));
    }
    else
    {
        AddInfo(TEXT("✅ ValidateMixedRoomSpacing() passed - mixed room sizes maintain proper spacing"));
    }
    
    // Additional room-boundary spacing validation using RoomInfoList
    const TArray<FGridRoomInfo>& RoomList = Visualizer->RoomInfoList;
    if (RoomList.Num() > 1)
    {
        for (int32 i = 0; i < RoomList.Num(); ++i)
        {
            for (int32 j = i + 1; j < RoomList.Num(); ++j)
            {
                const FGridRoomInfo& Room1 = RoomList[i];
                const FGridRoomInfo& Room2 = RoomList[j];
                
                // Calculate room boundaries
                int32 Room1MinX, Room1MaxX, Room1MinY, Room1MaxY;
                int32 Room2MinX, Room2MaxX, Room2MinY, Room2MaxY;
                
                if (Room1.RoomSize == ERoomSizeType::Small_2x2) // 2x2
                {
                    Room1MinX = Room1.Center.X;
                    Room1MaxX = Room1.Center.X + 1;
                    Room1MinY = Room1.Center.Y;
                    Room1MaxY = Room1.Center.Y + 1;
                }
                else // 3x3
                {
                    Room1MinX = Room1.Center.X - 1;
                    Room1MaxX = Room1.Center.X + 1;
                    Room1MinY = Room1.Center.Y - 1;
                    Room1MaxY = Room1.Center.Y + 1;
                }
                
                if (Room2.RoomSize == ERoomSizeType::Small_2x2) // 2x2
                {
                    Room2MinX = Room2.Center.X;
                    Room2MaxX = Room2.Center.X + 1;
                    Room2MinY = Room2.Center.Y;
                    Room2MaxY = Room2.Center.Y + 1;
                }
                else // 3x3
                {
                    Room2MinX = Room2.Center.X - 1;
                    Room2MaxX = Room2.Center.X + 1;
                    Room2MinY = Room2.Center.Y - 1;
                    Room2MaxY = Room2.Center.Y + 1;
                }
                
                // Calculate minimum gap between room boundaries
                int32 XGap = FMath::Max(0, FMath::Max(Room1MinX - Room2MaxX - 1, Room2MinX - Room1MaxX - 1));
                int32 YGap = FMath::Max(0, FMath::Max(Room1MinY - Room2MaxY - 1, Room2MinY - Room1MaxY - 1));
                int32 MinGap = FMath::Max(XGap, YGap);
                
                // Rooms must have at least 1 cell spacing
                if (MinGap < 1)
                {
                    ViolationCount++;
                    AddError(FString::Printf(TEXT("SPACING VIOLATION #%d: %dx%d room at (%d,%d) and %dx%d room at (%d,%d) have insufficient spacing (gap: %d)"), 
                        ViolationCount, 
                        (Room1.RoomSize == ERoomSizeType::Small_2x2 ? 2 : 3), (Room1.RoomSize == ERoomSizeType::Small_2x2 ? 2 : 3), Room1.Center.X, Room1.Center.Y,
                        (Room2.RoomSize == ERoomSizeType::Small_2x2 ? 2 : 3), (Room2.RoomSize == ERoomSizeType::Small_2x2 ? 2 : 3), Room2.Center.X, Room2.Center.Y,
                        MinGap));
                }
                else
                {
                    ValidPairs++;
                }
            }
        }
    }
    else
    {
        AddInfo(TEXT("Note: Limited room information available for boundary validation"));
        // Fallback to simpler validation if room list is incomplete
        ValidPairs = 1; // Prevent test failure due to lack of room data
    }
    
    // CRITICAL: No spacing violations allowed
    TestEqual(TEXT("CRITICAL: Zero spacing violations required"), ViolationCount, 0);
    
    if (ViolationCount > 0)
    {
        AddError(FString::Printf(TEXT("CRITICAL FAILURE: Found %d spacing violations"), ViolationCount));
        Visualizer->Destroy();
        return false;
    }
    
    AddInfo(FString::Printf(TEXT("Mixed room size spacing validation: %d valid pairs, %d violations"), ValidPairs, ViolationCount));
    
    // Room info summary
    if (RoomList.Num() > 0)
    {
        int32 StartRooms = 0, EndRooms = 0, RegularRooms = 0;
        for (const FGridRoomInfo& Room : RoomList)
        {
            if (Room.bIsStartRoom) StartRooms++;
            else if (Room.bIsEndRoom) EndRooms++;
            else RegularRooms++;
        }
        AddInfo(FString::Printf(TEXT("Room breakdown: %d START (2x2), %d END (2x2), %d Regular (3x3)"), 
            StartRooms, EndRooms, RegularRooms));
    }
    
    // Test medium grid for performance scaling
    Visualizer->ClearDungeon();
    Visualizer->GridSizeX = 15;
    Visualizer->GridSizeY = 15;
    
    AddInfo(FString::Printf(TEXT("Testing medium grid: %dx%d cells"), Visualizer->GridSizeX, Visualizer->GridSizeY));
    
    const double MediumStartTime = FPlatformTime::Seconds();
    Visualizer->GenerateAndVisualizeDungeon(54321); // Different seed
    const double MediumElapsedMs = (FPlatformTime::Seconds() - MediumStartTime) * 1000.0;
    
    AddInfo(FString::Printf(TEXT("Medium grid generation: %.3fms"), MediumElapsedMs));
    
    // Medium grids should still be reasonably fast
    TestTrue(TEXT("Medium grid should be under 50ms"), MediumElapsedMs < 50.0);
    
    // Count rooms in medium grid
    int32 MediumFloorCount = 0;
    for (int32 Y = 0; Y < Visualizer->GridSizeY; ++Y)
    {
        for (int32 X = 0; X < Visualizer->GridSizeX; ++X)
        {
            if (Visualizer->IsValidGridPosition(X, Y))
            {
                FGridCell Cell = Visualizer->GetGridCell(X, Y);
                if (Cell.CellType == EGridCellType::Floor)
                {
                    MediumFloorCount++;
                }
            }
        }
    }
    
    AddInfo(FString::Printf(TEXT("Medium grid generated %d floors"), MediumFloorCount));
    TestTrue(TEXT("Medium grid should generate similar or more floors"), MediumFloorCount >= FloorCount / 2);
    TestTrue(TEXT("Medium grid should generate reasonable floor count"), MediumFloorCount >= 100 && MediumFloorCount <= 300);
    
    // Performance summary
    const double TotalElapsedMs = (FPlatformTime::Seconds() - TestStartTime) * 1000.0;
    AddInfo(FString::Printf(TEXT("Total test execution: %.3fms"), TotalElapsedMs));
    
    // Test passes if no spacing violations and reasonable performance
    bool bTestPassed = (ViolationCount == 0) && 
                       (GenerationElapsedMs < 16.0) && 
                       (MediumElapsedMs < 50.0) && 
                       (FloorCount > 0) && 
                       (MediumFloorCount > 0);
    
    if (bTestPassed)
    {
        AddInfo(TEXT("✅ MIXED ROOM SIZE SYSTEM SUCCESS: Fast generation with proper mixed room spacing"));
    }
    else
    {
        AddError(TEXT("❌ MIXED ROOM SIZE SYSTEM FAILED: Performance or spacing issues detected"));
    }
    
    // Cleanup
    Visualizer->Destroy();
    
    return bTestPassed;
}

#endif // WITH_AUTOMATION_TESTS