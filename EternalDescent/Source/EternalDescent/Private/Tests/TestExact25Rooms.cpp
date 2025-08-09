/*
 * INTENT: Validate GridDungeonVisualizer's strict requirement for exactly 25 rooms with proper spacing and alignment
 * PURPOSE: Ensure generation consistently produces exactly 25 rooms with correct types and positioning
 * EMPIRICAL VALIDATION: Measures actual room counts, positions, spacing, and generation performance
 * FAILURE CONDITIONS: Room count != 25, incorrect room types, boundary violations, spacing < 1 cell
 * KNOWLEDGE TRANSFER: This test protects the core requirement that dungeons must have exactly 25 rooms
 *                     with Room 1 as START (2x2), Room 25 as END (2x2), and Rooms 2-24 as Regular (3x3)
 * REGRESSION PROTECTION: Prevents generation algorithm changes from violating the exact count requirement
 */

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "GridDungeonVisualizer.h"
#include "Engine/Engine.h"

#if WITH_AUTOMATION_TESTS

#include "Tests/AutomationEditorCommon.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestExact25Rooms, "EternalDescent.Dungeon.Exact25Rooms",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

/*
 * Test Helper Functions for Empirical Validation
 */

// Helper to verify exact room count with detailed logging
bool VerifyExactlyNRooms(AGridDungeonVisualizer* Visualizer, int32 ExpectedCount, FAutomationTestBase* TestContext)
{
    if (!IsValid(Visualizer))
    {
        TestContext->AddError(TEXT("VerifyExactlyNRooms: Invalid visualizer"));
        return false;
    }

    const int32 ActualCount = Visualizer->ActualRoomCount;
    const int32 RoomInfoCount = Visualizer->RoomInfoList.Num();

    TestContext->AddInfo(FString::Printf(TEXT("Room Count Analysis: ActualRoomCount=%d, RoomInfoList.Num()=%d, Expected=%d"),
        ActualCount, RoomInfoCount, ExpectedCount));

    if (ActualCount != ExpectedCount)
    {
        TestContext->AddError(FString::Printf(TEXT("ROOM COUNT FAILURE: ActualRoomCount=%d, Expected=%d"),
            ActualCount, ExpectedCount));
        return false;
    }

    if (RoomInfoCount != ExpectedCount)
    {
        TestContext->AddError(FString::Printf(TEXT("ROOM INFO LIST FAILURE: RoomInfoList.Num()=%d, Expected=%d"),
            RoomInfoCount, ExpectedCount));
        return false;
    }

    return true;
}

// Helper to verify START/END separation with Manhattan distance
int32 CalculateStartEndDistance(AGridDungeonVisualizer* Visualizer, FAutomationTestBase* TestContext)
{
    if (!IsValid(Visualizer) || Visualizer->RoomInfoList.Num() < 2)
    {
        TestContext->AddError(TEXT("CalculateStartEndDistance: Invalid visualizer or insufficient rooms"));
        return 0;
    }

    // Find START and END rooms
    FIntPoint StartPos = FIntPoint::ZeroValue;
    FIntPoint EndPos = FIntPoint::ZeroValue;
    bool bFoundStart = false;
    bool bFoundEnd = false;

    for (const FGridRoomInfo& Room : Visualizer->RoomInfoList)
    {
        if (Room.bIsStartRoom)
        {
            StartPos = Room.Center;
            bFoundStart = true;
            TestContext->AddInfo(FString::Printf(TEXT("START Room found at (%d, %d)"), StartPos.X, StartPos.Y));
        }
        if (Room.bIsEndRoom)
        {
            EndPos = Room.Center;
            bFoundEnd = true;
            TestContext->AddInfo(FString::Printf(TEXT("END Room found at (%d, %d)"), EndPos.X, EndPos.Y));
        }
    }

    if (!bFoundStart || !bFoundEnd)
    {
        TestContext->AddError(FString::Printf(TEXT("START/END not found: Start=%s, End=%s"),
            bFoundStart ? TEXT("Found") : TEXT("Missing"),
            bFoundEnd ? TEXT("Found") : TEXT("Missing")));
        return 0;
    }

    const int32 Distance = FMath::Abs(StartPos.X - EndPos.X) + FMath::Abs(StartPos.Y - EndPos.Y);
    TestContext->AddInfo(FString::Printf(TEXT("START-END Manhattan Distance: %d"), Distance));

    return Distance;
}

