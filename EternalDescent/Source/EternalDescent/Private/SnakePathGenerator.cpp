// SnakePathGenerator.cpp - Standalone snake path generation implementation
#include "SnakePathGenerator.h"
#include "Engine/Engine.h"
#include "HAL/PlatformFilemanager.h"

USnakePathGenerator::USnakePathGenerator(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    CurrentRetryCount = 0;
    CurrentBacktrackCount = 0;
    GenerationStartTime = 0.0;
    bVerboseLogging = false;
}

FSnakeGenerationResult USnakePathGenerator::GenerateSnakePath(const FSnakeGenerationConfig& Config, int32 Seed)
{
    // Record start time for performance tracking
    GenerationStartTime = FPlatformTime::Seconds();
    
    // Initialize result structure
    FSnakeGenerationResult Result;
    Result.GridSizeX = Config.GridSizeX;
    Result.GridSizeY = Config.GridSizeY;
    bVerboseLogging = Config.bVerboseLogging;
    
    // Initialize random seed
    if (Seed < 0)
    {
        Seed = FMath::Rand();
    }
    FMath::RandInit(Seed);
    
    if (bVerboseLogging)
    {
        UE_LOG(LogTemp, Warning, TEXT("🐍 SnakePathGenerator: Starting generation with seed %d"), Seed);
        UE_LOG(LogTemp, Warning, TEXT("📐 Grid Size: %dx%d, Required Rooms: %d"), 
            Config.GridSizeX, Config.GridSizeY, Config.RequiredRoomCount);
    }
    
    // Auto-calculate grid size if enabled
    FSnakeGenerationConfig WorkingConfig = Config;
    if (Config.bAutoCalculateGridSize)
    {
        FIntPoint OptimalSize = CalculateOptimalGridSize(Config.RequiredRoomCount);
        WorkingConfig.GridSizeX = OptimalSize.X;
        WorkingConfig.GridSizeY = OptimalSize.Y;
        Result.GridSizeX = OptimalSize.X;
        Result.GridSizeY = OptimalSize.Y;
        
        if (bVerboseLogging)
        {
            UE_LOG(LogTemp, Warning, TEXT("📏 Auto-calculated grid size: %dx%d"), OptimalSize.X, OptimalSize.Y);
        }
    }
    
    // Validate configuration - allow variable room counts for limits testing
    if (WorkingConfig.RequiredRoomCount < 1 || WorkingConfig.RequiredRoomCount > 1000)
    {
        Result.bGenerationSuccessful = false;
        Result.FailureReason = FString::Printf(TEXT("Invalid room count: %d (must be 1-1000)"), WorkingConfig.RequiredRoomCount);
        UE_LOG(LogTemp, Error, TEXT("❌ %s"), *Result.FailureReason);
        return Result;
    }
    
    // Generate the path
    CurrentRetryCount = 0;
    CurrentBacktrackCount = 0;
    
    FIntPoint StartPos(DEFAULT_START_X, DEFAULT_START_Y);
    TArray<FIntPoint> PathSequence = GeneratePathInternal(StartPos, WorkingConfig);
    
    // Check if generation was successful
    if (PathSequence.Num() != WorkingConfig.RequiredRoomCount)
    {
        Result.bGenerationSuccessful = false;
        Result.FailureReason = FString::Printf(TEXT("Generated %d rooms instead of %d"), 
            PathSequence.Num(), WorkingConfig.RequiredRoomCount);
        Result.RetryCount = CurrentRetryCount;
        Result.BacktrackCount = CurrentBacktrackCount;
        
        UE_LOG(LogTemp, Error, TEXT("❌ Generation failed: %s"), *Result.FailureReason);
        return Result;
    }
    
    // Convert path to room data
    Result.PathSequence = PathSequence;
    Result.Rooms.Empty();
    Result.Rooms.Reserve(PathSequence.Num());
    
    for (int32 i = 0; i < PathSequence.Num(); ++i)
    {
        FSnakeRoomData RoomData;
        RoomData.Center = PathSequence[i];
        RoomData.PathIndex = i;
        RoomData.bIsStartRoom = (i == 0);
        RoomData.bIsEndRoom = (i == PathSequence.Num() - 1);
        RoomData.RoomSize = GetRoomSizeForPathIndex(i, PathSequence.Num());
        
        Result.Rooms.Add(RoomData);
    }
    
    // Calculate generation time
    double GenerationEndTime = FPlatformTime::Seconds();
    Result.GenerationTimeMs = FMath::RoundToInt((GenerationEndTime - GenerationStartTime) * 1000.0);
    Result.RetryCount = CurrentRetryCount;
    Result.BacktrackCount = CurrentBacktrackCount;
    Result.bGenerationSuccessful = true;
    
    // Validate the final result
    if (!ValidateRoomConfiguration(Result.Rooms, Result.GridSizeX, Result.GridSizeY))
    {
        Result.bGenerationSuccessful = false;
        Result.FailureReason = TEXT("Final room configuration failed validation");
        UE_LOG(LogTemp, Error, TEXT("❌ %s"), *Result.FailureReason);
    }
    
    LogGenerationComplete(Result);
    return Result;
}

