// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/RHSHealthComponent.h"
#include "GameFramework/Actor.h"

URHSHealthComponent::URHSHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void URHSHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;

	AActor* ComponentOwner = GetOwner();
	if (ComponentOwner)
	{
		ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &URHSHealthComponent::OnTakeAnyDamage);
	}
}

void URHSHealthComponent::OnTakeAnyDamage(
	AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	Health -= Damage;
}

