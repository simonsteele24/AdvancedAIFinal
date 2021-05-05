// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyHatchbackAIController.generated.h"

/**
 * 
 */
UCLASS()
class RACINGAI_API AMyHatchbackAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite) FVector Steering;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite) float AutoThrottle;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite) FVector CheckpointLocation;
	UPROPERTY(EditDefaultsOnly) class AReinforcementLearningManager* manager;
	UPROPERTY(BlueprintReadWrite) int numOfCheckpoints = 0;
	UPROPERTY(BlueprintReadWrite) FVector racingLinePoint;
	UPROPERTY(BlueprintReadWrite) FVector leftLinePoint;
	UPROPERTY(BlueprintReadWrite) FVector rightLinePoint;
	UPROPERTY(BlueprintReadWrite) class ATrackBoundaryActor* rightwardTrackActor;
	UPROPERTY(BlueprintReadWrite) class ATrackBoundaryActor* leftwardTrackActor;

	UFUNCTION(BlueprintCallable)
	bool checkOnTrackLeft(FVector CarPos);

	UFUNCTION(BlueprintCallable)
	bool checkOnTrackRight(FVector CarPos);
};
