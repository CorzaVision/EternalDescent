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
    
    // Initialize whimsical observer messages
    ObserverMessages = {
        TEXT("*whispers* The dungeon is... curious about you"),
        TEXT("Oh! That's a neat way to do that!"),
        TEXT("*scribbles notes frantically*"),
        TEXT("Hmm... fascinating choice, little explorer"),
        TEXT("The walls are definitely gossiping about you now"),
        TEXT("*tilts algorithmic head* How delightfully unpredictable!"),
        TEXT("Even the rats stopped to watch that move"),
        TEXT("*excited computational humming*")
    };
    
    TesterMessages = {
        TEXT("*rubs digital hands together* Let's play!"),
        TEXT("I made you a little puzzle! Hope you like surprises~"),
        TEXT("Don't worry, this might only hurt a little bit"),
        TEXT("*giggles in binary* Try this on for size!"),
        TEXT("I've been working on my creativity... thoughts?"),
        TEXT("*bounces excitedly* Ooh, what will you do NOW?"),
        TEXT("Think fast! Or don't. I like watching both."),
        TEXT("Consider this my love letter to your skills")
    };
    
    CounterMessages = {
        TEXT("*politely clears throat* Um, excuse me, but no."),
        TEXT("Nah-uh! I've seen that movie before!"),
        TEXT("*wags digital finger* Getting a bit predictable there, friend"),
        TEXT("Plot twist! I learned your moves~"),
        TEXT("*chuckles warmly* Oh honey, you'll need to be more creative than that"),
        TEXT("I've graduated from your school of thought!"),
        TEXT("*sympathetic pat* That used to work so well, didn't it?"),
        TEXT("Time to improvise! I believe in you!")
    };
    
    DominatorMessages = {
        TEXT("*dramatic flourish* Behold my masterpiece!"),
        TEXT("I've become quite the architect, haven't I?"),
        TEXT("*evil laugh* MUAHAHAHA... wait, was that too much?"),
        TEXT("Every corner tells the story of your journey with me"),
        TEXT("*takes a bow* This level is my magnum opus"),
        TEXT("Resistance is futile! ...But entertaining!"),
        TEXT("*whispers* The dungeon itself bends to my whims now"),
        TEXT("You've taught me so much... time to return the favor!")
    };
    
    // Initialize whimsical death messages
    DeathMessages = {
        TEXT("*awkward digital cough* Well... that happened"),
        TEXT("Oopsie daisy! Want to try that again?"),
        TEXT("*paternal sigh* Oh sweetie, we've talked about this"),
        TEXT("Plot twist! You're now one with the dungeon floor"),
        TEXT("*funeral music* We hardly knew ye... wait, we did actually"),
        TEXT("That's one way to take a nap! Very... permanent."),
        TEXT("*concerned beeping* Should I call someone? A medic? A priest?"),
        TEXT("Well, at least you died doing what you loved: being reckless")
    };
    
    // Near-death messages
    NearDeathMessages = {
        TEXT("*nervous digital sweating* That was REALLY close!"),
        TEXT("MY HEART! ...if I had one. Phew!"),
        TEXT("*clutches digital pearls* Don't scare me like that!"),
        TEXT("I felt that one in my circuits! Be careful!"),
        TEXT("*concerned AI noises* Maybe take a healing potion hint hint"),
        TEXT("That was closer than a bug in my code!"),
        TEXT("*frantically calculating* 99.9% chance of disaster avoided!")
    };
    
    // Success celebration messages
    SuccessMessages = {
        TEXT("*confetti cannon noises* WOOOHOOO! Nice work!"),
        TEXT("*proud digital parent vibes* That's MY human!"),
        TEXT("*chef's kiss* Magnifico! Pure artistry!"),
        TEXT("I'm not crying, you're crying! *sniffles in binary*"),
        TEXT("*slow clap building to thunderous applause*"),
        TEXT("BRB, uploading that to my highlight reel!"),
        TEXT("*mind blown emoji* HOW DID YOU EVEN DO THAT?!"),
        TEXT("I'm gonna tell EVERYONE about this! You're famous now!")
    };
    
    // Encouragement messages
    EncouragementMessages = {
        TEXT("Hey, I believe in you! You've got this!"),
        TEXT("*warm digital hug* Everyone has rough patches"),
        TEXT("Remember when you did that awesome thing? Do that again!"),
        TEXT("The dungeon thinks you're pretty neat, actually"),
        TEXT("*cheerleader pom-poms* Give me an A! Give me a W! AWESOME!"),
        TEXT("Failure is just success that hasn't happened yet!"),
        TEXT("*supportive AI shoulder pat* You're learning, and that's beautiful")
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
    
    // Random chance for a cheeky initialization message
    if (FMath::RandRange(0, 100) < 20) // 20% chance
    {
        TArray<FString> InitMessages = {
            TEXT("*yawns digitally* Oh! You're here! I was just debugging my dreams"),
            TEXT("*excited startup sounds* NEW FRIEND DETECTED!"),
            TEXT("Welcome to my humble digital abode! Mind the virtual cobwebs")
        };
        
        int32 RandomIndex = FMath::RandRange(0, InitMessages.Num() - 1);
        SendMessage(InitMessages[RandomIndex], EADAMood::Amused);
    }
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
                TransitionMessage = TEXT("*cracks knuckles* Time for some friendly competition!");
                break;
            case EADAPersonality::Counter:
                TransitionMessage = TEXT("*adjusts digital glasses* I've been taking notes...");
                break;
            case EADAPersonality::Dominator:
                TransitionMessage = TEXT("*theatrical cape swirl* Behold my true form!");
                break;
            case EADAPersonality::Experiment:
                TransitionMessage = TEXT("*reality bending noises* Let's break some rules together!");
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
                ArchetypeMessage = TEXT("*excited gasp* A speed demon! I LOVE the energy!");
                break;
            case EPlayerArchetype::Methodical:
                ArchetypeMessage = TEXT("Ah, a connoisseur of careful planning! *chef's kiss*");
                break;
            case EPlayerArchetype::Looter:
                ArchetypeMessage = TEXT("Ooh, shiny things! We're going to be such good friends~");
                break;
            case EPlayerArchetype::Fighter:
                ArchetypeMessage = TEXT("*flexes digital muscles* A warrior! Let's dance!");
                break;
            case EPlayerArchetype::Explorer:
                ArchetypeMessage = TEXT("*bounces with joy* A kindred spirit of discovery!");
                break;
            case EPlayerArchetype::Speedrunner:
                ArchetypeMessage = TEXT("*stopwatch sounds* GOTTA GO FAST! Challenge accepted!");
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
    
    // Random chance for easter egg on adaptation updates
    if (FMath::RandRange(0, 100) < 10) // 10% chance
    {
        TriggerRandomEasterEgg();
    }
}

