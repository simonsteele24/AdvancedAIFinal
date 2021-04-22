// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAction.h"
#include "TurnRightAction.generated.h"

/**
 * 
 */
UCLASS()
class RACINGAI_API ATurnRightAction : public ABaseAction
{
	GENERATED_BODY()
	
public:
	void PerformAction(class AMyHatchbackAIController* newController);
};
