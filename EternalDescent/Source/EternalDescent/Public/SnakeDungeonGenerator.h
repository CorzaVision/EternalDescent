// SnakeDungeonGenerator.h - Snake-path dungeon generation system for EternalDescent
// Uses two-loop approach: 1) Room Placement, 2) Mesh and Cube Spawning
#pragma once

#include "CoreMinimal.h"
#include "DungeonVisualizer.h"
#include "Tests/DungeonTestTypes.h"
#include "ADASystem.h"
#include "Engine/Engine.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "SnakeDungeonGenerator.generated.h"

UENUM(BlueprintType)
enum class ESnakeDirection : uint8
{
    North   UMETA(DisplayName = "North"),
    South   UMETA(DisplayName = "South"),
    East    UMETA(DisplayName = "East"),
    West    UMETA(DisplayName = "West")
};

USTRUCT(BlueprintType)
struct FSnakePathNode
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    FIntVector Position;

    UPROPERTY(BlueprintReadWrite)
    ERoomType RoomType;

    UPROPERTY(BlueprintReadWrite)
    TArray<FIntVector> ConnectedTo;

    UPROPERTY(BlueprintReadWrite)
    bool bIsMainPath;

    FSnakePathNode()
    {
        Position = FIntVector::ZeroValue;
        RoomType = ERoomType::Standard;
        bIsMainPath = false;
    }
};

USTRUCT(BlueprintType)
struct FSnakeGenerationSettings
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Snake Generation")
    int32 GridSizeX = 5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Snake Generation")
    int32 GridSizeY = 5;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Snake Generation")
    int32 TargetRooms = 25;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Snake Generation")
    float WindingFactor = 0.7f; // 0.0 = straight line, 1.0 = maximum winding

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Snake Generation")
    int32 MaxBacktrackAttempts = 3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Snake Generation")
    bool bGuaranteeConnection = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Snake Generation")
    float BranchProbability = 0.2f; // Chance to create branches off main path

    FSnakeGenerationSettings()
    {
        GridSizeX = 5;
        GridSizeY = 5;
        TargetRooms = 25;
        WindingFactor = 0.7f;
        MaxBacktrackAttempts = 3;
        bGuaranteeConnection = true;
        BranchProbability = 0.2f;
    }
};

USTRUCT(BlueprintType)
struct FSnakeGenerationStats
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    float GenerationTimeMs = 0.0f;

    UPROPERTY(BlueprintReadOnly)
    int32 RoomsGenerated = 0;

    UPROPERTY(BlueprintReadOnly)
    int32 PathLength = 0;

    UPROPERTY(BlueprintReadOnly)
    int32 BacktrackCount = 0;

    UPROPERTY(BlueprintReadOnly)
    bool bPathConnected = false;

    UPROPERTY(BlueprintReadOnly)
    float PathEfficiency = 0.0f; // Actual path length / Manhattan distance

    FSnakeGenerationStats()
    {
        GenerationTimeMs = 0.0f;
        RoomsGenerated = 0;
        PathLength = 0;
        BacktrackCount = 0;
        bPathConnected = false;
        PathEfficiency = 0.0f;
    }
};

/**
 * SnakeDungeonGenerator - High-performance snake-path dungeon generator
 * 
 * Features:
 * - Two-loop generation: Room Placement -> Mesh Spawning
 * - Guaranteed START to EXIT connectivity
 * - Configurable winding patterns for exploration
 * - Performance target: <16ms total generation time
 * - ADA System integration for entity influence
 * - Uses HISM for optimal rendering performance
 */
UCLASS(BlueprintType, Blueprintable)
class ETERNALDESCENT_API ASnakeDungeonGenerator : public ADungeonVisualizer
{
    GENERATED_BODY()

public:
    ASnakeDungeonGenerator();

protected:
    virtual void BeginPlay() override;

public:
    // Core Generation Functions - Two-Loop System
    
    /** LOOP 1: Room Placement - Generate snake path and place rooms */
    UFUNCTION(BlueprintCallable, Category = "Snake Generation|Loop 1")
    FSnakeGenerationStats GenerateSnakePath(int32 Seed = -1);

    /** LOOP 2: Mesh and Cube Spawning - Visualize the generated layout */
    UFUNCTION(BlueprintCallable, Category = "Snake Generation|Loop 2")
    void SpawnSnakeVisualization();

    /** Combined function for complete generation */
    UFUNCTION(BlueprintCallable, Category = "Snake Generation")
    void GenerateAndVisualizeSnakeDungeon(int32 Seed = -1);

    // Path Generation Functions
    UFUNCTION(BlueprintCallable, Category = "Snake Generation|Path")
    TArray<FIntVector> CreateSnakePathFromStartToExit(FIntVector StartPos, FIntVector ExitPos);

    UFUNCTION(BlueprintCallable, Category = "Snake Generation|Path")
    bool ValidatePathConnectivity();

    UFUNCTION(BlueprintCallable, Category = "Snake Generation|Path")
    TArray<FIntVector> GetShortestPath(FIntVector Start, FIntVector End);

    // Room Assignment Functions
    UFUNCTION(BlueprintCallable, Category = "Snake Generation|Rooms")
    void AssignRoomTypes();

