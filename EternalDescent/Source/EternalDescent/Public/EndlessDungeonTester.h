// EndlessDungeonTester.h - Endless mode dungeon generation tester
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridDungeonVisualizer.h"
#include "ADASystem.h"
#include "Engine/DataTable.h"
#include "EndlessDungeonTester.generated.h"

USTRUCT(BlueprintType)
struct FStageGenerationResult
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    int32 StageNumber = 0;
    
    UPROPERTY(BlueprintReadWrite)
    bool bSuccess = false;
    
    UPROPERTY(BlueprintReadWrite)
    int32 RoomCount = 0;
    
    UPROPERTY(BlueprintReadWrite)
    float GenerationTime = 0.0f;
    
    UPROPERTY(BlueprintReadWrite)
    int32 TotalEnemies = 0;
    
    UPROPERTY(BlueprintReadWrite)
    int32 TotalChests = 0;
    
    UPROPERTY(BlueprintReadWrite)
    FString FailureReason;
};

USTRUCT(BlueprintType)
struct FEndlessTestStats
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    int32 TotalStagesGenerated = 0;
    
    UPROPERTY(BlueprintReadWrite)
    int32 TotalRoomsGenerated = 0;
    
    UPROPERTY(BlueprintReadWrite)
    int32 TotalEnemiesSpawned = 0;
    
    UPROPERTY(BlueprintReadWrite)
    int32 TotalChestsSpawned = 0;
    
    UPROPERTY(BlueprintReadWrite)
    float TotalGenerationTime = 0.0f;
    
    UPROPERTY(BlueprintReadWrite)
    float AverageGenerationTime = 0.0f;
    
    UPROPERTY(BlueprintReadWrite)
    int32 LargestStage = 0;
    
    UPROPERTY(BlueprintReadWrite)
    int32 SmallestStage = 999;
    
    UPROPERTY(BlueprintReadWrite)
    float CurrentFPS = 0.0f;
    
    UPROPERTY(BlueprintReadWrite)
    float LowestFPS = 120.0f;
    
    UPROPERTY(BlueprintReadWrite)
    int32 CurrentMemoryUsageMB = 0;
    
    UPROPERTY(BlueprintReadWrite)
    int32 PeakMemoryUsageMB = 0;
};

UCLASS(BlueprintType, Blueprintable)
class ETERNALDESCENT_API AEndlessDungeonTester : public AActor
{
    GENERATED_BODY()

public:
    AEndlessDungeonTester();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

public:
    // Core Testing Functions
    UFUNCTION(BlueprintCallable, Category = "Endless Test")
    void StartEndlessTest();
    
    UFUNCTION(BlueprintCallable, Category = "Endless Test")
    void StopEndlessTest();
    
    UFUNCTION(BlueprintCallable, Category = "Endless Test")
    void GenerateNextStage();
    
    UFUNCTION(BlueprintCallable, Category = "Endless Test")
    void GenerateMultipleStages(int32 Count);
    
    UFUNCTION(BlueprintCallable, Category = "Endless Test")
    void GenerateMaximumStages();
    
    // Stage Management
    UFUNCTION(BlueprintCallable, Category = "Endless Test")
    void ClearCurrentStage();
    
    UFUNCTION(BlueprintCallable, Category = "Endless Test")
    void TransitionToStage(int32 StageNumber);
    
    UFUNCTION(BlueprintCallable, Category = "Endless Test")
    bool ValidateStage(int32 StageNumber);
    
    // Testing Functions
    UFUNCTION(BlueprintCallable, Category = "Endless Test")
    void RunStressTest(int32 MaxStages = 1000);
    
    UFUNCTION(BlueprintCallable, Category = "Endless Test")
    void TestRoomScaling();
    
    UFUNCTION(BlueprintCallable, Category = "Endless Test")
    void TestGenerationSpeed();
    
    // Stats & Monitoring
    UFUNCTION(BlueprintPure, Category = "Endless Test")
    FEndlessTestStats GetTestStats() const { return TestStats; }
    
    UFUNCTION(BlueprintPure, Category = "Endless Test")
    FStageGenerationResult GetStageResult(int32 StageNumber) const;
    
    UFUNCTION(BlueprintCallable, Category = "Endless Test")
    void UpdatePerformanceMetrics();
    
    UFUNCTION(BlueprintCallable, Category = "Endless Test")
    void PrintTestReport();
    
    UFUNCTION(BlueprintCallable, Category = "Endless Test")
    void SaveTestResults();
    
    // Visualization
    UFUNCTION(BlueprintCallable, Category = "Endless Test")
    void VisualizeStage(int32 StageNumber);
    
    UFUNCTION(BlueprintCallable, Category = "Endless Test")
    void ShowAllStagesOverview();
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Endless Test")
    void OnStageGenerated(const FStageGenerationResult& Result);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Endless Test")
    void OnTestCompleted(const FEndlessTestStats& FinalStats);
    
    // Configuration
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration")
    int32 MaxStagesToGenerate = 100; // Start with 100, can go up to 1000+
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration")
    bool bAutoGenerateOnStart = true;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration")
    float DelayBetweenStages = 0.1f; // Small delay to prevent freezing
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration")
    bool bVisualizeEachStage = false; // Set false for max performance
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration")
    bool bLogDetailedStats = true;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration")
    int32 MinRoomsPerStage = 10;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration")
    int32 MaxRoomsPerStage = 30;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration")
    bool bIncreaseComplexityOverTime = true;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration")
    float ComplexityGrowthRate = 0.05f; // 5% more rooms per 10 stages
    
    // Performance Limits
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Performance")
    float MinAcceptableFPS = 30.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Performance")
    int32 MaxMemoryUsageMB = 4096; // 4GB limit
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Performance")
    bool bStopOnPerformanceIssue = true;
    
    // References
    UPROPERTY(BlueprintReadOnly, Category = "References")
    AGridDungeonVisualizer* DungeonVisualizer;
    
    UPROPERTY(BlueprintReadOnly, Category = "References")
    AADASystem* ADASystem;
    
    // Runtime Data
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    int32 CurrentStage = 0;
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    bool bIsTestRunning = false;
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    TArray<FStageGenerationResult> StageResults;
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    TArray<FDungeonLayout> GeneratedLayouts;
    
    UPROPERTY(BlueprintReadOnly, Category = "Runtime")
    FEndlessTestStats TestStats;

private:
    FTimerHandle GenerationTimerHandle;
    float TestStartTime;
    
    void GenerateStageInternal(int32 StageNumber);
    int32 CalculateRoomCount(int32 StageNumber);
    void CheckPerformanceLimits();
    int32 GetMemoryUsageMB();
    void UpdateADAPersonality(int32 StageNumber);
};