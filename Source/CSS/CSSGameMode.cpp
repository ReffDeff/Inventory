// Copyright Epic Games, Inc. All Rights Reserved.

#include "CSSGameMode.h"
#include "Player/CSSCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACSSGameMode::ACSSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