// Helper to verify no rooms touch grid boundaries
bool VerifyNoBoundaryTouch(AGridDungeonVisualizer* Visualizer, FAutomationTestBase* TestContext)
{
    if (!IsValid(Visualizer))
    {
        TestContext->AddError(TEXT("VerifyNoBoundaryTouch: Invalid visualizer"));
        return false;
    }

    const int32 GridSizeX = Visualizer->GridSizeX;
    const int32 GridSizeY = Visualizer->GridSizeY;
    bool bAllSafe = true;

    TestContext->AddInfo(FString::Printf(TEXT("Boundary Safety Check: Grid=%dx%d, Rooms=%d"),
        GridSizeX, GridSizeY, Visualizer->RoomInfoList.Num()));

    for (int32 i = 0; i < Visualizer->RoomInfoList.Num(); ++i)
    {
        const FGridRoomInfo& Room = Visualizer->RoomInfoList[i];
        const int32 RoomSize = (int32)Room.RoomSize;
        const FIntPoint& Center = Room.Center;

        // Calculate room bounds based on size
        int32 MinX, MaxX, MinY, MaxY;
        if (RoomSize == 2) // 2x2 room
        {
            MinX = Center.X;
            MaxX = Center.X + 1;
            MinY = Center.Y;
            MaxY = Center.Y + 1;
        }
        else // 3x3 room
        {
            MinX = Center.X - 1;
            MaxX = Center.X + 1;
            MinY = Center.Y - 1;
            MaxY = Center.Y + 1;
        }

        // Check boundaries
        const bool bTouchesBoundary = (MinX <= 0 || MaxX >= GridSizeX - 1 || MinY <= 0 || MaxY >= GridSizeY - 1);

        if (bTouchesBoundary)
        {
            TestContext->AddError(FString::Printf(TEXT("BOUNDARY VIOLATION: Room %d (%dx%d) at (%d,%d) touches boundary. Bounds: (%d,%d) to (%d,%d)"),
                i + 1, RoomSize, RoomSize, Center.X, Center.Y, MinX, MinY, MaxX, MaxY));
            bAllSafe = false;
        }
        else
        {
            TestContext->AddInfo(FString::Printf(TEXT("Room %d (%dx%d) at (%d,%d) safely positioned. Bounds: (%d,%d) to (%d,%d)"),
                i + 1, RoomSize, RoomSize, Center.X, Center.Y, MinX, MinY, MaxX, MaxY));
        }
    }

    return bAllSafe;
}

// Helper to verify exactly 1 cell gap between all rooms
bool VerifySpacingConsistency(AGridDungeonVisualizer* Visualizer, FAutomationTestBase* TestContext)
{
    if (!IsValid(Visualizer) || Visualizer->RoomInfoList.Num() < 2)
    {
        TestContext->AddError(TEXT("VerifySpacingConsistency: Invalid visualizer or insufficient rooms"));
        return false;
    }

    bool bAllSpacingValid = true;
    int32 ViolationCount = 0;
    int32 CheckCount = 0;

    TestContext->AddInfo(FString::Printf(TEXT("Spacing Validation: Checking %d rooms for 1-cell gaps"),
        Visualizer->RoomInfoList.Num()));

    // Check all room pairs
    for (int32 i = 0; i < Visualizer->RoomInfoList.Num(); ++i)
    {
        const FGridRoomInfo& Room1 = Visualizer->RoomInfoList[i];

        for (int32 j = i + 1; j < Visualizer->RoomInfoList.Num(); ++j)
        {
            const FGridRoomInfo& Room2 = Visualizer->RoomInfoList[j];
            CheckCount++;

            // Calculate required distance using the visualizer's function
            const float RequiredDistance = Visualizer->CalculateRequiredDistance(Room1.RoomSize, Room2.RoomSize);
            
            // Calculate actual distance
            const int32 ActualDistanceX = FMath::Abs(Room1.Center.X - Room2.Center.X);
            const int32 ActualDistanceY = FMath::Abs(Room1.Center.Y - Room2.Center.Y);
            const float ActualDistance = FMath::Max(ActualDistanceX, ActualDistanceY);

            const bool bSpacingValid = (ActualDistance >= RequiredDistance);

            if (!bSpacingValid)
            {
                TestContext->AddError(FString::Printf(TEXT("SPACING VIOLATION: Room %d (%dx%d) to Room %d (%dx%d) - Distance=%.1f, Required=%.1f"),
                    i + 1, (int32)Room1.RoomSize, (int32)Room1.RoomSize,
                    j + 1, (int32)Room2.RoomSize, (int32)Room2.RoomSize,
                    ActualDistance, RequiredDistance));
                ViolationCount++;
                bAllSpacingValid = false;
            }
        }
    }

    TestContext->AddInfo(FString::Printf(TEXT("Spacing Check Complete: %d pairs checked, %d violations found"),
        CheckCount, ViolationCount));

    return bAllSpacingValid;
}

