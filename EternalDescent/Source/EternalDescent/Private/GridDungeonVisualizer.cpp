// GridDungeonVisualizer.cpp - PERFORMANCE OPTIMIZED Grid-based dungeon visualization with HISM
#include "GridDungeonVisualizer.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "Engine/Engine.h"
#include "DrawDebugHelpers.h"
#include "Materials/MaterialInterface.h"
#include "Math/IntPoint.h"

// Room data structure for dungeon generation
struct FRoomData
{
    FIntPoint Position;
    int32 Size;
    TArray<int32> ConnectedTo;
};

AGridDungeonVisualizer::AGridDungeonVisualizer()
{
    PrimaryActorTick.bCanEverTick = false;
    
    // Create root component
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    
    InitializeComponents();
}

void AGridDungeonVisualizer::BeginPlay()
{
    Super::BeginPlay();
    
    UE_LOG(LogTemp, Warning, TEXT("=== GridDungeonVisualizer BeginPlay ==="));
    UE_LOG(LogTemp, Warning, TEXT("Grid Size: %dx%d"), GridSizeX, GridSizeY);
    UE_LOG(LogTemp, Warning, TEXT("Cell Size: %.1f"), CellSize);
    UE_LOG(LogTemp, Warning, TEXT("Plane Mesh: %s"), PlaneMesh ? TEXT("Assigned") : TEXT("NULL"));
    UE_LOG(LogTemp, Warning, TEXT("Cube Mesh: %s"), CubeMesh ? TEXT("Assigned") : TEXT("NULL"));
    
    InitializeGrid();
    
    // Auto-generate a simple pattern
    GenerateAndVisualizeDungeon();
}

void AGridDungeonVisualizer::InitializeComponents()
{
    // Create HISM components for better performance with large instance counts
    PlaneInstances = CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(TEXT("HISM_Planes"));
    PlaneInstances->SetupAttachment(RootComponent);
    
    CubeInstances = CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(TEXT("HISM_Cubes"));
    CubeInstances->SetupAttachment(RootComponent);
    
    // UE 5.5 HISM Optimizations
    if (bUseInstancePooling)
    {
        PlaneInstances->NumCustomDataFloats = 0; // Reduce memory if not using custom data
        CubeInstances->NumCustomDataFloats = 0;
        
        // Set batch size for efficient culling
        PlaneInstances->InstancingRandomSeed = FMath::Rand();
        CubeInstances->InstancingRandomSeed = FMath::Rand();
    }
    
    // UE 5.5 Shadow Optimizations
    PlaneInstances->SetCastShadow(bCastShadows);
    CubeInstances->SetCastShadow(bCastShadows);
    
    // UE 5.5 Culling optimizations
    PlaneInstances->bUseAsOccluder = false; // Floors don't occlude
    CubeInstances->bUseAsOccluder = true; // Walls can occlude
    
    // UE 5.5 Rendering optimizations
    PlaneInstances->SetCullDistances(0, 10000.0f); // Cull at 100m
    CubeInstances->SetCullDistances(0, 10000.0f);
    
    // Set collision
    PlaneInstances->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    CubeInstances->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    
    // Set materials if they exist
    if (FloorMaterial)
    {
        PlaneInstances->SetMaterial(0, FloorMaterial);
    }
    
    if (WallMaterial)
    {
        CubeInstances->SetMaterial(0, WallMaterial);
    }
    
    // Assign meshes if they exist
    if (PlaneMesh)
    {
        PlaneInstances->SetStaticMesh(PlaneMesh);
    }
    
    if (CubeMesh)
    {
        CubeInstances->SetStaticMesh(CubeMesh);
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Components initialized - Plane Instances: %s, Cube Instances: %s"), 
        PlaneInstances ? TEXT("Valid") : TEXT("NULL"), 
        CubeInstances ? TEXT("Valid") : TEXT("NULL"));
    
    UE_LOG(LogTemp, Warning, TEXT("Grid Size: %dx%d, Cell Size: %.1f"), GridSizeX, GridSizeY, CellSize);
    UE_LOG(LogTemp, Warning, TEXT("Wall Cube Size: %.1f%% of cell"), CubeSizePercentage * 100.0f);
    
    // Initialize drawing settings from header
}

