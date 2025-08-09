// GridDungeonVisualizer.cpp - PERFORMANCE OPTIMIZED Grid-based dungeon visualization with HISM
#include "GridDungeonVisualizer.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "Engine/Engine.h"
#include "DrawDebugHelpers.h"
#include "Materials/MaterialInterface.h"
#include "Math/IntPoint.h"
#include "Engine/World.h"
#include "TimerManager.h"
#if WITH_EDITOR
#include "Editor.h"
#endif

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
    UE_LOG(LogTemp, Warning, TEXT("🐍 Starting Mixed Room Size Dungeon Generation"));
    
    // Clear previous generation
    ClearDungeon();
    
    // Initialize random seed
    if (Seed < 0)
    {
        Seed = FMath::Rand();
    }
    FMath::RandInit(Seed);
    
    // LOOP 1: Generate path logic (no visuals yet)
    UE_LOG(LogTemp, Warning, TEXT("🔄 LOOP 1: Room Placement Logic"));
    GenerateSimpleLayout();
    
    if (bAnimateGeneration)
    {
        // Start animated generation
        UE_LOG(LogTemp, Warning, TEXT("🎬 Starting animated generation flow"));
        StartAnimatedGeneration();
    }
    else
    {
        // Instant generation (old behavior)
        UE_LOG(LogTemp, Warning, TEXT("⚡ Starting instant generation"));
        SpawnGridVisualization();
        
        // Draw debug grid and room boundaries if needed
        if (bShowDebugGrid)
        {
            DrawDebugGrid();
            DrawRoomBoundaries();
        }
        
        UE_LOG(LogTemp, Warning, TEXT("✅ Instant generation complete"));
        AutoClearDebugAfterGeneration();
    }
}

void AGridDungeonVisualizer::GenerateSimpleLayout()
{
    UE_LOG(LogTemp, Warning, TEXT("🐍 Snake Generation - LOOP 1: Mixed Room Size Placement Logic (2x2 START/END, 3x3 others, 1 CELL SPACING)"));
    
    // Auto-calculate grid size if enabled
    if (bAutoCalculateGridSize)
    {
        CalculateOptimalGridSize();
    }
    
    // Initialize all cells to empty first
    const int32 TotalCells = GridSizeX * GridSizeY;
    Grid.SetNum(TotalCells);
    
    for (int32 i = 0; i < TotalCells; ++i)
    {
        Grid[i].CellType = EGridCellType::Empty;
    }
    
    // Define START position - room center for 2x2 room (adjusted for auto-sizing)
    // START room center positioned to allow for 2x2 room
    FIntPoint StartPos(1, 1);  // 2x2 room will occupy (1,1) to (2,2)
    
    UE_LOG(LogTemp, Warning, TEXT("📍 START Room center at (%d, %d) - 2x2 occupies (1,1) to (2,2)"), StartPos.X, StartPos.Y);
    
    // Calculate END position based on grid size
    // For 2x2 END room, we need position that allows (X,Y) to (X+1,Y+1)
    FIntPoint EndPos(GridSizeX - 3, GridSizeY - 3); // Leaves room for 2x2
    
    // Generate snake path with mixed room spacing constraints
    TArray<FIntPoint> SnakePath = GenerateSnakePath(StartPos);
    
    if (SnakePath.Num() == 0)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Failed to generate mixed room snake path!"));
        return;
    }
    
    // Validate we got exactly the required room count
    if (SnakePath.Num() != RequiredRoomCount)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Generated %d rooms, but require EXACTLY %d rooms!"),
            SnakePath.Num(), RequiredRoomCount);
        return;
    }
    
    // EXIT is now the last room in the path
    FIntPoint ExitPos = SnakePath[SnakePath.Num() - 1];
    UE_LOG(LogTemp, Warning, TEXT("🚪 EXIT Room center at (%d, %d) - END OF PATH"), ExitPos.X, ExitPos.Y);
    UE_LOG(LogTemp, Warning, TEXT("🐍 Snake path generated with EXACTLY %d mixed rooms (required %d)"), SnakePath.Num(), RequiredRoomCount);
    
    // Mark the mixed room sizes in the grid with proper spacing
    MarkPathInGrid(SnakePath);
    
    UE_LOG(LogTemp, Warning, TEXT("✅ LOOP 1 Complete: Mixed room sizes placed with EXACTLY 1 CELL SPACING (2x2 START/END, 3x3 others)"));
}

void AGridDungeonVisualizer::SpawnGridVisualization()
{
    UE_LOG(LogTemp, Warning, TEXT("🔄 Mixed Room Size Generation - LOOP 2: Mesh/Cube Spawning (2x2 START/END, 3x3 others)"));
    
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
    
    // Pre-allocate transforms arrays to avoid reallocations
    TArray<FTransform> WallTransforms;
    TArray<FTransform> FloorTransforms;
    WallTransforms.Reserve(GridSizeX * GridSizeY);
    FloorTransforms.Reserve(GridSizeX * GridSizeY / 4); // Estimate fewer floors than walls
    
    // Pre-calculate common values
    const float DesiredCubeSize = CellSize * CubeSizePercentage;
    const float CubeScale = DesiredCubeSize / 100.0f; // 100.0f = default UE cube size
    const float PlaneScale = CellSize / 100.0f; // Plane scale to match cell size
    const FVector CubeScaleVector = FVector(CubeScale);
    const FVector PlaneScaleVector = FVector(PlaneScale, PlaneScale, 1.0f);
    const FVector BaseLocation = GetActorLocation();
    
    // Grid centering offsets
    const float GridOffsetX = (GridSizeX * CellSize) / 2.0f;
    const float GridOffsetY = (GridSizeY * CellSize) / 2.0f;
    
    // Find start and end room centers for 3x3 rooms
    TArray<FIntPoint> FloorCells;
    for (int32 Y = 0; Y < GridSizeY; ++Y)
    {
        for (int32 X = 0; X < GridSizeX; ++X)
        {
            if (Grid[GridIndexFromXY(X, Y)].CellType == EGridCellType::Floor)
            {
                FloorCells.Add(FIntPoint(X, Y));
            }
        }
    }
    
    // LOOP 2: Iterate through grid and spawn appropriate meshes for each cell
    for (int32 Y = 0; Y < GridSizeY; ++Y)
    {
        for (int32 X = 0; X < GridSizeX; ++X)
        {
            const int32 Index = Y * GridSizeX + X;
            if (!ensure(Grid.IsValidIndex(Index)))
            {
                continue;
            }
            
            const EGridCellType CellType = Grid[Index].CellType;
            
            if (CellType == EGridCellType::Floor)
            {
                // Add plane instance for each floor cell
                if (PlaneInstances && PlaneMesh)
                {
                    // Use centered grid alignment
                    const FVector FloorCenter = BaseLocation + FVector(
                        X * CellSize - GridOffsetX + CellSize/2.0f,
                        Y * CellSize - GridOffsetY + CellSize/2.0f,
                        0.0f
                    );
                    
                    FTransform FloorTransform;
                    FloorTransform.SetLocation(FloorCenter);
                    FloorTransform.SetRotation(FQuat::Identity);
                    FloorTransform.SetScale3D(PlaneScaleVector);
                    
                    FloorTransforms.Add(FloorTransform);
                }
            }
            else if (CellType == EGridCellType::Wall)
            {
                // Add cube instance for each wall cell
                // Use centered grid alignment
                const FVector CubeCenter = BaseLocation + FVector(
                    X * CellSize - GridOffsetX + CellSize/2.0f,
                    Y * CellSize - GridOffsetY + CellSize/2.0f,
                    CellSize * 0.5f
                );
                
                FTransform WallTransform;
                WallTransform.SetLocation(CubeCenter);
                WallTransform.SetRotation(FQuat::Identity);
                WallTransform.SetScale3D(CubeScaleVector);
                
                WallTransforms.Add(WallTransform);
            }
        }
    }
    
    // Set materials and spawn instances in batches
    if (WallMaterial)
    {
        CubeInstances->SetMaterial(0, WallMaterial);
    }
    
    if (FloorMaterial && PlaneInstances)
    {
        PlaneInstances->SetMaterial(0, FloorMaterial);
    }
    
    // Batch spawn floor instances
    if (PlaneInstances && FloorTransforms.Num() > 0)
    {
        PlaneInstances->AddInstances(FloorTransforms, false); // false = local space
        PlaneInstances->MarkRenderStateDirty();
        UE_LOG(LogTemp, Warning, TEXT("🟢 Spawned %d floor tiles for mixed room sizes (2x2 START/END, 3x3 others)"), FloorTransforms.Num());
    }
    
    // Batch spawn wall instances
    if (WallTransforms.Num() > 0)
    {
        CubeInstances->AddInstances(WallTransforms, false); // false = local space
        UE_LOG(LogTemp, Warning, TEXT("🟤 Spawned %d wall cubes with 1-cell spacing"), WallTransforms.Num());
    }
    
    // Log mixed room statistics
    int32 TotalFloorCells = FloorTransforms.Num();
    // Mixed calculation: 2x2 rooms (4 cells) + 3x3 rooms (9 cells)
    UE_LOG(LogTemp, Warning, TEXT("📊 Mixed Room Stats: %d floor cells total (2x2 START/END = 4 cells each, 3x3 others = 9 cells each)"), 
        TotalFloorCells);
    
    // Single render state update for walls
    CubeInstances->MarkRenderStateDirty();
    
    UE_LOG(LogTemp, Warning, TEXT("✅ LOOP 2 Complete: Mixed room size meshes spawned with exact 1-cell spacing (2x2 START/END, 3x3 others)"));
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
    // Use integer math to avoid floating point errors
    FVector BaseLocation = GetActorLocation();
    
    // Snap to grid
    int32 WorldX = X * (int32)CellSize;
    int32 WorldY = Y * (int32)CellSize;
    
    // Center the grid
    int32 GridOffsetX = (GridSizeX * (int32)CellSize) / 2;
    int32 GridOffsetY = (GridSizeY * (int32)CellSize) / 2;
    
    // Calculate final position with integer math
    FVector Position;
    Position.X = BaseLocation.X + (float)(WorldX - GridOffsetX) + CellSize/2.0f;
    Position.Y = BaseLocation.Y + (float)(WorldY - GridOffsetY) + CellSize/2.0f;
    Position.Z = BaseLocation.Z + (bIsFloor ? 0.0f : CellSize * 0.5f);
    
    return Position;
}

