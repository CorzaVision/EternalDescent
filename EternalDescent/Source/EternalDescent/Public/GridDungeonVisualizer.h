// GridDungeonVisualizer.h - Grid-based dungeon visualization with HISM (UE 5.5 Optimized)
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "Engine/World.h" // UE 5.5 World access
#include "Engine/TimerHandle.h" // For animation timer
#if WITH_EDITOR
#include "Engine/Engine.h" // For property change events
#endif
#include "GridDungeonVisualizer.generated.h"

UENUM(BlueprintType)
enum class EGridCellType : uint8
{
    Empty       UMETA(DisplayName = "Empty"),      // Nothing (air)
    Floor       UMETA(DisplayName = "Floor"),      // Walkable plane
    Wall        UMETA(DisplayName = "Wall")        // Solid cube
};

UENUM(BlueprintType)
enum class ERoomSizeType : uint8
{
    None = 0        UMETA(DisplayName = "None"),
    Small_2x2 = 2   UMETA(DisplayName = "2x2 Room"),
    Standard_3x3 = 3 UMETA(DisplayName = "3x3 Room")
};

UENUM(BlueprintType)
enum class EGenerationPhase : uint8
{
    Idle            UMETA(DisplayName = "Idle"),
    GeneratingPath  UMETA(DisplayName = "Generating Path"),
    SpawningCubes   UMETA(DisplayName = "Spawning Cubes"),
    SpawningPlanes  UMETA(DisplayName = "Spawning Planes"),
    Complete        UMETA(DisplayName = "Complete")
};

USTRUCT(BlueprintType)
struct FGridCell
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    EGridCellType CellType = EGridCellType::Empty;
};

USTRUCT(BlueprintType)
struct FGridRoomInfo
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    ERoomSizeType RoomSize = ERoomSizeType::None;
    
    UPROPERTY(BlueprintReadWrite)
    bool bIsStartRoom = false;
    
    UPROPERTY(BlueprintReadWrite)
    bool bIsEndRoom = false;
    
    UPROPERTY(BlueprintReadWrite)
    FIntPoint Center = FIntPoint::ZeroValue;
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
    
    // Grid Size Calculation
    UFUNCTION(BlueprintCallable, Category = "Grid Layout")
    void CalculateOptimalGridSize();

    UFUNCTION(BlueprintCallable, Category = "Grid Layout")
    FIntPoint GetOptimalGridSizeForRooms(int32 RoomCount);
    
    // Debug Visualization
    UFUNCTION(BlueprintCallable, Category = "Debug")
    void DrawDebugGrid();
    
    UFUNCTION(BlueprintCallable, Category = "Debug")
    void DrawRoomBoundaries();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Snake Generation", 
        meta = (DisplayName = "Generate (Animated)"))
    void GenerateInEditor();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Snake Generation",
        meta = (DisplayName = "Generate (Instant)"))
    void GenerateInstant();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Snake Generation",
        meta = (DisplayName = "Pause/Resume"))
    void TogglePause();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Snake Generation",
        meta = (DisplayName = "Skip to End"))
    void SkipToEnd();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Debug")
    void TestGridAlignment();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Debug") 
    void TestAlternativeAlignment();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Debug")
    void DrawDebugCubes();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Debug")
    void MatchCubesToDebugBoxes();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Debug")
    void ValidateSpacing();
    
    // Grid Configuration - EXACTLY 25 Rooms Required
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Layout", meta=(ClampMin="25", ClampMax="25"))
    int32 RequiredRoomCount = 25;  // EXACTLY 25 rooms, not negotiable

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Layout", meta=(ClampMin="25", ClampMax="25"))
    int32 DesiredRoomCount = 25;  // Alias for test compatibility

    UPROPERTY(BlueprintReadOnly, Category = "Grid Layout")
    int32 ActualRoomCount = 0;  // Track actual rooms generated

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Layout")
    bool bAutoCalculateGridSize = true;  // Auto-size grid based on room count

    UPROPERTY(BlueprintReadOnly, Category = "Grid Layout")
    int32 CalculatedGridSizeX = 30;  // Calculated optimal size

    UPROPERTY(BlueprintReadOnly, Category = "Grid Layout")
    int32 CalculatedGridSizeY = 30;  // Calculated optimal size
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Layout", meta=(ClampMin="20", ClampMax="50"))
    int32 GridSizeX = 30;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Layout", meta=(ClampMin="20", ClampMax="50"))
    int32 GridSizeY = 30;
    
    // Room Size Configuration
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Layout", meta=(ClampMin="3", ClampMax="3"))
    int32 RoomSize = 3;  // Rooms are 3x3
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Layout", meta=(ClampMin="1", ClampMax="1"))
    int32 RoomGap = 1;  // Exactly 1 cell gap between rooms
    
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
    
