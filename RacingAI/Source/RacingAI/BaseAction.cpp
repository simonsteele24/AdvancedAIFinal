// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAction.h"
#include "MyHatchbackAIController.h"

// Sets default values
ABaseAction::ABaseAction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseAction::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseAction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Performs specific action in decision tree
void ABaseAction::PerformAction(AMyHatchbackAIController* newController)
{
	controller = newController;
}