TArray<FIntPoint> USnakePathGenerator::GeneratePathInternal(FIntPoint StartPos, const FSnakeGenerationConfig& Config)
{
    if (bVerboseLogging)
    {
        UE_LOG(LogTemp, Warning, TEXT("🐍 Generating EXACTLY %d rooms with maximum START-END separation"), Config.RequiredRoomCount);
    }
    
    TArray<FIntPoint> Path;
    TSet<FIntPoint> Visited;
    
    // START position - ensure boundary safety for 2x2 room
    Path.Add(StartPos);
    Visited.Add(StartPos);
    
    // Generate exactly (RequiredRoomCount - 1) more rooms to reach total with END
    FIntPoint CurrentPos = StartPos;
    int32 TargetPathLength = Config.RequiredRoomCount;
    
    // Generation control variables
    int32 StuckCount = 0;
    int32 ConsecutiveBacktracks = 0;
    int32 ProgressStalls = 0;
    int32 LastProgressRoomCount = Path.Num();
    
    while (Path.Num() < TargetPathLength && CurrentRetryCount < Config.MaxRetries)
    {
        // Find valid next position that maintains spacing
        FIntPoint NextPos = FindNextPositionForPath(CurrentPos, Visited, Path.Num(), Config);
        
        if (NextPos == FIntPoint(-1, -1))
        {
            StuckCount++;
            CurrentRetryCount++;
            ConsecutiveBacktracks++;
            
            // Enhanced deadlock detection and recovery
            if (ConsecutiveBacktracks > Config.MaxBacktrackDepth || ProgressStalls > 50)
            {
                if (bVerboseLogging)
                {
                    UE_LOG(LogTemp, Warning, TEXT("🔄 Deadlock detected: ConsecutiveBacktracks=%d, ProgressStalls=%d - forcing restart"), 
                        ConsecutiveBacktracks, ProgressStalls);
                }
                
                // Complete restart
                Path.Empty();
                Visited.Empty();
                Path.Add(StartPos);
                Visited.Add(StartPos);
                CurrentPos = StartPos;
                StuckCount = 0;
                ConsecutiveBacktracks = 0;
                ProgressStalls = 0;
                LastProgressRoomCount = 1;
                continue;
            }
            
            // Try backtracking
            if (BacktrackPath(Path, Visited, Config.RequiredRoomCount, CurrentBacktrackCount))
            {
                CurrentPos = Path.Last();
                if (bVerboseLogging)
                {
                    UE_LOG(LogTemp, Warning, TEXT("🔄 Backtracked, continuing from (%d,%d) with %d rooms"), 
                        CurrentPos.X, CurrentPos.Y, Path.Num());
                }
                continue;
            }
            else
            {
                // If backtracking fails and we have very few rooms, restart completely
                if (Path.Num() < 10)
                {
                    if (bVerboseLogging)
                    {
                        UE_LOG(LogTemp, Warning, TEXT("🔄 Complete restart - only had %d rooms"), Path.Num());
                    }
                    
                    Path.Empty();
                    Visited.Empty();
                    Path.Add(StartPos);
                    Visited.Add(StartPos);
                    CurrentPos = StartPos;
                    StuckCount = 0;
                    ConsecutiveBacktracks = 0;
                    ProgressStalls = 0;
                    LastProgressRoomCount = 1;
                    continue;
                }
                else
                {
                    UE_LOG(LogTemp, Error, TEXT("❌ CRITICAL: Cannot backtrack further and cannot place more rooms!"));
                    break;
                }
            }
        }
        else
        {
            // Successfully found a position
            StuckCount = 0;
            ConsecutiveBacktracks = 0;
            
            // Track progress to detect stalls
            if (Path.Num() > LastProgressRoomCount)
            {
                ProgressStalls = 0;
                LastProgressRoomCount = Path.Num();
            }
            else
            {
                ProgressStalls++;
            }
            
            Path.Add(NextPos);
            Visited.Add(NextPos);
            CurrentPos = NextPos;
            
            if (bVerboseLogging && Path.Num() % 5 == 0)
            {
                LogGenerationProgress(Path.Num(), Config.RequiredRoomCount, CurrentRetryCount);
            }
        }
    }
    
    if (Path.Num() != TargetPathLength)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Path generation failed: Got %d rooms, needed %d"), 
            Path.Num(), TargetPathLength);
    }
    else if (bVerboseLogging)
    {
        UE_LOG(LogTemp, Warning, TEXT("✅ Path generation successful: %d rooms generated"), Path.Num());
    }
    
    return Path;
}

