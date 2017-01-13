// Fill out your copyright notice in the Description page of Project Settings.

#include "ZombieProject.h"
#include "RandomPlayer_BP.h"


// Sets default values
ARandomPlayer_BP::ARandomPlayer_BP()
{
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
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

