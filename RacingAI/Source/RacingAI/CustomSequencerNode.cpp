// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomSequencerNode.h"

// Overrided execute node, see CustomBehaviorTree.h for more
ACustomBehaviorTreeNode* ACustomSequencerNode::ExecuteNode()
{
	// Check if nodes are initialized
	if (sequencerObjects.Num() == 0)
	{
		ConstructSequencer(); // Construct sequencer if necessary
	}

	return RunSequence(); // run through all nodes
}

// Runs all sequences in sequencer
ACustomBehaviorTreeNode* ACustomSequencerNode::RunSequence()
{
	for (int i = 0; i < sequencerObjects.Num(); i++) 
	{
		sequencerObjects[i]->ExecuteNode();
	}

	return nullptr;
}

// This function contructs all nodes for sequence
void ACustomSequencerNode::ConstructSequencer()
{
	for (int i = 0; i < sequencerClasses.Num(); i++)
	{
		// Create default parameters for spawning
		FVector Location(0.0f, 0.0f, 0.0f);
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;

		// Spawn sequencer
		sequencerObjects.Add(GetWorld()->SpawnActor<ACustomBehaviorTreeNode>(sequencerClasses[i], Location, Rotation, SpawnInfo));
		sequencerObjects[sequencerObjects.Num() - 1]->treeOwner = treeOwner;
	}
}