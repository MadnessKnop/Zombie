// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "RandomPlayer_BP.generated.h"

UCLASS()
class ZOMBIEPROJECT_API ARandomPlayer_BP : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARandomPlayer_BP();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float amount);

	void MoveRight(float amount);
	
};
