// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHatchback.h"
#include "WheeledVehicleMovementComponent.h"

// Called every frame
void AMyHatchback::Tick(float DeltaTime)
{
	FVector directionOfGravity = GetActorUpVector();

	GetMesh()->AddForce(directionOfGravity * gravityStrength);

	Super::Tick(DeltaTime);

}

void AMyHatchback::AddToAcceleration(float newAxisVal) 
{
	GetVehicleMovement()->SetThrottleInput(newAxisVal);
}

void AMyHatchback::AddToSteering(float newSteeringVal) 
{
	GetVehicleMovement()->SetSteeringInput(newSteeringVal);
}

void AMyHatchback::Brake(bool bIsBraking) 
{
	GetVehicleMovement()->SetBrakeInput(bIsBraking);
}

void AMyHatchback::ControlCamera(float lookUpAxis, float lookRightAxis) 
{
	AddControllerPitchInput(lookUpAxis * -1.0f);
	AddControllerYawInput(lookRightAxis);
}