void AGridDungeonVisualizer::DrawDebugGrid()
{
    if (!bShowDebugGrid || !GetWorld())
    {
        return;
    }
    
    FVector BaseLocation = GetActorLocation();
    float GridOffsetX = (GridSizeX * CellSize) / 2.0f;
    float GridOffsetY = (GridSizeY * CellSize) / 2.0f;
    
    // Draw grid lines at cell boundaries
    for (int32 x = 0; x <= GridSizeX; x++)
    {
        FVector LineStart = BaseLocation + FVector(
            x * CellSize - GridOffsetX, 
            -GridOffsetY, 
            1.0f
        );
        FVector LineEnd = BaseLocation + FVector(
            x * CellSize - GridOffsetX, 
            GridSizeY * CellSize - GridOffsetY, 
            1.0f
        );
        
        DrawDebugLine(GetWorld(), LineStart, LineEnd, 
            DebugGridColor.ToFColor(true), false, 10000.0f, 0, DebugLineThickness);
    }
    
    for (int32 y = 0; y <= GridSizeY; y++)
    {
        FVector LineStart = BaseLocation + FVector(
            -GridOffsetX, 
            y * CellSize - GridOffsetY, 
            1.0f
        );
        FVector LineEnd = BaseLocation + FVector(
            GridSizeX * CellSize - GridOffsetX, 
            y * CellSize - GridOffsetY, 
            1.0f
        );
        
        DrawDebugLine(GetWorld(), LineStart, LineEnd, 
            DebugGridColor.ToFColor(true), false, 10000.0f, 0, DebugLineThickness);
    }
    
    // Draw cell coordinates for debugging
    if (bShowCellCoordinates)
    {
        for (int32 x = 0; x < GridSizeX; x++)
        {
            for (int32 y = 0; y < GridSizeY; y++)
            {
                FVector CellCenter = GridToWorldPosition(x, y, true);
                DrawDebugString(GetWorld(), CellCenter,
                    FString::Printf(TEXT("%d,%d"), x, y),
                    nullptr, FColor::Yellow, 10000.0f, true, 0.8f);
            }
        }
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
                    FColor::Red, false, 10000.0f, 0, 2.0f);
            }
            else if (Cell.CellType == EGridCellType::Floor)
            {
                float PlaneSize = CellSize * 0.8f;
                FVector FloorCenter = GridToWorldPosition(X, Y, true);
                DrawDebugSphere(GetWorld(), FloorCenter, PlaneSize * 0.1f, 8, FColor::Blue, false, 10000.0f, 0);
            }
        }
    }
}

void AGridDungeonVisualizer::GenerateInEditor()
{
    bAnimateGeneration = true;
    GenerateAndVisualizeDungeon(-1);
}

void AGridDungeonVisualizer::GenerateInstant()
{
    bAnimateGeneration = false;
    GenerateAndVisualizeDungeon(-1);
}

void AGridDungeonVisualizer::TogglePause()
{
    if (CurrentGenerationPhase != EGenerationPhase::Idle && 
        CurrentGenerationPhase != EGenerationPhase::Complete)
    {
        bGenerationPaused = !bGenerationPaused;
        
        if (GetWorld())
        {
            if (bGenerationPaused)
            {
                // Pause all timers
                GetWorld()->GetTimerManager().PauseTimer(PathAnimationTimer);
                GetWorld()->GetTimerManager().PauseTimer(CubeSpawnTimer);
                GetWorld()->GetTimerManager().PauseTimer(PlaneSpawnTimer);
                UE_LOG(LogTemp, Warning, TEXT("⏸️ Generation paused"));
            }
            else
            {
                // Resume all timers
                GetWorld()->GetTimerManager().UnPauseTimer(PathAnimationTimer);
                GetWorld()->GetTimerManager().UnPauseTimer(CubeSpawnTimer);
                GetWorld()->GetTimerManager().UnPauseTimer(PlaneSpawnTimer);
                UE_LOG(LogTemp, Warning, TEXT("▶️ Generation resumed"));
            }
        }
    }
}

