// SnakeDungeonGenerator.cpp
// Implementation of snake-path dungeon with proper spacing and stages

#include "SnakeDungeonGenerator.h"
#include "Engine/World.h"
#include "Async/Async.h"

ASnakeDungeonGenerator::ASnakeDungeonGenerator()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ASnakeDungeonGenerator::BeginPlay()
{
    Super::BeginPlay();
}

FSnakeDungeonLayout ASnakeDungeonGenerator::GenerateSnakeDungeon(int32 StageNumber)
{
    const double StartTime = FPlatformTime::Seconds();
    
    FSnakeDungeonLayout Layout;
    Layout.StageNumber = FMath::Clamp(StageNumber, 1, 20);
    
    // Determine stage type
    if (StageNumber % 10 == 0)
    {
        Layout.StageType = EStageType::Boss;
    }
    else if (StageNumber % 5 == 0)
    {
        Layout.StageType = EStageType::Elite;
    }
    else
    {
        Layout.StageType = EStageType::Normal;
    }
    
    // Generation pipeline
    InitializeStage(Layout);
    GenerateSnakePath(Layout);
    PlaceSpecialRooms(Layout);
    CreateHallwayConnections(Layout);
    AddBranchingPaths(Layout);
    
    // CRITICAL: Ensure all rooms are connected before filling empty space
    EnsureAllRoomsConnected(Layout);
    
    FillEmptySpace(Layout);
    OptimizeLayout(Layout);
    
    // VALIDATE: Ensure we have 15-25 rooms
    ValidateRoomCount(Layout);
    
    // Calculate metrics
    Layout.GenerationTime = (FPlatformTime::Seconds() - StartTime) * 1000.0f;
    
    UE_LOG(LogTemp, Display, TEXT("Generated Stage %d (%s) with %d rooms in %.2fms"),
        StageNumber,
        *UEnum::GetValueAsString(Layout.StageType),
        Layout.Rooms.Num(),
        Layout.GenerationTime);
    
    return Layout;
}

void ASnakeDungeonGenerator::GenerateSnakeDungeonAsync(int32 StageNumber, FOnSnakeDungeonGenerated OnComplete)
{
    Async(EAsyncExecution::ThreadPool, [this, StageNumber, OnComplete]()
    {
        FSnakeDungeonLayout Layout = GenerateSnakeDungeon(StageNumber);
        
        AsyncTask(ENamedThreads::GameThread, [OnComplete, Layout]()
        {
            OnComplete.ExecuteIfBound(Layout);
        });
    });
}

void ASnakeDungeonGenerator::InitializeStage(FSnakeDungeonLayout& Layout)
{
    // ALWAYS generate 15-25 rooms per floor
    int32 BaseRoomCount = FMath::RandRange(15, 25);
    
    // No reduction for boss/elite stages - maintain room count
    // Boss/Elite rooms will just be special rooms within the 15-25
    
    // Scale difficulty with stage number
    float StageMultiplier = 1.0f + (Layout.StageNumber * 0.1f);
    DifficultyMultiplier = StageMultiplier;
    
    // Set grid bounds based on room count - need more space for 15-25 rooms
    // Use larger grid to prevent placement failures
    Layout.GridBounds = FIntVector(
        300, // Fixed larger size for consistent generation
        300,
        10 // Keep vertical size limited
    );
    
    UE_LOG(LogTemp, Display, TEXT("Stage %d initialized with target room count: %d"), 
        Layout.StageNumber, BaseRoomCount);
}

void ASnakeDungeonGenerator::GenerateSnakePath(FSnakeDungeonLayout& Layout)
{
    // ENFORCE 15-25 rooms
    int32 TargetRoomCount = FMath::RandRange(15, 25);
    
    // Start room at center-bottom of grid
    FSnakeRoom StartRoom;
    StartRoom.RoomID = 0;
    StartRoom.Center = FIntVector(Layout.GridBounds.X / 2, Layout.GridBounds.Y / 2, 1);
    StartRoom.Size = FIntVector(
        FMath::RandRange(MinRoomSize, MaxRoomSize),
        FMath::RandRange(MinRoomSize, MaxRoomSize),
        3 // Standard height
    );
    StartRoom.Type = ERoomType::Start; // Explicitly mark as Start room (can be rest)
    StartRoom.PathOrder = 0;
    StartRoom.bIsMainPath = true;
    StartRoom.bAllowBranching = false; // No branches from start
    
    Layout.Rooms.Add(StartRoom.RoomID, StartRoom);
    Layout.MainPathRoomOrder.Add(StartRoom.RoomID);
    Layout.StartRoomID = StartRoom.RoomID;
    
    // Generate snake path
    FSnakeRoom* CurrentRoom = &Layout.Rooms[0];
    int32 CurrentDirection = FMath::RandRange(0, 3); // 0=North, 1=East, 2=South, 3=West
    int32 CurrentRoomRetries = 0; // Track retries per room
    
    for (int32 i = 1; i < TargetRoomCount; ++i)
    {
        // Calculate snake direction (creates winding path)
        CurrentDirection = CalculateSnakeDirection(i, TargetRoomCount);
        
        // Choose next room position with spacing
        TArray<FSnakeRoom> ExistingRooms;
        Layout.Rooms.GenerateValueArray(ExistingRooms);
        
        FIntVector NextPosition = ChooseNextRoomPosition(*CurrentRoom, ExistingRooms, CurrentDirection);
        
        // Create new room
        FSnakeRoom NewRoom;
        NewRoom.RoomID = i;
        NewRoom.Center = NextPosition;
        NewRoom.Size = FIntVector(
            FMath::RandRange(MinRoomSize, MaxRoomSize),
            FMath::RandRange(MinRoomSize, MaxRoomSize),
            FMath::RandRange(2, 4)
        );
        NewRoom.Type = DetermineRoomType(i, TargetRoomCount, Layout.StageType);
        NewRoom.PathOrder = i;
        NewRoom.bIsMainPath = true;
        NewRoom.bAllowBranching = (FMath::FRand() < BranchingChance) && (i > 2) && (i < TargetRoomCount - 2);
        
        // Try to place room without collision
        if (TryPlaceRoom(NewRoom, ExistingRooms, 1)) // 1 cube minimum spacing
        {
            Layout.Rooms.Add(NewRoom.RoomID, NewRoom);
            Layout.MainPathRoomOrder.Add(NewRoom.RoomID);
            
            // Connect to previous room
            CurrentRoom->ConnectedRooms.Add(NewRoom.RoomID);
            NewRoom.ConnectedRooms.Add(CurrentRoom->RoomID);
            
            CurrentRoom = &Layout.Rooms[NewRoom.RoomID];
            CurrentRoomRetries = 0; // Reset for next room
        }
        else
        {
            // Failed to place, try different direction
            i--; // Retry this room
            CurrentDirection = (CurrentDirection + 1) % 4;
            CurrentRoomRetries++;
            
            // Safety check to prevent infinite loop
            if (CurrentRoomRetries > 10)
            {
                UE_LOG(LogTemp, Warning, TEXT("Failed to place room %d after %d retries, ending path generation"), i, CurrentRoomRetries);
                break;
            }
        }
    }
    
    // Mark last room as exit
    if (Layout.MainPathRoomOrder.Num() > 0)
    {
        Layout.EndRoomID = Layout.MainPathRoomOrder.Last();
        if (FSnakeRoom* EndRoom = Layout.Rooms.Find(Layout.EndRoomID))
        {
            EndRoom->Type = ERoomType::Exit; // Explicitly mark as Exit room (can be rest)
        }
    }
    
    // Populate content markers for all rooms
    for (auto& RoomPair : Layout.Rooms)
    {
        PopulateRoomContent(RoomPair.Value);
    }
}

