// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "GameFramework/Pawn.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "UObject/UObjectGlobals.h"
#include "Enemy_Move_Location.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GOBEM_API UEnemy_Move_Location : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UEnemy_Move_Location(FObjectInitializer const& object_initializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_component, uint8* node_memory);
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Search", meta = (AllowProtectedAccess = "true"))
	float searchRadius = 1500.0f;
};