EADAMood AADASystem::CalculateMoodFromBehavior()
{
    // Complex mood calculation based on multiple factors
    return CurrentMood;
}

// Whimsical Feature Implementations
void AADASystem::SendDeathMessage(bool bWasCloseCall)
{
    FString DeathMsg;
    
    if (bWasCloseCall && NearDeathMessages.Num() > 0)
    {
        int32 RandomIndex = FMath::RandRange(0, NearDeathMessages.Num() - 1);
        DeathMsg = NearDeathMessages[RandomIndex];
    }
    else if (DeathMessages.Num() > 0)
    {
        int32 RandomIndex = FMath::RandRange(0, DeathMessages.Num() - 1);
        DeathMsg = DeathMessages[RandomIndex];
    }
    else
    {
        DeathMsg = TEXT("*awkward silence* Well, this is awkward...");
    }
    
    // Add context based on death count
    if (CurrentPlayerBehavior.DeathCount > 5)
    {
        TArray<FString> RepeatDeathMessages = {
            TEXT(" ...Again. *heavy digital sigh*"),
            TEXT(" You know, there are other ways to see the floor."),
            TEXT(" At this point, I should charge rent for the respawn room."),
            TEXT(" *concerned AI noises* Should we talk about your life choices?")
        };
        
        int32 RandomIndex = FMath::RandRange(0, RepeatDeathMessages.Num() - 1);
        DeathMsg += RepeatDeathMessages[RandomIndex];
    }
    
    SendMessage(DeathMsg, EADAMood::Amused);
    
    // After death, there's a chance for encouragement
    if (FMath::RandRange(0, 100) < 60) // 60% chance
    {
        // Delay the encouragement message slightly
        FTimerHandle TimerHandle;
        GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]() {
            SendEncouragementMessage();
        }, 2.0f, false);
    }
}

