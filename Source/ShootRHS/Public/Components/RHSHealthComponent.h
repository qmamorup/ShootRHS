// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RHSHealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTRHS_API URHSHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	URHSHealthComponent();

	float GetHealth() const { return Health; }

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Health", meta=(ClampMin = "0.0", ClampMax = "1000.0"))
	float MaxHealth = 100.0f;
	
	virtual void BeginPlay() override;

private:
	float Health = 0.0f;
};
