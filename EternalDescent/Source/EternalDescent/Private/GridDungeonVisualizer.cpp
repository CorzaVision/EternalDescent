// GridDungeonVisualizer implementation - UE 5.5 compatible
#include "GridDungeonVisualizer.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"

AGridDungeonVisualizer::AGridDungeonVisualizer()
{
    PrimaryActorTick.bCanEverTick = false;
    
    // Create instanced mesh components
    PlaneInstances = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("PlaneInstances"));
    CubeInstances = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("CubeInstances"));
    TestEnemyInstances = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("TestEnemyInstances"));
    TestChestInstances = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("TestChestInstances"));
    
    RootComponent = PlaneInstances;
    CubeInstances->SetupAttachment(RootComponent);
    TestEnemyInstances->SetupAttachment(RootComponent);
    TestChestInstances->SetupAttachment(RootComponent);
    
    // Calculate grid dimensions
    UpdateGridDimensions();
}

void AGridDungeonVisualizer::ConfigureRoomCountForStage()
{
    switch (StageType)
    {
        case EDungeonStageType::Standard:
            MinRoomCount = 23;
            MaxRoomCount = 25;
            break;
        case EDungeonStageType::Elite:
            MinRoomCount = 23;
            MaxRoomCount = 26;
            break;
        case EDungeonStageType::Boss:
            MinRoomCount = 24;
            MaxRoomCount = 27;
            break;
    }
}

void AGridDungeonVisualizer::GetRoomCountForStageType(EDungeonStageType Stage, int32& OutMin, int32& OutMax) const
{
    switch (Stage)
    {
        case EDungeonStageType::Standard:
            OutMin = 23;
            OutMax = 25;
            break;
        case EDungeonStageType::Elite:
            OutMin = 23;
            OutMax = 26;
            break;
        case EDungeonStageType::Boss:
            OutMin = 24;
            OutMax = 27;
            break;
        default:
            OutMin = 23;
            OutMax = 25;
            break;
    }
}

void AGridDungeonVisualizer::GenerateOrganicDungeon(int32 Seed)
{
    ClearDungeon();
    
    // Configure room count based on stage type
    ConfigureRoomCountForStage();
    
    // Initialize random stream
    if (Seed == -1)
    {
        Seed = FMath::Rand();
    }
    RandomStream.Initialize(Seed);
    
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    UE_LOG(LogTemp, Warning, TEXT("Generating Organic Dungeon - Floor %d"), CurrentFloor);
    UE_LOG(LogTemp, Warning, TEXT("Stage Type: %s"), *UEnum::GetValueAsString(StageType));
    UE_LOG(LogTemp, Warning, TEXT("Seed: %d"), Seed);
    
    // Reset layout
    OrganicLayout = FOrganicDungeonLayout();
    OrganicLayout.FloorNumber = CurrentFloor;
    
    // Determine room count based on configured min/max
    int32 RoomCount = RandomStream.RandRange(MinRoomCount, MaxRoomCount);
    UE_LOG(LogTemp, Warning, TEXT("Target Room Count: %d (Min: %d, Max: %d)"), RoomCount, MinRoomCount, MaxRoomCount);
    
    // Generate starting room (always at origin)
    FOrganicRoom StartRoom;
    StartRoom.Position = FVector::ZeroVector;
    StartRoom.Size = FVector2D(
        RandomStream.FRandRange(MinRoomSize * 1.5f, MaxRoomSize), 
        RandomStream.FRandRange(MinRoomSize * 1.5f, MaxRoomSize)
    );
    StartRoom.RoomType = ERoomType::Start;
    StartRoom.RoomID = 0;
    StartRoom.bIsMainPath = true;
    StartRoom.Depth = 0;
    OrganicLayout.Rooms.Add(StartRoom);
    OrganicLayout.StartRoomID = 0;
    
    UE_LOG(LogTemp, Warning, TEXT("Start room placed at origin"));
    
    // Generate main path
    GenerateMainPath();
    
    // Generate branching rooms
    GenerateBranches();
    
    // Note: We don't trim rooms anymore as it would break hallway references
    // The actual room count may exceed the max slightly due to branching
    
    UE_LOG(LogTemp, Warning, TEXT("Generated %d rooms"), OrganicLayout.Rooms.Num());
    UE_LOG(LogTemp, Warning, TEXT("Generated %d hallways"), OrganicLayout.Hallways.Num());
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    
    // Visualize the dungeon
    VisualizeOrganicDungeon();
    
    if (bShowDebugGrid)
    {
        DrawDebugGrid();
    }
}