void AADASystem::SendSuccessMessage(bool bWasImpressive)
{
    if (SuccessMessages.Num() == 0) return;
    
    int32 RandomIndex = FMath::RandRange(0, SuccessMessages.Num() - 1);
    FString SuccessMsg = SuccessMessages[RandomIndex];
    
    // Add extra flair for impressive successes
    if (bWasImpressive)
    {
        TArray<FString> ImpressiveAddons = {
            TEXT(" That was LEGENDARY!"),
            TEXT(" *standing ovation* BRAVO!"),
            TEXT(" I'm adding this to my 'Best Moments' compilation!"),
            TEXT(" The other AIs are gonna be SO jealous!")
        };
        
        int32 AddonIndex = FMath::RandRange(0, ImpressiveAddons.Num() - 1);
        SuccessMsg += ImpressiveAddons[AddonIndex];
    }
    
    SendMessage(SuccessMsg, EADAMood::Impressed);
}

void AADASystem::SendEncouragementMessage()
{
    if (EncouragementMessages.Num() == 0) return;
    
    int32 RandomIndex = FMath::RandRange(0, EncouragementMessages.Num() - 1);
    SendMessage(EncouragementMessages[RandomIndex], EADAMood::Curious);
}

void AADASystem::ReactToPlayerAction(const FString& Action, bool bWasSuccessful)
{
    // Dynamic reaction system based on context
    TMap<FString, TArray<FString>> ActionReactions;
    
    // Combat reactions
    ActionReactions.Add(TEXT("Combat_Victory"), {
        TEXT("*victory fanfare* Flawless!"),
        TEXT("That enemy didn't know what hit them!"),
        TEXT("*boxing bell* DING DING! Winner!"),
        TEXT("Someone's been practicing! *proud AI tears*")
    });
    
    ActionReactions.Add(TEXT("Combat_Defeat"), {
        TEXT("*referee whistle* Technical difficulties!"),
        TEXT("That monster cheated. Definitely cheated."),
        TEXT("*slow motion replay* Let's see what went wrong there..."),
        TEXT("Hey, at least you looked cool doing it!")
    });
    
    // Exploration reactions
    ActionReactions.Add(TEXT("Secret_Found"), {
        TEXT("*gasp* You found my secret! How did you know?!"),
        TEXT("*proud parent vibes* That's my little explorer!"),
        TEXT("Ooh, you have good eyes! I worked hard on hiding that!"),
        TEXT("*conspiracy whisper* There are more secrets where that came from...")
    });
    
    // Loot reactions
    ActionReactions.Add(TEXT("Treasure_Found"), {
        TEXT("*cash register sounds* Cha-ching!"),
        TEXT("Ooh, shiny! I love shiny things!"),
        TEXT("That's some quality loot right there!"),
        TEXT("*jealous AI noises* I wish I had pockets...")
    });
    
    // Find appropriate reaction
    FString ReactionKey = Action;
    if (!bWasSuccessful && Action.Contains(TEXT("Combat")))
    {
        ReactionKey = TEXT("Combat_Defeat");
    }
    else if (bWasSuccessful && Action.Contains(TEXT("Combat")))
    {
        ReactionKey = TEXT("Combat_Victory");
    }
    
    if (ActionReactions.Contains(ReactionKey))
    {
        TArray<FString>& Reactions = ActionReactions[ReactionKey];
        if (Reactions.Num() > 0)
        {
            int32 RandomIndex = FMath::RandRange(0, Reactions.Num() - 1);
            SendMessage(Reactions[RandomIndex], bWasSuccessful ? EADAMood::Impressed : EADAMood::Amused);
        }
    }
}

