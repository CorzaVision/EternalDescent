// GridDungeonVisualizer.h - Simple grid-based dungeon visualization using cubes and planes
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakeDungeonGenerator.h"
#include "ADASystem.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "GridDungeonVisualizer.generated.h"

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
    
    UFUNCTION(BlueprintCallable, Category = "Grid Dungeon")
    void PlaceHallwayInGrid(const FHallwayConnection& Hallway);
    
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
    
    // Debug
    UFUNCTION(BlueprintCallable, Category = "Grid Dungeon")
    void DrawDebugGrid();
    
    // Properties
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Settings")
    int32 GridSizeX = 300; // Total grid width
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Settings")
    int32 GridSizeY = 300; // Total grid height
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Settings")
    float CellSize = 366.0f; // Size of each grid cell = 2x mannequin height (183*2) for spacious rooms
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Settings")
    float WallHeight = 274.5f; // Wall height = 1.5x mannequin height (183*1.5) - feels right for dungeon
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Settings")
    bool bAutoGenerateOnBeginPlay = true;
    
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
    float TestEnemyScale = 1.5f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test Content")
    float TestChestScale = 0.8f;
    
    // References
    UPROPERTY(BlueprintReadOnly, Category = "References")
    ASnakeDungeonGenerator* DungeonGenerator;
    
    UPROPERTY(BlueprintReadOnly, Category = "References")
    AADASystem* ADASystem;
    
    // Runtime Data
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    TArray<FGridCell> Grid; // 1D array representing 2D grid
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    FDungeonLayout CurrentLayout;
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    FIntPoint StartRoomGridPos;
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    FIntPoint ExitRoomGridPos;

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
    void ConnectRoomsWithHallway(FIntPoint Start, FIntPoint End, int32 HallwayWidth = 3);
    UMaterialInterface* GetMaterialForCell(const FGridCell& Cell) const;
};