#if WITH_EDITOR
    // Editor-only visualization controls
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Snake Generation|Editor")
    void ClearInEditor();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Snake Generation|Editor")
    void StepThroughGeneration();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Snake Generation|Editor")
    void ToggleDebugVisualization();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Snake Generation|Animation")
    void AnimateSnakeGeneration();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Snake Generation|Animation")
    void StopAnimation();
#endif
    
    // Clear Functions
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Snake Generation|Debug")
    void ClearSnakePath();
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Snake Generation|Debug")  
    void ClearDebugVisualization();
    
    UFUNCTION(BlueprintCallable, Category = "Snake Generation|Debug")
    void AutoClearDebugAfterGeneration();
    
    // Auto-clear properties
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Snake Generation|Debug")
    bool bAutoClearDebugAfterGeneration = true;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Snake Generation|Debug")
    float DebugAutoClearDelay = 3.0f; // Seconds before auto-clear
    
    // Generation State
    UPROPERTY(BlueprintReadOnly, Category = "Generation State")
    EGenerationPhase CurrentGenerationPhase = EGenerationPhase::Idle;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|Animation", meta=(ClampMin="0.01", ClampMax="1.0"))
    float PathStepDelay = 0.1f;  // Delay between path steps
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|Animation", meta=(ClampMin="0.01", ClampMax="1.0"))
    float CubeSpawnDelay = 0.05f;  // Delay between cube spawns
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|Animation", meta=(ClampMin="0.01", ClampMax="1.0"))
    float PlaneSpawnDelay = 0.05f;  // Delay between plane spawns
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|Animation")
    bool bAnimateGeneration = true;  // Toggle for animated vs instant generation
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|Animation")
    bool bGenerationPaused = false;  // Animation pause state
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation|Validation")
    bool bAutoValidateSpacing = true;  // Auto-validate room spacing after generation

#if WITH_EDITORONLY_DATA
    // Legacy animation property for backwards compatibility
    UPROPERTY(EditAnywhere, Category = "Snake Generation|Animation", meta = (ClampMin = "0.1", ClampMax = "2.0"))
    float AnimationStepDelay = 0.5f;
    
    UPROPERTY(EditAnywhere, Category = "Snake Generation|Visualization")
    bool bShowPathNumbers = true;
    
    UPROPERTY(EditAnywhere, Category = "Snake Generation|Visualization")
    bool bShowRoomConnections = true;
    
    UPROPERTY(EditAnywhere, Category = "Snake Generation|Visualization")
    bool bHighlightCurrentStep = true;
    
    UPROPERTY(EditAnywhere, Category = "Snake Generation|Visualization")
    FLinearColor PathColor = FLinearColor::Green;
    
    UPROPERTY(EditAnywhere, Category = "Snake Generation|Visualization")
    FLinearColor StartColor = FLinearColor::Blue;
    
    UPROPERTY(EditAnywhere, Category = "Snake Generation|Visualization")
    FLinearColor EndColor = FLinearColor::Red;
    
    UPROPERTY(EditAnywhere, Category = "Snake Generation|Visualization")
    bool bAutoGenerateOnChange = false;
    
    // Room Generation Validation
    UPROPERTY(EditAnywhere, Category = "Room Generation")
    int32 RoomSpacing = 4; // Spacing between room centers (3 room + 1 gap)
    
    UFUNCTION(BlueprintCallable, CallInEditor, Category = "Room Generation")
    bool ValidateRoomSpacing(const TArray<FIntPoint>& Path);
    
    UFUNCTION(CallInEditor, Category = "Grid Layout",
        meta = (DisplayName = "Calculate Grid Size"))
    void CalculateGridSizeInEditor();
