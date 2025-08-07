// CubeDungeonTypes.h
// Cube-based dungeon generation with plane-defined rooms

#pragma once

#include "CoreMinimal.h"
#include "Tests/DungeonTestTypes.h"
#include "CubeDungeonTypes.generated.h"

// Each face of a cube can be a plane type
UENUM(BlueprintType)
enum class EPlaneType : uint8
{
    Solid       UMETA(DisplayName = "Solid Wall"),
    Open        UMETA(DisplayName = "Open Space"),
    Door        UMETA(DisplayName = "Door"),
    Window      UMETA(DisplayName = "Window"),
    Transparent UMETA(DisplayName = "Transparent"),
    Destructible UMETA(DisplayName = "Destructible")
};

UENUM(BlueprintType)
enum class ECubeType : uint8
{
    Empty       UMETA(DisplayName = "Empty Space"),
    Solid       UMETA(DisplayName = "Solid Block"),
    Floor       UMETA(DisplayName = "Floor"),
    Wall        UMETA(DisplayName = "Wall"),
    Ceiling     UMETA(DisplayName = "Ceiling"),
    Pillar      UMETA(DisplayName = "Pillar"),
    Stairs      UMETA(DisplayName = "Stairs"),
    Special     UMETA(DisplayName = "Special")
};

UENUM(BlueprintType)
enum class EDungeonCubeFace : uint8
{
    Top         UMETA(DisplayName = "Top +Z"),
    Bottom      UMETA(DisplayName = "Bottom -Z"),
    North       UMETA(DisplayName = "North +Y"),
    South       UMETA(DisplayName = "South -Y"),
    East        UMETA(DisplayName = "East +X"),
    West        UMETA(DisplayName = "West -X")
};

// Single plane definition on a cube face
USTRUCT(BlueprintType)
struct FCubePlane
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    EPlaneType Type;
    
    UPROPERTY(BlueprintReadWrite)
    EDungeonCubeFace Face;
    
    UPROPERTY(BlueprintReadWrite)
    int32 MaterialIndex;
    
    UPROPERTY(BlueprintReadWrite)
    bool bIsRoomBoundary;
    
    UPROPERTY(BlueprintReadWrite)
    int32 RoomID;
    
    FCubePlane()
    {
        Type = EPlaneType::Solid;
        Face = EDungeonCubeFace::North;
        MaterialIndex = 0;
        bIsRoomBoundary = false;
        RoomID = -1;
    }
};

// Single cube in the dungeon grid
USTRUCT(BlueprintType)
struct FDungeonCube
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    FIntVector GridPosition;
    
    UPROPERTY(BlueprintReadWrite)
    ECubeType Type;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FCubePlane> Planes;
    
    UPROPERTY(BlueprintReadWrite)
    int32 RoomID;
    
    UPROPERTY(BlueprintReadWrite)
    bool bIsOccupied;
    
    UPROPERTY(BlueprintReadWrite)
    float EntityInfluence;
    
    // Get plane for specific face
    FCubePlane* GetPlane(EDungeonCubeFace Face)
    {
        for (FCubePlane& Plane : Planes)
        {
            if (Plane.Face == Face)
            {
                return &Plane;
            }
        }
        return nullptr;
    }
    
    FDungeonCube()
    {
        GridPosition = FIntVector::ZeroValue;
        Type = ECubeType::Empty;
        RoomID = -1;
        bIsOccupied = false;
        EntityInfluence = 0.0f;
        
        // Initialize with 6 planes (one per face)
        Planes.Reserve(6);
        for (int32 i = 0; i < 6; ++i)
        {
            FCubePlane Plane;
            Plane.Face = (EDungeonCubeFace)i;
            Planes.Add(Plane);
        }
    }
};

