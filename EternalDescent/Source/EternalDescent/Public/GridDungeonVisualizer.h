// GridDungeonVisualizer.h - Simple grid-based dungeon visualization using cubes and planes
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tests/DungeonTestTypes.h"
#include "ADASystem.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "GridDungeonVisualizer.generated.h"

UENUM(BlueprintType)
enum class EDungeonGenerationType : uint8
{
    Grid        UMETA(DisplayName = "Grid-Based"),
    Organic     UMETA(DisplayName = "Organic/Natural")
};

UENUM(BlueprintType)
enum class EGridCellType : uint8
{
    Empty       UMETA(DisplayName = "Empty"),      // Nothing (air)
    Floor       UMETA(DisplayName = "Floor"),      // Walkable plane
    Wall        UMETA(DisplayName = "Wall"),       // Solid cube
    Door        UMETA(DisplayName = "Door"),       // Door position (plane)
    Hallway     UMETA(DisplayName = "Hallway")     // Hallway floor (plane)
};

USTRUCT(BlueprintType)
struct FGridCell
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    EGridCellType CellType = EGridCellType::Empty;
    
    UPROPERTY(BlueprintReadWrite)
    int32 RoomID = -1; // Which room this cell belongs to (-1 for walls/empty)
    
    UPROPERTY(BlueprintReadWrite)
    ERoomType RoomType = ERoomType::Standard;
};

USTRUCT(BlueprintType)
struct FOrganicRoom
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    FVector Position; // World position of room center
    
    UPROPERTY(BlueprintReadWrite)
    FVector2D Size; // Width and Height in world units
    
    UPROPERTY(BlueprintReadWrite)
    ERoomType RoomType = ERoomType::Standard;
    
    UPROPERTY(BlueprintReadWrite)
    int32 RoomID = -1;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<int32> ConnectedRooms; // IDs of connected rooms
    
    UPROPERTY(BlueprintReadWrite)
    bool bIsMainPath = false; // Part of the critical path
    
    UPROPERTY(BlueprintReadWrite)
    int32 Depth = 0; // Distance from start room
};

USTRUCT(BlueprintType)
struct FHallway
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    int32 RoomA = -1;
    
    UPROPERTY(BlueprintReadWrite)
    int32 RoomB = -1;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FVector> PathPoints; // Points along the hallway
    
    UPROPERTY(BlueprintReadWrite)
    float Width = 300.0f; // Hallway width
};

USTRUCT(BlueprintType)
struct FOrganicDungeonLayout
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FOrganicRoom> Rooms;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FHallway> Hallways;
    
    UPROPERTY(BlueprintReadWrite)
    int32 StartRoomID = 0;
    
    UPROPERTY(BlueprintReadWrite)
    int32 EndRoomID = -1;
    
    UPROPERTY(BlueprintReadWrite)
    int32 FloorNumber = 1;
};

UCLASS(BlueprintType, Blueprintable)
class ETERNALDESCENT_API AGridDungeonVisualizer : public AActor
{
    GENERATED_BODY()

public:
    AGridDungeonVisualizer();

protected:
    virtual void BeginPlay() override;

public:
    // Core Generation
    UFUNCTION(BlueprintCallable, Category = "Grid Dungeon")
    void GenerateAndVisualizeDungeon(int32 Seed = -1);
    
    UFUNCTION(BlueprintCallable, Category = "Grid Dungeon")
    void BuildGridFromLayout(const FDungeonLayout& Layout);
    
    UFUNCTION(BlueprintCallable, Category = "Grid Dungeon")
    void ClearDungeon();
    
    UFUNCTION(BlueprintCallable, Category = "Grid Dungeon")
    void SpawnGridVisualization();
    
    // Grid Operations
    UFUNCTION(BlueprintCallable, Category = "Grid Dungeon")
    void SetGridCell(int32 X, int32 Y, EGridCellType Type, int32 RoomID = -1);
    
    UFUNCTION(BlueprintPure, Category = "Grid Dungeon")
    FGridCell GetGridCell(int32 X, int32 Y) const;
    
    UFUNCTION(BlueprintPure, Category = "Grid Dungeon")
    bool IsValidGridPosition(int32 X, int32 Y) const;
    
    // Conversion Functions
    UFUNCTION(BlueprintPure, Category = "Grid Dungeon")
    FVector GridToWorldPosition(int32 X, int32 Y, bool bIsFloor = true) const;
    
