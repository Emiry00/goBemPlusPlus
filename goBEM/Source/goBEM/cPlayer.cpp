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
#include "Kismet/GameplayStatics.h"

FName AcPlayer::SpriteComponentName(TEXT("Sprite0"));

/**
* Player Class
* Conatining Movement, Item + States Logic
*/

// Default ACharacter Initialization
AcPlayer::AcPlayer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.DoNotCreateDefaultSubobject(ACharacter::MeshComponentName))
{
	/**
	* UE4 - Attaching sprite flipbook component to player class
	* Flipbook component specific configurations and initalizations
	* Getting the Sprite from the UE4 Blueprint Editor
	*/
	Sprite = CreateOptionalDefaultSubobject<UPaperFlipbookComponent>(AcPlayer::SpriteComponentName);
	if (Sprite)
	{
		// Sprite Rendering Options
		Sprite->AlwaysLoadOnClient = true;
		Sprite->AlwaysLoadOnServer = true;
		// Component owner visibility
		Sprite->bOwnerNoSee = false;
		// UE4 specific shadow casting
		Sprite->bAffectDynamicIndirectLighting = true;
		// Component update binding
		Sprite->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		// Attaching Sprite to players capsule component -> size of player
		Sprite->SetupAttachment(GetCapsuleComponent());
		static FName CollisionProfileName(TEXT("CharacterMesh"));
		// Collision component for player. Statically named CharacterMesh
		Sprite->SetCollisionProfileName(CollisionProfileName);
		Sprite->SetGenerateOverlapEvents(false);
		// Default flipbook animation -> IdleAnimation (Character im Ruhemodus oder auch Animation fürs stehen)
		Sprite->SetFlipbook(IdleAnimation);
	}

	
	/**
	* UE4 - Player SpringArm Initializations
	* SpringArm component specific configurations and initalizations
	* SpringArm component named SpringArm
	*/
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	// Attachment to player component
	SpringArm->SetupAttachment(RootComponent);
	// Distancing from character component on Z-Axis
	SpringArm->SocketOffset = FVector(0.0f, 0.0f, 75.0f);
	SpringArm->TargetArmLength = 500.0f;
	// Attaching absolute rotation for player rotations. Moving with the SideViewCamera component
	SpringArm->SetUsingAbsoluteRotation(true);
	SpringArm->bDoCollisionTest = false;
	SpringArm->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	
	/**
	* UE4 - Player CameraComponent Initializations
	* Camera component specific configurations and initalizations
	*/
	SideViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	// Camera Projectionmode whether Perspective or Orthographic
	SideViewCamera->ProjectionMode = ECameraProjectionMode::Perspective;
	SideViewCamera->OrthoWidth = 2048.0f;
	// Attaching Camera component on the SpringArm -> Distance from player
	SideViewCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	// Automatic rotation behavior on the camera component
	SideViewCamera->bAutoActivate = true;
	// Disabling default pawn rotations
	SideViewCamera->bUsePawnControlRotation = false;

	/**
	* UE4 - Player SceneComponent Initializations
	* Scene component specific configurations and initalizations
	*/
	RotComp = CreateDefaultSubobject<USceneComponent>(TEXT("RotComp"));
	RotComp->SetupAttachment(RootComponent);

	/**
	* UE4 - Player ArrowComponent Initializations
	* Arrow component specific configurations and initalizations
	*/
	ShotPosComp = CreateDefaultSubobject<UArrowComponent>(TEXT("ShotPosComp"));
	ShotPosComp->SetupAttachment(RotComp);

	// Configure character movement
	// Lock character motion onto the XZ plane, so the character can't move in or out of the screen
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0.0f, -1.0f, 0.0f));
	GetCharacterMovement()->bOrientRotationToMovement = false;
	// Default Velocity, Gravity and Jump Settings
	GetCharacterMovement()->GravityScale = 2.0f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;

	// Behave like a traditional 2D platformer character, with a flat bottom instead of a curved capsule bottom
	GetCharacterMovement()->bUseFlatBaseForFloorChecks = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Custom State Variables
	bDead = false;
	Coins = 0;
	Keys = 0;
	Time = 0;
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
	//PlayerInputComponent->BindAction("OpenMenu", IE_Pressed, this, &AcPlayer::PauseTime());
}