void AGridDungeonVisualizer::InitializeGrid()
{
    UE_LOG(LogTemp, Warning, TEXT("🔧 Initializing grid: %dx%d"), GridSizeX, GridSizeY);
    
    // Ensure reasonable bounds
    GridSizeX = FMath::Clamp(GridSizeX, 5, 100);
    GridSizeY = FMath::Clamp(GridSizeY, 5, 100);
    
    int32 TotalCells = GridSizeX * GridSizeY;
    Grid.SetNum(TotalCells);
    
    // Initialize all cells to walls
    for (FGridCell& Cell : Grid)
    {
        Cell.CellType = EGridCellType::Wall;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("✅ Grid initialized with %d cells"), TotalCells);
}

void AGridDungeonVisualizer::GenerateAndVisualizeDungeon(int32 Seed)
{
    // PERFORMANCE CRITICAL: Minimize function call overhead
    if (Seed > 0)
    {
        FMath::RandInit(Seed);
    }
    else
    {
        FMath::RandInit(FMath::Rand());
    }
    
    // Generate rooms (optimized layout generation)
    GenerateSimpleLayout();
    
    // Spawn visualization (optimized batch operations)
    SpawnGridVisualization();
    
    // Draw debug grid only if needed
    if (bShowDebugGrid)
    {
        DrawDebugGrid();
    }
}

void AGridDungeonVisualizer::GenerateSimpleLayout()
{
    // PERFORMANCE OPTIMIZATION: Pre-calculate required grid size to avoid reallocation
    const int32 TargetRooms = 25;
    const int32 RequiredGridSize = 35; // Pre-calculated for 25 rooms with spacing
    
    // Ensure grid is correctly sized from the start
    if (GridSizeX < RequiredGridSize || GridSizeY < RequiredGridSize)
    {
        GridSizeX = RequiredGridSize;
        GridSizeY = RequiredGridSize;
        
        // CRITICAL: Reallocate grid only once at the start
        const int32 TotalCells = GridSizeX * GridSizeY;
        Grid.SetNumUninitialized(TotalCells);
        
        // Initialize all cells to walls in single pass
        for (int32 i = 0; i < TotalCells; ++i)
        {
            Grid[i].CellType = EGridCellType::Wall;
        }
    }
    
    // Pre-allocate room array to prevent reallocation during generation
    TArray<FRoomData> Rooms;
    Rooms.Reserve(TargetRooms);
    
    // OPTIMIZED: Cache occupied positions to avoid expensive validation
    TSet<int32> OccupiedIndices;
    OccupiedIndices.Reserve(200); // Estimate for room coverage
    
    // Fast validation using cached occupied positions
    const auto IsRoomPositionValidFast = [this, &OccupiedIndices](const int32 X, const int32 Y, const int32 Size) -> bool
    {
        // Bounds check with early exit
        if (X < 0 || Y < 0 || X + Size > GridSizeX || Y + Size > GridSizeY)
        {
            return false;
        }
        
        // Check for overlap using cached indices (much faster than grid iteration)
        const int32 CheckMinX = FMath::Max(0, X - 1);
        const int32 CheckMaxX = FMath::Min(GridSizeX - 1, X + Size);
        const int32 CheckMinY = FMath::Max(0, Y - 1);
        const int32 CheckMaxY = FMath::Min(GridSizeY - 1, Y + Size);
        
        for (int32 CheckY = CheckMinY; CheckY <= CheckMaxY; ++CheckY)
        {
            for (int32 CheckX = CheckMinX; CheckX <= CheckMaxX; ++CheckX)
            {
                const int32 CheckIndex = CheckY * GridSizeX + CheckX;
                if (OccupiedIndices.Contains(CheckIndex))
                {
                    return false;
                }
            }
        }
        return true;
    };
    
    // Place start room efficiently
    for (int32 Y = 1; Y <= 2; ++Y)
    {
        for (int32 X = 1; X <= 2; ++X)
        {
            const int32 Index = Y * GridSizeX + X;
            Grid[Index].CellType = EGridCellType::Floor;
            OccupiedIndices.Add(Index);
        }
    }
    
    FRoomData StartRoom;
    StartRoom.Position = FIntPoint(1, 1);
    StartRoom.Size = 2;
    Rooms.Add(StartRoom);
    
    int32 RoomCount = 1;
    
    // PERFORMANCE OPTIMIZED: Efficient room placement with minimal attempts
    const int32 MaxAttempts = 100; // Reduced from 1000
    
    // Pre-calculated room positions for optimal placement (eliminates random searching)
    TArray<FIntPoint> PreferredPositions;
    PreferredPositions.Reserve(50);
    
    // Generate systematic placement positions (grid-based, not random)
    for (int32 Y = 4; Y < GridSizeY - 5; Y += 4) // 4-unit spacing
    {
        for (int32 X = 4; X < GridSizeX - 5; X += 4)
        {
            PreferredPositions.Add(FIntPoint(X, Y));
        }
    }
    
    // Shuffle once for variety
    for (int32 i = PreferredPositions.Num() - 1; i > 0; --i)
    {
        PreferredPositions.Swap(i, FMath::RandRange(0, i));
    }
    
    // Fast room placement using pre-calculated positions
    int32 PositionIndex = 0;
    while (RoomCount < TargetRooms && PositionIndex < PreferredPositions.Num())
    {
        const FIntPoint& Pos = PreferredPositions[PositionIndex++];
        
        // Determine room size (optimized distribution)
        int32 RoomSize;
        if (RoomCount == TargetRooms - 1)
        {
            RoomSize = 2; // Exit room
        }
        else
        {
            RoomSize = (FMath::RandRange(0, 4) == 0) ? 4 : 3; // 20% large, 80% medium
        }
        
        // Fast validation and placement
        if (IsRoomPositionValidFast(Pos.X, Pos.Y, RoomSize))
        {
            // Place room efficiently
            for (int32 Y = Pos.Y; Y < Pos.Y + RoomSize; ++Y)
            {
                for (int32 X = Pos.X; X < Pos.X + RoomSize; ++X)
                {
                    const int32 Index = Y * GridSizeX + X;
                    Grid[Index].CellType = EGridCellType::Floor;
                    OccupiedIndices.Add(Index);
                }
            }
            
            FRoomData NewRoom;
            NewRoom.Position = Pos;
            NewRoom.Size = RoomSize;
            Rooms.Add(NewRoom);
            RoomCount++;
        }
    }
    
    // Performance optimization: Remove expensive logging during generation
    // Only log final result
    if (RoomCount >= TargetRooms)
    {
        UE_LOG(LogTemp, Log, TEXT("GridDungeonVisualizer: Generated %d rooms successfully"), RoomCount);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("GridDungeonVisualizer: Generated %d/%d rooms"), RoomCount, TargetRooms);
    }
}