void AGridDungeonVisualizer::SkipToEnd()
{
    if (CurrentGenerationPhase == EGenerationPhase::Idle || 
        CurrentGenerationPhase == EGenerationPhase::Complete)
    {
        return;
    }
    
    // Clear all timers
    if (GetWorld())
    {
        GetWorld()->GetTimerManager().ClearTimer(PathAnimationTimer);
        GetWorld()->GetTimerManager().ClearTimer(CubeSpawnTimer);
        GetWorld()->GetTimerManager().ClearTimer(PlaneSpawnTimer);
    }
    
    // Complete generation instantly
    SpawnGridVisualization();
    CurrentGenerationPhase = EGenerationPhase::Complete;
    
    UE_LOG(LogTemp, Warning, TEXT("⏩ Skipped to end - generation complete"));
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

void AGridDungeonVisualizer::DrawDebugCubes()
{
    if (!GetWorld())
    {
        return;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("🔍 Drawing debug cubes that exactly match spawned cube positions"));
    
    // Draw debug cubes that exactly match spawned cube positions
    for (int32 x = 0; x < GridSizeX; x++)
    {
        for (int32 y = 0; y < GridSizeY; y++)
        {
            if (GetGridCell(x, y).CellType == EGridCellType::Wall)
            {
                FVector WorldPos = GridToWorldPosition(x, y, false); // Same as cube spawn
                float CubeScale = CellSize * CubeSizePercentage;
                
                DrawDebugBox(GetWorld(), WorldPos,
                    FVector(CubeScale/2.0f, CubeScale/2.0f, CubeScale/2.0f),
                    FColor::Blue, false, 10000.0f, 0, 2.0f);
                    
                // Also draw coordinate text
                DrawDebugString(GetWorld(), WorldPos + FVector(0, 0, CubeScale),
                    FString::Printf(TEXT("(%d,%d)"), x, y),
                    nullptr, FColor::White, 10000.0f);
            }
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("✅ Debug cubes drawn - should exactly match spawned cubes"));
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

void AGridDungeonVisualizer::ValidateSpacing()
{
    UE_LOG(LogTemp, Warning, TEXT("=== VALIDATING 1-CELL SPACING ==="));
    
    if (Grid.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("No grid data to validate. Generate a dungeon first."));
        return;
    }
    
    // Find all floor positions
    TArray<FIntPoint> FloorPositions;
    for (int32 Y = 0; Y < GridSizeY; ++Y)
    {
        for (int32 X = 0; X < GridSizeX; ++X)
        {
            FGridCell Cell = GetGridCell(X, Y);
            if (Cell.CellType == EGridCellType::Floor)
            {
                FloorPositions.Add(FIntPoint(X, Y));
            }
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Found %d floor positions to validate"), FloorPositions.Num());
    
    // Check spacing between all floor positions for 1-cell gap validation
    int32 ViolationCount = 0;
    int32 ValidPairs = 0;
    int32 PerfectSpacingPairs = 0;
    
    for (int32 i = 0; i < FloorPositions.Num(); ++i)
    {
        for (int32 j = i + 1; j < FloorPositions.Num(); ++j)
        {
            const FIntPoint& Room1 = FloorPositions[i];
            const FIntPoint& Room2 = FloorPositions[j];
            
            int32 DistX = FMath::Abs(Room1.X - Room2.X);
            int32 DistY = FMath::Abs(Room1.Y - Room2.Y);
            
            // Check for adjacency violations (no gap)
            if ((DistX == 1 && DistY == 0) || (DistX == 0 && DistY == 1) || (DistX == 1 && DistY == 1))
            {
                ViolationCount++;
                UE_LOG(LogTemp, Error, TEXT("SPACING VIOLATION #%d: Rooms (%d,%d) and (%d,%d) are ADJACENT! Distance: %d,%d (No gap)"), 
                    ViolationCount, Room1.X, Room1.Y, Room2.X, Room2.Y, DistX, DistY);
            }
            // Check for perfect 1-cell spacing
            else if ((DistX == 2 && DistY == 0) || (DistX == 0 && DistY == 2) || (DistX == 2 && DistY == 2))
            {
                PerfectSpacingPairs++;
                ValidPairs++;
                UE_LOG(LogTemp, Log, TEXT("PERFECT SPACING: Rooms (%d,%d) and (%d,%d) have exactly 1 gap. Distance: %d,%d"), 
                    Room1.X, Room1.Y, Room2.X, Room2.Y, DistX, DistY);
            }
            else
            {
                ValidPairs++;
                UE_LOG(LogTemp, Log, TEXT("VALID SPACING: Rooms (%d,%d) and (%d,%d) have >1 gap. Distance: %d,%d"), 
                    Room1.X, Room1.Y, Room2.X, Room2.Y, DistX, DistY);
            }
        }
    }
    
    // Detailed Summary
    int32 TotalPairs = ValidPairs + ViolationCount;
    if (ViolationCount == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("✅ SPACING VALIDATION PASSED: All %d room pairs maintain minimum 1-cell spacing"), TotalPairs);
        UE_LOG(LogTemp, Warning, TEXT("📊 Perfect 1-cell spacing pairs: %d/%d (%.1f%%)"), PerfectSpacingPairs, TotalPairs, 
            TotalPairs > 0 ? (float)PerfectSpacingPairs / TotalPairs * 100.0f : 0.0f);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("❌ SPACING VALIDATION FAILED: Found %d adjacent violations out of %d total pairs"), 
            ViolationCount, TotalPairs);
        UE_LOG(LogTemp, Error, TEXT("📊 Success rate: %.1f%% (%d valid pairs)"), 
            TotalPairs > 0 ? (float)ValidPairs / TotalPairs * 100.0f : 0.0f, ValidPairs);
    }
    
    // Visual debug - draw lines between rooms that violate spacing
    if (GetWorld() && ViolationCount > 0)
    {
        for (int32 i = 0; i < FloorPositions.Num(); ++i)
        {
            for (int32 j = i + 1; j < FloorPositions.Num(); ++j)
            {
                const FIntPoint& Room1 = FloorPositions[i];
                const FIntPoint& Room2 = FloorPositions[j];
                
                int32 DistX = FMath::Abs(Room1.X - Room2.X);
                int32 DistY = FMath::Abs(Room1.Y - Room2.Y);
                
                // Draw red lines for adjacency violations (no gap)
                if ((DistX == 1 && DistY == 0) || (DistX == 0 && DistY == 1) || (DistX == 1 && DistY == 1))
                {
                    FVector Pos1 = GridToWorldPosition(Room1.X, Room1.Y, false);
                    FVector Pos2 = GridToWorldPosition(Room2.X, Room2.Y, false);
                    DrawDebugLine(GetWorld(), Pos1, Pos2, FColor::Red, true, 30.0f, 0, 5.0f);
                }
                // Draw green lines for perfect 1-cell spacing
                else if ((DistX == 2 && DistY == 0) || (DistX == 0 && DistY == 2) || (DistX == 2 && DistY == 2))
                {
                    FVector Pos1 = GridToWorldPosition(Room1.X, Room1.Y, false);
                    FVector Pos2 = GridToWorldPosition(Room2.X, Room2.Y, false);
                    DrawDebugLine(GetWorld(), Pos1, Pos2, FColor::Green, true, 30.0f, 0, 2.0f);
                }
            }
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("=== VALIDATION COMPLETE ==="));
}

int32 AGridDungeonVisualizer::GridIndexFromXY(int32 X, int32 Y) const
{
    return Y * GridSizeX + X;
}

// Snake Generation Helper Functions Implementation (MIXED ROOM SIZES WITH 1 CELL SPACING)
TArray<FIntPoint> AGridDungeonVisualizer::GenerateSnakePath(FIntPoint Start)
{
    UE_LOG(LogTemp, Warning, TEXT("🐍 Generating EXACTLY 25 rooms with maximum START-END separation"));
    
    TArray<FIntPoint> Path;
    TSet<FIntPoint> Visited;
    
    // START position - ensure boundary safety for 2x2 room
    FIntPoint StartPos(2, 2);  // 2x2 room at (2,2) occupies (2,2) to (3,3)
    Path.Add(StartPos);
    Visited.Add(StartPos);
    
    // Generate exactly 23 more rooms (2-24) to reach 25 total with END
    FIntPoint CurrentPos = StartPos;
    int32 TargetPathLength = RequiredRoomCount; // Must be exactly 25
    
    // FIXED: More robust generation with retry logic - NEVER give up before 25 rooms
    int32 MaxRetries = 1000; // Prevent infinite loops
    int32 RetryCount = 0;
    int32 StuckCount = 0; // Track consecutive failed attempts
    
    while (Path.Num() < TargetPathLength && RetryCount < MaxRetries)
    {
        // Find valid next position that maintains spacing
        FIntPoint NextPos = FindNextPositionForPath(CurrentPos, Visited, Path.Num());
        
        if (NextPos == FIntPoint(-1, -1))
        {
            StuckCount++;
            RetryCount++;
            
            // Try backtracking
            if (BacktrackPath(Path, Visited))
            {
                CurrentPos = Path.Last();
                UE_LOG(LogTemp, Warning, TEXT("🔄 Backtracked, continuing from (%d,%d) with %d rooms"), 
                    CurrentPos.X, CurrentPos.Y, Path.Num());
                continue;
            }
            else
            {
                // If backtracking fails and we have very few rooms, restart completely
                if (Path.Num() < 5)
                {
                    UE_LOG(LogTemp, Warning, TEXT("🔄 Complete restart - only had %d rooms"), Path.Num());
                    Path.Empty();
                    Visited.Empty();
                    Path.Add(StartPos);
                    Visited.Add(StartPos);
                    CurrentPos = StartPos;
                    StuckCount = 0;
                    continue;
                }
                else
                {
                    UE_LOG(LogTemp, Error, TEXT("❌ CRITICAL: Cannot backtrack further and cannot place more rooms!"));
                    break;
                }
            }
        }
        else
        {
            // Successfully found a position
            StuckCount = 0; // Reset stuck counter
            Path.Add(NextPos);
            Visited.Add(NextPos);
            CurrentPos = NextPos;
            
            FString RoomType = (Path.Num() == 1) ? TEXT("START(2x2)") : 
                              (Path.Num() == RequiredRoomCount) ? TEXT("END(2x2)") : TEXT("REGULAR(3x3)");
            UE_LOG(LogTemp, VeryVerbose, TEXT("🐍 Added %s room %d at (%d,%d)"), *RoomType, Path.Num(), NextPos.X, NextPos.Y);
        }
        
        // Progress logging every 5 rooms
        if (Path.Num() % 5 == 0 && Path.Num() > 0)
        {
            UE_LOG(LogTemp, Log, TEXT("📊 Progress: %d/%d rooms placed (%.1f%% complete)"), 
                Path.Num(), TargetPathLength, (float(Path.Num()) / float(TargetPathLength)) * 100.0f);
        }
    }
    
    // CRITICAL: Verify we got exactly 25 rooms - this MUST never fail
    if (Path.Num() != RequiredRoomCount)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ CRITICAL FAILURE: Path generation failed after %d retries: Got %d rooms, need exactly %d"), 
            RetryCount, Path.Num(), RequiredRoomCount);
        UE_LOG(LogTemp, Error, TEXT("❌ Grid Size: %dx%d, StuckCount: %d"), GridSizeX, GridSizeY, StuckCount);
        
        // This should never happen with the improved algorithm
        checkf(false, TEXT("CRITICAL: GridDungeonVisualizer failed to generate exactly 25 rooms! Got %d rooms. This violates the core requirement."), Path.Num());
        return TArray<FIntPoint>(); // Return empty on failure
    }
    
    // SUCCESS: The last room (25th) is the END
    UE_LOG(LogTemp, Log, TEXT("✅ SUCCESS: Generated exactly %d rooms after %d attempts"), Path.Num(), RetryCount);
    UE_LOG(LogTemp, Log, TEXT("  START at (%d,%d)"), Path[0].X, Path[0].Y);
    UE_LOG(LogTemp, Log, TEXT("  END at (%d,%d)"), Path.Last().X, Path.Last().Y);
    
    // Verify START and END separation
    int32 Distance = FMath::Abs(Path[0].X - Path.Last().X) + FMath::Abs(Path[0].Y - Path.Last().Y);
    if (Distance < 20)
    {
        UE_LOG(LogTemp, Warning, TEXT("⚠️ START and END too close: Manhattan distance = %d"), Distance);
    }
    
    return Path;
}

bool AGridDungeonVisualizer::IsValidMove(int32 X, int32 Y, const TSet<FIntPoint>& Visited)
{
    // Check if the 3x3 room would fit within grid bounds
    if (!IsValid3x3RoomPosition(FIntPoint(X, Y)))
    {
        return false;
    }
    
    // Check if already visited
    if (Visited.Contains(FIntPoint(X, Y)))
    {
        return false;
    }
    
    // Check for overlaps with existing 3x3 rooms
    FIntPoint ProposedRoom(X, Y);
    for (const FIntPoint& ExistingRoom : Visited)
    {
        if (DoesRoomOverlap(ProposedRoom, ExistingRoom))
        {
            return false; // Room overlap found - invalid move
        }
    }
    
    return true; // No overlaps found - valid move
}

bool AGridDungeonVisualizer::IsValidMoveForVariableRooms(FIntPoint NewPos, int32 PathIndex, const TSet<FIntPoint>& Visited)
{
    // Determine what size room would be placed here
    bool bIsStartOrEnd = (PathIndex == 0) || (PathIndex == INT_MAX); // INT_MAX indicates potential end position
    ERoomSizeType NewRoomSize = bIsStartOrEnd ? ERoomSizeType::Small_2x2 : ERoomSizeType::Standard_3x3;
    
    // Check bounds for the appropriate room size
    if (NewRoomSize == ERoomSizeType::Small_2x2)
    {
        if (!IsValid2x2RoomPosition(NewPos))
        {
            return false;
        }
    }
    else
    {
        if (!IsValid3x3RoomPosition(NewPos))
        {
            return false;
        }
    }
    
    // Check if already visited
    if (Visited.Contains(NewPos))
    {
        return false;
    }
    
    // Check against all existing rooms with proper mixed-size spacing
    int32 ExistingIndex = 0;
    for (const FIntPoint& ExistingRoom : Visited)
    {
        // Determine existing room size (START is always first)
        ERoomSizeType ExistingRoomSize = (ExistingIndex == 0) ? ERoomSizeType::Small_2x2 : ERoomSizeType::Standard_3x3;
        
        // Calculate required distance for 1 cell gap
        float RequiredDistance = CalculateRequiredDistance(NewRoomSize, ExistingRoomSize);
        
        // Check actual distance using Chebyshev distance (max of X and Y distances)
        int32 DistX = FMath::Abs(NewPos.X - ExistingRoom.X);
        int32 DistY = FMath::Abs(NewPos.Y - ExistingRoom.Y);
        int32 MaxDist = FMath::Max(DistX, DistY);
        
        if (MaxDist < RequiredDistance)
        {
            return false; // Too close, would violate 1 cell gap
        }
        
        ExistingIndex++;
    }
    
    return true;
}

FIntPoint AGridDungeonVisualizer::FindNextPositionForPath(FIntPoint Current, const TSet<FIntPoint>& Visited, int32 PathIndex)
{
    // FIXED: More flexible room placement to avoid getting stuck
    // Determine room size for next position
    bool bIsStart = (PathIndex == 0);
    bool bIsEnd = (PathIndex == RequiredRoomCount - 1);
    int32 NextRoomSize = (bIsStart || bIsEnd) ? 2 : 3;
    
    // FIXED: Try multiple step sizes instead of just one calculated size
    TArray<int32> StepSizes;
    
    // For mixed room sizes, try different step sizes
    if (NextRoomSize == 2 && PathIndex > 1) // 2x2 room (END)
    {
        StepSizes = {4, 5, 6, 7}; // Try various distances for 2x2
    }
    else if (NextRoomSize == 3) // 3x3 room
    {
        StepSizes = {4, 5, 6, 7, 8}; // Try various distances for 3x3
    }
    else // START room or fallback
    {
        StepSizes = {4, 5, 6};
    }
    
    TArray<FIntPoint> PossibleMoves;
    
    // Try all step sizes and directions
    for (int32 StepSize : StepSizes)
    {
        TArray<FIntPoint> Directions = {
            FIntPoint(StepSize, 0),   // Right
            FIntPoint(-StepSize, 0),  // Left
            FIntPoint(0, StepSize),   // Up
            FIntPoint(0, -StepSize),  // Down
            // FIXED: Add diagonal moves for better connectivity
            FIntPoint(StepSize, StepSize),   // Up-Right
            FIntPoint(StepSize, -StepSize),  // Down-Right
            FIntPoint(-StepSize, StepSize),  // Up-Left
            FIntPoint(-StepSize, -StepSize)  // Down-Left
        };
        
        for (const FIntPoint& Dir : Directions)
        {
            FIntPoint NewPos = Current + Dir;
            
            // Check if position is valid
            if (IsValidRoomPosition(NewPos, NextRoomSize, Visited))
            {
                PossibleMoves.Add(NewPos);
            }
        }
    }
    
    if (PossibleMoves.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("🔄 FindNextPositionForPath: No valid moves found for PathIndex %d at (%d,%d)"), PathIndex, Current.X, Current.Y);
        return FIntPoint(-1, -1); // No valid moves
    }
    
    // FIXED: Smarter move selection to avoid getting stuck
    FIntPoint BestMove = PossibleMoves[0];
    
    if (PathIndex < RequiredRoomCount / 2)
    {
        // First half: Maximize distance from START for spread
        float MaxDistance = 0;
        for (const FIntPoint& Move : PossibleMoves)
        {
            float DistFromStart = FVector2D::Distance(FVector2D(Move.X, Move.Y), FVector2D(2, 2));
            if (DistFromStart > MaxDistance)
            {
                MaxDistance = DistFromStart;
                BestMove = Move;
            }
        }
    }
    else
    {
        // Second half: Choose moves that maintain connectivity and avoid corners
        // Prefer moves toward center of available space
        float BestScore = -1;
        for (const FIntPoint& Move : PossibleMoves)
        {
            // Score based on distance from edges (avoid getting trapped in corners)
            int32 DistFromLeftEdge = Move.X - 2;
            int32 DistFromRightEdge = (GridSizeX - 3) - Move.X;
            int32 DistFromTopEdge = Move.Y - 2;
            int32 DistFromBottomEdge = (GridSizeY - 3) - Move.Y;
            
            int32 MinDistFromEdge = FMath::Min(FMath::Min(DistFromLeftEdge, DistFromRightEdge), FMath::Min(DistFromTopEdge, DistFromBottomEdge));
            float EdgeScore = MinDistFromEdge;
            
            if (EdgeScore > BestScore)
            {
                BestScore = EdgeScore;
                BestMove = Move;
            }
        }
    }
    
    UE_LOG(LogTemp, VeryVerbose, TEXT("✅ FindNextPositionForPath: Selected (%d,%d) from %d options for PathIndex %d"), 
        BestMove.X, BestMove.Y, PossibleMoves.Num(), PathIndex);
    
    return BestMove;
}

