// SnakeDungeonGenerator.cpp - High-performance snake-path dungeon generation
#include "SnakeDungeonGenerator.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "HAL/PlatformFilemanager.h"
#include "Misc/DateTime.h"

ASnakeDungeonGenerator::ASnakeDungeonGenerator()
{
    PrimaryActorTick.bCanEverTick = false;
    
    // Initialize generation settings
    GenerationSettings = FSnakeGenerationSettings();
    
    // Performance optimizations
    bUseBatchedSpawning = true;
    MaxInstancesPerBatch = 500;
    bAutoGenerateOnBeginPlay = true;
    bEnableDebugVisualization = false;
    
    // Set cell size to match specification (350 units = 3.5 meters)
    CellSize = 350.0f;
    
    // Initialize room positions
    StartRoomPosition = FIntVector::ZeroValue;
    ExitRoomPosition = FIntVector::ZeroValue;
    CurrentSeed = -1;
    GenerationStartTime = 0.0;
    
    // Reserve space for performance
    GenerationTimes.Reserve(100);
}

void ASnakeDungeonGenerator::BeginPlay()
{
    Super::BeginPlay();
    
    UE_LOG(LogTemp, Warning, TEXT("=== SnakeDungeonGenerator BeginPlay ==="));
    UE_LOG(LogTemp, Warning, TEXT("Grid Size: %dx%d"), GenerationSettings.GridSizeX, GenerationSettings.GridSizeY);
    UE_LOG(LogTemp, Warning, TEXT("Target Rooms: %d"), GenerationSettings.TargetRooms);
    UE_LOG(LogTemp, Warning, TEXT("Cell Size: %.1f units"), CellSize);
    
    if (bAutoGenerateOnBeginPlay)
    {
        GenerateAndVisualizeSnakeDungeon();
    }
}

void ASnakeDungeonGenerator::GenerateAndVisualizeSnakeDungeon(int32 Seed)
{
    UE_LOG(LogTemp, Log, TEXT("Starting complete snake dungeon generation..."));
    
    double TotalStartTime = FPlatformTime::Seconds();
    
    // LOOP 1: Room Placement
    FSnakeGenerationStats Stats = GenerateSnakePath(Seed);
    
    // LOOP 2: Mesh and Cube Spawning
    SpawnSnakeVisualization();
    
    double TotalEndTime = FPlatformTime::Seconds();
    double TotalGenerationTime = (TotalEndTime - TotalStartTime) * 1000.0; // Convert to milliseconds
    
    // Update stats
    LastGenerationStats.GenerationTimeMs = TotalGenerationTime;
    GenerationTimes.Add(TotalGenerationTime);
    
    // Performance validation
    if (TotalGenerationTime > 16.0)
    {
        UE_LOG(LogTemp, Warning, TEXT("⚠️ Generation time %.2fms exceeds 16ms target!"), TotalGenerationTime);
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("✅ Generation completed in %.2fms (within 16ms target)"), TotalGenerationTime);
    }
    
    // Trigger blueprint event
    OnSnakePathGenerated(LastGenerationStats);
    OnSnakeVisualizationComplete();
}

