// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSPlayerController.h"
#include "Character/OnTerminal.h"
#include "Character/CharacterBase.h"
#include "UI/MainHUD.h"

AFPSPlayerController::AFPSPlayerController()
{
	ConstructorHelpers::FClassFinder<UUserWidget> MainHUDRef(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/GTFO/UI/UI_Main.UI_Main_C'"));
	if (MainHUDRef.Succeeded())
	{
		MainHUDClass = MainHUDRef.Class;
	}

}

void AFPSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//���� ȭ�鿡�� �÷��̾��� �Է��� ó���ϰ� ���� �ܺ��� �ٷ� ��ҿ� ���� �Է��� �����Ѵ�.
	//���� �÷��� �߿��� �÷��̾��� �Է¸� ó���Ǹ� ���� �ǿ��� �޴��� �ΰ��� UI � ���� �Է��� ���õȴ�. 

	//���� �߿� ����� �������̽��� ��ȣ �ۿ��� �ϰų� ���� �÷��̸������� �� �ַ� ���ȴ�.
	FInputModeGameOnly GameOnlyInputMode;
	SetInputMode(GameOnlyInputMode);

	if (IsValid(MainHUDClass))
	{
		MainHUD = Cast<UMainHUD>(CreateWidget(GetWorld(), MainHUDClass));
		if (IsValid(MainHUD))
		{
			MainHUD->AddToViewport();
			//MainHUD->GetPlayerHPWidget()->SetHp(50.f);
		}
	}


}

void AFPSPlayerController::PossessCharacterPawn()
{
	Possess(BaseCharacterPawn);

	ACharacterBase* CharacterPawn = Cast<ACharacterBase>(BaseCharacterPawn);
	CharacterPawn->SetCharacterInput();
}

void AFPSPlayerController::PossessTerminalPawn()
{

	Possess(OnTerminalPawn);

	AOnTerminal* TerminalPawn = Cast<AOnTerminal>(OnTerminalPawn);
	TerminalPawn->SetTerminalInput();
}