// Helper to verify grid alignment with integer coordinates
bool VerifyGridAlignment(AGridDungeonVisualizer* Visualizer, FAutomationTestBase* TestContext)
{
    if (!IsValid(Visualizer))
    {
        TestContext->AddError(TEXT("VerifyGridAlignment: Invalid visualizer"));
        return false;
    }

    bool bAllAligned = true;
    const float CellSize = Visualizer->CellSize;

    TestContext->AddInfo(FString::Printf(TEXT("Grid Alignment Check: CellSize=%.1f"), CellSize));

    // Test various grid coordinates
    TArray<FIntPoint> TestCoords = {
        FIntPoint(0, 0), FIntPoint(5, 5), FIntPoint(10, 10), FIntPoint(15, 15)
    };

    for (const FIntPoint& Coord : TestCoords)
    {
        const FVector WorldPos = Visualizer->GridToWorldPosition(Coord.X, Coord.Y, false);
        
        // Check for integer alignment (world positions should be multiples of CellSize)
        const float ExpectedX = Coord.X * CellSize;
        const float ExpectedY = Coord.Y * CellSize;
        
        const bool bXAligned = FMath::IsNearlyEqual(WorldPos.X, ExpectedX, 0.1f);
        const bool bYAligned = FMath::IsNearlyEqual(WorldPos.Y, ExpectedY, 0.1f);

        if (!bXAligned || !bYAligned)
        {
            TestContext->AddError(FString::Printf(TEXT("ALIGNMENT FAILURE: Grid(%d,%d) -> World(%.2f,%.2f), Expected(%.2f,%.2f)"),
                Coord.X, Coord.Y, WorldPos.X, WorldPos.Y, ExpectedX, ExpectedY));
            bAllAligned = false;
        }
        else
        {
            TestContext->AddInfo(FString::Printf(TEXT("Grid(%d,%d) correctly aligned to World(%.1f,%.1f)"),
                Coord.X, Coord.Y, WorldPos.X, WorldPos.Y));
        }
    }

    return bAllAligned;
}