FSnakeGenerationStats ASnakeDungeonGenerator::GenerateSnakePath(int32 Seed)
{
    UE_LOG(LogTemp, Log, TEXT("=== LOOP 1: Room Placement ==="));
    
    GenerationStartTime = FPlatformTime::Seconds();
    
    // Initialize seed
    if (Seed > 0)
    {
        CurrentSeed = Seed;
        FMath::RandInit(Seed);
    }
    else
    {
        CurrentSeed = FMath::Rand();
        FMath::RandInit(CurrentSeed);
    }
    
    // Clear previous data
    InitializeSnakeGeneration();
    
    // Step 1: Place START room at one edge
    StartRoomPosition = FIntVector(0, 0, 0);
    
    // Step 2: Place EXIT room on opposite side
    ExitRoomPosition = FIntVector(GenerationSettings.GridSizeX - 1, GenerationSettings.GridSizeY - 1, 0);
    
    // Step 3: Generate snake-like path from START to EXIT
    TArray<FIntVector> MainPath = CreateSnakePathFromStartToExit(StartRoomPosition, ExitRoomPosition);
    
    if (MainPath.Num() == 0)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Failed to generate snake path!"));
        OnPathValidationFailed(TEXT("No valid path found from START to EXIT"));
        return FSnakeGenerationStats();
    }
    
    // Step 4: Convert path to snake nodes and assign room types
    SnakePath.Empty();
    SnakePath.Reserve(MainPath.Num() + 10); // Reserve extra space for branches
    
    for (int32 i = 0; i < MainPath.Num(); ++i)
    {
        FSnakePathNode Node;
        Node.Position = MainPath[i];
        Node.bIsMainPath = true;
        Node.RoomType = DetermineRoomTypeForPosition(i, MainPath.Num());
        
        // Set up connections
        if (i > 0)
        {
            Node.ConnectedTo.Add(MainPath[i - 1]);
        }
        if (i < MainPath.Num() - 1)
        {
            Node.ConnectedTo.Add(MainPath[i + 1]);
        }
        
        SnakePath.Add(Node);
        OccupiedPositions.Add(Node.Position);
    }
    
    // Step 5: Generate branches to reach target room count
    GenerateBranches();
    
    // Step 6: Apply ADA influence
    ApplyADAInfluence();
    
    // Step 7: Build room lookup for fast access
    RoomLookup.Empty();
    for (const FSnakePathNode& Node : SnakePath)
    {
        RoomLookup.Add(Node.Position, Node);
    }
    
    // Calculate generation statistics
    double GenerationTime = (FPlatformTime::Seconds() - GenerationStartTime) * 1000.0;
    
    LastGenerationStats.GenerationTimeMs = GenerationTime;
    LastGenerationStats.RoomsGenerated = SnakePath.Num();
    LastGenerationStats.PathLength = MainPath.Num();
    LastGenerationStats.bPathConnected = ValidatePathConnectivity();
    LastGenerationStats.PathEfficiency = CalculateManhattanDistance(StartRoomPosition, ExitRoomPosition) / (float)MainPath.Num();
    
    UE_LOG(LogTemp, Log, TEXT("Snake path generation completed: %d rooms, %.2fms"), LastGenerationStats.RoomsGenerated, GenerationTime);
    
    return LastGenerationStats;
}

void ASnakeDungeonGenerator::SpawnSnakeVisualization()
{
    UE_LOG(LogTemp, Log, TEXT("=== LOOP 2: Mesh and Cube Spawning ==="));
    
    double SpawnStartTime = FPlatformTime::Seconds();
    
    // Clear existing visualization
    ClearDungeon();
    
    // Step 1: Spawn room meshes for all snake path nodes
    SpawnRoomMeshesForSnake();
    
    // Step 2: Spawn wall cubes between rooms where there's no connection
    SpawnWallCubesBetweenRooms();
    
    // Step 3: Spawn connection hallways (optional visual element)
    SpawnConnectionHallways();
    
    double SpawnTime = (FPlatformTime::Seconds() - SpawnStartTime) * 1000.0;
    UE_LOG(LogTemp, Log, TEXT("Snake visualization completed in %.2fms"), SpawnTime);
    
    // Debug visualization if enabled
    if (bEnableDebugVisualization)
    {
        DrawDebugSnakePath();
    }
}

TArray<FIntVector> ASnakeDungeonGenerator::CreateSnakePathFromStartToExit(FIntVector StartPos, FIntVector ExitPos)
{
    TArray<FIntVector> Path;
    TSet<FIntVector> Visited;
    
    Path.Add(StartPos);
    Visited.Add(StartPos);
    
    FIntVector CurrentPos = StartPos;
    int32 BacktrackCount = 0;
    const int32 MaxIterations = GenerationSettings.GridSizeX * GenerationSettings.GridSizeY * 2; // Safety limit
    int32 Iterations = 0;
    
    while (CurrentPos != ExitPos && Iterations < MaxIterations)
    {
        ++Iterations;
        
        // Get next position with winding behavior
        FIntVector NextPos = ChooseNextDirection(CurrentPos, ExitPos, Visited);
        
        if (NextPos == FIntVector::ZeroValue) // No valid moves
        {
            // Backtrack
            if (Path.Num() > 1 && BacktrackCount < GenerationSettings.MaxBacktrackAttempts)
            {
                BacktrackAndRetry(Path, Visited, FMath::RandRange(1, 3));
                CurrentPos = Path.Last();
                BacktrackCount++;
                continue;
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("Snake path generation failed - no valid moves and max backtracks reached"));
                return TArray<FIntVector>(); // Return empty array on failure
            }
        }
        
        // Move to next position
        Path.Add(NextPos);
        Visited.Add(NextPos);
        CurrentPos = NextPos;
        
        // Reset backtrack count on successful move
        BacktrackCount = 0;
    }
    
    if (CurrentPos == ExitPos)
    {
        UE_LOG(LogTemp, Log, TEXT("Snake path generated successfully: %d rooms, %d backtracks"), Path.Num(), BacktrackCount);
        LastGenerationStats.BacktrackCount = BacktrackCount;
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Snake path generation failed after %d iterations"), MaxIterations);
    }
    
    return Path;
}

