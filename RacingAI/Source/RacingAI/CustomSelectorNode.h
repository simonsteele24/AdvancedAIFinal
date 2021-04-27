// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomBehaviorTreeNode.h"
#include "CustomSelectorNode.generated.h"

/**
 * 
 */
UCLASS()
class RACINGAI_API ACustomSelectorNode : public ACustomBehaviorTreeNode
{
	GENERATED_BODY()

public:

    /* Public Vars */
    UPROPERTY(EditDefaultsOnly) TArray<TSubclassOf<ACustomBehaviorTreeNode>> selectorClasses; // Classes that will spawn selector nodes
    UPROPERTY() TArray<ACustomBehaviorTreeNode*> selectorObjects; // Objects that represent the spawned selector nodes

    /* Public Funcs */
    UFUNCTION() virtual ACustomBehaviorTreeNode* SelectNode(); // This function selects a node based on selection
    ACustomBehaviorTreeNode* ExecuteNode(); // Overrided execute node, see CustomBehaviorTree.h for more

protected:

    /* Private Funcs */
    UFUNCTION() void ConstructSelector(); // This function contructs all selectors for selection node
};