void ASnakeDungeonGenerator::PlaceSpecialRooms(FSnakeDungeonLayout& Layout)
{
    if (Layout.StageType == EStageType::Elite)
    {
        PlaceEliteRoom(Layout);
    }
    else if (Layout.StageType == EStageType::Boss)
    {
        PlaceBossRoom(Layout);
    }
    
    // Always try to place some treasure rooms
    PlaceTreasureRooms(Layout);
}

void ASnakeDungeonGenerator::PlaceEliteRoom(FSnakeDungeonLayout& Layout)
{
    // Place elite room around 60-70% through the path
    int32 ElitePosition = FMath::FloorToInt(Layout.MainPathRoomOrder.Num() * 0.65f);
    
    if (ElitePosition < Layout.MainPathRoomOrder.Num())
    {
        int32 EliteRoomID = Layout.MainPathRoomOrder[ElitePosition];
        if (FSnakeRoom* EliteRoom = Layout.Rooms.Find(EliteRoomID))
        {
            EliteRoom->Type = ERoomType::Combat;
            EliteRoom->StageType = EStageType::Elite;
            // Make elite rooms slightly larger
            EliteRoom->Size = EliteRoom->Size + FIntVector(2, 2, 0);
            Layout.EliteRoomID = EliteRoomID;
            
            UE_LOG(LogTemp, Display, TEXT("Placed Elite room at position %d"), ElitePosition);
        }
    }
}

void ASnakeDungeonGenerator::PlaceBossRoom(FSnakeDungeonLayout& Layout)
{
    // Boss room is always near the end (80-90% through path)
    int32 BossPosition = FMath::FloorToInt(Layout.MainPathRoomOrder.Num() * 0.85f);
    
    if (BossPosition < Layout.MainPathRoomOrder.Num())
    {
        int32 BossRoomID = Layout.MainPathRoomOrder[BossPosition];
        if (FSnakeRoom* BossRoom = Layout.Rooms.Find(BossRoomID))
        {
            BossRoom->Type = ERoomType::Boss;
            BossRoom->StageType = EStageType::Boss;
            // Boss rooms are much larger
            BossRoom->Size = FIntVector(
                FMath::Max(15, BossRoom->Size.X + 5),
                FMath::Max(15, BossRoom->Size.Y + 5),
                FMath::Max(5, BossRoom->Size.Z + 2)
            );
            Layout.BossRoomID = BossRoomID;
            
            UE_LOG(LogTemp, Display, TEXT("Placed Boss room at position %d"), BossPosition);
        }
    }
}

void ASnakeDungeonGenerator::PlaceTreasureRooms(FSnakeDungeonLayout& Layout)
{
    // Place 1-2 treasure rooms as branches
    int32 TreasureCount = FMath::RandRange(1, 2);
    
    for (int32 i = 0; i < TreasureCount; ++i)
    {
        // Find rooms that allow branching
        TArray<int32> BranchableRooms;
        for (const auto& RoomPair : Layout.Rooms)
        {
            if (RoomPair.Value.bAllowBranching && RoomPair.Value.ConnectedRooms.Num() < 3)
            {
                BranchableRooms.Add(RoomPair.Key);
            }
        }
        
        if (BranchableRooms.Num() > 0)
        {
            int32 BranchFromID = BranchableRooms[FMath::RandRange(0, BranchableRooms.Num() - 1)];
            FSnakeRoom* BranchFrom = Layout.Rooms.Find(BranchFromID);
            
            if (BranchFrom)
            {
                // Create treasure room as branch
                FSnakeRoom TreasureRoom;
                TreasureRoom.RoomID = Layout.Rooms.Num();
                TreasureRoom.Type = ERoomType::Treasure;
                TreasureRoom.bIsMainPath = false;
                TreasureRoom.Size = FIntVector(6, 6, 3); // Standard treasure room size
                
                // Try to place in different directions
                TArray<FSnakeRoom> ExistingRooms;
                Layout.Rooms.GenerateValueArray(ExistingRooms);
                
                for (int32 Dir = 0; Dir < 4; ++Dir)
                {
                    FIntVector Direction = GetDirectionVector(Dir);
                    TreasureRoom.Center = BranchFrom->Center + Direction * (BranchFrom->Size + TreasureRoom.Size + FIntVector(2, 2, 0));
                    
                    if (TryPlaceRoom(TreasureRoom, ExistingRooms, 1))
                    {
                        Layout.Rooms.Add(TreasureRoom.RoomID, TreasureRoom);
                        BranchFrom->ConnectedRooms.Add(TreasureRoom.RoomID);
                        TreasureRoom.ConnectedRooms.Add(BranchFromID);
                        
                        UE_LOG(LogTemp, Display, TEXT("Placed Treasure room branching from room %d"), BranchFromID);
                        break;
                    }
                }
            }
        }
    }
}

