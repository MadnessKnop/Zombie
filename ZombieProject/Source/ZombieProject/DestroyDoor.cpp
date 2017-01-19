// Fill out your copyright notice in the Description page of Project Settings.

#include "ZombieProject.h"
#include "DestroyDoor.h"
#include "RandomPlayer_BP.h"

// Sets default values for this component's properties
UDestroyDoor::UDestroyDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDestroyDoor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDestroyDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	OpenAngle();
	// ...
}

void UDestroyDoor::OpenAngle()
{
	ARandomPlayer_BP * MyPawn = Cast<ARandomPlayer_BP>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (MyPawn->GetDoorOpen())
	{
		GetOwner()->Destroy();
	}
}

