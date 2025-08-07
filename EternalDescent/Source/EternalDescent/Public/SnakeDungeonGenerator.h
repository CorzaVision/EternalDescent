// SnakeDungeonGenerator.h
// Snake-path dungeon with proper room spacing and stage progression

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeDungeonTypes.h"
#include "Tests/DungeonTestTypes.h"
#include "SnakeDungeonGenerator.generated.h"

UENUM(BlueprintType)
enum class EStageType : uint8
{
    Normal      UMETA(DisplayName = "Normal Stage"),
    Elite       UMETA(DisplayName = "Elite Stage (Every 5)"),
    Boss        UMETA(DisplayName = "Boss Stage (Every 10)"),
    SafeZone    UMETA(DisplayName = "Safe Zone")
};

UENUM(BlueprintType)
enum class EContentMarkerType : uint8
{
    Enemy       UMETA(DisplayName = "Enemy Spawn"),
    Chest       UMETA(DisplayName = "Treasure Chest"),
    Puzzle      UMETA(DisplayName = "Puzzle Element"),
    Interactable UMETA(DisplayName = "Interactable Object"),
    Elite       UMETA(DisplayName = "Elite Enemy"),
    Boss        UMETA(DisplayName = "Boss Enemy")
};

// Content marker for spawning entities in rooms
USTRUCT(BlueprintType)
struct FContentMarker
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    FVector RelativePosition; // Position relative to room center
    
    UPROPERTY(BlueprintReadWrite)
    EContentMarkerType Type;
    
    UPROPERTY(BlueprintReadWrite)
    float Radius; // Capsule radius for enemies, sphere radius for chests
    
    UPROPERTY(BlueprintReadWrite)
    float Height; // Capsule height for enemies (ignored for spheres)
    
    UPROPERTY(BlueprintReadWrite)
    int32 DifficultyTier; // 1-3 for enemy difficulty
    
    UPROPERTY(BlueprintReadWrite)
    FString ContentID; // Specific enemy/item ID if needed
    
    FContentMarker()
    {
        RelativePosition = FVector::ZeroVector;
        Type = EContentMarkerType::Enemy;
        Radius = 50.0f; // Default capsule radius
        Height = 180.0f; // Default capsule height (human-sized)
        DifficultyTier = 1;
        ContentID = "";
    }
};

USTRUCT(BlueprintType)
struct FSnakeRoom
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    int32 RoomID;
    
    UPROPERTY(BlueprintReadWrite)
    FIntVector Center;
    
    UPROPERTY(BlueprintReadWrite)
    FIntVector Size;
    
    UPROPERTY(BlueprintReadWrite)
    ERoomType Type;
    
    UPROPERTY(BlueprintReadWrite)
    EStageType StageType;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<int32> ConnectedRooms;
    
    UPROPERTY(BlueprintReadWrite)
    int32 PathOrder; // Position in snake path (0 = start)
    
    UPROPERTY(BlueprintReadWrite)
    bool bIsMainPath;
    
    UPROPERTY(BlueprintReadWrite)
    bool bAllowBranching;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FContentMarker> ContentMarkers; // Enemies, chests, etc.
    
    // Get bounding box
    FIntVector GetMinBounds() const { return Center - Size / 2; }
    FIntVector GetMaxBounds() const { return Center + Size / 2; }
    
    // Check if a point is inside this room (with buffer)
    bool ContainsPoint(const FIntVector& Point, int32 Buffer = 0) const
    {
        FIntVector Min = GetMinBounds() - FIntVector(Buffer, Buffer, Buffer);
        FIntVector Max = GetMaxBounds() + FIntVector(Buffer, Buffer, Buffer);
        
        return Point.X >= Min.X && Point.X <= Max.X &&
               Point.Y >= Min.Y && Point.Y <= Max.Y &&
               Point.Z >= Min.Z && Point.Z <= Max.Z;
    }
    
    // Check collision with another room
    bool CollidesWith(const FSnakeRoom& Other, int32 MinSpacing = 1) const
    {
        FIntVector ThisMin = GetMinBounds() - FIntVector(MinSpacing, MinSpacing, 0);
        FIntVector ThisMax = GetMaxBounds() + FIntVector(MinSpacing, MinSpacing, 0);
        FIntVector OtherMin = Other.GetMinBounds();
        FIntVector OtherMax = Other.GetMaxBounds();
        
        return !(ThisMax.X < OtherMin.X || ThisMin.X > OtherMax.X ||
                 ThisMax.Y < OtherMin.Y || ThisMin.Y > OtherMax.Y ||
                 ThisMax.Z < OtherMin.Z || ThisMin.Z > OtherMax.Z);
    }
    
    FSnakeRoom()
    {
        RoomID = -1;
        Center = FIntVector::ZeroValue;
        Size = FIntVector(5, 5, 3);
        Type = ERoomType::Combat;
        StageType = EStageType::Normal;
        PathOrder = -1;
        bIsMainPath = true;
        bAllowBranching = false;
    }
};