void ASnakeDungeonGenerator::CreateHallwayConnections(FSnakeDungeonLayout& Layout)
{
    // Create hallways for all connected rooms
    TSet<TPair<int32, int32>> ProcessedConnections;
    
    for (const auto& RoomPair : Layout.Rooms)
    {
        const FSnakeRoom& FromRoom = RoomPair.Value;
        
        for (int32 ToRoomID : FromRoom.ConnectedRooms)
        {
            // Avoid duplicate hallways
            TPair<int32, int32> Connection(FMath::Min(FromRoom.RoomID, ToRoomID), FMath::Max(FromRoom.RoomID, ToRoomID));
            if (ProcessedConnections.Contains(Connection))
            {
                continue;
            }
            ProcessedConnections.Add(Connection);
            
            if (const FSnakeRoom* ToRoom = Layout.Rooms.Find(ToRoomID))
            {
                // Create hallway path (1-2 cubes)
                TArray<FIntVector> HallwayPath = CreateHallway(FromRoom, *ToRoom, MaxHallwayLength);
                
                // CHECK FOR HALLWAY COLLISIONS
                if (HallwayPath.Num() > 0 && !CheckHallwayCollisions(HallwayPath, Layout))
                {
                    FHallwayConnection Hallway;
                    Hallway.FromRoomID = FromRoom.RoomID;
                    Hallway.ToRoomID = ToRoomID;
                    Hallway.Path = HallwayPath;
                    Hallway.Length = HallwayPath.Num();
                    Hallway.bIsMainPath = FromRoom.bIsMainPath && ToRoom->bIsMainPath;
                    
                    Layout.Hallways.Add(Hallway);
                }
                else if (HallwayPath.Num() > 0)
                {
                    // Hallway would collide, remove this connection
                    UE_LOG(LogTemp, Warning, TEXT("Hallway collision detected between rooms %d and %d, skipping connection"), 
                        FromRoom.RoomID, ToRoomID);
                }
            }
        }
    }
}

TArray<FIntVector> ASnakeDungeonGenerator::CreateHallway(const FSnakeRoom& FromRoom, const FSnakeRoom& ToRoom, int32 MaxLength)
{
    TArray<FIntVector> Path;
    
    // Get exit and entry points
    FIntVector Direction = ToRoom.Center - FromRoom.Center;
    // Normalize manually (FIntVector doesn't have Normalize)
    if (Direction.X != 0) Direction.X = FMath::Sign(Direction.X);
    if (Direction.Y != 0) Direction.Y = FMath::Sign(Direction.Y);
    if (Direction.Z != 0) Direction.Z = FMath::Sign(Direction.Z);
    
    FIntVector ExitPoint = GetRoomExitPoint(FromRoom, Direction);
    FIntVector EntryPoint = GetRoomEntryPoint(ToRoom, FIntVector(-Direction.X, -Direction.Y, -Direction.Z));
    
    // Create simple straight hallway (1-2 cubes)
    FIntVector Current = ExitPoint;
    FIntVector Target = EntryPoint;
    FIntVector Step = Target - Current;
    
    // Normalize to single steps
    if (Step.X != 0) Step.X = FMath::Sign(Step.X);
    if (Step.Y != 0) Step.Y = FMath::Sign(Step.Y);
    if (Step.Z != 0) Step.Z = FMath::Sign(Step.Z);
    
    int32 StepCount = 0;
    while (Current != Target && StepCount < MaxLength)
    {
        Current += Step;
        Path.Add(Current);
        StepCount++;
    }
    
    return Path;
}

FIntVector ASnakeDungeonGenerator::GetRoomExitPoint(const FSnakeRoom& Room, const FIntVector& Direction)
{
    // Get edge of room in direction of travel
    FIntVector ExitPoint = Room.Center;
    
    if (FMath::Abs(Direction.X) > FMath::Abs(Direction.Y))
    {
        // Exit on X axis
        ExitPoint.X += FMath::Sign(Direction.X) * (Room.Size.X / 2 + 1);
    }
    else
    {
        // Exit on Y axis
        ExitPoint.Y += FMath::Sign(Direction.Y) * (Room.Size.Y / 2 + 1);
    }
    
    return ExitPoint;
}

FIntVector ASnakeDungeonGenerator::GetRoomEntryPoint(const FSnakeRoom& Room, const FIntVector& Direction)
{
    // Get edge of room from direction of approach
    return GetRoomExitPoint(Room, Direction);
}

