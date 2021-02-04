// Fill out your copyright notice in the Description page of Project Settings.

#include "goBEMEnemy.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AgoBEMEnemy::AgoBEMEnemy()
{
	// Set this character to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Point1 = CreateDefaultSubobject<USceneComponent>(TEXT("Point1"));
	Point1->SetupAttachment(RootComponent);

	Point2 = CreateDefaultSubobject<USceneComponent>(TEXT("Point2"));
	Point2->SetupAttachment(RootComponent);

	UCharacterMovementComponent* MovementPtr = Cast<UCharacterMovementComponent>(GetCharacterMovement());
	MovementPtr->MaxWalkSpeed = speed;
}

// Called when the game starts or when spawned
void AgoBEMEnemy::BeginPlay()
{
	Super::BeginPlay();
	Point1->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
	Point2->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
	SetPatrolPoint();
}

// Called every frame
void AgoBEMEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector enemy = GetActorLocation();
	FVector world_direction = patrolLocationVector - enemy;

	if (patrollingEnabled) 
	{
		float distance = FVector::Dist(enemy, patrolLocationVector);
		AddMovementInput(world_direction);

		if (distance < 20.0f) 
		{
			SetPatrolPoint();
		}
	}
}

void AgoBEMEnemy::SetPatrolPoint()
{
	if (isPoint1)
	{
		patrolLocationVector = Point1->GetComponentLocation();
		isPoint1 = false;
	}
	else 
	{
		patrolLocationVector = Point2->GetComponentLocation();
		isPoint1 = true;
	}
}