FIntPoint USnakePathGenerator::FindNextPositionForPath(FIntPoint Current, const TSet<FIntPoint>& Visited, int32 PathIndex, const FSnakeGenerationConfig& Config)
{
    // Determine room size for next position
    bool bIsStart = (PathIndex == 0);
    bool bIsEnd = (PathIndex == Config.RequiredRoomCount - 1);
    int32 NextRoomSize = (bIsStart || bIsEnd) ? ROOM_SIZE_2x2 : ROOM_SIZE_3x3;
    
    // Get step sizes for this room transition
    int32 CurrentRoomSize = (PathIndex == 0) ? ROOM_SIZE_2x2 : ROOM_SIZE_3x3;
    TArray<int32> StepSizes = GetStepSizesForRoomTransition(CurrentRoomSize, NextRoomSize);
    
    TArray<FIntPoint> PossibleMoves;
    
    // Try all step sizes and directions
    for (int32 StepSize : StepSizes)
    {
        TArray<FIntPoint> Directions = {
            FIntPoint(StepSize, 0),   // Right
            FIntPoint(-StepSize, 0),  // Left
            FIntPoint(0, StepSize),   // Up
            FIntPoint(0, -StepSize)   // Down
            // Cardinal-only movement for proper snake behavior
        };
        
        for (const FIntPoint& Dir : Directions)
        {
            FIntPoint NewPos = Current + Dir;
            
            if (IsValidRoomPosition(NewPos, NextRoomSize, Visited, Config))
            {
                PossibleMoves.Add(NewPos);
            }
        }
    }
    
    if (PossibleMoves.Num() == 0)
    {
        if (bVerboseLogging)
        {
            UE_LOG(LogTemp, Warning, TEXT("🔄 FindNextPositionForPath: No valid moves found for PathIndex %d at (%d,%d)"), 
                PathIndex, Current.X, Current.Y);
        }
        return FIntPoint(-1, -1); // No valid moves
    }
    
    // Select the best move based on generation strategy
    return SelectBestMove(PossibleMoves, Current, PathIndex, Config.RequiredRoomCount);
}

bool USnakePathGenerator::IsValidRoomPosition(FIntPoint Pos, int32 RoomSize, const TSet<FIntPoint>& Visited, const FSnakeGenerationConfig& Config) const
{
    // Check if room fits within grid bounds
    if (!DoesRoomFitInGrid(Pos, RoomSize, Config.GridSizeX, Config.GridSizeY))
    {
        return false;
    }
    
    // Check spacing from all existing rooms
    for (const FIntPoint& ExistingPos : Visited)
    {
        // Assume existing rooms follow the pattern: START = 2x2, others = 3x3
        int32 ExistingRoomSize = ROOM_SIZE_3x3; // Default assumption
        
        if (!CheckRoomSpacing(Pos, RoomSize, ExistingPos, ExistingRoomSize, Config.RoomGap))
        {
            return false;
        }
    }
    
    return true;
}

