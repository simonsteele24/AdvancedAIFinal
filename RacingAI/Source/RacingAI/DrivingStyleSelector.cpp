// Fill out your copyright notice in the Description page of Project Settings.


#include "DrivingStyleSelector.h"
#include "MyHatchbackAIController.h"

ACustomBehaviorTreeNode* ADrivingStyleSelector::SelectNode() 
{
	AMyHatchbackAIController* controller = Cast<AMyHatchbackAIController>(treeOwner);
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

	selectorObjects[0]->ExecuteNode();
	return selectorObjects[0];
}