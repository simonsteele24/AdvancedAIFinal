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
};
