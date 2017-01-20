// Fill out your copyright notice in the Description page of Project Settings.

#include "ZombieProject.h"
#include "Item.h"


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	TBox->bGenerateOverlapEvents = true;
	//TBox->OnComponentBeginOverlap.AddDynamic(this, &AItem::TriggerEnter);
	//TBox->OnComponentEndOverlap.AddDynamic(this, &AItem::TriggerExit);
	RootComponent = TBox;

	SM_TBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box Mesh"));
	SM_TBox->AttachTo(RootComponent);
}

void AItem::GetPlayer(AActor* Player)
{
	MyPlayerController = Cast<ARandomPlayer_BP>(Player);
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItem::Pickup()
{
	//MyPlayerController->Inventory.Add();
	Destroy();
}

// Called every frame
void AItem::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (MyPlayerController != NULL)
	{
		if (MyPlayerController->IsPickingUp && ItemIsWithinRange)
		{
			Pickup();
		}
	}
}
//Bug from Unreal
//void AItem::TriggerEnter(AActor * OtherActor, UPrimitivComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
//{
//	ItemIsWithinRange = true;
//	GetPlayer(OtherActor);
//}
//
//void AItem::TriggerExit(AActor * OtherActor, UPrimitivComponent * OtherComp, int32 OtherBodyIndex)
//{
//	ItemIsWithinRange = false;
//}

