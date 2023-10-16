// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CSSHUD.generated.h"

struct FInteractableData;
class UInteractionWidget;
class UMainMenu;

UCLASS()
class CSS_API ACSSHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category="Widgets")
	TSubclassOf<UMainMenu> MainMenuClass;
	
	UPROPERTY(EditDefaultsOnly, Category="Widgets")
	TSubclassOf<UInteractionWidget> InteractionWidgetClass;

	bool bIsMenuVisible;

	ACSSHUD();

	void DisplayMenu();
	void HideMenu();

	void ShowInteractionWidget() const;
	void HideInteractionWidget() const;

	void UpdateInteractionWidget(const FInteractableData* InteractableData) const;

protected:

	UPROPERTY()
	UMainMenu* MainMenuWidget;

	UPROPERTY()
	UInteractionWidget* InteractionWidget;
	
	virtual void BeginPlay() override;
};
