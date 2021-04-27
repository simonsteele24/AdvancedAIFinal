// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomBehaviorTreeNode.h"
#include "DecisionTree.h"
#include "ExecuteDeicisionTreeNode.generated.h"

/**
 * 
 */
UCLASS()
class RACINGAI_API AExecuteDeicisionTreeNode : public ACustomBehaviorTreeNode
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly) TSubclassOf<ADecisionTree> decisionTreeClass; // Represents decision tree class

	ACustomBehaviorTreeNode* ExecuteNode(); // This function executes whenever the node is called

protected:

	UPROPERTY() ADecisionTree* decisionTreeObject; // Represents decision tree

	UFUNCTION() void BuildDecisionTree(); // This function builds the decision tree

};
