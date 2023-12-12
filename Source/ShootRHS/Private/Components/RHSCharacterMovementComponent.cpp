// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/RHSCharacterMovementComponent.h"
#include "Player/ShootRHSBaseCharacter.h"

float URHSCharacterMovementComponent::GetMaxSpeed() const
{
	const float MaxSpeed = Super::GetMaxSpeed();
	const AShootRHSBaseCharacter* Player = Cast<AShootRHSBaseCharacter>(GetPawnOwner());
	return Player && Player->IsRunning() ? MaxSpeed* RunModifier: MaxSpeed;
}