    UFUNCTION(BlueprintCallable, Category = "Snake Generation|Rooms")
    ERoomType DetermineRoomTypeForPosition(int32 PathIndex, int32 TotalPathLength);

    // Branching Functions
    UFUNCTION(BlueprintCallable, Category = "Snake Generation|Branching")
    void GenerateBranches();

    UFUNCTION(BlueprintCallable, Category = "Snake Generation|Branching")
    bool AttemptBranchFromPosition(FIntVector Position);

    // ADA Integration
    UFUNCTION(BlueprintCallable, Category = "Snake Generation|ADA")
    void ApplyADAInfluence();

    UFUNCTION(BlueprintCallable, Category = "Snake Generation|ADA")
    float GetADADifficultyModifier(int32 PathIndex);

    // Visualization Functions
    UFUNCTION(BlueprintCallable, Category = "Snake Generation|Visualization")
    void SpawnRoomMeshesForSnake();

    UFUNCTION(BlueprintCallable, Category = "Snake Generation|Visualization")
    void SpawnWallCubesBetweenRooms();

    UFUNCTION(BlueprintCallable, Category = "Snake Generation|Visualization")
    void SpawnConnectionHallways();

    // Debug and Testing Functions
    UFUNCTION(BlueprintCallable, Category = "Snake Generation|Debug")
    void DrawDebugSnakePath();

    UFUNCTION(BlueprintCallable, Category = "Snake Generation|Debug")
    void ValidateSnakeGeneration();

    UFUNCTION(BlueprintCallable, Category = "Snake Generation|Debug")
    FSnakeGenerationStats GetLastGenerationStats() const { return LastGenerationStats; }

    // Utility Functions
    UFUNCTION(BlueprintPure, Category = "Snake Generation|Utility")
    bool IsValidSnakePosition(FIntVector Position) const;

    UFUNCTION(BlueprintPure, Category = "Snake Generation|Utility")
    TArray<FIntVector> GetValidNeighbors(FIntVector Position) const;

    UFUNCTION(BlueprintPure, Category = "Snake Generation|Utility")
    ESnakeDirection GetDirectionToNeighbor(FIntVector From, FIntVector To) const;

    UFUNCTION(BlueprintPure, Category = "Snake Generation|Utility")
    float CalculateManhattanDistance(FIntVector A, FIntVector B) const;

    // Settings and Properties
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Snake Generation|Settings")
    FSnakeGenerationSettings GenerationSettings;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Snake Generation|Settings")
    bool bEnableDebugVisualization = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Snake Generation|Performance")
    bool bUseBatchedSpawning = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Snake Generation|Performance")
    int32 MaxInstancesPerBatch = 500;

    // Runtime Data
    UPROPERTY(BlueprintReadOnly, Category = "Snake Generation|Runtime")
    TArray<FSnakePathNode> SnakePath;

    UPROPERTY(BlueprintReadOnly, Category = "Snake Generation|Runtime")
    FIntVector StartRoomPosition;

    UPROPERTY(BlueprintReadOnly, Category = "Snake Generation|Runtime")
    FIntVector ExitRoomPosition;

    UPROPERTY(BlueprintReadOnly, Category = "Snake Generation|Runtime")
    FSnakeGenerationStats LastGenerationStats;

    UPROPERTY(BlueprintReadOnly, Category = "Snake Generation|Runtime")
    TMap<FIntVector, FSnakePathNode> RoomLookup;

    // Blueprint Events
    UFUNCTION(BlueprintImplementableEvent, Category = "Snake Generation|Events")
    void OnSnakePathGenerated(const FSnakeGenerationStats& Stats);

    UFUNCTION(BlueprintImplementableEvent, Category = "Snake Generation|Events")
    void OnSnakeVisualizationComplete();

    UFUNCTION(BlueprintImplementableEvent, Category = "Snake Generation|Events")
    void OnPathValidationFailed(const FString& Reason);

private:
    // Internal Generation Functions
    void InitializeSnakeGeneration();
    TArray<FIntVector> GenerateMainSnakePath(FIntVector Start, FIntVector End);
    bool CanMoveToPosition(FIntVector Position, const TSet<FIntVector>& OccupiedPositions);
    FIntVector ChooseNextDirection(FIntVector Current, FIntVector Target, const TSet<FIntVector>& Occupied);
    void BacktrackAndRetry(TArray<FIntVector>& Path, TSet<FIntVector>& Occupied, int32 BacktrackSteps);
    
    // Performance optimization functions
    void PreAllocateDataStructures();
    void BatchSpawnInstances(UHierarchicalInstancedStaticMeshComponent* Component, const TArray<FTransform>& Transforms);
    void BatchSpawnInstances(UInstancedStaticMeshComponent* Component, const TArray<FTransform>& Transforms);
    
    // ADA integration helpers
    float CalculateEntityInfluenceForRoom(FIntVector Position);
    ERoomType ApplyADAToRoomType(ERoomType BaseType, float Influence);

    // Internal state
    TSet<FIntVector> OccupiedPositions;
    TMap<FIntVector, TArray<FIntVector>> ConnectionMap;
    double GenerationStartTime;
    int32 CurrentSeed;
    
    // Performance tracking
    UPROPERTY()
    TArray<float> GenerationTimes;
};