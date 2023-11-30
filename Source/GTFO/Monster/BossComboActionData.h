// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BossComboActionData.generated.h"

/**
 * 
 */
UCLASS()
class GTFO_API UBossComboActionData : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UBossComboActionData();

	UPROPERTY(EditAnywhere, Category = Name)
	FString MontageSectionNamePrefix;			//��Ÿ�� ���� �̸�

	UPROPERTY(EditAnywhere, Category = Name)
	uint8 MaxComboCount;						//��� �޺� �׼��� �ִ���

	UPROPERTY(EditAnywhere, Category = Name)
	float FrameRate;

	UPROPERTY(EditAnywhere, Category = ComboData)
	TArray<float> EffectiveFrameCount;			//������ �Է��� �Ǿ����� ����
	
};
