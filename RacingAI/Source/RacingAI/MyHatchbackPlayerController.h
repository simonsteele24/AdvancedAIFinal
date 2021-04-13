// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyHatchback.h"
#include "MyHatchbackPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class RACINGAI_API AMyHatchbackPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
	AMyHatchback* Car;

	virtual void SetupInputComponent() override;

protected:

	void AddToAcceleration(float accelerationVal);
	void AddToSteering(float steeringVal);
	void ControlCameraX(float lookRightAxis);
	void ControlCameraY(float lookUpAxis);

};
