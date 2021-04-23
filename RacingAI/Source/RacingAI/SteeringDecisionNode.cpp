// Fill out your copyright notice in the Description page of Project Settings.


#include "SteeringDecisionNode.h"
#include "MyHatchbackAIController.h"
#include "Kismet/GameplayStatics.h"
#include "MyHatchback.h"

ABaseDecisionNode* ASteeringDecisionNode::ExecuteDecision(class AMyHatchbackAIController* newController, bool& bHasFoundAction)
{
	controller = newController;
	bHasFoundAction = true;
	
	AMyHatchback * closestHatchback = GetClosestCar();

	if (closestHatchback != nullptr) 
	{
		FVector dist = closestHatchback->GetActorLocation() - controller->GetPawn()->GetActorLocation();
		float distance = dist.Size();
		dist.Normalize();
		float dotProduct = FVector::DotProduct(controller->GetPawn()->GetActorRightVector(), dist);

		if (distance < 2000.0f) 
		{
			if (dotProduct > 0)
			{
				trueAction->PerformAction(controller);
			}
			else
			{
				falseAction->PerformAction(controller);
			}
		}
	}


	return nullptr;
}

class AMyHatchback* ASteeringDecisionNode::GetClosestCar() 
{
	TArray<AActor*> outActor;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyHatchback::StaticClass(), outActor);

	AMyHatchback* closest = nullptr;

	for (int i = 0; i < outActor.Num(); i++) 
	{
		float closestDistance = 99999999.0f;
		FVector dist = outActor[i]->GetActorLocation() - controller->GetPawn()->GetActorLocation();
		float distance = dist.Size();
		dist.Normalize();
		float dotProduct = FVector::DotProduct(controller->GetPawn()->GetActorForwardVector(), dist);

		if (dotProduct > 0 && controller->GetPawn() != outActor[i]) 
		{
			if (distance < closestDistance) 
			{
				closestDistance = distance;
				closest = Cast<AMyHatchback>(outActor[i]);
			}
		}
	}

	return closest;
}