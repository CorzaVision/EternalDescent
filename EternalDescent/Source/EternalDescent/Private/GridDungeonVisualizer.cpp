// Temporary minimal implementation of GridDungeonVisualizer to get Blueprint compilation working
#include "GridDungeonVisualizer.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "Math/UnrealMathUtility.h"

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

void AGridDungeonVisualizer::GenerateOrganicDungeon(int32 Seed)
{
    ClearDungeon();
    
    // Initialize random stream
    if (Seed == -1)
    {
        Seed = FMath::Rand();
    }
    RandomStream.Initialize(Seed);
    
    UE_LOG(LogTemp, Warning, TEXT("========================================"));
    UE_LOG(LogTemp, Warning, TEXT("Generating Organic Dungeon - Floor %d"), CurrentFloor);
    UE_LOG(LogTemp, Warning, TEXT("Seed: %d"), Seed);
    
    // Reset layout
    OrganicLayout = FOrganicDungeonLayout();
    OrganicLayout.FloorNumber = CurrentFloor;
    
    // Determine room count
    int32 RoomCount = RandomStream.RandRange(MinRoomCount, MaxRoomCount);
    
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
    
    // Use appropriate generation based on mode
    if (GenerationType == EDungeonGenerationType::Organic)
    {
        GenerateOrganicDungeon(Seed);
        return;
    }
    
    // Create layout with stage-appropriate room types
    FDungeonLayout TestLayout;
    TestLayout.FloorNumber = CurrentFloor;
    TestLayout.CurrentZone = EDungeonZone::SunkenCrypt;
    
    // Stage-based room restrictions:
    bool bCanHaveElite = CurrentFloor >= 5;
    bool bCanHaveBoss = (CurrentFloor % 5 == 0);
    
    // Generate a 5x5 grid of 25 rooms total
    int32 RoomIndex = 0;
    for (int32 Y = 0; Y < 5; ++Y)
    {
        for (int32 X = 0; X < 5; ++X)
        {
            FRoomData Room;
            Room.GridPosition = FIntVector(X, Y, 0);
            
            // Assign room types strategically
            if (X == 0 && Y == 0)
            {
                // Start room at (0,0)
                Room.RoomType = ERoomType::Start;
                TestLayout.SpawnRoom = Room.GridPosition;
            }
            else if (X == 4 && Y == 4)
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
    UE_LOG(LogTemp, Warning, TEXT("Total rooms: %d"), TestLayout.Rooms.Num());
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
    // Debug logging to track mesh spawning
    int32 FloorCount = 0;
    int32 WallCount = 0;
    
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
    
    UE_LOG(LogTemp, Warning, TEXT("GridDungeonVisualizer: Spawning grid %dx%d"), GridSizeX, GridSizeY);
    
    for (int32 X = 0; X < GridSizeX; ++X)
    {
        for (int32 Y = 0; Y < GridSizeY; ++Y)
        {
            FGridCell Cell = GetGridCell(X, Y);
            
            if (Cell.CellType == EGridCellType::Floor)
            {
                // Floor plane at ground level (Z = 0)
                float TileScale = CellSize / 100.0f;
                FVector FloorPos = GridToWorldPosition(X, Y, true);
                FloorPos.Z = 0.0f; // Floor at ground level
                FTransform FloorTransform(FRotator::ZeroRotator, FloorPos, FVector(TileScale, TileScale, 1.0f));
                PlaneInstances->AddInstance(FloorTransform);
                FloorCount++;
            }
            else if (Cell.CellType == EGridCellType::Wall)
            {
                // Wall cube sits on top of floor
                float TileScale = CellSize / 100.0f;
                FVector WallPos = GridToWorldPosition(X, Y, false);
                WallPos.Z = WallHeight * 0.5f; // Center of wall
                FTransform WallTransform(FRotator::ZeroRotator, WallPos, FVector(TileScale, TileScale, WallHeight / 100.0f));
                CubeInstances->AddInstance(WallTransform);
                WallCount++;
            }
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("GridDungeonVisualizer: Spawned %d floors and %d walls"), FloorCount, WallCount);
    
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
    // Both floor and walls use same X,Y grid position
    // This ensures perfect grid alignment
    FVector WorldPos;
    WorldPos.X = X * CellSize + (CellSize * 0.5f); // Center of grid cell
    WorldPos.Y = Y * CellSize + (CellSize * 0.5f); // Center of grid cell
    WorldPos.Z = 0.0f; // Base Z position (we'll adjust for walls in spawn code)
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
    // Each room is 3x3 tiles with walls forming an enclosed space
    // With CellSize=1000, each room is 3,000x3,000 units (about 16x16 mannequins)
    int32 RoomTiles = 3; // Interior floor space (3x3 is plenty with 1000-unit tiles)
    int32 RoomSpacing = 5; // Total space per room including walls (3 floor + 2 walls)
    
    int32 StartX = Room.GridPosition.X * RoomSpacing + 1; // +1 to leave space for boundary walls
    int32 StartY = Room.GridPosition.Y * RoomSpacing + 1;
    
    int32 FloorTilesPlaced = 0;
    int32 WallTilesPlaced = 0;
    
    // Place floor tiles (interior space)
    for (int32 X = StartX + 1; X < StartX + 1 + RoomTiles; ++X)
    {
        for (int32 Y = StartY + 1; Y < StartY + 1 + RoomTiles; ++Y)
        {
            SetGridCell(X, Y, EGridCellType::Floor, 1);
            FloorTilesPlaced++;
        }
    }
    
    // Place walls to form complete room enclosure
    // Top and bottom walls
    for (int32 X = StartX; X <= StartX + RoomTiles + 1; ++X)
    {
        SetGridCell(X, StartY, EGridCellType::Wall);                    // Top wall
        SetGridCell(X, StartY + RoomTiles + 1, EGridCellType::Wall);    // Bottom wall
        WallTilesPlaced += 2;
    }
    
    // Left and right walls
    for (int32 Y = StartY; Y <= StartY + RoomTiles + 1; ++Y)
    {
        SetGridCell(StartX, Y, EGridCellType::Wall);                    // Left wall
        SetGridCell(StartX + RoomTiles + 1, Y, EGridCellType::Wall);    // Right wall
        WallTilesPlaced += 2;
    }
    
    UE_LOG(LogTemp, Log, TEXT("Room at (%d,%d): Placed %d floor tiles and %d wall tiles"), 
           Room.GridPosition.X, Room.GridPosition.Y, FloorTilesPlaced, WallTilesPlaced);
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
        
        if (bValid)
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