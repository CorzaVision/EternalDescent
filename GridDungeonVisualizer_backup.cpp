// GridDungeonVisualizer.cpp - Grid-based dungeon visualization with HISM
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
    
    // Basic collision settings
    PlaneInstances->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    PlaneInstances->SetCollisionResponseToAllChannels(ECR_Block);
    
    CubeInstances->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    CubeInstances->SetCollisionResponseToAllChannels(ECR_Block);
    
    // HISM-specific optimizations
    PlaneInstances->SetCastShadow(bCastShadows);
    CubeInstances->SetCastShadow(bCastShadows);
    
    // Enable culling for better performance
    PlaneInstances->SetCullDistances(0, 50000.0f); // Cull at 500m
    CubeInstances->SetCullDistances(0, 50000.0f);
    
    // HISM Custom data for room types
    PlaneInstances->NumCustomDataFloats = 1; // For room type marking
    CubeInstances->NumCustomDataFloats = 0;
    
    // HISM-specific settings for optimal performance
    PlaneInstances->bUseAsOccluder = false; // Floors don't occlude
    CubeInstances->bUseAsOccluder = true;    // Walls can occlude
    
    // Set up LOD distances for HISM (automatic LOD generation)
    PlaneInstances->bAutoRebuildTreeOnInstanceChanges = false; // We'll rebuild manually after batch adds
    CubeInstances->bAutoRebuildTreeOnInstanceChanges = false;
    
    // Enable distance field shadows for better performance
    PlaneInstances->bAffectDistanceFieldLighting = true;
    CubeInstances->bAffectDistanceFieldLighting = true;
    
    // UE 5.5 Nanite support (configured via mesh asset settings)
    // Nanite is enabled per-mesh in the Static Mesh Editor
    
    // UE 5.5 Virtual Shadow Maps support
    PlaneInstances->bCastContactShadow = true;
    CubeInstances->bCastContactShadow = true;
    
    // UE 5.5 GPU Scene support
    PlaneInstances->bVisibleInRayTracing = true;
    CubeInstances->bVisibleInRayTracing = true;
    
    // UE 5.5 World Partition streaming support
    // Density scaling is handled automatically by World Partition
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
    UE_LOG(LogTemp, Warning, TEXT("=== GenerateAndVisualizeDungeon Started ==="));
    
    // Always reinitialize to ensure grid matches current size settings
    InitializeGrid();
    ClearDungeon();
    
    // Use seed for reproducible generation
    if (Seed > 0)
    {
        FMath::RandInit(Seed);
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Calling GenerateSimpleLayout..."));
    GenerateSimpleLayout();
    
    UE_LOG(LogTemp, Warning, TEXT("Calling SpawnGridVisualization..."));
    SpawnGridVisualization();
    
    if (bShowDebugGrid)
    {
        DrawDebugGrid();
    }
    
    UE_LOG(LogTemp, Warning, TEXT("=== GenerateAndVisualizeDungeon Complete ==="));
}

// Helper function for room placement during final push
bool TryPlaceRoom(int32 RoomX, int32 RoomY, int32 RoomSize, int32 ParentIndex, 
                  const FString& RoomType, TArray<FRoomData>& Rooms, int32& RoomCount, 
                  int32 GridSizeX, int32 GridSizeY)
{
    // Check bounds
    if (RoomX < 1 || RoomY < 1 || RoomX + RoomSize > GridSizeX - 1 || RoomY + RoomSize > GridSizeY - 1)
    {
        return false;
    }
    
    // Check spacing from existing rooms
    for (const auto& ExistingRoom : Rooms)
    {
        int32 NewRight = RoomX + RoomSize;
        int32 NewBottom = RoomY + RoomSize;
        int32 ExistingRight = ExistingRoom.Position.X + ExistingRoom.Size;
        int32 ExistingBottom = ExistingRoom.Position.Y + ExistingRoom.Size;
        
        if (RoomX < ExistingRight + 1 &&
            NewRight + 1 > ExistingRoom.Position.X &&
            RoomY < ExistingBottom + 1 &&
            NewBottom + 1 > ExistingRoom.Position.Y)
        {
            return false;
        }
    }
    
    // Place the room
    FRoomData NewRoom;
    NewRoom.Position = FIntPoint(RoomX, RoomY);
    NewRoom.Size = RoomSize;
    NewRoom.ConnectedTo.Add(ParentIndex);
    
    Rooms[ParentIndex].ConnectedTo.Add(RoomCount);
    Rooms.Add(NewRoom);
    RoomCount++;
    
    UE_LOG(LogTemp, Warning, TEXT("FINAL PUSH Room %d: %dx%d at (%d,%d) connected to Room %d"), 
        RoomCount - 1, RoomSize, RoomSize, RoomX, RoomY, ParentIndex);
    
    return true;
}

