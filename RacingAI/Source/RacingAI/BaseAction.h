// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseAction.generated.h"

UCLASS()
class RACINGAI_API ABaseAction : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseAction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Performs specific action in decision tree
	UFUNCTION() virtual void PerformAction(class AMyHatchbackAIController* newController);

	/* Controllers */
	UPROPERTY() class AMyHatchbackAIController* controller;
};
