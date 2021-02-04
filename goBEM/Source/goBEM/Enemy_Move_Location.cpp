// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Move_Location.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "Enemy_Controller.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_vector.h"
#include "blackboard_keys.h"
#include "Enemy_Move_Location.h"

UEnemy_Move_Location::UEnemy_Move_Location(FObjectInitializer const& object_initializer)
{
	NodeName = TEXT("Find Random Location");
}

EBTNodeResult::Type UEnemy_Move_Location::ExecuteTask(UBehaviorTreeComponent& owner_component, uint8* node_memory)
{
	// get AI controller and its Enemy
	auto const controller = Cast<AEnemy_Controller>(owner_component.GetAIOwner());
	auto const enemy = controller->GetPawn();

	// obtain enemy location to use as an origin location
	FVector const origin = enemy->GetActorLocation();
	FNavLocation location;

	// get the navigation system and generate a random location on the NavMesh
	UNavigationSystemV1* const navSystem = UNavigationSystemV1::GetCurrent(GetWorld());

	if (navSystem->GetRandomPointInNavigableRadius(origin, searchRadius, location, nullptr)) 
	{
		controller->get_blackboard()->SetValueAsVector(bb_keys::targetLocation, location.Location);
	}

	// finish with success
	FinishLatentTask(owner_component, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
