// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5LabGameMode.h"
#include "UE5LabCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5LabGameMode::AUE5LabGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