FIntVector ASnakeDungeonGenerator::ChooseNextDirection(FIntVector Current, FIntVector Target, const TSet<FIntVector>& Occupied)
{
    TArray<FIntVector> ValidMoves = GetValidNeighbors(Current);
    TArray<FIntVector> UnoccupiedMoves;
    
    // Filter out occupied positions
    for (const FIntVector& Move : ValidMoves)
    {
        if (!Occupied.Contains(Move))
        {
            UnoccupiedMoves.Add(Move);
        }
    }
    
    if (UnoccupiedMoves.Num() == 0)
    {
        return FIntVector::ZeroValue; // No valid moves
    }
    
    // Implement winding behavior
    FIntVector DirectMove = FIntVector::ZeroValue;
    TArray<FIntVector> WindingMoves;
    
    // Find the move that goes directly toward target
    float MinDistance = FLT_MAX;
    for (const FIntVector& Move : UnoccupiedMoves)
    {
        float Distance = CalculateManhattanDistance(Move, Target);
        if (Distance < MinDistance)
        {
            MinDistance = Distance;
            DirectMove = Move;
        }
    }
    
    // Collect moves that are NOT the direct move (for winding)
    for (const FIntVector& Move : UnoccupiedMoves)
    {
        if (Move != DirectMove)
        {
            WindingMoves.Add(Move);
        }
    }
    
    // Choose based on winding factor
    float RandomValue = FMath::RandRange(0.0f, 1.0f);
    if (RandomValue < GenerationSettings.WindingFactor && WindingMoves.Num() > 0)
    {
        // Choose a winding move
        return WindingMoves[FMath::RandRange(0, WindingMoves.Num() - 1)];
    }
    else
    {
        // Choose the direct move
        return DirectMove;
    }
}

void ASnakeDungeonGenerator::BacktrackAndRetry(TArray<FIntVector>& Path, TSet<FIntVector>& Occupied, int32 BacktrackSteps)
{
    int32 StepsToRemove = FMath::Min(BacktrackSteps, Path.Num() - 1);
    
    for (int32 i = 0; i < StepsToRemove; ++i)
    {
        if (Path.Num() > 1) // Keep at least the start position
        {
            FIntVector LastPos = Path.Last();
            Occupied.Remove(LastPos);
            Path.RemoveAt(Path.Num() - 1);
        }
    }
}

ERoomType ASnakeDungeonGenerator::DetermineRoomTypeForPosition(int32 PathIndex, int32 TotalPathLength)
{
    // Start room
    if (PathIndex == 0)
    {
        return ERoomType::Start;
    }
    
    // Exit room
    if (PathIndex == TotalPathLength - 1)
    {
        return ERoomType::Exit;
    }
    
    // Boss rooms (near the end)
    if (PathIndex >= TotalPathLength * 0.9f)
    {
        if (FMath::RandRange(0.0f, 1.0f) < 0.3f) // 30% chance
        {
            return ERoomType::Boss;
        }
    }
    
    // Elite rooms (middle to late)
    if (PathIndex >= TotalPathLength * 0.5f)
    {
        if (FMath::RandRange(0.0f, 1.0f) < 0.15f) // 15% chance
        {
            return ERoomType::Elite;
        }
    }
    
    // Treasure rooms (scattered throughout)
    if (FMath::RandRange(0.0f, 1.0f) < 0.12f) // 12% chance
    {
        return ERoomType::Treasure;
    }
    
    // Shop rooms (early to mid)
    if (PathIndex >= 3 && PathIndex <= TotalPathLength * 0.6f)
    {
        if (FMath::RandRange(0.0f, 1.0f) < 0.08f) // 8% chance
        {
            return ERoomType::Shop;
        }
    }
    
    // Puzzle rooms
    if (FMath::RandRange(0.0f, 1.0f) < 0.10f) // 10% chance
    {
        return ERoomType::Puzzle;
    }
    
    // Rest rooms (healing stations)
    if (PathIndex > 5 && FMath::RandRange(0.0f, 1.0f) < 0.05f) // 5% chance
    {
        return ERoomType::Rest;
    }
    
    // Default to combat or standard
    return (FMath::RandRange(0.0f, 1.0f) < 0.7f) ? ERoomType::Combat : ERoomType::Standard;
}

