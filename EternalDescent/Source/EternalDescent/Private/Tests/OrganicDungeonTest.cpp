// OrganicDungeonTest.cpp - Backend test for organic dungeon generation
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Tests/AutomationCommon.h"
#include "Tests/AutomationEditorCommon.h"
#include "GridDungeonVisualizer.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FOrganicDungeonGenerationTest, "EternalDescent.Dungeon.OrganicGeneration", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::ProductFilter)

bool FOrganicDungeonGenerationTest::RunTest(const FString& Parameters)
{
    // Test 1: Create dungeon generator and verify initialization
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::Game, false);
    TestNotNull(TEXT("Test world should be created"), TestWorld);
    
    AGridDungeonVisualizer* Generator = TestWorld->SpawnActor<AGridDungeonVisualizer>();
    TestNotNull(TEXT("Generator should spawn"), Generator);
    
    // Configure for organic generation
    Generator->GenerationType = EDungeonGenerationType::Organic;
    Generator->MinRoomCount = 10;
    Generator->MaxRoomCount = 15;
    Generator->MinRoomSize = 800.0f;
    Generator->MaxRoomSize = 2000.0f;
    Generator->HallwayWidth = 300.0f;
    Generator->MinRoomDistance = 400.0f;
    Generator->MaxRoomDistance = 1500.0f;
    Generator->BranchingFactor = 2;
    Generator->DeadEndChance = 0.3f;
    Generator->CurrentFloor = 1;
    
    // Test 2: Generate organic dungeon
    Generator->GenerateOrganicDungeon(12345); // Fixed seed for reproducibility
    
    // Test 3: Verify room generation
    TestTrue(TEXT("Should have generated rooms"), Generator->OrganicLayout.Rooms.Num() > 0);
    TestTrue(TEXT("Should have at least min rooms"), Generator->OrganicLayout.Rooms.Num() >= Generator->MinRoomCount);
    TestTrue(TEXT("Should not exceed max rooms"), Generator->OrganicLayout.Rooms.Num() <= Generator->MaxRoomCount);
    
    // Test 4: Verify start and exit rooms exist
    bool bHasStart = false;
    bool bHasExit = false;
    int32 MainPathRooms = 0;
    int32 BranchRooms = 0;
    
    for (const FOrganicRoom& Room : Generator->OrganicLayout.Rooms)
    {
        if (Room.RoomType == ERoomType::Start)
        {
            bHasStart = true;
            TestEqual(TEXT("Start room should be at origin"), Room.Position, FVector::ZeroVector);
            TestEqual(TEXT("Start room should be ID 0"), Room.RoomID, 0);
            TestTrue(TEXT("Start room should be on main path"), Room.bIsMainPath);
        }
        
        if (Room.RoomType == ERoomType::Exit)
        {
            bHasExit = true;
            TestTrue(TEXT("Exit room should be on main path"), Room.bIsMainPath);
        }
        
        if (Room.bIsMainPath)
        {
            MainPathRooms++;
        }
        else
        {
            BranchRooms++;
        }
        
        // Test room size constraints
        TestTrue(TEXT("Room width should be within bounds"), 
            Room.Size.X >= Generator->MinRoomSize && Room.Size.X <= Generator->MaxRoomSize);
        TestTrue(TEXT("Room height should be within bounds"), 
            Room.Size.Y >= Generator->MinRoomSize && Room.Size.Y <= Generator->MaxRoomSize);
    }
    
    TestTrue(TEXT("Should have start room"), bHasStart);
    TestTrue(TEXT("Should have exit room"), bHasExit);
    TestTrue(TEXT("Should have main path rooms"), MainPathRooms >= 5);
    TestTrue(TEXT("Should have some branch rooms"), BranchRooms > 0);
    
    // Test 5: Verify no room overlaps
    for (int32 i = 0; i < Generator->OrganicLayout.Rooms.Num(); ++i)
    {
        for (int32 j = i + 1; j < Generator->OrganicLayout.Rooms.Num(); ++j)
        {
            const FOrganicRoom& RoomA = Generator->OrganicLayout.Rooms[i];
            const FOrganicRoom& RoomB = Generator->OrganicLayout.Rooms[j];
            
            bool bOverlap = Generator->DoRoomsOverlap(RoomA, RoomB, 50.0f);
            TestFalse(FString::Printf(TEXT("Room %d and %d should not overlap"), i, j), bOverlap);
        }
    }
    
    // Test 6: Verify hallway connections
    TestTrue(TEXT("Should have hallways"), Generator->OrganicLayout.Hallways.Num() > 0);
    
    for (const FHallway& Hallway : Generator->OrganicLayout.Hallways)
    {
        TestTrue(TEXT("Hallway should connect valid rooms"), 
            Hallway.RoomA >= 0 && Hallway.RoomA < Generator->OrganicLayout.Rooms.Num());
        TestTrue(TEXT("Hallway should connect valid rooms"), 
            Hallway.RoomB >= 0 && Hallway.RoomB < Generator->OrganicLayout.Rooms.Num());
        TestTrue(TEXT("Hallway should have path points"), Hallway.PathPoints.Num() >= 2);
        TestEqual(TEXT("Hallway width should match setting"), Hallway.Width, Generator->HallwayWidth);
        
        // Verify rooms know about their connections (only if both rooms still exist)
        if (Hallway.RoomA < Generator->OrganicLayout.Rooms.Num() && 
            Hallway.RoomB < Generator->OrganicLayout.Rooms.Num())
        {
            const FOrganicRoom& RoomA = Generator->OrganicLayout.Rooms[Hallway.RoomA];
            const FOrganicRoom& RoomB = Generator->OrganicLayout.Rooms[Hallway.RoomB];
            TestTrue(TEXT("Room A should know about connection to Room B"), 
                RoomA.ConnectedRooms.Contains(Hallway.RoomB));
            TestTrue(TEXT("Room B should know about connection to Room A"), 
                RoomB.ConnectedRooms.Contains(Hallway.RoomA));
        }
    }
    
    // Test 7: Verify room connectivity (all rooms should be reachable)
    TSet<int32> VisitedRooms;
    TArray<int32> RoomsToVisit;
    RoomsToVisit.Add(0); // Start from room 0
    
    while (RoomsToVisit.Num() > 0)
    {
        int32 CurrentRoom = RoomsToVisit.Pop();
        if (VisitedRooms.Contains(CurrentRoom))
            continue;
            
        VisitedRooms.Add(CurrentRoom);
        
        if (CurrentRoom < Generator->OrganicLayout.Rooms.Num())
        {
            const FOrganicRoom& Room = Generator->OrganicLayout.Rooms[CurrentRoom];
            for (int32 ConnectedRoom : Room.ConnectedRooms)
            {
                if (!VisitedRooms.Contains(ConnectedRoom))
                {
                    RoomsToVisit.Add(ConnectedRoom);
                }
            }
        }
    }
    
    TestEqual(TEXT("All rooms should be connected"), VisitedRooms.Num(), Generator->OrganicLayout.Rooms.Num());
    
    // Test 8: Test room type distribution
    TMap<ERoomType, int32> RoomTypeCounts;
    for (const FOrganicRoom& Room : Generator->OrganicLayout.Rooms)
    {
        RoomTypeCounts.FindOrAdd(Room.RoomType)++;
    }
    
    TestTrue(TEXT("Should have exactly one start room"), RoomTypeCounts.FindOrAdd(ERoomType::Start) == 1);
    TestTrue(TEXT("Should have exactly one exit room"), RoomTypeCounts.FindOrAdd(ERoomType::Exit) == 1);
    TestTrue(TEXT("Should have some standard rooms"), RoomTypeCounts.FindOrAdd(ERoomType::Standard) > 0);
    
    // Test 9: Test depth values
    for (const FOrganicRoom& Room : Generator->OrganicLayout.Rooms)
    {
        TestTrue(TEXT("Room depth should be non-negative"), Room.Depth >= 0);
        
        if (Room.RoomType == ERoomType::Start)
        {
            TestEqual(TEXT("Start room should have depth 0"), Room.Depth, 0);
        }
        
        // Verify depth increases along connections
        for (int32 ConnectedID : Room.ConnectedRooms)
        {
            if (ConnectedID < Generator->OrganicLayout.Rooms.Num())
            {
                const FOrganicRoom& ConnectedRoom = Generator->OrganicLayout.Rooms[ConnectedID];
                int32 DepthDiff = FMath::Abs(Room.Depth - ConnectedRoom.Depth);
                TestTrue(TEXT("Connected rooms should have reasonable depth difference"), DepthDiff <= 2);
            }
        }
    }
    
    // Test 10: Performance test - generate multiple dungeons
    double TotalTime = 0.0;
    const int32 NumIterations = 10;
    
    for (int32 i = 0; i < NumIterations; ++i)
    {
        double StartTime = FPlatformTime::Seconds();
        Generator->GenerateOrganicDungeon(i * 100); // Different seeds
        double EndTime = FPlatformTime::Seconds();
        TotalTime += (EndTime - StartTime);
        
        TestTrue(FString::Printf(TEXT("Iteration %d should generate valid dungeon"), i), 
            Generator->OrganicLayout.Rooms.Num() > 0);
    }
    
    double AverageTime = TotalTime / NumIterations;
    TestTrue(FString::Printf(TEXT("Average generation time (%.3f ms) should be under 100ms"), AverageTime * 1000.0), 
        AverageTime < 0.1);
    
    // Test 11: Edge cases
    
    // Test minimum configuration
    Generator->MinRoomCount = 5;
    Generator->MaxRoomCount = 5;
    Generator->GenerateOrganicDungeon(999);
    TestEqual(TEXT("Should generate exactly 5 rooms with min=max=5"), Generator->OrganicLayout.Rooms.Num(), 5);
    
    // Test large room sizes
    Generator->MinRoomSize = 2500.0f;
    Generator->MaxRoomSize = 3000.0f;
    Generator->MaxRoomDistance = 4000.0f;
    Generator->GenerateOrganicDungeon(777);
    
    bool bAllRoomsLarge = true;
    for (const FOrganicRoom& Room : Generator->OrganicLayout.Rooms)
    {
        if (Room.Size.X < 2500.0f || Room.Size.Y < 2500.0f)
        {
            bAllRoomsLarge = false;
            break;
        }
    }
    TestTrue(TEXT("All rooms should respect large size constraints"), bAllRoomsLarge);
    
    // Test 12: Verify FindValidRoomPosition works correctly
    FOrganicRoom TestRoom;
    TestRoom.Position = FVector(0, 0, 0);
    TestRoom.Size = FVector2D(1000, 1000);
    TestRoom.bIsMainPath = true;
    TestRoom.Depth = 0;
    
    FVector NewPos = Generator->FindValidRoomPosition(TestRoom, FVector2D(800, 800), 500.0f, 2000.0f);
    float Distance = FVector::Dist(TestRoom.Position, NewPos);
    
    TestTrue(TEXT("New position should be at reasonable distance"), Distance >= 500.0f && Distance <= 3000.0f);
    
    // Cleanup
    TestWorld->DestroyActor(Generator);
    TestWorld->DestroyWorld(false);
    
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FOrganicDungeonStressTest, "EternalDescent.Dungeon.OrganicStressTest", 
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::ClientContext | EAutomationTestFlags::StressFilter)

