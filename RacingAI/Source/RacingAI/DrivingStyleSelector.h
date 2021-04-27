// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomSelectorNode.h"
#include "DrivingStyleSelector.generated.h"

/**
 * 
 */
UCLASS()
class RACINGAI_API ADrivingStyleSelector : public ACustomSelectorNode
{
	GENERATED_BODY()
	
public:
	ACustomBehaviorTreeNode* SelectNode(); // This function selects a node based on selection
};