void AGridDungeonVisualizer::SpawnGridVisualization()
{
    if (!ensure(CubeInstances))
    {
        UE_LOG(LogTemp, Error, TEXT("GridDungeonVisualizer: CubeInstances not initialized"));
        return;
    }
    
    // Clear existing instances
    CubeInstances->ClearInstances();
    if (PlaneInstances)
    {
        PlaneInstances->ClearInstances();
    }
    
    // PERFORMANCE CRITICAL: Pre-allocate transforms array to avoid reallocations
    TArray<FTransform> WallTransforms;
    WallTransforms.Reserve(GridSizeX * GridSizeY / 2); // Estimate 50% walls
    
    // Pre-calculate common values
    const float DesiredCubeSize = CellSize * CubeSizePercentage;
    const float RequiredScale = DesiredCubeSize / 100.0f; // 100.0f = default UE cube size
    const FVector ScaleVector = FVector(RequiredScale);
    const FVector BaseLocation = GetActorLocation();
    
    // OPTIMIZED: Single pass through grid to collect wall transforms
    for (int32 Y = 0; Y < GridSizeY; ++Y)
    {
        for (int32 X = 0; X < GridSizeX; ++X)
        {
            const int32 Index = Y * GridSizeX + X;
            if (ensure(Grid.IsValidIndex(Index)) && Grid[Index].CellType == EGridCellType::Wall)
            {
                // Calculate position once
                const FVector CubeCenter = BaseLocation + FVector(X * CellSize, Y * CellSize, CellSize * 0.5f);
                
                // Create transform efficiently
                FTransform WallTransform;
                WallTransform.SetLocation(CubeCenter);
                WallTransform.SetRotation(FQuat::Identity);
                WallTransform.SetScale3D(ScaleVector);
                
                WallTransforms.Add(WallTransform);
            }
        }
    }
    
    // Set materials once
    if (WallMaterial)
    {
        CubeInstances->SetMaterial(0, WallMaterial);
    }
    
    // PERFORMANCE CRITICAL: Batch add all instances at once (much faster than individual AddInstance calls)
    if (WallTransforms.Num() > 0)
    {
        CubeInstances->AddInstances(WallTransforms, false); // false = local space
    }
    
    // Single render state update
    CubeInstances->MarkRenderStateDirty();
}

