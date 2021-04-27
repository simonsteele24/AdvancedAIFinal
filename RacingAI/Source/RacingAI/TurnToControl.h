// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomBehaviorTreeNode.h"
#include "TurnToControl.generated.h"

/**
 * 
 */
UCLASS()
class RACINGAI_API ATurnToControl : public ACustomBehaviorTreeNode
{
	GENERATED_BODY()
	
public:

	ACustomBehaviorTreeNode* ExecuteNode(); // This function executes whenever the node is called

};