// Collection of cubes forming a room
USTRUCT(BlueprintType)
struct FCubeRoom
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    int32 RoomID;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FIntVector> CubePositions;
    
    UPROPERTY(BlueprintReadWrite)
    FIntVector MinBounds;
    
    UPROPERTY(BlueprintReadWrite)
    FIntVector MaxBounds;
    
    UPROPERTY(BlueprintReadWrite)
    ERoomType RoomType;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<int32> ConnectedRoomIDs;
    
    // Calculate room from cube positions
    void CalculateBounds()
    {
        if (CubePositions.Num() == 0) return;
        
        MinBounds = CubePositions[0];
        MaxBounds = CubePositions[0];
        
        for (const FIntVector& Pos : CubePositions)
        {
            MinBounds.X = FMath::Min(MinBounds.X, Pos.X);
            MinBounds.Y = FMath::Min(MinBounds.Y, Pos.Y);
            MinBounds.Z = FMath::Min(MinBounds.Z, Pos.Z);
            
            MaxBounds.X = FMath::Max(MaxBounds.X, Pos.X);
            MaxBounds.Y = FMath::Max(MaxBounds.Y, Pos.Y);
            MaxBounds.Z = FMath::Max(MaxBounds.Z, Pos.Z);
        }
    }
    
    FIntVector GetSize() const
    {
        return MaxBounds - MinBounds + FIntVector(1, 1, 1);
    }
    
    int32 GetVolume() const
    {
        FIntVector Size = GetSize();
        return Size.X * Size.Y * Size.Z;
    }
    
    FCubeRoom()
    {
        RoomID = -1;
        MinBounds = FIntVector::ZeroValue;
        MaxBounds = FIntVector::ZeroValue;
        RoomType = ERoomType::Empty;
    }
};

// Cube-based dungeon layout
USTRUCT(BlueprintType)
struct FCubeDungeonLayout
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    int32 FloorNumber;
    
    // 3D grid of cubes
    UPROPERTY(BlueprintReadWrite)
    TMap<FIntVector, FDungeonCube> CubeGrid;
    
    // Rooms formed by adjacent cubes
    UPROPERTY(BlueprintReadWrite)
    TMap<int32, FCubeRoom> Rooms;
    
    UPROPERTY(BlueprintReadWrite)
    FIntVector GridDimensions;
    
    UPROPERTY(BlueprintReadWrite)
    int32 TotalCubes;
    
    UPROPERTY(BlueprintReadWrite)
    int32 OccupiedCubes;
    
    UPROPERTY(BlueprintReadWrite)
    float GenerationTime;
    
    // Helper functions
    FDungeonCube* GetCube(const FIntVector& Position)
    {
        return CubeGrid.Find(Position);
    }
    
    bool IsValidPosition(const FIntVector& Position) const
    {
        return Position.X >= 0 && Position.X < GridDimensions.X &&
               Position.Y >= 0 && Position.Y < GridDimensions.Y &&
               Position.Z >= 0 && Position.Z < GridDimensions.Z;
    }
    
    // Get adjacent cube positions
    TArray<FIntVector> GetAdjacentPositions(const FIntVector& Position) const
    {
        TArray<FIntVector> Adjacent;
        Adjacent.Reserve(6);
        
        // 6 face neighbors
        Adjacent.Add(Position + FIntVector(1, 0, 0));   // East
        Adjacent.Add(Position + FIntVector(-1, 0, 0));  // West
        Adjacent.Add(Position + FIntVector(0, 1, 0));   // North
        Adjacent.Add(Position + FIntVector(0, -1, 0));  // South
        Adjacent.Add(Position + FIntVector(0, 0, 1));   // Top
        Adjacent.Add(Position + FIntVector(0, 0, -1));  // Bottom
        
        // Filter valid positions
        Adjacent.RemoveAll([this](const FIntVector& Pos) 
        { 
            return !IsValidPosition(Pos); 
        });
        
        return Adjacent;
    }
    
    FCubeDungeonLayout()
    {
        FloorNumber = 1;
        GridDimensions = FIntVector(50, 50, 10); // Default 50x50x10 grid
        TotalCubes = 0;
        OccupiedCubes = 0;
        GenerationTime = 0.0f;
    }
};