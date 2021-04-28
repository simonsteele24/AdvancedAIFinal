// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyHatchbackAIController.h"
#include "ReinforcementLearningManager.generated.h"

UCLASS()
class RACINGAI_API AReinforcementLearningManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AReinforcementLearningManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// TMap<int, FActionsMap> map
	// TArray<ActionsEnum> actionsTaken
	// TArray<ResultsEnum> resultsGiven

	AMyHatchbackAIController* controller;

	UFUNCTION(BlueprintCallable) void InitializeManager(AMyHatchbackAIController * newController); // This function initializes all of the required components to get the RL manager to work
	UFUNCTION(BlueprintCallable) void CheckupManager(int checkpointNum); // This function calculates the reward based on actions given
	UFUNCTION() float GetAction(); // This function gets the action from the RL agent

};
