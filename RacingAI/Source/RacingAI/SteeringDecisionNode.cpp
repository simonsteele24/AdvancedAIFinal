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
				//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("True!"));
				trueAction->PerformAction(controller);
			}
			else
			{
				//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("False!"));
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
	float closestDistance = 99999999.0f;

	for (int i = 0; i < outActor.Num(); i++) 
	{
		FVector dist = outActor[i]->GetActorLocation() - controller->GetPawn()->GetActorLocation();
		float distance = dist.Size();
		dist.Normalize();
		float dotProduct = FVector::DotProduct(controller->GetPawn()->GetActorForwardVector(), dist);

		if ((dotProduct > 0 || distance <= 2000.0f) && controller->GetPawn() != outActor[i]) 
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