// CubeDungeonGenerator.cpp
// Implementation of cube-based dungeon generation

#include "CubeDungeonGenerator.h"
#include "Engine/World.h"
#include "Async/Async.h"

ACubeDungeonGenerator::ACubeDungeonGenerator()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ACubeDungeonGenerator::BeginPlay()
{
    Super::BeginPlay();
}

FCubeDungeonLayout ACubeDungeonGenerator::GenerateCubeDungeon(int32 FloorNumber, const FIntVector& Dimensions)
{
    const double StartTime = FPlatformTime::Seconds();
    
    FCubeDungeonLayout Layout;
    Layout.FloorNumber = FloorNumber;
    Layout.GridDimensions = Dimensions;
    Layout.TotalCubes = Dimensions.X * Dimensions.Y * Dimensions.Z;
    
    // Generation pipeline
    InitializeCubeGrid(Layout);
    GenerateRoomClusters(Layout);
    CarveRooms(Layout);
    AssignPlanes(Layout);
    ConnectRooms(Layout);
    ClusterAdjacentCubes(Layout);
    OptimizeCubeData(Layout);
    
    // Calculate metrics
    const double EndTime = FPlatformTime::Seconds();
    Layout.GenerationTime = (EndTime - StartTime) * 1000.0f;
    
    return Layout;
}

void ACubeDungeonGenerator::GenerateCubeDungeonAsync(int32 FloorNumber, const FIntVector& Dimensions, FOnCubeDungeonGenerated OnComplete)
{
    Async(EAsyncExecution::ThreadPool, [this, FloorNumber, Dimensions, OnComplete]()
    {
        FCubeDungeonLayout Layout = GenerateCubeDungeon(FloorNumber, Dimensions);
        
        AsyncTask(ENamedThreads::GameThread, [OnComplete, Layout]()
        {
            OnComplete.ExecuteIfBound(Layout);
        });
    });
}

void ACubeDungeonGenerator::InitializeCubeGrid(FCubeDungeonLayout& Layout)
{
    // Initialize sparse grid - only create cubes we need
    // Start with empty grid, cubes will be added as needed
    Layout.CubeGrid.Reserve(Layout.TotalCubes * RoomDensity);
}

void ACubeDungeonGenerator::GenerateRoomClusters(FCubeDungeonLayout& Layout)
{
    int32 NextRoomID = 0;
    int32 TargetCubes = Layout.TotalCubes * RoomDensity;
    int32 PlacedCubes = 0;
    
    // Generate rooms until we reach target density
    while (PlacedCubes < TargetCubes)
    {
        // Random room origin
        FIntVector Origin(
            FMath::RandRange(0, Layout.GridDimensions.X - MaxRoomSize),
            FMath::RandRange(0, Layout.GridDimensions.Y - MaxRoomSize),
            FMath::RandRange(0, Layout.GridDimensions.Z - 1)
        );
        
        // Random room size
        FIntVector Size(
            FMath::RandRange(MinRoomSize, MaxRoomSize),
            FMath::RandRange(MinRoomSize, MaxRoomSize),
            FMath::RandRange(1, FMath::Min(3, Layout.GridDimensions.Z)) // Usually 1-3 cubes tall
        );
        
        // Choose room shape
        float ShapeRoll = FMath::FRand();
        if (ShapeRoll < 0.7f)
        {
            // 70% box rooms
            GenerateBoxRoom(Layout, Origin, Size, NextRoomID);
        }
        else
        {
            // 30% L-shaped rooms
            GenerateLShapedRoom(Layout, Origin, NextRoomID);
        }
        
        // Count placed cubes
        if (Layout.Rooms.Contains(NextRoomID))
        {
            PlacedCubes += Layout.Rooms[NextRoomID].GetVolume();
            NextRoomID++;
        }
        
        // Safety check
        if (NextRoomID > 100) break;
    }
    
    Layout.OccupiedCubes = PlacedCubes;
}