void ASnakeDungeonGenerator::GenerateBranches()
{
    if (GenerationSettings.BranchProbability <= 0.0f || SnakePath.Num() >= GenerationSettings.TargetRooms)
    {
        return;
    }
    
    TArray<FSnakePathNode> NewBranches;
    int32 InitialRoomCount = SnakePath.Num();
    
    // Try to add branches from main path nodes
    for (int32 i = 1; i < InitialRoomCount - 1; ++i) // Skip start and exit
    {
        if (SnakePath.Num() >= GenerationSettings.TargetRooms)
        {
            break;
        }
        
        if (FMath::RandRange(0.0f, 1.0f) < GenerationSettings.BranchProbability)
        {
            if (AttemptBranchFromPosition(SnakePath[i].Position))
            {
                // Branch was successfully created
            }
        }
    }
    
    UE_LOG(LogTemp, Log, TEXT("Generated branches: %d new rooms (total: %d)"), SnakePath.Num() - InitialRoomCount, SnakePath.Num());
}

bool ASnakeDungeonGenerator::AttemptBranchFromPosition(FIntVector Position)
{
    TArray<FIntVector> ValidNeighbors = GetValidNeighbors(Position);
    TArray<FIntVector> UnoccupiedNeighbors;
    
    // Find unoccupied neighbors
    for (const FIntVector& Neighbor : ValidNeighbors)
    {
        if (!OccupiedPositions.Contains(Neighbor))
        {
            UnoccupiedNeighbors.Add(Neighbor);
        }
    }
    
    if (UnoccupiedNeighbors.Num() == 0)
    {
        return false;
    }
    
    // Create a branch of 1-3 rooms
    int32 BranchLength = FMath::RandRange(1, 3);
    FIntVector BranchPos = Position;
    
    for (int32 i = 0; i < BranchLength && SnakePath.Num() < GenerationSettings.TargetRooms; ++i)
    {
        // Choose a random unoccupied neighbor
        if (UnoccupiedNeighbors.Num() == 0)
        {
            break;
        }
        
        FIntVector NextBranchPos = UnoccupiedNeighbors[FMath::RandRange(0, UnoccupiedNeighbors.Num() - 1)];
        
        // Create branch node
        FSnakePathNode BranchNode;
        BranchNode.Position = NextBranchPos;
        BranchNode.bIsMainPath = false;
        BranchNode.RoomType = (FMath::RandRange(0.0f, 1.0f) < 0.6f) ? ERoomType::Combat : ERoomType::Treasure;
        BranchNode.ConnectedTo.Add(BranchPos);
        
        // Connect back to previous node
        for (FSnakePathNode& Node : SnakePath)
        {
            if (Node.Position == BranchPos)
            {
                Node.ConnectedTo.Add(NextBranchPos);
                break;
            }
        }
        
        SnakePath.Add(BranchNode);
        OccupiedPositions.Add(NextBranchPos);
        
        // Update for next iteration
        BranchPos = NextBranchPos;
        UnoccupiedNeighbors = GetValidNeighbors(BranchPos);
        
        // Filter out occupied positions
        UnoccupiedNeighbors.RemoveAll([this](const FIntVector& Pos) {
            return OccupiedPositions.Contains(Pos);
        });
    }
    
    return true;
}

