// Copyright 2025 Eternal Descent Studios

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "RPGComponent.generated.h"


UCLASS(ClassGroup=(RPG), BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class ETERNALDESCENT_API URPGComponent : public UActorComponent, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URPGComponent();

	// Runtime values (initialized from Base* in BeginPlay)
	UPROPERTY(BlueprintReadOnly, Category="RPG|Runtime")
	float Health;

	UPROPERTY(BlueprintReadOnly, Category="RPG|Runtime")
	float Mana;

	UPROPERTY(BlueprintReadOnly, Category="RPG|Runtime")
	float Stamina;

	UPROPERTY(BlueprintReadOnly, Category="RPG|Runtime")
	float Damage;

	UPROPERTY(BlueprintReadOnly, Category="RPG|Runtime")
	float Armor;

	// Designer defaults (set in Blueprint)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RPG|Defaults", meta=(ClampMin="0.0", UIMin="0.0"))
	float BaseHealth = 100.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RPG|Defaults", meta=(ClampMin="0.0", UIMin="0.0"))
	float BaseMana = 50.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RPG|Defaults", meta=(ClampMin="0.0", UIMin="0.0"))
	float BaseStamina = 100.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RPG|Defaults", meta=(ClampMin="0.0", UIMin="0.0"))
	float BaseDamage = 10.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RPG|Defaults", meta=(ClampMin="0.0", UIMin="0.0"))
	float BaseArmor = 0.f;

	// Runtime max values (calculated from Base values)
	UPROPERTY(BlueprintReadOnly, Category="RPG|Runtime")
	float MaxHealth;

	UPROPERTY(BlueprintReadOnly, Category="RPG|Runtime")
	float MaxMana;

	UPROPERTY(BlueprintReadOnly, Category="RPG|Runtime")
	float MaxStamina;

	// Ability System
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="RPG|GAS")
	TObjectPtr<UAbilitySystemComponent> AbilitySystem;

	// Get the ability system component
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category="RPG")
	void InitializeRPG();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
