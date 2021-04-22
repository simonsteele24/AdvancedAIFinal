// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseAction.h"
#include "BaseDecisionNode.generated.h"

UCLASS()
class RACINGAI_API ABaseDecisionNode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseDecisionNode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* Public Functions */
	UFUNCTION() void ConstructDecision();
	UFUNCTION() virtual ABaseDecisionNode* ExecuteDecision(class AMyHatchbackAIController* newController, bool& bHasFoundAction);

	/* Conditionals */
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bIsActionNode = false;

	/* Controllers */
	UPROPERTY() class AMyHatchbackAIController* controller;

	/* Decision Classes */
	UPROPERTY(EditDefaultsOnly)	TSubclassOf<ABaseDecisionNode> trueDecisionClass;
	UPROPERTY(EditDefaultsOnly)	TSubclassOf<ABaseDecisionNode> falseDecisionClass;

	/* Action Classes */
	UPROPERTY(EditDefaultsOnly) TSubclassOf<ABaseAction> trueActionClass;
	UPROPERTY(EditDefaultsOnly)	TSubclassOf<ABaseAction> falseActionClass;

	/* Decision Objects */
	UPROPERTY() ABaseDecisionNode* trueDecision = nullptr;
	UPROPERTY() ABaseDecisionNode* falseDecision = nullptr;

	/* Actions Objects */
	UPROPERTY() ABaseAction* trueAction = nullptr;
	UPROPERTY() ABaseAction* falseAction = nullptr;
};
