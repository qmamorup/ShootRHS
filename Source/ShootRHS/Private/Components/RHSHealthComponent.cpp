// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/RHSHealthComponent.h"

URHSHealthComponent::URHSHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void URHSHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
}


