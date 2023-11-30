// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/GameDataSingleton.h"

//DEFINE_LOG_CATEGORY(LogABGameSingleton);

UGameDataSingleton::UGameDataSingleton()
{
	{
		static ConstructorHelpers::FObjectFinder<UDataTable> DataTableRef(TEXT("/Script/Engine.DataTable'/Game/GTFO/Data/CharacterStatTable.CharacterStatTable'"));
		if (nullptr != DataTableRef.Object)
		{
			const UDataTable* DataTable = DataTableRef.Object;
			check(DataTable->GetRowMap().Num() > 0);

			TArray<FName> RowNames = DataTable->GetRowNames();
			for (const FName& RowName : RowNames)
			{
				FCharacterStatData* Value = DataTable->FindRow<FCharacterStatData>(RowName, TEXT(""));
				CharacterStatTableKeyAndValue.Add(RowName, *Value);
			}

			TArray<uint8*> ValueArray;
			DataTable->GetRowMap().GenerateValueArray(ValueArray);
			Algo::Transform(ValueArray, CharacterStatTableValue,
				[](uint8* Value)
				{
					return *reinterpret_cast<FCharacterStatData*>(Value);
				}
			);

			CharacterMaxLevel = CharacterStatTableValue.Num();
		}
	}

	{
		static ConstructorHelpers::FObjectFinder<UDataTable> DataTableRef(TEXT("/Script/Engine.DataTable'/Game/GTFO/Data/MosterDataTable.MosterDataTable'"));
		if (nullptr != DataTableRef.Object)
		{
			const UDataTable* DataTable = DataTableRef.Object;
			check(DataTable->GetRowMap().Num() > 0);

			TArray<FName> RowNames = DataTable->GetRowNames();

			for (const FName& RowName : RowNames)
			{
				FMonsterData* Value = DataTable->FindRow<FMonsterData>(RowName, TEXT(""));
				MonsterDataTableKeyAndValue.Add(RowName, *Value);
			}
		}
	}

	{
		static ConstructorHelpers::FObjectFinder<UDataTable> DataTableRef(TEXT("/Script/Engine.DataTable'/Game/GTFO/Data/BulletDataTable.BulletDataTable'"));
		if (nullptr != DataTableRef.Object)
		{
			const UDataTable* DataTable = DataTableRef.Object;
			check(DataTable->GetRowMap().Num() > 0);

			TArray<FName> RowNames = DataTable->GetRowNames();

			for (const FName& RowName : RowNames)
			{
				FBulletData* Value = DataTable->FindRow<FBulletData>(RowName, TEXT(""));
				BulletDataTableKeyAndValue.Add(RowName, *Value);
			}
		}
	}

}

UGameDataSingleton& UGameDataSingleton::GetInst()
{
	//������ �ʱ�ȭ �� �� �ٷ� Ȱ��ȭ�� �Ǵ� ���� ������ �ޱ� ������
	//���� ���� �� ���ٸ� ���� �߸��� �Ŷ�� �� �� �ִ�.
	UGameDataSingleton* Singleton = CastChecked< UGameDataSingleton>(GEngine->GameSingleton);
	if (Singleton)
	{
		return *Singleton;
	}

	//UE_LOG(LogABGameSingleton, Error, TEXT("Invalid Game Singleton"));
	return *NewObject<UGameDataSingleton>();

}