bool FOrganicDungeonStressTest::RunTest(const FString& Parameters)
{
    UWorld* TestWorld = UWorld::CreateWorld(EWorldType::Game, false);
    AGridDungeonVisualizer* Generator = TestWorld->SpawnActor<AGridDungeonVisualizer>();
    
    // Configure for stress test
    Generator->GenerationType = EDungeonGenerationType::Organic;
    Generator->MinRoomCount = 40;
    Generator->MaxRoomCount = 50;
    Generator->MinRoomSize = 500.0f;
    Generator->MaxRoomSize = 4000.0f;
    Generator->BranchingFactor = 5;
    
    // Generate large dungeon
    double StartTime = FPlatformTime::Seconds();
    Generator->GenerateOrganicDungeon(54321);
    double EndTime = FPlatformTime::Seconds();
    
    double GenerationTime = EndTime - StartTime;
    
    TestTrue(TEXT("Should generate many rooms"), Generator->OrganicLayout.Rooms.Num() >= 40);
    TestTrue(TEXT("Should complete in reasonable time"), GenerationTime < 1.0);
    
    // Verify no crashes or invalid data
    for (const FOrganicRoom& Room : Generator->OrganicLayout.Rooms)
    {
        TestFalse(TEXT("Room position should not have NaN"), Room.Position.ContainsNaN());
        TestTrue(TEXT("Room size should be valid"), Room.Size.X > 0 && Room.Size.Y > 0);
        TestTrue(TEXT("Room ID should be valid"), Room.RoomID >= 0);
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Stress test: Generated %d rooms in %.3f ms"), 
        Generator->OrganicLayout.Rooms.Num(), GenerationTime * 1000.0);
    
    // Cleanup
    TestWorld->DestroyActor(Generator);
    TestWorld->DestroyWorld(false);
    
    return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS