#include "EternalDescent/Public/RPGClasses/ACharacterBase.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"


AACharacterBase::AACharacterBase()
{
    // Constructor code
    PrimaryActorTick.bCanEverTick = true;
}

void AACharacterBase::BeginPlay()
{
    Super::BeginPlay();
    // Your initialization code
}

void AACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        // Combat actions
        EnhancedInput->BindAction(AttackAction, ETriggerEvent::Started, this, &AACharacterBase::Attack);
        EnhancedInput->BindAction(BlockAction, ETriggerEvent::Started, this, &AACharacterBase::Block);
        EnhancedInput->BindAction(SecondaryAttackAction, ETriggerEvent::Started, this, &AACharacterBase::SecondaryAttack);
        EnhancedInput->BindAction(SpecialAction, ETriggerEvent::Started, this, &AACharacterBase::Special);
        EnhancedInput->BindAction(DodgeAction, ETriggerEvent::Started, this, &AACharacterBase::Dodge);
        
        // Gameplay actions
        EnhancedInput->BindAction(InteractAction, ETriggerEvent::Started, this, &AACharacterBase::Interact);
        EnhancedInput->BindAction(InventoryAction, ETriggerEvent::Started, this, &AACharacterBase::Inventory);
        EnhancedInput->BindAction(SkillsAction, ETriggerEvent::Started, this, &AACharacterBase::Skills);
        EnhancedInput->BindAction(MenuAction, ETriggerEvent::Started, this, &AACharacterBase::Menu);
    }
}
void AACharacterBase::Attack(const FInputActionValue& Value)
{
    // Attack logic here
}

void AACharacterBase::Block(const FInputActionValue& Value)
{
    // Block logic here
}

void AACharacterBase::SecondaryAttack(const FInputActionValue& Value)
{
    // Secondary attack logic here
}

void AACharacterBase::Special(const FInputActionValue& Value)
{
    // Special ability logic here
}

void AACharacterBase::Dodge(const FInputActionValue& Value)
{
    // Dodge logic here
}

void AACharacterBase::Interact(const FInputActionValue& Value)
{
    // Interact logic here
}

void AACharacterBase::Inventory(const FInputActionValue& Value)
{
    // Open inventory logic here
}

void AACharacterBase::Skills(const FInputActionValue& Value)
{
    // Open skills logic here
}

void AACharacterBase::Menu(const FInputActionValue& Value)
{
    // Open menu logic here
}

