 // Fill out your copyright notice in the Description page of Project Settings.
#include "Components/InventoryComponent.h"

#include "PropertyEditorModule.h"
#include "Items/ItemBase.h"

 // Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

 FItemAddResult UInventoryComponent::HandleAddItem(UItemBase* InputItem)
 {
	
 }

 UItemBase* UInventoryComponent::FindMatchingItem(UItemBase* ItemIn) const
 {
	 if (ItemIn)
	 {
		 if (InventoryContents.Contains(ItemIn))
		 {
			 return ItemIn;
		 }
	 }
	return nullptr;
 }

 UItemBase* UInventoryComponent::FindNextItemByID(UItemBase* ItemIn) const
 {
	 if (ItemIn)
	 {
		 if (const TArray<TObjectPtr<UItemBase>>::ElementType* Result = InventoryContents.FindByKey(ItemIn))
		 {
			 return *Result;
		 }
	 }
	return nullptr;
 }

 UItemBase* UInventoryComponent::FindNextPartialStack(UItemBase* ItemIn) const
 {
	 if (const TArray<TObjectPtr<UItemBase>>::ElementType* Result =
	 	InventoryContents.FindByPredicate([&ItemIn](const UItemBase* InventoryItem)
	 {
		 return InventoryItem->ID == ItemIn->ID && !InventoryItem->IsFullItemStack();
	 }
	 ))
	 {
		 return *Result;
	 }
	return nullptr;
 }

int32 UInventoryComponent::CalculateWeightAddAmount(UItemBase*, int32 RequestedAddAmount)
{
}

int32 UInventoryComponent::CalculateNumberForFullStack(UItemBase* ExistingItem, int32 InitialRequestedAddAmount)
{
	
}

 void UInventoryComponent::RemoveSingleInstanceOfItem(UItemBase* ItemIn)
 {
 }

 int32 UInventoryComponent::RemoveAmountOfItem(UItemBase* ItemIn, int32 DesiredAmountToRemove)
 {
 }

 void UInventoryComponent::SplitExistingStack(UItemBase* ItemIn, const int32 AmountToSplit)
 {
 }

 FItemAddResult UInventoryComponent::HandleNonStackableItems(UItemBase*, int32 RequestedAddAmount)
 {
 }

 int32 UInventoryComponent::HandleStackableItems(UItemBase*, int32 RequestedAddAmount)
 {
 }



 void UInventoryComponent::AddNewItem(UItemBase* Item, const int32 AmountToAdd)
 {
	
 }




//
// // Called every frame
// void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
// {
// 	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
// 	// ...
// }

