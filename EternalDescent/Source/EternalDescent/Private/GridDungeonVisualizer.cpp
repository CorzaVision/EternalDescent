// GridDungeonVisualizer.cpp - Simple grid-based cube visualization
#include "GridDungeonVisualizer.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Engine/Engine.h"
#include "DrawDebugHelpers.h"
#include "Materials/MaterialInterface.h"

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
    
    InitializeGrid();
    
    // Auto-generate a simple pattern
    GenerateAndVisualizeDungeon();
}

void AGridDungeonVisualizer::InitializeComponents()
{
    // Create instanced mesh components for performance
    PlaneInstances = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("PlaneInstances"));
    PlaneInstances->SetupAttachment(RootComponent);
    
    CubeInstances = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("CubeInstances"));
    CubeInstances->SetupAttachment(RootComponent);
    
    // Basic collision settings
    PlaneInstances->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    PlaneInstances->SetCollisionResponseToAllChannels(ECR_Block);
    
    CubeInstances->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    CubeInstances->SetCollisionResponseToAllChannels(ECR_Block);
}

void AGridDungeonVisualizer::InitializeGrid()
{
    // Initialize grid array
    const int32 TotalCells = GridSizeX * GridSizeY;
    Grid.Empty(TotalCells);
    Grid.SetNum(TotalCells);
    
    // Set all cells to empty by default
    for (int32 i = 0; i < TotalCells; ++i)
    {
        Grid[i].CellType = EGridCellType::Empty;
    }
}

void AGridDungeonVisualizer::GenerateAndVisualizeDungeon(int32 Seed)
{
    ClearDungeon();
    
    // Use seed for reproducible generation
    if (Seed > 0)
    {
        FMath::RandInit(Seed);
    }
    
    GenerateSimpleLayout();
    SpawnGridVisualization();
    
    if (bShowDebugGrid)
    {
        DrawDebugGrid();
    }
}

void AGridDungeonVisualizer::GenerateSimpleLayout()
{
    // Simple 2x2 test pattern - just place walls in all cells for testing
    for (int32 Y = 0; Y < GridSizeY; ++Y)
    {
        for (int32 X = 0; X < GridSizeX; ++X)
        {
            // Place a wall cube in each cell for testing
            SetGridCell(X, Y, EGridCellType::Wall);
        }
    }
    
    // Log the layout for debugging
    UE_LOG(LogTemp, Warning, TEXT("Generated %dx%d grid with wall cubes in all cells"), GridSizeX, GridSizeY);
}