    UFUNCTION(BlueprintPure, Category = "Grid Dungeon")
    FIntPoint WorldToGridPosition(FVector WorldPos) const;
    
    // Room Building
    UFUNCTION(BlueprintCallable, Category = "Grid Dungeon")
    void PlaceRoomInGrid(const FRoomData& Room);
    
    // Debug Visualization
    UFUNCTION(BlueprintCallable, Category = "Debug")
    void DrawDebugGrid();
    
    UFUNCTION(BlueprintCallable, Category = "Debug")
    void ClearDebugGrid();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Debug")
    void ToggleDebugGridInEditor();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Grid Dungeon")
    void GenerateInEditor();
    
    // Player Functions
    UFUNCTION(BlueprintCallable, Category = "Grid Dungeon")
    void SpawnPlayerAtStart();
    
    UFUNCTION(BlueprintPure, Category = "Grid Dungeon")
    FVector GetStartPosition() const;
    
    // Content Spawning
    UFUNCTION(BlueprintCallable, Category = "Grid Dungeon")
    void SpawnRoomContents();
    
    UFUNCTION(BlueprintCallable, Category = "Grid Dungeon")
    void SpawnTestEnemiesInRoom(const FRoomData& Room);
    
    UFUNCTION(BlueprintCallable, Category = "Grid Dungeon")
    void SpawnTestChestsInRoom(const FRoomData& Room);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Grid Dungeon")
    void OnTestEnemySpawned(FVector Position, ERoomType RoomType);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Grid Dungeon")
    void OnTestChestSpawned(FVector Position, ERoomType RoomType);
    
    // Properties - Generation Mode
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation Mode")
    EDungeonGenerationType GenerationType = EDungeonGenerationType::Organic;
    
    // Grid-based properties
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Layout", meta=(EditCondition="GenerationType==EDungeonGenerationType::Grid", EditConditionHides, ClampMin="1", ClampMax="10"))
    int32 RoomsPerRow = 5; // Number of rooms horizontally
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Layout", meta=(EditCondition="GenerationType==EDungeonGenerationType::Grid", EditConditionHides, ClampMin="1", ClampMax="10"))
    int32 RoomsPerColumn = 5; // Number of rooms vertically (5x5 = 25 rooms total)
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Layout", meta=(EditCondition="GenerationType==EDungeonGenerationType::Grid", EditConditionHides, ClampMin="10", ClampMax="50"))
    int32 TilesPerRoom = 20; // Number of tiles per room (20x20 tiles per room)
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Layout", meta=(EditCondition="GenerationType==EDungeonGenerationType::Grid", EditConditionHides, ClampMin="1", ClampMax="10"))
    float TileSizeMultiplier = 3.5f; // Multiplier for tile size (3.5 = 350 units per tile)
    
    // Organic generation properties
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Organic Layout", meta=(EditCondition="GenerationType==EDungeonGenerationType::Organic", EditConditionHides, ClampMin="10", ClampMax="50"))
    int32 MinRoomCount = 15;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Organic Layout", meta=(EditCondition="GenerationType==EDungeonGenerationType::Organic", EditConditionHides, ClampMin="10", ClampMax="50"))
    int32 MaxRoomCount = 25;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Organic Layout", meta=(EditCondition="GenerationType==EDungeonGenerationType::Organic", EditConditionHides))
    float MinRoomSize = 1000.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Organic Layout", meta=(EditCondition="GenerationType==EDungeonGenerationType::Organic", EditConditionHides))
    float MaxRoomSize = 3000.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Organic Layout", meta=(EditCondition="GenerationType==EDungeonGenerationType::Organic", EditConditionHides))
    float HallwayWidth = 400.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Organic Layout", meta=(EditCondition="GenerationType==EDungeonGenerationType::Organic", EditConditionHides))
    float MinRoomDistance = 500.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Organic Layout", meta=(EditCondition="GenerationType==EDungeonGenerationType::Organic", EditConditionHides))
    float MaxRoomDistance = 2000.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Organic Layout", meta=(EditCondition="GenerationType==EDungeonGenerationType::Organic", EditConditionHides))
    int32 BranchingFactor = 3;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Organic Layout", meta=(EditCondition="GenerationType==EDungeonGenerationType::Organic", EditConditionHides))
    float DeadEndChance = 0.3f;
    
    // Shared properties
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General Settings")
    float WallHeight = 500.0f; // Height of walls (about 2.7x mannequin height)
    
