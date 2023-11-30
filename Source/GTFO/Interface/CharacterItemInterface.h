// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CharacterItemInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCharacterItemInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GTFO_API ICharacterItemInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void TakeItem(class UItemData* InItemData) = 0;
	virtual bool GetIsInteractionAction() { return false;  }
};
