// Fill out your copyright notice in the Description page of Project Settings.


#include "UIHUD.h"
#include "SUIWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

void AUIHUD::BeginPlay()
{
	Super::BeginPlay();

	// Show Menu on Start
	ShowMenu();
}

// Shows Menu on UI
void AUIHUD::ShowMenu()
{
	if (GEngine && GEngine->GameViewport)
	{
		// Create UIWidget
		UIWidget = SNew(SUIWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(UIWidgetContainer, SWeakWidget).PossiblyNullContent(UIWidget.ToSharedRef()));

		if (PlayerOwner)
		{
			// Enable MouseCursor
			PlayerOwner->bShowMouseCursor = true;
			// Set UI Mode
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
	}
}

// Removes Menu from UI
void AUIHUD::RemoveMenu()
{
	if (GEngine && GEngine->GameViewport && UIWidget.IsValid() && UIWidgetContainer.IsValid())
	{
		// Remove UIWidgetContainer content (UIWidget)
		GEngine->GameViewport->RemoveViewportWidgetContent(UIWidgetContainer.ToSharedRef());

		if (PlayerOwner)
		{
			// Disable MouseCursor
			PlayerOwner->bShowMouseCursor = false;
			// Set Game Mode
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}
