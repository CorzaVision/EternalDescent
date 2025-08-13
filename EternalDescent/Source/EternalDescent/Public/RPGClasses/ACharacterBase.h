// Copyright 2025 CorzaVision Indie Game

#pragma once

#include "CoreMinimal.h"
#include "EternalDescent/EternalDescentCharacter.h"
#include "ACharacterBase.generated.h"

class UInputMappingContext;
class UInputAction;
class UEnhancedInputComponent;


UCLASS()
class ETERNALDESCENT_API AACharacterBase : public AEternalDescentCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AACharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Combat Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* DodgeAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* AttackAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* BlockAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* SecondaryAttackAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* SpecialAction;

	// Gameplay Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* InteractAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* InventoryAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* SkillsAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MenuAction;


	// Enhanced Input Component
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Input")
	UEnhancedInputComponent* EnhancedInputComponent;

	// Input Mapping Context
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* InputMappingContext;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



	// Combat Functions
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void Attack(const FInputActionValue& Value);
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void Block(const FInputActionValue& Value);
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void SecondaryAttack(const FInputActionValue& Value);
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void Special(const FInputActionValue& Value);
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void Dodge(const FInputActionValue& Value);

	// Gameplay Functions
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void Interact(const FInputActionValue& Value);
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void Inventory(const FInputActionValue& Value);
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void Skills(const FInputActionValue& Value);
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void Menu(const FInputActionValue& Value);
	
};