void AGridDungeonVisualizer::GenerateSimpleLayout()
{
    // First, fill entire grid with walls (cubes)
    for (int32 Y = 0; Y < GridSizeY; ++Y)
    {
        for (int32 X = 0; X < GridSizeX; ++X)
        {
            SetGridCell(X, Y, EGridCellType::Wall);
        }
    }
    
    // Generate room-as-path layout: [S] [C] [R] [C] [R] ... [E]
    // Where S=Start, R=Room, C=Cube(gap), E=End
    // For 30x30 grid: TARGET = 25 ROOMS!
    int32 MinGridSize = 15; // Allow space for multiple rooms with gaps
    
    UE_LOG(LogTemp, Warning, TEXT("🎯 25-ROOM CHALLENGE: Grid size %dx%d (minimum %d required)"), GridSizeX, GridSizeY, MinGridSize);
    
    if (GridSizeX == 30 && GridSizeY == 30)
    {
        UE_LOG(LogTemp, Warning, TEXT("🚀 MAIN DUNGEON SIZE DETECTED: Targeting exactly 25 rooms!"));
    }
    
    if (GridSizeX >= MinGridSize && GridSizeY >= MinGridSize)
    {
        // Track rooms for path generation
        TArray<FRoomData> Rooms;
        int32 RoomCount = 0;
        
        // Start room [S] - always 2x2 at position (1,1)
        for (int32 Y = 1; Y <= 2; ++Y)
        {
            for (int32 X = 1; X <= 2; ++X)
            {
                SetGridCell(X, Y, EGridCellType::Floor);
            }
        }
        FRoomData StartRoom;
        StartRoom.Position = FIntPoint(1, 1);
        StartRoom.Size = 2;
        Rooms.Add(StartRoom);
        RoomCount++;
        UE_LOG(LogTemp, Warning, TEXT("[S] START ROOM #%d (2x2) at (1,1) to (2,2)"), RoomCount);
        
        // Build main path and branches
        TArray<int32> PathQueue; // Rooms to branch from
        PathQueue.Add(0); // Start with the start room
        
        // Use a more practical room placement approach for 25-room target
        int32 MaxRooms;
        if (GridSizeX == 30 && GridSizeY == 30)
        {
            MaxRooms = 25; // YOUR CHALLENGE: Exactly 25 rooms!
        }
        else if (GridSizeX >= 25)
        {
            MaxRooms = FMath::Min(20, (GridSizeX * GridSizeY) / 40);
        }
        else if (GridSizeX >= 20)
        {
            MaxRooms = FMath::Min(12, (GridSizeX * GridSizeY) / 50);
        }
        else
        {
            MaxRooms = FMath::Min(8, (GridSizeX * GridSizeY) / 60);
        }
        
        UE_LOG(LogTemp, Warning, TEXT("🎯 CHALLENGE: Generate %d rooms in %dx%d grid!"), MaxRooms, GridSizeX, GridSizeY);
        
        // NEW STRATEGY: Grid-based placement for guaranteed success
        // Instead of strict adjacency, use a more flexible approach
        
        // Create potential placement zones across the grid
        TArray<FIntPoint> PlacementZones;
        int32 ZoneSize = 6; // Each zone can hold a room + gap
        
        for (int32 ZoneY = 1; ZoneY < GridSizeY - ZoneSize; ZoneY += ZoneSize)
        {
            for (int32 ZoneX = 1; ZoneX < GridSizeX - ZoneSize; ZoneX += ZoneSize)
            {
                PlacementZones.Add(FIntPoint(ZoneX, ZoneY));
            }
        }
        
        // Shuffle zones for organic placement
        for (int32 i = PlacementZones.Num() - 1; i > 0; --i)
        {
            int32 j = FMath::RandRange(0, i);
            PlacementZones.Swap(i, j);
        }
        
        UE_LOG(LogTemp, Warning, TEXT("Available placement zones: %d"), PlacementZones.Num());
        
        // Place rooms in available zones
        int32 ZoneIndex = 0;
        while (RoomCount < MaxRooms && ZoneIndex < PlacementZones.Num())
        {
            PlacementAttempts++;
            // Pick a room to extend from
            int32 ParentIndex = PathQueue[0];
            PathQueue.RemoveAt(0);
            
            const FRoomData& ParentRoom = Rooms[ParentIndex];
            
            // More aggressive branching for 25 rooms - need to fill the space
            int32 BranchCount;
            if (ParentIndex == 0) // Start room - create main arteries
            {
                BranchCount = (MaxRooms >= 20) ? FMath::RandRange(2, 4) : FMath::RandRange(1, 2);
            }
            else if (RoomCount < MaxRooms * 0.7f) // First 70% - keep branching aggressively
            {
                BranchCount = FMath::RandRange(1, 3);
            }
            else // Final 30% - more selective
            {
                BranchCount = FMath::RandRange(0, 2);
            }
            
            for (int32 Branch = 0; Branch < BranchCount && RoomCount < MaxRooms; ++Branch)
            {
                // Determine room size
                int32 RoomSize;
                FString RoomType;
                
                if (RoomCount == MaxRooms - 1) // Last room is the end room
                {
                    RoomSize = FMath::RandRange(3, 4); // End room is medium to large
                    RoomType = TEXT("END");
                }
                else if (FMath::RandRange(0, 100) < 10) // 10% chance for boss room
                {
                    RoomSize = 5;
                    RoomType = TEXT("BOSS");
                }
                else if (FMath::RandRange(0, 100) < 20) // 20% chance for elite room
                {
                    RoomSize = 4;
                    RoomType = TEXT("ELITE");
                }
                else if (FMath::RandRange(0, 100) < 40) // 40% chance for medium room
                {
                    RoomSize = 3;
                    RoomType = TEXT("MEDIUM");
                }
                else // 30% chance for small room
                {
                    RoomSize = 2;
                    RoomType = TEXT("SMALL");
                }
            
                // Find valid position adjacent to parent room with EXACTLY 1 cell gap
                bool bPlaced = false;
                
                // Try different directions from parent room
                TArray<FIntPoint> Directions = {
                    FIntPoint(1, 0),   // Right
                    FIntPoint(-1, 0),  // Left
                    FIntPoint(0, 1),   // Down
                    FIntPoint(0, -1)   // Up
                };
                
                // Randomize direction order for organic feel
                for (int32 i = Directions.Num() - 1; i > 0; --i)
                {
                    int32 j = FMath::RandRange(0, i);
                    Directions.Swap(i, j);
                }
                
                for (const FIntPoint& Dir : Directions)
                {
                    // Calculate position with EXACTLY 1 cell gap from parent
                    // Parent edge + 1 cell gap + new room position
                    int32 RoomX, RoomY;
                    
                    if (Dir.X != 0) // Horizontal placement
                    {
                        RoomX = (Dir.X > 0) ? 
                            (ParentRoom.Position.X + ParentRoom.Size + 1) : // Right: parent right edge + 1 gap
                            (ParentRoom.Position.X - RoomSize - 1);         // Left: parent left edge - size - 1 gap
                        
                        // For 25 rooms, be more flexible with positioning
                        int32 YOffset;
                        if (MaxRooms >= 20)
                        {
                            // Larger variation for more room placement opportunities
                            YOffset = FMath::RandRange(-2, ParentRoom.Size + 1);
                        }
                        else
                        {
                            YOffset = FMath::RandRange(-1, ParentRoom.Size - 1);
                        }
                        RoomY = FMath::Clamp(ParentRoom.Position.Y + YOffset, 1, GridSizeY - RoomSize - 1);
                    }
                    else // Vertical placement
                    {
                        RoomY = (Dir.Y > 0) ?
                            (ParentRoom.Position.Y + ParentRoom.Size + 1) : // Down: parent bottom edge + 1 gap
                            (ParentRoom.Position.Y - RoomSize - 1);         // Up: parent top edge - size - 1 gap
                        
                        // For 25 rooms, be more flexible with positioning
                        int32 XOffset;
                        if (MaxRooms >= 20)
                        {
                            // Larger variation for more room placement opportunities
                            XOffset = FMath::RandRange(-2, ParentRoom.Size + 1);
                        }
                        else
                        {
                            XOffset = FMath::RandRange(-1, ParentRoom.Size - 1);
                        }
                        RoomX = FMath::Clamp(ParentRoom.Position.X + XOffset, 1, GridSizeX - RoomSize - 1);
                    }
                
                    // Check if position is valid
                    if (RoomX < 1 || RoomY < 1 || 
                        RoomX + RoomSize > GridSizeX - 1 || 
                        RoomY + RoomSize > GridSizeY - 1)
                    {
                        continue; // Out of bounds
                    }
                    
                    // Check if position maintains EXACTLY 1 cell spacing from all existing rooms
                    bool bValidPosition = true;
                    for (int32 i = 0; i < Rooms.Num(); ++i)
                    {
                        const FRoomData& ExistingRoom = Rooms[i];
                        
                        // Skip parent room - we know it's exactly 1 cell away by construction
                        if (i == ParentIndex) continue;
                        
                        int32 NewRoomRight = RoomX + RoomSize;
                        int32 NewRoomBottom = RoomY + RoomSize;
                        int32 ExistingRoomRight = ExistingRoom.Position.X + ExistingRoom.Size;
                        int32 ExistingRoomBottom = ExistingRoom.Position.Y + ExistingRoom.Size;
                        
                        // Check if rooms maintain at least 1 cell gap
                        if (RoomX < ExistingRoomRight + 1 &&
                            NewRoomRight + 1 > ExistingRoom.Position.X &&
                            RoomY < ExistingRoomBottom + 1 &&
                            NewRoomBottom + 1 > ExistingRoom.Position.Y)
                        {
                            bValidPosition = false;
                            break;
                        }
                    }
                
                    // Check if the space is clear
                    if (bValidPosition)
                    {
                        bool bSpaceClear = true;
                        for (int32 CheckY = RoomY; CheckY < RoomY + RoomSize; ++CheckY)
                        {
                            for (int32 CheckX = RoomX; CheckX < RoomX + RoomSize; ++CheckX)
                            {
                                if (!IsValidGridPosition(CheckX, CheckY) || 
                                    GetGridCell(CheckX, CheckY).CellType == EGridCellType::Floor)
                                {
                                    bSpaceClear = false;
                                    break;
                                }
                            }
                            if (!bSpaceClear) break;
                        }
                        
                        if (bSpaceClear)
                        {
                            // Place the room
                            for (int32 Y = RoomY; Y < RoomY + RoomSize; ++Y)
                            {
                                for (int32 X = RoomX; X < RoomX + RoomSize; ++X)
                                {
                                    SetGridCell(X, Y, EGridCellType::Floor);
                                }
                            }
                            
                            FRoomData NewRoom;
                            NewRoom.Position = FIntPoint(RoomX, RoomY);
                            NewRoom.Size = RoomSize;
                            Rooms.Add(NewRoom);
                            RoomCount++;
                            
                            // Update connections
                            Rooms[ParentIndex].ConnectedTo.Add(RoomCount - 1);
                            NewRoom.ConnectedTo.Add(ParentIndex);
                            
                            // Add to queue for potential branching - more aggressive for 25 rooms
                            bool bShouldBranch = false;
                            if (RoomType == TEXT("END") || RoomType == TEXT("BOSS"))
                            {
                                bShouldBranch = false; // Never branch from end/boss rooms
                            }
                            else if (MaxRooms >= 20) // For 25-room target, be very aggressive
                            {
                                bShouldBranch = (FMath::RandRange(0, 100) < 80); // 80% chance
                            }
                            else if (MaxRooms >= 10)
                            {
                                bShouldBranch = (FMath::RandRange(0, 100) < 60); // 60% chance
                            }
                            else
                            {
                                bShouldBranch = (FMath::RandRange(0, 100) < 40); // 40% chance
                            }
                            
                            if (bShouldBranch)
                            {
                                PathQueue.Add(RoomCount - 1);
                            }
                            
                            // Log room placement with path notation
                            FString PathNotation = (RoomType == TEXT("END")) ? TEXT("[E]") : TEXT("[R]");
                            if (RoomCount == 1) PathNotation = TEXT("[S]");
                            
                            UE_LOG(LogTemp, Warning, TEXT("%s %s ROOM #%d (%dx%d) at (%d,%d) to (%d,%d) - Connected to Room #%d"), 
                                *PathNotation, *RoomType, RoomCount, RoomSize, RoomSize, 
                                RoomX, RoomY, RoomX + RoomSize - 1, RoomY + RoomSize - 1, ParentIndex + 1);
                            
                            bPlaced = true;
                            break;
                        }
                    }
                }
                
                if (bPlaced) break; // Successfully placed room from this parent
            }
        }
        
        // Final push: If we're close to target but not there, try harder
        if (RoomCount < MaxRooms && MaxRooms >= 20)
        {
            UE_LOG(LogTemp, Warning, TEXT("FINAL PUSH: Attempting to reach %d rooms (currently %d)"), MaxRooms, RoomCount);
            
            // Re-add all existing rooms to queue for one more aggressive attempt
            PathQueue.Empty();
            for (int32 i = 0; i < Rooms.Num(); ++i)
            {
                // Don't add rooms that are already heavily branched
                if (Rooms[i].ConnectedTo.Num() < 3)
                {
                    PathQueue.Add(i);
                }
            }
            
            // Try smaller rooms for final placements
            int32 FinalAttempts = (MaxRooms - RoomCount) * 50;
            while (PathQueue.Num() > 0 && RoomCount < MaxRooms && FinalAttempts > 0)
            {
                FinalAttempts--;
                int32 ParentIndex = PathQueue[FMath::RandRange(0, PathQueue.Num() - 1)];
                PathQueue.RemoveAt(PathQueue.Find(ParentIndex));
                
                const FRoomData& ParentRoom = Rooms[ParentIndex];
                
                // Force smaller rooms for final placements
                int32 RoomSize = 2; // Only 2x2 rooms for final push
                FString RoomType = TEXT("SMALL");
                
                // Try all 4 directions with maximum flexibility
                TArray<FIntPoint> FinalDirections = {
                    FIntPoint(1, 0), FIntPoint(-1, 0), FIntPoint(0, 1), FIntPoint(0, -1)
                };
                
                for (const FIntPoint& Dir : FinalDirections)
                {
                    if (RoomCount >= MaxRooms) break;
                    
                    int32 RoomX, RoomY;
                    if (Dir.X != 0)
                    {
                        RoomX = (Dir.X > 0) ? 
                            (ParentRoom.Position.X + ParentRoom.Size + 1) : 
                            (ParentRoom.Position.X - RoomSize - 1);
                        
                        // Try multiple Y offsets
                        for (int32 YTry = -3; YTry <= ParentRoom.Size + 2; ++YTry)
                        {
                            RoomY = FMath::Clamp(ParentRoom.Position.Y + YTry, 1, GridSizeY - RoomSize - 1);
                            
                            if (TryPlaceRoom(RoomX, RoomY, RoomSize, ParentIndex, RoomType, Rooms, RoomCount, GridSizeX, GridSizeY))
                            {
                                break;
                            }
                        }
                    }
                    else
                    {
                        RoomY = (Dir.Y > 0) ? 
                            (ParentRoom.Position.Y + ParentRoom.Size + 1) : 
                            (ParentRoom.Position.Y - RoomSize - 1);
                        
                        // Try multiple X offsets
                        for (int32 XTry = -3; XTry <= ParentRoom.Size + 2; ++XTry)
                        {
                            RoomX = FMath::Clamp(ParentRoom.Position.X + XTry, 1, GridSizeX - RoomSize - 1);
                            
                            if (TryPlaceRoom(RoomX, RoomY, RoomSize, ParentIndex, RoomType, Rooms, RoomCount, GridSizeX, GridSizeY))
                            {
                                break;
                            }
                        }
                    }
                }
            }
        }
        
        // NO CORRIDORS - rooms are the path themselves!
        // The 1-cell gaps between rooms act as the connections
        
        UE_LOG(LogTemp, Warning, TEXT("Generated %dx%d room-as-path dungeon:"), GridSizeX, GridSizeY);
        UE_LOG(LogTemp, Warning, TEXT("  - Pattern: [S] [C] [R] [C] [R] ... [E]"));
        UE_LOG(LogTemp, Warning, TEXT("  - %d rooms total (TARGET: %d)"), RoomCount, MaxRooms);
        if (RoomCount >= MaxRooms)
        {
            UE_LOG(LogTemp, Warning, TEXT("  ✅ TARGET ACHIEVED: %d/%d rooms generated!"), RoomCount, MaxRooms);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("  ⚠️ TARGET MISSED: %d/%d rooms generated"), RoomCount, MaxRooms);
        }
        UE_LOG(LogTemp, Warning, TEXT("  - Variable room sizes (2x2 to 5x5)"));
        UE_LOG(LogTemp, Warning, TEXT("  - EXACTLY 1 cell gap between connected rooms"));
        UE_LOG(LogTemp, Warning, TEXT("  - Organic branching paths"));
        UE_LOG(LogTemp, Warning, TEXT("  - No corridors - rooms ARE the path"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Grid too small for room-path generation! Need at least %dx%d grid (current: %dx%d)."), MinGridSize, MinGridSize, GridSizeX, GridSizeY);
        
        // For small grids, create a simple 2-room layout
        if (GridSizeX >= 6 && GridSizeY >= 6)
        {
            UE_LOG(LogTemp, Warning, TEXT("Creating simple 2-room layout for small grid"));
            
            // Start room at (1,1) - already created above
            // End room at opposite corner
            int32 EndX = GridSizeX - 3;
            int32 EndY = GridSizeY - 3;
            
            if (EndX > 3 && EndY > 3) // Ensure there's space
            {
                for (int32 Y = EndY; Y < EndY + 2; ++Y)
                {
                    for (int32 X = EndX; X < EndX + 2; ++X)
                    {
                        if (IsValidGridPosition(X, Y))
                        {
                            SetGridCell(X, Y, EGridCellType::Floor);
                        }
                    }
                }
                
                UE_LOG(LogTemp, Warning, TEXT("[E] END ROOM created at (%d,%d) to (%d,%d)"), 
                    EndX, EndY, EndX + 1, EndY + 1);
            }
        }
    }
}

void AGridDungeonVisualizer::SpawnGridVisualization()
{
    if (!PlaneInstances || !CubeInstances)
    {
        UE_LOG(LogTemp, Error, TEXT("Instance components not initialized"));
        return;
    }
    
    // Check if meshes are assigned
    if (!PlaneMesh || !CubeMesh)
    {
        UE_LOG(LogTemp, Error, TEXT("MESHES NOT ASSIGNED! PlaneMesh=%s, CubeMesh=%s"), 
            PlaneMesh ? TEXT("Valid") : TEXT("NULL"),
            CubeMesh ? TEXT("Valid") : TEXT("NULL"));
        
        // Try to load default meshes if not assigned
        if (!CubeMesh)
        {
            CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
            if (CubeMesh)
            {
                UE_LOG(LogTemp, Warning, TEXT("Loaded default Cube mesh"));
            }
        }
        
        if (!PlaneMesh)
        {
            PlaneMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Plane.Plane"));
            if (PlaneMesh)
            {
                UE_LOG(LogTemp, Warning, TEXT("Loaded default Plane mesh"));
            }
        }
    }
    
    // Set meshes if available
    if (PlaneMesh)
    {
        PlaneInstances->SetStaticMesh(PlaneMesh);
        if (FloorMaterial)
        {
            PlaneInstances->SetMaterial(0, FloorMaterial);
        }
        UE_LOG(LogTemp, Warning, TEXT("Plane mesh set successfully"));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Still no Plane mesh available!"));
    }
    
    if (CubeMesh)
    {
        CubeInstances->SetStaticMesh(CubeMesh);
        if (WallMaterial)
        {
            CubeInstances->SetMaterial(0, WallMaterial);
        }
        UE_LOG(LogTemp, Warning, TEXT("Cube mesh set successfully"));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Still no Cube mesh available!"));
    }
    
    // Clear existing instances
    PlaneInstances->ClearInstances();
    CubeInstances->ClearInstances();
    
    // UE 5.5: Pre-allocate instance capacity for better performance
    int32 EstimatedFloors = (GridSizeX * GridSizeY) / 4; // Rough estimate
    int32 EstimatedWalls = (GridSizeX * GridSizeY) / 2;
    PlaneInstances->PreAllocateInstancesMemory(EstimatedFloors);
    CubeInstances->PreAllocateInstancesMemory(EstimatedWalls);
    
    // UE 5.5: Set batch size for optimal GPU instancing
    PlaneInstances->InstancingRandomSeed = FMath::Rand();
    CubeInstances->InstancingRandomSeed = FMath::Rand();
    
    // Calculate scaling for meshes to EXACTLY match debug boxes
    // Default UE cube is 100x100x100 units
    // Default UE plane is 100x100 units
    float DesiredCubeSize = CellSize * CubeSizePercentage; // Actual size we want
    float CubeMeshScale = DesiredCubeSize / 100.0f;  // Scale for cube mesh
    float PlaneMeshScale = CellSize / 100.0f;  // Scale plane to fill entire cell
    
    UE_LOG(LogTemp, Warning, TEXT("=== EXACT SIZING DEBUG ==="));
    UE_LOG(LogTemp, Warning, TEXT("CellSize: %.1f units"), CellSize);
    UE_LOG(LogTemp, Warning, TEXT("CubeSizePercentage: %.2f"), CubeSizePercentage);
    UE_LOG(LogTemp, Warning, TEXT("DesiredCubeSize: %.1f units"), DesiredCubeSize);
    UE_LOG(LogTemp, Warning, TEXT("CubeMeshScale: %.2f (for 100-unit cube)"), CubeMeshScale);
    UE_LOG(LogTemp, Warning, TEXT("PlaneMeshScale: %.2f (for 100-unit plane)"), PlaneMeshScale);
    UE_LOG(LogTemp, Warning, TEXT("Final cube size: %.1f x %.1f x %.1f units"), 
        CubeMeshScale * 100.0f, CubeMeshScale * 100.0f, CubeMeshScale * 100.0f);
    UE_LOG(LogTemp, Warning, TEXT("Final plane size: %.1f x %.1f units"), 
        PlaneMeshScale * 100.0f, PlaneMeshScale * 100.0f);
    
    // Spawn instances based on grid
    int32 FloorCount = 0;
    int32 WallCount = 0;
    
    for (int32 Y = 0; Y < GridSizeY; ++Y)
    {
        for (int32 X = 0; X < GridSizeX; ++X)
        {
            FGridCell Cell = GetGridCell(X, Y);
            
            if (Cell.CellType == EGridCellType::Floor)
            {
                // Spawn floor plane - EXACTLY centered in cell
                FVector FloorPos = GridToWorldPosition(X, Y, true);
                FTransform FloorTransform;
                FloorTransform.SetLocation(FloorPos);
                FloorTransform.SetRotation(FQuat::Identity);
                FloorTransform.SetScale3D(FVector(PlaneMeshScale, PlaneMeshScale, 1.0f)); // Scale X,Y to cell size, keep Z thin
                
                // Add instance and potentially override material for start/end rooms
                int32 InstanceIndex = PlaneInstances->AddInstance(FloorTransform);
                FloorCount++;
                
                // Check if this is part of start room (1,1) to (2,2)
                bool bIsStartRoom = (X >= 1 && X <= 2 && Y >= 1 && Y <= 2);
                
                // Check if this is part of end room
                bool bIsEndRoom = (X >= GridSizeX - 3 && X <= GridSizeX - 2 && 
                                  Y >= GridSizeY - 3 && Y <= GridSizeY - 2);
                
                if (bIsStartRoom)
                {
                    // Apply start room material if available
                    if (StartRoomMaterial)
                    {
                        PlaneInstances->SetCustomDataValue(InstanceIndex, 0, 1.0f); // Mark as start
                    }
                    UE_LOG(LogTemp, Warning, TEXT("START ROOM cell at grid (%d,%d)"), X, Y);
                }
                else if (bIsEndRoom)
                {
                    // Apply end room material if available
                    if (EndRoomMaterial)
                    {
                        PlaneInstances->SetCustomDataValue(InstanceIndex, 0, 2.0f); // Mark as end
                    }
                    UE_LOG(LogTemp, Warning, TEXT("END ROOM cell at grid (%d,%d)"), X, Y);
                }
            }
            else if (Cell.CellType == EGridCellType::Wall)
            {
                // Spawn wall cube - EXACTLY matching debug box position and size
                FVector CubeCenter = GridToWorldPosition(X, Y, false);
                
                // CRITICAL: Match debug box exactly
                // Debug box uses HalfSize = (CellSize * CubeSizePercentage) * 0.5f
                // Debug box center is at GridToWorldPosition(X, Y, false)
                // Debug box extent is FVector(HalfSize, HalfSize, HalfSize)
                
                float WallCubeSize = CellSize * CubeSizePercentage;
                float DebugHalfSize = WallCubeSize * 0.5f;
                
                // The mesh scale must make the mesh bounds match the debug box bounds
                // Default UE cube is 100x100x100 units, so scale = DesiredSize / 100
                float ExactMeshScale = WallCubeSize / 100.0f;
                
                FTransform WallTransform;
                WallTransform.SetLocation(CubeCenter); // Same center as debug box
                WallTransform.SetRotation(FQuat::Identity);
                WallTransform.SetScale3D(FVector(ExactMeshScale, ExactMeshScale, ExactMeshScale));
                CubeInstances->AddInstance(WallTransform);
                WallCount++;
                
                // Verify positioning matches debug box
                if (X < 3 && Y < 3) // Log first few for verification
                {
                    UE_LOG(LogTemp, Warning, TEXT("Cube (%d,%d): Center(%.1f,%.1f,%.1f) Scale:%.3f DebugBoxSize:%.1f"), 
                        X, Y, CubeCenter.X, CubeCenter.Y, CubeCenter.Z, ExactMeshScale, WallCubeSize);
                }
                
                // Debug: Log exact transform for 2x2 grid
                if (GridSizeX <= 2 && GridSizeY <= 2)
                {
                    float HalfSize = DesiredCubeSize * 0.5f;
                    UE_LOG(LogTemp, Warning, TEXT("Wall Cube at grid (%d,%d):"), X, Y);
                    UE_LOG(LogTemp, Warning, TEXT("  Center: (%.1f, %.1f, %.1f)"), 
                        CubeCenter.X, CubeCenter.Y, CubeCenter.Z);
                    UE_LOG(LogTemp, Warning, TEXT("  Scale: (%.3f, %.3f, %.3f)"), 
                        ExactMeshScale, ExactMeshScale, ExactMeshScale);
                    UE_LOG(LogTemp, Warning, TEXT("  Size: %.1f x %.1f x %.1f units"), 
                        WallCubeSize, WallCubeSize, WallCubeSize);
                    UE_LOG(LogTemp, Warning, TEXT("  Bounds: Min(%.1f, %.1f, %.1f) Max(%.1f, %.1f, %.1f)"),
                        CubeCenter.X - HalfSize, CubeCenter.Y - HalfSize, CubeCenter.Z - HalfSize,
                        CubeCenter.X + HalfSize, CubeCenter.Y + HalfSize, CubeCenter.Z + HalfSize);
                }
            }
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Added %d floors and %d walls to grid"), FloorCount, WallCount);
    
    // HISM: Build the tree after adding all instances for optimal performance
    PlaneInstances->BuildTreeIfOutdated(true, true);
    CubeInstances->BuildTreeIfOutdated(true, true);
    
    UE_LOG(LogTemp, Warning, TEXT("Generated grid with %d floor instances and %d wall instances"), 
        PlaneInstances->GetInstanceCount(), CubeInstances->GetInstanceCount());
    UE_LOG(LogTemp, Warning, TEXT("HISM trees built for optimal culling and LOD performance"));
        
    // Debug output for positioning verification
    UE_LOG(LogTemp, Warning, TEXT("Grid Configuration:"));
    UE_LOG(LogTemp, Warning, TEXT("  GridSize: %dx%d"), GridSizeX, GridSizeY);
    UE_LOG(LogTemp, Warning, TEXT("  CellSize: %.1f units"), CellSize);
    UE_LOG(LogTemp, Warning, TEXT("  CubeSizePercentage: %.2f"), CubeSizePercentage);
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
        // Ensure array is large enough
        if (Grid.Num() <= Index)
        {
            InitializeGrid();
        }
        if (Index < Grid.Num())
        {
            Grid[Index].CellType = Type;
        }
    }
}

FGridCell AGridDungeonVisualizer::GetGridCell(int32 X, int32 Y) const
{
    if (IsValidGridPosition(X, Y))
    {
        int32 Index = GridIndexFromXY(X, Y);
        // Check array bounds
        if (Index < Grid.Num())
        {
            return Grid[Index];
        }
    }
    
    // Return empty cell for invalid positions or out of bounds
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
    
    // Draw debug boxes for ALL wall cells to verify perfect alignment
    UE_LOG(LogTemp, Warning, TEXT("=== DRAWING DEBUG BOXES FOR WALLS ==="));
    for (int32 Y = 0; Y < GridSizeY; ++Y)
    {
        for (int32 X = 0; X < GridSizeX; ++X)
        {
            FGridCell Cell = GetGridCell(X, Y);
            if (Cell.CellType == EGridCellType::Wall)
            {
                // Calculate EXACT same position and size as the cube mesh
                FVector CubeCenter = GridToWorldPosition(X, Y, false);
                float DesiredCubeSize = CellSize * CubeSizePercentage;
                float HalfSize = DesiredCubeSize * 0.5f;
                
                // Draw a box outline showing exactly where the cube should be
                DrawDebugBox(GetWorld(), CubeCenter, FVector(HalfSize, HalfSize, HalfSize), 
                    FColor::Yellow, true, -1.0f, 0, 3.0f);
                
                // For small grids, log details
                if (GridSizeX <= 3 && GridSizeY <= 3)
                {
                    UE_LOG(LogTemp, Warning, TEXT("Debug box at (%d,%d): Center(%.1f, %.1f, %.1f), Size=%.1f"), 
                        X, Y, CubeCenter.X, CubeCenter.Y, CubeCenter.Z, DesiredCubeSize);
                }
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