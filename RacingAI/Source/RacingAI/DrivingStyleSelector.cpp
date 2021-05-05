// Fill out your copyright notice in the Description page of Project Settings.


#include "DrivingStyleSelector.h"
#include "MyHatchbackAIController.h"
#include "ReinforcementLearningManager.h"

ACustomBehaviorTreeNode* ADrivingStyleSelector::SelectNode() 
{
	AMyHatchbackAIController* controller = Cast<AMyHatchbackAIController>(treeOwner);

	// RL actions override everything
	if (controller->manager->GetAction() != 0.0f) 
	{
		selectorObjects[2]->ExecuteNode();
		return selectorObjects[2];
	}

	// Obstacle avoidance follows second
	if (controller != nullptr) 
	{
		AActor* car = controller->GetPawn();
		FVector location = controller->CheckpointLocation;

		FVector direction = location - car->GetActorLocation();
		direction.Normalize();

		float dotProd = FVector::DotProduct(direction, car->GetActorForwardVector());

		if (dotProd < 0) 
		{
			selectorObjects[1]->ExecuteNode();
			return selectorObjects[1];
		}
	}

	// LOOK HERE COLTON!!!
	// If you want it to switch to the slot to car track node use this:
	// return selectorObjects[3];

	// If all else fails, then go to just following the racing line
	selectorObjects[0]->ExecuteNode();
	return selectorObjects[0];
}