void ASnakeDungeonGenerator::ApplyADAInfluence()
{
    // Find ADA system
    if (!ADASystem)
    {
        ADASystem = Cast<AADASystem>(UGameplayStatics::GetActorOfClass(GetWorld(), AADASystem::StaticClass()));
    }
    
    if (!ADASystem)
    {
        return; // No ADA system available
    }
    
    // Apply entity influence to each room
    for (FSnakePathNode& Node : SnakePath)
    {
        float EntityInfluence = CalculateEntityInfluenceForRoom(Node.Position);
        
        // Modify room type based on ADA influence
        if (EntityInfluence > 0.7f && Node.RoomType == ERoomType::Standard)
        {
            Node.RoomType = ERoomType::Elite;
        }
        else if (EntityInfluence > 0.5f && Node.RoomType == ERoomType::Combat)
        {
            // Increase difficulty without changing type
        }
        
        // Store influence for later use
        // This would be stored in a more comprehensive room data structure in a full implementation
    }
}

float ASnakeDungeonGenerator::CalculateEntityInfluenceForRoom(FIntVector Position)
{
    if (!ADASystem)
    {
        return 0.0f;
    }
    
    // Calculate influence based on:
    // - Distance from start (increases over time)
    // - Player behavior patterns
    // - ADA personality
    
    float DistanceFromStart = CalculateManhattanDistance(Position, StartRoomPosition);
    float MaxDistance = CalculateManhattanDistance(StartRoomPosition, ExitRoomPosition);
    float ProgressFactor = DistanceFromStart / MaxDistance;
    
    // Base influence increases with progress through dungeon
    float BaseInfluence = ProgressFactor * 0.5f;
    
    // Add ADA-specific modifications
    float ADAModifier = ADASystem->CalculateAdaptationStrength(CurrentFloor);
    
    return FMath::Clamp(BaseInfluence + ADAModifier, 0.0f, 1.0f);
}

void ASnakeDungeonGenerator::SpawnRoomMeshesForSnake()
{
    if (!ensure(FloorInstancedMesh && WallInstancedMesh))
    {
        UE_LOG(LogTemp, Error, TEXT("HISM components not initialized!"));
        return;
    }
    
    // Pre-allocate transform arrays for better performance
    TArray<FTransform> FloorTransforms;
    FloorTransforms.Reserve(SnakePath.Num());
    
    const FVector BaseLocation = GetActorLocation();
    const FVector FloorScale = FVector(CellSize / 100.0f); // Scale to cell size
    
    // Spawn floor meshes for each room in the snake path
    for (const FSnakePathNode& Node : SnakePath)
    {
        FVector RoomWorldPos = BaseLocation + FVector(
            Node.Position.X * CellSize,
            Node.Position.Y * CellSize,
            0.0f
        );
        
        FTransform FloorTransform;
        FloorTransform.SetLocation(RoomWorldPos);
        FloorTransform.SetRotation(FQuat::Identity);
        FloorTransform.SetScale3D(FloorScale);
        
        FloorTransforms.Add(FloorTransform);
    }
    
    // Batch spawn all floor instances
    if (FloorTransforms.Num() > 0)
    {
        BatchSpawnInstances(FloorInstancedMesh, FloorTransforms);
    }
    
    UE_LOG(LogTemp, Log, TEXT("Spawned %d room floor meshes"), FloorTransforms.Num());
}

void ASnakeDungeonGenerator::SpawnWallCubesBetweenRooms()
{
    if (!ensure(WallInstancedMesh))
    {
        return;
    }
    
    // Generate wall cubes for all grid positions that are not rooms
    TArray<FTransform> WallTransforms;
    WallTransforms.Reserve(GenerationSettings.GridSizeX * GenerationSettings.GridSizeY);
    
    const FVector BaseLocation = GetActorLocation();
    const FVector WallScale = FVector(CellSize / 100.0f); // Scale cube to cell size
    
    for (int32 X = 0; X < GenerationSettings.GridSizeX; ++X)
    {
        for (int32 Y = 0; Y < GenerationSettings.GridSizeY; ++Y)
        {
            FIntVector GridPos(X, Y, 0);
            
            // Skip if this position has a room
            if (OccupiedPositions.Contains(GridPos))
            {
                continue;
            }
            
            // Create wall cube at this position
            FVector WallWorldPos = BaseLocation + FVector(
                X * CellSize,
                Y * CellSize,
                CellSize * 0.5f // Raise cube to proper height
            );
            
            FTransform WallTransform;
            WallTransform.SetLocation(WallWorldPos);
            WallTransform.SetRotation(FQuat::Identity);
            WallTransform.SetScale3D(WallScale);
            
            WallTransforms.Add(WallTransform);
        }
    }
    
    // Batch spawn all wall instances
    if (WallTransforms.Num() > 0)
    {
        BatchSpawnInstances(WallInstancedMesh, WallTransforms);
    }
    
    UE_LOG(LogTemp, Log, TEXT("Spawned %d wall cubes"), WallTransforms.Num());
}

