// Fill out your copyright notice in the Description page of Project Settings.


#include "UIController.h"
#include "UIHUD.h"

AUIController::AUIController()
{

}

void AUIController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (InputComponent)
	{
		InputComponent->BindAction("OpenMenu", IE_Pressed, this, &AUIController::OpenMenu);
	}
}

void AUIController::OpenMenu()
{
	if (AUIHUD* UIHUD = Cast<AUIHUD>(GetHUD()))
	{
		UIHUD->ShowMenu();
	}
}