void ASnakeDungeonGenerator::AddBranchingPaths(FSnakeDungeonLayout& Layout)
{
    // Add some additional connections for variety
    int32 BranchCount = FMath::RandRange(1, 3);
    
    for (int32 i = 0; i < BranchCount; ++i)
    {
        // Find rooms that can have more connections
        TArray<int32> CandidateRooms;
        for (const auto& RoomPair : Layout.Rooms)
        {
            if (RoomPair.Value.ConnectedRooms.Num() == 1 && RoomPair.Value.bAllowBranching)
            {
                CandidateRooms.Add(RoomPair.Key);
            }
        }
        
        if (CandidateRooms.Num() >= 2)
        {
            // Connect two random rooms
            int32 Room1ID = CandidateRooms[FMath::RandRange(0, CandidateRooms.Num() - 1)];
            CandidateRooms.Remove(Room1ID);
            int32 Room2ID = CandidateRooms[FMath::RandRange(0, CandidateRooms.Num() - 1)];
            
            if (FSnakeRoom* Room1 = Layout.Rooms.Find(Room1ID))
            {
                if (FSnakeRoom* Room2 = Layout.Rooms.Find(Room2ID))
                {
                    // Check if connection is reasonable
                    float Distance = CalculatePathDistance(*Room1, *Room2);
                    if (Distance < 30.0f) // Don't connect rooms too far apart
                    {
                        Room1->ConnectedRooms.AddUnique(Room2ID);
                        Room2->ConnectedRooms.AddUnique(Room1ID);
                        
                        // Create hallway
                        TArray<FIntVector> HallwayPath = CreateHallway(*Room1, *Room2, MaxHallwayLength * 2);
                        
                        FHallwayConnection Hallway;
                        Hallway.FromRoomID = Room1ID;
                        Hallway.ToRoomID = Room2ID;
                        Hallway.Path = HallwayPath;
                        Hallway.Length = HallwayPath.Num();
                        Hallway.bIsMainPath = false;
                        
                        Layout.Hallways.Add(Hallway);
                    }
                }
            }
        }
    }
}

void ASnakeDungeonGenerator::FillEmptySpace(FSnakeDungeonLayout& Layout)
{
    // Fill empty spaces with solid cubes for underground feel
    FillWithSolidCubes(Layout);
    
    // Add atmospheric details
    CreateUndergroundAmbience(Layout);
}

void ASnakeDungeonGenerator::FillWithSolidCubes(FSnakeDungeonLayout& Layout)
{
    // Create a buffer zone around rooms and hallways
    const int32 BufferSize = 2;
    
    // Scan through grid and fill empty spaces
    for (int32 X = 0; X < Layout.GridBounds.X; X += 5) // Sample every 5 cubes for performance
    {
        for (int32 Y = 0; Y < Layout.GridBounds.Y; Y += 5)
        {
            for (int32 Z = 0; Z < Layout.GridBounds.Z; Z += 3)
            {
                FIntVector Position(X, Y, Z);
                
                if (!IsSpaceOccupied(Position, Layout))
                {
                    // Check distance to nearest room
                    float MinDistance = FLT_MAX;
                    for (const auto& RoomPair : Layout.Rooms)
                    {
                        float Distance = FVector::Dist(FVector(Position), FVector(RoomPair.Value.Center));
                        MinDistance = FMath::Min(MinDistance, Distance);
                    }
                    
                    // Only fill if far enough from rooms
                    if (MinDistance > BufferSize * 2)
                    {
                        FDungeonCube FillerCube;
                        FillerCube.GridPosition = Position;
                        FillerCube.Type = ECubeType::Solid;
                        FillerCube.bIsOccupied = true;
                        
                        // Set all planes to solid
                        for (FCubePlane& Plane : FillerCube.Planes)
                        {
                            Plane.Type = EPlaneType::Solid;
                        }
                        
                        Layout.FillerCubes.Add(Position, FillerCube);
                    }
                }
            }
        }
    }
    
    UE_LOG(LogTemp, Display, TEXT("Added %d filler cubes for underground ambience"), Layout.FillerCubes.Num());
}

bool ASnakeDungeonGenerator::IsSpaceOccupied(const FIntVector& Position, const FSnakeDungeonLayout& Layout)
{
    // Check if position is inside any room
    for (const auto& RoomPair : Layout.Rooms)
    {
        if (RoomPair.Value.ContainsPoint(Position, 1)) // 1 cube buffer
        {
            return true;
        }
    }
    
    // Check if position is in any hallway
    for (const FHallwayConnection& Hallway : Layout.Hallways)
    {
        for (const FIntVector& HallwayPos : Hallway.Path)
        {
            if (FVector::Dist(FVector(Position), FVector(HallwayPos)) < 2.0f)
            {
                return true;
            }
        }
    }
    
    return false;
}

void ASnakeDungeonGenerator::CreateUndergroundAmbience(FSnakeDungeonLayout& Layout)
{
    // Add stalactites, stalagmites, and other underground features
    // This would be expanded with actual mesh placement in a full implementation
}

void ASnakeDungeonGenerator::OptimizeLayout(FSnakeDungeonLayout& Layout)
{
    // Remove redundant filler cubes that aren't visible
    TArray<FIntVector> ToRemove;
    
    for (const auto& CubePair : Layout.FillerCubes)
    {
        // Check if cube is completely surrounded
        bool bSurrounded = true;
        TArray<FIntVector> Neighbors = {
            CubePair.Key + FIntVector(1, 0, 0),
            CubePair.Key + FIntVector(-1, 0, 0),
            CubePair.Key + FIntVector(0, 1, 0),
            CubePair.Key + FIntVector(0, -1, 0),
            CubePair.Key + FIntVector(0, 0, 1),
            CubePair.Key + FIntVector(0, 0, -1)
        };
        
        for (const FIntVector& Neighbor : Neighbors)
        {
            if (!Layout.FillerCubes.Contains(Neighbor))
            {
                bSurrounded = false;
                break;
            }
        }
        
        if (bSurrounded)
        {
            ToRemove.Add(CubePair.Key);
        }
    }
    
    // Remove hidden cubes
    for (const FIntVector& Position : ToRemove)
    {
        Layout.FillerCubes.Remove(Position);
    }
    
    UE_LOG(LogTemp, Display, TEXT("Optimized: Removed %d hidden filler cubes"), ToRemove.Num());
}

