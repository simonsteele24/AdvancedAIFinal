// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHatchback.h"
#include "WheeledVehicleMovementComponent.h"

// Called every frame
void AMyHatchback::Tick(float DeltaTime)
{
	FVector directionOfGravity = GetActorUpVector();

	GetMesh()->AddForce(directionOfGravity * gravityStrength);
	GetVehicleMovement()->MaxEngineRPM = maxRPM;
	//GetVehicleMovement()->gear

	Super::Tick(DeltaTime);

}

void AMyHatchback::AddToAcceleration(float newAxisVal) 
{
	if (GetVehicleMovement()->GetEngineRotationSpeed() <= lowTargetRPM)
	{
		if (GetVehicleMovement()->GetCurrentGear() >= 2)
		{
			//downshift
			GetVehicleMovement()->SetGearDown(true);
		}
	}

	if (GetVehicleMovement()->GetEngineRotationSpeed() >= highTargetRPM)
	{
		//upshift
		GetVehicleMovement()->SetGearUp(true);
	}
	

	GetVehicleMovement()->SetThrottleInput(newAxisVal);
}

void AMyHatchback::AddToSteering(float newSteeringVal) 
{
	GetVehicleMovement()->SetSteeringInput(newSteeringVal);
}

void AMyHatchback::Brake(bool bIsBraking) 
{
	if (GetVehicleMovement()->GetEngineRotationSpeed() <= lowTargetRPM)
	{
		if (GetVehicleMovement()->GetCurrentGear() >= 2)
		{
			//downshift
			GetVehicleMovement()->SetGearDown(true);
		}
	}

	if (GetVehicleMovement()->GetEngineRotationSpeed() >= highTargetRPM)
	{
		//upshift
		GetVehicleMovement()->SetGearUp(true);
	}

	GetVehicleMovement()->SetBrakeInput(bIsBraking);
}

void AMyHatchback::ControlCamera(float lookUpAxis, float lookRightAxis) 
{
	AddControllerPitchInput(lookUpAxis * -1.0f);
	AddControllerYawInput(lookRightAxis);
}