// Helper to verify room types are correct
bool VerifyRoomTypes(AGridDungeonVisualizer* Visualizer, FAutomationTestBase* TestContext)
{
    if (!IsValid(Visualizer) || Visualizer->RoomInfoList.Num() != 25)
    {
        TestContext->AddError(TEXT("VerifyRoomTypes: Invalid visualizer or wrong room count"));
        return false;
    }

    bool bTypesValid = true;
    int32 StartRoomCount = 0;
    int32 EndRoomCount = 0;
    int32 Size2x2Count = 0;
    int32 Size3x3Count = 0;

    // Count room types
    for (int32 i = 0; i < Visualizer->RoomInfoList.Num(); ++i)
    {
        const FGridRoomInfo& Room = Visualizer->RoomInfoList[i];
        
        if (Room.bIsStartRoom) StartRoomCount++;
        if (Room.bIsEndRoom) EndRoomCount++;
        
        if (Room.RoomSize == ERoomSizeType::Small_2x2) Size2x2Count++;
        else if (Room.RoomSize == ERoomSizeType::Standard_3x3) Size3x3Count++;
    }

    // Verify counts
    const bool bStartValid = (StartRoomCount == 1);
    const bool bEndValid = (EndRoomCount == 1);
    const bool bSize2x2Valid = (Size2x2Count == 2); // START and END
    const bool bSize3x3Valid = (Size3x3Count == 23); // Remaining rooms

    TestContext->AddInfo(FString::Printf(TEXT("Room Type Analysis: START=%d, END=%d, 2x2=%d, 3x3=%d"),
        StartRoomCount, EndRoomCount, Size2x2Count, Size3x3Count));

    if (!bStartValid)
    {
        TestContext->AddError(FString::Printf(TEXT("ROOM TYPE FAILURE: Found %d START rooms, expected 1"), StartRoomCount));
        bTypesValid = false;
    }

    if (!bEndValid)
    {
        TestContext->AddError(FString::Printf(TEXT("ROOM TYPE FAILURE: Found %d END rooms, expected 1"), EndRoomCount));
        bTypesValid = false;
    }

    if (!bSize2x2Valid)
    {
        TestContext->AddError(FString::Printf(TEXT("ROOM SIZE FAILURE: Found %d 2x2 rooms, expected 2"), Size2x2Count));
        bTypesValid = false;
    }

    if (!bSize3x3Valid)
    {
        TestContext->AddError(FString::Printf(TEXT("ROOM SIZE FAILURE: Found %d 3x3 rooms, expected 23"), Size3x3Count));
        bTypesValid = false;
    }

    return bTypesValid;
}