FIntVector ASnakeDungeonGenerator::ChooseNextRoomPosition(const FSnakeRoom& CurrentRoom, const TArray<FSnakeRoom>& ExistingRooms, int32 PreferredDirection)
{
    // Calculate position based on direction with proper spacing
    FIntVector Direction = GetDirectionVector(PreferredDirection);
    
    // Calculate proper distance: current room's half-size + new room's half-size + spacing
    // Use the actual room dimensions, not Size() which returns magnitude
    int32 CurrentRoomRadius = FMath::Max(CurrentRoom.Size.X, CurrentRoom.Size.Y) / 2;
    int32 NewRoomRadius = MaxRoomSize / 2; // Assume max size for safety
    int32 Spacing = FMath::RandRange(3, 8); // 3-8 cubes spacing between rooms
    int32 Distance = CurrentRoomRadius + NewRoomRadius + Spacing;
    
    FIntVector NewPosition = CurrentRoom.Center + Direction * Distance;
    
    // Add some variation to prevent perfectly straight paths
    if (FMath::FRand() < 0.3f) // 30% chance of offset
    {
        int32 PerpendicularDir = (PreferredDirection + 1) % 4;
        FIntVector PerpDirection = GetDirectionVector(PerpendicularDir);
        NewPosition += PerpDirection * FMath::RandRange(-5, 5);
    }
    
    // Keep within grid bounds (get bounds from first room which should have the layout info)
    // Use larger bounds to allow more room placement
    int32 GridSizeX = 300; // Increased from 150 for more space
    int32 GridSizeY = 300;
    NewPosition.X = FMath::Clamp(NewPosition.X, MaxRoomSize + 10, GridSizeX - MaxRoomSize - 10);
    NewPosition.Y = FMath::Clamp(NewPosition.Y, MaxRoomSize + 10, GridSizeY - MaxRoomSize - 10);
    NewPosition.Z = FMath::Clamp(NewPosition.Z, 0, 3); // Keep rooms on lower levels
    
    return NewPosition;
}

bool ASnakeDungeonGenerator::TryPlaceRoom(FSnakeRoom& NewRoom, const TArray<FSnakeRoom>& ExistingRooms, int32 MinSpacing)
{
    // Check collisions with all existing rooms
    for (const FSnakeRoom& ExistingRoom : ExistingRooms)
    {
        if (NewRoom.CollidesWith(ExistingRoom, MinSpacing))
        {
            return false;
        }
    }
    
    return true;
}

int32 ASnakeDungeonGenerator::CalculateSnakeDirection(int32 PathPosition, int32 TotalRooms)
{
    // Create a winding snake pattern
    float Progress = (float)PathPosition / TotalRooms;
    
    if (Progress < 0.25f)
    {
        return 1; // East
    }
    else if (Progress < 0.5f)
    {
        return 0; // North
    }
    else if (Progress < 0.75f)
    {
        return 3; // West
    }
    else
    {
        return FMath::RandRange(0, 1) == 0 ? 0 : 1; // North or East for variety
    }
}

bool ASnakeDungeonGenerator::CheckRoomCollisions(const FSnakeRoom& Room, const TMap<int32, FSnakeRoom>& ExistingRooms, int32 MinSpacing)
{
    for (const auto& RoomPair : ExistingRooms)
    {
        if (RoomPair.Key != Room.RoomID && Room.CollidesWith(RoomPair.Value, MinSpacing))
        {
            return true;
        }
    }
    return false;
}

bool ASnakeDungeonGenerator::CheckHallwayCollisions(const TArray<FIntVector>& Path, const FSnakeDungeonLayout& Layout)
{
    // Check each point in the new hallway path
    for (const FIntVector& PathPoint : Path)
    {
        // Check collision with existing hallways
        for (const FHallwayConnection& ExistingHallway : Layout.Hallways)
        {
            for (const FIntVector& ExistingPoint : ExistingHallway.Path)
            {
                // Hallways must not touch or overlap (minimum 1 cube spacing)
                if (FVector::Dist(FVector(PathPoint), FVector(ExistingPoint)) < 1.5f)
                {
                    return true; // Collision detected
                }
            }
        }
        
        // Also check that hallway doesn't pass through rooms (except endpoints)
        for (const auto& RoomPair : Layout.Rooms)
        {
            // Allow hallway endpoints to touch rooms (they're connections)
            bool bIsEndpoint = (PathPoint == Path[0] || PathPoint == Path.Last());
            
            if (!bIsEndpoint && RoomPair.Value.ContainsPoint(PathPoint, 0))
            {
                return true; // Hallway passes through a room
            }
        }
    }
    
    return false; // No collisions
}

