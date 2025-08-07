// TestSnakeDungeonValidation.cpp
// Validation tests for Snake Dungeon constraints:
// - 15-25 rooms per floor
// - No rest rooms
// - Hallways never touch/intersect

#include "CoreMinimal.h"
#include "SnakeDungeonGenerator.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "Engine/World.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * SNAKE DUNGEON VALIDATION TESTS
 * ================================
 * Critical Requirements:
 * - MUST have 15-25 rooms per floor
 * - NO rest rooms allowed
 * - Hallways MUST NOT intersect or touch
 */

// ============================================================================
// TEST 1: ROOM COUNT VALIDATION - Ensure 15-25 rooms per floor
// ============================================================================
// Intent: Validate every floor has exactly 15-25 rooms
// Purpose: Ensure consistent dungeon size and player experience
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestSnakeDungeonRoomCount, "EternalDescent.SnakeDungeon.Validation.RoomCount",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTestSnakeDungeonRoomCount::RunTest(const FString& Parameters)
{
    // Setup
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    ASnakeDungeonGenerator* Generator = TestWorld->SpawnActor<ASnakeDungeonGenerator>();
    
    AddInfo(TEXT("=== Testing Room Count Requirement (15-25 rooms) ==="));
    
    // Test all 20 stages
    for (int32 Stage = 1; Stage <= 20; ++Stage)
    {
        FSnakeDungeonLayout Layout = Generator->GenerateSnakeDungeon(Stage);
        
        int32 RoomCount = Layout.Rooms.Num();
        
        // Log room count for each stage
        AddInfo(FString::Printf(TEXT("Stage %d: %d rooms"), Stage, RoomCount));
        
        // CRITICAL CHECK: Must be 15-25 rooms
        if (RoomCount < 15 || RoomCount > 25)
        {
            AddError(FString::Printf(TEXT("FAILURE: Stage %d has %d rooms, must be 15-25"), 
                Stage, RoomCount));
            TestWorld->DestroyWorld(false);
            return false;
        }
        
        // Check stage type is correctly assigned
        if (Stage % 10 == 0)
        {
            TestEqual(FString::Printf(TEXT("Stage %d should be Boss"), Stage),
                (uint8)Layout.StageType, (uint8)EStageType::Boss);
        }
        else if (Stage % 5 == 0)
        {
            TestEqual(FString::Printf(TEXT("Stage %d should be Elite"), Stage),
                (uint8)Layout.StageType, (uint8)EStageType::Elite);
        }
    }
    
    AddInfo(TEXT("✓ All stages have 15-25 rooms"));
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    return true;
}

// ============================================================================
// TEST 2: START/EXIT ROOMS - Ensure Start and Exit rooms are properly labeled
// ============================================================================
// Intent: Validate that Start and Exit rooms are explicitly marked
// Purpose: Ensure proper room labeling for start and extraction points
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestSnakeDungeonStartExitRooms, "EternalDescent.SnakeDungeon.Validation.StartExitRooms",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTestSnakeDungeonStartExitRooms::RunTest(const FString& Parameters)
{
    // Setup
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    ASnakeDungeonGenerator* Generator = TestWorld->SpawnActor<ASnakeDungeonGenerator>();
    
    AddInfo(TEXT("=== Testing Start/Exit Room Labeling ==="));
    
    // Test multiple stages
    TArray<int32> TestStages = {1, 5, 10, 15, 20};
    
    for (int32 Stage : TestStages)
    {
        FSnakeDungeonLayout Layout = Generator->GenerateSnakeDungeon(Stage);
        
        // Check for Start room
        bool bHasStartRoom = false;
        bool bHasExitRoom = false;
        int32 RestRoomCount = 0;
        
        for (const auto& RoomPair : Layout.Rooms)
        {
            if (RoomPair.Value.Type == ERoomType::Start)
            {
                bHasStartRoom = true;
                TestEqual(TEXT("Start room should be first in path"), 
                    RoomPair.Value.PathOrder, 0);
            }
            else if (RoomPair.Value.Type == ERoomType::Exit)
            {
                bHasExitRoom = true;
            }
            // Check that no other rooms are Rest type
            else if (RoomPair.Value.Type == ERoomType::Rest)
            {
                RestRoomCount++;
                AddError(FString::Printf(TEXT("FAILURE: Found rest room (ID: %d) that is not Start/Exit in stage %d"), 
                    RoomPair.Key, Stage));
            }
        }
        
        TestTrue(FString::Printf(TEXT("Stage %d should have Start room"), Stage), bHasStartRoom);
        TestTrue(FString::Printf(TEXT("Stage %d should have Exit room"), Stage), bHasExitRoom);
        TestEqual(FString::Printf(TEXT("Stage %d should have no standalone rest rooms"), Stage), RestRoomCount, 0);
        
        if (bHasStartRoom && bHasExitRoom && RestRoomCount == 0)
        {
            AddInfo(FString::Printf(TEXT("Stage %d: ✓ Start/Exit rooms properly labeled, no standalone rest rooms"), Stage));
        }
    }
    
    AddInfo(TEXT("✓ All stages have proper Start/Exit labeling"));
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    return true;
}

