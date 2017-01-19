// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "RandomPlayer_BP.generated.h"

UCLASS()
class ZOMBIEPROJECT_API ARandomPlayer_BP : public ACharacter
{
	GENERATED_BODY()

		//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		//class UCameraComponent* FirstPersonCameraComponent;

public:
	// Sets default values for this character's properties
	ARandomPlayer_BP();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	void MoveForward(float amount);

	void MoveRight(float amount);

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	void OpenDoor();

	bool GetDoorOpen();

	void IsDoorOpenTrue(bool DoorOpened);

private:

	bool DoorOpen = false;
};
