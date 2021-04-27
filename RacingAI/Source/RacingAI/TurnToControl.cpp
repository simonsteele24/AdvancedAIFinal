// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnToControl.h"
#include "MyHatchbackAIController.h"

// This function executes whenever the node is called
ACustomBehaviorTreeNode* ATurnToControl::ExecuteNode() 
{
	AMyHatchbackAIController* controller = Cast<AMyHatchbackAIController>(treeOwner);

	if (controller != nullptr) 
	{
		controller->Steering = controller->CheckpointLocation;
	}

	return nullptr;
}