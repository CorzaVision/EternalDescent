// DungeonVisualizer.h - Frontend visualization for procedural dungeons
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakeDungeonGenerator.h"
#include "ADASystem.h"
#include "Engine/StaticMesh.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "DungeonVisualizer.generated.h"

USTRUCT(BlueprintType)
struct FRoomMeshSet
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meshes")
    UStaticMesh* FloorMesh;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meshes")
    UStaticMesh* WallMesh;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meshes")
    UStaticMesh* CeilingMesh;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meshes")
    UStaticMesh* DoorFrameMesh;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meshes")
    UStaticMesh* PillarMesh;
};

USTRUCT(BlueprintType)
struct FRoomVisualData
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    int32 RoomID;
    
    UPROPERTY(BlueprintReadWrite)
    FVector WorldPosition;
    
    UPROPERTY(BlueprintReadWrite)
    FVector RoomSize;
    
    UPROPERTY(BlueprintReadWrite)
    ERoomType RoomType;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<AActor*> SpawnedActors;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<int32> ConnectedRoomIDs;
};

UCLASS(BlueprintType, Blueprintable)
class ETERNALDESCENT_API ADungeonVisualizer : public AActor
{
    GENERATED_BODY()

public:
    ADungeonVisualizer();

protected:
    virtual void BeginPlay() override;

public:
    // Core Generation Functions
    UFUNCTION(BlueprintCallable, Category = "Dungeon|Generation")
    void GenerateAndVisualizeDungeon(int32 Seed = -1);
    
    UFUNCTION(BlueprintCallable, Category = "Dungeon|Generation")
    void VisualizeDungeonLayout(const FDungeonLayout& Layout);
    
    UFUNCTION(BlueprintCallable, Category = "Dungeon|Generation")
    void ClearDungeon();
    
    // Room Spawning Functions
    UFUNCTION(BlueprintCallable, Category = "Dungeon|Rooms")
    void SpawnRoom(const FRoomData& RoomData);
    
    UFUNCTION(BlueprintCallable, Category = "Dungeon|Rooms")
    void SpawnRoomMeshes(const FRoomVisualData& RoomVisual);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Dungeon|Rooms")
    void OnRoomSpawned(const FRoomVisualData& RoomData);
    
    // Hallway Functions
    UFUNCTION(BlueprintCallable, Category = "Dungeon|Hallways")
    void SpawnHallway(const FHallwayConnection& Hallway);
    
    UFUNCTION(BlueprintCallable, Category = "Dungeon|Hallways")
    void CreateHallwayPath(FVector StartPos, FVector EndPos);
    
    // Door System
    UFUNCTION(BlueprintCallable, Category = "Dungeon|Doors")
    void SpawnDoor(FVector Position, FRotator Rotation, bool bIsLocked = false);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Dungeon|Doors")
    void OnDoorSpawned(FVector Position, bool bIsLocked);
    
    // Player Functions
    UFUNCTION(BlueprintCallable, Category = "Dungeon|Player")
    void SpawnPlayerAtStart();
    
    UFUNCTION(BlueprintCallable, Category = "Dungeon|Player")
    FVector GetStartRoomPosition();
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Dungeon|Player")
    void OnPlayerSpawned(FVector SpawnPosition);
    
    // Enemy Spawning
    UFUNCTION(BlueprintCallable, Category = "Dungeon|Enemies")
    void SpawnEnemiesInRoom(const FRoomVisualData& Room);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Dungeon|Enemies")
    void OnEnemySpawned(FVector Position, const FString& EnemyType);
    
    // Loot & Items
    UFUNCTION(BlueprintCallable, Category = "Dungeon|Loot")
    void SpawnLootInRoom(const FRoomVisualData& Room);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Dungeon|Loot")
    void OnLootSpawned(FVector Position, const FString& LootType);
    
    // Visual Settings
    UFUNCTION(BlueprintCallable, Category = "Dungeon|Visuals")
    void SetRoomTheme(int32 FloorNumber);
    
    UFUNCTION(BlueprintCallable, Category = "Dungeon|Visuals")
    void ApplyLighting(const FRoomVisualData& Room);
    
    // Helper Functions
    UFUNCTION(BlueprintPure, Category = "Dungeon|Utility")
    FVector GridToWorldPosition(FIntPoint GridPos);
    
    UFUNCTION(BlueprintPure, Category = "Dungeon|Utility")
    FIntPoint WorldToGridPosition(FVector WorldPos);
    
    UFUNCTION(BlueprintCallable, Category = "Dungeon|Utility")
    FRoomVisualData GetRoomVisualData(int32 RoomID);
    
    // Properties
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dungeon|Settings")
    float CellSize = 100.0f; // Size of one grid cell in world units
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dungeon|Settings")
    float WallHeight = 400.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dungeon|Settings")
    float HallwayWidth = 300.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dungeon|Settings")
    bool bAutoGenerateOnBeginPlay = false;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dungeon|Settings")
    int32 CurrentFloor = 1;
    
    // Mesh Sets for Different Room Types
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dungeon|Meshes")
    FRoomMeshSet StandardRoomMeshes;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dungeon|Meshes")
    FRoomMeshSet TreasureRoomMeshes;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dungeon|Meshes")
    FRoomMeshSet ShopRoomMeshes;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dungeon|Meshes")
    FRoomMeshSet BossRoomMeshes;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dungeon|Meshes")
    UStaticMesh* HallwayFloorMesh;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dungeon|Meshes")
    UStaticMesh* HallwayWallMesh;
    
    // Blueprint Actor Classes
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dungeon|Classes")
    TSubclassOf<AActor> DoorActorClass;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dungeon|Classes")
    TSubclassOf<AActor> ChestActorClass;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dungeon|Classes")
    TSubclassOf<AActor> EnemySpawnerClass;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dungeon|Classes")
    TSubclassOf<AActor> InteractableClass;
    
    // Enemy Types per Floor
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dungeon|Enemies")
    TMap<FString, TSubclassOf<AActor>> EnemyClasses;
    
    // References
    UPROPERTY(BlueprintReadOnly, Category = "Dungeon|References")
    ASnakeDungeonGenerator* DungeonGenerator;
    
    UPROPERTY(BlueprintReadOnly, Category = "Dungeon|References")
    AADASystem* ADASystem;
    
    // Runtime Data
    UPROPERTY(BlueprintReadOnly, Category = "Dungeon|Runtime")
    TArray<FRoomVisualData> VisualizedRooms;
    
    UPROPERTY(BlueprintReadOnly, Category = "Dungeon|Runtime")
    FDungeonLayout CurrentLayout;
    
    UPROPERTY(BlueprintReadOnly, Category = "Dungeon|Runtime")
    TArray<AActor*> SpawnedDungeonActors;

private:
    // Instanced Mesh Components for Performance
    UPROPERTY()
    UInstancedStaticMeshComponent* FloorInstancedMesh;
    
    UPROPERTY()
    UInstancedStaticMeshComponent* WallInstancedMesh;
    
    UPROPERTY()
    UInstancedStaticMeshComponent* CeilingInstancedMesh;
    
    // Internal Functions
    void SpawnWallsForRoom(const FRoomVisualData& Room);
    void SpawnFloorForRoom(const FRoomVisualData& Room);
    void CalculateDoorPositions(const FRoomVisualData& Room, TArray<FVector>& OutDoorPositions);
    FRoomMeshSet GetMeshSetForRoomType(ERoomType Type);
    void InitializeInstancedMeshComponents();
};