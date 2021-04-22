// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseDecisionNode.h"
#include "BaseAction.h"
#include "MyHatchbackAIController.h"

// Sets default values
ABaseDecisionNode::ABaseDecisionNode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseDecisionNode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseDecisionNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// This function executes to find the next node or find that the action has been found
ABaseDecisionNode* ABaseDecisionNode::ExecuteDecision(AMyHatchbackAIController* newController, bool& bHasFoundAction)
{
	return nullptr;
}

// Constructs the decision based on classes
void ABaseDecisionNode::ConstructDecision() 
{
	// Create default parameters for spawning
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;


	if (bIsActionNode) 
	{
		// Make action nodes if decided as such 


		// Throw error if action classes are invalid
		if (trueActionClass == nullptr || falseActionClass == nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Action Classes are Invalid!"));
			return;
		}

		// Create true and false actions if classes are valid
		trueAction = GetWorld()->SpawnActor<ABaseAction>(trueActionClass, Location, Rotation, SpawnInfo);
		falseAction = GetWorld()->SpawnActor<ABaseAction>(falseActionClass, Location, Rotation, SpawnInfo);
	}
	else 
	{
		// If nodes arent action nodes, then create decision classes instead

		// Throw error if decision classes are invalid
		if (trueDecisionClass == nullptr || falseDecisionClass == nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Decision Classes are Invalid!"));
			return;
		}

		// Create true and false decisions if classes are valid and initialize them as well
		trueDecision = GetWorld()->SpawnActor<ABaseDecisionNode>(trueDecisionClass, Location, Rotation, SpawnInfo);
		trueDecision->ConstructDecision();

		falseDecision = GetWorld()->SpawnActor<ABaseDecisionNode>(falseDecisionClass, Location, Rotation, SpawnInfo);
		falseDecision->ConstructDecision();
	}
}