USTRUCT(BlueprintType)
struct FHallwayConnection
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    int32 FromRoomID;
    
    UPROPERTY(BlueprintReadWrite)
    int32 ToRoomID;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FIntVector> Path;
    
    UPROPERTY(BlueprintReadWrite)
    int32 Length; // In cubes
    
    UPROPERTY(BlueprintReadWrite)
    bool bIsMainPath;
    
    FHallwayConnection()
    {
        FromRoomID = -1;
        ToRoomID = -1;
        Length = 0;
        bIsMainPath = true;
    }
};

USTRUCT(BlueprintType)
struct FSnakeDungeonLayout
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    int32 StageNumber; // 1-20
    
    UPROPERTY(BlueprintReadWrite)
    EStageType StageType;
    
    UPROPERTY(BlueprintReadWrite)
    TMap<int32, FSnakeRoom> Rooms;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FHallwayConnection> Hallways;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<int32> MainPathRoomOrder; // Room IDs in snake path order
    
    UPROPERTY(BlueprintReadWrite)
    TMap<FIntVector, FDungeonCube> FillerCubes; // Space-filling cubes
    
    UPROPERTY(BlueprintReadWrite)
    FIntVector GridBounds;
    
    UPROPERTY(BlueprintReadWrite)
    int32 StartRoomID;
    
    UPROPERTY(BlueprintReadWrite)
    int32 EndRoomID;
    
    UPROPERTY(BlueprintReadWrite)
    int32 EliteRoomID; // -1 if not elite stage
    
    UPROPERTY(BlueprintReadWrite)
    int32 BossRoomID; // -1 if not boss stage
    
    UPROPERTY(BlueprintReadWrite)
    float GenerationTime;
    
    FSnakeDungeonLayout()
    {
        StageNumber = 1;
        StageType = EStageType::Normal;
        GridBounds = FIntVector(100, 100, 20);
        StartRoomID = -1;
        EndRoomID = -1;
        EliteRoomID = -1;
        BossRoomID = -1;
        GenerationTime = 0.0f;
    }
};

DECLARE_DELEGATE_OneParam(FOnSnakeDungeonGenerated, const FSnakeDungeonLayout&);

UCLASS()
class ETERNALDESCENT_API ASnakeDungeonGenerator : public AActor
{
    GENERATED_BODY()
    
public:
    ASnakeDungeonGenerator();
    
    // Main generation function
    UFUNCTION(BlueprintCallable, Category = "Snake Dungeon")
    FSnakeDungeonLayout GenerateSnakeDungeon(int32 StageNumber);
    
    // Async generation
    void GenerateSnakeDungeonAsync(int32 StageNumber, FOnSnakeDungeonGenerated OnComplete);
    
    // Configuration
    UFUNCTION(BlueprintCallable, Category = "Snake Dungeon")
    void SetDifficulty(float Difficulty) { DifficultyMultiplier = Difficulty; }
    
protected:
    virtual void BeginPlay() override;
    
private:
    // Generation parameters
    UPROPERTY(EditAnywhere, Category = "Generation")
    int32 MinRoomsPerStage = 15;  // MINIMUM 15 rooms
    
    UPROPERTY(EditAnywhere, Category = "Generation")
    int32 MaxRoomsPerStage = 25;  // MAXIMUM 25 rooms
    
    UPROPERTY(EditAnywhere, Category = "Generation")
    int32 MinRoomSize = 5;
    
    UPROPERTY(EditAnywhere, Category = "Generation")
    int32 MaxRoomSize = 12;
    
    UPROPERTY(EditAnywhere, Category = "Generation")
    int32 MinHallwayLength = 1;
    
