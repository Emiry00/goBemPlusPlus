// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "GameFramework/Character.h"
#include "Blueprint/UserWidget.h"
#include "cPlayer.generated.h"  

UCLASS()
class GOBEM_API AcPlayer : public ACharacter
{
	GENERATED_UCLASS_BODY()

		//Name of the Sprite component
		static FName SpriteComponentName;

public:

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UPaperFlipbookComponent* Sprite;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringArm;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* SideViewCamera;


	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* RotComp;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* ShotPosComp;

	// Sprite Varaibles------------------------------------------------
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Animations)
		class UPaperFlipbook* IdleAnimation;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Animations)
		class UPaperFlipbook* RunningAnimation;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Animations)
		class UPaperFlipbook* JumpAnimation;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Animations)
		class UPaperFlipbook* JumpUpAnimation;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Animations)
		class UPaperFlipbook* JumpMidAnimation;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Animations)
		class UPaperFlipbook* JumpDownAnimation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animations)
		class UPaperFlipbook* DesiredAnimation;

	// Character Properties------------------------------------------------
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Animations)
		float JumpMidVelocity = 120.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int Coins;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int Keys;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int Time;

	UFUNCTION()
		void OnBeginOverlap(class UPrimitiveComponent* HitComp,
			class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void RestartGame();

	UPROPERTY(EditAnywhere, Category = "UI HUD")
		TSubclassOf<UUserWidget> Player_Game_Widget_Class;
	UUserWidget* Player_Game_Widget;

	UPROPERTY(EditAnywhere)
		TSubclassOf<APawn> Coin;
	// ----------------------------------------------------------------

	// Constants-------------------------------------------------------
	const int IDLE = 10;
	const int RUN = 11;
	const int JUMP = 12;

	// States
	int STATE = IDLE;
	bool bNewState = true;

	int Facing = 1;

	float InputThreshold = 0.4;
	// ----------------------------------------------------------------

	bool bDead;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this character's properties
	AcPlayer();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void DoLanded();
	void DoJumped();
	void DoStopJump();
	void UpdateStates();
	void UpdateAnimations();
	void HorizontalMovement(float value);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE class UPaperFlipbookComponent* GetSprite() const { return Sprite; }
	FORCEINLINE class USpringArmComponent* GetSpringArm() const { return SpringArm; }
	FORCEINLINE class UCameraComponent* GetSideViewCamera() const { return SideViewCamera; }
	FORCEINLINE class USceneComponent* GetRot() const { return RotComp; }
	FORCEINLINE class UArrowComponent* GetShotComp() const { return ShotPosComp; }
};
