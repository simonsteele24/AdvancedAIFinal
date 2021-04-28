// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyHatchbackAIController.h"
#include "ReinforcementLearningManager.generated.h"

UENUM(BlueprintType)
enum Actions
{
	LEFT   UMETA(DisplayName = "LEFT"),
	RIGHT   UMETA(DisplayName = "RIGHT")
};

UENUM(BlueprintType)
enum Results
{
	PASS   UMETA(DisplayName = "Pass"),
	NOPASS   UMETA(DisplayName = "No Pass"),
	OFFTRACK UMETA(DisplayName = "Offtrack")
};

USTRUCT()
struct FRewardsStats
{
	GENERATED_BODY()

	float leftReward = 0.0f;
	float rightReward = 0.0f;
};

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

	UPROPERTY() TArray<FRewardsStats> map;
	UPROPERTY() TArray<TEnumAsByte<Actions>> actionsTaken;
	UPROPERTY() TArray<TEnumAsByte<Results>> resultsGiven;

	UPROPERTY() AMyHatchbackAIController* controller;

	UFUNCTION(BlueprintCallable) void InitializeManager(AMyHatchbackAIController * newController); // This function initializes all of the required components to get the RL manager to work
	UFUNCTION(BlueprintCallable) void CheckupManager(int checkpointNum); // This function calculates the reward based on actions given
	UFUNCTION() float GetAction(); // This function gets the action from the RL agent

};
