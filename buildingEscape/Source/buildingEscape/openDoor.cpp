// Fill out your copyright notice in the Description page of Project Settings.

#include "buildingEscape.h"
#include "openDoor.h"


// Sets default values for this component's properties
UopenDoor::UopenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UopenDoor::BeginPlay()
{
	Super::BeginPlay();

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	owner = GetOwner();
}

void UopenDoor::OpenDoor()
{
	owner->SetActorRotation(FRotator(0.0f, openAngle, 0.0f));
}

void UopenDoor::CloseDoor()
{
	owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
}


// Called every frame
void UopenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
		lastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() > (lastDoorOpenTime + doorCloseDelay))
	{
		CloseDoor();
	}

	
}

