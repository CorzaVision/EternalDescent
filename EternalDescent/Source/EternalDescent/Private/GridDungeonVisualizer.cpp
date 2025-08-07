// Temporary minimal implementation of GridDungeonVisualizer to get Blueprint compilation working
#include "GridDungeonVisualizer.h"
#include "Components/InstancedStaticMeshComponent.h"

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
    
    // Create layout with stage-appropriate room types
    FDungeonLayout TestLayout;
    TestLayout.FloorNumber = CurrentFloor;
    TestLayout.CurrentZone = EDungeonZone::SunkenCrypt;
    
    // Stage-based room restrictions:
    // Elite rooms: Available from floor 5+
    // Boss rooms: Available every 5th floor (5, 10, 15, 20, etc.) and final floors of zones
    bool bCanHaveElite = CurrentFloor >= 5;
    bool bCanHaveBoss = (CurrentFloor % 5 == 0) || (CurrentFloor % 10 == 0); // Boss every 5th floor
    
    // 1. Start Room (0,0,0) - Always present
    FRoomData StartRoom;
    StartRoom.GridPosition = FIntVector(0, 0, 0);
    StartRoom.RoomType = ERoomType::Start;
    TestLayout.Rooms.Add(StartRoom.GridPosition, StartRoom);
    TestLayout.SpawnRoom = StartRoom.GridPosition;
    
    // 2. Combat Room (1,0,0) - Always present
    FRoomData CombatRoom;
    CombatRoom.GridPosition = FIntVector(1, 0, 0);
    CombatRoom.RoomType = ERoomType::Combat;
    TestLayout.Rooms.Add(CombatRoom.GridPosition, CombatRoom);
    
    // 3. Treasure Room (2,0,0) - Always present
    FRoomData TreasureRoom;
    TreasureRoom.GridPosition = FIntVector(2, 0, 0);
    TreasureRoom.RoomType = ERoomType::Treasure;
    TestLayout.Rooms.Add(TreasureRoom.GridPosition, TreasureRoom);
    
    // 4. Elite Room (0,1,0) - Only on floor 5+
    FRoomData EliteRoom;
    EliteRoom.GridPosition = FIntVector(0, 1, 0);
    EliteRoom.RoomType = bCanHaveElite ? ERoomType::Elite : ERoomType::Standard;
    TestLayout.Rooms.Add(EliteRoom.GridPosition, EliteRoom);
    
    // 5. Boss Room (1,1,0) - Only on boss floors (every 5th)
    FRoomData BossRoom;
    BossRoom.GridPosition = FIntVector(1, 1, 0);
    BossRoom.RoomType = bCanHaveBoss ? ERoomType::Boss : ERoomType::Combat;
    TestLayout.Rooms.Add(BossRoom.GridPosition, BossRoom);
    
    // 6. Standard Room (2,1,0) - Always present for breathing room
    FRoomData StandardRoom;
    StandardRoom.GridPosition = FIntVector(2, 1, 0);
    StandardRoom.RoomType = ERoomType::Standard;
    TestLayout.Rooms.Add(StandardRoom.GridPosition, StandardRoom);
    
    // 7. End/Exit Room (1,2,0) - Always present
    FRoomData ExitRoom;
    ExitRoom.GridPosition = FIntVector(1, 2, 0);
    ExitRoom.RoomType = ERoomType::Exit;
    TestLayout.Rooms.Add(ExitRoom.GridPosition, ExitRoom);
    
    // Log floor and room composition for debugging
    UE_LOG(LogTemp, Warning, TEXT("Floor %d: Elite=%s, Boss=%s"), 
           CurrentFloor, 
           bCanHaveElite ? TEXT("Yes") : TEXT("No"),
           bCanHaveBoss ? TEXT("Yes") : TEXT("No"));
    
    BuildGridFromLayout(TestLayout);
    SpawnGridVisualization();
    SpawnRoomContents();
}

