// Copyright 2025 Eternal Descent Studios

#include "RPGComponent.h"

// Sets default values for this component's properties
URPGComponent::URPGComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem"));
	AbilitySystem->SetIsReplicated(true);
	AbilitySystem->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
}

// Called when the game starts
void URPGComponent::BeginPlay()
{
	Super::BeginPlay();
	InitializeRPG();
}

void URPGComponent::InitializeRPG()
{
	Health = BaseHealth;
	MaxHealth = BaseHealth;
	Mana = BaseMana;
	MaxMana = BaseMana;
	Stamina = BaseStamina;
	MaxStamina = BaseStamina;
	Damage = BaseDamage;
	Armor = BaseArmor;
}

// Called every frame
void URPGComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

UAbilitySystemComponent* URPGComponent::GetAbilitySystemComponent() const
{
	return AbilitySystem;
}