void ASnakeDungeonGenerator::SpawnConnectionHallways()
{
    // Optional: Spawn visual elements to show connections between rooms
    // This could include door frames, hallway lighting, etc.
    // Implementation depends on available art assets
    
    UE_LOG(LogTemp, Log, TEXT("Connection hallways spawned (placeholder)"));
}

void ASnakeDungeonGenerator::BatchSpawnInstances(UHierarchicalInstancedStaticMeshComponent* Component, const TArray<FTransform>& Transforms)
{
    if (!Component || Transforms.Num() == 0)
    {
        return;
    }
    
    // Batch spawn in chunks for optimal performance
    int32 BatchSize = FMath::Min(MaxInstancesPerBatch, Transforms.Num());
    
    if (bUseBatchedSpawning && Transforms.Num() > BatchSize)
    {
        // Spawn in batches
        for (int32 i = 0; i < Transforms.Num(); i += BatchSize)
        {
            int32 EndIndex = FMath::Min(i + BatchSize, Transforms.Num());
            TArray<FTransform> Batch;
            
            for (int32 j = i; j < EndIndex; ++j)
            {
                Batch.Add(Transforms[j]);
            }
            
            Component->AddInstances(Batch, false); // false = world space
        }
    }
    else
    {
        // Spawn all at once
        Component->AddInstances(Transforms, false); // false = world space
    }
    
    // Update render state once after all batches
    Component->MarkRenderStateDirty();
}

// Overload for base UInstancedStaticMeshComponent
void ASnakeDungeonGenerator::BatchSpawnInstances(UInstancedStaticMeshComponent* Component, const TArray<FTransform>& Transforms)
{
    if (!Component || Transforms.Num() == 0)
    {
        return;
    }
    
    // Batch spawn in chunks for optimal performance
    int32 BatchSize = FMath::Min(MaxInstancesPerBatch, Transforms.Num());
    
    if (bUseBatchedSpawning && Transforms.Num() > BatchSize)
    {
        // Spawn in batches
        for (int32 i = 0; i < Transforms.Num(); i += BatchSize)
        {
            int32 EndIndex = FMath::Min(i + BatchSize, Transforms.Num());
            TArray<FTransform> Batch;
            
            for (int32 j = i; j < EndIndex; ++j)
            {
                Batch.Add(Transforms[j]);
            }
            
            Component->AddInstances(Batch, false); // false = world space
        }
    }
    else
    {
        // Spawn all at once
        Component->AddInstances(Transforms, false); // false = world space
    }
    
    // Update render state once after all batches
    Component->MarkRenderStateDirty();
}

bool ASnakeDungeonGenerator::ValidatePathConnectivity()
{
    // Verify that there's a valid path from start to exit
    TArray<FIntVector> Path = GetShortestPath(StartRoomPosition, ExitRoomPosition);
    return Path.Num() > 0 && Path.Last() == ExitRoomPosition;
}

