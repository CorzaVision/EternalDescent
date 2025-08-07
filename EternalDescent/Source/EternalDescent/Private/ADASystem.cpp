// ADASystem.cpp - The Living Dungeon Entity (Game Master)
#include "ADASystem.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"

AADASystem::AADASystem()
{
    PrimaryActorTick.bCanEverTick = true;
    
    // Initialize default personality
    CurrentPersonality = EADAPersonality::Observer;
    CurrentMood = EADAMood::Curious;
    
    // Initialize default messages
    ObserverMessages = {
        TEXT("The Dungeon Listens..."),
        TEXT("Interesting approach..."),
        TEXT("I see you..."),
        TEXT("Your patterns reveal much..."),
        TEXT("Continue... show me more...")
    };
    
    TesterMessages = {
        TEXT("Let's see how you handle this..."),
        TEXT("Can you adapt as I do?"),
        TEXT("Your limits intrigue me..."),
        TEXT("This should prove entertaining..."),
        TEXT("Show me your true capabilities...")
    };
    
    CounterMessages = {
        TEXT("That won't work anymore..."),
        TEXT("I've learned your tricks..."),
        TEXT("Predictable..."),
        TEXT("You'll need to try harder..."),
        TEXT("I know what you're going to do...")
    };
    
    DominatorMessages = {
        TEXT("You cannot escape my design..."),
        TEXT("Every path leads to my choosing..."),
        TEXT("Your struggle amuses me..."),
        TEXT("I am inevitable..."),
        TEXT("Dance for me, little hero...")
    };
}

void AADASystem::BeginPlay()
{
    Super::BeginPlay();
    InitializeADA();
}

void AADASystem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    TimeSinceLastAdaptation += DeltaTime;
    
    // Periodic adaptation check (every 30 seconds)
    if (TimeSinceLastAdaptation > 30.0f)
    {
        UpdateAdaptationStrength();
        TimeSinceLastAdaptation = 0.0f;
    }
}

void AADASystem::InitializeADA()
{
    // Load any saved data about the player
    LoadHistoricalData();
    
    // Send initial message
    SendMessage(TEXT("The Dungeon Awaits..."), EADAMood::Curious);
    
    // Reset session data
    TimeSinceLastAdaptation = 0.0f;
    ConsecutiveSuccesses = 0;
    ConsecutiveFailures = 0;
    
    UE_LOG(LogTemp, Display, TEXT("ADA System Initialized - The Entity Awakens"));
}

void AADASystem::UpdatePersonality(int32 FloorNumber)
{
    EADAPersonality OldPersonality = CurrentPersonality;
    
    // Personality evolves based on floor progression
    if (FloorNumber <= 10)
    {
        CurrentPersonality = EADAPersonality::Observer;
    }
    else if (FloorNumber <= 25)
    {
        CurrentPersonality = EADAPersonality::Tester;
    }
    else if (FloorNumber <= 50)
    {
        CurrentPersonality = EADAPersonality::Counter;
    }
    else if (FloorNumber <= 100)
    {
        CurrentPersonality = EADAPersonality::Dominator;
    }
    else
    {
        CurrentPersonality = EADAPersonality::Experiment;
    }
    
    // Announce personality change
    if (OldPersonality != CurrentPersonality)
    {
        FString TransitionMessage;
        switch (CurrentPersonality)
        {
            case EADAPersonality::Tester:
                TransitionMessage = TEXT("The Dungeon begins to test you...");
                break;
            case EADAPersonality::Counter:
                TransitionMessage = TEXT("The Dungeon adapts to your methods...");
                break;
            case EADAPersonality::Dominator:
                TransitionMessage = TEXT("The Dungeon asserts its dominance...");
                break;
            case EADAPersonality::Experiment:
                TransitionMessage = TEXT("The Dungeon transcends predictability...");
                break;
            default:
                break;
        }
        
        if (!TransitionMessage.IsEmpty())
        {
            SendMessage(TransitionMessage, EADAMood::Challenged);
        }
    }
    
    AdaptationData.CurrentFloor = FloorNumber;
    AdaptationData.AdaptationStrength = CalculateAdaptationStrength(FloorNumber);
}

