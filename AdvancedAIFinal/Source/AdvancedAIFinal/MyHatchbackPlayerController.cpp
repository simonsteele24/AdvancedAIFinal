// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHatchbackPlayerController.h"
#include "Kismet/GameplayStatics.h"

void AMyHatchbackPlayerController::BeginPlay() 
{
	Car = Cast<AMyHatchback>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

void AMyHatchbackPlayerController::SetupInputComponent() 
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &AMyHatchbackPlayerController::AddToAcceleration);
	InputComponent->BindAxis("MoveRight", this, &AMyHatchbackPlayerController::AddToSteering);
	InputComponent->BindAxis("LookUp", this, &AMyHatchbackPlayerController::ControlCameraY);
	InputComponent->BindAxis("LookRight", this, &AMyHatchbackPlayerController::ControlCameraX);
}

void AMyHatchbackPlayerController::AddToAcceleration(float accelerationVal) 
{
	Car->AddToAcceleration(accelerationVal);
}

void AMyHatchbackPlayerController::AddToSteering(float steeringVal) 
{
	Car->AddToSteering(steeringVal);
}

void AMyHatchbackPlayerController::ControlCameraY(float lookUpAxis) 
{
	Car->AddControllerPitchInput(lookUpAxis * -1.0f);
}

void AMyHatchbackPlayerController::ControlCameraX(float lookRightAxis) 
{
	Car->AddControllerYawInput(lookRightAxis);
}