TArray<FIntVector> ASnakeDungeonGenerator::GetShortestPath(FIntVector Start, FIntVector End)
{
    // Simple BFS pathfinding to validate connectivity
    TQueue<FIntVector> Queue;
    TMap<FIntVector, FIntVector> Parents;
    TSet<FIntVector> Visited;
    
    Queue.Enqueue(Start);
    Visited.Add(Start);
    Parents.Add(Start, FIntVector::ZeroValue);
    
    while (!Queue.IsEmpty())
    {
        FIntVector Current;
        Queue.Dequeue(Current);
        
        if (Current == End)
        {
            // Reconstruct path
            TArray<FIntVector> Path;
            FIntVector PathNode = End;
            
            while (PathNode != FIntVector::ZeroValue)
            {
                Path.Add(PathNode);
                FIntVector* ParentPtr = Parents.Find(PathNode);
                PathNode = ParentPtr ? *ParentPtr : FIntVector::ZeroValue;
            }
            
            Algo::Reverse(Path);
            return Path;
        }
        
        // Check all connected neighbors
        const FSnakePathNode* NodePtr = RoomLookup.Find(Current);
        if (NodePtr)
        {
            for (const FIntVector& Connection : NodePtr->ConnectedTo)
            {
                if (!Visited.Contains(Connection))
                {
                    Visited.Add(Connection);
                    Parents.Add(Connection, Current);
                    Queue.Enqueue(Connection);
                }
            }
        }
    }
    
    return TArray<FIntVector>(); // No path found
}

void ASnakeDungeonGenerator::DrawDebugSnakePath()
{
    if (!GetWorld() || !bEnableDebugVisualization)
    {
        return;
    }
    
    const FVector BaseLocation = GetActorLocation();
    const FColor MainPathColor = FColor::Blue;
    const FColor BranchColor = FColor::Green;
    const FColor ConnectionColor = FColor::Yellow;
    
    // Draw room positions
    for (const FSnakePathNode& Node : SnakePath)
    {
        FVector WorldPos = BaseLocation + FVector(Node.Position.X * CellSize, Node.Position.Y * CellSize, 50.0f);
        FColor RoomColor = Node.bIsMainPath ? MainPathColor : BranchColor;
        
        DrawDebugSphere(GetWorld(), WorldPos, 30.0f, 8, RoomColor, true, -1.0f, 0, 3.0f);
        
        // Draw room type label
        FString RoomLabel = UEnum::GetValueAsString(Node.RoomType);
        DrawDebugString(GetWorld(), WorldPos + FVector(0, 0, 50), RoomLabel, nullptr, RoomColor, -1.0f);
    }
    
    // Draw connections
    for (const FSnakePathNode& Node : SnakePath)
    {
        FVector NodeWorldPos = BaseLocation + FVector(Node.Position.X * CellSize, Node.Position.Y * CellSize, 25.0f);
        
        for (const FIntVector& Connection : Node.ConnectedTo)
        {
            FVector ConnectionWorldPos = BaseLocation + FVector(Connection.X * CellSize, Connection.Y * CellSize, 25.0f);
            DrawDebugLine(GetWorld(), NodeWorldPos, ConnectionWorldPos, ConnectionColor, true, -1.0f, 0, 5.0f);
        }
    }
    
    UE_LOG(LogTemp, Log, TEXT("Debug snake path visualization drawn"));
}

void ASnakeDungeonGenerator::ValidateSnakeGeneration()
{
    bool bIsValid = true;
    TArray<FString> ValidationErrors;
    
    // Check if we have a valid path
    if (SnakePath.Num() == 0)
    {
        ValidationErrors.Add(TEXT("No snake path generated"));
        bIsValid = false;
    }
    
    // Check connectivity
    if (!ValidatePathConnectivity())
    {
        ValidationErrors.Add(TEXT("Path is not connected from start to exit"));
        bIsValid = false;
    }
    
    // Check room count
    if (SnakePath.Num() < GenerationSettings.TargetRooms * 0.8f) // Allow 20% tolerance
    {
        ValidationErrors.Add(FString::Printf(TEXT("Generated only %d rooms (target: %d)"), SnakePath.Num(), GenerationSettings.TargetRooms));
    }
    
    // Check for start and exit rooms
    bool bHasStart = false, bHasExit = false;
    for (const FSnakePathNode& Node : SnakePath)
    {
        if (Node.RoomType == ERoomType::Start) bHasStart = true;
        if (Node.RoomType == ERoomType::Exit) bHasExit = true;
    }
    
    if (!bHasStart)
    {
        ValidationErrors.Add(TEXT("No start room found"));
        bIsValid = false;
    }
    
    if (!bHasExit)
    {
        ValidationErrors.Add(TEXT("No exit room found"));
        bIsValid = false;
    }
    
    // Log results
    if (bIsValid)
    {
        UE_LOG(LogTemp, Log, TEXT("✅ Snake generation validation passed"));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Snake generation validation failed:"));
        for (const FString& Error : ValidationErrors)
        {
            UE_LOG(LogTemp, Error, TEXT("  - %s"), *Error);
        }
    }
}