bool FTestExact25Rooms::RunTest(const FString& Parameters)
{
    AddInfo(TEXT("=== Starting Comprehensive 25 Room Validation Test ==="));

    // Create test world and visualizer
    UWorld* TestWorld = FAutomationEditorCommonUtils::CreateNewMap();
    if (!TestWorld)
    {
        AddError(TEXT("Failed to create test world"));
        return false;
    }

    // Spawn visualizer
    FActorSpawnParameters SpawnParams;
    SpawnParams.Name = TEXT("TestGridDungeonVisualizer");
    AGridDungeonVisualizer* Visualizer = TestWorld->SpawnActor<AGridDungeonVisualizer>(SpawnParams);

    if (!IsValid(Visualizer))
    {
        AddError(TEXT("Failed to spawn GridDungeonVisualizer"));
        return false;
    }

    // Configure for consistent testing
    Visualizer->RequiredRoomCount = 25;
    Visualizer->bAutoCalculateGridSize = true;
    Visualizer->bAnimateGeneration = false; // Instant for testing

    AddInfo(FString::Printf(TEXT("Test Configuration: RequiredRoomCount=%d, AutoCalculateGridSize=%s"),
        Visualizer->RequiredRoomCount,
        Visualizer->bAutoCalculateGridSize ? TEXT("true") : TEXT("false")));

    // Performance measurement
    const double StartTime = FPlatformTime::Seconds();

    // Generate dungeon
    Visualizer->GenerateAndVisualizeDungeon(12345); // Fixed seed for consistency

    const double GenerationTime = (FPlatformTime::Seconds() - StartTime) * 1000.0; // Convert to ms

    AddInfo(FString::Printf(TEXT("Generation completed in %.3f ms"), GenerationTime));

    // Critical performance assertion - generation must be under 16ms
    checkf(GenerationTime < 16.0, TEXT("CRITICAL: Generation time %.3fms exceeds 16ms limit"), GenerationTime);

    bool bAllTestsPassed = true;

    // TEST 1: Exact Room Count
    {
        AddInfo(TEXT("--- TEST 1: Exact Room Count ---"));
        if (!VerifyExactlyNRooms(Visualizer, 25, this))
        {
            bAllTestsPassed = false;
        }
        else
        {
            AddInfo(TEXT("✅ Exact room count validation PASSED"));
        }
    }

    // TEST 2: Room Types Validation
    {
        AddInfo(TEXT("--- TEST 2: Room Types Validation ---"));
        if (!VerifyRoomTypes(Visualizer, this))
        {
            bAllTestsPassed = false;
        }
        else
        {
            AddInfo(TEXT("✅ Room types validation PASSED"));
        }
    }

    // TEST 3: START/END Separation
    {
        AddInfo(TEXT("--- TEST 3: START/END Separation ---"));
        const int32 Distance = CalculateStartEndDistance(Visualizer, this);
        const int32 MinRequiredDistance = 20;

        if (Distance < MinRequiredDistance)
        {
            AddError(FString::Printf(TEXT("START/END DISTANCE FAILURE: Distance=%d, Required=%d"), Distance, MinRequiredDistance));
            bAllTestsPassed = false;
        }
        else
        {
            AddInfo(FString::Printf(TEXT("✅ START/END separation validation PASSED (Distance=%d >= %d)"), Distance, MinRequiredDistance));
        }
    }

    // TEST 4: Grid Alignment
    {
        AddInfo(TEXT("--- TEST 4: Grid Alignment ---"));
        if (!VerifyGridAlignment(Visualizer, this))
        {
            bAllTestsPassed = false;
        }
        else
        {
            AddInfo(TEXT("✅ Grid alignment validation PASSED"));
        }
    }

    // TEST 5: Boundary Safety
    {
        AddInfo(TEXT("--- TEST 5: Boundary Safety ---"));
        if (!VerifyNoBoundaryTouch(Visualizer, this))
        {
            bAllTestsPassed = false;
        }
        else
        {
            AddInfo(TEXT("✅ Boundary safety validation PASSED"));
        }
    }

    // TEST 6: Spacing Consistency
    {
        AddInfo(TEXT("--- TEST 6: Spacing Consistency ---"));
        if (!VerifySpacingConsistency(Visualizer, this))
        {
            bAllTestsPassed = false;
        }
        else
        {
            AddInfo(TEXT("✅ Spacing consistency validation PASSED"));
        }
    }

    // TEST 7: Performance Validation
    {
        AddInfo(TEXT("--- TEST 7: Performance Validation ---"));
        const double MaxAllowedTime = 16.0; // 16ms requirement from CLAUDE.md

        if (GenerationTime >= MaxAllowedTime)
        {
            AddError(FString::Printf(TEXT("PERFORMANCE FAILURE: Generation time %.3fms exceeds %.3fms limit"), GenerationTime, MaxAllowedTime));
            bAllTestsPassed = false;
        }
        else if (GenerationTime >= MaxAllowedTime * 0.8) // 80% threshold warning
        {
            AddWarning(FString::Printf(TEXT("PERFORMANCE WARNING: Generation time %.3fms approaching limit"), GenerationTime));
            AddInfo(TEXT("✅ Performance validation PASSED (with warning)"));
        }
        else
        {
            AddInfo(FString::Printf(TEXT("✅ Performance validation PASSED (%.3fms < %.3fms)"), GenerationTime, MaxAllowedTime));
        }
    }

    // Final validation summary
    AddInfo(TEXT("=== Test Summary ==="));
    AddInfo(FString::Printf(TEXT("Generation Time: %.3f ms"), GenerationTime));
    AddInfo(FString::Printf(TEXT("Room Count: %d (Required: 25)"), Visualizer->ActualRoomCount));
    AddInfo(FString::Printf(TEXT("Grid Size: %dx%d"), Visualizer->GridSizeX, Visualizer->GridSizeY));

    if (bAllTestsPassed)
    {
        AddInfo(TEXT("🎉 ALL TESTS PASSED - GridDungeonVisualizer correctly generates exactly 25 rooms"));
    }
    else
    {
        AddError(TEXT("❌ SOME TESTS FAILED - GridDungeonVisualizer has issues with 25 room requirement"));
    }

    // Cleanup
    if (IsValid(Visualizer))
    {
        Visualizer->Destroy();
    }

    return bAllTestsPassed;
}

#endif // WITH_AUTOMATION_TESTS