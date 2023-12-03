// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShootRHSGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "Player/ShootRHSBaseCharacter.h"
#include "Player/ShootRHSPlayerController.h"

AShootRHSGameMode::AShootRHSGameMode()
{
	DefaultPawnClass = AShootRHSBaseCharacter::StaticClass();
	PlayerControllerClass = AShootRHSPlayerController::StaticClass();
}