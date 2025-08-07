// DungeonTestTypes.h
// Test data structures and types for dungeon generation testing

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DungeonTestTypes.generated.h"

UENUM(BlueprintType)
enum class EDungeonZone : uint8
{
    None            UMETA(DisplayName = "None"),
    SunkenCrypt     UMETA(DisplayName = "Sunken Crypt"),
    BlightedForest  UMETA(DisplayName = "Blighted Forest"),
    FrozenFortress  UMETA(DisplayName = "Frozen Fortress")
};

UENUM(BlueprintType)
enum class ERoomType : uint8
{
    Empty           UMETA(DisplayName = "Empty"),
    Standard        UMETA(DisplayName = "Standard"),    // Basic combat room
    Combat          UMETA(DisplayName = "Combat"),
    Elite           UMETA(DisplayName = "Elite"),       // Harder combat room
    Treasure        UMETA(DisplayName = "Treasure"),
    Shop            UMETA(DisplayName = "Shop"),        // Merchant room
    Puzzle          UMETA(DisplayName = "Puzzle"),
    Rest            UMETA(DisplayName = "Rest"),
    Boss            UMETA(DisplayName = "Boss"),
    Start           UMETA(DisplayName = "Start Room"),  // Explicitly marked start
    Exit            UMETA(DisplayName = "Exit Room"),   // Explicitly marked exit (extraction)
    Extraction      UMETA(DisplayName = "Extraction"),  // Legacy support
    Hallway         UMETA(DisplayName = "Hallway")
};

UENUM(BlueprintType)
enum class EEntityPersonality : uint8
{
    Observer        UMETA(DisplayName = "The Observer"),
    Challenger      UMETA(DisplayName = "The Challenger"),
    Counter         UMETA(DisplayName = "The Counter"),
    Architect       UMETA(DisplayName = "The Architect"),
    Historian       UMETA(DisplayName = "The Historian"),
    Prophet         UMETA(DisplayName = "The Prophet")
};

USTRUCT(BlueprintType)
struct FRoomData
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    FIntVector GridPosition;
    
    UPROPERTY(BlueprintReadWrite)
    ERoomType RoomType;
    
    UPROPERTY(BlueprintReadWrite)
    EDungeonZone ZoneType;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FIntVector> Connections;
    
    UPROPERTY(BlueprintReadWrite)
    float DifficultyModifier;
    
    UPROPERTY(BlueprintReadWrite)
    float EntityInfluence;
    
    FRoomData()
    {
        GridPosition = FIntVector::ZeroValue;
        RoomType = ERoomType::Standard;
        ZoneType = EDungeonZone::None;
        DifficultyModifier = 1.0f;
        EntityInfluence = 0.0f;
    }
};

USTRUCT(BlueprintType)
struct FDungeonLayout
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    int32 FloorNumber;
    
    UPROPERTY(BlueprintReadWrite)
    TMap<FIntVector, FRoomData> Rooms;
    
    UPROPERTY(BlueprintReadWrite)
    FIntVector SpawnRoom;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FIntVector> ExtractionPoints;
    
    UPROPERTY(BlueprintReadWrite)
    EDungeonZone CurrentZone;
    
    UPROPERTY(BlueprintReadWrite)
    float GenerationTime;
    
    FRoomData* GetRoom(const FIntVector& Position)
    {
        return Rooms.Find(Position);
    }
    
    const FRoomData* GetRoom(const FIntVector& Position) const
    {
        return Rooms.Find(Position);
    }
    
    FDungeonLayout()
    {
        FloorNumber = 1;
        SpawnRoom = FIntVector::ZeroValue;
        CurrentZone = EDungeonZone::None;
        GenerationTime = 0.0f;
    }
};

USTRUCT(BlueprintType)
struct FEntityProfile
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    TMap<FString, float> PlayerPatterns;
    
    UPROPERTY(BlueprintReadWrite)
    EEntityPersonality CurrentMood;
    
    UPROPERTY(BlueprintReadWrite)
    float AdaptationLevel;
    
    UPROPERTY(BlueprintReadWrite)
    int32 RunCount;
    
    FEntityProfile()
    {
        CurrentMood = EEntityPersonality::Observer;
        AdaptationLevel = 0.0f;
        RunCount = 0;
    }
};