void ACubeDungeonGenerator::GenerateBoxRoom(FCubeDungeonLayout& Layout, const FIntVector& Origin, const FIntVector& Size, int32 RoomID)
{
    FCubeRoom Room;
    Room.RoomID = RoomID;
    Room.RoomType = ERoomType::Combat; // Default, will vary later
    
    // Create cubes for room
    for (int32 X = 0; X < Size.X; ++X)
    {
        for (int32 Y = 0; Y < Size.Y; ++Y)
        {
            for (int32 Z = 0; Z < Size.Z; ++Z)
            {
                FIntVector Position = Origin + FIntVector(X, Y, Z);
                
                // Skip if outside grid
                if (!Layout.IsValidPosition(Position))
                    continue;
                
                // Skip if already occupied
                if (Layout.CubeGrid.Contains(Position))
                    continue;
                
                // Create cube
                FDungeonCube Cube;
                Cube.GridPosition = Position;
                Cube.Type = (Z == 0) ? ECubeType::Floor : ECubeType::Empty;
                Cube.RoomID = RoomID;
                Cube.bIsOccupied = true;
                
                Layout.CubeGrid.Add(Position, Cube);
                Room.CubePositions.Add(Position);
            }
        }
    }
    
    // Only add room if it has cubes
    if (Room.CubePositions.Num() > 0)
    {
        Room.CalculateBounds();
        Layout.Rooms.Add(RoomID, Room);
    }
}

void ACubeDungeonGenerator::GenerateLShapedRoom(FCubeDungeonLayout& Layout, const FIntVector& Origin, int32 RoomID)
{
    FCubeRoom Room;
    Room.RoomID = RoomID;
    Room.RoomType = ERoomType::Puzzle; // L-shaped rooms are interesting for puzzles
    
    // Generate L-shape
    int32 Width1 = FMath::RandRange(MinRoomSize, MaxRoomSize);
    int32 Height1 = FMath::RandRange(MinRoomSize, MaxRoomSize);
    int32 Width2 = FMath::RandRange(MinRoomSize, MaxRoomSize);
    int32 Height2 = FMath::RandRange(MinRoomSize, MaxRoomSize);
    
    // First rectangle of L
    for (int32 X = 0; X < Width1; ++X)
    {
        for (int32 Y = 0; Y < Height1; ++Y)
        {
            FIntVector Position = Origin + FIntVector(X, Y, 0);
            
            if (!Layout.IsValidPosition(Position) || Layout.CubeGrid.Contains(Position))
                continue;
            
            FDungeonCube Cube;
            Cube.GridPosition = Position;
            Cube.Type = ECubeType::Floor;
            Cube.RoomID = RoomID;
            Cube.bIsOccupied = true;
            
            Layout.CubeGrid.Add(Position, Cube);
            Room.CubePositions.Add(Position);
        }
    }
    
    // Second rectangle of L (perpendicular)
    for (int32 X = 0; X < Width2; ++X)
    {
        for (int32 Y = 0; Y < Height2; ++Y)
        {
            FIntVector Position = Origin + FIntVector(Width1 + X - 1, Y, 0);
            
            if (!Layout.IsValidPosition(Position) || Layout.CubeGrid.Contains(Position))
                continue;
            
            FDungeonCube Cube;
            Cube.GridPosition = Position;
            Cube.Type = ECubeType::Floor;
            Cube.RoomID = RoomID;
            Cube.bIsOccupied = true;
            
            Layout.CubeGrid.Add(Position, Cube);
            Room.CubePositions.Add(Position);
        }
    }
    
    if (Room.CubePositions.Num() > 0)
    {
        Room.CalculateBounds();
        Layout.Rooms.Add(RoomID, Room);
    }
}

void ACubeDungeonGenerator::CarveRooms(FCubeDungeonLayout& Layout)
{
    // Process each room to carve out space and set cube types
    for (auto& RoomPair : Layout.Rooms)
    {
        FCubeRoom& Room = RoomPair.Value;
        
        for (const FIntVector& CubePos : Room.CubePositions)
        {
            if (FDungeonCube* Cube = Layout.GetCube(CubePos))
            {
                // Set cube types based on position in room
                bool bIsEdge = false;
                
                // Check if cube is at room edge
                TArray<FIntVector> Adjacent = Layout.GetAdjacentPositions(CubePos);
                for (const FIntVector& AdjPos : Adjacent)
                {
                    FDungeonCube* AdjCube = Layout.GetCube(AdjPos);
                    if (!AdjCube || AdjCube->RoomID != Room.RoomID)
                    {
                        bIsEdge = true;
                        break;
                    }
                }
                
                // Set type based on position
                if (bIsEdge)
                {
                    Cube->Type = ECubeType::Wall;
                }
                else if (CubePos.Z == 0)
                {
                    Cube->Type = ECubeType::Floor;
                }
                else
                {
                    Cube->Type = ECubeType::Empty;
                }
            }
        }
    }
}

