// Fill out your copyright notice in the Description page of Project Settings.


#include "DrivingStyleSelector.h"
#include "MyHatchbackAIController.h"
#include "MyHatchback.h"
#include "ReinforcementLearningManager.h"
#include "TrackBoundaryActor.h"


ACustomBehaviorTreeNode* ADrivingStyleSelector::SelectNode() 
{
	AMyHatchbackAIController* controller = Cast<AMyHatchbackAIController>(treeOwner);

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
			Cast<AMyHatchback>(car)->decisionIndex = 1;
			return selectorObjects[1];
		}
	}

	// If you want it to switch to the slot to car track node use this:
	FVector P = controller->GetPawn()->GetActorLocation();
	FVector ALeft = controller->leftwardTrackActor->getPath()->FindLocationClosestToWorldLocation(P, ESplineCoordinateSpace::World);// + FVector(0.0f, controller->minActivationDistance, 0.0f);
	FVector ARight = controller->rightwardTrackActor->getPath()->FindLocationClosestToWorldLocation(P, ESplineCoordinateSpace::World);// - FVector(0.0f, controller->minActivationDistance, 0.0f);

	//if we are outside of the race line catch bounds (from min dist left A to min dist right A), then execute
	//	this subtraction order matters, dealing with left right specific on this check

	FVector LvecL = controller->leftwardTrackActor->getPath()->FindRightVectorClosestToWorldLocation(ALeft, ESplineCoordinateSpace::Local);
	FVector LvecR = -controller->rightwardTrackActor->getPath()->FindRightVectorClosestToWorldLocation(ARight, ESplineCoordinateSpace::Local);

	//determine in or out of track
	float lSet = FVector::DotProduct(LvecL, (ALeft - P));
	if (lSet < 0.0f)
	{
		selectorObjects[3]->ExecuteNode();
		AActor* car = controller->GetPawn();
		Cast<AMyHatchback>(car)->decisionIndex = 3;
		return selectorObjects[3];
	}

	float rSet = FVector::DotProduct(LvecR, (ARight - P));
	if(rSet < 0.0f)
	{
		selectorObjects[3]->ExecuteNode();
		AActor* car = controller->GetPawn();
		Cast<AMyHatchback>(car)->decisionIndex = 3;
		return selectorObjects[3];
	}

	//if ((P.Y - ALeft.Y > 0.0f))
	//{
	//	selectorObjects[3]->ExecuteNode();
	//	return selectorObjects[3];
	//}
		
	//if((P.Y - ARight.Y < 0.0f))
	//{
	//	selectorObjects[3]->ExecuteNode();
	//	return selectorObjects[3];
	//}

	// If all else fails, then go to just following the racing line
	selectorObjects[0]->ExecuteNode();
	AActor* car = controller->GetPawn();
	Cast<AMyHatchback>(car)->decisionIndex = 0;
	return selectorObjects[0];
}