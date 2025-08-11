// SnakeDungeonVisualizer.h - Visual debugging tool for SnakePathGenerator backend
// Provides real-time visualization of snake path generation with debug capabilities
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"
#include "SnakePathGenerator.h"
#include "SnakeDungeonVisualizer.generated.h"

/**
 * Visual debugging actor for SnakePathGenerator backend.
 * 
 * This actor provides real-time visualization of the snake path generation algorithm:
 * - Spawns debug boxes for each room with color coding
 * - Draws path connections between rooms  
 * - Displays room indices and generation statistics
 * - Editor-friendly with regeneration controls
 * 
 * Color Coding:
 * - START room: Green
 * - END room: Red  
 * - Regular rooms: Blue
 * 
 * Features:
 * - Real-time regeneration with different seeds
 * - Configurable visualization scale and grid size
 * - Debug output with generation statistics
 * - Editor properties for easy testing
 */
UCLASS(BlueprintType, Blueprintable)
class ETERNALDESCENT_API ASnakeDungeonVisualizer : public AActor
{
    GENERATED_BODY()

public:
    ASnakeDungeonVisualizer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
    virtual void BeginPlay() override;
    virtual void OnConstruction(const FTransform& Transform) override;

public:
    // === EDITOR PROPERTIES ===
    
    /** Random seed for generation (-1 for random) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation", meta = (ClampMin = "-1"))
    int32 RandomSeed = -1;
    
    /** Grid size X dimension */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation", meta = (ClampMin = "30", ClampMax = "60"))
    int32 GridSizeX = 45;
    
    /** Grid size Y dimension */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation", meta = (ClampMin = "30", ClampMax = "60"))
    int32 GridSizeY = 45;
    
    /** Scale multiplier for visualization */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visualization", meta = (ClampMin = "0.1", ClampMax = "10.0"))
    float VisualizationScale = 100.0f;
    
    /** Auto-calculate grid size based on room count */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation")
    bool bAutoCalculateGridSize = true;
    
    /** Enable verbose logging during generation */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
    bool bVerboseLogging = false;
    
    /** Show room indices as text */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visualization")
    bool bShowRoomIndices = true;
    
    /** Show path connections between rooms */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visualization")
    bool bShowPathConnections = true;
    
    /** Show generation statistics */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
    bool bShowGenerationStats = true;
    
    /** Regenerate dungeon on property change */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
    bool bAutoRegenerate = true;
    
    // === VISUALIZATION PROPERTIES ===
    
    /** Material for START room (Green) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
    TSoftObjectPtr<UMaterialInterface> StartRoomMaterial;
    
    /** Material for END room (Red) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
    TSoftObjectPtr<UMaterialInterface> EndRoomMaterial;
    
    /** Material for regular rooms (Blue) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
    TSoftObjectPtr<UMaterialInterface> RegularRoomMaterial;
    
    /** Static mesh for room visualization */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meshes")
    TSoftObjectPtr<UStaticMesh> RoomMesh;

    // === GENERATION FUNCTIONS ===
    
    /** Generate and visualize a new dungeon */
    UFUNCTION(BlueprintCallable, Category = "Generation")
    void GenerateAndVisualize();
    
    /** Clear all current visualization */
    UFUNCTION(BlueprintCallable, Category = "Visualization")
    void ClearVisualization();
    
    /** Regenerate with a new random seed */
    UFUNCTION(BlueprintCallable, Category = "Generation", meta = (CallInEditor = "true"))
    void RegenerateWithNewSeed();
    
    /** Get the current generation result */
    UFUNCTION(BlueprintPure, Category = "Generation")
    FSnakeGenerationResult GetCurrentResult() const { return CurrentResult; }

protected:
    // === INTERNAL COMPONENTS ===
    
    /** Root scene component */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<USceneComponent> RootSceneComponent;
    
    /** Snake path generator instance */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    TObjectPtr<USnakePathGenerator> PathGenerator;

    // === VISUALIZATION MANAGEMENT ===
    
    /** Array of spawned room visualization components */
    UPROPERTY()
    TArray<TObjectPtr<UStaticMeshComponent>> RoomComponents;
    
    /** Current generation result */
    UPROPERTY(BlueprintReadOnly, Category = "Debug")
    FSnakeGenerationResult CurrentResult;
    
    // === VISUALIZATION FUNCTIONS ===
    
    /** Create visualization for all rooms */
    void CreateRoomVisualization();
    
    /** Create a single room visualization component */
    UStaticMeshComponent* CreateRoomComponent(const FSnakeRoomData& RoomData);
    
    /** Get the appropriate material for a room type */
    UMaterialInterface* GetMaterialForRoom(const FSnakeRoomData& RoomData);
    
    /** Convert grid coordinates to world position */
    FVector GridToWorldPosition(const FIntPoint& GridPos) const;
    
    /** Draw debug lines for path connections */
    void DrawPathConnections();
    
    /** Draw debug text for room indices */
    void DrawRoomIndices();
    
    /** Log generation statistics to output */
    void LogGenerationStatistics();
    
    /** Initialize default materials and meshes */
    void InitializeDefaults();
    
    /** Validate that required assets are loaded */
    bool ValidateAssets();

#if WITH_EDITOR
    /** Editor-only function for property changes */
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
};