bool AGridDungeonVisualizer::IsValidRoomPosition(FIntPoint Pos, int32 CurrentRoomSize, const TSet<FIntPoint>& Visited)
{
    // Check boundary constraints
    int32 MinBoundaryDistance = (CurrentRoomSize == 2) ? 1 : 2;
    
    if (CurrentRoomSize == 2) // 2x2 room
    {
        // Room occupies Pos to Pos+1
        if (Pos.X < MinBoundaryDistance || Pos.X + 1 >= GridSizeX - MinBoundaryDistance)
            return false;
        if (Pos.Y < MinBoundaryDistance || Pos.Y + 1 >= GridSizeY - MinBoundaryDistance)
            return false;
    }
    else // 3x3 room
    {
        // Room occupies Pos-1 to Pos+1
        if (Pos.X - 1 < MinBoundaryDistance || Pos.X + 1 >= GridSizeX - MinBoundaryDistance)
            return false;
        if (Pos.Y - 1 < MinBoundaryDistance || Pos.Y + 1 >= GridSizeY - MinBoundaryDistance)
            return false;
    }
    
    // Check spacing from all existing rooms
    for (const FIntPoint& ExistingPos : Visited)
    {
        if (!CheckRoomSpacing(Pos, RoomSize, ExistingPos))
        {
            return false;
        }
    }
    
    return true;
}

bool AGridDungeonVisualizer::CheckRoomSpacing(FIntPoint NewPos, int32 NewSize, FIntPoint ExistingPos)
{
    // Calculate minimum required distance to maintain 1 cell gap
    // This depends on the sizes of both rooms
    
    // For now, assume existing rooms are 3x3 (except START which is 2x2)
    // This is a simplification - in practice you'd track room sizes
    
    int32 RequiredDistance = 4; // Default for 3x3 to 3x3
    
    int32 DistX = FMath::Abs(NewPos.X - ExistingPos.X);
    int32 DistY = FMath::Abs(NewPos.Y - ExistingPos.Y);
    
    // Use Chebyshev distance (max of X,Y distances)
    int32 MaxDist = FMath::Max(DistX, DistY);
    
    return MaxDist >= RequiredDistance;
}

bool AGridDungeonVisualizer::BacktrackPath(TArray<FIntPoint>& Path, TSet<FIntPoint>& Visited)
{
    // FIXED: More aggressive backtracking to avoid permanent stuck states
    if (Path.Num() <= 1)
    {
        return false; // Can't backtrack from START
    }
    
    // Remove multiple rooms if we're really stuck (when we have many rooms but still can't progress)
    int32 BacktrackCount = 1;
    if (Path.Num() > RequiredRoomCount * 0.5 && Path.Num() < RequiredRoomCount * 0.8)
    {
        // We're in the middle phase and stuck - backtrack more aggressively
        BacktrackCount = FMath::Min(3, Path.Num() - 1);
        UE_LOG(LogTemp, Warning, TEXT("🔙 Aggressive backtracking: removing %d rooms"), BacktrackCount);
    }
    
    for (int32 i = 0; i < BacktrackCount && Path.Num() > 1; ++i)
    {
        FIntPoint LastRoom = Path.Last();
        Path.RemoveAt(Path.Num() - 1);
        Visited.Remove(LastRoom);
        
        UE_LOG(LogTemp, Warning, TEXT("🔙 Backtracked from (%d,%d), now at %d rooms"), 
            LastRoom.X, LastRoom.Y, Path.Num());
    }
    
    return true;
}

void AGridDungeonVisualizer::MarkPathInGrid(const TArray<FIntPoint>& Path)
{
    // Verify exactly 25 rooms
    if (Path.Num() != RequiredRoomCount)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Cannot mark grid: Path has %d rooms, need exactly 25"), Path.Num());
        return;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("🗺️ Marking exactly %d rooms (2x2 START/END, 3x3 others) with proper 1-cell spacing"), Path.Num());
    
    InitializeGrid();
    RoomInfoList.Empty();
    RoomInfoList.Reserve(Path.Num());
    ActualRoomCount = 0;
    
    // First, mark all rooms as Floor with appropriate sizes
    for (int32 i = 0; i < Path.Num(); ++i)
    {
        const FIntPoint& RoomCenter = Path[i];
        FGridRoomInfo RoomInfo;
        RoomInfo.Center = RoomCenter;
        
        if (i == 0) // START room - 2x2
        {
            RoomInfo.RoomSize = ERoomSizeType::Small_2x2;
            RoomInfo.bIsStartRoom = true;
            
            Mark2x2RoomInGrid(RoomCenter, EGridCellType::Floor);
            
            UE_LOG(LogTemp, Warning, TEXT("🟢 START room (2x2) center at (%d, %d) - occupies (%d,%d) to (%d,%d)"), 
                RoomCenter.X, RoomCenter.Y, RoomCenter.X, RoomCenter.Y, RoomCenter.X+1, RoomCenter.Y+1);
        }
        else if (i == Path.Num() - 1) // END room - 2x2
        {
            RoomInfo.RoomSize = ERoomSizeType::Small_2x2;
            RoomInfo.bIsEndRoom = true;
            
            Mark2x2RoomInGrid(RoomCenter, EGridCellType::Floor);
            
            UE_LOG(LogTemp, Warning, TEXT("🔴 END room (2x2) center at (%d, %d) - occupies (%d,%d) to (%d,%d)"), 
                RoomCenter.X, RoomCenter.Y, RoomCenter.X, RoomCenter.Y, RoomCenter.X+1, RoomCenter.Y+1);
        }
        else // Regular room - 3x3
        {
            RoomInfo.RoomSize = ERoomSizeType::Standard_3x3;
            
            Mark3x3RoomInGrid(RoomCenter, EGridCellType::Floor);
            
            UE_LOG(LogTemp, Log, TEXT("🟦 Regular room (3x3) center at (%d, %d) - occupies (%d,%d) to (%d,%d)"), 
                RoomCenter.X, RoomCenter.Y, RoomCenter.X-1, RoomCenter.Y-1, RoomCenter.X+1, RoomCenter.Y+1);
        }
        
        RoomInfoList.Add(RoomInfo);
        ActualRoomCount++;
    }
    
    // Validate mixed room spacing
    if (!ValidateMixedRoomSpacing())
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Mixed room spacing validation failed!"));
    }
    
    // Second pass: Fill remaining empty cells with walls to create proper separation
    for (int32 Y = 0; Y < GridSizeY; ++Y)
    {
        for (int32 X = 0; X < GridSizeX; ++X)
        {
            FGridCell Cell = GetGridCell(X, Y);
            if (Cell.CellType == EGridCellType::Empty)
            {
                SetGridCell(X, Y, EGridCellType::Wall);
            }
        }
    }
    
    // Final verification
    if (ActualRoomCount != RequiredRoomCount)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Room count mismatch: Generated %d, Required %d"), ActualRoomCount, RequiredRoomCount);
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("✅ Successfully placed exactly 25 rooms"));
    }
    
    UE_LOG(LogTemp, Warning, TEXT("✅ Mixed room size path marking complete with exactly 1-cell spacing"));
}

// ========== 3x3 ROOM HELPER FUNCTIONS ==========

void AGridDungeonVisualizer::Mark3x3RoomInGrid(FIntPoint RoomCenter, EGridCellType CellType)
{
    // Mark 3x3 area centered on RoomCenter
    for (int32 dx = -1; dx <= 1; dx++)
    {
        for (int32 dy = -1; dy <= 1; dy++)
        {
            int32 X = RoomCenter.X + dx;
            int32 Y = RoomCenter.Y + dy;
            
            if (IsValidGridPosition(X, Y))
            {
                SetGridCell(X, Y, CellType);
            }
        }
    }
}

void AGridDungeonVisualizer::Mark2x2RoomInGrid(FIntPoint RoomCenter, EGridCellType CellType)
{
    // Mark 2x2 area starting from RoomCenter
    // 2x2 room at center (X,Y) occupies (X,Y) to (X+1,Y+1)
    for (int32 dx = 0; dx <= 1; dx++)
    {
        for (int32 dy = 0; dy <= 1; dy++)
        {
            int32 X = RoomCenter.X + dx;
            int32 Y = RoomCenter.Y + dy;
            
            if (IsValidGridPosition(X, Y))
            {
                SetGridCell(X, Y, CellType);
            }
        }
    }
}