void ASnakeDungeonGenerator::ValidateRoomCount(FSnakeDungeonLayout& Layout)
{
    int32 RoomCount = Layout.Rooms.Num();
    
    // If we don't have enough rooms, generate filler rooms
    if (RoomCount < 15)
    {
        UE_LOG(LogTemp, Warning, TEXT("Stage %d has only %d rooms, generating %d filler rooms"), 
            Layout.StageNumber, RoomCount, 15 - RoomCount);
        
        // Generate filler rooms in empty spaces
        for (int32 i = RoomCount; i < 15; ++i)
        {
            FSnakeRoom FillerRoom;
            FillerRoom.RoomID = i;
            FillerRoom.Type = ERoomType::Combat;
            FillerRoom.PathOrder = i;
            FillerRoom.bIsMainPath = false;
            FillerRoom.Size = FIntVector(3, 3, 2); // Small filler rooms
            
            // Try to place in random empty locations
            bool bPlaced = false;
            for (int32 Attempts = 0; Attempts < 20; ++Attempts)
            {
                FillerRoom.Center = FIntVector(
                    FMath::RandRange(10, Layout.GridBounds.X - 10),
                    FMath::RandRange(10, Layout.GridBounds.Y - 10),
                    0
                );
                
                TArray<FSnakeRoom> ExistingRooms;
                Layout.Rooms.GenerateValueArray(ExistingRooms);
                
                if (TryPlaceRoom(FillerRoom, ExistingRooms, 1))
                {
                    // Connect to nearest room BEFORE adding to layout
                    int32 NearestRoomID = FindNearestRoom(FillerRoom.Center, Layout.Rooms);
                    if (NearestRoomID >= 0)
                    {
                        FillerRoom.ConnectedRooms.Add(NearestRoomID);
                        Layout.Rooms[NearestRoomID].ConnectedRooms.Add(FillerRoom.RoomID);
                        
                        // Create hallway connection
                        FHallwayConnection Hallway;
                        Hallway.FromRoomID = NearestRoomID;
                        Hallway.ToRoomID = FillerRoom.RoomID;
                        
                        // Simple straight path
                        Hallway.Path.Add(Layout.Rooms[NearestRoomID].Center);
                        Hallway.Path.Add(FillerRoom.Center);
                        Hallway.Length = FVector::Dist(FVector(Layout.Rooms[NearestRoomID].Center), FVector(FillerRoom.Center));
                        
                        Layout.Hallways.Add(Hallway);
                    }
                    
                    Layout.Rooms.Add(FillerRoom.RoomID, FillerRoom);
                    bPlaced = true;
                    break;
                }
            }
            
            if (!bPlaced)
            {
                UE_LOG(LogTemp, Warning, TEXT("Could not place filler room %d"), i);
            }
        }
        
        RoomCount = Layout.Rooms.Num();
    }
    
    // Still check, but with warning instead of hard crash
    if (RoomCount < 15 || RoomCount > 25)
    {
        UE_LOG(LogTemp, Error, TEXT("WARNING: Stage %d has %d rooms, expected 15-25"), 
            Layout.StageNumber, RoomCount);
    }
    else
    {
        UE_LOG(LogTemp, Display, TEXT("Stage %d validated: %d rooms (15-25 required)"), 
            Layout.StageNumber, RoomCount);
    }
}

int32 ASnakeDungeonGenerator::FindNearestRoom(const FIntVector& Position, const TMap<int32, FSnakeRoom>& Rooms) const
{
    int32 NearestRoomID = -1;
    float MinDistance = FLT_MAX;
    
    for (const auto& RoomPair : Rooms)
    {
        float Distance = FVector::Dist(FVector(Position), FVector(RoomPair.Value.Center));
        if (Distance < MinDistance)
        {
            MinDistance = Distance;
            NearestRoomID = RoomPair.Key;
        }
    }
    
    return NearestRoomID;
}

FIntVector ASnakeDungeonGenerator::GetDirectionVector(int32 Direction) const
{
    switch (Direction)
    {
        case 0: return FIntVector(0, 1, 0);  // North
        case 1: return FIntVector(1, 0, 0);  // East
        case 2: return FIntVector(0, -1, 0); // South
        case 3: return FIntVector(-1, 0, 0); // West
        default: return FIntVector(0, 1, 0);
    }
}

float ASnakeDungeonGenerator::CalculatePathDistance(const FSnakeRoom& From, const FSnakeRoom& To) const
{
    return FVector::Dist(FVector(From.Center), FVector(To.Center));
}

void ASnakeDungeonGenerator::PopulateRoomContent(FSnakeRoom& Room)
{
    // Clear existing markers
    Room.ContentMarkers.Empty();
    
    switch (Room.Type)
    {
        case ERoomType::Combat:
            // Add 3-4 enemies per combat room
            AddEnemyMarkers(Room, FMath::RandRange(3, 4));
            break;
            
        case ERoomType::Treasure:
            // Add 1-2 treasure chests
            AddTreasureMarkers(Room, FMath::RandRange(1, 2));
            // Also add 1-2 guard enemies
            AddEnemyMarkers(Room, FMath::RandRange(1, 2));
            break;
            
        case ERoomType::Boss:
            // Add boss markers
            AddBossMarkers(Room);
            break;
            
        case ERoomType::Puzzle:
            // Add puzzle elements (spheres for interaction points)
            {
                FContentMarker PuzzleMarker;
                PuzzleMarker.Type = EContentMarkerType::Puzzle;
                PuzzleMarker.RelativePosition = FVector::ZeroVector;
                PuzzleMarker.Radius = 75.0f; // Larger sphere for puzzle elements
                Room.ContentMarkers.Add(PuzzleMarker);
            }
            break;
            
        case ERoomType::Start:
        case ERoomType::Exit:
            // Start and Exit rooms are rest areas - no enemies
            // Could add healing station markers here
            break;
            
        default:
            break;
    }
    
    // Handle elite rooms
    if (Room.StageType == EStageType::Elite && Room.Type == ERoomType::Combat)
    {
        AddEliteMarkers(Room);
    }
}

