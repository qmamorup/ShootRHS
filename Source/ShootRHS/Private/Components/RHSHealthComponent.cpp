// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/RHSHealthComponent.h"
#include "GameFramework/Actor.h"
#include "Dev/RHSFireDamageType.h"
#include "Dev/RHSIceDamageType.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthComponent, All, All)

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
	UE_LOG(LogHealthComponent, Display, TEXT("Damage: %f"), Damage);

	if (DamageType)
	{
		if (DamageType->IsA<URHSFireDamageType>())
		{
			UE_LOG(LogHealthComponent, Display, TEXT("So hoooot !!!"));
		}
		else if (DamageType->IsA<URHSIceDamageType>())
		{
			UE_LOG(LogHealthComponent, Display, TEXT("So coooold !!!"));
		}
	}
}

