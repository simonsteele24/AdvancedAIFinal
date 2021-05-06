// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnLeftAction.h"
#include "MyHatchbackAIController.h"

void ATurnLeftAction::PerformAction(AMyHatchbackAIController* newController)
{
	controller = newController;
	controller->Steering += controller->GetPawn()->GetActorRightVector() * -200.0f;
}
