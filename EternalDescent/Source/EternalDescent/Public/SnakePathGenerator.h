// SnakePathGenerator.h - Standalone snake path generation algorithm for dungeon generation
// Pure generation logic with no visual dependencies - Performance Target: 16ms per floor
#pragma once

#include "CoreMinimal.h"
#include "Math/IntPoint.h"
#include "SnakePathGenerator.generated.h"

UENUM(BlueprintType)
enum class ESnakeRoomSize : uint8
{
    None = 0        UMETA(DisplayName = "None"),
    Small_2x2 = 2   UMETA(DisplayName = "2x2 Room"),
    Standard_3x3 = 3 UMETA(DisplayName = "3x3 Room")
};

USTRUCT(BlueprintType)
struct FSnakeRoomData
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    FIntPoint Center = FIntPoint::ZeroValue;
    
    UPROPERTY(BlueprintReadWrite)
    ESnakeRoomSize RoomSize = ESnakeRoomSize::Standard_3x3;
    
    UPROPERTY(BlueprintReadWrite)
    bool bIsStartRoom = false;
    
    UPROPERTY(BlueprintReadWrite)
    bool bIsEndRoom = false;
    
    UPROPERTY(BlueprintReadWrite)
    int32 PathIndex = -1; // Position in the path sequence (0 = start)
    
    FSnakeRoomData()
    {
        Center = FIntPoint::ZeroValue;
        RoomSize = ESnakeRoomSize::Standard_3x3;
        bIsStartRoom = false;
        bIsEndRoom = false;
        PathIndex = -1;
    }
    
    FSnakeRoomData(FIntPoint InCenter, ESnakeRoomSize InSize, bool bIsStart = false, bool bIsEnd = false, int32 InPathIndex = -1)
        : Center(InCenter), RoomSize(InSize), bIsStartRoom(bIsStart), bIsEndRoom(bIsEnd), PathIndex(InPathIndex)
    {
    }
};

USTRUCT(BlueprintType)
struct FSnakeGenerationResult
{
    GENERATED_BODY()
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FSnakeRoomData> Rooms;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FIntPoint> PathSequence; // Room centers in path order
    
    UPROPERTY(BlueprintReadWrite)
    bool bGenerationSuccessful = false;
    
    UPROPERTY(BlueprintReadWrite)
    int32 GenerationTimeMs = 0;
    
    UPROPERTY(BlueprintReadWrite)
    int32 RetryCount = 0;
    
    UPROPERTY(BlueprintReadWrite)
    int32 BacktrackCount = 0;
    
    UPROPERTY(BlueprintReadWrite)
    FString FailureReason = TEXT("");
    
    // Grid dimensions used for generation
    UPROPERTY(BlueprintReadWrite)
    int32 GridSizeX = 0;
    
    UPROPERTY(BlueprintReadWrite)
    int32 GridSizeY = 0;
    
    FSnakeGenerationResult()
    {
        Rooms.Empty();
        PathSequence.Empty();
        bGenerationSuccessful = false;
        GenerationTimeMs = 0;
        RetryCount = 0;
        BacktrackCount = 0;
        FailureReason = TEXT("");
        GridSizeX = 0;
        GridSizeY = 0;
    }
};

USTRUCT(BlueprintType)
struct FSnakeGenerationConfig
{
    GENERATED_BODY()
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="25", ClampMax="1000"))
    int32 RequiredRoomCount = 25; // Default 25 rooms, configurable for limits testing
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="30", ClampMax="1000"))
    int32 GridSizeX = 45; // Grid width
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="30", ClampMax="1000"))
    int32 GridSizeY = 45; // Grid height
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="1", ClampMax="1"))
    int32 RoomGap = 1; // Exactly 1 cell gap between rooms
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="100", ClampMax="5000"))
    int32 MaxRetries = 3000; // Maximum generation attempts
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin="1", ClampMax="20"))
    int32 MaxBacktrackDepth = 8; // Maximum consecutive backtracks before restart
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bAutoCalculateGridSize = true; // Auto-size grid based on room count
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bVerboseLogging = false; // Enable detailed generation logs
    
    FSnakeGenerationConfig()
    {
        RequiredRoomCount = 25;
        GridSizeX = 45;
        GridSizeY = 45;
        RoomGap = 1;
        MaxRetries = 3000;
        MaxBacktrackDepth = 8;
        bAutoCalculateGridSize = true;
        bVerboseLogging = false;
    }
};

