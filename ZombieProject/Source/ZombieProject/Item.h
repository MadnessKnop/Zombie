// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/Actor.h"
#include "RandomPlayer_BP.h"
#include "Item.generated.h"

UCLASS()
class ZOMBIEPROJECT_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UShapeComponent* TBox;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SM_TBox;

	ARandomPlayer_BP* MyPlayerController;

	UPROPERTY(EditAnywhere)
		FString ItemName = FString(TEXT(""));

	void Pickup();
	void GetPlayer(AActor* Player);
	bool ItemIsWithinRange = false;

	//Bug from Unreal
	//UFUNCTION()
	//	void TriggerEnter(class AActor* OtherActor, class UPrimitivComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	//UFUNCTION()
	//	void TriggerExit(class AActor* OtherActor, class UPrimitivComponent* OtherComp, int32 OtherBodyIndex);
	
};
