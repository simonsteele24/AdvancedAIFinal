// Fill out your copyright notice in the Description page of Project Settings.

#include "SlotCarToTrackNode.h"
#include "MyHatchbackAIController.h"
#include "TrackBoundaryActor.h"


ACustomBehaviorTreeNode* ASlotCarToTrackNode::ExecuteNode() 
{
	// Logic goes here
	
	AMyHatchbackAIController* controller = Cast<AMyHatchbackAIController>(treeOwner);

	//first check are we left or are we right
	FVector P = controller->GetPawn()->GetActorLocation();
	FVector ACloseLeft = controller->leftwardTrackActor->getPath()->FindLocationClosestToWorldLocation(P, ESplineCoordinateSpace::World);
	FVector ACloseRight = controller->rightwardTrackActor->getPath()->FindLocationClosestToWorldLocation(P, ESplineCoordinateSpace::World);
	FVector ALeft = ACloseLeft;//  + FVector(0.0f, controller->minActivationDistance, 0.0f);
	FVector ARight = ACloseRight;// - FVector(0.0f, controller->minActivationDistance, 0.0f);
	
	FVector dir;

	FVector LvecL = controller->leftwardTrackActor->getPath()->FindRightVectorClosestToWorldLocation(ALeft, ESplineCoordinateSpace::Local);
	FVector LvecR = -controller->rightwardTrackActor->getPath()->FindRightVectorClosestToWorldLocation(ARight, ESplineCoordinateSpace::Local);

	//are we on the left track side
	float lSet = FVector::DotProduct(LvecL, (ALeft - P));
	if (lSet < 0.0f)
	{
		float AP_Left_dist = FVector::Dist(ALeft, P);
		FVector D = controller->GetPawn()->GetActorForwardVector();

		if (AP_Left_dist < controller->minActivationDistance)
		{
			FVector L = controller->leftwardTrackActor->getPath()->FindRightVectorClosestToWorldLocation(ACloseLeft, ESplineCoordinateSpace::Local);	//this might have to be negative;
			FVector H = (D.GetSafeNormal() + L.GetSafeNormal()).GetSafeNormal();
			dir = H;
		}
		else
		{
			FVector F = controller->leftwardTrackActor->getPath()->FindDirectionClosestToWorldLocation(ACloseLeft, ESplineCoordinateSpace::Local);	//this might have to be negative
			FVector X = 2.0f * (FVector::DotProduct(F, D)) * F - D;
			dir = X * AP_Left_dist * 0.25f;
		}
	}
	else
	{
		float AP_Right_dist = FVector::Dist(ARight, P);
		FVector D = controller->GetPawn()->GetActorForwardVector();

		if (AP_Right_dist < controller->minActivationDistance)
		{
			FVector L = controller->rightwardTrackActor->getPath()->FindRightVectorClosestToWorldLocation(ACloseRight, ESplineCoordinateSpace::Local);	//this might have to be positive
			FVector H = (D.GetSafeNormal() + L.GetSafeNormal()).GetSafeNormal();
			dir = H;
		}
		else
		{
			FVector F = controller->rightwardTrackActor->getPath()->FindDirectionClosestToWorldLocation(ACloseRight, ESplineCoordinateSpace::Local);	//this might have to be negative
			FVector X = 2.0f * (FVector::DotProduct(F, D)) * F - D;
			dir = X * AP_Right_dist * 0.25f;
		}
	}

	controller->Steering = dir;

	return nullptr; // Keep this as is
}