void ASnakeDungeonGenerator::InitializeSnakeGeneration()
{
    // Clear previous state
    SnakePath.Empty();
    OccupiedPositions.Empty();
    RoomLookup.Empty();
    ConnectionMap.Empty();
    
    // Pre-allocate data structures for performance
    PreAllocateDataStructures();
    
    // Reset stats
    LastGenerationStats = FSnakeGenerationStats();
}

void ASnakeDungeonGenerator::PreAllocateDataStructures()
{
    const int32 EstimatedRooms = GenerationSettings.TargetRooms;
    const int32 EstimatedGridSize = GenerationSettings.GridSizeX * GenerationSettings.GridSizeY;
    
    SnakePath.Reserve(EstimatedRooms);
    OccupiedPositions.Reserve(EstimatedRooms);
    RoomLookup.Reserve(EstimatedRooms);
    ConnectionMap.Reserve(EstimatedRooms);
}

TArray<FIntVector> ASnakeDungeonGenerator::GetValidNeighbors(FIntVector Position) const
{
    TArray<FIntVector> Neighbors;
    
    // 4-directional movement (North, South, East, West)
    TArray<FIntVector> Directions = {
        FIntVector(0, 1, 0),  // North
        FIntVector(0, -1, 0), // South
        FIntVector(1, 0, 0),  // East
        FIntVector(-1, 0, 0)  // West
    };
    
    for (const FIntVector& Direction : Directions)
    {
        FIntVector Neighbor = Position + Direction;
        if (IsValidSnakePosition(Neighbor))
        {
            Neighbors.Add(Neighbor);
        }
    }
    
    return Neighbors;
}

bool ASnakeDungeonGenerator::IsValidSnakePosition(FIntVector Position) const
{
    return Position.X >= 0 && Position.X < GenerationSettings.GridSizeX &&
           Position.Y >= 0 && Position.Y < GenerationSettings.GridSizeY &&
           Position.Z == 0; // We only work in 2D for now
}

ESnakeDirection ASnakeDungeonGenerator::GetDirectionToNeighbor(FIntVector From, FIntVector To) const
{
    FIntVector Delta = To - From;
    
    if (Delta.Y > 0) return ESnakeDirection::North;
    if (Delta.Y < 0) return ESnakeDirection::South;
    if (Delta.X > 0) return ESnakeDirection::East;
    if (Delta.X < 0) return ESnakeDirection::West;
    
    return ESnakeDirection::North; // Default fallback
}

float ASnakeDungeonGenerator::CalculateManhattanDistance(FIntVector A, FIntVector B) const
{
    return FMath::Abs(A.X - B.X) + FMath::Abs(A.Y - B.Y);
}

ERoomType ASnakeDungeonGenerator::ApplyADAToRoomType(ERoomType BaseType, float Influence)
{
    // Apply ADA influence to modify room types
    if (Influence > 0.8f && BaseType == ERoomType::Standard)
    {
        return ERoomType::Elite;
    }
    
    if (Influence > 0.6f && BaseType == ERoomType::Combat)
    {
        return (FMath::RandRange(0.0f, 1.0f) < 0.5f) ? ERoomType::Elite : BaseType;
    }
    
    return BaseType;
}

float ASnakeDungeonGenerator::GetADADifficultyModifier(int32 PathIndex)
{
    if (!ADASystem)
    {
        return 1.0f;
    }
    
    // Difficulty increases along the path
    float PathProgress = (float)PathIndex / (float)FMath::Max(1, SnakePath.Num() - 1);
    float BaseModifier = 1.0f + (PathProgress * 0.5f);
    
    // Apply ADA influence
    float ADAModifier = ADASystem->CalculateAdaptationStrength(CurrentFloor);
    
    return BaseModifier * (1.0f + ADAModifier);
}

void ASnakeDungeonGenerator::AssignRoomTypes()
{
    // This is called internally during path generation
    // Room types are assigned in DetermineRoomTypeForPosition
}