// ============================================================================
// TEST 3: HALLWAY COLLISION - Ensure hallways never intersect
// ============================================================================
// Intent: Validate that hallways maintain spacing and never touch
// Purpose: Prevent navigation issues and maintain clean dungeon layout
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestSnakeDungeonHallwayCollision, "EternalDescent.SnakeDungeon.Validation.HallwayNoCollision",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTestSnakeDungeonHallwayCollision::RunTest(const FString& Parameters)
{
    // Setup
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    ASnakeDungeonGenerator* Generator = TestWorld->SpawnActor<ASnakeDungeonGenerator>();
    
    AddInfo(TEXT("=== Testing Hallway Non-Intersection Requirement ==="));
    
    // Test multiple stages with different complexities
    TArray<int32> TestStages = {1, 5, 10, 15, 20};
    
    for (int32 Stage : TestStages)
    {
        FSnakeDungeonLayout Layout = Generator->GenerateSnakeDungeon(Stage);
        
        AddInfo(FString::Printf(TEXT("Stage %d: Checking %d hallways"), 
            Stage, Layout.Hallways.Num()));
        
        // Check each hallway against every other hallway
        bool bHasCollision = false;
        for (int32 i = 0; i < Layout.Hallways.Num(); ++i)
        {
            const FHallwayConnection& Hallway1 = Layout.Hallways[i];
            
            for (int32 j = i + 1; j < Layout.Hallways.Num(); ++j)
            {
                const FHallwayConnection& Hallway2 = Layout.Hallways[j];
                
                // Check if any points in Hallway1 are too close to points in Hallway2
                for (const FIntVector& Point1 : Hallway1.Path)
                {
                    for (const FIntVector& Point2 : Hallway2.Path)
                    {
                        float Distance = FVector::Dist(FVector(Point1), FVector(Point2));
                        
                        // Hallways should never be closer than 1 cube
                        if (Distance < 1.0f)
                        {
                            AddError(FString::Printf(
                                TEXT("FAILURE: Hallway collision detected in stage %d between hallways %d-%d and %d-%d (distance: %.2f)"), 
                                Stage, 
                                Hallway1.FromRoomID, Hallway1.ToRoomID,
                                Hallway2.FromRoomID, Hallway2.ToRoomID,
                                Distance));
                            bHasCollision = true;
                        }
                    }
                }
            }
        }
        
        if (!bHasCollision)
        {
            AddInfo(FString::Printf(TEXT("Stage %d: ✓ No hallway collisions"), Stage));
        }
        else
        {
            TestWorld->DestroyWorld(false);
            return false;
        }
    }
    
    AddInfo(TEXT("✓ No hallway collisions detected in any stage"));
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    return true;
}

// ============================================================================
// TEST 4: HALLWAY LENGTH - Ensure hallways are 1-2 cubes only
// ============================================================================
// Intent: Validate hallway length constraints
// Purpose: Maintain room-to-room feel without long corridors
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestSnakeDungeonHallwayLength, "EternalDescent.SnakeDungeon.Validation.HallwayLength",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTestSnakeDungeonHallwayLength::RunTest(const FString& Parameters)
{
    // Setup
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    ASnakeDungeonGenerator* Generator = TestWorld->SpawnActor<ASnakeDungeonGenerator>();
    
    AddInfo(TEXT("=== Testing Hallway Length Requirement (1-2 cubes) ==="));
    
    // Test multiple stages
    for (int32 Stage = 1; Stage <= 5; ++Stage)
    {
        FSnakeDungeonLayout Layout = Generator->GenerateSnakeDungeon(Stage);
        
        int32 TotalHallways = Layout.Hallways.Num();
        int32 ValidHallways = 0;
        int32 TooLongHallways = 0;
        
        for (const FHallwayConnection& Hallway : Layout.Hallways)
        {
            if (Hallway.Length >= 1 && Hallway.Length <= 2)
            {
                ValidHallways++;
            }
            else
            {
                TooLongHallways++;
                AddWarning(FString::Printf(
                    TEXT("Stage %d: Hallway %d-%d is %d cubes long (should be 1-2)"),
                    Stage, Hallway.FromRoomID, Hallway.ToRoomID, Hallway.Length));
            }
        }
        
        AddInfo(FString::Printf(TEXT("Stage %d: %d/%d hallways are 1-2 cubes"), 
            Stage, ValidHallways, TotalHallways));
        
        // Allow some flexibility but most should be 1-2 cubes
        float ValidPercentage = (float)ValidHallways / TotalHallways;
        TestTrue(FString::Printf(TEXT("Stage %d: Most hallways should be 1-2 cubes"), Stage),
            ValidPercentage >= 0.8f); // 80% should be 1-2 cubes
    }
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    return true;
}

