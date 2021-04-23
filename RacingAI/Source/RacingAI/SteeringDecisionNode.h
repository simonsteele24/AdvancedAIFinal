// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseDecisionNode.h"
#include "DrawDebugHelpers.h"
#include "SteeringDecisionNode.generated.h"

/**
 * 
 */
UCLASS()
class RACINGAI_API ASteeringDecisionNode : public ABaseDecisionNode
{
	GENERATED_BODY()
	
protected:
	UFUNCTION() class AMyHatchback* GetClosestCar();

public:
	ABaseDecisionNode* ExecuteDecision(class AMyHatchbackAIController* newController, bool& bHasFoundAction);

};
