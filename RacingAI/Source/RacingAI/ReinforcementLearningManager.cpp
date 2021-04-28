// Fill out your copyright notice in the Description page of Project Settings.


#include "ReinforcementLearningManager.h"

// Sets default values
AReinforcementLearningManager::AReinforcementLearningManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AReinforcementLearningManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReinforcementLearningManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// This function initializes all of the required components to get the RL manager to work
void AReinforcementLearningManager::InitializeManager(AMyHatchbackAIController* newController)
{
	controller = newController;
}

// This function calculates the reward based on actions given
void AReinforcementLearningManager::CheckupManager(int checkpointNum) 
{

}

// This function gets the action from the RL agent 
float AReinforcementLearningManager::GetAction() 
{
	return 0.0f;
}