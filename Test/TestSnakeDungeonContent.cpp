// TestSnakeDungeonContent.cpp
// Tests for content markers in Snake Dungeon rooms:
// - 3-4 enemies per combat room
// - Treasure chests in treasure rooms
// - Boss/Elite markers in special rooms

#include "CoreMinimal.h"
#include "SnakeDungeonGenerator.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "Engine/World.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * SNAKE DUNGEON CONTENT TESTS
 * ================================
 * Verify content marker placement in rooms
 */

// ============================================================================
// TEST 1: COMBAT ROOM ENEMIES - Ensure 3-4 enemies per combat room
// ============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestSnakeDungeonCombatEnemies, "EternalDescent.SnakeDungeon.Content.CombatEnemies",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTestSnakeDungeonCombatEnemies::RunTest(const FString& Parameters)
{
    // Setup
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    ASnakeDungeonGenerator* Generator = TestWorld->SpawnActor<ASnakeDungeonGenerator>();
    
    AddInfo(TEXT("=== Testing Combat Room Enemy Counts (3-4 per room) ==="));
    
    // Test multiple stages
    TArray<int32> TestStages = {1, 5, 10, 15, 20};
    
    for (int32 Stage : TestStages)
    {
        FSnakeDungeonLayout Layout = Generator->GenerateSnakeDungeon(Stage);
        
        int32 CombatRoomCount = 0;
        int32 ValidEnemyRooms = 0;
        
        for (const auto& RoomPair : Layout.Rooms)
        {
            const FSnakeRoom& Room = RoomPair.Value;
            
            if (Room.Type == ERoomType::Combat)
            {
                CombatRoomCount++;
                
                // Count enemy markers
                int32 EnemyCount = 0;
                for (const FContentMarker& Marker : Room.ContentMarkers)
                {
                    if (Marker.Type == EContentMarkerType::Enemy)
                    {
                        EnemyCount++;
                    }
                }
                
                // Should have 3-4 enemies
                if (EnemyCount >= 3 && EnemyCount <= 4)
                {
                    ValidEnemyRooms++;
                }
                else
                {
                    AddError(FString::Printf(TEXT("Stage %d Room %d: Has %d enemies, expected 3-4"), 
                        Stage, Room.RoomID, EnemyCount));
                }
                
                // Verify enemy markers have proper capsule dimensions
                for (const FContentMarker& Marker : Room.ContentMarkers)
                {
                    if (Marker.Type == EContentMarkerType::Enemy)
                    {
                        TestTrue(TEXT("Enemy capsule radius should be reasonable"), 
                            Marker.Radius > 30.0f && Marker.Radius < 100.0f);
                        TestTrue(TEXT("Enemy capsule height should be reasonable"), 
                            Marker.Height > 100.0f && Marker.Height < 250.0f);
                    }
                }
            }
        }
        
        AddInfo(FString::Printf(TEXT("Stage %d: %d/%d combat rooms have 3-4 enemies"), 
            Stage, ValidEnemyRooms, CombatRoomCount));
        
        TestEqual(TEXT("All combat rooms should have 3-4 enemies"), 
            ValidEnemyRooms, CombatRoomCount);
    }
    
    AddInfo(TEXT("✓ All combat rooms have proper enemy counts"));
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    return true;
}

