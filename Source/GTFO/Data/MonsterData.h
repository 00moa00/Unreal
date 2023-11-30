#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MonsterData.generated.h"

USTRUCT(BlueprintType)
struct FMonsterData : public FTableRowBase
{
	GENERATED_BODY()

	public:
	FMonsterData() : MaxHp(0.0f), Attack(0.0f) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float MaxHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float Attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float AttackRadius;

	//float�� ���ִ� ����ü
	// �ΰ��� ����ü�� ���� �������� ��������� ���� �ִ����� �˻��ϰ� �̰��� ���ϴ� ���� �ƴϰ�
	// ũ�⸸ŭ ������ Ȯ���ϰ� �����ָ� ���߿� ���ο� �����ڸ� �߰��ص� ���� ������ ��ĥ �ʿ䰡 ���� �ȴ�. 
	FMonsterData operator+(const FMonsterData& Other) const
	{
		const float* const ThisPtr = reinterpret_cast<const float* const>(this);
		const float* const OtherPtr = reinterpret_cast<const float* const>(&Other);

		FMonsterData Result;
		float* ResultPtr = reinterpret_cast<float*>(&Result);
		int32 StatNum = sizeof(FMonsterData) / sizeof(float);
		for (int32 i = 0; i < StatNum; i++)
		{
			ResultPtr[i] = ThisPtr[i] + OtherPtr[i];
		}

		return Result;
	}
};