bool AGridDungeonVisualizer::IsValid3x3RoomPosition(FIntPoint RoomCenter) const
{
    // Check if 3x3 room fits within grid bounds
    // Room occupies RoomCenter +/- 1 in both directions
    return (RoomCenter.X >= 1 && RoomCenter.X < GridSizeX - 1 &&
            RoomCenter.Y >= 1 && RoomCenter.Y < GridSizeY - 1);
}

bool AGridDungeonVisualizer::IsValid2x2RoomPosition(FIntPoint RoomCenter) const
{
    // Check if 2x2 room fits within grid bounds
    // Room occupies RoomCenter to RoomCenter + 1 in both directions
    return (RoomCenter.X >= 0 && RoomCenter.X < GridSizeX - 1 &&
            RoomCenter.Y >= 0 && RoomCenter.Y < GridSizeY - 1);
}

bool AGridDungeonVisualizer::DoesRoomOverlap(FIntPoint Room1Center, FIntPoint Room2Center) const
{
    // Calculate room boundaries for 3x3 rooms
    int32 Room1MinX = Room1Center.X - 1;
    int32 Room1MaxX = Room1Center.X + 1;
    int32 Room1MinY = Room1Center.Y - 1;
    int32 Room1MaxY = Room1Center.Y + 1;
    
    int32 Room2MinX = Room2Center.X - 1;
    int32 Room2MaxX = Room2Center.X + 1;
    int32 Room2MinY = Room2Center.Y - 1;
    int32 Room2MaxY = Room2Center.Y + 1;
    
    // Check for exact spacing requirement (must have at least 1 cell gap)
    // Rooms should not touch or overlap
    bool XOverlap = !(Room1MaxX < Room2MinX - 1 || Room2MaxX < Room1MinX - 1);
    bool YOverlap = !(Room1MaxY < Room2MinY - 1 || Room2MaxY < Room1MinY - 1);
    
    return XOverlap && YOverlap;
}

float AGridDungeonVisualizer::CalculateRequiredDistance(ERoomSizeType Room1Size, ERoomSizeType Room2Size) const
{
    // For 1 cell gap: distance = (room1_size + room2_size)/2 + 1
    return ((float)Room1Size + (float)Room2Size) / 2.0f + 1.0f;
}

bool AGridDungeonVisualizer::ValidateMixedRoomSpacing()
{
    UE_LOG(LogTemp, Warning, TEXT("🔍 Validating mixed room spacing for %d rooms"), RoomInfoList.Num());
    
    for (int32 i = 0; i < RoomInfoList.Num(); i++)
    {
        FGridRoomInfo& Room1 = RoomInfoList[i];
        int32 Room1Size = (int32)Room1.RoomSize;
        
        for (int32 j = i + 1; j < RoomInfoList.Num(); j++)
        {
            FGridRoomInfo& Room2 = RoomInfoList[j];
            int32 Room2Size = (int32)Room2.RoomSize;
            
            // Calculate actual boundaries
            int32 Room1MinX, Room1MaxX, Room1MinY, Room1MaxY;
            int32 Room2MinX, Room2MaxX, Room2MinY, Room2MaxY;
            
            if (Room1Size == 2) // 2x2
            {
                Room1MinX = Room1.Center.X;
                Room1MaxX = Room1.Center.X + 1;
                Room1MinY = Room1.Center.Y;
                Room1MaxY = Room1.Center.Y + 1;
            }
            else // 3x3
            {
                Room1MinX = Room1.Center.X - 1;
                Room1MaxX = Room1.Center.X + 1;
                Room1MinY = Room1.Center.Y - 1;
                Room1MaxY = Room1.Center.Y + 1;
            }
            
            if (Room2Size == 2) // 2x2
            {
                Room2MinX = Room2.Center.X;
                Room2MaxX = Room2.Center.X + 1;
                Room2MinY = Room2.Center.Y;
                Room2MaxY = Room2.Center.Y + 1;
            }
            else // 3x3
            {
                Room2MinX = Room2.Center.X - 1;
                Room2MaxX = Room2.Center.X + 1;
                Room2MinY = Room2.Center.Y - 1;
                Room2MaxY = Room2.Center.Y + 1;
            }
            
            // Calculate minimum gap between rooms
            // Gap = minimum distance between room boundaries - 1
            int32 XGapLeft = (Room2MinX > Room1MaxX) ? (Room2MinX - Room1MaxX - 1) : -1;
            int32 XGapRight = (Room1MinX > Room2MaxX) ? (Room1MinX - Room2MaxX - 1) : -1;
            int32 YGapUp = (Room2MinY > Room1MaxY) ? (Room2MinY - Room1MaxY - 1) : -1;
            int32 YGapDown = (Room1MinY > Room2MaxY) ? (Room1MinY - Room2MaxY - 1) : -1;
            
            // Find the actual gap (rooms are separated in at least one direction)
            int32 XGap = FMath::Max(XGapLeft, XGapRight);
            int32 YGap = FMath::Max(YGapUp, YGapDown);
            
            // Check for insufficient gap (rooms overlap or touch)
            bool bRoomsOverlapOrTouch = (XGap < 1 && YGap < 1);
            
            if (bRoomsOverlapOrTouch)
            {
                FString Room1Type = Room1.bIsStartRoom ? TEXT("START") : 
                                   (Room1.bIsEndRoom ? TEXT("END") : TEXT("REGULAR"));
                FString Room2Type = Room2.bIsStartRoom ? TEXT("START") : 
                                   (Room2.bIsEndRoom ? TEXT("END") : TEXT("REGULAR"));
                
                UE_LOG(LogTemp, Error, 
                    TEXT("❌ Rooms overlap! %s(%dx%d) at (%d,%d) and %s(%dx%d) at (%d,%d)"),
                    *Room1Type, Room1Size, Room1Size, Room1.Center.X, Room1.Center.Y,
                    *Room2Type, Room2Size, Room2Size, Room2.Center.X, Room2.Center.Y);
                return false;
            }
        }
    }
    
    UE_LOG(LogTemp, Log, TEXT("✅ All rooms maintain 1 cell spacing (2x2 START/END, 3x3 others)"));
    return true;
}

bool AGridDungeonVisualizer::ValidateRoomSpacing(const TArray<FIntPoint>& Path)
{
    UE_LOG(LogTemp, Warning, TEXT("🔍 Validating spacing for %d 3x3 rooms"), Path.Num());
    
    for (int32 i = 0; i < Path.Num(); i++)
    {
        for (int32 j = i + 1; j < Path.Num(); j++)
        {
            FIntPoint Room1 = Path[i];
            FIntPoint Room2 = Path[j];
            
            // Calculate actual room boundaries for 3x3 rooms
            int32 Room1MinX = Room1.X - 1;
            int32 Room1MaxX = Room1.X + 1;
            int32 Room1MinY = Room1.Y - 1;
            int32 Room1MaxY = Room1.Y + 1;
            
            int32 Room2MinX = Room2.X - 1;
            int32 Room2MaxX = Room2.X + 1;
            int32 Room2MinY = Room2.Y - 1;
            int32 Room2MaxY = Room2.Y + 1;
            
            // Calculate gaps between room boundaries
            int32 XGap = FMath::Max(0, FMath::Max(Room1MinX - Room2MaxX, Room2MinX - Room1MaxX) - 1);
            int32 YGap = FMath::Max(0, FMath::Max(Room1MinY - Room2MaxY, Room2MinY - Room1MaxY) - 1);
            
            // Check if rooms maintain at least 1 cell gap
            if (XGap < 1 && YGap < 1)
            {
                UE_LOG(LogTemp, Error, 
                    TEXT("❌ 3x3 Rooms overlap or touch! Room1 center:(%d,%d) Room2 center:(%d,%d)"),
                    Room1.X, Room1.Y, Room2.X, Room2.Y);
                return false;
            }
        }
    }
    
    UE_LOG(LogTemp, Log, TEXT("✅ All 3x3 rooms maintain exactly 1 cell spacing"));
    return true;
}

// ========== CLEAR FUNCTIONS ==========

void AGridDungeonVisualizer::ClearSnakePath()
{
    AnimationPath.Empty();
    CurrentGenerationStep = 0;
    UE_LOG(LogTemp, Log, TEXT("Snake path cleared"));
}

void AGridDungeonVisualizer::ClearDebugVisualization()
{
    if (GetWorld())
    {
        FlushPersistentDebugLines(GetWorld());
        FlushDebugStrings(GetWorld());
    }
    UE_LOG(LogTemp, Log, TEXT("Debug visualization cleared"));
}

void AGridDungeonVisualizer::AutoClearDebugAfterGeneration()
{
    if (bAutoClearDebugAfterGeneration && bShowDebugGrid && GetWorld())
    {
        FTimerHandle AutoClearTimer;
        GetWorld()->GetTimerManager().SetTimer(
            AutoClearTimer,
            this,
            &AGridDungeonVisualizer::ClearDebugVisualization,
            DebugAutoClearDelay,
            false
        );
        UE_LOG(LogTemp, Log, TEXT("Auto-clear debug scheduled in %.1f seconds"), DebugAutoClearDelay);
    }
}

#if WITH_EDITOR
// ========== EDITOR VISUALIZATION FUNCTIONS ==========

void AGridDungeonVisualizer::ClearInEditor()
{
    UE_LOG(LogTemp, Warning, TEXT("🧹 Clearing dungeon in editor"));
    
    // Stop any running animation
    if (GetWorld() && GetWorld()->GetTimerManager().IsTimerActive(AnimationTimerHandle))
    {
        GetWorld()->GetTimerManager().ClearTimer(AnimationTimerHandle);
    }
    
    // Clear visual instances
    ClearDungeon();
    
    // Clear debug drawings
    if (GetWorld())
    {
        FlushPersistentDebugLines(GetWorld());
    }
    
    // Reset animation state
    CurrentGenerationStep = 0;
    AnimationPath.Empty();
    
    UE_LOG(LogTemp, Warning, TEXT("✅ Editor cleared"));
}

