// Copyright Epic Games, Inc. All Rights Reserved.

#include "EternalDescentGameMode.h"
#include "EternalDescentCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEternalDescentGameMode::AEternalDescentGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