// ============================================================================
// TEST 2: TREASURE ROOM CHESTS - Ensure treasure rooms have chest markers
// ============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestSnakeDungeonTreasureChests, "EternalDescent.SnakeDungeon.Content.TreasureChests",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTestSnakeDungeonTreasureChests::RunTest(const FString& Parameters)
{
    // Setup
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    ASnakeDungeonGenerator* Generator = TestWorld->SpawnActor<ASnakeDungeonGenerator>();
    
    AddInfo(TEXT("=== Testing Treasure Room Chest Markers ==="));
    
    FSnakeDungeonLayout Layout = Generator->GenerateSnakeDungeon(10); // Stage with variety
    
    int32 TreasureRoomCount = 0;
    int32 ValidTreasureRooms = 0;
    
    for (const auto& RoomPair : Layout.Rooms)
    {
        const FSnakeRoom& Room = RoomPair.Value;
        
        if (Room.Type == ERoomType::Treasure)
        {
            TreasureRoomCount++;
            
            // Count chest markers
            int32 ChestCount = 0;
            int32 GuardCount = 0;
            
            for (const FContentMarker& Marker : Room.ContentMarkers)
            {
                if (Marker.Type == EContentMarkerType::Chest)
                {
                    ChestCount++;
                    
                    // Verify chest is a sphere
                    TestTrue(TEXT("Chest should be a sphere (radius > 0)"), 
                        Marker.Radius > 0.0f);
                    TestEqual(TEXT("Chest sphere radius should be ~30"), 
                        FMath::RoundToInt(Marker.Radius), 30);
                }
                else if (Marker.Type == EContentMarkerType::Enemy)
                {
                    GuardCount++;
                }
            }
            
            // Should have 1-2 chests and 1-2 guards
            if (ChestCount >= 1 && ChestCount <= 2 && GuardCount >= 1 && GuardCount <= 2)
            {
                ValidTreasureRooms++;
                AddInfo(FString::Printf(TEXT("Treasure Room %d: %d chests, %d guards ✓"), 
                    Room.RoomID, ChestCount, GuardCount));
            }
            else
            {
                AddError(FString::Printf(TEXT("Treasure Room %d: %d chests, %d guards (expected 1-2 each)"), 
                    Room.RoomID, ChestCount, GuardCount));
            }
        }
    }
    
    if (TreasureRoomCount > 0)
    {
        TestEqual(TEXT("All treasure rooms should have proper content"), 
            ValidTreasureRooms, TreasureRoomCount);
    }
    else
    {
        AddInfo(TEXT("No treasure rooms in this layout"));
    }
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    return true;
}

// ============================================================================
// TEST 3: BOSS ROOM MARKERS - Ensure boss rooms have boss markers
// ============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestSnakeDungeonBossMarkers, "EternalDescent.SnakeDungeon.Content.BossMarkers",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTestSnakeDungeonBossMarkers::RunTest(const FString& Parameters)
{
    // Setup
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    ASnakeDungeonGenerator* Generator = TestWorld->SpawnActor<ASnakeDungeonGenerator>();
    
    AddInfo(TEXT("=== Testing Boss Room Markers ==="));
    
    // Test boss stages (10, 20)
    TArray<int32> BossStages = {10, 20};
    
    for (int32 Stage : BossStages)
    {
        FSnakeDungeonLayout Layout = Generator->GenerateSnakeDungeon(Stage);
        
        // Find boss room
        if (Layout.BossRoomID >= 0)
        {
            const FSnakeRoom* BossRoom = Layout.Rooms.Find(Layout.BossRoomID);
            TestNotNull(TEXT("Boss room should exist"), BossRoom);
            
            if (BossRoom)
            {
                // Check for boss marker
                bool bHasBossMarker = false;
                int32 MinionCount = 0;
                
                for (const FContentMarker& Marker : BossRoom->ContentMarkers)
                {
                    if (Marker.Type == EContentMarkerType::Boss)
                    {
                        bHasBossMarker = true;
                        
                        // Verify boss capsule is larger
                        TestTrue(TEXT("Boss should have large radius"), 
                            Marker.Radius >= 100.0f);
                        TestTrue(TEXT("Boss should be tall"), 
                            Marker.Height >= 300.0f);
                        TestEqual(TEXT("Boss should be max difficulty"), 
                            Marker.DifficultyTier, 5);
                    }
                    else if (Marker.Type == EContentMarkerType::Enemy)
                    {
                        MinionCount++;
                    }
                }
                
                TestTrue(FString::Printf(TEXT("Stage %d boss room should have boss marker"), Stage), 
                    bHasBossMarker);
                TestTrue(FString::Printf(TEXT("Stage %d boss room should have minions"), Stage), 
                    MinionCount >= 2);
                
                AddInfo(FString::Printf(TEXT("Stage %d Boss Room: Boss marker ✓, %d minions"), 
                    Stage, MinionCount));
            }
        }
        else
        {
            // Only boss stages should have boss rooms
            TestTrue(TEXT("Non-boss stage shouldn't have boss room"), 
                Stage % 10 != 0);
        }
    }
    
    AddInfo(TEXT("✓ Boss rooms have proper markers"));
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    return true;
}

