// Fill out your copyright notice in the Description page of Project Settings.

#include "ZombieProject.h"
#include "RandomPlayer_BP.h"


// Sets default values
ARandomPlayer_BP::ARandomPlayer_BP()
{
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARandomPlayer_BP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARandomPlayer_BP::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ARandomPlayer_BP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//MovementInput
	InputComponent->BindAxis("MoveForward", this, &ARandomPlayer_BP::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ARandomPlayer_BP::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}

void ARandomPlayer_BP::MoveForward(float amount)
{
	if (Controller && amount)
	{
		AddMovementInput(GetActorForwardVector(), amount);
	}
}

void ARandomPlayer_BP::MoveRight(float amount)
{
	if (Controller && amount)
	{
		AddMovementInput(GetActorRightVector(), amount);
	}
}

void ARandomPlayer_BP::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ARandomPlayer_BP::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

