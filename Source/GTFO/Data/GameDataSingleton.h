// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Data/CharacterStatData.h"
#include "Data/MonsterData.h"
#include "Data/BulletData.h"
#include "GameDataSingleton.generated.h"

//DECLARE_LOG_CATEGORY_EXTERN(LogABGameSingleton, Error, All);

UCLASS()
class GTFO_API UGameDataSingleton : public UObject
{
	GENERATED_BODY()
	
public:
	UGameDataSingleton();
	static UGameDataSingleton& GetInst();

	//Character Stat Data Section
public:

	//���̺��� ������ �ش��ϴ� �ϳ��� ����ü ������ �����ϵ���
public:
	FORCEINLINE FCharacterStatData GetCharacterStatData(int32 _InLevel) const { return CharacterStatTableValue.IsValidIndex(_InLevel - 1) ? CharacterStatTableValue[_InLevel - 1] : FCharacterStatData(); }
	FORCEINLINE FCharacterStatData GetCharacterStatData(FName _Name) const {return *CharacterStatTableKeyAndValue.Find(_Name);}

	FORCEINLINE FMonsterData GetMonsterData(FName _Name) const { return *MonsterDataTableKeyAndValue.Find(_Name); }
	
	FORCEINLINE FBulletData GetBulletData(FName _Name) const { return *BulletDataTableKeyAndValue.Find(_Name); }


	UPROPERTY()
	int32 CharacterMaxLevel;	//�� ���� ������ �������ִ���


private:
	TArray<FCharacterStatData> CharacterStatTableValue;
	TMap<FName,FCharacterStatData> CharacterStatTableKeyAndValue;

	TMap<FName, FMonsterData> MonsterDataTableKeyAndValue;

	TMap<FName, FBulletData> BulletDataTableKeyAndValue;

};
