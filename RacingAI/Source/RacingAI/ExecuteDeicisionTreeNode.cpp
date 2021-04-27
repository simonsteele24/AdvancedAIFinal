// Fill out your copyright notice in the Description page of Project Settings.


#include "ExecuteDeicisionTreeNode.h"
#include "Kismet/GameplayStatics.h"
#include "MyHatchbackAIController.h"

// This function executes whenever the node is called
ACustomBehaviorTreeNode* AExecuteDeicisionTreeNode::ExecuteNode()
{
	// Build tree if necessary
	if (decisionTreeObject == nullptr) 
	{
		BuildDecisionTree();
	}

	// Traverse decision
	decisionTreeObject->TraverseTree();

	return nullptr;
}

// This function builds the decision tree
void AExecuteDeicisionTreeNode::BuildDecisionTree() 
{
	// Create default parameters for spawning
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

	// Spawn and initialize tree
	decisionTreeObject = GetWorld()->SpawnActor<ADecisionTree>(decisionTreeClass, Location, Rotation, SpawnInfo);
	decisionTreeObject->ConstructTree(Cast<AMyHatchbackAIController>(treeOwner));
}