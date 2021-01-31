// Copyright Epic Games, Inc. All Rights Reserved.

#include "goBEMGameMode.h"
#include "goBEMCharacter.h"

AgoBEMGameMode::AgoBEMGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = AgoBEMCharacter::StaticClass();	
}