void AGridDungeonVisualizer::ClearDungeon()
{
    if (CubeInstances)
    {
        CubeInstances->ClearInstances();
    }
    
    if (PlaneInstances)
    {
        PlaneInstances->ClearInstances();
    }
}

void AGridDungeonVisualizer::SetGridCell(int32 X, int32 Y, EGridCellType Type)
{
    // FIXED: Enhanced bounds checking to prevent ACCESS_VIOLATION
    if (!IsValidGridPosition(X, Y))
    {
        UE_LOG(LogTemp, Warning, TEXT("⚠️ SetGridCell: Invalid position (%d, %d) - Grid size is %dx%d"), X, Y, GridSizeX, GridSizeY);
        return;
    }
    
    int32 Index = GridIndexFromXY(X, Y);
    if (!Grid.IsValidIndex(Index))
    {
        UE_LOG(LogTemp, Error, TEXT("❌ SetGridCell: Index %d out of bounds (Grid size: %d)"), Index, Grid.Num());
        return;
    }
    
    Grid[Index].CellType = Type;
}

FGridCell AGridDungeonVisualizer::GetGridCell(int32 X, int32 Y) const
{
    // FIXED: Enhanced bounds checking to prevent ACCESS_VIOLATION
    if (!IsValidGridPosition(X, Y))
    {
        FGridCell DefaultCell;
        DefaultCell.CellType = EGridCellType::Wall;
        return DefaultCell;
    }
    
    int32 Index = GridIndexFromXY(X, Y);
    if (!Grid.IsValidIndex(Index))
    {
        UE_LOG(LogTemp, Error, TEXT("❌ GetGridCell: Index %d out of bounds (Grid size: %d)"), Index, Grid.Num());
        FGridCell DefaultCell;
        DefaultCell.CellType = EGridCellType::Wall;
        return DefaultCell;
    }
    
    return Grid[Index];
}

bool AGridDungeonVisualizer::IsValidGridPosition(int32 X, int32 Y) const
{
    return X >= 0 && X < GridSizeX && Y >= 0 && Y < GridSizeY;
}

FVector AGridDungeonVisualizer::GridToWorldPosition(int32 X, int32 Y, bool bIsFloor) const
{
    FVector BaseLocation = GetActorLocation();
    FVector GridPos = FVector(X * CellSize, Y * CellSize, bIsFloor ? 0.0f : CellSize * 0.5f);
    return BaseLocation + GridPos;
}

void AGridDungeonVisualizer::DrawDebugGrid()
{
    if (!GetWorld())
    {
        return;
    }
    
    FVector BasePos = GetActorLocation();
    FColor GridColor = FColor::Green;
    float LineThickness = 2.0f;
    bool bPersistent = true;
    float LifeTime = -1.0f; // Permanent
    
    // Draw vertical lines
    for (int32 X = 0; X <= GridSizeX; ++X)
    {
        FVector Start = BasePos + FVector(X * CellSize, 0, 0);
        FVector End = BasePos + FVector(X * CellSize, GridSizeY * CellSize, 0);
        DrawDebugLine(GetWorld(), Start, End, GridColor, bPersistent, LifeTime, 0, LineThickness);
    }
    
    // Draw horizontal lines
    for (int32 Y = 0; Y <= GridSizeY; ++Y)
    {
        FVector Start = BasePos + FVector(0, Y * CellSize, 0);
        FVector End = BasePos + FVector(GridSizeX * CellSize, Y * CellSize, 0);
        DrawDebugLine(GetWorld(), Start, End, GridColor, bPersistent, LifeTime, 0, LineThickness);
    }
    
    // Draw cell content debug visualization
    for (int32 Y = 0; Y < GridSizeY; ++Y)
    {
        for (int32 X = 0; X < GridSizeX; ++X)
        {
            FGridCell Cell = GetGridCell(X, Y);
            FVector CellCenter = GridToWorldPosition(X, Y, false);
            
            if (Cell.CellType == EGridCellType::Wall)
            {
                float CubeSize = CellSize * CubeSizePercentage;
                float HalfSize = CubeSize * 0.5f;
                DrawDebugBox(GetWorld(), CellCenter, FVector(HalfSize, HalfSize, HalfSize), 
                    FColor::Red, bPersistent, LifeTime, 0, 2.0f);
            }
            else if (Cell.CellType == EGridCellType::Floor)
            {
                float PlaneSize = CellSize * 0.8f;
                FVector FloorCenter = GridToWorldPosition(X, Y, true);
                DrawDebugSphere(GetWorld(), FloorCenter, PlaneSize * 0.1f, 8, FColor::Blue, bPersistent, LifeTime, 0);
            }
        }
    }
}