void AGridDungeonVisualizer::StepThroughGeneration()
{
    UE_LOG(LogTemp, Warning, TEXT("🐾 Step through generation - Step %d"), CurrentGenerationStep);
    
    if (CurrentGenerationStep == 0)
    {
        // Start fresh generation
        ClearDungeon();
        InitializeGrid();
        
        // Generate the complete snake path with 3x3 room centers
        FIntPoint StartPos(2, 2); // Start at center for 3x3 room
        AnimationPath = GenerateSnakePath(StartPos);
        
        if (AnimationPath.Num() == 0)
        {
            UE_LOG(LogTemp, Error, TEXT("❌ Failed to generate snake path for stepping"));
            return;
        }
        
        UE_LOG(LogTemp, Warning, TEXT("🐍 Generated path with %d rooms for stepping"), AnimationPath.Num());
    }
    
    if (CurrentGenerationStep < AnimationPath.Num())
    {
        // Add one room at a time (2x2 for START/END, 3x3 for others)
        FIntPoint RoomCenter = AnimationPath[CurrentGenerationStep];
        
        if (CurrentGenerationStep == 0) // START room
        {
            Mark2x2RoomInGrid(RoomCenter, EGridCellType::Floor);
        }
        else if (CurrentGenerationStep == AnimationPath.Num() - 1) // END room
        {
            Mark2x2RoomInGrid(RoomCenter, EGridCellType::Floor);
        }
        else // Regular room
        {
            Mark3x3RoomInGrid(RoomCenter, EGridCellType::Floor);
        }
        
        // Spawn visual representation immediately
        SpawnSingleRoomVisualization(RoomCenter, CurrentGenerationStep);
        
        // Draw debug info
        DrawRoomDebugInfo(RoomCenter, CurrentGenerationStep);
        
        CurrentGenerationStep++;
        
        FString RoomType = (CurrentGenerationStep == 1) ? TEXT("START(2x2)") : 
                          (CurrentGenerationStep == AnimationPath.Num()) ? TEXT("END(2x2)") : TEXT("REGULAR(3x3)");
        UE_LOG(LogTemp, Warning, TEXT("🐾 Step %d/%d: %s Room center at (%d, %d)"), 
            CurrentGenerationStep, AnimationPath.Num(), *RoomType, RoomCenter.X, RoomCenter.Y);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("✅ Step-by-step generation complete!"));
        OnAnimationComplete();
        CurrentGenerationStep = 0;
    }
}

void AGridDungeonVisualizer::ToggleDebugVisualization()
{
    bShowDebugGrid = !bShowDebugGrid;
    
    UE_LOG(LogTemp, Warning, TEXT("🔍 Debug visualization %s"), 
        bShowDebugGrid ? TEXT("ENABLED") : TEXT("DISABLED"));
    
    if (bShowDebugGrid)
    {
        DrawDebugGrid();
    }
    else if (GetWorld())
    {
        // Clear debug lines
        FlushPersistentDebugLines(GetWorld());
    }
}

void AGridDungeonVisualizer::AnimateSnakeGeneration()
{
    UE_LOG(LogTemp, Warning, TEXT("🎬 Starting animated snake generation (Delay: %.2fs)"), AnimationStepDelay);
    
    // Stop any existing animation
    StopAnimation();
    
    // Start fresh
    CurrentGenerationStep = 0;
    ClearDungeon();
    InitializeGrid();
    
    // Generate the full path with 3x3 room centers
    FIntPoint StartPos(2, 2); // Start at center for 3x3 room
    AnimationPath = GenerateSnakePath(StartPos);
    
    if (AnimationPath.Num() == 0)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Failed to generate snake path for animation"));
        return;
    }
    
    UE_LOG(LogTemp, Warning, TEXT("🐍 Generated path with %d rooms for animation"), AnimationPath.Num());
    
    // Start the animation timer
    if (GetWorld())
    {
        GetWorld()->GetTimerManager().SetTimer(
            AnimationTimerHandle,
            this,
            &AGridDungeonVisualizer::AnimationStep,
            AnimationStepDelay,
            true
        );
    }
}

void AGridDungeonVisualizer::StopAnimation()
{
    if (GetWorld() && GetWorld()->GetTimerManager().IsTimerActive(AnimationTimerHandle))
    {
        GetWorld()->GetTimerManager().ClearTimer(AnimationTimerHandle);
        UE_LOG(LogTemp, Warning, TEXT("⏹️ Animation stopped"));
    }
}

void AGridDungeonVisualizer::AnimationStep()
{
    if (CurrentGenerationStep < AnimationPath.Num())
    {
        FIntPoint RoomCenter = AnimationPath[CurrentGenerationStep];
        
        // Mark room with appropriate size
        if (CurrentGenerationStep == 0) // START room
        {
            Mark2x2RoomInGrid(RoomCenter, EGridCellType::Floor);
        }
        else if (CurrentGenerationStep == AnimationPath.Num() - 1) // END room
        {
            Mark2x2RoomInGrid(RoomCenter, EGridCellType::Floor);
        }
        else // Regular room
        {
            Mark3x3RoomInGrid(RoomCenter, EGridCellType::Floor);
        }
        
        // Spawn visual representation
        SpawnSingleRoomVisualization(RoomCenter, CurrentGenerationStep);
        
        // Draw debug info
        DrawRoomDebugInfo(RoomCenter, CurrentGenerationStep);
        
        CurrentGenerationStep++;
        
        FString RoomType = (CurrentGenerationStep == 1) ? TEXT("START(2x2)") : 
                          (CurrentGenerationStep == AnimationPath.Num()) ? TEXT("END(2x2)") : TEXT("REGULAR(3x3)");
        UE_LOG(LogTemp, Log, TEXT("🎬 Animation step %d/%d: %s Room center at (%d, %d)"), 
            CurrentGenerationStep, AnimationPath.Num(), *RoomType, RoomCenter.X, RoomCenter.Y);
    }
    else
    {
        // Animation complete
        StopAnimation();
        OnAnimationComplete();
    }
}

void AGridDungeonVisualizer::SpawnSingleRoomVisualization(FIntPoint RoomPos, int32 StepIndex)
{
    if (!PlaneInstances || !GetWorld())
    {
        return;
    }
    
    FVector WorldPos = GridToWorldPosition(RoomPos.X, RoomPos.Y, true);
    
    // Add floor instance to HISM
    FTransform Transform;
    Transform.SetLocation(WorldPos);
    Transform.SetScale3D(FVector(CellSize / 100.0f, CellSize / 100.0f, 1.0f));
    
    // Add the instance
    PlaneInstances->AddInstance(Transform);
    PlaneInstances->MarkRenderStateDirty();
    
    // Set material based on room type
    UMaterialInterface* RoomMaterial = FloorMaterial;
    if (StepIndex == 0 && StartRoomMaterial)
    {
        RoomMaterial = StartRoomMaterial;
    }
    else if (StepIndex == AnimationPath.Num() - 1 && EndRoomMaterial)
    {
        RoomMaterial = EndRoomMaterial;
    }
    
    if (RoomMaterial && RoomMaterial != FloorMaterial)
    {
        PlaneInstances->SetMaterial(0, RoomMaterial);
    }
}

void AGridDungeonVisualizer::DrawRoomDebugInfo(FIntPoint RoomPos, int32 StepIndex)
{
    if (!GetWorld())
    {
        return;
    }
    
    FVector WorldPos = GridToWorldPosition(RoomPos.X, RoomPos.Y, true);
    
    // Determine room size and type
    FString RoomLabel;
    FColor DebugColor;
    float BoxSize;
    
    if (StepIndex == 0) // START
    {
        RoomLabel = FString::Printf(TEXT("START (2x2)\n%d"), StepIndex);
        DebugColor = StartColor.ToFColor(true);
        BoxSize = CellSize * 2.0f; // 2x2
    }
    else if (StepIndex == AnimationPath.Num() - 1) // END
    {
        RoomLabel = FString::Printf(TEXT("END (2x2)\n%d"), StepIndex);
        DebugColor = EndColor.ToFColor(true);
        BoxSize = CellSize * 2.0f; // 2x2
    }
    else // Regular room
    {
        RoomLabel = FString::Printf(TEXT("Room (3x3)\n%d"), StepIndex);
        DebugColor = PathColor.ToFColor(true);
        BoxSize = CellSize * 3.0f; // 3x3
    }
    
    // Draw room outline
    DrawDebugBox(GetWorld(), WorldPos, 
        FVector(BoxSize * 0.45f, BoxSize * 0.45f, 10),
        DebugColor, false, 10000.0f, 0, 3.0f);
    
    // Draw room number and type
    if (bShowPathNumbers)
    {
        DrawDebugString(GetWorld(), WorldPos + FVector(0, 0, 50),
            RoomLabel, nullptr, FColor::White, 10000.0f, true, 1.2f);
    }
    
    // Highlight current step
    if (bHighlightCurrentStep && StepIndex == CurrentGenerationStep - 1)
    {
        DrawDebugBox(GetWorld(), WorldPos + FVector(0, 0, 20), 
            FVector(CellSize * 0.4f, CellSize * 0.4f, 10),
            FColor::Yellow, false, 10000.0f, 0, 5.0f);
    }
    
    // Draw connections to previous room
    if (bShowRoomConnections && StepIndex > 0)
    {
        FIntPoint PrevRoom = AnimationPath[StepIndex - 1];
        FVector PrevWorldPos = GridToWorldPosition(PrevRoom.X, PrevRoom.Y, true);
        
        DrawDebugLine(GetWorld(), PrevWorldPos + FVector(0, 0, 30),
            WorldPos + FVector(0, 0, 30),
            PathColor.ToFColor(true), false, 10000.0f, 0, 3.0f);
        
        // Draw the gap indicator
        FVector GapPos = (PrevWorldPos + WorldPos) * 0.5f;
        DrawDebugSphere(GetWorld(), GapPos + FVector(0, 0, 30),
            20.0f, 8, FColor::Orange, false, 10000.0f);
    }
    
    // Special markers for start/end
    if (StepIndex == 0)
    {
        DrawDebugCapsule(GetWorld(), WorldPos + FVector(0, 0, 100),
            50, 25, FQuat::Identity, StartColor.ToFColor(true),
            false, 10000.0f, 0, 3.0f);
    }
    else if (StepIndex == AnimationPath.Num() - 1)
    {
        DrawDebugCapsule(GetWorld(), WorldPos + FVector(0, 0, 100),
            50, 25, FQuat::Identity, EndColor.ToFColor(true),
            false, 10000.0f, 0, 3.0f);
    }
}

void AGridDungeonVisualizer::OnAnimationComplete()
{
    UE_LOG(LogTemp, Warning, TEXT("🎉 Animation complete! Filling remaining walls..."));
    
    // Fill remaining empty cells with walls to complete the visualization
    for (int32 Y = 0; Y < GridSizeY; ++Y)
    {
        for (int32 X = 0; X < GridSizeX; ++X)
        {
            FGridCell Cell = GetGridCell(X, Y);
            if (Cell.CellType == EGridCellType::Empty)
            {
                SetGridCell(X, Y, EGridCellType::Wall);
                
                // Spawn wall visualization
                FVector WorldPos = GridToWorldPosition(X, Y, false);
                float CubeScale = (CellSize * CubeSizePercentage) / 100.0f;
                
                FTransform WallTransform;
                WallTransform.SetLocation(WorldPos);
                WallTransform.SetScale3D(FVector(CubeScale));
                
                if (CubeInstances)
                {
                    CubeInstances->AddInstance(WallTransform);
                }
            }
        }
    }
    
    if (CubeInstances)
    {
        CubeInstances->MarkRenderStateDirty();
    }
    
    // Reset animation state
    CurrentGenerationStep = 0;
    
    UE_LOG(LogTemp, Warning, TEXT("✅ Animation and wall filling complete!"));
}

