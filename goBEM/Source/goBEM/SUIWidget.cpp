// Fill out your copyright notice in the Description page of Project Settings.


#include "SUIWidget.h"
#include "UIHUD.h"
#include "GameFramework/PlayerController.h"

#define LOCTEXT_NAMESPACE "UI"

void SUIWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	OwningHUD = InArgs._OwningHUD;

	const FMargin ContentPadding = FMargin(500.f, 450.f);
	const FMargin ButtonPadding = FMargin(10.f);
	
	const FText StartText = LOCTEXT("StartGame", "START");
	const FText QuitText = LOCTEXT("QuitGame", "QUIT");

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;


	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(ContentPadding)
			[
				SNew(SVerticalBox)

				// Start button
				+ SVerticalBox::Slot()
				.Padding(ButtonPadding)
				[
					SNew(SButton)
					.OnClicked(this, &SUIWidget::OnStartClicked)
					[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(StartText)
						.Justification(ETextJustify::Center)
					]
				]
				// Start button
				+ SVerticalBox::Slot()
				.Padding(ButtonPadding)
				[
					SNew(SButton)
					.OnClicked(this, &SUIWidget::OnQuitClicked)
					[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(QuitText)
						.Justification(ETextJustify::Center)
					]
				]
			]

		];

}

FReply SUIWidget::OnStartClicked() const
{
	if (OwningHUD.IsValid())
	{
		OwningHUD->RemoveMenu();
	}
	return FReply::Handled();
}

FReply SUIWidget::OnQuitClicked() const
{
	if (OwningHUD.IsValid())
	{
		if (APlayerController* PC = OwningHUD->PlayerOwner)
		{
			PC->ConsoleCommand("quit");
		}
	}

	return FReply::Handled();
}


#undef LOCTEXT_NAMESPACE