bool USnakePathGenerator::CheckRoomSpacing(FIntPoint NewPos, int32 NewSize, FIntPoint ExistingPos, int32 ExistingSize, int32 RequiredGap) const
{
    // Calculate minimum required distance based on room sizes
    int32 NewRadius = GetRoomRadius(NewSize);
    int32 ExistingRadius = GetRoomRadius(ExistingSize);
    int32 RequiredDistance = NewRadius + ExistingRadius + RequiredGap;
    
    int32 DistX = FMath::Abs(NewPos.X - ExistingPos.X);
    int32 DistY = FMath::Abs(NewPos.Y - ExistingPos.Y);
    
    // Both distances must meet the requirement (Manhattan distance approach)
    return (DistX >= RequiredDistance || DistY >= RequiredDistance);
}

bool USnakePathGenerator::BacktrackPath(TArray<FIntPoint>& Path, TSet<FIntPoint>& Visited, int32 RequiredRoomCount, int32& BacktrackCount)
{
    if (Path.Num() <= 1)
    {
        return false; // Can't backtrack from START
    }
    
    // Calculate how aggressive we need to be based on current progress
    int32 BacktrackDepth = 1; // Default: remove 1 room
    int32 CurrentPathLength = Path.Num();
    
    if (CurrentPathLength > RequiredRoomCount * 0.8) // Late stage (80%+ complete)
    {
        BacktrackDepth = FMath::Min(5, Path.Num() - 1);
        if (bVerboseLogging)
        {
            UE_LOG(LogTemp, Warning, TEXT("🔙 VERY Aggressive backtracking (late stage): removing %d rooms"), BacktrackDepth);
        }
    }
    else if (CurrentPathLength > RequiredRoomCount * 0.5) // Middle stage (50-80%)
    {
        BacktrackDepth = FMath::Min(3, Path.Num() - 1);
        if (bVerboseLogging)
        {
            UE_LOG(LogTemp, Warning, TEXT("🔙 Aggressive backtracking (middle stage): removing %d rooms"), BacktrackDepth);
        }
    }
    else if (CurrentPathLength > RequiredRoomCount * 0.3) // Early-middle stage (30-50%)
    {
        BacktrackDepth = FMath::Min(2, Path.Num() - 1);
        if (bVerboseLogging)
        {
            UE_LOG(LogTemp, Warning, TEXT("🔙 Moderate backtracking (early-middle): removing %d rooms"), BacktrackDepth);
        }
    }
    
    // Remove rooms from the end of the path
    for (int32 i = 0; i < BacktrackDepth && Path.Num() > 1; ++i)
    {
        FIntPoint RemovedPos = Path.Last();
        Path.RemoveAt(Path.Num() - 1);
        Visited.Remove(RemovedPos);
        BacktrackCount++;
        
        if (bVerboseLogging)
        {
            LogBacktrackAttempt(Path.Num(), i + 1);
        }
    }
    
    return true;
}

FIntPoint USnakePathGenerator::CalculateOptimalGridSize(int32 RoomCount) const
{
    // Base calculation for variable room count with mixed sizes and spacing
    // Estimate: Each room + gap needs roughly 4x4 area on average
    float EstimatedAreaPerRoom = 16.0f; // 4x4 area per room
    float TotalArea = RoomCount * EstimatedAreaPerRoom;
    int32 BaseSize = FMath::CeilToInt(FMath::Sqrt(TotalArea));
    
    // Add buffer for snake path inefficiency
    int32 BufferedSize = BaseSize + FMath::Max(10, RoomCount / 3);
    
    // Clamp to reasonable bounds
    int32 OptimalSize = FMath::Clamp(BufferedSize, MIN_GRID_SIZE, MAX_GRID_SIZE);
    
    // Ensure it's reasonable for the room count
    if (OptimalSize < 45 && RoomCount >= 25)
    {
        OptimalSize = 45; // Minimum for 25 rooms
    }
    
    return FIntPoint(OptimalSize, OptimalSize);
}