/**
 * Standalone snake path generation algorithm for dungeon generation.
 * 
 * This class contains ONLY the generation logic with no visual dependencies.
 * It generates exactly 25 rooms with proper spacing:
 * - START room: 2x2 at position (2,2)
 * - END room: 2x2 at final path position
 * - Regular rooms: 3x3 for all middle rooms
 * - Spacing: Exactly 1 cell gap between all rooms
 * 
 * Performance Target: 16ms per floor generation
 * 
 * Key Features:
 * - Pure algorithm with no Unreal visual components
 * - Robust backtracking and recovery logic
 * - Deadlock detection and prevention
 * - Configurable generation parameters
 * - Detailed generation statistics and failure reporting
 */
UCLASS(BlueprintType, Blueprintable)
class ETERNALDESCENT_API USnakePathGenerator : public UObject
{
    GENERATED_BODY()

public:
    USnakePathGenerator(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

    /**
     * Generate a complete snake path with exactly 25 rooms
     * @param Config - Generation configuration parameters
     * @param Seed - Random seed (-1 for random seed)
     * @return Complete generation result with room data and statistics
     */
    UFUNCTION(BlueprintCallable, Category = "Snake Generation")
    FSnakeGenerationResult GenerateSnakePath(const FSnakeGenerationConfig& Config, int32 Seed = -1);
    
    /**
     * Calculate optimal grid size for the given room count
     * @param RoomCount - Number of rooms to fit
     * @return Optimal grid dimensions as FIntPoint
     */
    UFUNCTION(BlueprintPure, Category = "Snake Generation")
    FIntPoint CalculateOptimalGridSize(int32 RoomCount) const;
    
    /**
     * Validate that a room configuration is valid
     * @param Rooms - Array of room data to validate
     * @param GridSizeX - Grid width
     * @param GridSizeY - Grid height
     * @return True if configuration is valid, false otherwise
     */
    UFUNCTION(BlueprintPure, Category = "Snake Generation")
    bool ValidateRoomConfiguration(const TArray<FSnakeRoomData>& Rooms, int32 GridSizeX, int32 GridSizeY) const;

protected:
    // Core Generation Algorithm
    TArray<FIntPoint> GeneratePathInternal(FIntPoint StartPos, const FSnakeGenerationConfig& Config);
    
    // Path Finding and Validation
    FIntPoint FindNextPositionForPath(FIntPoint Current, const TSet<FIntPoint>& Visited, int32 PathIndex, const FSnakeGenerationConfig& Config);
    bool IsValidRoomPosition(FIntPoint Pos, int32 RoomSize, const TSet<FIntPoint>& Visited, const FSnakeGenerationConfig& Config) const;
    bool CheckRoomSpacing(FIntPoint NewPos, int32 NewSize, FIntPoint ExistingPos, int32 ExistingSize, int32 RequiredGap) const;
    
    // Backtracking and Recovery
    bool BacktrackPath(TArray<FIntPoint>& Path, TSet<FIntPoint>& Visited, int32 RequiredRoomCount, int32& BacktrackCount);
    
    // Room Size Logic
    ESnakeRoomSize GetRoomSizeForPathIndex(int32 PathIndex, int32 TotalRooms) const;
    int32 GetRoomSizeValue(ESnakeRoomSize RoomSize) const;
    int32 GetRoomRadius(int32 RoomSize) const;
    
    // Boundary and Grid Validation
    bool IsPositionInBounds(FIntPoint Pos, int32 RoomSize, int32 GridSizeX, int32 GridSizeY) const;
    bool DoesRoomFitInGrid(FIntPoint Center, int32 RoomSize, int32 GridSizeX, int32 GridSizeY) const;
    
    // Move Selection Strategies
    FIntPoint SelectBestMove(const TArray<FIntPoint>& PossibleMoves, FIntPoint Current, int32 PathIndex, int32 RequiredRoomCount) const;
    TArray<int32> GetStepSizesForRoomTransition(int32 CurrentRoomSize, int32 NextRoomSize) const;
    
    // Statistics and Logging
    void LogGenerationProgress(int32 CurrentRooms, int32 RequiredRooms, int32 RetryCount) const;
    void LogBacktrackAttempt(int32 PathLength, int32 BacktrackDepth) const;
    void LogGenerationComplete(const FSnakeGenerationResult& Result) const;

private:
    // Generation state tracking
    int32 CurrentRetryCount = 0;
    int32 CurrentBacktrackCount = 0;
    double GenerationStartTime = 0.0;
    bool bVerboseLogging = false;
    
    // Constants for room placement
    static constexpr int32 ROOM_SIZE_2x2 = 2;
    static constexpr int32 ROOM_SIZE_3x3 = 3;
    static constexpr int32 DEFAULT_START_X = 2;
    static constexpr int32 DEFAULT_START_Y = 2;
    static constexpr int32 MIN_GRID_SIZE = 30;
    static constexpr int32 MAX_GRID_SIZE = 1000;
};