// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomBehaviorTreeNode.h"
#include "CustomSequencerNode.generated.h"

/**
 * 
 */
UCLASS()
class RACINGAI_API ACustomSequencerNode : public ACustomBehaviorTreeNode
{
	GENERATED_BODY()

public:

    /* Public Vars */
    UPROPERTY(EditDefaultsOnly) TArray<TSubclassOf<ACustomBehaviorTreeNode>> sequencerClasses; // Classes that will spawn nodes
    UPROPERTY() TArray<ACustomBehaviorTreeNode*> sequencerObjects; // Objects that represent the spawned nodes

    /* Public Funcs */
    UFUNCTION() ACustomBehaviorTreeNode* RunSequence(); // Runs all sequences in sequencer
    ACustomBehaviorTreeNode* ExecuteNode(); // Overrided execute node, see CustomBehaviorTree.h for more

protected:

    /* Private Funcs */
    UFUNCTION() void ConstructSequencer(); // This function contructs all nodes for sequence
};