    UPROPERTY(EditAnywhere, Category = "Generation")
    int32 MaxHallwayLength = 2;
    
    UPROPERTY(EditAnywhere, Category = "Generation")
    float BranchingChance = 0.3f; // 30% chance for branching paths
    
    UPROPERTY(EditAnywhere, Category = "Generation")
    float DifficultyMultiplier = 1.0f;
    
    UPROPERTY(EditAnywhere, Category = "Generation")
    int32 CubeSize = 100; // World units per cube
    
    // Generation pipeline
    void InitializeStage(FSnakeDungeonLayout& Layout);
    void GenerateSnakePath(FSnakeDungeonLayout& Layout);
    void PlaceSpecialRooms(FSnakeDungeonLayout& Layout);
    void CreateHallwayConnections(FSnakeDungeonLayout& Layout);
    void AddBranchingPaths(FSnakeDungeonLayout& Layout);
    void FillEmptySpace(FSnakeDungeonLayout& Layout);
    void OptimizeLayout(FSnakeDungeonLayout& Layout);
    
    // Snake path generation
    FIntVector ChooseNextRoomPosition(const FSnakeRoom& CurrentRoom, const TArray<FSnakeRoom>& ExistingRooms, int32 PreferredDirection);
    bool TryPlaceRoom(FSnakeRoom& NewRoom, const TArray<FSnakeRoom>& ExistingRooms, int32 MinSpacing = 1);
    int32 CalculateSnakeDirection(int32 PathPosition, int32 TotalRooms);
    
    // Hallway creation
    TArray<FIntVector> CreateHallway(const FSnakeRoom& FromRoom, const FSnakeRoom& ToRoom, int32 MaxLength = 2);
    FIntVector GetRoomExitPoint(const FSnakeRoom& Room, const FIntVector& Direction);
    FIntVector GetRoomEntryPoint(const FSnakeRoom& Room, const FIntVector& Direction);
    
    // Special room placement
    void PlaceEliteRoom(FSnakeDungeonLayout& Layout);
    void PlaceBossRoom(FSnakeDungeonLayout& Layout);
    void PlaceTreasureRooms(FSnakeDungeonLayout& Layout);
    
    // Space filling
    void FillWithSolidCubes(FSnakeDungeonLayout& Layout);
    bool IsSpaceOccupied(const FIntVector& Position, const FSnakeDungeonLayout& Layout);
    void CreateUndergroundAmbience(FSnakeDungeonLayout& Layout);
    
    // Collision detection
    bool CheckRoomCollisions(const FSnakeRoom& Room, const TMap<int32, FSnakeRoom>& ExistingRooms, int32 MinSpacing = 1);
    bool CheckHallwayCollisions(const TArray<FIntVector>& Path, const FSnakeDungeonLayout& Layout);
    void ValidateRoomCount(FSnakeDungeonLayout& Layout); // Validation for 15-25 rooms
    
    // Connectivity fixes
    void EnsureAllRoomsConnected(FSnakeDungeonLayout& Layout);
    TSet<int32> FindConnectedRooms(const FSnakeDungeonLayout& Layout, int32 StartRoomID);
    int32 FindNearestRoom(const FIntVector& Position, const TMap<int32, FSnakeRoom>& Rooms) const;
    void ConnectIsolatedRooms(FSnakeDungeonLayout& Layout, const TSet<int32>& ConnectedRooms);
    bool TryConnectToNearestRoom(FSnakeDungeonLayout& Layout, int32 IsolatedRoomID, const TSet<int32>& ConnectedRooms);
    void ExpandGridIfNeeded(FSnakeDungeonLayout& Layout);
    
    // Content population
    void PopulateRoomContent(FSnakeRoom& Room);
    void AddEnemyMarkers(FSnakeRoom& Room, int32 Count);
    void AddTreasureMarkers(FSnakeRoom& Room, int32 Count);
    void AddBossMarkers(FSnakeRoom& Room);
    void AddEliteMarkers(FSnakeRoom& Room);
    
    // Helpers
    FIntVector GetDirectionVector(int32 Direction) const;
    float CalculatePathDistance(const FSnakeRoom& From, const FSnakeRoom& To) const;
    ERoomType DetermineRoomType(int32 PathPosition, int32 TotalRooms, EStageType StageType) const;
};