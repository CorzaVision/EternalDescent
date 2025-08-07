// CubeDungeonGenerator.h
// Cube-based dungeon generator with plane-defined rooms

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeDungeonTypes.h"
#include "Tests/DungeonTestTypes.h"
#include "CubeDungeonGenerator.generated.h"

DECLARE_DELEGATE_OneParam(FOnCubeDungeonGenerated, const FCubeDungeonLayout&);

UCLASS()
class ETERNALDESCENT_API ACubeDungeonGenerator : public AActor
{
    GENERATED_BODY()
    
public:
    ACubeDungeonGenerator();
    
    // Core generation
    UFUNCTION(BlueprintCallable, Category = "Cube Dungeon")
    FCubeDungeonLayout GenerateCubeDungeon(int32 FloorNumber, const FIntVector& Dimensions);
    
    // Async generation
    void GenerateCubeDungeonAsync(int32 FloorNumber, const FIntVector& Dimensions, FOnCubeDungeonGenerated OnComplete);
    
    // Configuration
    UFUNCTION(BlueprintCallable, Category = "Cube Dungeon")
    void SetCubeSize(float Size) { CubeSize = Size; }
    
    UFUNCTION(BlueprintCallable, Category = "Cube Dungeon")
    float GetCubeSize() const { return CubeSize; }
    
protected:
    virtual void BeginPlay() override;
    
private:
    // Generation parameters
    UPROPERTY(EditAnywhere, Category = "Cube Settings")
    float CubeSize = 100.0f; // Size of each cube in world units
    
    UPROPERTY(EditAnywhere, Category = "Generation")
    float RoomDensity = 0.3f; // Percentage of grid to fill with rooms
    
    UPROPERTY(EditAnywhere, Category = "Generation")
    int32 MinRoomSize = 3; // Minimum cubes per room dimension
    
    UPROPERTY(EditAnywhere, Category = "Generation")
    int32 MaxRoomSize = 10; // Maximum cubes per room dimension
    
    // Generation pipeline
    void InitializeCubeGrid(FCubeDungeonLayout& Layout);
    void GenerateRoomClusters(FCubeDungeonLayout& Layout);
    void CarveRooms(FCubeDungeonLayout& Layout);
    void AssignPlanes(FCubeDungeonLayout& Layout);
    void ConnectRooms(FCubeDungeonLayout& Layout);
    void OptimizeCubeData(FCubeDungeonLayout& Layout);
    
    // Room generation algorithms
    void GenerateBoxRoom(FCubeDungeonLayout& Layout, const FIntVector& Origin, const FIntVector& Size, int32 RoomID);
    void GenerateLShapedRoom(FCubeDungeonLayout& Layout, const FIntVector& Origin, int32 RoomID);
    void GenerateCorridors(FCubeDungeonLayout& Layout);
    
    // Plane assignment
    void UpdatePlaneBetweenCubes(FCubeDungeonLayout& Layout, const FIntVector& Cube1, const FIntVector& Cube2);
    void SetPlaneType(FDungeonCube& Cube, EDungeonCubeFace Face, EPlaneType Type, bool bIsRoomBoundary);
    
    // Room clustering
    void ClusterAdjacentCubes(FCubeDungeonLayout& Layout);
    int32 FloodFillRoom(FCubeDungeonLayout& Layout, const FIntVector& Start, int32 RoomID);
    
    // Connectivity
    bool CreateConnection(FCubeDungeonLayout& Layout, int32 Room1ID, int32 Room2ID);
    TArray<FIntVector> FindPath(FCubeDungeonLayout& Layout, const FIntVector& Start, const FIntVector& End);
    
    // Optimization
    void RemoveUnusedCubes(FCubeDungeonLayout& Layout);
    void MergePlanes(FCubeDungeonLayout& Layout);
    
    // Helpers
    EDungeonCubeFace GetFaceBetween(const FIntVector& From, const FIntVector& To) const;
    EDungeonCubeFace GetOppositeFace(EDungeonCubeFace Face) const;
    bool AreCubesAdjacent(const FIntVector& Cube1, const FIntVector& Cube2) const;
};