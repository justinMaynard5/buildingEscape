// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "openDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UopenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UopenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();

	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
private:
	UPROPERTY(EditAnywhere)
		float openAngle = 90.0f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate;

	AActor* owner;

	UPROPERTY(EditAnywhere)
		float doorCloseDelay = 1.0f;
	
	float lastDoorOpenTime;

	float GetTotalMassOnPlate();
};