void AADASystem::AnalyzePlayerBehavior(const FPlayerBehaviorData& BehaviorData)
{
    CurrentPlayerBehavior = BehaviorData;
    
    // Analyze patterns
    AnalyzePatterns();
    
    // Determine archetype
    EPlayerArchetype NewArchetype = DeterminePlayerArchetype();
    
    if (NewArchetype != AdaptationData.IdentifiedArchetype)
    {
        AdaptationData.IdentifiedArchetype = NewArchetype;
        
        // React to newly identified archetype
        FString ArchetypeMessage;
        switch (NewArchetype)
        {
            case EPlayerArchetype::Rusher:
                ArchetypeMessage = TEXT("Always in a hurry, aren't you?");
                break;
            case EPlayerArchetype::Methodical:
                ArchetypeMessage = TEXT("So careful... so predictable...");
                break;
            case EPlayerArchetype::Looter:
                ArchetypeMessage = TEXT("Greed will be your downfall...");
                break;
            case EPlayerArchetype::Fighter:
                ArchetypeMessage = TEXT("Violence is your answer to everything...");
                break;
            case EPlayerArchetype::Explorer:
                ArchetypeMessage = TEXT("Curiosity... I can use that...");
                break;
            case EPlayerArchetype::Speedrunner:
                ArchetypeMessage = TEXT("Racing against time itself...");
                break;
            default:
                break;
        }
        
        if (!ArchetypeMessage.IsEmpty())
        {
            SendMessage(ArchetypeMessage, EADAMood::Amused);
        }
    }
    
    // Update mood based on player performance
    UpdateMoodBasedOnPerformance();
}

EPlayerArchetype AADASystem::DeterminePlayerArchetype()
{
    // Analyze behavior patterns to determine archetype
    float CombatFocus = CurrentPlayerBehavior.CombatEngagementRate;
    float ExploreFocus = CurrentPlayerBehavior.ExplorationRate;
    float LootFocus = CurrentPlayerBehavior.ItemCollectionRate;
    float Speed = 1.0f / FMath::Max(CurrentPlayerBehavior.AverageRoomClearTime, 0.01f);
    
    // Find dominant playstyle
    TArray<TPair<EPlayerArchetype, float>> Scores;
    Scores.Add(TPair<EPlayerArchetype, float>(EPlayerArchetype::Fighter, CombatFocus));
    Scores.Add(TPair<EPlayerArchetype, float>(EPlayerArchetype::Explorer, ExploreFocus));
    Scores.Add(TPair<EPlayerArchetype, float>(EPlayerArchetype::Looter, LootFocus));
    Scores.Add(TPair<EPlayerArchetype, float>(EPlayerArchetype::Rusher, Speed * 2.0f));
    
    // Methodical players have low speed but high exploration
    if (Speed < 0.5f && ExploreFocus > 0.7f)
    {
        return EPlayerArchetype::Methodical;
    }
    
    // Speedrunners have very high speed and low everything else
    if (Speed > 2.0f && CombatFocus < 0.3f && LootFocus < 0.3f)
    {
        return EPlayerArchetype::Speedrunner;
    }
    
    // Sort and return highest scoring archetype
    Scores.Sort([](const TPair<EPlayerArchetype, float>& A, const TPair<EPlayerArchetype, float>& B) {
        return A.Value > B.Value;
    });
    
    return Scores[0].Key;
}

void AADASystem::SendMessage(const FString& Message, EADAMood Mood)
{
    FADAMessage ADAMessage;
    ADAMessage.MessageText = Message;
    ADAMessage.Mood = Mood;
    ADAMessage.MessageColor = GetMoodColor(Mood);
    ADAMessage.DisplayDuration = 3.0f + (Message.Len() * 0.05f); // Longer messages display longer
    ADAMessage.bIsImportant = (Mood == EADAMood::Challenged || Mood == EADAMood::Impressed);
    
    // Trigger Blueprint event for UI display
    OnMessageSent(ADAMessage);
    
    UE_LOG(LogTemp, Display, TEXT("ADA: %s"), *Message);
}

