// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomSelectorNode.h"

// Overrided execute node, see CustomBehaviorTree.h for more
ACustomBehaviorTreeNode* ACustomSelectorNode::ExecuteNode() 
{
	// Check if selector objects are initialized
	if (selectorObjects.Num() == 0) 
	{
		ConstructSelector(); // Construct selector if necessary
	}

	return SelectNode(); // Turn to select function to choose next node
}

// This function selects a node based on selection
ACustomBehaviorTreeNode* ACustomSelectorNode::SelectNode()
{
	return nullptr;
}

// This function contructs all selectors for selection node
void ACustomSelectorNode::ConstructSelector() 
{
	for (int i = 0; i < selectorClasses.Num(); i++) 
	{
		// Create default parameters for spawning
		FVector Location(0.0f, 0.0f, 0.0f);
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;

		// Spawn selector
		selectorObjects.Add(GetWorld()->SpawnActor<ACustomBehaviorTreeNode>(selectorClasses[i], Location, Rotation, SpawnInfo));
	}
}