// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "MyHatchback.generated.h"

/**
 * 
 */
UCLASS()
class RACINGAI_API AMyHatchback : public AWheeledVehicle
{
	GENERATED_BODY()
	
public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float maxRPM = 9000.f;

	UPROPERTY(EditAnywhere)
	float lowTargetRPM = 500.f;

	UPROPERTY(EditAnywhere)
	float highTargetRPM = 8800.f;

	UPROPERTY(EditAnywhere)
	int numGears = 6;

	UPROPERTY(EditAnywhere)
	float gravityStrength = -2000000.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float aiSpeed = 0.0f;

	UFUNCTION(BlueprintCallable)
	void AddToAcceleration(float newAxisVal);

	UFUNCTION(BlueprintCallable)
	void AddToSteering(float newSteeringVal);

	UFUNCTION(BlueprintCallable)
	void Brake(bool bIsBraking);

	UFUNCTION(BlueprintCallable)
	void ControlCamera(float lookUpAxis, float lookRightAxis);

protected:

};
