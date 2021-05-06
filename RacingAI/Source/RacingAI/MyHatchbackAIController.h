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
	UPROPERTY(BlueprintReadWrite) class ATrackBoundaryActor* rightwardTrackActor;
	UPROPERTY(BlueprintReadWrite) class ATrackBoundaryActor* leftwardTrackActor;

	//minimum distance for the slot steering to take over
									   /*
									   *  Minimum Activation distance is "=="
									   *
									   *		RL		  Track Boundary
											   /	   	  /
											  /		     /
											 |		    |
											|		   |
											 |		 A==|    CarPoint
											  |	         |
											   \		  \
												\		   \
									   */
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float minActivationDistance = 4.0f;

	UFUNCTION(BlueprintCallable)
	bool checkOnTrackLeft(FVector CarPos);

	UFUNCTION(BlueprintCallable)
	bool checkOnTrackRight(FVector CarPos);
};
