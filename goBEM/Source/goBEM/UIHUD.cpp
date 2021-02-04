// Fill out your copyright notice in the Description page of Project Settings.


#include "UIHUD.h"
#include "SUIWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

void AUIHUD::BeginPlay()
{
	Super::BeginPlay();

	ShowMenu();
}

void AUIHUD::ShowMenu()
{
	if (GEngine && GEngine->GameViewport)
	{
		UIWidget = SNew(SUIWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(UIWidgetContainer, SWeakWidget).PossiblyNullContent(UIWidget.ToSharedRef()));

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
	}
}

void AUIHUD::RemoveMenu()
{
	if (GEngine && GEngine->GameViewport && UIWidget.IsValid() && UIWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(UIWidgetContainer.ToSharedRef());

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}
