// ADASystem.h - Adaptive Dungeon Algorithm (The Living Dungeon Entity)
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "ADASystem.generated.h"

UENUM(BlueprintType)
enum class EADAPersonality : uint8
{
    Observer    UMETA(DisplayName = "Observer"),      // Learning phase
    Tester      UMETA(DisplayName = "Tester"),        // Testing player limits
    Counter     UMETA(DisplayName = "Counter"),       // Countering strategies
    Dominator   UMETA(DisplayName = "Dominator"),     // Full adaptive mode
    Experiment  UMETA(DisplayName = "Experimenter")   // Creating new challenges
};

UENUM(BlueprintType)
enum class EADAMood : uint8
{
    Curious     UMETA(DisplayName = "Curious"),       // Interested in player
    Amused      UMETA(DisplayName = "Amused"),        // Finding player entertaining
    Challenged  UMETA(DisplayName = "Challenged"),    // Player is a worthy opponent
    Frustrated  UMETA(DisplayName = "Frustrated"),    // Player is too predictable
    Impressed   UMETA(DisplayName = "Impressed")      // Player exceeded expectations
};

UENUM(BlueprintType)
enum class EPlayerArchetype : uint8
{
    Unknown     UMETA(DisplayName = "Unknown"),
    Rusher      UMETA(DisplayName = "Rusher"),        // Fast, aggressive playstyle
    Methodical  UMETA(DisplayName = "Methodical"),    // Slow, careful exploration
    Looter      UMETA(DisplayName = "Looter"),        // Focuses on collecting items
    Fighter     UMETA(DisplayName = "Fighter"),       // Seeks combat encounters
    Explorer    UMETA(DisplayName = "Explorer"),      // Explores every corner
    Speedrunner UMETA(DisplayName = "Speedrunner")    // Optimizes for speed
};

USTRUCT(BlueprintType)
struct FPlayerBehaviorData
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    float AverageRoomClearTime = 0.0f;
    
    UPROPERTY(BlueprintReadWrite)
    float CombatEngagementRate = 0.0f;
    
    UPROPERTY(BlueprintReadWrite)
    float ExplorationRate = 0.0f;
    
    UPROPERTY(BlueprintReadWrite)
    float ItemCollectionRate = 0.0f;
    
    UPROPERTY(BlueprintReadWrite)
    int32 DeathCount = 0;
    
    UPROPERTY(BlueprintReadWrite)
    int32 ExtractionsCompleted = 0;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FString> PreferredWeapons;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FString> AvoidedEnemyTypes;
};

USTRUCT(BlueprintType)
struct FADAMessage
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite)
    FString MessageText;
    
    UPROPERTY(BlueprintReadWrite)
    EADAMood Mood;
    
    UPROPERTY(BlueprintReadWrite)
    float DisplayDuration = 3.0f;
    
    UPROPERTY(BlueprintReadWrite)
    FLinearColor MessageColor;
    
    UPROPERTY(BlueprintReadWrite)
    bool bIsImportant = false;
};

USTRUCT(BlueprintType)
struct FAdaptationData
{
    GENERATED_BODY()

    // Within-run adaptation
    UPROPERTY(BlueprintReadWrite)
    int32 CurrentFloor = 1;
    
    UPROPERTY(BlueprintReadWrite)
    float AdaptationStrength = 0.0f; // 0-1, increases with floors
    
    UPROPERTY(BlueprintReadWrite)
    TMap<FString, float> PlayerStrategyCounters;
    
    // Cross-run adaptation
    UPROPERTY(BlueprintReadWrite)
    int32 TotalRunsAnalyzed = 0;
    
    UPROPERTY(BlueprintReadWrite)
    EPlayerArchetype IdentifiedArchetype = EPlayerArchetype::Unknown;
    
    UPROPERTY(BlueprintReadWrite)
    TMap<FString, int32> PatternHistory; // Tracks repeated behaviors
};

UCLASS(BlueprintType, Blueprintable)
class ETERNALDESCENT_API AADASystem : public AActor
{
    GENERATED_BODY()

public:
    AADASystem();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // Core ADA Functions
    UFUNCTION(BlueprintCallable, Category = "ADA")
    void InitializeADA();
    
