// GridDungeonVisualizer.h - Grid-based dungeon visualization with HISM (UE 5.5 Optimized)
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "Engine/World.h" // UE 5.5 World access
#include "GridDungeonVisualizer.generated.h"

UENUM(BlueprintType)
enum class EGridCellType : uint8
{
    Empty       UMETA(DisplayName = "Empty"),      // Nothing (air)
    Floor       UMETA(DisplayName = "Floor"),      // Walkable plane
    Wall        UMETA(DisplayName = "Wall")        // Solid cube
};

USTRUCT(BlueprintType)
struct FGridCell
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    EGridCellType CellType = EGridCellType::Empty;
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
    void ClearDungeon();
    
    // Grid Operations
    UFUNCTION(BlueprintCallable, Category = "Grid Dungeon")
    void SetGridCell(int32 X, int32 Y, EGridCellType Type);
    
    UFUNCTION(BlueprintPure, Category = "Grid Dungeon")
    FGridCell GetGridCell(int32 X, int32 Y) const;
    
    UFUNCTION(BlueprintPure, Category = "Grid Dungeon")
    bool IsValidGridPosition(int32 X, int32 Y) const;
    
    UFUNCTION(BlueprintPure, Category = "Grid Dungeon")
    FVector GridToWorldPosition(int32 X, int32 Y, bool bIsFloor = true) const;
    
    // Debug Visualization
    UFUNCTION(BlueprintCallable, Category = "Debug")
    void DrawDebugGrid();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Debug")
    void GenerateInEditor();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Debug")
    void TestGridAlignment();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Debug") 
    void TestAlternativeAlignment();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Debug")
    void MatchCubesToDebugBoxes();
    
    // Grid Configuration
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Layout", meta=(ClampMin="1", ClampMax="50"))
    int32 GridSizeX = 10;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Layout", meta=(ClampMin="1", ClampMax="50"))
    int32 GridSizeY = 10;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Layout", meta=(ClampMin="100", ClampMax="1000"))
    float CellSize = 350.0f; // 3.5 * 100 units per cell
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Layout", meta=(ClampMin="0.1", ClampMax="1.0"))
    float CubeSizePercentage = 1.0f; // Percentage of cell size for cubes (1.0 = 100%)
    
    // Prefabs
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prefabs")
    UStaticMesh* PlaneMesh; // For floors
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prefabs")
    UStaticMesh* CubeMesh; // For walls
    
    // Visual Settings
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
    UMaterialInterface* FloorMaterial;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
    UMaterialInterface* WallMaterial;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
    UMaterialInterface* StartRoomMaterial;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
    UMaterialInterface* EndRoomMaterial;
    
    // UE 5.5 Optimization Settings
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UE5.5 Features")
    bool bUseNanite = true;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UE5.5 Features")
    bool bCastShadows = true;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UE5.5 Features", meta=(ClampMin="0", ClampMax="7"))
    int32 LODBias = 0;
    
    // UE 5.5 HISM Pooling Settings
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UE5.5 HISM")
    bool bUseInstancePooling = true;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UE5.5 HISM", meta=(ClampMin="64", ClampMax="1024"))
    int32 InstanceBatchSize = 256;
    
    // UE 5.5 Lumen Support
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UE5.5 Rendering")
    bool bLumenEnabled = true;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UE5.5 Rendering")
    bool bVirtualShadowMaps = true;
    
    // Debug Settings
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
    bool bShowDebugGrid = false;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
    float DebugLineThickness = 2.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
    FLinearColor DebugGridColor = FLinearColor::Green;
    
    // HISM Components for better performance with large instance counts
    UPROPERTY(BlueprintReadOnly, Category = "Components")
    UHierarchicalInstancedStaticMeshComponent* PlaneInstances;
    
    UPROPERTY(BlueprintReadOnly, Category = "Components")
    UHierarchicalInstancedStaticMeshComponent* CubeInstances;
    
    // Runtime Data
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    TArray<FGridCell> Grid;

private:
    void InitializeComponents();
    void InitializeGrid();
    void SpawnGridVisualization();
    int32 GridIndexFromXY(int32 X, int32 Y) const;
    void GenerateSimpleLayout();
};