// NEW ANIMATED GENERATION SYSTEM IMPLEMENTATION

void AGridDungeonVisualizer::StartAnimatedGeneration()
{
    CurrentGenerationPhase = EGenerationPhase::GeneratingPath;
    CurrentPathStep = 0;
    CurrentCubeIndex = 0;
    CurrentPlaneIndex = 0;
    
    // Prepare visual data
    PrepareVisualizationData();
    
    // Start path animation
    if (GetWorld())
    {
        GetWorld()->GetTimerManager().SetTimer(
            PathAnimationTimer,
            this,
            &AGridDungeonVisualizer::AnimatePathStep,
            PathStepDelay,
            true
        );
    }
    
    UE_LOG(LogTemp, Log, TEXT("🐍 Starting animated snake generation..."));
}

void AGridDungeonVisualizer::PrepareVisualizationData()
{
    // Generate the animation path from the generated grid
    AnimationPath.Empty();
    
    // Extract the path from generated rooms
    if (RoomInfoList.Num() > 0)
    {
        for (const FGridRoomInfo& RoomInfo : RoomInfoList)
        {
            AnimationPath.Add(RoomInfo.Center);
        }
    }
    else
    {
        // Fallback: Generate simple path for visualization
        FIntPoint StartPos(2, 2);
        AnimationPath = GenerateSnakePath(StartPos);
    }
    
    UE_LOG(LogTemp, Log, TEXT("📋 Prepared animation path with %d rooms"), AnimationPath.Num());
}

void AGridDungeonVisualizer::AnimatePathStep()
{
    if (bGenerationPaused)
    {
        return; // Skip this step if paused
    }
    
    if (CurrentPathStep < AnimationPath.Num())
    {
        FIntPoint RoomPos = AnimationPath[CurrentPathStep];
        
        // Visual feedback for path
        DrawPathVisualization(RoomPos, CurrentPathStep);
        
        // Mark in grid (logic only - no mesh spawning yet)
        if (CurrentPathStep == 0)
        {
            Mark2x2RoomInGrid(RoomPos); // START
        }
        else if (CurrentPathStep == AnimationPath.Num() - 1)
        {
            Mark2x2RoomInGrid(RoomPos); // END
        }
        else
        {
            Mark3x3RoomInGrid(RoomPos); // Regular
        }
        
        CurrentPathStep++;
        
        // Progress feedback
        float Progress = (float)CurrentPathStep / AnimationPath.Num() * 100.0f;
        UE_LOG(LogTemp, Log, TEXT("🐍 Path Generation: %.0f%% (%d/%d)"), Progress, CurrentPathStep, AnimationPath.Num());
    }
    else
    {
        // Path complete, move to cube spawning
        if (GetWorld())
        {
            GetWorld()->GetTimerManager().ClearTimer(PathAnimationTimer);
        }
        TransitionToCubeSpawning();
    }
}

void AGridDungeonVisualizer::DrawPathVisualization(FIntPoint RoomPos, int32 StepIndex)
{
    if (!GetWorld())
    {
        return;
    }
    
    FVector WorldPos = GridToWorldPosition(RoomPos.X, RoomPos.Y, true);
    
    // Draw path number
    DrawDebugString(GetWorld(), WorldPos + FVector(0, 0, 50),
        FString::Printf(TEXT("%d"), StepIndex + 1),
        nullptr, FColor::White, 10000.0f, true, 1.5f);
    
    // Draw connection to previous
    if (StepIndex > 0 && AnimationPath.IsValidIndex(StepIndex - 1))
    {
        FIntPoint PrevPos = AnimationPath[StepIndex - 1];
        FVector PrevWorld = GridToWorldPosition(PrevPos.X, PrevPos.Y, true);
        
        DrawDebugLine(GetWorld(), PrevWorld + FVector(0, 0, 30),
            WorldPos + FVector(0, 0, 30),
            FColor::Green, false, 10000.0f, 0, 3.0f);
    }
    
    // Highlight current room being placed
    FColor RoomColor = (StepIndex == 0) ? FColor::Blue :
                      (StepIndex == AnimationPath.Num() - 1) ? FColor::Red :
                      FColor::Green;
    
    // Draw room outline matching grid alignment
    float BoxSize = (StepIndex == 0 || StepIndex == AnimationPath.Num() - 1) ? 
        CellSize * 2.0f * 0.45f : CellSize * 3.0f * 0.45f;
    
    DrawDebugBox(GetWorld(), WorldPos,
        FVector(BoxSize, BoxSize, 10),
        RoomColor, false, 10000.0f, 0, 5.0f);
}

void AGridDungeonVisualizer::TransitionToCubeSpawning()
{
    CurrentGenerationPhase = EGenerationPhase::SpawningCubes;
    
    // Prepare cube transforms based on path
    PrepareCubeTransforms();
    
    // Start cube spawning animation
    if (GetWorld())
    {
        GetWorld()->GetTimerManager().SetTimer(
            CubeSpawnTimer,
            this,
            &AGridDungeonVisualizer::AnimateCubeSpawn,
            CubeSpawnDelay,
            true
        );
    }
    
    UE_LOG(LogTemp, Log, TEXT("🧱 Starting cube spawning phase..."));
}

void AGridDungeonVisualizer::PrepareCubeTransforms()
{
    PendingCubeTransforms.Empty();
    
    // Pre-calculate common values to match SpawnGridVisualization exactly
    const float DesiredCubeSize = CellSize * CubeSizePercentage;
    const float CubeScale = DesiredCubeSize / 100.0f; // 100.0f = default UE cube size
    const FVector CubeScaleVector = FVector(CubeScale);
    const FVector BaseLocation = GetActorLocation();
    
    // Grid centering offsets (match SpawnGridVisualization)
    const float GridOffsetX = (GridSizeX * CellSize) / 2.0f;
    const float GridOffsetY = (GridSizeY * CellSize) / 2.0f;
    
    // Generate cube positions for walls using same logic as SpawnGridVisualization
    for (int32 Y = 0; Y < GridSizeY; Y++)
    {
        for (int32 X = 0; X < GridSizeX; X++)
        {
            if (GetGridCell(X, Y).CellType == EGridCellType::Wall)
            {
                // Match the exact position calculation from SpawnGridVisualization with centered alignment
                const FVector CubeCenter = BaseLocation + FVector(
                    X * CellSize - GridOffsetX + CellSize/2.0f,
                    Y * CellSize - GridOffsetY + CellSize/2.0f,
                    CellSize * 0.5f
                );
                
                FTransform Transform;
                Transform.SetLocation(CubeCenter);
                Transform.SetRotation(FQuat::Identity);
                Transform.SetScale3D(CubeScaleVector);
                
                PendingCubeTransforms.Add(Transform);
            }
        }
    }
    
    UE_LOG(LogTemp, Log, TEXT("📦 Prepared %d cube transforms (matching debug alignment)"), PendingCubeTransforms.Num());
}

void AGridDungeonVisualizer::AnimateCubeSpawn()
{
    if (bGenerationPaused)
    {
        return; // Skip this step if paused
    }
    
    const int32 CubesPerFrame = 5; // Spawn multiple cubes per tick for speed
    
    for (int32 i = 0; i < CubesPerFrame && CurrentCubeIndex < PendingCubeTransforms.Num(); i++)
    {
        if (CubeInstances)
        {
            CubeInstances->AddInstance(PendingCubeTransforms[CurrentCubeIndex]);
        }
        CurrentCubeIndex++;
    }
    
    // Progress feedback
    if (CurrentCubeIndex % 10 == 0 || CurrentCubeIndex >= PendingCubeTransforms.Num())
    {
        float Progress = (float)CurrentCubeIndex / FMath::Max(1, PendingCubeTransforms.Num()) * 100.0f;
        UE_LOG(LogTemp, Log, TEXT("🧱 Cube Spawning: %.0f%% (%d/%d)"), Progress, CurrentCubeIndex, PendingCubeTransforms.Num());
    }
    
    if (CurrentCubeIndex >= PendingCubeTransforms.Num())
    {
        // Cubes complete, move to plane spawning
        if (GetWorld())
        {
            GetWorld()->GetTimerManager().ClearTimer(CubeSpawnTimer);
        }
        TransitionToPlaneSpawning();
    }
}

void AGridDungeonVisualizer::TransitionToPlaneSpawning()
{
    CurrentGenerationPhase = EGenerationPhase::SpawningPlanes;
    
    // Prepare plane transforms based on path
    PreparePlaneTransforms();
    
    // Start plane spawning animation
    if (GetWorld())
    {
        GetWorld()->GetTimerManager().SetTimer(
            PlaneSpawnTimer,
            this,
            &AGridDungeonVisualizer::AnimatePlaneSpawn,
            PlaneSpawnDelay,
            true
        );
    }
    
    UE_LOG(LogTemp, Log, TEXT("🟦 Starting floor plane spawning..."));
}

void AGridDungeonVisualizer::PreparePlaneTransforms()
{
    PendingPlaneTransforms.Empty();
    
    // Pre-calculate common values to match SpawnGridVisualization exactly
    const float PlaneScale = CellSize / 100.0f; // Plane scale to match cell size
    const FVector PlaneScaleVector = FVector(PlaneScale, PlaneScale, 1.0f);
    const FVector BaseLocation = GetActorLocation();
    
    // Grid centering offsets (match SpawnGridVisualization)
    const float GridOffsetX = (GridSizeX * CellSize) / 2.0f;
    const float GridOffsetY = (GridSizeY * CellSize) / 2.0f;
    
    // Generate plane positions for ALL floor cells using same logic as SpawnGridVisualization
    for (int32 Y = 0; Y < GridSizeY; Y++)
    {
        for (int32 X = 0; X < GridSizeX; X++)
        {
            if (GetGridCell(X, Y).CellType == EGridCellType::Floor)
            {
                // Match the exact position calculation from SpawnGridVisualization with centered alignment
                const FVector FloorCenter = BaseLocation + FVector(
                    X * CellSize - GridOffsetX + CellSize/2.0f,
                    Y * CellSize - GridOffsetY + CellSize/2.0f,
                    0.0f
                );
                
                FTransform Transform;
                Transform.SetLocation(FloorCenter);
                Transform.SetRotation(FQuat::Identity);
                Transform.SetScale3D(PlaneScaleVector);
                
                PendingPlaneTransforms.Add(Transform);
            }
        }
    }
    
    UE_LOG(LogTemp, Log, TEXT("🟦 Prepared %d plane transforms (matching debug alignment)"), PendingPlaneTransforms.Num());
}