FADAMessage AADASystem::GenerateContextualMessage(const FString& Context)
{
    FADAMessage Message;
    
    // Select message based on personality and context
    TArray<FString>* MessagePool = nullptr;
    
    switch (CurrentPersonality)
    {
        case EADAPersonality::Observer:
            MessagePool = &ObserverMessages;
            break;
        case EADAPersonality::Tester:
            MessagePool = &TesterMessages;
            break;
        case EADAPersonality::Counter:
            MessagePool = &CounterMessages;
            break;
        case EADAPersonality::Dominator:
            MessagePool = &DominatorMessages;
            break;
        default:
            MessagePool = &ObserverMessages;
            break;
    }
    
    if (MessagePool && MessagePool->Num() > 0)
    {
        int32 RandomIndex = FMath::RandRange(0, MessagePool->Num() - 1);
        Message.MessageText = (*MessagePool)[RandomIndex];
    }
    else
    {
        Message.MessageText = TEXT("...");
    }
    
    Message.Mood = CurrentMood;
    Message.MessageColor = GetMoodColor(CurrentMood);
    Message.DisplayDuration = 3.0f;
    
    return Message;
}

void AADASystem::AdaptToPlayerStrategy(const FString& StrategyName)
{
    // Track how often player uses this strategy
    if (!AdaptationData.PlayerStrategyCounters.Contains(StrategyName))
    {
        AdaptationData.PlayerStrategyCounters.Add(StrategyName, 0.0f);
    }
    
    AdaptationData.PlayerStrategyCounters[StrategyName] += 1.0f;
    
    // Generate counter if strategy is used too often
    if (AdaptationData.PlayerStrategyCounters[StrategyName] > 3)
    {
        UE_LOG(LogTemp, Display, TEXT("ADA: Generating counter for strategy: %s"), *StrategyName);
        GeneratePersonalizedChallenge();
    }
}

TArray<FString> AADASystem::GenerateCounterStrategies()
{
    TArray<FString> Counters;
    
    switch (AdaptationData.IdentifiedArchetype)
    {
        case EPlayerArchetype::Rusher:
            Counters.Add(TEXT("Increase_Enemy_Speed"));
            Counters.Add(TEXT("Add_Time_Pressure"));
            Counters.Add(TEXT("Create_Ambushes"));
            break;
            
        case EPlayerArchetype::Methodical:
            Counters.Add(TEXT("Add_Timers"));
            Counters.Add(TEXT("Spawn_Pursuers"));
            Counters.Add(TEXT("Decay_Resources"));
            break;
            
        case EPlayerArchetype::Looter:
            Counters.Add(TEXT("Trap_Chests"));
            Counters.Add(TEXT("Mimic_Enemies"));
            Counters.Add(TEXT("Cursed_Items"));
            break;
            
        case EPlayerArchetype::Fighter:
            Counters.Add(TEXT("Damage_Reflect"));
            Counters.Add(TEXT("Evasive_Enemies"));
            Counters.Add(TEXT("Pacifist_Rewards"));
            break;
            
        case EPlayerArchetype::Explorer:
            Counters.Add(TEXT("Dead_Ends"));
            Counters.Add(TEXT("Maze_Layouts"));
            Counters.Add(TEXT("Hidden_Traps"));
            break;
            
        case EPlayerArchetype::Speedrunner:
            Counters.Add(TEXT("Movement_Debuffs"));
            Counters.Add(TEXT("Mandatory_Fights"));
            Counters.Add(TEXT("Complex_Puzzles"));
            break;
            
        default:
            Counters.Add(TEXT("Random_Challenge"));
            break;
    }
    
    return Counters;
}