void ACubeDungeonGenerator::AssignPlanes(FCubeDungeonLayout& Layout)
{
    // Assign plane types for each cube face
    for (auto& CubePair : Layout.CubeGrid)
    {
        FDungeonCube& Cube = CubePair.Value;
        const FIntVector& Position = CubePair.Key;
        
        // Check each face
        for (int32 FaceIndex = 0; FaceIndex < 6; ++FaceIndex)
        {
            EDungeonCubeFace Face = (EDungeonCubeFace)FaceIndex;
            
            // Get adjacent position in face direction
            FIntVector AdjacentPos = Position;
            switch (Face)
            {
                case EDungeonCubeFace::East:  AdjacentPos.X++; break;
                case EDungeonCubeFace::West:  AdjacentPos.X--; break;
                case EDungeonCubeFace::North: AdjacentPos.Y++; break;
                case EDungeonCubeFace::South: AdjacentPos.Y--; break;
                case EDungeonCubeFace::Top:   AdjacentPos.Z++; break;
                case EDungeonCubeFace::Bottom: AdjacentPos.Z--; break;
            }
            
            // Determine plane type based on adjacent cube
            FDungeonCube* AdjacentCube = Layout.GetCube(AdjacentPos);
            
            if (!Layout.IsValidPosition(AdjacentPos) || !AdjacentCube)
            {
                // Edge of world or empty space - solid wall
                SetPlaneType(Cube, Face, EPlaneType::Solid, true);
            }
            else if (AdjacentCube->RoomID != Cube.RoomID)
            {
                // Different room - potential door/window
                bool bIsDoor = (Face == EDungeonCubeFace::North || Face == EDungeonCubeFace::South || 
                               Face == EDungeonCubeFace::East || Face == EDungeonCubeFace::West) && 
                               FMath::FRand() < 0.2f; // 20% chance for door
                
                SetPlaneType(Cube, Face, bIsDoor ? EPlaneType::Door : EPlaneType::Solid, true);
                
                // Update adjacent cube's opposite face
                if (AdjacentCube)
                {
                    EDungeonCubeFace OppositeFace = GetOppositeFace(Face);
                    SetPlaneType(*AdjacentCube, OppositeFace, bIsDoor ? EPlaneType::Door : EPlaneType::Solid, true);
                }
            }
            else
            {
                // Same room - open space
                SetPlaneType(Cube, Face, EPlaneType::Open, false);
            }
        }
    }
}

void ACubeDungeonGenerator::SetPlaneType(FDungeonCube& Cube, EDungeonCubeFace Face, EPlaneType Type, bool bIsRoomBoundary)
{
    if (FCubePlane* Plane = Cube.GetPlane(Face))
    {
        Plane->Type = Type;
        Plane->bIsRoomBoundary = bIsRoomBoundary;
        Plane->RoomID = Cube.RoomID;
    }
}

void ACubeDungeonGenerator::ConnectRooms(FCubeDungeonLayout& Layout)
{
    // Create corridors between rooms
    TArray<int32> RoomIDs;
    Layout.Rooms.GetKeys(RoomIDs);
    
    // Connect each room to at least one other
    for (int32 i = 0; i < RoomIDs.Num(); ++i)
    {
        int32 FromRoomID = RoomIDs[i];
        
        // Find nearest unconnected room
        float MinDistance = FLT_MAX;
        int32 NearestRoomID = -1;
        
        for (int32 j = 0; j < RoomIDs.Num(); ++j)
        {
            if (i == j) continue;
            
            int32 ToRoomID = RoomIDs[j];
            FCubeRoom* FromRoom = Layout.Rooms.Find(FromRoomID);
            FCubeRoom* ToRoom = Layout.Rooms.Find(ToRoomID);
            
            if (!FromRoom || !ToRoom) continue;
            
            // Skip if already connected
            if (FromRoom->ConnectedRoomIDs.Contains(ToRoomID)) continue;
            
            // Calculate distance between room centers
            FVector FromCenter = FVector(FromRoom->MinBounds + FromRoom->MaxBounds) * 0.5f;
            FVector ToCenter = FVector(ToRoom->MinBounds + ToRoom->MaxBounds) * 0.5f;
            float Distance = FVector::Dist(FromCenter, ToCenter);
            
            if (Distance < MinDistance)
            {
                MinDistance = Distance;
                NearestRoomID = ToRoomID;
            }
        }
        
        // Create connection
        if (NearestRoomID >= 0)
        {
            CreateConnection(Layout, FromRoomID, NearestRoomID);
        }
    }
}