void AGridDungeonVisualizer::GenerateMainPath()
{
    // Create main path from start to end
    int32 MainPathLength = RandomStream.RandRange(5, 8);
    int32 CurrentRoomID = OrganicLayout.StartRoomID;
    
    for (int32 i = 0; i < MainPathLength; ++i)
    {
        const FOrganicRoom& CurrentRoom = OrganicLayout.Rooms[CurrentRoomID];
        
        // Determine room type for this position
        ERoomType NextRoomType = ERoomType::Standard;
        if (i == MainPathLength - 1)
        {
            NextRoomType = ERoomType::Exit; // Last room is exit
        }
        else if (i % 3 == 0 && i > 0)
        {
            NextRoomType = ERoomType::Combat;
        }
        else if (i == MainPathLength / 2 && CurrentFloor % 5 == 0)
        {
            NextRoomType = ERoomType::Boss;
        }
        
        // Generate next room size
        FVector2D NextRoomSize(
            RandomStream.FRandRange(MinRoomSize, MaxRoomSize),
            RandomStream.FRandRange(MinRoomSize, MaxRoomSize)
        );
        
        // Find valid position for next room
        FVector NextPosition = FindValidRoomPosition(
            CurrentRoom, 
            NextRoomSize,
            MinRoomDistance,
            MaxRoomDistance
        );
        
        // Create and add room
        FOrganicRoom NextRoom;
        NextRoom.Position = NextPosition;
        NextRoom.Size = NextRoomSize;
        NextRoom.RoomType = NextRoomType;
        NextRoom.RoomID = OrganicLayout.Rooms.Num();
        NextRoom.bIsMainPath = true;
        NextRoom.Depth = i + 1;
        
        // Connect rooms
        OrganicLayout.Rooms[CurrentRoomID].ConnectedRooms.Add(NextRoom.RoomID);
        NextRoom.ConnectedRooms.Add(CurrentRoomID);
        
        // Create hallway
        FHallway Hallway = CreateHallway(CurrentRoomID, NextRoom.RoomID);
        OrganicLayout.Hallways.Add(Hallway);
        
        // Add room to layout
        OrganicLayout.Rooms.Add(NextRoom);
        
        if (NextRoomType == ERoomType::Exit)
        {
            OrganicLayout.EndRoomID = NextRoom.RoomID;
        }
        
        CurrentRoomID = NextRoom.RoomID;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Main path created with %d rooms"), MainPathLength + 1);
}

void AGridDungeonVisualizer::GenerateBranches()
{
    // Add branching rooms off the main path
    TArray<int32> MainPathRooms;
    for (const FOrganicRoom& Room : OrganicLayout.Rooms)
    {
        if (Room.bIsMainPath)
        {
            MainPathRooms.Add(Room.RoomID);
        }
    }
    
    for (int32 MainRoomID : MainPathRooms)
    {
        int32 BranchCount = RandomStream.RandRange(0, BranchingFactor);
        
        for (int32 b = 0; b < BranchCount; ++b)
        {
            if (OrganicLayout.Rooms.Num() >= MaxRoomCount)
                break;
            
            const FOrganicRoom& MainRoom = OrganicLayout.Rooms[MainRoomID];
            
            // Determine branch room type
            ERoomType BranchType = ERoomType::Standard;
            float TypeRoll = RandomStream.FRand();
            if (TypeRoll < 0.2f)
            {
                BranchType = ERoomType::Treasure;
            }
            else if (TypeRoll < 0.4f && CurrentFloor >= 5)
            {
                BranchType = ERoomType::Elite;
            }
            else if (TypeRoll < 0.7f)
            {
                BranchType = ERoomType::Combat;
            }
            
            // Generate branch room
            FVector2D BranchSize(
                RandomStream.FRandRange(MinRoomSize, MaxRoomSize * 0.8f),
                RandomStream.FRandRange(MinRoomSize, MaxRoomSize * 0.8f)
            );
            
            FVector BranchPosition = FindValidRoomPosition(
                MainRoom,
                BranchSize,
                MinRoomDistance,
                MaxRoomDistance * 0.7f
            );
            
            // Check if position is valid (no overlaps)
            bool bValidPosition = true;
            FOrganicRoom TestRoom;
            TestRoom.Position = BranchPosition;
            TestRoom.Size = BranchSize;
            
            for (const FOrganicRoom& ExistingRoom : OrganicLayout.Rooms)
            {
                if (DoRoomsOverlap(TestRoom, ExistingRoom, 200.0f))
                {
                    bValidPosition = false;
                    break;
                }
            }
            
            if (!bValidPosition)
                continue;
            
            // Create branch room
            FOrganicRoom BranchRoom;
            BranchRoom.Position = BranchPosition;
            BranchRoom.Size = BranchSize;
            BranchRoom.RoomType = BranchType;
            BranchRoom.RoomID = OrganicLayout.Rooms.Num();
            BranchRoom.bIsMainPath = false;
            BranchRoom.Depth = MainRoom.Depth + 1;
            
            // Connect rooms
            OrganicLayout.Rooms[MainRoomID].ConnectedRooms.Add(BranchRoom.RoomID);
            BranchRoom.ConnectedRooms.Add(MainRoomID);
            
            // Create hallway
            FHallway Hallway = CreateHallway(MainRoomID, BranchRoom.RoomID);
            OrganicLayout.Hallways.Add(Hallway);
            
            // Add room
            OrganicLayout.Rooms.Add(BranchRoom);
            
            // Chance for dead end or continue branching
            if (RandomStream.FRand() > DeadEndChance && OrganicLayout.Rooms.Num() < MaxRoomCount)
            {
                // Create sub-branch
                FVector2D SubBranchSize(
                    RandomStream.FRandRange(MinRoomSize * 0.7f, MaxRoomSize * 0.6f),
                    RandomStream.FRandRange(MinRoomSize * 0.7f, MaxRoomSize * 0.6f)
                );
                
                FVector SubBranchPosition = FindValidRoomPosition(
                    BranchRoom,
                    SubBranchSize,
                    MinRoomDistance,
                    MaxRoomDistance * 0.5f
                );
                
                // Validate sub-branch position
                TestRoom.Position = SubBranchPosition;
                TestRoom.Size = SubBranchSize;
                bValidPosition = true;
                
                for (const FOrganicRoom& ExistingRoom : OrganicLayout.Rooms)
                {
                    if (DoRoomsOverlap(TestRoom, ExistingRoom, 200.0f))
                    {
                        bValidPosition = false;
                        break;
                    }
                }
                
                if (bValidPosition)
                {
                    FOrganicRoom SubBranch;
                    SubBranch.Position = SubBranchPosition;
                    SubBranch.Size = SubBranchSize;
                    SubBranch.RoomType = ERoomType::Standard;
                    SubBranch.RoomID = OrganicLayout.Rooms.Num();
                    SubBranch.bIsMainPath = false;
                    SubBranch.Depth = BranchRoom.Depth + 1;
                    
                    // Connect
                    OrganicLayout.Rooms[BranchRoom.RoomID].ConnectedRooms.Add(SubBranch.RoomID);
                    SubBranch.ConnectedRooms.Add(BranchRoom.RoomID);
                    
                    // Hallway
                    FHallway SubHallway = CreateHallway(BranchRoom.RoomID, SubBranch.RoomID);
                    OrganicLayout.Hallways.Add(SubHallway);
                    
                    OrganicLayout.Rooms.Add(SubBranch);
                }
            }
        }
    }
}

void AGridDungeonVisualizer::UpdateGridDimensions()
{
    GridSizeX = RoomsPerRow * TilesPerRoom;
    GridSizeY = RoomsPerColumn * TilesPerRoom;
    CellSize = TileSizeMultiplier * 100.0f; // Convert multiplier to actual units (3.5 = 350 units)
}

void AGridDungeonVisualizer::BeginPlay()
{
    Super::BeginPlay();
    InitializeComponents();
    
    if (bAutoGenerateOnBeginPlay)
    {
        GenerateAndVisualizeDungeon(-1);
    }
}

void AGridDungeonVisualizer::GenerateAndVisualizeDungeon(int32 Seed)
{
    ClearDungeon();
    
    // IMPORTANT: TDD/GDD requires GRID-BASED generation, not organic
    // Force grid generation to comply with TDD/GDD specifications
    GenerationType = EDungeonGenerationType::Grid;
    
    // TDD/GDD Specification: 5x5 room grid with 1 cell spacing
    // Each room is 2x2 to 3x3 cells, with 1 cell gap between rooms
    // Total grid size accounts for rooms + spacing
    
    UpdateGridDimensions();
    
    // Create layout with stage-appropriate room types
    FDungeonLayout TestLayout;
    TestLayout.FloorNumber = CurrentFloor;
    TestLayout.CurrentZone = EDungeonZone::SunkenCrypt;
    
    // Stage-based room restrictions:
    bool bCanHaveElite = CurrentFloor >= 5;
    bool bCanHaveBoss = (CurrentFloor % 5 == 0);
    
    // VOXEL GRID ROOM PLACEMENT with exact 1-cell spacing
    // Each room: 3x3 cells
    // Between rooms: 1 cell gap (filled with cubes)
    // Pattern: [ROOM-3x3][GAP-1][ROOM-3x3][GAP-1]...
    
    // Calculate how many rooms can fit with proper spacing
    // Formula: Room(3) + Gap(1) = 4 cells per room, plus 1 extra at start
    int32 CellsPerRoom = 4; // 3 for room + 1 for gap
    int32 MaxRoomsX = (GridSizeX - 1) / CellsPerRoom;
    int32 MaxRoomsY = (GridSizeY - 1) / CellsPerRoom;
    int32 ActualRoomsX = FMath::Min(RoomsPerRow, MaxRoomsX);
    int32 ActualRoomsY = FMath::Min(RoomsPerColumn, MaxRoomsY);
    
    // Generate rooms with exact voxel spacing
    int32 RoomIndex = 0;
    
    for (int32 Y = 0; Y < ActualRoomsY; ++Y)
    {
        for (int32 X = 0; X < ActualRoomsX; ++X)
        {
            FRoomData Room;
            // VOXEL PLACEMENT: Each room at exact grid position with 1-cell gaps
            // Position formula: Start(1) + Index * (RoomSize(3) + Gap(1))
            int32 RoomX = 1 + (X * 4); // Start at cell 1, then every 4 cells
            int32 RoomY = 1 + (Y * 4); // Same for Y axis
            Room.GridPosition = FIntVector(RoomX, RoomY, 0);
            
            // Assign room types strategically
            if (X == 0 && Y == 0)
            {
                // Start room at (0,0)
                Room.RoomType = ERoomType::Start;
                TestLayout.SpawnRoom = Room.GridPosition;
            }
            else if (X == ActualRoomsX - 1 && Y == ActualRoomsY - 1)
            {
                // Exit room at (4,4)
                Room.RoomType = ERoomType::Exit;
            }
            else if (X == 2 && Y == 2 && bCanHaveBoss)
            {
                // Boss room in center if allowed
                Room.RoomType = ERoomType::Boss;
            }
            else if ((X == 1 && Y == 3) || (X == 3 && Y == 1))
            {
                // Treasure rooms at specific locations
                Room.RoomType = ERoomType::Treasure;
            }
            else if (bCanHaveElite && ((X == 1 && Y == 1) || (X == 3 && Y == 3)))
            {
                // Elite rooms if floor 5+
                Room.RoomType = ERoomType::Elite;
            }
            else if (RoomIndex % 3 == 0)
            {
                // Every 3rd room is standard for breathing room
                Room.RoomType = ERoomType::Standard;
            }
            else
            {
                // Rest are combat rooms
                Room.RoomType = ERoomType::Combat;
            }
            
            TestLayout.Rooms.Add(Room.GridPosition, Room);
            RoomIndex++;
        }
    }
    
    // Log floor and room composition for debugging
    UE_LOG(LogTemp, Warning, TEXT("=========================================="));
    UE_LOG(LogTemp, Warning, TEXT("GridDungeonVisualizer: Generating Floor %d"), CurrentFloor);
    UE_LOG(LogTemp, Warning, TEXT("Elite rooms enabled: %s"), bCanHaveElite ? TEXT("Yes") : TEXT("No"));
    UE_LOG(LogTemp, Warning, TEXT("Boss room enabled: %s"), bCanHaveBoss ? TEXT("Yes") : TEXT("No"));
    UE_LOG(LogTemp, Warning, TEXT("Room Grid: %dx%d (Total: %d rooms)"), ActualRoomsX, ActualRoomsY, TestLayout.Rooms.Num());
    UE_LOG(LogTemp, Warning, TEXT("Voxel Grid: Every cell is %0.fx%0.fx%0.f units"), CellSize, CellSize, CellSize);
    UE_LOG(LogTemp, Warning, TEXT("=========================================="));
    
    BuildGridFromLayout(TestLayout);
    SpawnGridVisualization();
    SpawnRoomContents();
}

void AGridDungeonVisualizer::BuildGridFromLayout(const FDungeonLayout& Layout)
{
    InitializeGrid();
    CurrentLayout = Layout;
    
    // Place boundary walls around the entire grid perimeter
    PlaceBoundaryWalls();
    
    // First pass: Place all rooms in grid
    TArray<FRoomData> RoomArray;
    TMap<FIntPoint, int32> RoomPositionMap; // Map grid positions to room indices
    
    for (const auto& RoomPair : Layout.Rooms)
    {
        const FRoomData& Room = RoomPair.Value;
        PlaceRoomInGrid(Room);
        int32 RoomIndex = RoomArray.Add(Room);
        
        // Store room position for neighbor finding (using room grid coordinates)
        FIntPoint RoomCoord((Room.GridPosition.X - 1) / 4, (Room.GridPosition.Y - 1) / 4);
        RoomPositionMap.Add(RoomCoord, RoomIndex);
        
        // Track start and exit positions  
        if (Room.RoomType == ERoomType::Start)
        {
            StartRoomGridPos = FIntPoint(Room.GridPosition.X, Room.GridPosition.Y);
        }
        else if (Room.RoomType == ERoomType::Exit)
        {
            ExitRoomGridPos = FIntPoint(Room.GridPosition.X, Room.GridPosition.Y);
        }
    }
    
    // Second pass: Create LINEAR PATH with BRANCHES (no loops)
    // This creates a tree structure - no circular paths allowed
    TSet<int32> VisitedRooms;
    TArray<TPair<int32, int32>> MainPathConnections;
    TArray<TPair<int32, int32>> BranchConnections;
    
    // Step 1: Create main linear path from start to exit
    // Find start and exit room indices
    int32 StartRoomIdx = -1;
    int32 ExitRoomIdx = -1;
    for (int32 i = 0; i < RoomArray.Num(); ++i)
    {
        if (RoomArray[i].RoomType == ERoomType::Start) StartRoomIdx = i;
        if (RoomArray[i].RoomType == ERoomType::Exit) ExitRoomIdx = i;
    }
    
    // If no explicit start/exit, use corners
    if (StartRoomIdx == -1) StartRoomIdx = 0;
    if (ExitRoomIdx == -1) ExitRoomIdx = RoomArray.Num() - 1;
    
    // Build main path using BFS to find route from start to exit
    TArray<int32> MainPath;
    TMap<int32, int32> ParentMap;
    TQueue<int32> PathQueue;
    
    PathQueue.Enqueue(StartRoomIdx);
    VisitedRooms.Add(StartRoomIdx);
    ParentMap.Add(StartRoomIdx, -1);
    
    while (!PathQueue.IsEmpty())
    {
        int32 CurrentIdx;
        PathQueue.Dequeue(CurrentIdx);
        
        if (CurrentIdx == ExitRoomIdx)
            break;
            
        // Check neighbors
        FIntPoint CurrentCoord((RoomArray[CurrentIdx].GridPosition.X - 1) / 4, 
                               (RoomArray[CurrentIdx].GridPosition.Y - 1) / 4);
        
        TArray<FIntPoint> Directions = {
            FIntPoint(1, 0), FIntPoint(0, 1), 
            FIntPoint(-1, 0), FIntPoint(0, -1)
        };
        
        for (const FIntPoint& Dir : Directions)
        {
            FIntPoint NeighborCoord = CurrentCoord + Dir;
            if (int32* NeighborIdx = RoomPositionMap.Find(NeighborCoord))
            {
                if (!VisitedRooms.Contains(*NeighborIdx))
                {
                    VisitedRooms.Add(*NeighborIdx);
                    ParentMap.Add(*NeighborIdx, CurrentIdx);
                    PathQueue.Enqueue(*NeighborIdx);
                }
            }
        }
    }
    
    // Reconstruct main path
    int32 Current = ExitRoomIdx;
    while (Current != -1 && ParentMap.Contains(Current))
    {
        int32 Parent = ParentMap[Current];
        if (Parent != -1)
        {
            MainPathConnections.Add(TPair<int32, int32>(Parent, Current));
        }
        Current = Parent;
    }
    
    // Step 2: Add branches for unvisited rooms (creates tree structure, no loops)
    for (int32 i = 0; i < RoomArray.Num(); ++i)
    {
        if (!VisitedRooms.Contains(i))
        {
            // Find nearest visited room to connect to
            FIntPoint UnvisitedCoord((RoomArray[i].GridPosition.X - 1) / 4,
                                     (RoomArray[i].GridPosition.Y - 1) / 4);
            
            // Check immediate neighbors only
            TArray<FIntPoint> Directions = {
                FIntPoint(1, 0), FIntPoint(0, 1),
                FIntPoint(-1, 0), FIntPoint(0, -1)
            };
            
            for (const FIntPoint& Dir : Directions)
            {
                FIntPoint NeighborCoord = UnvisitedCoord + Dir;
                if (int32* NeighborIdx = RoomPositionMap.Find(NeighborCoord))
                {
                    if (VisitedRooms.Contains(*NeighborIdx))
                    {
                        // Connect to visited neighbor (creates branch)
                        BranchConnections.Add(TPair<int32, int32>(*NeighborIdx, i));
                        VisitedRooms.Add(i);
                        break;
                    }
                }
            }
        }
    }
    
    // Create hallway connections for main path
    for (const auto& Connection : MainPathConnections)
    {
        ConnectRoomsWithHallway(RoomArray[Connection.Key], RoomArray[Connection.Value]);
    }
    
    // Create hallway connections for branches
    for (const auto& Connection : BranchConnections)
    {
        ConnectRoomsWithHallway(RoomArray[Connection.Key], RoomArray[Connection.Value]);
    }
    
    // Step 3: Final verification - ensure no isolated rooms remain
    int32 IsolatedCount = 0;
    for (int32 i = 0; i < RoomArray.Num(); ++i)
    {
        if (!VisitedRooms.Contains(i))
        {
            IsolatedCount++;
            UE_LOG(LogTemp, Warning, TEXT("WARNING: Room %d at (%d,%d) is isolated!"), 
                   i, RoomArray[i].GridPosition.X, RoomArray[i].GridPosition.Y);
        }
    }
    
    // Log the final structure
    UE_LOG(LogTemp, Warning, TEXT("=========================================="));
    UE_LOG(LogTemp, Warning, TEXT("LINEAR PATH GENERATION COMPLETE"));
    UE_LOG(LogTemp, Warning, TEXT("=========================================="));
    UE_LOG(LogTemp, Warning, TEXT("Total Rooms: %d"), RoomArray.Num());
    UE_LOG(LogTemp, Warning, TEXT("Main Path: %d connections"), MainPathConnections.Num());
    UE_LOG(LogTemp, Warning, TEXT("Branches: %d connections"), BranchConnections.Num());
    UE_LOG(LogTemp, Warning, TEXT("Total Connections: %d"), MainPathConnections.Num() + BranchConnections.Num());
    UE_LOG(LogTemp, Warning, TEXT("Isolated Rooms: %d"), IsolatedCount);
    UE_LOG(LogTemp, Warning, TEXT("Structure Type: TREE (no loops)"));
    UE_LOG(LogTemp, Warning, TEXT("=========================================="));
}

void AGridDungeonVisualizer::ClearDungeon()
{
    if (PlaneInstances)
        PlaneInstances->ClearInstances();
    if (CubeInstances)
        CubeInstances->ClearInstances();
    if (TestEnemyInstances)
        TestEnemyInstances->ClearInstances();
    if (TestChestInstances)
        TestChestInstances->ClearInstances();
        
    Grid.Empty();
}

void AGridDungeonVisualizer::SpawnGridVisualization()
{
    // MINECRAFT/RIMWORLD VOXEL GRID: Every cell is a uniform block
    // Like Minecraft, the entire world is made of same-sized cubes
    // Like Rimworld, rooms are carved out of the cube grid with floor planes
    
    int32 FloorCount = 0;
    int32 CubeCount = 0;
    int32 TotalCells = GridSizeX * GridSizeY;
    
    if (!PlaneInstances || !CubeInstances) 
    {
        UE_LOG(LogTemp, Error, TEXT("GridDungeonVisualizer: Missing instance components!"));
        return;
    }
    
    if (!PlaneMesh || !CubeMesh)
    {
        UE_LOG(LogTemp, Error, TEXT("GridDungeonVisualizer: PlaneMesh or CubeMesh not set! Please assign in Blueprint."));
        return;
    }
    
    // Clear existing instances
    PlaneInstances->ClearInstances();
    CubeInstances->ClearInstances();
    
    UE_LOG(LogTemp, Warning, TEXT("VOXEL GRID: Generating %dx%d grid (%d total cells)"), GridSizeX, GridSizeY, TotalCells);
    
    // VOXEL GRID ALIGNMENT: Scale meshes to exactly match grid cell size
    // CRITICAL: Assuming standard UE4 cube is 100x100x100 units
    // If CellSize is 350, scale = 3.5 to make cube exactly 350x350x350
    float MeshBaseSize = 100.0f; // Standard cube mesh size
    float UniformCubeScale = CellSize / MeshBaseSize;
    
    UE_LOG(LogTemp, Warning, TEXT("Voxel Alignment: CellSize=%.0f, Scale=%.2f, Final Cube Size=%.0fx%.0fx%.0f"), 
           CellSize, UniformCubeScale, CellSize, CellSize, CellSize);
    
    // Process every single cell in the grid
    for (int32 Y = 0; Y < GridSizeY; ++Y)
    {
        for (int32 X = 0; X < GridSizeX; ++X)
        {
            FGridCell Cell = GetGridCell(X, Y);
            
            // VOXEL GRID POSITION: Calculate exact grid-aligned position
            // Meshes in UE4 spawn from their pivot point (usually center)
            // We need to position at cell CENTER for proper alignment
            FVector CellCenter;
            CellCenter.X = X * CellSize + (CellSize * 0.5f); // Center of cell
            CellCenter.Y = Y * CellSize + (CellSize * 0.5f); // Center of cell
            CellCenter.Z = 0.0f;
            
            switch (Cell.CellType)
            {
                case EGridCellType::Floor:
                case EGridCellType::Hallway:
                case EGridCellType::Door:
                    // Floor cells: Place a plane exactly aligned to grid
                    {
                        // Position plane at cell center for proper alignment
                        FVector PlanePos = CellCenter;
                        PlanePos.Z = 0.0f; // Planes at ground level
                        
                        // Scale plane to exactly fill one grid cell
                        // Note: Plane mesh is typically 100x100 in X,Y
                        FTransform PlaneTransform(
                            FRotator::ZeroRotator, 
                            PlanePos, 
                            FVector(UniformCubeScale, UniformCubeScale, 1.0f) // Keep Z thin for floor
                        );
                        PlaneInstances->AddInstance(PlaneTransform);
                        FloorCount++;
                    }
                    break;
                    
                case EGridCellType::Wall:
                case EGridCellType::Empty:
                default:
                    // All non-floor cells: Place a cube exactly aligned to grid
                    {
                        // Position cube at cell center
                        FVector CubePos = CellCenter;
                        CubePos.Z = CellSize * 0.5f; // Raise cube so bottom is at ground level
                        
                        // Scale cube to exactly fill one grid cell (350x350x350)
                        FTransform CubeTransform(
                            FRotator::ZeroRotator, 
                            CubePos, 
                            FVector(UniformCubeScale, UniformCubeScale, UniformCubeScale)
                        );
                        CubeInstances->AddInstance(CubeTransform);
                        CubeCount++;
                    }
                    break;
            }
        }
    }
    
    // Log statistics
    UE_LOG(LogTemp, Warning, TEXT("=========================================="));
    UE_LOG(LogTemp, Warning, TEXT("VOXEL GRID GENERATION COMPLETE"));
    UE_LOG(LogTemp, Warning, TEXT("Grid Size: %dx%d cells"), GridSizeX, GridSizeY);
    UE_LOG(LogTemp, Warning, TEXT("Cell Size: %.0f units"), CellSize);
    UE_LOG(LogTemp, Warning, TEXT("Cube Scale: %.2fx"), UniformCubeScale);
    UE_LOG(LogTemp, Warning, TEXT("Floor Planes: %d"), FloorCount);
    UE_LOG(LogTemp, Warning, TEXT("Cubes Placed: %d"), CubeCount);
    UE_LOG(LogTemp, Warning, TEXT("Total Cells: %d"), TotalCells);
    UE_LOG(LogTemp, Warning, TEXT("=========================================="));
    
    // Draw debug grid if enabled
    if (bShowDebugGrid)
    {
        DrawDebugGrid();
    }
}

void AGridDungeonVisualizer::DrawDebugGrid()
{
    UWorld* World = GetWorld();
    if (!World) return;
    
    // Clear any previous debug lines
    FlushPersistentDebugLines(World);
    
#if WITH_EDITOR
    // Use editor-specific drawing if in editor
    if (!World->IsGameWorld())
    {
        // Force flush for editor
        FlushDebugStrings(World);
    }
#endif
    
    FVector GridOrigin = GetActorLocation();
    float TotalWidth = GridSizeX * CellSize;
    float TotalHeight = GridSizeY * CellSize;
    
    // Draw vertical lines (along Y axis)
    for (int32 X = 0; X <= GridSizeX; ++X)
    {
        FVector LineStart = GridOrigin + FVector(X * CellSize, 0, 10.0f);
        FVector LineEnd = GridOrigin + FVector(X * CellSize, TotalHeight, 10.0f);
        
        // Make boundary lines thicker/different color
        bool bIsBoundary = (X == 0 || X == GridSizeX);
        FColor LineColor = bIsBoundary ? FColor::Red : DebugGridColor.ToFColor(true);
        float Thickness = bIsBoundary ? DebugLineThickness * 2 : DebugLineThickness;
        
        DrawDebugLine(World, LineStart, LineEnd, LineColor, true, DebugDrawDuration, 0, Thickness);
    }
    
    // Draw horizontal lines (along X axis)
    for (int32 Y = 0; Y <= GridSizeY; ++Y)
    {
        FVector LineStart = GridOrigin + FVector(0, Y * CellSize, 10.0f);
        FVector LineEnd = GridOrigin + FVector(TotalWidth, Y * CellSize, 10.0f);
        
        // Make boundary lines thicker/different color
        bool bIsBoundary = (Y == 0 || Y == GridSizeY);
        FColor LineColor = bIsBoundary ? FColor::Red : DebugGridColor.ToFColor(true);
        float Thickness = bIsBoundary ? DebugLineThickness * 2 : DebugLineThickness;
        
        DrawDebugLine(World, LineStart, LineEnd, LineColor, true, DebugDrawDuration, 0, Thickness);
    }
    
    // Draw cell numbers for first few rows/cols to help visualize
    for (int32 X = 0; X < FMath::Min(10, GridSizeX); ++X)
    {
        for (int32 Y = 0; Y < FMath::Min(10, GridSizeY); ++Y)
        {
            FVector CellCenter = GridToWorldPosition(X, Y, true);
            CellCenter.Z = 20.0f;
            
            FString CellText = FString::Printf(TEXT("%d,%d"), X, Y);
            DrawDebugString(World, CellCenter, CellText, nullptr, FColor::White, DebugDrawDuration, false, 0.5f);
        }
    }
    
    // Draw room boundaries with different colors
    for (const auto& RoomPair : CurrentLayout.Rooms)
    {
        const FRoomData& Room = RoomPair.Value;
        int32 RoomSpacing = 5;
        int32 StartX = Room.GridPosition.X * RoomSpacing + 1;
        int32 StartY = Room.GridPosition.Y * RoomSpacing + 1;
        int32 RoomSize = 5; // Total room size including walls
        
        // Draw room outline
        FVector RoomMin = GridOrigin + FVector(StartX * CellSize, StartY * CellSize, 15.0f);
        FVector RoomMax = GridOrigin + FVector((StartX + RoomSize) * CellSize, (StartY + RoomSize) * CellSize, 15.0f);
        
        FColor RoomColor = FColor::Yellow;
        switch (Room.RoomType)
        {
            case ERoomType::Start: RoomColor = FColor::Green; break;
            case ERoomType::Exit: RoomColor = FColor::Blue; break;
            case ERoomType::Boss: RoomColor = FColor::Red; break;
            case ERoomType::Treasure: RoomColor = FColor::Yellow; break;
            case ERoomType::Elite: RoomColor = FColor::Orange; break;
            case ERoomType::Combat: RoomColor = FColor::Purple; break;
            default: break;
        }
        
        // Draw room rectangle
        DrawDebugBox(World, 
            (RoomMin + RoomMax) * 0.5f, 
            FVector((RoomMax.X - RoomMin.X) * 0.5f, (RoomMax.Y - RoomMin.Y) * 0.5f, 5.0f),
            RoomColor, true, DebugDrawDuration, 0, 3.0f);
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Debug Grid: Drew %dx%d grid with cell size %.0f"), GridSizeX, GridSizeY, CellSize);
}

void AGridDungeonVisualizer::ClearDebugGrid()
{
    UWorld* World = GetWorld();
    if (World)
    {
        FlushPersistentDebugLines(World);
#if WITH_EDITOR
        FlushDebugStrings(World);
#endif
    }
}

void AGridDungeonVisualizer::ToggleDebugGridInEditor()
{
#if WITH_EDITOR
    bShowDebugGrid = !bShowDebugGrid;
    
    if (bShowDebugGrid)
    {
        // Generate if nothing exists
        if (Grid.Num() == 0)
        {
            GenerateAndVisualizeDungeon(-1);
        }
        DrawDebugGrid();
        UE_LOG(LogTemp, Warning, TEXT("Debug Grid ENABLED - Showing grid overlay"));
    }
    else
    {
        ClearDebugGrid();
        UE_LOG(LogTemp, Warning, TEXT("Debug Grid DISABLED"));
    }
#endif
}

void AGridDungeonVisualizer::GenerateInEditor()
{
#if WITH_EDITOR
    // Clear existing
    ClearDungeon();
    ClearDebugGrid();
    
    // Generate new dungeon
    GenerateAndVisualizeDungeon(-1);
    
    // Show debug if enabled
    if (bShowDebugGrid)
    {
        DrawDebugGrid();
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Generated dungeon in editor with %d rooms"), CurrentLayout.Rooms.Num());
#endif
}

void AGridDungeonVisualizer::SpawnRoomContents()
{
    // Spawn content for all 6 room types as requested by user
    for (const auto& RoomPair : CurrentLayout.Rooms)
    {
        const FRoomData& Room = RoomPair.Value;
        // Calculate room center based on new room spacing (5 tiles per room, center at +2.5)
        int32 RoomSpacing = 5;
        FVector RoomCenter = GridToWorldPosition(
            Room.GridPosition.X * RoomSpacing + 2, 
            Room.GridPosition.Y * RoomSpacing + 2, 
            true
        );
        // Different heights for different content types
        float ContentHeight = 0.0f;
        
        switch (Room.RoomType)
        {
            case ERoomType::Start:
                // Start room - spawn player here
                UE_LOG(LogTemp, Warning, TEXT("Start room spawned at %s"), *RoomCenter.ToString());
                break;
                
            case ERoomType::Combat:
                // Combat room - spawn standard enemies on ground
                {
                    FVector EnemyPos = RoomCenter;
                    EnemyPos.Z = 100.0f; // Enemy center at mannequin height
                    FTransform EnemyTransform(FRotator::ZeroRotator, EnemyPos, FVector(TestEnemyScale));
                    if (TestEnemyInstances)
                        TestEnemyInstances->AddInstance(EnemyTransform);
                    OnTestEnemySpawned(EnemyPos, Room.RoomType);
                }
                break;
                
            case ERoomType::Elite:
                // Elite room - spawn harder enemies on ground (larger scale)
                {
                    FVector ElitePos = RoomCenter;
                    ElitePos.Z = 150.0f; // Slightly higher for larger enemies
                    FTransform EliteEnemyTransform(FRotator::ZeroRotator, ElitePos, FVector(TestEnemyScale * 1.5f));
                    if (TestEnemyInstances)
                        TestEnemyInstances->AddInstance(EliteEnemyTransform);
                    OnTestEnemySpawned(ElitePos, Room.RoomType);
                }
                break;
                
            case ERoomType::Boss:
                // Boss room - spawn large boss enemy on ground
                {
                    FVector BossPos = RoomCenter;
                    BossPos.Z = 200.0f; // Higher for massive boss
                    FTransform BossTransform(FRotator::ZeroRotator, BossPos, FVector(TestEnemyScale * 2.0f));
                    if (TestEnemyInstances)
                        TestEnemyInstances->AddInstance(BossTransform);
                    OnTestEnemySpawned(BossPos, Room.RoomType);
                }
                break;
                
            case ERoomType::Treasure:
                // Treasure room - spawn chest slightly above ground
                {
                    FVector ChestPos = RoomCenter;
                    ChestPos.Z = 75.0f; // Chest sits on floor
                    FTransform ChestTransform(FRotator::ZeroRotator, ChestPos, FVector(TestChestScale));
                    if (TestChestInstances)
                        TestChestInstances->AddInstance(ChestTransform);
                    OnTestChestSpawned(ChestPos, Room.RoomType);
                }
                break;
                
            case ERoomType::Standard:
                // Standard room - breathing room, minimal content
                UE_LOG(LogTemp, Warning, TEXT("Standard room completed at %s"), *RoomCenter.ToString());
                break;
                
            case ERoomType::Exit:
                // Exit room - spawn exit portal/door
                UE_LOG(LogTemp, Warning, TEXT("Exit room spawned at %s"), *RoomCenter.ToString());
                break;
                
            default:
                // Unknown room type
                break;
        }
    }
}

// Simple implementations for required functions
void AGridDungeonVisualizer::SetGridCell(int32 X, int32 Y, EGridCellType Type, int32 RoomID)
{
    if (IsValidGridPosition(X, Y))
    {
        int32 Index = GridIndexFromXY(X, Y);
        if (Grid.IsValidIndex(Index))
        {
            Grid[Index].CellType = Type;
            Grid[Index].RoomID = RoomID;
        }
    }
}

FGridCell AGridDungeonVisualizer::GetGridCell(int32 X, int32 Y) const
{
    if (IsValidGridPosition(X, Y))
    {
        int32 Index = GridIndexFromXY(X, Y);
        if (Grid.IsValidIndex(Index))
        {
            return Grid[Index];
        }
    }
    return FGridCell(); // Return empty cell
}

bool AGridDungeonVisualizer::IsValidGridPosition(int32 X, int32 Y) const
{
    return X >= 0 && X < GridSizeX && Y >= 0 && Y < GridSizeY;
}

FVector AGridDungeonVisualizer::GridToWorldPosition(int32 X, int32 Y, bool bIsFloor) const
{
    // VOXEL ALIGNMENT: Calculate exact world position for grid cell
    // Always return CENTER of grid cell for proper mesh alignment
    FVector WorldPos;
    WorldPos.X = X * CellSize + (CellSize * 0.5f); // Center of grid cell
    WorldPos.Y = Y * CellSize + (CellSize * 0.5f); // Center of grid cell
    WorldPos.Z = bIsFloor ? 0.0f : (CellSize * 0.5f); // Floor at ground, walls raised
    return WorldPos;
}

FIntPoint AGridDungeonVisualizer::WorldToGridPosition(FVector WorldPos) const
{
    int32 GridX = FMath::FloorToInt(WorldPos.X / CellSize);
    int32 GridY = FMath::FloorToInt(WorldPos.Y / CellSize);
    return FIntPoint(GridX, GridY);
}

void AGridDungeonVisualizer::PlaceRoomInGrid(const FRoomData& Room)
{
    // VOXEL GRID: Each room is a 3x3 area of floor cells
    // With 1 cell gap between rooms for the voxel aesthetic
    int32 RoomSize = 3; // Each room is 3x3 cells
    
    // Room position is already calculated with spacing in GenerateAndVisualizeDungeon
    int32 StartX = Room.GridPosition.X;
    int32 StartY = Room.GridPosition.Y;
    
    // Validate room fits in grid
    if (StartX + RoomSize > GridSizeX || StartY + RoomSize > GridSizeY)
    {
        UE_LOG(LogTemp, Error, TEXT("Room at (%d,%d) exceeds grid bounds!"), StartX, StartY);
        return;
    }
    
    // Place floor cells for the room interior (3x3)
    for (int32 X = StartX; X < StartX + RoomSize; ++X)
    {
        for (int32 Y = StartY; Y < StartY + RoomSize; ++Y)
        {
            // Mark these cells as floor (will get planes instead of cubes)
            SetGridCell(X, Y, EGridCellType::Floor, Room.GridPosition.X * 5 + Room.GridPosition.Y);
        }
    }
    
    // Place wall cells around the room (creating a border)
    // This creates the room boundaries in the voxel grid
    
    // Top and bottom walls
    for (int32 X = StartX - 1; X <= StartX + RoomSize; ++X)
    {
        if (X >= 0 && X < GridSizeX)
        {
            // Top wall
            if (StartY - 1 >= 0)
            {
                FGridCell& TopCell = Grid[GridIndexFromXY(X, StartY - 1)];
                if (TopCell.CellType == EGridCellType::Empty)
                    SetGridCell(X, StartY - 1, EGridCellType::Wall);
            }
            // Bottom wall
            if (StartY + RoomSize < GridSizeY)
            {
                FGridCell& BottomCell = Grid[GridIndexFromXY(X, StartY + RoomSize)];
                if (BottomCell.CellType == EGridCellType::Empty)
                    SetGridCell(X, StartY + RoomSize, EGridCellType::Wall);
            }
        }
    }
    
    // Left and right walls
    for (int32 Y = StartY; Y < StartY + RoomSize; ++Y)
    {
        if (Y >= 0 && Y < GridSizeY)
        {
            // Left wall
            if (StartX - 1 >= 0)
            {
                FGridCell& LeftCell = Grid[GridIndexFromXY(StartX - 1, Y)];
                if (LeftCell.CellType == EGridCellType::Empty)
                    SetGridCell(StartX - 1, Y, EGridCellType::Wall);
            }
            // Right wall
            if (StartX + RoomSize < GridSizeX)
            {
                FGridCell& RightCell = Grid[GridIndexFromXY(StartX + RoomSize, Y)];
                if (RightCell.CellType == EGridCellType::Empty)
                    SetGridCell(StartX + RoomSize, Y, EGridCellType::Wall);
            }
        }
    }
    
    UE_LOG(LogTemp, Log, TEXT("Room at Grid(%d,%d): %dx%d tiles, %d floor, %d walls"), 
           Room.GridPosition.X, Room.GridPosition.Y, RoomSize, RoomSize, FloorTilesPlaced, WallTilesPlaced);
}

void AGridDungeonVisualizer::ConnectRoomsWithHallway(const FRoomData& RoomA, const FRoomData& RoomB)
{
    // NEIGHBOR-ONLY CONNECTIONS: Rooms must be exactly 1 cell apart
    // Only connect adjacent rooms to maintain clean voxel grid
    
    int32 RoomSize = 3;
    
    // Calculate room positions in the simplified grid (where each room occupies one slot)
    FIntPoint RoomAPos((RoomA.GridPosition.X - 1) / 4, (RoomA.GridPosition.Y - 1) / 4);
    FIntPoint RoomBPos((RoomB.GridPosition.X - 1) / 4, (RoomB.GridPosition.Y - 1) / 4);
    
    // Check if rooms are adjacent (exactly 1 unit apart in grid coordinates)
    int32 XDiff = FMath::Abs(RoomAPos.X - RoomBPos.X);
    int32 YDiff = FMath::Abs(RoomAPos.Y - RoomBPos.Y);
    
    // Only connect if rooms are direct neighbors
    bool bHorizontalNeighbors = (XDiff == 1 && YDiff == 0);
    bool bVerticalNeighbors = (XDiff == 0 && YDiff == 1);
    
    if (!bHorizontalNeighbors && !bVerticalNeighbors)
    {
        // Rooms are not adjacent, skip connection
        return;
    }
    
    // Determine connection point in the 1-cell gap between rooms
    if (bHorizontalNeighbors)
    {
        // Horizontal connection through the gap
        int32 GapX = FMath::Min(RoomA.GridPosition.X, RoomB.GridPosition.X) + RoomSize;
        int32 ConnectY = RoomA.GridPosition.Y + 1; // Middle of room edge
        
        // Place single hallway cell in the gap
        FGridCell& GapCell = Grid[GridIndexFromXY(GapX, ConnectY)];
        if (GapCell.CellType == EGridCellType::Empty || GapCell.CellType == EGridCellType::Wall)
        {
            SetGridCell(GapX, ConnectY, EGridCellType::Hallway);
            
            // Open doorways on room edges
            SetGridCell(GapX - 1, ConnectY, EGridCellType::Door); // Door on one side
            SetGridCell(GapX + 1, ConnectY, EGridCellType::Door); // Door on other side
        }
    }
    else if (bVerticalNeighbors)
    {
        // Vertical connection through the gap
        int32 ConnectX = RoomA.GridPosition.X + 1; // Middle of room edge
        int32 GapY = FMath::Min(RoomA.GridPosition.Y, RoomB.GridPosition.Y) + RoomSize;
        
        // Place single hallway cell in the gap
        FGridCell& GapCell = Grid[GridIndexFromXY(ConnectX, GapY)];
        if (GapCell.CellType == EGridCellType::Empty || GapCell.CellType == EGridCellType::Wall)
        {
            SetGridCell(ConnectX, GapY, EGridCellType::Hallway);
            
            // Open doorways on room edges
            SetGridCell(ConnectX, GapY - 1, EGridCellType::Door); // Door on one side
            SetGridCell(ConnectX, GapY + 1, EGridCellType::Door); // Door on other side
        }
    }
    
    UE_LOG(LogTemp, Log, TEXT("Connected Room(%d,%d) to Room(%d,%d) with 1x1 hallway"),
           RoomA.GridPosition.X, RoomA.GridPosition.Y,
           RoomB.GridPosition.X, RoomB.GridPosition.Y);
}


void AGridDungeonVisualizer::SpawnPlayerAtStart()
{
    // Implementation for spawning player at start room
    FVector StartPos = GetStartPosition();
    // Move player to start position (implementation depends on player system)
}

FVector AGridDungeonVisualizer::GetStartPosition() const
{
    // Get the center of the start room
    int32 RoomSpacing = 5;
    FVector StartPos = GridToWorldPosition(
        StartRoomGridPos.X * RoomSpacing + 2,
        StartRoomGridPos.Y * RoomSpacing + 2,
        true
    );
    StartPos.Z = 100.0f; // Spawn player slightly above floor
    return StartPos;
}

void AGridDungeonVisualizer::SpawnTestEnemiesInRoom(const FRoomData& Room)
{
    // Implementation for spawning test enemies
}

void AGridDungeonVisualizer::SpawnTestChestsInRoom(const FRoomData& Room)
{
    // Implementation for spawning test chests
}

// Private helper functions
void AGridDungeonVisualizer::InitializeGrid()
{
    int32 TotalCells = GridSizeX * GridSizeY;
    Grid.Empty(TotalCells);
    Grid.SetNum(TotalCells);
    
    // Initialize all cells as empty
    for (FGridCell& Cell : Grid)
    {
        Cell.CellType = EGridCellType::Empty;
        Cell.RoomID = -1;
    }
}

void AGridDungeonVisualizer::InitializeComponents()
{
    // Use default engine meshes if none are set
    if (!PlaneMesh)
    {
        PlaneMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Plane.Plane"));
        UE_LOG(LogTemp, Warning, TEXT("GridDungeonVisualizer: Using default Plane mesh"));
    }
    
    if (!CubeMesh)
    {
        CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
        UE_LOG(LogTemp, Warning, TEXT("GridDungeonVisualizer: Using default Cube mesh"));
    }
    
    // Set up plane instances
    if (PlaneInstances && PlaneMesh)
    {
        PlaneInstances->SetStaticMesh(PlaneMesh);
        if (FloorMaterial)
            PlaneInstances->SetMaterial(0, FloorMaterial);
        UE_LOG(LogTemp, Warning, TEXT("GridDungeonVisualizer: PlaneInstances initialized"));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("GridDungeonVisualizer: Failed to initialize PlaneInstances"));
    }
    
    // Set up cube instances
    if (CubeInstances && CubeMesh)
    {
        CubeInstances->SetStaticMesh(CubeMesh);
        if (WallMaterial)
            CubeInstances->SetMaterial(0, WallMaterial);
        UE_LOG(LogTemp, Warning, TEXT("GridDungeonVisualizer: CubeInstances initialized"));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("GridDungeonVisualizer: Failed to initialize CubeInstances"));
    }
    
    // Set up test enemy instances
    if (TestEnemyInstances)
    {
        if (!TestEnemyMesh)
        {
            TestEnemyMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Sphere.Sphere"));
        }
        if (TestEnemyMesh)
        {
            TestEnemyInstances->SetStaticMesh(TestEnemyMesh);
            if (TestEnemyMaterial)
                TestEnemyInstances->SetMaterial(0, TestEnemyMaterial);
        }
    }
    
    // Set up test chest instances
    if (TestChestInstances)
    {
        if (!TestChestMesh)
        {
            TestChestMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
        }
        if (TestChestMesh)
        {
            TestChestInstances->SetStaticMesh(TestChestMesh);
            if (TestChestMaterial)
                TestChestInstances->SetMaterial(0, TestChestMaterial);
        }
    }
}

int32 AGridDungeonVisualizer::GridIndexFromXY(int32 X, int32 Y) const
{
    return Y * GridSizeX + X;
}

void AGridDungeonVisualizer::PlaceBoundaryWalls()
{
    // Place walls around the entire grid perimeter to prevent players from walking off
    for (int32 X = 0; X < GridSizeX; ++X)
    {
        // Top edge
        SetGridCell(X, 0, EGridCellType::Wall);
        // Bottom edge
        SetGridCell(X, GridSizeY - 1, EGridCellType::Wall);
    }
    
    for (int32 Y = 0; Y < GridSizeY; ++Y)
    {
        // Left edge
        SetGridCell(0, Y, EGridCellType::Wall);
        // Right edge
        SetGridCell(GridSizeX - 1, Y, EGridCellType::Wall);
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Placed boundary walls around %dx%d grid"), GridSizeX, GridSizeY);
}

UMaterialInterface* AGridDungeonVisualizer::GetMaterialForCell(const FGridCell& Cell) const
{
    switch (Cell.CellType)
    {
        case EGridCellType::Floor:
            return FloorMaterial;
        case EGridCellType::Wall:
            return WallMaterial;
        case EGridCellType::Hallway:
            return HallwayMaterial;
        default:
            return nullptr;
    }
}

FVector AGridDungeonVisualizer::FindValidRoomPosition(const FOrganicRoom& FromRoom, FVector2D NewRoomSize, float MinDistance, float MaxDistance)
{
    // Try multiple angles to find a valid position
    int32 MaxAttempts = 16;
    
    for (int32 i = 0; i < MaxAttempts; ++i)
    {
        // Generate random angle with some bias based on depth
        float Angle = RandomStream.FRandRange(0, 360);
        if (FromRoom.bIsMainPath)
        {
            // Main path tends to go forward
            Angle = RandomStream.FRandRange(-45, 45) + (FromRoom.Depth * 15);
        }
        
        float Distance = RandomStream.FRandRange(MinDistance, MaxDistance);
        
        // Calculate position
        FVector Direction(
            FMath::Cos(FMath::DegreesToRadians(Angle)),
            FMath::Sin(FMath::DegreesToRadians(Angle)),
            0
        );
        
        // Account for room sizes
        float EdgeDistance = (FMath::Max(FromRoom.Size.X, FromRoom.Size.Y) + 
                             FMath::Max(NewRoomSize.X, NewRoomSize.Y)) * 0.5f;
        
        FVector NewPosition = FromRoom.Position + Direction * (Distance + EdgeDistance);
        
        // Check if position is valid
        bool bValid = true;
        FOrganicRoom TestRoom;
        TestRoom.Position = NewPosition;
        TestRoom.Size = NewRoomSize;
        
        for (const FOrganicRoom& ExistingRoom : OrganicLayout.Rooms)
        {
            if (DoRoomsOverlap(TestRoom, ExistingRoom, 200.0f))
            {
                bValid = false;
                break;
            }
        }
        
        // Check boundary constraints
        float HalfWidth = NewRoomSize.X * 0.5f;
        float HalfHeight = NewRoomSize.Y * 0.5f;
        
        bool bWithinBounds = 
            (NewPosition.X - HalfWidth) >= (DungeonBoundaryMin.X + BoundaryPadding) &&
            (NewPosition.X + HalfWidth) <= (DungeonBoundaryMax.X - BoundaryPadding) &&
            (NewPosition.Y - HalfHeight) >= (DungeonBoundaryMin.Y + BoundaryPadding) &&
            (NewPosition.Y + HalfHeight) <= (DungeonBoundaryMax.Y - BoundaryPadding);
        
        if (bValid && bWithinBounds)
        {
            return NewPosition;
        }
    }
    
    // Fallback: place further away
    float FallbackAngle = RandomStream.FRandRange(0, 360);
    FVector Direction(
        FMath::Cos(FMath::DegreesToRadians(FallbackAngle)),
        FMath::Sin(FMath::DegreesToRadians(FallbackAngle)),
        0
    );
    
    return FromRoom.Position + Direction * (MaxDistance * 1.5f);
}

bool AGridDungeonVisualizer::DoRoomsOverlap(const FOrganicRoom& A, const FOrganicRoom& B, float Padding)
{
    float AMinX = A.Position.X - A.Size.X * 0.5f - Padding;
    float AMaxX = A.Position.X + A.Size.X * 0.5f + Padding;
    float AMinY = A.Position.Y - A.Size.Y * 0.5f - Padding;
    float AMaxY = A.Position.Y + A.Size.Y * 0.5f + Padding;
    
    float BMinX = B.Position.X - B.Size.X * 0.5f;
    float BMaxX = B.Position.X + B.Size.X * 0.5f;
    float BMinY = B.Position.Y - B.Size.Y * 0.5f;
    float BMaxY = B.Position.Y + B.Size.Y * 0.5f;
    
    return !(AMaxX < BMinX || BMaxX < AMinX || AMaxY < BMinY || BMaxY < AMinY);
}

FHallway AGridDungeonVisualizer::CreateHallway(int32 RoomA, int32 RoomB)
{
    FHallway Hallway;
    Hallway.RoomA = RoomA;
    Hallway.RoomB = RoomB;
    Hallway.Width = HallwayWidth;
    
    if (RoomA >= 0 && RoomA < OrganicLayout.Rooms.Num() &&
        RoomB >= 0 && RoomB < OrganicLayout.Rooms.Num())
    {
        const FOrganicRoom& RoomAData = OrganicLayout.Rooms[RoomA];
        const FOrganicRoom& RoomBData = OrganicLayout.Rooms[RoomB];
        
        // Generate path points
        Hallway.PathPoints = GenerateHallwayPath(RoomAData.Position, RoomBData.Position);
    }
    
    return Hallway;
}

TArray<FVector> AGridDungeonVisualizer::GenerateHallwayPath(FVector StartPos, FVector EndPos)
{
    TArray<FVector> PathPoints;
    
    // Simple L-shaped path for now
    PathPoints.Add(StartPos);
    
    // Decide whether to go horizontal or vertical first
    if (RandomStream.FRand() < 0.5f)
    {
        // Horizontal then vertical
        FVector MidPoint(EndPos.X, StartPos.Y, StartPos.Z);
        PathPoints.Add(MidPoint);
    }
    else
    {
        // Vertical then horizontal
        FVector MidPoint(StartPos.X, EndPos.Y, StartPos.Z);
        PathPoints.Add(MidPoint);
    }
    
    PathPoints.Add(EndPos);
    
    return PathPoints;
}

void AGridDungeonVisualizer::VisualizeOrganicDungeon()
{
    if (!PlaneInstances || !CubeInstances)
        return;
    
    // Load default meshes if not set
    if (!PlaneMesh)
    {
        PlaneMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Plane.Plane"));
    }
    if (!CubeMesh)
    {
        CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
    }
    
    // Set meshes
    if (PlaneMesh)
        PlaneInstances->SetStaticMesh(PlaneMesh);
    if (CubeMesh)
        CubeInstances->SetStaticMesh(CubeMesh);
    
    // Spawn room geometry
    for (const FOrganicRoom& Room : OrganicLayout.Rooms)
    {
        SpawnOrganicRoomGeometry(Room);
    }
    
    // Spawn hallway geometry
    for (const FHallway& Hallway : OrganicLayout.Hallways)
    {
        SpawnHallwayGeometry(Hallway);
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Organic visualization complete"));
}

void AGridDungeonVisualizer::SpawnOrganicRoomGeometry(const FOrganicRoom& Room)
{
    if (!PlaneInstances || !CubeInstances)
        return;
    
    // Spawn floor
    FTransform FloorTransform;
    FloorTransform.SetLocation(Room.Position);
    FloorTransform.SetScale3D(FVector(Room.Size.X / 100.0f, Room.Size.Y / 100.0f, 1.0f));
    PlaneInstances->AddInstance(FloorTransform);
    
    float WallThickness = 50.0f;
    
    // Spawn walls around room perimeter
    // North wall
    FTransform NorthWall;
    NorthWall.SetLocation(Room.Position + FVector(0, Room.Size.Y * 0.5f + WallThickness * 0.5f, WallHeight * 0.5f));
    NorthWall.SetScale3D(FVector(Room.Size.X / 100.0f, WallThickness / 100.0f, WallHeight / 100.0f));
    CubeInstances->AddInstance(NorthWall);
    
    // South wall
    FTransform SouthWall;
    SouthWall.SetLocation(Room.Position + FVector(0, -Room.Size.Y * 0.5f - WallThickness * 0.5f, WallHeight * 0.5f));
    SouthWall.SetScale3D(FVector(Room.Size.X / 100.0f, WallThickness / 100.0f, WallHeight / 100.0f));
    CubeInstances->AddInstance(SouthWall);
    
    // East wall
    FTransform EastWall;
    EastWall.SetLocation(Room.Position + FVector(Room.Size.X * 0.5f + WallThickness * 0.5f, 0, WallHeight * 0.5f));
    EastWall.SetScale3D(FVector(WallThickness / 100.0f, Room.Size.Y / 100.0f, WallHeight / 100.0f));
    CubeInstances->AddInstance(EastWall);
    
    // West wall
    FTransform WestWall;
    WestWall.SetLocation(Room.Position + FVector(-Room.Size.X * 0.5f - WallThickness * 0.5f, 0, WallHeight * 0.5f));
    WestWall.SetScale3D(FVector(WallThickness / 100.0f, Room.Size.Y / 100.0f, WallHeight / 100.0f));
    CubeInstances->AddInstance(WestWall);
}

void AGridDungeonVisualizer::SpawnHallwayGeometry(const FHallway& Hallway)
{
    if (!PlaneInstances || Hallway.PathPoints.Num() < 2)
        return;
    
    // Spawn floor segments along path
    for (int32 i = 0; i < Hallway.PathPoints.Num() - 1; ++i)
    {
        FVector Start = Hallway.PathPoints[i];
        FVector End = Hallway.PathPoints[i + 1];
        
        FVector MidPoint = (Start + End) * 0.5f;
        float Length = FVector::Dist(Start, End);
        
        FVector Direction = (End - Start).GetSafeNormal();
        FRotator Rotation = Direction.Rotation();
        
        FTransform HallwayFloor;
        HallwayFloor.SetLocation(MidPoint);
        HallwayFloor.SetRotation(Rotation.Quaternion());
        
        // Determine scale based on direction
        if (FMath::Abs(Direction.X) > 0.5f)
        {
            // Horizontal hallway
            HallwayFloor.SetScale3D(FVector(Length / 100.0f, Hallway.Width / 100.0f, 1.0f));
        }
        else
        {
            // Vertical hallway
            HallwayFloor.SetScale3D(FVector(Hallway.Width / 100.0f, Length / 100.0f, 1.0f));
        }
        
        PlaneInstances->AddInstance(HallwayFloor);
    }
}