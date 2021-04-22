// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAction.h"
#include "TurnLeftAction.generated.h"

/**
 * 
 */
UCLASS()
class RACINGAI_API ATurnLeftAction : public ABaseAction
{
	GENERATED_BODY()
	
public:
	void PerformAction(class AMyHatchbackAIController* newController);
};
