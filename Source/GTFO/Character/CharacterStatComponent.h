// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/CharacterStatData.h"
#include "CharacterStatComponent.generated.h"




DECLARE_MULTICAST_DELEGATE(FOnHpZeroDelegate);

DECLARE_MULTICAST_DELEGATE_OneParam(FOnHpChangedDelegate, float /*CurrentHp*/);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnSteminaChangedDelegate, float /*Stemina*/);

DECLARE_MULTICAST_DELEGATE_OneParam(FOnRedChangedDelegate, uint32 /*RedBullet*/);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnGreenChangedDelegate, uint32 /*RedBullet*/);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnBlueChangedDelegate, uint32 /*RedBullet*/);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GTFO_API UCharacterStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)override;
	
public:
	FOnHpZeroDelegate OnHpZero; 
	FOnHpChangedDelegate OnHpChanged;
	FOnSteminaChangedDelegate OnSteminaChanged;

	FOnRedChangedDelegate OnRedBulletChanged;
	FOnBlueChangedDelegate OnBlueBulletChanged;
	FOnGreenChangedDelegate OnGreenBulletChanged;


	void SetLevelStat(int32 InNewLevel);
	float ApplyDamage(float InDamage);
	void RecoveryHp(float InKit);

	float ApplyStemina(float InStemina);

	FORCEINLINE float GetCurrentLevel() const { return CurrentLevel; }
	FORCEINLINE void SetModifierStat(const FCharacterStatData& InModifierStat) { ModifierStat = InModifierStat; }
	FORCEINLINE FCharacterStatData GetTotalStat() const { return BaseStat + ModifierStat; }
	FORCEINLINE float GetCurrentHp() const { return CurrentHp; }

	FORCEINLINE uint32 GetBlueBullet() const { return BlueBulllet; }
	FORCEINLINE uint32 GetGreenBullet() const { return GreenBulllet; }
	FORCEINLINE uint32 GetRedBullet() const { return RedBulllet; }
	FORCEINLINE float GetCurrentStemina() const { return CurrentStemina; }

	bool SubBlueBullet(uint32 _Value);
	bool SubGreenBullet(uint32 _Value);
	bool SubRedBullet(uint32 _Value);

	void AddBlueBullet(uint32 _Value);
	void AddGreenBullet(uint32 _Value);
	void AddRedBullet(uint32 _Value);

protected:
	void SetHp(float NewHp);
	void SetStemina(float NewStemina);

	//����ؼ� �ٲ�� ��

	//Transient : ������Ʈ�� ������ ������ �Ӽ����� ��� �� ��ũ�� ������ �ȴ�.
	//���� hp�� ���� ��쿡�� ������ �� ������ ���Ӱ� ������ �Ǳ� �빮�� ������ �ʿ䰡 ���� ���� �ִ�.
	//��ũ�� ������ �ʿ䰡���ٸ� Ʈ������Ʈ��� Ű��Ʈ�� �߰��ؼ� 
	//��ũ�κ��� ������ �� ���ʿ��� ������ ������� �ʵ��� �������� ���� �ִ�.
	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat)
	float CurrentHp;

	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat)
	float CurrentLevel;

	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat)
	float CurrentStemina;

	UPROPERTY()
	float MaxStemina;


	//�������ִ� �Ѿ� ����
	UPROPERTY(EditAnywhere, Category = Stat)
	uint32 BlueBulllet = 0;

	UPROPERTY(EditAnywhere, Category = Stat)
	uint32 GreenBulllet = 0;

	UPROPERTY(EditAnywhere, Category = Stat)
	uint32 RedBulllet = 0;


	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	FCharacterStatData BaseStat;

	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	FCharacterStatData ModifierStat;

		
};
