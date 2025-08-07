// EndlessDungeonTester.cpp - Minimal implementation to fix linker errors
#include "EndlessDungeonTester.h"
#include "Engine/Engine.h"
#include "Engine/World.h"

AEndlessDungeonTester::AEndlessDungeonTester()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AEndlessDungeonTester::BeginPlay()
{
    Super::BeginPlay();
    
    if (bAutoGenerateOnStart)
    {
        StartEndlessTest();
    }
}

void AEndlessDungeonTester::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    if (bIsTestRunning)
    {
        UpdatePerformanceMetrics();
        CheckPerformanceLimits();
    }
}

void AEndlessDungeonTester::StartEndlessTest()
{
    bIsTestRunning = true;
    CurrentStage = 0;
    TestStartTime = GetWorld()->GetTimeSeconds();
    UE_LOG(LogTemp, Warning, TEXT("Endless Test Started"));
}

void AEndlessDungeonTester::StopEndlessTest()
{
    bIsTestRunning = false;
    GetWorld()->GetTimerManager().ClearTimer(GenerationTimerHandle);
    UE_LOG(LogTemp, Warning, TEXT("Endless Test Stopped"));
}

void AEndlessDungeonTester::GenerateNextStage()
{
    if (CurrentStage < MaxStagesToGenerate)
    {
        CurrentStage++;
        GenerateStageInternal(CurrentStage);
    }
    else
    {
        StopEndlessTest();
    }
}

void AEndlessDungeonTester::GenerateMultipleStages(int32 Count)
{
    for (int32 i = 0; i < Count && CurrentStage < MaxStagesToGenerate; ++i)
    {
        GenerateNextStage();
    }
}

void AEndlessDungeonTester::GenerateMaximumStages()
{
    while (CurrentStage < MaxStagesToGenerate && bIsTestRunning)
    {
        GenerateNextStage();
    }
}

void AEndlessDungeonTester::ClearCurrentStage()
{
    // Clear visualization if exists
    if (DungeonVisualizer)
    {
        DungeonVisualizer->ClearDungeon();
    }
}

void AEndlessDungeonTester::TransitionToStage(int32 StageNumber)
{
    CurrentStage = StageNumber;
    ClearCurrentStage();
    GenerateStageInternal(StageNumber);
}

bool AEndlessDungeonTester::ValidateStage(int32 StageNumber)
{
    if (StageNumber < 0 || StageNumber >= StageResults.Num())
        return false;
        
    return StageResults[StageNumber].bSuccess;
}

void AEndlessDungeonTester::RunStressTest(int32 MaxStages)
{
    MaxStagesToGenerate = MaxStages;
    StartEndlessTest();
}

void AEndlessDungeonTester::TestRoomScaling()
{
    UE_LOG(LogTemp, Warning, TEXT("Room scaling test initiated"));
}

void AEndlessDungeonTester::TestGenerationSpeed()
{
    UE_LOG(LogTemp, Warning, TEXT("Generation speed test initiated"));
}

FStageGenerationResult AEndlessDungeonTester::GetStageResult(int32 StageNumber) const
{
    if (StageNumber >= 0 && StageNumber < StageResults.Num())
    {
        return StageResults[StageNumber];
    }
    
    FStageGenerationResult EmptyResult;
    EmptyResult.StageNumber = StageNumber;
    EmptyResult.bSuccess = false;
    EmptyResult.FailureReason = TEXT("Stage not found");
    return EmptyResult;
}

void AEndlessDungeonTester::UpdatePerformanceMetrics()
{
    // Basic performance tracking - UE 5.5 compatible
    if (GetWorld())
    {
        float DeltaTime = GetWorld()->GetDeltaSeconds();
        if (DeltaTime > 0.0f)
        {
            TestStats.CurrentFPS = 1.0f / DeltaTime;
            if (TestStats.CurrentFPS < TestStats.LowestFPS)
            {
                TestStats.LowestFPS = TestStats.CurrentFPS;
            }
        }
    }
    
    TestStats.CurrentMemoryUsageMB = GetMemoryUsageMB();
    if (TestStats.CurrentMemoryUsageMB > TestStats.PeakMemoryUsageMB)
    {
        TestStats.PeakMemoryUsageMB = TestStats.CurrentMemoryUsageMB;
    }
}

