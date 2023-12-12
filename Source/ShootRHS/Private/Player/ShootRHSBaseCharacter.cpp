// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ShootRHSBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/RHSCharacterMovementComponent.h"

// Sets default values
AShootRHSBaseCharacter::AShootRHSBaseCharacter(const FObjectInitializer& ObjectInit) : Super(ObjectInit.SetDefaultSubobjectClass<URHSCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void AShootRHSBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShootRHSBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShootRHSBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AShootRHSBaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AShootRHSBaseCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AShootRHSBaseCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnAround", this, &AShootRHSBaseCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AShootRHSBaseCharacter::Jump);
	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &AShootRHSBaseCharacter::OnStartRunning);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &AShootRHSBaseCharacter::OnStopRunning);
}

void AShootRHSBaseCharacter::MoveForward(float Amount)
{
	IsMovingForward = Amount > 0.0f;
	AddMovementInput(GetActorForwardVector(), Amount);
}

void AShootRHSBaseCharacter::MoveRight(float Amount)
{
	AddMovementInput(GetActorRightVector(), Amount);
}

void AShootRHSBaseCharacter::OnStartRunning()
{
	WantsToRun = true;
}

void AShootRHSBaseCharacter::OnStopRunning()
{
	WantsToRun = false;
}

bool AShootRHSBaseCharacter::IsRunning() const 
{
	return WantsToRun && IsMovingForward && !GetVelocity().IsZero();
}