void AGridDungeonVisualizer::SpawnGridVisualization()
{
    if (!PlaneInstances || !CubeInstances)
    {
        UE_LOG(LogTemp, Error, TEXT("Instance components not initialized"));
        return;
    }
    
    // Set meshes if available
    if (PlaneMesh)
    {
        PlaneInstances->SetStaticMesh(PlaneMesh);
        if (FloorMaterial)
        {
            PlaneInstances->SetMaterial(0, FloorMaterial);
        }
    }
    
    if (CubeMesh)
    {
        CubeInstances->SetStaticMesh(CubeMesh);
        if (WallMaterial)
        {
            CubeInstances->SetMaterial(0, WallMaterial);
        }
    }
    
    // Clear existing instances
    PlaneInstances->ClearInstances();
    CubeInstances->ClearInstances();
    
    // Calculate scaling for meshes based on cell size and percentage
    // Default UE cube is 100 units, scale by CubeSizePercentage
    float ActualCubeSize = CellSize * CubeSizePercentage;
    float MeshScale = ActualCubeSize / 100.0f;  // Scale to match desired size
    
    UE_LOG(LogTemp, Warning, TEXT("=== CUBE SCALING DEBUG ==="));
    UE_LOG(LogTemp, Warning, TEXT("CellSize: %.1f"), CellSize);
    UE_LOG(LogTemp, Warning, TEXT("MeshScale: %.2f"), MeshScale);
    UE_LOG(LogTemp, Warning, TEXT("Resulting cube size: %.1f x %.1f x %.1f"), 
        MeshScale * 100.0f, MeshScale * 100.0f, MeshScale * 100.0f);
    
    // Spawn instances based on grid
    for (int32 Y = 0; Y < GridSizeY; ++Y)
    {
        for (int32 X = 0; X < GridSizeX; ++X)
        {
            FGridCell Cell = GetGridCell(X, Y);
            
            if (Cell.CellType == EGridCellType::Floor)
            {
                // Spawn floor plane - centered in cell with uniform scaling
                FVector FloorPos = GridToWorldPosition(X, Y, true);
                FTransform FloorTransform;
                FloorTransform.SetLocation(FloorPos);
                FloorTransform.SetRotation(FQuat::Identity);
                FloorTransform.SetScale3D(FVector(MeshScale, MeshScale, MeshScale)); // Uniform scale
                PlaneInstances->AddInstance(FloorTransform);
            }
            else if (Cell.CellType == EGridCellType::Wall)
            {
                // Spawn wall cube - centered in cell, scaled to fit exactly
                FVector WallPos = GridToWorldPosition(X, Y, false);
                FTransform WallTransform;
                WallTransform.SetLocation(WallPos);
                WallTransform.SetRotation(FQuat::Identity);
                WallTransform.SetScale3D(FVector(MeshScale, MeshScale, MeshScale)); // Uniform scale
                CubeInstances->AddInstance(WallTransform);
                
                // Debug: Log exact transform for 2x2 grid
                if (GridSizeX <= 2 && GridSizeY <= 2)
                {
                    UE_LOG(LogTemp, Warning, TEXT("Cube at grid (%d,%d):"), X, Y);
                    UE_LOG(LogTemp, Warning, TEXT("  Position: (%.1f, %.1f, %.1f)"), 
                        WallPos.X, WallPos.Y, WallPos.Z);
                    UE_LOG(LogTemp, Warning, TEXT("  Scale: (%.2f, %.2f, %.2f)"), 
                        MeshScale, MeshScale, MeshScale);
                    UE_LOG(LogTemp, Warning, TEXT("  Expected bounds: Min(%.1f, %.1f, %.1f) Max(%.1f, %.1f, %.1f)"),
                        WallPos.X - (MeshScale * 50.0f), WallPos.Y - (MeshScale * 50.0f), WallPos.Z - (MeshScale * 50.0f),
                        WallPos.X + (MeshScale * 50.0f), WallPos.Y + (MeshScale * 50.0f), WallPos.Z + (MeshScale * 50.0f));
                }
            }
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Generated grid with %d floor instances and %d wall instances"), 
        PlaneInstances->GetInstanceCount(), CubeInstances->GetInstanceCount());
        
    // Debug output for positioning verification
    UE_LOG(LogTemp, Warning, TEXT("Grid Configuration:"));
    UE_LOG(LogTemp, Warning, TEXT("  GridSize: %dx%d"), GridSizeX, GridSizeY);
    UE_LOG(LogTemp, Warning, TEXT("  CellSize: %.1f units"), CellSize);
    UE_LOG(LogTemp, Warning, TEXT("  MeshScale: %.2f (CellSize / 100 for exact match)"), MeshScale);
    UE_LOG(LogTemp, Warning, TEXT("  Actual cube size: %.1f units (matches cell exactly)"), MeshScale * 100.0f);
    UE_LOG(LogTemp, Warning, TEXT("  Cell (0,0) center: %.1f, %.1f"), 
        GetActorLocation().X + (CellSize * 0.5f), GetActorLocation().Y + (CellSize * 0.5f));
    UE_LOG(LogTemp, Warning, TEXT("  Cell (1,1) center: %.1f, %.1f"), 
        GetActorLocation().X + CellSize + (CellSize * 0.5f), GetActorLocation().Y + CellSize + (CellSize * 0.5f));
}

void AGridDungeonVisualizer::ClearDungeon()
{
    if (PlaneInstances)
    {
        PlaneInstances->ClearInstances();
    }
    
    if (CubeInstances)
    {
        CubeInstances->ClearInstances();
    }
    
    InitializeGrid();
}

void AGridDungeonVisualizer::SetGridCell(int32 X, int32 Y, EGridCellType Type)
{
    if (IsValidGridPosition(X, Y))
    {
        int32 Index = GridIndexFromXY(X, Y);
        Grid[Index].CellType = Type;
    }
}

FGridCell AGridDungeonVisualizer::GetGridCell(int32 X, int32 Y) const
{
    if (IsValidGridPosition(X, Y))
    {
        int32 Index = GridIndexFromXY(X, Y);
        return Grid[Index];
    }
    
    // Return empty cell for invalid positions
    FGridCell EmptyCell;
    EmptyCell.CellType = EGridCellType::Empty;
    return EmptyCell;
}

bool AGridDungeonVisualizer::IsValidGridPosition(int32 X, int32 Y) const
{
    return X >= 0 && X < GridSizeX && Y >= 0 && Y < GridSizeY;
}

FVector AGridDungeonVisualizer::GridToWorldPosition(int32 X, int32 Y, bool bIsFloor) const
{
    FVector BasePos = GetActorLocation();
    
    // Center the mesh in the grid cell
    float WorldX = BasePos.X + (X * CellSize) + (CellSize * 0.5f);
    float WorldY = BasePos.Y + (Y * CellSize) + (CellSize * 0.5f);
    float WorldZ = BasePos.Z;
    
    if (!bIsFloor)
    {
        // Position cube so its bottom sits exactly on the grid floor
        // The cube center needs to be raised by half of the actual cube size
        float ActualCubeSize = CellSize * CubeSizePercentage;
        WorldZ += ActualCubeSize * 0.5f;
    }
    
    return FVector(WorldX, WorldY, WorldZ);
}

void AGridDungeonVisualizer::DrawDebugGrid()
{
    if (!GetWorld())
    {
        return;
    }
    
    FVector BasePos = GetActorLocation();
    
    // Draw grid lines at cell boundaries
    for (int32 X = 0; X <= GridSizeX; ++X)
    {
        FVector Start = FVector(BasePos.X + X * CellSize, BasePos.Y, BasePos.Z);
        FVector End = FVector(BasePos.X + X * CellSize, BasePos.Y + GridSizeY * CellSize, BasePos.Z);
        DrawDebugLine(GetWorld(), Start, End, DebugGridColor.ToFColor(true), true, -1.0f, 0, DebugLineThickness);
        
        // Log grid line positions for 2x2 grid
        if (GridSizeX <= 2 && GridSizeY <= 2)
        {
            UE_LOG(LogTemp, Warning, TEXT("Vertical grid line %d at X=%.1f"), X, BasePos.X + X * CellSize);
        }
    }
    
    for (int32 Y = 0; Y <= GridSizeY; ++Y)
    {
        FVector Start = FVector(BasePos.X, BasePos.Y + Y * CellSize, BasePos.Z);
        FVector End = FVector(BasePos.X + GridSizeX * CellSize, BasePos.Y + Y * CellSize, BasePos.Z);
        DrawDebugLine(GetWorld(), Start, End, DebugGridColor.ToFColor(true), true, -1.0f, 0, DebugLineThickness);
        
        // Log grid line positions for 2x2 grid
        if (GridSizeX <= 2 && GridSizeY <= 2)
        {
            UE_LOG(LogTemp, Warning, TEXT("Horizontal grid line %d at Y=%.1f"), Y, BasePos.Y + Y * CellSize);
        }
    }
    
    // For 2x2 grid, also draw cube boundaries as reference
    if (GridSizeX <= 2 && GridSizeY <= 2)
    {
        UE_LOG(LogTemp, Warning, TEXT("=== DEBUG BOX POSITIONS ==="));
        for (int32 Y = 0; Y < GridSizeY; ++Y)
        {
            for (int32 X = 0; X < GridSizeX; ++X)
            {
                FVector CubeCenter = GridToWorldPosition(X, Y, false);
                float ActualCubeSize = CellSize * CubeSizePercentage;
                float MeshScale = ActualCubeSize / 100.0f;  // Match cube scale exactly
                float HalfSize = ActualCubeSize * 0.5f; // Half of actual cube size
                
                // Draw a box outline showing exactly where the cube should be
                DrawDebugBox(GetWorld(), CubeCenter, FVector(HalfSize, HalfSize, HalfSize), 
                    FColor::Yellow, true, -1.0f, 0, 3.0f);
                    
                UE_LOG(LogTemp, Warning, TEXT("Debug box at (%d,%d): Center(%.1f, %.1f, %.1f), Size=%.1fx%.1fx%.1f"), 
                    X, Y, CubeCenter.X, CubeCenter.Y, CubeCenter.Z, ActualCubeSize, ActualCubeSize, ActualCubeSize);
            }
        }
    }
}

void AGridDungeonVisualizer::GenerateInEditor()
{
    GenerateAndVisualizeDungeon(FMath::Rand());
}

void AGridDungeonVisualizer::TestGridAlignment()
{
    if (!GetWorld())
    {
        UE_LOG(LogTemp, Error, TEXT("No world available for grid alignment test"));
        return;
    }
    
    // Clear any existing debug lines
    FlushPersistentDebugLines(GetWorld());
    
    // Draw debug grid
    DrawDebugGrid();
    
    // Test a few specific positions to verify alignment
    UE_LOG(LogTemp, Warning, TEXT("=== GRID ALIGNMENT TEST ==="));
    
    for (int32 TestX = 0; TestX < FMath::Min(3, GridSizeX); ++TestX)
    {
        for (int32 TestY = 0; TestY < FMath::Min(3, GridSizeY); ++TestY)
        {
            // Get the center position where a cube would be placed
            FVector CubeCenter = GridToWorldPosition(TestX, TestY, false);
            
            // Calculate expected grid boundaries for this cell
            FVector BasePos = GetActorLocation();
            float GridLeftEdge = BasePos.X + (TestX * CellSize);
            float GridRightEdge = BasePos.X + ((TestX + 1) * CellSize);
            float GridTopEdge = BasePos.Y + (TestY * CellSize);
            float GridBottomEdge = BasePos.Y + ((TestY + 1) * CellSize);
            float GridCenterX = GridLeftEdge + (CellSize * 0.5f);
            float GridCenterY = GridTopEdge + (CellSize * 0.5f);
            
            UE_LOG(LogTemp, Warning, TEXT("Cell (%d,%d):"), TestX, TestY);
            UE_LOG(LogTemp, Warning, TEXT("  Grid boundaries: X[%.1f-%.1f], Y[%.1f-%.1f]"), 
                GridLeftEdge, GridRightEdge, GridTopEdge, GridBottomEdge);
            UE_LOG(LogTemp, Warning, TEXT("  Grid center: (%.1f, %.1f)"), GridCenterX, GridCenterY);
            UE_LOG(LogTemp, Warning, TEXT("  Cube center: (%.1f, %.1f)"), CubeCenter.X, CubeCenter.Y);
            UE_LOG(LogTemp, Warning, TEXT("  Match: %s"), 
                (FMath::IsNearlyEqual(CubeCenter.X, GridCenterX, 0.1f) && 
                 FMath::IsNearlyEqual(CubeCenter.Y, GridCenterY, 0.1f)) ? TEXT("YES") : TEXT("NO"));
            
            // Draw a debug sphere at the calculated cube center for visual verification
            DrawDebugSphere(GetWorld(), CubeCenter, 25.0f, 8, FColor::Red, true, -1.0f, 0, 3.0f);
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Grid alignment test complete. Check debug spheres against grid lines."));
}

void AGridDungeonVisualizer::TestAlternativeAlignment()
{
    if (!GetWorld())
    {
        UE_LOG(LogTemp, Error, TEXT("No world available for alternative alignment test"));
        return;
    }
    
    // Clear any existing debug lines
    FlushPersistentDebugLines(GetWorld());
    
    UE_LOG(LogTemp, Warning, TEXT("=== ALTERNATIVE ALIGNMENT TEST ==="));
    UE_LOG(LogTemp, Warning, TEXT("Choose your preferred approach:"));
    
    // APPROACH 1: Current - Cubes centered in cells, debug shows boundaries
    UE_LOG(LogTemp, Warning, TEXT("APPROACH 1: Cubes centered, grid shows boundaries"));
    DrawDebugGrid();
    
    for (int32 X = 0; X < 3 && X < GridSizeX; ++X)
    {
        for (int32 Y = 0; Y < 3 && Y < GridSizeY; ++Y)
        {
            FVector CubeCenter = GridToWorldPosition(X, Y, false);
            DrawDebugSphere(GetWorld(), CubeCenter, 15.0f, 8, FColor::Blue, true, -1.0f, 0, 2.0f);
        }
    }
    
    // APPROACH 2: Alternative - Cubes on grid intersections
    UE_LOG(LogTemp, Warning, TEXT("APPROACH 2: Cubes on grid intersections"));
    FVector BasePos = GetActorLocation();
    
    for (int32 X = 0; X < 3 && X <= GridSizeX; ++X)
    {
        for (int32 Y = 0; Y < 3 && Y <= GridSizeY; ++Y)
        {
            // Position cubes directly on grid line intersections
            FVector IntersectionPos = FVector(
                BasePos.X + X * CellSize,
                BasePos.Y + Y * CellSize,
                BasePos.Z + CellSize * 0.5f
            );
            DrawDebugSphere(GetWorld(), IntersectionPos, 15.0f, 8, FColor::Red, true, -1.0f, 0, 2.0f);
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Blue spheres = CURRENT (cubes centered in cells)"));
    UE_LOG(LogTemp, Warning, TEXT("Red spheres = ALTERNATIVE (cubes on grid intersections)"));
    UE_LOG(LogTemp, Warning, TEXT("Which looks better to you?"));
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
                
                // Calculate the exact same scale as the debug box
                float DesiredCubeSize = CellSize * CubeSizePercentage; // Use the percentage setting
                float ActualMeshSize = 100.0f; // Default UE cube is 100x100x100
                float RequiredScale = DesiredCubeSize / ActualMeshSize;
                
                // Create transform
                FTransform WallTransform;
                WallTransform.SetLocation(CubeCenter);
                WallTransform.SetRotation(FQuat::Identity);
                WallTransform.SetScale3D(FVector(RequiredScale, RequiredScale, RequiredScale));
                
                // Add the instance
                CubeInstances->AddInstance(WallTransform);
                
                // Log details
                UE_LOG(LogTemp, Warning, TEXT("Cube (%d,%d): Pos(%.1f,%.1f,%.1f) Scale:%.2f Size:%.1f"), 
                    X, Y, CubeCenter.X, CubeCenter.Y, CubeCenter.Z, RequiredScale, RequiredScale * ActualMeshSize);
                
                // Also draw the debug box for comparison
                float HalfSize = DesiredCubeSize * 0.5f;
                DrawDebugBox(GetWorld(), CubeCenter, FVector(HalfSize, HalfSize, HalfSize), 
                    FColor::Yellow, true, -1.0f, 0, 3.0f);
            }
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Spawned %d cubes to match debug boxes"), CubeInstances->GetInstanceCount());
}

int32 AGridDungeonVisualizer::GridIndexFromXY(int32 X, int32 Y) const
{
    return Y * GridSizeX + X;
}