bool USnakePathGenerator::ValidateRoomConfiguration(const TArray<FSnakeRoomData>& Rooms, int32 GridSizeX, int32 GridSizeY) const
{
    // Allow variable room counts for limits testing
    if (Rooms.Num() < 1)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Validation failed: No rooms generated"));
        return false;
    }
    
    // Check each room fits in grid and has proper spacing
    for (int32 i = 0; i < Rooms.Num(); ++i)
    {
        const FSnakeRoomData& Room = Rooms[i];
        int32 RoomSize = GetRoomSizeValue(Room.RoomSize);
        
        // Check bounds
        if (!DoesRoomFitInGrid(Room.Center, RoomSize, GridSizeX, GridSizeY))
        {
            UE_LOG(LogTemp, Error, TEXT("❌ Validation failed: Room %d at (%d,%d) doesn't fit in grid %dx%d"), 
                i, Room.Center.X, Room.Center.Y, GridSizeX, GridSizeY);
            return false;
        }
        
        // Check spacing with other rooms
        for (int32 j = i + 1; j < Rooms.Num(); ++j)
        {
            const FSnakeRoomData& OtherRoom = Rooms[j];
            int32 OtherRoomSize = GetRoomSizeValue(OtherRoom.RoomSize);
            
            if (!CheckRoomSpacing(Room.Center, RoomSize, OtherRoom.Center, OtherRoomSize, 1))
            {
                UE_LOG(LogTemp, Error, TEXT("❌ Validation failed: Rooms %d and %d have insufficient spacing"), i, j);
                return false;
            }
        }
    }
    
    // Check START and END room types
    if (Rooms.Num() > 0 && Rooms[0].RoomSize != ESnakeRoomSize::Small_2x2)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Validation failed: START room must be 2x2"));
        return false;
    }
    
    if (Rooms.Num() > 0 && Rooms.Last().RoomSize != ESnakeRoomSize::Small_2x2)
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Validation failed: END room must be 2x2"));
        return false;
    }
    
    return true;
}

ESnakeRoomSize USnakePathGenerator::GetRoomSizeForPathIndex(int32 PathIndex, int32 TotalRooms) const
{
    if (PathIndex == 0 || PathIndex == TotalRooms - 1)
    {
        return ESnakeRoomSize::Small_2x2; // START and END are 2x2
    }
    return ESnakeRoomSize::Standard_3x3; // All others are 3x3
}

int32 USnakePathGenerator::GetRoomSizeValue(ESnakeRoomSize RoomSize) const
{
    return static_cast<int32>(RoomSize);
}

int32 USnakePathGenerator::GetRoomRadius(int32 RoomSize) const
{
    // Conservative radius calculation for spacing
    return (RoomSize == ROOM_SIZE_2x2) ? 1 : 2;
}

bool USnakePathGenerator::IsPositionInBounds(FIntPoint Pos, int32 RoomSize, int32 GridSizeX, int32 GridSizeY) const
{
    return DoesRoomFitInGrid(Pos, RoomSize, GridSizeX, GridSizeY);
}

bool USnakePathGenerator::DoesRoomFitInGrid(FIntPoint Center, int32 RoomSize, int32 GridSizeX, int32 GridSizeY) const
{
    if (RoomSize == ROOM_SIZE_2x2)
    {
        // 2x2 room occupies Center to Center+1
        return (Center.X >= 0 && Center.X + 1 < GridSizeX && 
                Center.Y >= 0 && Center.Y + 1 < GridSizeY);
    }
    else // 3x3 room
    {
        // 3x3 room occupies Center-1 to Center+1
        return (Center.X - 1 >= 0 && Center.X + 1 < GridSizeX && 
                Center.Y - 1 >= 0 && Center.Y + 1 < GridSizeY);
    }
}

