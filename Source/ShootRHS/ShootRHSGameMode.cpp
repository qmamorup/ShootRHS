// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShootRHSGameMode.h"
#include "ShootRHSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AShootRHSGameMode::AShootRHSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