bool ACubeDungeonGenerator::CreateConnection(FCubeDungeonLayout& Layout, int32 Room1ID, int32 Room2ID)
{
    FCubeRoom* Room1 = Layout.Rooms.Find(Room1ID);
    FCubeRoom* Room2 = Layout.Rooms.Find(Room2ID);
    
    if (!Room1 || !Room2) return false;
    
    // Mark rooms as connected
    Room1->ConnectedRoomIDs.AddUnique(Room2ID);
    Room2->ConnectedRoomIDs.AddUnique(Room1ID);
    
    // Find closest cubes between rooms
    FIntVector Start = Room1->CubePositions[0];
    FIntVector End = Room2->CubePositions[0];
    float MinDist = FLT_MAX;
    
    for (const FIntVector& Pos1 : Room1->CubePositions)
    {
        for (const FIntVector& Pos2 : Room2->CubePositions)
        {
            float Dist = FVector::Dist(FVector(Pos1), FVector(Pos2));
            if (Dist < MinDist)
            {
                MinDist = Dist;
                Start = Pos1;
                End = Pos2;
            }
        }
    }
    
    // Create corridor path (simple straight line for now)
    TArray<FIntVector> Path = FindPath(Layout, Start, End);
    
    // Add corridor cubes
    for (const FIntVector& Position : Path)
    {
        if (!Layout.CubeGrid.Contains(Position))
        {
            FDungeonCube CorridorCube;
            CorridorCube.GridPosition = Position;
            CorridorCube.Type = ECubeType::Floor;
            CorridorCube.RoomID = -1; // Corridor ID
            CorridorCube.bIsOccupied = true;
            
            Layout.CubeGrid.Add(Position, CorridorCube);
        }
    }
    
    return true;
}

TArray<FIntVector> ACubeDungeonGenerator::FindPath(FCubeDungeonLayout& Layout, const FIntVector& Start, const FIntVector& End)
{
    TArray<FIntVector> Path;
    
    // Simple Manhattan path for now
    FIntVector Current = Start;
    
    while (Current != End)
    {
        // Move towards target one axis at a time
        if (Current.X != End.X)
        {
            Current.X += (End.X > Current.X) ? 1 : -1;
        }
        else if (Current.Y != End.Y)
        {
            Current.Y += (End.Y > Current.Y) ? 1 : -1;
        }
        else if (Current.Z != End.Z)
        {
            Current.Z += (End.Z > Current.Z) ? 1 : -1;
        }
        
        Path.Add(Current);
    }
    
    return Path;
}

void ACubeDungeonGenerator::ClusterAdjacentCubes(FCubeDungeonLayout& Layout)
{
    // Re-cluster cubes into rooms based on connectivity
    TSet<FIntVector> Visited;
    int32 NewRoomID = 1000; // Start new room IDs at 1000 to avoid conflicts
    
    for (auto& CubePair : Layout.CubeGrid)
    {
        const FIntVector& Position = CubePair.Key;
        
        if (Visited.Contains(Position)) continue;
        
        // Flood fill from this cube
        int32 ClusteredCubes = FloodFillRoom(Layout, Position, NewRoomID);
        
        if (ClusteredCubes > 0)
        {
            NewRoomID++;
        }
        
        Visited.Add(Position);
    }
}

int32 ACubeDungeonGenerator::FloodFillRoom(FCubeDungeonLayout& Layout, const FIntVector& Start, int32 RoomID)
{
    // Flood fill to assign room IDs to connected cubes
    TQueue<FIntVector> ToVisit;
    TSet<FIntVector> Visited;
    
    ToVisit.Enqueue(Start);
    int32 Count = 0;
    
    while (!ToVisit.IsEmpty())
    {
        FIntVector Current;
        ToVisit.Dequeue(Current);
        
        if (Visited.Contains(Current)) continue;
        Visited.Add(Current);
        
        FDungeonCube* Cube = Layout.GetCube(Current);
        if (!Cube || !Cube->bIsOccupied) continue;
        
        // Check if we can reach adjacent cubes
        TArray<FIntVector> Adjacent = Layout.GetAdjacentPositions(Current);
        
        for (const FIntVector& AdjPos : Adjacent)
        {
            if (Visited.Contains(AdjPos)) continue;
            
            FDungeonCube* AdjCube = Layout.GetCube(AdjPos);
            if (!AdjCube || !AdjCube->bIsOccupied) continue;
            
            // Check if there's an open connection
            EDungeonCubeFace FaceToAdj = GetFaceBetween(Current, AdjPos);
            FCubePlane* Plane = Cube->GetPlane(FaceToAdj);
            
            if (Plane && (Plane->Type == EPlaneType::Open || Plane->Type == EPlaneType::Door))
            {
                ToVisit.Enqueue(AdjPos);
            }
        }
        
        Count++;
    }
    
    return Count;
}