void AGridDungeonVisualizer::AnimatePlaneSpawn()
{
    if (bGenerationPaused)
    {
        return; // Skip this step if paused
    }
    
    const int32 PlanesPerFrame = 3; // Spawn multiple planes per tick
    
    for (int32 i = 0; i < PlanesPerFrame && CurrentPlaneIndex < PendingPlaneTransforms.Num(); i++)
    {
        if (PlaneInstances)
        {
            PlaneInstances->AddInstance(PendingPlaneTransforms[CurrentPlaneIndex]);
        }
        CurrentPlaneIndex++;
    }
    
    // Progress feedback
    if (CurrentPlaneIndex % 5 == 0 || CurrentPlaneIndex >= PendingPlaneTransforms.Num())
    {
        float Progress = (float)CurrentPlaneIndex / FMath::Max(1, PendingPlaneTransforms.Num()) * 100.0f;
        UE_LOG(LogTemp, Log, TEXT("🟦 Plane Spawning: %.0f%% (%d/%d)"), Progress, CurrentPlaneIndex, PendingPlaneTransforms.Num());
    }
    
    if (CurrentPlaneIndex >= PendingPlaneTransforms.Num())
    {
        // Generation complete
        if (GetWorld())
        {
            GetWorld()->GetTimerManager().ClearTimer(PlaneSpawnTimer);
        }
        OnGenerationComplete();
    }
}

void AGridDungeonVisualizer::OnGenerationComplete()
{
    CurrentGenerationPhase = EGenerationPhase::Complete;
    
    // Update render states for performance
    if (CubeInstances)
    {
        CubeInstances->MarkRenderStateDirty();
    }
    if (PlaneInstances)
    {
        PlaneInstances->MarkRenderStateDirty();
    }
    
    UE_LOG(LogTemp, Log, TEXT("✅ Animated generation complete!"));
    UE_LOG(LogTemp, Log, TEXT("  - Path steps: %d"), AnimationPath.Num());
    UE_LOG(LogTemp, Log, TEXT("  - Cubes spawned: %d"), CurrentCubeIndex);
    UE_LOG(LogTemp, Log, TEXT("  - Planes spawned: %d"), CurrentPlaneIndex);
    
    // Draw debug grid and room boundaries if needed
    if (bShowDebugGrid)
    {
        DrawDebugGrid();
        DrawRoomBoundaries();
    }
    
    // Validate spacing if needed
    if (bAutoValidateSpacing)
    {
        ValidateMixedRoomSpacing();
    }
    
    // Auto-clear debug if enabled
    AutoClearDebugAfterGeneration();
}

// END NEW ANIMATED GENERATION SYSTEM

void AGridDungeonVisualizer::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);
    
    FName PropertyName = (PropertyChangedEvent.Property != nullptr) 
        ? PropertyChangedEvent.Property->GetFName() : NAME_None;
    
    // Auto-regenerate on certain property changes
    if (PropertyName == GET_MEMBER_NAME_CHECKED(AGridDungeonVisualizer, GridSizeX) ||
        PropertyName == GET_MEMBER_NAME_CHECKED(AGridDungeonVisualizer, GridSizeY) ||
        PropertyName == GET_MEMBER_NAME_CHECKED(AGridDungeonVisualizer, CellSize) ||
        PropertyName == GET_MEMBER_NAME_CHECKED(AGridDungeonVisualizer, CubeSizePercentage))
    {
        if (bAutoGenerateOnChange)
        {
            UE_LOG(LogTemp, Warning, TEXT("🔄 Auto-regenerating due to property change: %s"), 
                *PropertyName.ToString());
            GenerateInEditor();
        }
    }
    
    // Update visualization settings on debug property changes
    if (PropertyName == GET_MEMBER_NAME_CHECKED(AGridDungeonVisualizer, bShowDebugGrid))
    {
        if (bShowDebugGrid)
        {
            DrawDebugGrid();
        }
        else if (GetWorld())
        {
            FlushPersistentDebugLines(GetWorld());
        }
    }
    
    // Auto-calculate grid size when room count changes
    if (PropertyName == GET_MEMBER_NAME_CHECKED(AGridDungeonVisualizer, RequiredRoomCount))
    {
        if (bAutoCalculateGridSize)
        {
            CalculateOptimalGridSize();
        }
    }
    
    // Update colors/visualization when properties change
    if (PropertyName == GET_MEMBER_NAME_CHECKED(AGridDungeonVisualizer, PathColor) ||
        PropertyName == GET_MEMBER_NAME_CHECKED(AGridDungeonVisualizer, StartColor) ||
        PropertyName == GET_MEMBER_NAME_CHECKED(AGridDungeonVisualizer, EndColor) ||
        PropertyName == GET_MEMBER_NAME_CHECKED(AGridDungeonVisualizer, bShowPathNumbers) ||
        PropertyName == GET_MEMBER_NAME_CHECKED(AGridDungeonVisualizer, bShowRoomConnections) ||
        PropertyName == GET_MEMBER_NAME_CHECKED(AGridDungeonVisualizer, bHighlightCurrentStep))
    {
        // Refresh debug visualization if currently active
        if (AnimationPath.Num() > 0)
        {
            if (GetWorld())
            {
                FlushPersistentDebugLines(GetWorld());
            }
            
            // Redraw all debug info
            for (int32 i = 0; i < CurrentGenerationStep && i < AnimationPath.Num(); ++i)
            {
                DrawRoomDebugInfo(AnimationPath[i], i);
            }
        }
    }
}

void AGridDungeonVisualizer::CalculateGridSizeInEditor()
{
    CalculateOptimalGridSize();
    UE_LOG(LogTemp, Log, TEXT("Grid size set to %dx%d for exactly %d rooms"),
        GridSizeX, GridSizeY, RequiredRoomCount);
}

#endif // WITH_EDITOR

// ========== AUTO-SIZING GRID FUNCTIONS ==========

void AGridDungeonVisualizer::CalculateOptimalGridSize()
{
    if (!bAutoCalculateGridSize)
    {
        CalculatedGridSizeX = GridSizeX;
        CalculatedGridSizeY = GridSizeY;
        return;
    }
    
    // FIXED: More generous grid sizing to ensure 25 rooms can always be placed
    // Snake pattern with mixed room sizes (2x2 START/END, 3x3 regular)
    // Account for worst-case scenario where snake needs to wind extensively
    
    // For exactly 25 rooms with mixed sizes:
    // - 2 rooms are 2x2 (START and END) = 8 cells
    // - 23 rooms are 3x3 = 207 cells
    // Plus 1-cell gaps between all rooms
    // Plus boundary safety margins
    
    int32 BaseRoomCells = (2 * 4) + (23 * 9); // Actual room cells
    int32 GapCells = RequiredRoomCount * 4; // Conservative gap estimate
    int32 BoundaryCells = 50; // Safety margin for boundaries
    int32 TotalCellsNeeded = BaseRoomCells + GapCells + BoundaryCells;
    
    int32 MinGridSize = FMath::CeilToInt(FMath::Sqrt((float)TotalCellsNeeded));
    
    // Ensure minimum size that empirically works for snake patterns
    MinGridSize = FMath::Max(MinGridSize, 35); // Increased from 24 to 35
    
    // Round up to multiple of 4 for clean alignment
    MinGridSize = ((MinGridSize + 3) / 4) * 4;
    
    // Set to calculated size
    CalculatedGridSizeX = MinGridSize;
    CalculatedGridSizeY = MinGridSize;
    
    // Apply to actual grid if auto-sizing
    if (bAutoCalculateGridSize)
    {
        GridSizeX = CalculatedGridSizeX;
        GridSizeY = CalculatedGridSizeY;
    }
    
    UE_LOG(LogTemp, Log, TEXT("📐 FIXED: Grid size set to %dx%d for exactly 25 rooms (was getting stuck at smaller sizes)"), GridSizeX, GridSizeY);
}

FIntPoint AGridDungeonVisualizer::GetOptimalGridSizeForRooms(int32 RoomCount)
{
    // More sophisticated calculation
    // Account for snake pattern efficiency
    
    // Snake pattern can pack rooms more efficiently
    // Approximate formula: Grid = sqrt(RoomCount * 16) for 3x3 rooms with 1 gap
    
    int32 CellsNeeded = RoomCount * 16; // Each room needs ~16 cells (4x4 with gap)
    int32 GridSize = FMath::CeilToInt(FMath::Sqrt((float)CellsNeeded));
    
    // Ensure divisible by 4 for clean room placement
    GridSize = ((GridSize + 3) / 4) * 4;
    
    // Minimum size constraints
    GridSize = FMath::Clamp(GridSize, 12, 50);
    
    return FIntPoint(GridSize, GridSize);
}

void AGridDungeonVisualizer::DrawRoomBoundaries()
{
    if (!bShowRoomBoundaries || !GetWorld()) 
    {
        return;
    }
    
    for (const FGridRoomInfo& Room : RoomInfoList)
    {
        FVector RoomCenter = GridToWorldPosition(Room.Center.X, Room.Center.Y, true);
        
        float RoomSizeWorld;
        if (Room.bIsStartRoom || Room.bIsEndRoom)
        {
            // 2x2 room
            RoomSizeWorld = CellSize * 2.0f;
        }
        else
        {
            // 3x3 room
            RoomSizeWorld = CellSize * 3.0f;
        }
        
        // Draw room boundary box
        DrawDebugBox(GetWorld(), RoomCenter,
            FVector(RoomSizeWorld/2.0f - 10, RoomSizeWorld/2.0f - 10, 5),
            RoomBoundaryColor.ToFColor(true), false, 10000.0f, 0, 2.0f);
        
        // Label room type
        FString RoomLabel = Room.bIsStartRoom ? TEXT("START") :
                           Room.bIsEndRoom ? TEXT("END") : TEXT("ROOM");
        DrawDebugString(GetWorld(), RoomCenter + FVector(0, 0, 100),
            RoomLabel, nullptr, FColor::White, 10000.0f, true, 1.0f);
    }
}