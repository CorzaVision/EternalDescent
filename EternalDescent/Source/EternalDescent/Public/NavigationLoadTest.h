// NavigationLoadTest.h - Test navigation with load/unload cycles
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakeDungeonGenerator.h"
#include "GridDungeonVisualizer.h"
// Navigation includes disabled for UE 5.5 compatibility
// #include "NavigationPath.h"
// #include "NavigationSystem.h"
// #include "AI/Navigation/NavigationTypes.h"
#include "NavigationLoadTest.generated.h"

USTRUCT(BlueprintType)
struct FNavigationTestResult
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    int32 CycleNumber = 0;
    
    UPROPERTY(BlueprintReadWrite)
    bool bPathFound = false;
    
    UPROPERTY(BlueprintReadWrite)
    float PathLength = 0.0f;
    
    UPROPERTY(BlueprintReadWrite)
    int32 PathNodes = 0;
    
    UPROPERTY(BlueprintReadWrite)
    float NavigationTime = 0.0f;
    
    UPROPERTY(BlueprintReadWrite)
    float LoadTime = 0.0f;
    
    UPROPERTY(BlueprintReadWrite)
    float UnloadTime = 0.0f;
    
    UPROPERTY(BlueprintReadWrite)
    int32 MemoryBeforeMB = 0;
    
    UPROPERTY(BlueprintReadWrite)
    int32 MemoryAfterMB = 0;
    
    UPROPERTY(BlueprintReadWrite)
    int32 RoomCount = 0;
    
    UPROPERTY(BlueprintReadWrite)
    FString FailureReason;
};

USTRUCT(BlueprintType)
struct FNavigationTestStats
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    int32 TotalCycles = 0;
    
    UPROPERTY(BlueprintReadWrite)
    int32 SuccessfulPaths = 0;
    
    UPROPERTY(BlueprintReadWrite)
    int32 FailedPaths = 0;
    
    UPROPERTY(BlueprintReadWrite)
    float TotalNavigationTime = 0.0f;
    
    UPROPERTY(BlueprintReadWrite)
    float TotalLoadTime = 0.0f;
    
    UPROPERTY(BlueprintReadWrite)
    float TotalUnloadTime = 0.0f;
    
    UPROPERTY(BlueprintReadWrite)
    float AveragePathLength = 0.0f;
    
    UPROPERTY(BlueprintReadWrite)
    float ShortestPath = 999999.0f;
    
    UPROPERTY(BlueprintReadWrite)
    float LongestPath = 0.0f;
    
    UPROPERTY(BlueprintReadWrite)
    int32 StartMemoryMB = 0;
    
    UPROPERTY(BlueprintReadWrite)
    int32 CurrentMemoryMB = 0;
    
    UPROPERTY(BlueprintReadWrite)
    int32 PeakMemoryMB = 0;
    
    UPROPERTY(BlueprintReadWrite)
    int32 MemoryLeakMB = 0;
    
    UPROPERTY(BlueprintReadWrite)
    float CurrentFPS = 0.0f;
    
    UPROPERTY(BlueprintReadWrite)
    float LowestFPS = 120.0f;
};

UCLASS(BlueprintType, Blueprintable)
class ETERNALDESCENT_API ANavigationLoadTest : public AActor
{
    GENERATED_BODY()

public:
    ANavigationLoadTest();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

public:
    // Core Test Functions
    UFUNCTION(BlueprintCallable, Category = "Navigation Test")
    void StartNavigationTest();
    
    UFUNCTION(BlueprintCallable, Category = "Navigation Test")
    void StopNavigationTest();
    
    UFUNCTION(BlueprintCallable, Category = "Navigation Test")
    void RunSingleCycle();
    
    UFUNCTION(BlueprintCallable, Category = "Navigation Test")
    void RunMultipleCycles(int32 NumCycles);
    
    // Navigation Functions
    UFUNCTION(BlueprintCallable, Category = "Navigation Test")
    bool NavigateFromStartToExit();
    