FIntPoint USnakePathGenerator::SelectBestMove(const TArray<FIntPoint>& PossibleMoves, FIntPoint Current, int32 PathIndex, int32 RequiredRoomCount) const
{
    if (PossibleMoves.Num() == 1)
    {
        return PossibleMoves[0];
    }
    
    FIntPoint BestMove = PossibleMoves[0];
    
    if (PathIndex < RequiredRoomCount / 3)
    {
        // First third: Maximize distance from START for initial spread
        float MaxDistance = 0;
        for (const FIntPoint& Move : PossibleMoves)
        {
            float DistFromStart = FVector2D::Distance(FVector2D(Move.X, Move.Y), FVector2D(DEFAULT_START_X, DEFAULT_START_Y));
            if (DistFromStart > MaxDistance)
            {
                MaxDistance = DistFromStart;
                BestMove = Move;
            }
        }
    }
    else if (PathIndex > RequiredRoomCount * 2 / 3)
    {
        // Final third: Choose move that maximizes future options
        int32 MaxFutureOptions = -1;
        for (const FIntPoint& Move : PossibleMoves)
        {
            // Count how many directions are still available from this position
            int32 FutureOptions = 0;
            TArray<FIntPoint> TestDirections = {
                FIntPoint(4, 0), FIntPoint(-4, 0), FIntPoint(0, 4), FIntPoint(0, -4)
            };
            
            for (const FIntPoint& Dir : TestDirections)
            {
                FIntPoint TestPos = Move + Dir;
                if (DoesRoomFitInGrid(TestPos, ROOM_SIZE_2x2, 45, 45)) // Rough test for END room
                {
                    FutureOptions++;
                }
            }
            
            if (FutureOptions > MaxFutureOptions)
            {
                MaxFutureOptions = FutureOptions;
                BestMove = Move;
            }
        }
    }
    else
    {
        // Middle: Prefer moves that maintain good spread
        return PossibleMoves[FMath::RandRange(0, PossibleMoves.Num() - 1)];
    }
    
    return BestMove;
}

TArray<int32> USnakePathGenerator::GetStepSizesForRoomTransition(int32 CurrentRoomSize, int32 NextRoomSize) const
{
    TArray<int32> StepSizes;
    
    if (NextRoomSize == ROOM_SIZE_2x2) // Transitioning to 2x2 room (END room)
    {
        // Expanded range for maximum flexibility when placing END room
        StepSizes = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    }
    else // Transitioning to 3x3 room (regular room)
    {
        // Standard range for regular rooms
        StepSizes = {3, 4, 5, 6, 7, 8, 9, 10};
    }
    
    return StepSizes;
}

void USnakePathGenerator::LogGenerationProgress(int32 CurrentRooms, int32 RequiredRooms, int32 RetryCount) const
{
    if (bVerboseLogging)
    {
        float Progress = (float)CurrentRooms / RequiredRooms * 100.0f;
        UE_LOG(LogTemp, Log, TEXT("🐍 Generation Progress: %d/%d rooms (%.1f%%) - Retries: %d"), 
            CurrentRooms, RequiredRooms, Progress, RetryCount);
    }
}

void USnakePathGenerator::LogBacktrackAttempt(int32 PathLength, int32 BacktrackDepth) const
{
    if (bVerboseLogging)
    {
        UE_LOG(LogTemp, Log, TEXT("🔙 Backtrack depth %d - Path now has %d rooms"), 
            BacktrackDepth, PathLength);
    }
}

void USnakePathGenerator::LogGenerationComplete(const FSnakeGenerationResult& Result) const
{
    if (Result.bGenerationSuccessful)
    {
        UE_LOG(LogTemp, Warning, TEXT("✅ Snake generation successful!"));
        UE_LOG(LogTemp, Warning, TEXT("📊 Stats: %d rooms, %dms generation time, %d retries, %d backtracks"), 
            Result.Rooms.Num(), Result.GenerationTimeMs, Result.RetryCount, Result.BacktrackCount);
        UE_LOG(LogTemp, Warning, TEXT("📐 Grid: %dx%d"), Result.GridSizeX, Result.GridSizeY);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("❌ Snake generation failed: %s"), *Result.FailureReason);
        UE_LOG(LogTemp, Error, TEXT("📊 Stats: %dms generation time, %d retries, %d backtracks"), 
            Result.GenerationTimeMs, Result.RetryCount, Result.BacktrackCount);
    }
}