void ASnakeDungeonGenerator::AddEnemyMarkers(FSnakeRoom& Room, int32 Count)
{
    // Calculate room dimensions in world units
    FVector RoomSize = FVector(Room.Size) * CubeSize;
    
    for (int32 i = 0; i < Count; ++i)
    {
        FContentMarker EnemyMarker;
        EnemyMarker.Type = EContentMarkerType::Enemy;
        
        // Capsule dimensions for humanoid enemies
        EnemyMarker.Radius = 50.0f; // Capsule radius
        EnemyMarker.Height = 180.0f; // Human height
        
        // Position enemies strategically in the room
        float Angle = (360.0f / Count) * i;
        float Distance = FMath::Min(RoomSize.X, RoomSize.Y) * 0.3f; // 30% from center
        
        EnemyMarker.RelativePosition = FVector(
            FMath::Cos(FMath::DegreesToRadians(Angle)) * Distance,
            FMath::Sin(FMath::DegreesToRadians(Angle)) * Distance,
            0.0f // Floor level
        );
        
        // Set difficulty based on stage
        EnemyMarker.DifficultyTier = FMath::Clamp(1 + (Room.PathOrder / 5), 1, 3);
        
        Room.ContentMarkers.Add(EnemyMarker);
    }
}

void ASnakeDungeonGenerator::AddTreasureMarkers(FSnakeRoom& Room, int32 Count)
{
    for (int32 i = 0; i < Count; ++i)
    {
        FContentMarker ChestMarker;
        ChestMarker.Type = EContentMarkerType::Chest;
        
        // Sphere for treasure chests
        ChestMarker.Radius = 30.0f; // Small sphere
        ChestMarker.Height = 0.0f; // Not used for spheres
        
        // Position chests at room edges
        if (i == 0)
        {
            // Main chest at far end of room
            ChestMarker.RelativePosition = FVector(
                0.0f,
                Room.Size.Y * CubeSize * 0.4f,
                0.0f
            );
        }
        else
        {
            // Secondary chests in corners
            float X = (i % 2 == 0 ? -1.0f : 1.0f) * Room.Size.X * CubeSize * 0.4f;
            float Y = Room.Size.Y * CubeSize * 0.3f;
            ChestMarker.RelativePosition = FVector(X, Y, 0.0f);
        }
        
        Room.ContentMarkers.Add(ChestMarker);
    }
}

void ASnakeDungeonGenerator::AddBossMarkers(FSnakeRoom& Room)
{
    // Single boss enemy in center
    FContentMarker BossMarker;
    BossMarker.Type = EContentMarkerType::Boss;
    BossMarker.Radius = 100.0f; // Large capsule for boss
    BossMarker.Height = 300.0f; // Tall boss
    BossMarker.RelativePosition = FVector::ZeroVector; // Center of room
    BossMarker.DifficultyTier = 5; // Max difficulty
    BossMarker.ContentID = TEXT("Boss_Stage") + FString::FromInt(Room.PathOrder / 10);
    
    Room.ContentMarkers.Add(BossMarker);
    
    // Add minion spawn points
    AddEnemyMarkers(Room, 2); // 2 additional minions
}

void ASnakeDungeonGenerator::AddEliteMarkers(FSnakeRoom& Room)
{
    // Clear existing markers and add elite
    Room.ContentMarkers.Empty();
    
    FContentMarker EliteMarker;
    EliteMarker.Type = EContentMarkerType::Elite;
    EliteMarker.Radius = 75.0f; // Larger than normal enemies
    EliteMarker.Height = 220.0f; // Taller
    EliteMarker.RelativePosition = FVector::ZeroVector;
    EliteMarker.DifficultyTier = 4;
    EliteMarker.ContentID = TEXT("Elite_Stage") + FString::FromInt(Room.PathOrder / 5);
    
    Room.ContentMarkers.Add(EliteMarker);
    
    // Add support enemies
    AddEnemyMarkers(Room, 2);
}

ERoomType ASnakeDungeonGenerator::DetermineRoomType(int32 PathPosition, int32 TotalRooms, EStageType StageType) const
{
    float Progress = (float)PathPosition / TotalRooms;
    
    // First room is Start
    if (PathPosition == 0)
    {
        return ERoomType::Start;
    }
    
    // Last room is Exit
    if (PathPosition == TotalRooms - 1)
    {
        return ERoomType::Exit;
    }
    
    // NO REST ROOMS except for Start/Exit - removed rest stop logic
    
    // Random distribution for others (no rest rooms)
    float RandValue = FMath::FRand();
    
    if (RandValue < 0.55f)  // Increased combat chance since no rest
    {
        return ERoomType::Combat;
    }
    else if (RandValue < 0.75f)
    {
        return ERoomType::Puzzle;
    }
    else if (RandValue < 0.90f)
    {
        return ERoomType::Treasure;
    }
    else
    {
        return ERoomType::Empty;
    }
}

void ASnakeDungeonGenerator::EnsureAllRoomsConnected(FSnakeDungeonLayout& Layout)
{
    if (Layout.Rooms.Num() == 0 || Layout.StartRoomID < 0)
    {
        return;
    }
    
    // Find all rooms connected to the start room
    TSet<int32> ConnectedRooms = FindConnectedRooms(Layout, Layout.StartRoomID);
    
    // Check if all rooms are connected
    if (ConnectedRooms.Num() < Layout.Rooms.Num())
    {
        UE_LOG(LogTemp, Warning, TEXT("Found %d isolated rooms out of %d total rooms"), 
            Layout.Rooms.Num() - ConnectedRooms.Num(), Layout.Rooms.Num());
        
        // Connect isolated rooms
        ConnectIsolatedRooms(Layout, ConnectedRooms);
        
        // Verify connectivity after fix
        TSet<int32> VerifyConnected = FindConnectedRooms(Layout, Layout.StartRoomID);
        if (VerifyConnected.Num() < Layout.Rooms.Num())
        {
            // If still not all connected, try expanding grid
            UE_LOG(LogTemp, Warning, TEXT("Still have isolated rooms after connection attempts. Trying grid expansion."));
            ExpandGridIfNeeded(Layout);
            
            // Final attempt to connect
            ConnectedRooms = FindConnectedRooms(Layout, Layout.StartRoomID);
            ConnectIsolatedRooms(Layout, ConnectedRooms);
        }
    }
    
    UE_LOG(LogTemp, Display, TEXT("Connectivity check complete: %d/%d rooms connected"), 
        ConnectedRooms.Num(), Layout.Rooms.Num());
}