void ACubeDungeonGenerator::OptimizeCubeData(FCubeDungeonLayout& Layout)
{
    // Remove unused data and optimize memory
    RemoveUnusedCubes(Layout);
    MergePlanes(Layout);
}

void ACubeDungeonGenerator::RemoveUnusedCubes(FCubeDungeonLayout& Layout)
{
    // Remove empty cubes that don't contribute to structure
    TArray<FIntVector> ToRemove;
    
    for (const auto& CubePair : Layout.CubeGrid)
    {
        const FDungeonCube& Cube = CubePair.Value;
        
        // Keep only occupied cubes and walls
        if (!Cube.bIsOccupied && Cube.Type == ECubeType::Empty)
        {
            // Check if this cube has any room boundaries
            bool bHasRoomBoundary = false;
            for (const FCubePlane& Plane : Cube.Planes)
            {
                if (Plane.bIsRoomBoundary)
                {
                    bHasRoomBoundary = true;
                    break;
                }
            }
            
            if (!bHasRoomBoundary)
            {
                ToRemove.Add(CubePair.Key);
            }
        }
    }
    
    // Remove marked cubes
    for (const FIntVector& Position : ToRemove)
    {
        Layout.CubeGrid.Remove(Position);
    }
}

void ACubeDungeonGenerator::MergePlanes(FCubeDungeonLayout& Layout)
{
    // Merge adjacent planes of the same type to reduce draw calls
    // This is where we'd optimize plane data for rendering
    // For now, just ensure planes are properly set
    
    for (auto& CubePair : Layout.CubeGrid)
    {
        FDungeonCube& Cube = CubePair.Value;
        
        // Ensure all planes have proper material indices
        for (FCubePlane& Plane : Cube.Planes)
        {
            // Assign material based on plane type
            switch (Plane.Type)
            {
                case EPlaneType::Solid:
                    Plane.MaterialIndex = 0; // Stone
                    break;
                case EPlaneType::Door:
                    Plane.MaterialIndex = 1; // Wood
                    break;
                case EPlaneType::Window:
                    Plane.MaterialIndex = 2; // Glass
                    break;
                default:
                    Plane.MaterialIndex = 0;
                    break;
            }
        }
    }
}

EDungeonCubeFace ACubeDungeonGenerator::GetFaceBetween(const FIntVector& From, const FIntVector& To) const
{
    FIntVector Delta = To - From;
    
    if (Delta.X > 0) return EDungeonCubeFace::East;
    if (Delta.X < 0) return EDungeonCubeFace::West;
    if (Delta.Y > 0) return EDungeonCubeFace::North;
    if (Delta.Y < 0) return EDungeonCubeFace::South;
    if (Delta.Z > 0) return EDungeonCubeFace::Top;
    if (Delta.Z < 0) return EDungeonCubeFace::Bottom;
    
    return EDungeonCubeFace::North; // Default
}

EDungeonCubeFace ACubeDungeonGenerator::GetOppositeFace(EDungeonCubeFace Face) const
{
    switch (Face)
    {
        case EDungeonCubeFace::Top:    return EDungeonCubeFace::Bottom;
        case EDungeonCubeFace::Bottom: return EDungeonCubeFace::Top;
        case EDungeonCubeFace::North:  return EDungeonCubeFace::South;
        case EDungeonCubeFace::South:  return EDungeonCubeFace::North;
        case EDungeonCubeFace::East:   return EDungeonCubeFace::West;
        case EDungeonCubeFace::West:   return EDungeonCubeFace::East;
        default: return Face;
    }
}

bool ACubeDungeonGenerator::AreCubesAdjacent(const FIntVector& Cube1, const FIntVector& Cube2) const
{
    FIntVector Delta = Cube2 - Cube1;
    int32 ManhattanDist = FMath::Abs(Delta.X) + FMath::Abs(Delta.Y) + FMath::Abs(Delta.Z);
    return ManhattanDist == 1;
}