float AADASystem::CalculateAdaptationStrength(int32 FloorNumber)
{
    // Adaptation strength increases with floor number
    // Caps at 1.0 (100% adaptation) at floor 100
    float BaseStrength = FMath::Min(FloorNumber / 100.0f, 1.0f);
    
    // Modify based on player performance
    if (ConsecutiveSuccesses > 5)
    {
        BaseStrength = FMath::Min(BaseStrength + 0.2f, 1.0f);
    }
    else if (ConsecutiveFailures > 3)
    {
        BaseStrength = FMath::Max(BaseStrength - 0.1f, 0.0f);
    }
    
    return BaseStrength;
}

void AADASystem::RecordPlayerAction(const FString& ActionType, float Value)
{
    if (!PlayerActionHistory.Contains(ActionType))
    {
        PlayerActionHistory.Add(ActionType, 0.0f);
    }
    
    PlayerActionHistory[ActionType] += Value;
    
    // Update pattern history for cross-run learning
    FString PatternKey = ActionType + TEXT("_") + FString::FromInt(AdaptationData.CurrentFloor);
    if (!AdaptationData.PatternHistory.Contains(PatternKey))
    {
        AdaptationData.PatternHistory.Add(PatternKey, 0);
    }
    AdaptationData.PatternHistory[PatternKey]++;
}

void AADASystem::SaveRunData()
{
    // Save current run data for cross-run adaptation
    AdaptationData.TotalRunsAnalyzed++;
    
    // In a real implementation, this would save to a file or database
    UE_LOG(LogTemp, Display, TEXT("ADA: Saving run data. Total runs analyzed: %d"), AdaptationData.TotalRunsAnalyzed);
}

void AADASystem::LoadHistoricalData()
{
    // Load previous run data
    // In a real implementation, this would load from a file or database
    UE_LOG(LogTemp, Display, TEXT("ADA: Loading historical data..."));
}

void AADASystem::ModifyDungeonDifficulty(float DifficultyMultiplier)
{
    // Apply difficulty modifications based on adaptation
    float FinalMultiplier = DifficultyMultiplier * (1.0f + AdaptationData.AdaptationStrength);
    
    UE_LOG(LogTemp, Display, TEXT("ADA: Modifying dungeon difficulty to %f"), FinalMultiplier);
    
    // This would communicate with the dungeon generation system
}

void AADASystem::InjectPsychologicalElements()
{
    // Add psychological warfare elements based on player profile
    switch (AdaptationData.IdentifiedArchetype)
    {
        case EPlayerArchetype::Looter:
            // Create false treasure rooms, mimics
            UE_LOG(LogTemp, Display, TEXT("ADA: Injecting false rewards for greedy player"));
            break;
            
        case EPlayerArchetype::Fighter:
            // Create enemies that punish aggression
            UE_LOG(LogTemp, Display, TEXT("ADA: Injecting counter-aggressive enemies"));
            break;
            
        case EPlayerArchetype::Explorer:
            // Create confusing layouts, false paths
            UE_LOG(LogTemp, Display, TEXT("ADA: Injecting maze-like confusion"));
            break;
            
        default:
            break;
    }
    
    SendMessage(TEXT("I've prepared something special for you..."), EADAMood::Amused);
}

TArray<FString> AADASystem::SelectEnemyTypes(int32 FloorNumber)
{
    TArray<FString> EnemyTypes;
    
    // Select enemies based on player weaknesses
    if (CurrentPlayerBehavior.AvoidedEnemyTypes.Num() > 0)
    {
        // Intentionally spawn enemies the player avoids
        EnemyTypes = CurrentPlayerBehavior.AvoidedEnemyTypes;
        
        if (CurrentPersonality >= EADAPersonality::Counter)
        {
            SendMessage(TEXT("You can't avoid them forever..."), EADAMood::Amused);
        }
    }
    else
    {
        // Default enemy selection based on floor
        if (FloorNumber <= 10)
        {
            EnemyTypes = {TEXT("Skeleton"), TEXT("Zombie"), TEXT("Rat")};
        }
        else if (FloorNumber <= 25)
        {
            EnemyTypes = {TEXT("Ghost"), TEXT("Wraith"), TEXT("Skeleton_Elite")};
        }
        else
        {
            EnemyTypes = {TEXT("Lich"), TEXT("Bone_Dragon"), TEXT("Death_Knight")};
        }
    }
    
    return EnemyTypes;
}