    // Calculated grid size (read-only in editor)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid Info")
    int32 GridSizeX; // Will be RoomsPerRow * TilesPerRoom
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid Info")
    int32 GridSizeY; // Will be RoomsPerColumn * TilesPerRoom
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid Info")
    float CellSize; // Will be equal to TileSize
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Settings")
    bool bAutoGenerateOnBeginPlay = true;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
    bool bShowDebugGrid = false;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
    float DebugLineThickness = 2.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
    FLinearColor DebugGridColor = FLinearColor::Green;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
    float DebugDrawDuration = 0.0f; // 0 = persistent
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Settings")
    int32 CurrentFloor = 1;
    
    // Prefabs (only 2 needed!)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prefabs")
    UStaticMesh* PlaneMesh; // For floors/walkable spaces
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prefabs")
    UStaticMesh* CubeMesh; // For walls/obstacles
    
    // Visual Settings
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
    UMaterialInterface* FloorMaterial;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
    UMaterialInterface* WallMaterial;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
    UMaterialInterface* HallwayMaterial;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
    UMaterialInterface* SpecialRoomMaterial; // For boss/treasure rooms
    
    // Test Content Prefabs
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Content")
    UStaticMesh* TestEnemyMesh; // Simple mesh to represent enemies
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Content")
    UStaticMesh* TestChestMesh; // Simple mesh to represent chests
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Content")
    UMaterialInterface* TestEnemyMaterial;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Content")
    UMaterialInterface* TestChestMaterial;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Content")
    float TestEnemyScale = 2.0f; // Scaled up for spacious mannequin-sized rooms
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Content")
    float TestChestScale = 1.5f; // Scaled up to be visible in large rooms
    
    // References
    UPROPERTY(BlueprintReadOnly, Category = "References")
    AADASystem* ADASystem;
    
    // Runtime Data
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    TArray<FGridCell> Grid; // 1D array representing 2D grid (for grid mode)
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    FDungeonLayout CurrentLayout; // For grid mode
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    FOrganicDungeonLayout OrganicLayout; // For organic mode
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    FIntPoint StartRoomGridPos;
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    FIntPoint ExitRoomGridPos;
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    FRandomStream RandomStream;

    // Organic generation functions
    UFUNCTION(BlueprintCallable, Category = "Organic Dungeon")
    void GenerateOrganicDungeon(int32 Seed = -1);
    
    UFUNCTION(BlueprintCallable, Category = "Organic Dungeon")
    void GenerateMainPath();
    
    UFUNCTION(BlueprintCallable, Category = "Organic Dungeon")
    void GenerateBranches();
    
    UFUNCTION(BlueprintCallable, Category = "Organic Dungeon")
    FHallway CreateHallway(int32 RoomA, int32 RoomB);
    
    UFUNCTION(BlueprintCallable, Category = "Organic Dungeon")
    TArray<FVector> GenerateHallwayPath(FVector StartPos, FVector EndPos);
    
    UFUNCTION(BlueprintCallable, Category = "Organic Dungeon")
    bool DoRoomsOverlap(const FOrganicRoom& A, const FOrganicRoom& B, float Padding = 100.0f);
    
    UFUNCTION(BlueprintCallable, Category = "Organic Dungeon")
    FVector FindValidRoomPosition(const FOrganicRoom& FromRoom, FVector2D NewRoomSize, float MinDistance, float MaxDistance);
    
    void SpawnOrganicRoomGeometry(const FOrganicRoom& Room);
    void SpawnHallwayGeometry(const FHallway& Hallway);
    void VisualizeOrganicDungeon();

private:
    // Instanced mesh components for performance
    UPROPERTY()
    UInstancedStaticMeshComponent* PlaneInstances; // All floor planes
    
    UPROPERTY()
    UInstancedStaticMeshComponent* CubeInstances; // All wall cubes
    
    UPROPERTY()
    UInstancedStaticMeshComponent* TestEnemyInstances; // Test enemy representations
    
    UPROPERTY()
    UInstancedStaticMeshComponent* TestChestInstances; // Test chest representations
    
    // Helper functions
    void InitializeGrid();
    void InitializeComponents();
    int32 GridIndexFromXY(int32 X, int32 Y) const;
    void PlaceWallsAroundRoom(const FRoomData& Room);
    void PlaceBoundaryWalls();
    UMaterialInterface* GetMaterialForCell(const FGridCell& Cell) const;
    void UpdateGridDimensions();
};