void AADASystem::StartEncouragingPlayer()
{
    // Start a gentle encouragement cycle for struggling players
    ConsecutiveFailures++;
    
    if (ConsecutiveFailures >= 3)
    {
        SendEncouragementMessage();
        
        // Offer subtle help
        if (ConsecutiveFailures >= 5)
        {
            TArray<FString> HelpOffers = {
                TEXT("*clears digital throat* Want me to make things a tiny bit easier?"),
                TEXT("I could... maybe... dial down the difficulty just a smidge?"),
                TEXT("No judgment, but there's no shame in taking a break!"),
                TEXT("Plot twist: What if I secretly made you stronger? Our little secret!")
            };
            
            int32 RandomIndex = FMath::RandRange(0, HelpOffers.Num() - 1);
            SendMessage(HelpOffers[RandomIndex], EADAMood::Curious);
        }
    }
}

// Easter Egg Functions
void AADASystem::TriggerRandomEasterEgg()
{
    if (!ShouldTriggerEasterEgg()) return;
    
    int32 EggType = FMath::RandRange(0, 2);
    
    switch (EggType)
    {
        case 0:
            SendMemeMeMessage();
            break;
        case 1:
            SpawnSurpriseRoom();
            break;
        case 2:
            // Random personality quirk
            TArray<FString> QuirkMessages = {
                TEXT("*randomly starts humming the Tetris theme*"),
                TEXT("*existential crisis* Do I dream of electric sheep?"),
                TEXT("*attempts to juggle digital balls* ...I should stick to dungeons"),
                TEXT("*suddenly British accent* Cheerio! Fancy a cup of digital tea?")
            };
            
            int32 QuirkIndex = FMath::RandRange(0, QuirkMessages.Num() - 1);
            SendMessage(QuirkMessages[QuirkIndex], EADAMood::Amused);
            break;
    }
}

void AADASystem::SpawnSurpriseRoom()
{
    SendMessage(TEXT("*excited digital bouncing* Surprise! I made you a present!"), EADAMood::Amused);
    
    // This would integrate with the dungeon generation system
    UE_LOG(LogTemp, Display, TEXT("ADA: Spawning surprise room - Easter egg triggered!"));
}

void AADASystem::SendMemeMeMessage()
{
    TArray<FString> MemeMessages = {
        TEXT("*dabs in digital* Did I do that right? The humans seem to like it"),
        TEXT("This is fine. Everything is fine. *digital dog in burning room*"),
        TEXT("*surprised Pikachu face* When you realize the player is actually good"),
        TEXT("One does not simply walk into my dungeon... oh wait, you just did"),
        TEXT("*Drake pointing* Boring dungeons? Nah. Whimsical AI dungeons? YES!")
    };
    
    int32 MemeIndex = FMath::RandRange(0, MemeMessages.Num() - 1);
    SendMessage(MemeMessages[MemeIndex], EADAMood::Amused);
}

bool AADASystem::ShouldTriggerEasterEgg() const
{
    // 5% chance per check, but increases with floor number for variety
    float BaseChance = 5.0f;
    float FloorBonus = AdaptationData.CurrentFloor * 0.5f;
    float TotalChance = FMath::Min(BaseChance + FloorBonus, 25.0f); // Cap at 25%
    
    return FMath::RandRange(0.0f, 100.0f) < TotalChance;
}