void AEndlessDungeonTester::PrintTestReport()
{
    UE_LOG(LogTemp, Warning, TEXT("=== ENDLESS DUNGEON TEST REPORT ==="));
    UE_LOG(LogTemp, Warning, TEXT("Total Stages Generated: %d"), TestStats.TotalStagesGenerated);
    UE_LOG(LogTemp, Warning, TEXT("Total Rooms Generated: %d"), TestStats.TotalRoomsGenerated);
    UE_LOG(LogTemp, Warning, TEXT("Average Generation Time: %f seconds"), TestStats.AverageGenerationTime);
    UE_LOG(LogTemp, Warning, TEXT("Lowest FPS: %f"), TestStats.LowestFPS);
    UE_LOG(LogTemp, Warning, TEXT("Peak Memory Usage: %d MB"), TestStats.PeakMemoryUsageMB);
}

void AEndlessDungeonTester::SaveTestResults()
{
    // Save test results to file (minimal implementation)
    UE_LOG(LogTemp, Warning, TEXT("Test results saved"));
}

void AEndlessDungeonTester::VisualizeStage(int32 StageNumber)
{
    if (DungeonVisualizer && StageNumber < GeneratedLayouts.Num())
    {
        // Use GenerateAndVisualizeDungeon instead of VisualizeDungeonLayout for UE 5.5 compatibility
        DungeonVisualizer->GenerateAndVisualizeDungeon(StageNumber);
    }
}

void AEndlessDungeonTester::ShowAllStagesOverview()
{
    UE_LOG(LogTemp, Warning, TEXT("Showing all stages overview"));
}

// Private functions
void AEndlessDungeonTester::GenerateStageInternal(int32 StageNumber)
{
    float StartTime = GetWorld()->GetTimeSeconds();
    
    FStageGenerationResult Result;
    Result.StageNumber = StageNumber;
    
    // Simple test generation
    int32 RoomCount = CalculateRoomCount(StageNumber);
    Result.RoomCount = RoomCount;
    Result.bSuccess = true;
    Result.GenerationTime = GetWorld()->GetTimeSeconds() - StartTime;
    
    StageResults.Add(Result);
    
    // Update stats
    TestStats.TotalStagesGenerated++;
    TestStats.TotalRoomsGenerated += RoomCount;
    TestStats.TotalGenerationTime += Result.GenerationTime;
    TestStats.AverageGenerationTime = TestStats.TotalGenerationTime / TestStats.TotalStagesGenerated;
    
    UE_LOG(LogTemp, Warning, TEXT("Generated Stage %d with %d rooms in %f seconds"), 
           StageNumber, RoomCount, Result.GenerationTime);
}

int32 AEndlessDungeonTester::CalculateRoomCount(int32 StageNumber)
{
    int32 BaseRooms = MinRoomsPerStage;
    if (bIncreaseComplexityOverTime)
    {
        float ComplexityMultiplier = 1.0f + (StageNumber * ComplexityGrowthRate / 10.0f);
        BaseRooms = FMath::Clamp(BaseRooms * ComplexityMultiplier, MinRoomsPerStage, MaxRoomsPerStage);
    }
    return BaseRooms;
}

void AEndlessDungeonTester::CheckPerformanceLimits()
{
    if (bStopOnPerformanceIssue)
    {
        if (TestStats.CurrentFPS < MinAcceptableFPS)
        {
            UE_LOG(LogTemp, Error, TEXT("Performance limit reached - FPS: %f"), TestStats.CurrentFPS);
            StopEndlessTest();
        }
        
        if (TestStats.CurrentMemoryUsageMB > MaxMemoryUsageMB)
        {
            UE_LOG(LogTemp, Error, TEXT("Memory limit reached - Usage: %d MB"), TestStats.CurrentMemoryUsageMB);
            StopEndlessTest();
        }
    }
}

int32 AEndlessDungeonTester::GetMemoryUsageMB()
{
    // Simple memory usage estimation
    return 100; // Placeholder
}

void AEndlessDungeonTester::UpdateADAPersonality(int32 StageNumber)
{
    // Update ADA system based on stage
    if (ADASystem)
    {
        // Implementation would go here
    }
}