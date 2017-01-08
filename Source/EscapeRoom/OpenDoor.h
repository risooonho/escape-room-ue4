// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
    
    void OpenDoor();
    void CloseDoor();

private:
    UPROPERTY(EditAnywhere)
    float OpenAngle = 90.0f;
    
    UPROPERTY(EditAnywhere)
    ATriggerVolume* PressurePlate;
    
    
    UPROPERTY(EditAnywhere)
    float DoorCloseDelay = 1.0f;
    
    float LastOpenDoorTime;
    
    AActor * Owner;
    
    UPROPERTY(EditAnywhere)
    float MassTresholdForPressurePlate = 50.0f;
    
    float GetTotalMassOfActorsOnPlate();
		
	
};