    UFUNCTION(BlueprintCallable, Category = "Navigation Test")
    TArray<FVector> FindPathBetweenRooms(int32 StartRoomID, int32 EndRoomID);
    
    UFUNCTION(BlueprintCallable, Category = "Navigation Test")
    bool SimulatePlayerMovement(const TArray<FVector>& Path, float Speed = 600.0f);
    
    // Load/Unload Functions
    UFUNCTION(BlueprintCallable, Category = "Navigation Test")
    bool LoadDungeon(int32 Seed = -1);
    
    UFUNCTION(BlueprintCallable, Category = "Navigation Test")
    void UnloadDungeon();
    
    UFUNCTION(BlueprintCallable, Category = "Navigation Test")
    void ClearAllMemory();
    
    // Testing Functions
    UFUNCTION(BlueprintCallable, Category = "Navigation Test")
    void TestMemoryLeaks();
    
    UFUNCTION(BlueprintCallable, Category = "Navigation Test")
    void TestPathfindingPerformance();
    
    UFUNCTION(BlueprintCallable, Category = "Navigation Test")
    void StressTestNavigation();
    
    // Stats & Reporting
    UFUNCTION(BlueprintPure, Category = "Navigation Test")
    FNavigationTestStats GetTestStats() const { return TestStats; }
    
    UFUNCTION(BlueprintCallable, Category = "Navigation Test")
    void PrintTestReport();
    
    UFUNCTION(BlueprintCallable, Category = "Navigation Test")
    void SaveTestResults();
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Navigation Test")
    void OnCycleCompleted(const FNavigationTestResult& Result);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Navigation Test")
    void OnTestCompleted(const FNavigationTestStats& FinalStats);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Navigation Test")
    void OnPathVisualization(const TArray<FVector>& Path);
    
    // Configuration
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration")
    int32 MaxCyclesToRun = 1000;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration")
    bool bAutoStartTest = true;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration")
    float DelayBetweenCycles = 0.1f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration")
    bool bVisualizeNavigation = false;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration")
    bool bSimulateMovement = true;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration")
    float SimulatedPlayerSpeed = 600.0f; // Units per second
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration")
    bool bLogDetailedInfo = false;
    
    // Performance Limits
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Performance")
    int32 MaxMemoryMB = 4096;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Performance")
    float MinAcceptableFPS = 30.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Performance")
    int32 MemoryLeakThresholdMB = 100;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Performance")
    bool bStopOnMemoryLeak = true;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Performance")
    bool bStopOnPathFailure = false;
    
    // References
    UPROPERTY(BlueprintReadOnly, Category = "References")
    ASnakeDungeonGenerator* DungeonGenerator;
    
    UPROPERTY(BlueprintReadOnly, Category = "References")
    AGridDungeonVisualizer* DungeonVisualizer;
    
    // Navigation system disabled for UE 5.5 compatibility
    // UPROPERTY(BlueprintReadOnly, Category = "References")
    // UNavigationSystemV1* NavSystem;
    
    // Runtime Data
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    int32 CurrentCycle = 0;
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    bool bIsTestRunning = false;
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    FDungeonLayout CurrentLayout;
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    TArray<FNavigationTestResult> CycleResults;
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    FNavigationTestStats TestStats;
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    TArray<FVector> CurrentPath;
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    FVector StartRoomLocation;
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    FVector ExitRoomLocation;

private:
    FTimerHandle CycleTimerHandle;
    float TestStartTime;
    
    void RunNextCycle();
    FNavigationTestResult ExecuteCycle();
    bool FindStartAndExitLocations();
    int32 GetMemoryUsageMB();
    void UpdatePerformanceMetrics();
    void CheckForMemoryLeak();
    TArray<FVector> ConvertRoomPathToWorldPath(const TArray<int32>& RoomPath);
    bool IsPathValid(const TArray<FVector>& Path);
};