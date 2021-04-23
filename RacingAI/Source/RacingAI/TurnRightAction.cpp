// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnRightAction.h"
#include "MyHatchbackAIController.h"

void ATurnRightAction::PerformAction(AMyHatchbackAIController* newController) 
{
	controller = newController;
	controller->Steering += controller->GetPawn()->GetActorRightVector() * 10000.0f;
}