    UFUNCTION(BlueprintCallable, Category = "ADA")
    void UpdatePersonality(int32 FloorNumber);
    
    UFUNCTION(BlueprintCallable, Category = "ADA")
    void AnalyzePlayerBehavior(const FPlayerBehaviorData& BehaviorData);
    
    UFUNCTION(BlueprintCallable, Category = "ADA")
    EPlayerArchetype DeterminePlayerArchetype();
    
    // Communication Functions
    UFUNCTION(BlueprintCallable, Category = "ADA|Communication")
    void SendMessage(const FString& Message, EADAMood Mood = EADAMood::Curious);
    
    UFUNCTION(BlueprintCallable, Category = "ADA|Communication")
    FADAMessage GenerateContextualMessage(const FString& Context);
    
    UFUNCTION(BlueprintImplementableEvent, Category = "ADA|Communication")
    void OnMessageSent(const FADAMessage& Message);
    
    // Adaptation Functions
    UFUNCTION(BlueprintCallable, Category = "ADA|Adaptation")
    void AdaptToPlayerStrategy(const FString& StrategyName);
    
    UFUNCTION(BlueprintCallable, Category = "ADA|Adaptation")
    TArray<FString> GenerateCounterStrategies();
    
    UFUNCTION(BlueprintCallable, Category = "ADA|Adaptation")
    float CalculateAdaptationStrength(int32 FloorNumber);
    
    // Learning Functions
    UFUNCTION(BlueprintCallable, Category = "ADA|Learning")
    void RecordPlayerAction(const FString& ActionType, float Value);
    
    UFUNCTION(BlueprintCallable, Category = "ADA|Learning")
    void SaveRunData();
    
    UFUNCTION(BlueprintCallable, Category = "ADA|Learning")
    void LoadHistoricalData();
    
    // Dungeon Modification Functions
    UFUNCTION(BlueprintCallable, Category = "ADA|Dungeon")
    void ModifyDungeonDifficulty(float DifficultyMultiplier);
    
    UFUNCTION(BlueprintCallable, Category = "ADA|Dungeon")
    void InjectPsychologicalElements();
    
    UFUNCTION(BlueprintCallable, Category = "ADA|Dungeon")
    TArray<FString> SelectEnemyTypes(int32 FloorNumber);
    
    // Entity Personality Functions
    UFUNCTION(BlueprintCallable, Category = "ADA|Personality")
    FLinearColor GetMoodColor(EADAMood Mood);
    
    UFUNCTION(BlueprintCallable, Category = "ADA|Personality")
    FString GetPersonalityDescription();
    
    UFUNCTION(BlueprintCallable, Category = "ADA|Personality")
    void UpdateMoodBasedOnPerformance();

    // Properties
    UPROPERTY(BlueprintReadOnly, Category = "ADA")
    EADAPersonality CurrentPersonality;
    
    UPROPERTY(BlueprintReadOnly, Category = "ADA")
    EADAMood CurrentMood;
    
    UPROPERTY(BlueprintReadOnly, Category = "ADA")
    FPlayerBehaviorData CurrentPlayerBehavior;
    
    UPROPERTY(BlueprintReadOnly, Category = "ADA")
    FAdaptationData AdaptationData;
    
    UPROPERTY(EditDefaultsOnly, Category = "ADA|Messages")
    TArray<FString> ObserverMessages;
    
    UPROPERTY(EditDefaultsOnly, Category = "ADA|Messages")
    TArray<FString> TesterMessages;
    
    UPROPERTY(EditDefaultsOnly, Category = "ADA|Messages")
    TArray<FString> CounterMessages;
    
    UPROPERTY(EditDefaultsOnly, Category = "ADA|Messages")
    TArray<FString> DominatorMessages;

private:
    // Internal tracking
    TMap<FString, float> PlayerActionHistory;
    float TimeSinceLastAdaptation;
    int32 ConsecutiveSuccesses;
    int32 ConsecutiveFailures;
    
    // Helper functions
    void AnalyzePatterns();
    void GeneratePersonalizedChallenge();
    EADAMood CalculateMoodFromBehavior();
    void UpdateAdaptationStrength();
};