TSet<int32> ASnakeDungeonGenerator::FindConnectedRooms(const FSnakeDungeonLayout& Layout, int32 StartRoomID)
{
    TSet<int32> Connected;
    TQueue<int32> ToVisit;
    
    ToVisit.Enqueue(StartRoomID);
    
    while (!ToVisit.IsEmpty())
    {
        int32 CurrentID;
        ToVisit.Dequeue(CurrentID);
        
        if (Connected.Contains(CurrentID))
        {
            continue;
        }
        
        Connected.Add(CurrentID);
        
        // Add all connected rooms to the queue
        if (const FSnakeRoom* Room = Layout.Rooms.Find(CurrentID))
        {
            for (int32 ConnectedID : Room->ConnectedRooms)
            {
                if (!Connected.Contains(ConnectedID))
                {
                    ToVisit.Enqueue(ConnectedID);
                }
            }
        }
    }
    
    return Connected;
}

void ASnakeDungeonGenerator::ConnectIsolatedRooms(FSnakeDungeonLayout& Layout, const TSet<int32>& ConnectedRooms)
{
    // Find all isolated rooms
    TArray<int32> IsolatedRooms;
    for (const auto& RoomPair : Layout.Rooms)
    {
        if (!ConnectedRooms.Contains(RoomPair.Key))
        {
            IsolatedRooms.Add(RoomPair.Key);
        }
    }
    
    // Try to connect each isolated room to the nearest connected room
    for (int32 IsolatedID : IsolatedRooms)
    {
        if (TryConnectToNearestRoom(Layout, IsolatedID, ConnectedRooms))
        {
            UE_LOG(LogTemp, Display, TEXT("Successfully connected isolated room %d"), IsolatedID);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Failed to connect isolated room %d"), IsolatedID);
        }
    }
}

bool ASnakeDungeonGenerator::TryConnectToNearestRoom(FSnakeDungeonLayout& Layout, int32 IsolatedRoomID, const TSet<int32>& ConnectedRooms)
{
    FSnakeRoom* IsolatedRoom = Layout.Rooms.Find(IsolatedRoomID);
    if (!IsolatedRoom)
    {
        return false;
    }
    
    // Find the nearest connected room
    float MinDistance = FLT_MAX;
    int32 NearestRoomID = -1;
    
    for (int32 ConnectedID : ConnectedRooms)
    {
        if (const FSnakeRoom* ConnectedRoom = Layout.Rooms.Find(ConnectedID))
        {
            float Distance = FVector::Dist(FVector(IsolatedRoom->Center), FVector(ConnectedRoom->Center));
            if (Distance < MinDistance)
            {
                MinDistance = Distance;
                NearestRoomID = ConnectedID;
            }
        }
    }
    
    if (NearestRoomID == -1 || MinDistance > 50.0f) // Don't connect if too far
    {
        return false;
    }
    
    FSnakeRoom* NearestRoom = Layout.Rooms.Find(NearestRoomID);
    if (!NearestRoom)
    {
        return false;
    }
    
    // Create a connection
    IsolatedRoom->ConnectedRooms.AddUnique(NearestRoomID);
    NearestRoom->ConnectedRooms.AddUnique(IsolatedRoomID);
    
    // Create a hallway (allow slightly longer hallways for emergency connections)
    TArray<FIntVector> HallwayPath = CreateHallway(*IsolatedRoom, *NearestRoom, MaxHallwayLength * 3);
    
    if (HallwayPath.Num() > 0)
    {
        FHallwayConnection Hallway;
        Hallway.FromRoomID = IsolatedRoomID;
        Hallway.ToRoomID = NearestRoomID;
        Hallway.Path = HallwayPath;
        Hallway.Length = HallwayPath.Num();
        Hallway.bIsMainPath = false;
        
        Layout.Hallways.Add(Hallway);
        
        UE_LOG(LogTemp, Display, TEXT("Created emergency hallway from room %d to room %d (distance: %.1f)"), 
            IsolatedRoomID, NearestRoomID, MinDistance);
        
        return true;
    }
    
    return false;
}

void ASnakeDungeonGenerator::ExpandGridIfNeeded(FSnakeDungeonLayout& Layout)
{
    // Check if we're near grid boundaries
    bool bNeedExpansion = false;
    
    for (const auto& RoomPair : Layout.Rooms)
    {
        const FSnakeRoom& Room = RoomPair.Value;
        FIntVector MaxBounds = Room.Center + Room.Size;
        FIntVector MinBounds = Room.Center - Room.Size;
        
        if (MaxBounds.X > Layout.GridBounds.X - 20 || MaxBounds.Y > Layout.GridBounds.Y - 20 ||
            MinBounds.X < 20 || MinBounds.Y < 20)
        {
            bNeedExpansion = true;
            break;
        }
    }
    
    if (bNeedExpansion)
    {
        FIntVector OldBounds = Layout.GridBounds;
        Layout.GridBounds = FIntVector(
            Layout.GridBounds.X + 50,
            Layout.GridBounds.Y + 50,
            Layout.GridBounds.Z
        );
        
        UE_LOG(LogTemp, Display, TEXT("Expanded grid from (%d,%d,%d) to (%d,%d,%d)"), 
            OldBounds.X, OldBounds.Y, OldBounds.Z,
            Layout.GridBounds.X, Layout.GridBounds.Y, Layout.GridBounds.Z);
    }
}