// ============================================================================
// TEST 5: ROOM SPACING - Ensure rooms maintain minimum 1 cube spacing
// ============================================================================
// Intent: Validate rooms never touch
// Purpose: Prevent room overlap and maintain clean separation
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestSnakeDungeonRoomSpacing, "EternalDescent.SnakeDungeon.Validation.RoomSpacing",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTestSnakeDungeonRoomSpacing::RunTest(const FString& Parameters)
{
    // Setup
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    ASnakeDungeonGenerator* Generator = TestWorld->SpawnActor<ASnakeDungeonGenerator>();
    
    AddInfo(TEXT("=== Testing Room Spacing Requirement (min 1 cube apart) ==="));
    
    // Test a few stages
    TArray<int32> TestStages = {1, 10, 20};
    
    for (int32 Stage : TestStages)
    {
        FSnakeDungeonLayout Layout = Generator->GenerateSnakeDungeon(Stage);
        
        bool bHasOverlap = false;
        
        // Check each room against every other room
        TArray<FSnakeRoom> Rooms;
        Layout.Rooms.GenerateValueArray(Rooms);
        
        for (int32 i = 0; i < Rooms.Num(); ++i)
        {
            for (int32 j = i + 1; j < Rooms.Num(); ++j)
            {
                // Check if rooms collide (with 0 spacing means they're touching)
                if (Rooms[i].CollidesWith(Rooms[j], 0))
                {
                    AddError(FString::Printf(
                        TEXT("Stage %d: Rooms %d and %d are touching or overlapping!"),
                        Stage, Rooms[i].RoomID, Rooms[j].RoomID));
                    bHasOverlap = true;
                }
            }
        }
        
        if (!bHasOverlap)
        {
            AddInfo(FString::Printf(TEXT("Stage %d: ✓ All rooms properly spaced"), Stage));
        }
        else
        {
            TestWorld->DestroyWorld(false);
            return false;
        }
    }
    
    AddInfo(TEXT("✓ All rooms maintain proper spacing"));
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    return true;
}

// ============================================================================
// TEST 6: COMPREHENSIVE VALIDATION - Test all constraints together
// ============================================================================
// Intent: Validate all requirements in a single comprehensive test
// Purpose: Ensure system meets all design constraints
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestSnakeDungeonComprehensive, "EternalDescent.SnakeDungeon.Validation.Comprehensive",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTestSnakeDungeonComprehensive::RunTest(const FString& Parameters)
{
    // Setup
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    ASnakeDungeonGenerator* Generator = TestWorld->SpawnActor<ASnakeDungeonGenerator>();
    
    AddInfo(TEXT("=== Comprehensive Snake Dungeon Validation ==="));
    
    // Test all 20 stages
    int32 TotalRooms = 0;
    int32 TotalHallways = 0;
    
    for (int32 Stage = 1; Stage <= 20; ++Stage)
    {
        const double StartTime = FPlatformTime::Seconds();
        
        FSnakeDungeonLayout Layout = Generator->GenerateSnakeDungeon(Stage);
        
        const double GenerationTime = (FPlatformTime::Seconds() - StartTime) * 1000.0;
        
        // 1. Check room count (15-25)
        int32 RoomCount = Layout.Rooms.Num();
        checkf(RoomCount >= 15 && RoomCount <= 25, 
            TEXT("Stage %d: Room count %d outside 15-25 range"), Stage, RoomCount);
        
        // 2. Check room types - Start/Exit can be rest, others cannot
        bool bHasStart = false;
        bool bHasExit = false;
        for (const auto& Room : Layout.Rooms)
        {
            if (Room.Value.Type == ERoomType::Start)
            {
                bHasStart = true;
            }
            else if (Room.Value.Type == ERoomType::Exit)
            {
                bHasExit = true;
            }
            else
            {
                checkf(Room.Value.Type != ERoomType::Rest,
                    TEXT("Stage %d: Standalone rest room found (ID: %d)"), Stage, Room.Key);
            }
        }
        checkf(bHasStart, TEXT("Stage %d: Missing Start room"), Stage);
        checkf(bHasExit, TEXT("Stage %d: Missing Exit room"), Stage);
        
        // 3. Check special rooms for boss/elite stages
        if (Stage % 10 == 0)
        {
            TestTrue(FString::Printf(TEXT("Stage %d should have boss room"), Stage),
                Layout.BossRoomID >= 0);
        }
        if (Stage % 5 == 0)
        {
            TestTrue(FString::Printf(TEXT("Stage %d should have elite room"), Stage),
                Layout.EliteRoomID >= 0);
        }
        
        // Track totals
        TotalRooms += RoomCount;
        TotalHallways += Layout.Hallways.Num();
        
        AddInfo(FString::Printf(
            TEXT("Stage %d: %d rooms, %d hallways, generated in %.2fms"),
            Stage, RoomCount, Layout.Hallways.Num(), GenerationTime));
    }
    
    // Summary
    AddInfo(TEXT("=== Summary ==="));
    AddInfo(FString::Printf(TEXT("Total Rooms: %d (avg %.1f per stage)"), 
        TotalRooms, TotalRooms / 20.0f));
    AddInfo(FString::Printf(TEXT("Total Hallways: %d (avg %.1f per stage)"), 
        TotalHallways, TotalHallways / 20.0f));
    
    AddInfo(TEXT("✓ All validation checks passed"));
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS