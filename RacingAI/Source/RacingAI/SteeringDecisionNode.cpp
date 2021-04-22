// Fill out your copyright notice in the Description page of Project Settings.


#include "SteeringDecisionNode.h"
#include "MyHatchbackAIController.h"
#include "MyHatchback.h"

ABaseDecisionNode* ASteeringDecisionNode::ExecuteDecision(class AMyHatchbackAIController* newController, bool& bHasFoundAction)
{
	controller = newController;
	bHasFoundAction = true;
	
	FHitResult out;

	FVector Start = controller->GetPawn()->GetActorLocation() + FVector(0, 0, 20);
	FVector End = (controller->GetPawn()->GetActorLocation() + FVector(0, 0, 20)) + controller->GetPawn()->GetActorForwardVector() * 2000.0f;

	GetWorld()->LineTraceSingleByChannel(out, Start, End, ECollisionChannel::ECC_Visibility);
	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 1);

	if (Cast<AMyHatchback>(out.Actor) != nullptr) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Hitting!"));
	}


	return nullptr;
}