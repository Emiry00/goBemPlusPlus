// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UIHUD.generated.h"

/**
 * 
 */
UCLASS()
class GOBEM_API AUIHUD : public AHUD
{
	GENERATED_BODY()
	
protected:

	TSharedPtr<class SUIWidget> UIWidget;
	TSharedPtr<class SWidget> UIWidgetContainer;

	virtual void BeginPlay() override;

public:

	void ShowMenu();
	void RemoveMenu();
};
