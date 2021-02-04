// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"


/**
 * 
 */
class SUIWidget : public SCompoundWidget
{

public:

	SLATE_BEGIN_ARGS(SUIWidget) {}

	SLATE_ARGUMENT(TWeakObjectPtr<class AUIHUD>, OwningHUD)

	SLATE_END_ARGS()

	/** every widget needs a construction function **/  
	void Construct(const FArguments& InArgs);

	FReply OnStartClicked() const;
	FReply OnQuitClicked() const;
	
	/** The HUD that created this widget **/
	TWeakObjectPtr<class AUIHUD> OwningHUD;

	virtual bool SupportsKeyboardFocus() const override { return true; };
};