void AGridDungeonVisualizer::BuildGridFromLayout(const FDungeonLayout& Layout)
{
    InitializeGrid();
    CurrentLayout = Layout;
    
    // Place each room in the grid
    for (const auto& RoomPair : Layout.Rooms)
    {
        const FRoomData& Room = RoomPair.Value;
        PlaceRoomInGrid(Room);
        
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
    if (!PlaneInstances || !CubeInstances) return;
    
    for (int32 X = 0; X < GridSizeX; ++X)
    {
        for (int32 Y = 0; Y < GridSizeY; ++Y)
        {
            FGridCell Cell = GetGridCell(X, Y);
            FVector WorldPos = GridToWorldPosition(X, Y, true);
            FTransform Transform(FRotator::ZeroRotator, WorldPos, FVector::OneVector);
            
            if (Cell.CellType == EGridCellType::Floor)
            {
                PlaneInstances->AddInstance(Transform);
            }
            else if (Cell.CellType == EGridCellType::Wall)
            {
                FVector WallPos = GridToWorldPosition(X, Y, false);
                WallPos.Z += WallHeight * 0.5f;
                FTransform WallTransform(FRotator::ZeroRotator, WallPos, FVector(1.0f, 1.0f, WallHeight / 100.0f));
                CubeInstances->AddInstance(WallTransform);
            }
        }
    }
}

void AGridDungeonVisualizer::SpawnRoomContents()
{
    // Spawn content for all 6 room types as requested by user
    for (const auto& RoomPair : CurrentLayout.Rooms)
    {
        const FRoomData& Room = RoomPair.Value;
        FVector RoomCenter = GridToWorldPosition(Room.GridPosition.X, Room.GridPosition.Y, true);
        RoomCenter.Z += 50.0f; // Lift above floor
        
        switch (Room.RoomType)
        {
            case ERoomType::Start:
                // Start room - spawn player here
                UE_LOG(LogTemp, Warning, TEXT("Start room spawned at %s"), *RoomCenter.ToString());
                break;
                
            case ERoomType::Combat:
                // Combat room - spawn standard enemies
                {
                    FTransform EnemyTransform(FRotator::ZeroRotator, RoomCenter, FVector(TestEnemyScale));
                    if (TestEnemyInstances)
                        TestEnemyInstances->AddInstance(EnemyTransform);
                    OnTestEnemySpawned(RoomCenter, Room.RoomType);
                }
                break;
                
            case ERoomType::Elite:
                // Elite room - spawn harder enemies (larger scale)
                {
                    FTransform EliteEnemyTransform(FRotator::ZeroRotator, RoomCenter, FVector(TestEnemyScale * 1.5f));
                    if (TestEnemyInstances)
                        TestEnemyInstances->AddInstance(EliteEnemyTransform);
                    OnTestEnemySpawned(RoomCenter, Room.RoomType);
                }
                break;
                
            case ERoomType::Boss:
                // Boss room - spawn large boss enemy
                {
                    FTransform BossTransform(FRotator::ZeroRotator, RoomCenter, FVector(TestEnemyScale * 2.0f));
                    if (TestEnemyInstances)
                        TestEnemyInstances->AddInstance(BossTransform);
                    OnTestEnemySpawned(RoomCenter, Room.RoomType);
                }
                break;
                
            case ERoomType::Treasure:
                // Treasure room - spawn chest
                {
                    FTransform ChestTransform(FRotator::ZeroRotator, RoomCenter, FVector(TestChestScale));
                    if (TestChestInstances)
                        TestChestInstances->AddInstance(ChestTransform);
                    OnTestChestSpawned(RoomCenter, Room.RoomType);
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
    FVector WorldPos;
    WorldPos.X = X * CellSize;
    WorldPos.Y = Y * CellSize;
    WorldPos.Z = bIsFloor ? 0.0f : WallHeight * 0.5f;
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
    // Scale rooms to UE5 Mannequin size (183 units tall)
    // Each room = ~8 mannequin heights = spacious dungeon room feeling
    int32 RoomSize = 4; // 4x4 floor tiles per room
    int32 StartX = Room.GridPosition.X * 6; // Space rooms with wall buffer
    int32 StartY = Room.GridPosition.Y * 6;
    
    // Place floor tiles
    for (int32 X = StartX; X < StartX + RoomSize; ++X)
    {
        for (int32 Y = StartY; Y < StartY + RoomSize; ++Y)
        {
            SetGridCell(X, Y, EGridCellType::Floor, 1);
        }
    }
    
    // Place walls around room
    for (int32 X = StartX - 1; X <= StartX + RoomSize; ++X)
    {
        SetGridCell(X, StartY - 1, EGridCellType::Wall);
        SetGridCell(X, StartY + RoomSize, EGridCellType::Wall);
    }
    for (int32 Y = StartY - 1; Y <= StartY + RoomSize; ++Y)
    {
        SetGridCell(StartX - 1, Y, EGridCellType::Wall);
        SetGridCell(StartX + RoomSize, Y, EGridCellType::Wall);
    }
}

void AGridDungeonVisualizer::PlaceHallwayInGrid(const FHallwayConnection& Hallway)
{
    // Simple hallway implementation - connect two points
    // This would be implemented properly later
}

void AGridDungeonVisualizer::SpawnPlayerAtStart()
{
    // Implementation for spawning player at start room
    FVector StartPos = GetStartPosition();
    // Move player to start position (implementation depends on player system)
}

FVector AGridDungeonVisualizer::GetStartPosition() const
{
    return GridToWorldPosition(StartRoomGridPos.X, StartRoomGridPos.Y, true);
}

void AGridDungeonVisualizer::SpawnTestEnemiesInRoom(const FRoomData& Room)
{
    // Implementation for spawning test enemies
}

void AGridDungeonVisualizer::SpawnTestChestsInRoom(const FRoomData& Room)
{
    // Implementation for spawning test chests
}

void AGridDungeonVisualizer::DrawDebugGrid()
{
    // Implementation for debug grid drawing
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
    if (PlaneInstances && PlaneMesh)
    {
        PlaneInstances->SetStaticMesh(PlaneMesh);
        if (FloorMaterial)
            PlaneInstances->SetMaterial(0, FloorMaterial);
    }
    
    if (CubeInstances && CubeMesh)
    {
        CubeInstances->SetStaticMesh(CubeMesh);
        if (WallMaterial)
            CubeInstances->SetMaterial(0, WallMaterial);
    }
    
    if (TestEnemyInstances && TestEnemyMesh)
    {
        TestEnemyInstances->SetStaticMesh(TestEnemyMesh);
        if (TestEnemyMaterial)
            TestEnemyInstances->SetMaterial(0, TestEnemyMaterial);
    }
    
    if (TestChestInstances && TestChestMesh)
    {
        TestChestInstances->SetStaticMesh(TestChestMesh);
        if (TestChestMaterial)
            TestChestInstances->SetMaterial(0, TestChestMaterial);
    }
}

int32 AGridDungeonVisualizer::GridIndexFromXY(int32 X, int32 Y) const
{
    return Y * GridSizeX + X;
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