// ============================================================================
// TEST 4: ELITE ROOM MARKERS - Ensure elite rooms have elite markers
// ============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestSnakeDungeonEliteMarkers, "EternalDescent.SnakeDungeon.Content.EliteMarkers",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTestSnakeDungeonEliteMarkers::RunTest(const FString& Parameters)
{
    // Setup
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    ASnakeDungeonGenerator* Generator = TestWorld->SpawnActor<ASnakeDungeonGenerator>();
    
    AddInfo(TEXT("=== Testing Elite Room Markers ==="));
    
    // Test elite stages (5, 15)
    TArray<int32> EliteStages = {5, 15};
    
    for (int32 Stage : EliteStages)
    {
        FSnakeDungeonLayout Layout = Generator->GenerateSnakeDungeon(Stage);
        
        // Find elite room
        if (Layout.EliteRoomID >= 0)
        {
            const FSnakeRoom* EliteRoom = Layout.Rooms.Find(Layout.EliteRoomID);
            TestNotNull(TEXT("Elite room should exist"), EliteRoom);
            
            if (EliteRoom)
            {
                // Check for elite marker
                bool bHasEliteMarker = false;
                int32 SupportCount = 0;
                
                for (const FContentMarker& Marker : EliteRoom->ContentMarkers)
                {
                    if (Marker.Type == EContentMarkerType::Elite)
                    {
                        bHasEliteMarker = true;
                        
                        // Verify elite is between normal and boss size
                        TestTrue(TEXT("Elite should have medium-large radius"), 
                            Marker.Radius >= 75.0f && Marker.Radius < 100.0f);
                        TestTrue(TEXT("Elite should be taller than normal"), 
                            Marker.Height >= 220.0f);
                        TestEqual(TEXT("Elite should be high difficulty"), 
                            Marker.DifficultyTier, 4);
                    }
                    else if (Marker.Type == EContentMarkerType::Enemy)
                    {
                        SupportCount++;
                    }
                }
                
                TestTrue(FString::Printf(TEXT("Stage %d elite room should have elite marker"), Stage), 
                    bHasEliteMarker);
                TestTrue(FString::Printf(TEXT("Stage %d elite room should have support enemies"), Stage), 
                    SupportCount >= 2);
                
                AddInfo(FString::Printf(TEXT("Stage %d Elite Room: Elite marker ✓, %d support enemies"), 
                    Stage, SupportCount));
            }
        }
    }
    
    AddInfo(TEXT("✓ Elite rooms have proper markers"));
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    return true;
}

// ============================================================================
// TEST 5: CONTENT MARKER POSITIONS - Ensure markers are positioned properly
// ============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTestSnakeDungeonMarkerPositions, "EternalDescent.SnakeDungeon.Content.MarkerPositions",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FTestSnakeDungeonMarkerPositions::RunTest(const FString& Parameters)
{
    // Setup
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::None, false);
    ASnakeDungeonGenerator* Generator = TestWorld->SpawnActor<ASnakeDungeonGenerator>();
    
    AddInfo(TEXT("=== Testing Content Marker Positioning ==="));
    
    FSnakeDungeonLayout Layout = Generator->GenerateSnakeDungeon(5);
    
    for (const auto& RoomPair : Layout.Rooms)
    {
        const FSnakeRoom& Room = RoomPair.Value;
        
        if (Room.ContentMarkers.Num() > 0)
        {
            // Calculate room bounds in world units (assuming 100 units per cube)
            float RoomSizeX = Room.Size.X * 100.0f;
            float RoomSizeY = Room.Size.Y * 100.0f;
            
            for (const FContentMarker& Marker : Room.ContentMarkers)
            {
                // Check that markers are within room bounds
                TestTrue(FString::Printf(TEXT("Room %d marker X position should be within bounds"), Room.RoomID),
                    FMath::Abs(Marker.RelativePosition.X) <= RoomSizeX * 0.5f);
                TestTrue(FString::Printf(TEXT("Room %d marker Y position should be within bounds"), Room.RoomID),
                    FMath::Abs(Marker.RelativePosition.Y) <= RoomSizeY * 0.5f);
                
                // Check that markers aren't overlapping (simplified check)
                for (const FContentMarker& OtherMarker : Room.ContentMarkers)
                {
                    if (&Marker != &OtherMarker)
                    {
                        float Distance = FVector::Dist(Marker.RelativePosition, OtherMarker.RelativePosition);
                        
                        // Markers should be at least their combined radii apart
                        float MinDistance = Marker.Radius + OtherMarker.Radius;
                        TestTrue(TEXT("Markers should not overlap"),
                            Distance >= MinDistance * 0.8f); // Allow slight overlap for gameplay
                    }
                }
            }
        }
    }
    
    AddInfo(TEXT("✓ Content markers are positioned properly"));
    
    // Cleanup
    TestWorld->DestroyWorld(false);
    return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS