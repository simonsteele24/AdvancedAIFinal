// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHatchbackAIController.h"
#include "TrackBoundaryActor.h"

bool AMyHatchbackAIController::checkOnTrackLeft(FVector CarPos)
{
	FVector closestTrackPoint = leftwardTrackActor->getPath()->FindLocationClosestToWorldLocation(CarPos, ESplineCoordinateSpace::World);
	FVector carDirVector = CarPos - closestTrackPoint;
	return FVector::DotProduct(carDirVector, leftwardTrackActor->getPath()->FindRightVectorClosestToWorldLocation(closestTrackPoint, ESplineCoordinateSpace::Local)) < 0.0f;
}

bool AMyHatchbackAIController::checkOnTrackRight(FVector CarPos)
{
	FVector closestTrackPoint = rightwardTrackActor->getPath()->FindLocationClosestToWorldLocation(CarPos, ESplineCoordinateSpace::World);
	FVector carDirVector = CarPos - closestTrackPoint;
	return FVector::DotProduct(carDirVector, -rightwardTrackActor->getPath()->FindRightVectorClosestToWorldLocation(closestTrackPoint, ESplineCoordinateSpace::Local)) < 0.0f;
}