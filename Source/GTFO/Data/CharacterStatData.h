#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CharacterStatData.generated.h"

USTRUCT(BlueprintType)
struct FCharacterStatData : public FTableRowBase
{
	GENERATED_BODY()

	public:
	FCharacterStatData() : MaxHp(0.0f), JumpZVelocity(0.0f), AirControl(0.0f), MaxWalkSpeed(0.0f), DashPower(0.0f), BrakingDecelerationWalking(0.0f) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float MaxHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float JumpZVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float AirControl;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float MaxWalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float DashPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float BrakingDecelerationWalking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
	float Stemina;

	//float�� ���ִ� ����ü
	// �ΰ��� ����ü�� ���� �������� ��������� ���� �ִ����� �˻��ϰ� �̰��� ���ϴ� ���� �ƴϰ�
	// ũ�⸸ŭ ������ Ȯ���ϰ� �����ָ� ���߿� ���ο� �����ڸ� �߰��ص� ���� ������ ��ĥ �ʿ䰡 ���� �ȴ�. 
	FCharacterStatData operator+(const FCharacterStatData& Other) const
	{
		const float* const ThisPtr = reinterpret_cast<const float* const>(this);
		const float* const OtherPtr = reinterpret_cast<const float* const>(&Other);

		FCharacterStatData Result;
		float* ResultPtr = reinterpret_cast<float*>(&Result);
		int32 StatNum = sizeof(FCharacterStatData) / sizeof(float);
		for (int32 i = 0; i < StatNum; i++)
		{
			ResultPtr[i] = ThisPtr[i] + OtherPtr[i];
		}

		return Result;
	}
};
