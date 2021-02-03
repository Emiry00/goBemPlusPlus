// Fill out your copyright notice in the Description page of Project Settings.


#include "cPlayer.h"
#include "PaperFlipbookComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Camera/CameraComponent.h"

FName AcPlayer::SpriteComponentName(TEXT("Sprite0"));

// Sets default values
AcPlayer::AcPlayer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.DoNotCreateDefaultSubobject(ACharacter::MeshComponentName))
{
	Sprite = CreateOptionalDefaultSubobject<UPaperFlipbookComponent>(AcPlayer::SpriteComponentName);
	if (Sprite)
	{
		Sprite->AlwaysLoadOnClient = true;
		Sprite->AlwaysLoadOnServer = true;
		Sprite->bOwnerNoSee = false;
		Sprite->bAffectDynamicIndirectLighting = true;
		Sprite->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		Sprite->SetupAttachment(GetCapsuleComponent());
		static FName CollisionProfileName(TEXT("CharacterMesh"));
		Sprite->SetCollisionProfileName(CollisionProfileName);
		Sprite->SetGenerateOverlapEvents(false);
		Sprite->SetFlipbook(IdleAnimation);
	}

	// Player SpringArm Initializations
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SocketOffset = FVector(0.0f, 0.0f, 75.0f);
	SpringArm->TargetArmLength = 500.0f;
	SpringArm->SetUsingAbsoluteRotation(true);
	SpringArm->bDoCollisionTest = false;
	SpringArm->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	

	SideViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCamera->ProjectionMode = ECameraProjectionMode::Perspective;
	SideViewCamera->OrthoWidth = 2048.0f;
	SideViewCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	// Automatic rotation behavior on the camera component
	SideViewCamera->bAutoActivate = true;
	SideViewCamera->bUsePawnControlRotation = false;

	RotComp = CreateDefaultSubobject<USceneComponent>(TEXT("RotComp"));
	RotComp->SetupAttachment(RootComponent);

	ShotPosComp = CreateDefaultSubobject<UArrowComponent>(TEXT("ShotPosComp"));
	ShotPosComp->SetupAttachment(RotComp);

	// Configure character movement
	// Lock character motion onto the XZ plane, so the character can't move in or out of the screen
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0.0f, -1.0f, 0.0f));
	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->GravityScale = 2.0f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;

	// Behave like a traditional 2D platformer character, with a flat bottom instead of a curved capsule bottom
	GetCharacterMovement()->bUseFlatBaseForFloorChecks = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	bDead = false;
	Coins = 0;
	Keys = 0;
}


// Called to bind functionality to input
void AcPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Binding Unreal Engine Input Settings to the Player Input Component Controller
	// kJump & kHor - Custom Input Project Preferences
	PlayerInputComponent->BindAction("kJump", IE_Pressed, this, &AcPlayer::DoJumped);
	PlayerInputComponent->BindAction("kJump", IE_Released, this, &AcPlayer::DoStopJump);
	PlayerInputComponent->BindAxis("kHor", this, &AcPlayer::HorizontalMovement);

}


// Called when the game starts or when spawned
void AcPlayer::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AcPlayer::OnBeginOverlap);

	if (Player_Game_Widget_Class != nullptr)
	{
		Player_Game_Widget = CreateWidget(GetWorld(), Player_Game_Widget_Class);
		Player_Game_Widget->AddToViewport();

	}
}

// Called every frame
void AcPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateStates();
	UpdateAnimations();

}

void AcPlayer::HorizontalMovement(float value)
{
	if (!bDead)
	{
		if (value == 0.0f)
		{
			return;
		}

		// Default Left and Right Movement States
		bool kLeft = false;
		bool kRight = false;

		if (value > InputThreshold)
		{
			kRight = true;
		}

		if (value < -InputThreshold)
		{
			kLeft = true;
		}

		if ((kRight && !kLeft) || (!kRight && kLeft)) 
		{
			if (kRight)
			{
				Facing = 1;
			}

			if (kLeft)
			{
				Facing = -1;
			}

			AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Facing);
		}
	}
}

void AcPlayer::DoJumped()
{
	// Unreal Default Jump Functionality for Characters
	if (!bDead)
	{
		Jump();
	}
}

void AcPlayer::DoStopJump()
{
	if (!bDead)
	{
		FVector velocity = GetVelocity();

		if (velocity.Z > 0.0f)
		{
			velocity.Z *= 0.25f;
			GetCharacterMovement()->Velocity = velocity;
		}
	}
}

void AcPlayer::UpdateStates()
{
	FVector speed = GetVelocity();
	if (speed.Z != 0.0f)
	{
		STATE = JUMP;
	}
	else
	{
		if (speed.X != 0.0f)
		{
			STATE = RUN;
		}
		else
		{
			STATE = IDLE;
		}
	}
}

void AcPlayer::UpdateAnimations()
{
	FVector speed = GetVelocity();

	switch (STATE)
	{
		// Setting Idle Animation
		case 10:
		{
			DesiredAnimation = IdleAnimation;
			break;
		}
		// Setting Run Animation
		case 11:
		{
			DesiredAnimation = RunningAnimation;
			break;
		}
		// Setting Jump Animation
		case 12:
		{
			if (speed.Z < JumpMidVelocity && speed.Z > -JumpMidVelocity)
			{
				JumpAnimation = JumpMidAnimation;
			}
			else
			{
				if (speed.Z > 0.0f)
				{
					JumpAnimation = JumpUpAnimation;
				}
				else
				{
					JumpAnimation = JumpDownAnimation;
				}
			}
			DesiredAnimation = JumpAnimation;
			break;
		}
	}

	FVector spriteScale = Sprite->GetComponentScale();
	spriteScale.X = Facing;
	if (Sprite->GetComponentScale() != spriteScale)
	{
		Sprite->SetRelativeScale3D(spriteScale);
	}

	if (Sprite->GetFlipbook() != DesiredAnimation)
	{
		Sprite->SetFlipbook(DesiredAnimation);
	}
}

// If the player collides with an object
void AcPlayer::OnBeginOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!bDead)
	{
		// If the player collides with a coin
		if (OtherActor->ActorHasTag("Coin"))
		{
			UE_LOG(LogTemp, Warning, TEXT("COLLIDED WITH COIN"));
			Coins += 1;
			OtherActor->Destroy();
		}
		// If the player collides with a key
		else if (OtherActor->ActorHasTag("Key"))
		{
			UE_LOG(LogTemp, Warning, TEXT("COLLIDED WITH KEY"));
			Keys += 1;
			OtherActor->Destroy();
		}
		// If the player collides with a key
		else if (OtherActor->ActorHasTag("Chest"))
		{
			UE_LOG(LogTemp, Warning, TEXT("COLLIDED WITH CHEST"));
			if (Keys > 0)
			{
				OtherActor->Destroy();
				Keys -= 1;

				FVector SpawnPosition = GetActorLocation();
				FRotator SpawnRotation = GetActorRotation();

				GetWorld()->SpawnActor(Coin, &SpawnPosition, &SpawnRotation);
			}
		}
	}
}