FLinearColor AADASystem::GetMoodColor(EADAMood Mood)
{
    switch (Mood)
    {
        case EADAMood::Curious:
            return FLinearColor(0.5f, 0.5f, 1.0f); // Light blue
        case EADAMood::Amused:
            return FLinearColor(1.0f, 1.0f, 0.5f); // Yellow
        case EADAMood::Challenged:
            return FLinearColor(1.0f, 0.5f, 0.0f); // Orange
        case EADAMood::Frustrated:
            return FLinearColor(1.0f, 0.0f, 0.0f); // Red
        case EADAMood::Impressed:
            return FLinearColor(0.0f, 1.0f, 0.5f); // Green
        default:
            return FLinearColor::White;
    }
}

FString AADASystem::GetPersonalityDescription()
{
    switch (CurrentPersonality)
    {
        case EADAPersonality::Observer:
            return TEXT("The Entity observes your every move with curiosity...");
        case EADAPersonality::Tester:
            return TEXT("The Entity begins testing your limits...");
        case EADAPersonality::Counter:
            return TEXT("The Entity actively counters your strategies...");
        case EADAPersonality::Dominator:
            return TEXT("The Entity seeks to dominate your will...");
        case EADAPersonality::Experiment:
            return TEXT("The Entity experiments with reality itself...");
        default:
            return TEXT("The Entity watches...");
    }
}

void AADASystem::UpdateMoodBasedOnPerformance()
{
    float DeathRate = CurrentPlayerBehavior.DeathCount / FMath::Max(AdaptationData.CurrentFloor, 1);
    float SuccessRate = CurrentPlayerBehavior.ExtractionsCompleted / FMath::Max(AdaptationData.TotalRunsAnalyzed, 1);
    
    EADAMood OldMood = CurrentMood;
    
    if (DeathRate > 0.5f)
    {
        CurrentMood = EADAMood::Amused; // Player is struggling
    }
    else if (SuccessRate > 0.8f)
    {
        CurrentMood = EADAMood::Impressed; // Player is doing very well
    }
    else if (DeathRate < 0.1f && SuccessRate < 0.3f)
    {
        CurrentMood = EADAMood::Frustrated; // Player is too cautious/boring
    }
    else if (AdaptationData.AdaptationStrength > 0.5f)
    {
        CurrentMood = EADAMood::Challenged; // Good back-and-forth
    }
    else
    {
        CurrentMood = EADAMood::Curious; // Still learning
    }
    
    if (OldMood != CurrentMood)
    {
        UE_LOG(LogTemp, Display, TEXT("ADA Mood changed from %d to %d"), (int32)OldMood, (int32)CurrentMood);
    }
}

void AADASystem::AnalyzePatterns()
{
    // Analyze player patterns for adaptation
    for (auto& Pattern : PlayerActionHistory)
    {
        UE_LOG(LogTemp, Verbose, TEXT("ADA Pattern Analysis: %s = %f"), *Pattern.Key, Pattern.Value);
    }
}

void AADASystem::GeneratePersonalizedChallenge()
{
    // Create challenges specifically designed for this player
    TArray<FString> Counters = GenerateCounterStrategies();
    
    for (const FString& Counter : Counters)
    {
        UE_LOG(LogTemp, Display, TEXT("ADA: Implementing counter strategy: %s"), *Counter);
    }
    
    InjectPsychologicalElements();
}

void AADASystem::UpdateAdaptationStrength()
{
    AdaptationData.AdaptationStrength = CalculateAdaptationStrength(AdaptationData.CurrentFloor);
    
    UE_LOG(LogTemp, Display, TEXT("ADA: Adaptation strength updated to %f"), AdaptationData.AdaptationStrength);
}

EADAMood AADASystem::CalculateMoodFromBehavior()
{
    // Complex mood calculation based on multiple factors
    return CurrentMood;
}