void AGridDungeonVisualizer::GenerateInEditor()
{
    GenerateAndVisualizeDungeon();
}

void AGridDungeonVisualizer::TestGridAlignment()
{
    UE_LOG(LogTemp, Warning, TEXT("=== TESTING GRID ALIGNMENT ==="));
    
    // Basic test - just draws some debug spheres to test alignment
    if (!GetWorld())
    {
        return;
    }
    
    FVector BasePos = GetActorLocation();
    
    for (int32 X = 0; X < 3 && X < GridSizeX; ++X)
    {
        for (int32 Y = 0; Y < 3 && Y < GridSizeY; ++Y)
        {
            FVector CubeCenter = GridToWorldPosition(X, Y, false);
            DrawDebugSphere(GetWorld(), CubeCenter, 15.0f, 8, FColor::Blue, true, -1.0f, 0, 2.0f);
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Grid alignment test complete"));
}

void AGridDungeonVisualizer::TestAlternativeAlignment()
{
    UE_LOG(LogTemp, Warning, TEXT("=== TESTING ALTERNATIVE ALIGNMENT ==="));
    
    if (!GetWorld())
    {
        return;
    }
    
    FVector BasePos = GetActorLocation();
    
    for (int32 X = 0; X < 3 && X <= GridSizeX; ++X)
    {
        for (int32 Y = 0; Y < 3 && Y <= GridSizeY; ++Y)
        {
            FVector IntersectionPos = FVector(
                BasePos.X + X * CellSize,
                BasePos.Y + Y * CellSize,
                BasePos.Z + CellSize * 0.5f
            );
            DrawDebugSphere(GetWorld(), IntersectionPos, 15.0f, 8, FColor::Red, true, -1.0f, 0, 2.0f);
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Alternative alignment test complete"));
}

void AGridDungeonVisualizer::MatchCubesToDebugBoxes()
{
    if (!CubeInstances || !GetWorld())
    {
        return;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("=== MATCHING CUBES TO DEBUG BOXES ==="));
    
    // Clear existing cube instances
    CubeInstances->ClearInstances();
    
    // Ensure we have a mesh
    if (!CubeMesh)
    {
        UE_LOG(LogTemp, Error, TEXT("No cube mesh assigned!"));
        return;
    }
    
    CubeInstances->SetStaticMesh(CubeMesh);
    if (WallMaterial)
    {
        CubeInstances->SetMaterial(0, WallMaterial);
    }
    
    // For each cell in the grid, spawn a cube that exactly matches the debug box
    for (int32 Y = 0; Y < GridSizeY; ++Y)
    {
        for (int32 X = 0; X < GridSizeX; ++X)
        {
            // Get cell type
            FGridCell Cell = GetGridCell(X, Y);
            
            if (Cell.CellType == EGridCellType::Wall)
            {
                // Calculate the exact same position as the debug box
                FVector CubeCenter = GridToWorldPosition(X, Y, false);
                
                // FIXED: Calculate scale to match debug visualization exactly when CubeSizePercentage = 1.0
                // Debug boxes use CellSize directly, so at 1.0 percentage, mesh should fill cell
                float DesiredCubeSize = CellSize * CubeSizePercentage;
                float ActualMeshSize = 100.0f; // Default UE cube is 100x100x100
                // When CubeSizePercentage = 1.0, cube should be same size as cell
                float RequiredScale = DesiredCubeSize / ActualMeshSize;
                
                // Create transform
                FTransform WallTransform;
                WallTransform.SetLocation(CubeCenter);
                WallTransform.SetRotation(FQuat::Identity);
                WallTransform.SetScale3D(FVector(RequiredScale, RequiredScale, RequiredScale));
                
                // UE 5.5: AddInstance with world space flag for better performance
                CubeInstances->AddInstance(WallTransform, true); // true = world space
            }
        }
    }
    
    // UE 5.5: Mark render state dirty and update bounds for proper culling
    CubeInstances->MarkRenderStateDirty();
    CubeInstances->UpdateBounds();
    
    UE_LOG(LogTemp, Warning, TEXT("Spawned %d cubes to match debug boxes (UE 5.5 Optimized)"), CubeInstances->GetInstanceCount());
}

int32 AGridDungeonVisualizer::GridIndexFromXY(int32 X, int32 Y) const
{
    return Y * GridSizeX + X;
}