// Called when the game starts or when spawned
void AcPlayer::BeginPlay()
{
	Super::BeginPlay();
	// Dynamic collision enabled for player capsule with dynamic elements
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

	// When game started track time
	if (bTime)
	{
		// Passed Time
		floatTime += DeltaTime;

		if (floatTime >= 1.0f)
		{
			Time += 1;
			floatTime = 0.0f;
		}
	}

	// Statemanagement + Jump Animation Management
	UpdateStates();
	UpdateAnimations();
}

// Horizontal Movement 
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

		// Time Tracking starts by moving the character
		if (!bTime)
		{
			bTime = true;
		}

		if (value > InputThreshold)
		{
			kRight = true;
		}

		if (value < -InputThreshold)
		{
			kLeft = true;
		}
		// XZ Plane orientation flipping
		// Facing direction for player
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

// For Jumped State connected to UE4 - InputController
void AcPlayer::DoJumped()
{
	// Unreal Default Jump Functionality for Characters
	if (!bDead)
	{
		Jump();
	}
}

// For Jump Button Released State connected to UE4 - InputController
void AcPlayer::DoStopJump()
{
	if (!bDead)
	{
		FVector velocity = GetVelocity();

		// Droping down when jump button is released
		if (velocity.Z > 0.0f)
		{
			velocity.Z *= 0.25f;
			GetCharacterMovement()->Velocity = velocity;
		}
	}
}

// Updating States
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

// Stand, Walk, Jump Animation Statemanagement Handler
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
				// For Jump Up
				if (speed.Z > 0.0f)
				{
					JumpAnimation = JumpUpAnimation;
				}
				// For Jump Down / Fall down
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
			// UE4 Debug Log
			UE_LOG(LogTemp, Warning, TEXT("COLLIDED WITH COIN"));
			// Collecting Coins - Increasing Players Coins
			Coins += 1;
			// Removing the coin element from the scene by colliding
			OtherActor->Destroy();
		}
		// If the player collides with a key
		else if (OtherActor->ActorHasTag("Key"))
		{
			// UE4 Debug Log
			UE_LOG(LogTemp, Warning, TEXT("COLLIDED WITH KEY"));
			// Collecting Keys - Increasing Players Keys
			Keys += 1;
			// Removing the key element from the scene by colliding
			OtherActor->Destroy();
		}
		// If the player collides with a key
		else if (OtherActor->ActorHasTag("Chest"))
		{
			// UE4 Debug Log
			UE_LOG(LogTemp, Warning, TEXT("COLLIDED WITH CHEST"));
			if (Keys > 0)
			{
				// Removing key from inventory
				Keys -= 1;
				// Adding Coins to Player
				Coins += 5;
				// Removing the chest element from the scene by colliding
				OtherActor->Destroy();
			}
			LaunchCharacter({ 0.0f, 0.0f, 1300.0f }, false, false);
		}
		// If the player collides with the head of an enemy
		else if (OtherComp->ComponentHasTag("HeadBox"))
		{
			// UE4 Debug Log
			UE_LOG(LogTemp, Warning, TEXT("COLLIDED WITH ENEMYS HEAD"));
			// Player Bounce effect
			LaunchCharacter({ 0.0f, 0.0f, 1300.0f }, false, false);
			// Removing the enemy element from the scene by colliding
			OtherActor->Destroy();
		}
		// If the player collides with the body of an enemy -> Game restarts + Player dies
		else if (OtherComp->ComponentHasTag("BodyBox"))
		{
			// UE4 Debug Log
			UE_LOG(LogTemp, Warning, TEXT("COLLIDED WITH ENEMYS BODY"));
			// Player Bounce effect
			LaunchCharacter({ 0.0f, 200.0f, 300.0f }, false, false);
			// Character Dead State -> Disabling movement
			bDead = true;
			// Timer Handler
			FTimerHandle UnusedHandle;
			// Restart game after 1.5s 
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &AcPlayer::RestartGame, 1.5f, false);
		}
		// If the player collides with the goal -> Game restarts + Player states getting resetted
		else if (OtherActor->ActorHasTag("Goal"))
		{
			// UE4 Debug Log
			UE_LOG(LogTemp, Warning, TEXT("COLLIDED WITH GOAL"));
			// Character Dead State -> Disabling movement
			bDead = true;
			// Timer Instance
			FTimerHandle UnusedHandle;
			// Restart game after 0.5s 
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &AcPlayer::RestartGame, .5f, false);
		}
	}
}

void AcPlayer::RestartGame()
{
	// Opens a Level inside this
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}
