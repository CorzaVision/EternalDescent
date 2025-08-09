// MixedRoomTestUtilities.cpp - Reusable helper functions for mixed room size testing
/*
 * INTENT: Provide reusable utility functions for testing mixed room size systems
 * PURPOSE: Centralize common test validation logic for room sizes and spacing
 * EMPIRICAL VALIDATION: Functions provide measurable validation of room properties
 * FAILURE CONDITIONS: Helper functions return false when validation fails
 * KNOWLEDGE TRANSFER: Centralized test utilities ensure consistent validation across all tests
 */

#include "MixedRoomTestUtilities.h"
#include "GridDungeonVisualizer.h"

#if WITH_AUTOMATION_TESTS

bool MixedRoomTestUtilities::VerifyRoomSize(AGridDungeonVisualizer* Visualizer, FIntPoint RoomCenter, int32 ExpectedSize)
{
    if (!IsValid(Visualizer))
    {
        return false;
    }
    
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

bool MixedRoomTestUtilities::VerifyGapBetweenRooms(AGridDungeonVisualizer* Visualizer,
    FIntPoint Room1Center, int32 Room1Size,
    FIntPoint Room2Center, int32 Room2Size)
{
    if (!IsValid(Visualizer))
    {
        return false;
    }
    
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

FMixedRoomAnalysis MixedRoomTestUtilities::AnalyzeMixedRoomGeneration(AGridDungeonVisualizer* Visualizer)
{
    FMixedRoomAnalysis Analysis;
    
    if (!IsValid(Visualizer))
    {
        return Analysis;
    }
    
    const TArray<FGridRoomInfo>& RoomList = Visualizer->RoomInfoList;
    Analysis.TotalRoomCount = RoomList.Num();
    
    // Analyze room types and sizes
    for (const FGridRoomInfo& Room : RoomList)
    {
        if (Room.bIsStartRoom)
        {
            Analysis.StartRoomCount++;
            if ((int32)Room.RoomSize == 2)
            {
                Analysis.Correct2x2StartRooms++;
            }
        }
        else if (Room.bIsEndRoom)
        {
            Analysis.EndRoomCount++;
            if ((int32)Room.RoomSize == 2)
            {
                Analysis.Correct2x2EndRooms++;
            }
        }
        else
        {
            Analysis.RegularRoomCount++;
            if ((int32)Room.RoomSize == 3)
            {
                Analysis.Correct3x3RegularRooms++;
            }
        }
    }
    
    // Calculate floor cell statistics
    for (int32 Y = 0; Y < Visualizer->GridSizeY; ++Y)
    {
        for (int32 X = 0; X < Visualizer->GridSizeX; ++X)
        {
            if (Visualizer->IsValidGridPosition(X, Y))
            {
                FGridCell Cell = Visualizer->GetGridCell(X, Y);
                if (Cell.CellType == EGridCellType::Floor)
                {
                    Analysis.TotalFloorCells++;
                }
                else if (Cell.CellType == EGridCellType::Wall)
                {
                    Analysis.TotalWallCells++;
                }
            }
        }
    }
    
    // Check spacing violations using mixed room system
    Analysis.SpacingValid = Visualizer->ValidateMixedRoomSpacing();
    
    // Analyze room pair types
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
                Analysis.TwoByTwoPairs++;
            }
            else if ((Size1 == 2 && Size2 == 3) || (Size1 == 3 && Size2 == 2))
            {
                Analysis.TwoByThreePairs++;
            }
            else if (Size1 == 3 && Size2 == 3)
            {
                Analysis.ThreeByThreePairs++;
            }
            
            Analysis.TotalRoomPairs++;
        }
    }
    
    return Analysis;
}

bool MixedRoomTestUtilities::ValidateRoomSystemIntegrity(const FMixedRoomAnalysis& Analysis)
{
    // Basic integrity checks
    if (Analysis.TotalRoomCount == 0)
    {
        return false; // No rooms generated
    }
    
    if (Analysis.StartRoomCount != 1 || Analysis.EndRoomCount != 1)
    {
        return false; // Must have exactly one START and one END
    }
    
    if (Analysis.Correct2x2StartRooms != 1 || Analysis.Correct2x2EndRooms != 1)
    {
        return false; // START and END must be 2x2
    }
    
    if (Analysis.Correct3x3RegularRooms != Analysis.RegularRoomCount)
    {
        return false; // All regular rooms must be 3x3
    }
    
    if (!Analysis.SpacingValid)
    {
        return false; // Spacing validation must pass
    }
    
    if (Analysis.TotalFloorCells == 0 || Analysis.TotalWallCells == 0)
    {
        return false; // Must have both floors and walls
    }
    
    // Expected floor cells: 2 * 4 (START/END 2x2) + RegularRoomCount * 9 (3x3)
    int32 ExpectedFloorCells = (Analysis.Correct2x2StartRooms + Analysis.Correct2x2EndRooms) * 4 + 
                               Analysis.Correct3x3RegularRooms * 9;
    
    if (Analysis.TotalFloorCells != ExpectedFloorCells)
    {
        return false; // Floor cell count doesn't match expected room sizes
    }
    
    return true; // All integrity checks passed
}

FString MixedRoomTestUtilities::GenerateAnalysisReport(const FMixedRoomAnalysis& Analysis)
{
    FString Report = TEXT("=== MIXED ROOM SIZE ANALYSIS REPORT ===\n");
    
    Report += FString::Printf(TEXT("Total Rooms: %d\n"), Analysis.TotalRoomCount);
    Report += FString::Printf(TEXT("  - START (2x2): %d/%d correct\n"), 
        Analysis.Correct2x2StartRooms, Analysis.StartRoomCount);
    Report += FString::Printf(TEXT("  - END (2x2): %d/%d correct\n"), 
        Analysis.Correct2x2EndRooms, Analysis.EndRoomCount);
    Report += FString::Printf(TEXT("  - Regular (3x3): %d/%d correct\n"), 
        Analysis.Correct3x3RegularRooms, Analysis.RegularRoomCount);
    
    Report += FString::Printf(TEXT("Floor Cells: %d, Wall Cells: %d\n"), 
        Analysis.TotalFloorCells, Analysis.TotalWallCells);
    
    Report += FString::Printf(TEXT("Room Pairs: %d total\n"), Analysis.TotalRoomPairs);
    Report += FString::Printf(TEXT("  - 2x2↔2x2: %d pairs\n"), Analysis.TwoByTwoPairs);
    Report += FString::Printf(TEXT("  - 2x2↔3x3: %d pairs\n"), Analysis.TwoByThreePairs);
    Report += FString::Printf(TEXT("  - 3x3↔3x3: %d pairs\n"), Analysis.ThreeByThreePairs);
    
    Report += FString::Printf(TEXT("Spacing Valid: %s\n"), 
        Analysis.SpacingValid ? TEXT("✅ PASS") : TEXT("❌ FAIL"));
    
    bool bIntegrityValid = ValidateRoomSystemIntegrity(Analysis);
    Report += FString::Printf(TEXT("System Integrity: %s\n"), 
        bIntegrityValid ? TEXT("✅ PASS") : TEXT("❌ FAIL"));
    
    Report += TEXT("=== END ANALYSIS REPORT ===");
    
    return Report;
}

#endif // WITH_AUTOMATION_TESTS