#endif
    
    // Timer handles for animation phases
    FTimerHandle PathAnimationTimer;
    FTimerHandle CubeSpawnTimer;
    FTimerHandle PlaneSpawnTimer;
    
    // Animation tracking
    int32 CurrentPathStep = 0;
    int32 CurrentCubeIndex = 0;
    int32 CurrentPlaneIndex = 0;
    TArray<FTransform> PendingCubeTransforms;
    TArray<FTransform> PendingPlaneTransforms;

#if WITH_EDITOR
private:
    // Legacy animation state for backwards compatibility
    int32 CurrentGenerationStep = 0;
    TArray<FIntPoint> AnimationPath;
    FTimerHandle AnimationTimerHandle;
    
    // Editor helper functions
    void AnimationStep();
    void SpawnSingleRoomVisualization(FIntPoint RoomPos, int32 StepIndex);
    void DrawRoomDebugInfo(FIntPoint RoomPos, int32 StepIndex);
    void OnAnimationComplete();
    
public:
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
    
    // Mixed Room Validation (public for testing)
    UFUNCTION(BlueprintCallable, Category = "Mixed Room Validation")
    bool ValidateMixedRoomSpacing();
    
    UFUNCTION(BlueprintPure, Category = "Mixed Room Validation")
    float CalculateRequiredDistance(ERoomSizeType Room1Size, ERoomSizeType Room2Size) const;
    
    // Debug Settings
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
    bool bShowDebugGrid = false;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
    bool bShowCellCoordinates = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
    bool bShowRoomBoundaries = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
    FLinearColor RoomBoundaryColor = FLinearColor::Yellow;
    
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
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    TArray<FGridRoomInfo> RoomInfoList;

private:
    void InitializeComponents();
    void InitializeGrid();
    void SpawnGridVisualization();
    int32 GridIndexFromXY(int32 X, int32 Y) const;
    void GenerateSimpleLayout();
    
    // New Animated Generation System
    void StartAnimatedGeneration();
    void AnimatePathStep();
    void TransitionToCubeSpawning();
    void AnimateCubeSpawn();
    void TransitionToPlaneSpawning();
    void AnimatePlaneSpawn();
    void OnGenerationComplete();
    void DrawPathVisualization(FIntPoint RoomPos, int32 StepIndex);
    void PrepareCubeTransforms();
    void PreparePlaneTransforms();
    void PrepareVisualizationData();
    
    // Snake Generation Helper Functions (EXACTLY 25 ROOMS WITH PERFECT SPACING)
    TArray<FIntPoint> GenerateSnakePath(FIntPoint Start);
    FIntPoint FindNextPositionForPath(FIntPoint Current, const TSet<FIntPoint>& Visited, int32 PathIndex);
    bool IsValidRoomPosition(FIntPoint Pos, int32 RoomSize, const TSet<FIntPoint>& Visited);
    bool CheckRoomSpacing(FIntPoint NewPos, int32 NewSize, FIntPoint ExistingPos);
    bool BacktrackPath(TArray<FIntPoint>& Path, TSet<FIntPoint>& Visited);
    bool IsValidMove(int32 X, int32 Y, const TSet<FIntPoint>& Visited);
    bool IsValidMoveForVariableRooms(FIntPoint NewPos, int32 PathIndex, const TSet<FIntPoint>& Visited);
    void MarkPathInGrid(const TArray<FIntPoint>& Path);
    
    // Variable Room Size Helper Functions
    void Mark3x3RoomInGrid(FIntPoint RoomCenter, EGridCellType CellType = EGridCellType::Floor);
    void Mark2x2RoomInGrid(FIntPoint RoomCenter, EGridCellType CellType = EGridCellType::Floor);
    bool IsValid3x3RoomPosition(FIntPoint RoomCenter) const;
    bool IsValid2x2RoomPosition(FIntPoint RoomCenter) const;
    bool DoesRoomOverlap(FIntPoint Room1Center, FIntPoint Room2Center) const;
};