#include "OverlayMenuWidget.h"

#include "GP4/Subsystems/CombatSubsystem.h"
#include "GP4/Subsystems/ProgressSubsystem.h"
#include "GP4/Subsystems/UISubsystem.h"
#include "Kismet/GameplayStatics.h"

void UOverlayMenuWidget::UpdateOverlayValues()
{
	ULocalPlayer* LocalPlayer;
	UGameInstance* GameInstance;
	UCombatSubsystem* CombatSubsystem;
	UUISubsystem* UISubsystem;
	UProgressSubsystem* ProgressSubsystem;
	UPlayerSubsystem* PlayerSubsystem;
	UEnemySubsystem* EnemySubsystem;

	LocalPlayer = GetOwningLocalPlayer();
	GameInstance = Cast<UGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	UISubsystem = GameInstance->GetSubsystem<UUISubsystem>();
	PlayerSubsystem = LocalPlayer->GetSubsystem<UPlayerSubsystem>();
	CombatSubsystem = LocalPlayer->GetSubsystem<UCombatSubsystem>();
	EnemySubsystem = GetWorld()->GetSubsystem<UEnemySubsystem>();
	ProgressSubsystem = GetWorld()->GetSubsystem<UProgressSubsystem>();

	//Shotgun UI
	
	ShotgunNumber->SetText(FText::FromString(FString::Printf(TEXT("%d/5"), ProgressSubsystem->ShotGunSetInfo.NumberOfWeaponsAcquired)));
	
	if(ProgressSubsystem->ShotGunSetInfo.HasI)
	{
		Shotgun1Frame->SetColorAndOpacity(CommonColor);
		Shotgun1Img->SetColorAndOpacity(FLinearColor::White);
	}
	if(ProgressSubsystem->ShotGunSetInfo.HasII)
	{
		Shotgun2Frame->SetColorAndOpacity(CommonColor);
		Shotgun2Img->SetColorAndOpacity(FLinearColor::White);
	}
	if(ProgressSubsystem->ShotGunSetInfo.HasIII)
	{
		Shotgun3Frame->SetColorAndOpacity(CommonColor);
		Shotgun3Img->SetColorAndOpacity(FLinearColor::White);
	}
	if(ProgressSubsystem->ShotGunSetInfo.HasIV)
	{
		Shotgun4Frame->SetColorAndOpacity(RareColor);
		Shotgun4Img->SetColorAndOpacity(FLinearColor::White);
	}
	if(ProgressSubsystem->ShotGunSetInfo.HasV)
	{
		Shotgun5Frame->SetColorAndOpacity(LegendaryColor);
		Shotgun5Img->SetColorAndOpacity(FLinearColor::White);
	}

	if(ProgressSubsystem->ShotGunSetInfo.NumberOfWeaponsAcquired == 5)
	{

		//Enable Shotgun Bonus UI

		ShotgunBonusBack->SetColorAndOpacity(FLinearColor::White);
		ShotgunBonusBack->SetRenderOpacity(1);

		ShotgunBonusBox->SetRenderOpacity(1);

		ShotgunLockBox->SetRenderOpacity(0);

		if(IsValid(ShotgunUIData))
		{
			ShotgunStatName_1->SetText(ShotgunUIData->Row1Name);
			ShotgunStatName_2->SetText(ShotgunUIData->Row2Name);
			ShotgunStatName_3->SetText(ShotgunUIData->Row3Name);

			ShotgunStatValue_1->SetText(ShotgunUIData->Row1Value);
			ShotgunStatValue_2->SetText(ShotgunUIData->Row2Value);
			ShotgunStatValue_3->SetText(ShotgunUIData->Row3Value);

			switch (ShotgunUIData->Row1Color)
			{
			case EUpgradeFieldColor::Green:
				//ShotgunStatName_1->SetColorAndOpacity(GreenFieldColor);
				ShotgunStatValue_1->SetColorAndOpacity(GreenFieldColor);
				break;

			case EUpgradeFieldColor::Red:
				//ShotgunStatName_1->SetColorAndOpacity(RedFieldColor);
				ShotgunStatValue_1->SetColorAndOpacity(RedFieldColor);
				break;

			case EUpgradeFieldColor::White:
				//ShotgunStatName_1->SetColorAndOpacity(WhiteFieldColor);
				ShotgunStatValue_1->SetColorAndOpacity(WhiteFieldColor);
				break;
			}
		}
	}

	//Sniper UI
	
	SniperNumber->SetText(FText::FromString(FString::Printf(TEXT("%d/5"), ProgressSubsystem->SniperSetInfo.NumberOfWeaponsAcquired)));
	
	if(ProgressSubsystem->SniperSetInfo.HasI)
	{
		Sniper1Frame->SetColorAndOpacity(CommonColor);
		Sniper1Img->SetColorAndOpacity(FLinearColor::White);
	}
	if(ProgressSubsystem->SniperSetInfo.HasII)
	{
		Sniper2Frame->SetColorAndOpacity(CommonColor);
		Sniper2Img->SetColorAndOpacity(FLinearColor::White);
	}
	if(ProgressSubsystem->SniperSetInfo.HasIII)
	{
		Sniper3Frame->SetColorAndOpacity(CommonColor);
		Sniper3Img->SetColorAndOpacity(FLinearColor::White);
	}
	if(ProgressSubsystem->SniperSetInfo.HasIV)
	{
		Sniper4Frame->SetColorAndOpacity(RareColor);
		Sniper4Img->SetColorAndOpacity(FLinearColor::White);
	}
	if(ProgressSubsystem->SniperSetInfo.HasV)
	{
		Sniper5Frame->SetColorAndOpacity(LegendaryColor);
		Sniper5Img->SetColorAndOpacity(FLinearColor::White);
	}

	if(ProgressSubsystem->SniperSetInfo.NumberOfWeaponsAcquired == 5)
	{

		//Enable Sniper Bonus UI

		SniperBonusBack->SetColorAndOpacity(FLinearColor::White);
		SniperBonusBack->SetRenderOpacity(1);

		SniperBonusBox->SetRenderOpacity(1);

		SniperLockBox->SetRenderOpacity(0);

		if(IsValid(SniperUIData))
		{
			SniperStatName_1->SetText(SniperUIData->Row1Name);
			SniperStatName_2->SetText(SniperUIData->Row2Name);
			SniperStatName_3->SetText(SniperUIData->Row3Name);

			SniperStatValue_1->SetText(SniperUIData->Row1Value);
			SniperStatValue_2->SetText(SniperUIData->Row2Value);
			SniperStatValue_3->SetText(SniperUIData->Row3Value);

			switch (SniperUIData->Row1Color)
			{
			case EUpgradeFieldColor::Green:
				//SniperStatName_1->SetColorAndOpacity(GreenFieldColor);
				SniperStatValue_1->SetColorAndOpacity(GreenFieldColor);
				break;

			case EUpgradeFieldColor::Red:
				//SniperStatName_1->SetColorAndOpacity(RedFieldColor);
				SniperStatValue_1->SetColorAndOpacity(RedFieldColor);
				break;

			case EUpgradeFieldColor::White:
				//SniperStatName_1->SetColorAndOpacity(WhiteFieldColor);
				SniperStatValue_1->SetColorAndOpacity(WhiteFieldColor);
				break;
			}
		}
	}

	//Rifle UI
	
	RifleNumber->SetText(FText::FromString(FString::Printf(TEXT("%d/5"), ProgressSubsystem->RifleSetInfo.NumberOfWeaponsAcquired)));
	
	if(ProgressSubsystem->RifleSetInfo.HasI)
	{
		Rifle1Frame->SetColorAndOpacity(CommonColor);
		Rifle1Img->SetColorAndOpacity(FLinearColor::White);
	}
	if(ProgressSubsystem->RifleSetInfo.HasII)
	{
		Rifle2Frame->SetColorAndOpacity(CommonColor);
		Rifle2Img->SetColorAndOpacity(FLinearColor::White);
	}
	if(ProgressSubsystem->RifleSetInfo.HasIII)
	{
		Rifle3Frame->SetColorAndOpacity(CommonColor);
		Rifle3Img->SetColorAndOpacity(FLinearColor::White);
	}
	if(ProgressSubsystem->RifleSetInfo.HasIV)
	{
		Rifle4Frame->SetColorAndOpacity(RareColor);
		Rifle4Img->SetColorAndOpacity(FLinearColor::White);
	}
	if(ProgressSubsystem->RifleSetInfo.HasV)
	{
		Rifle5Frame->SetColorAndOpacity(LegendaryColor);
		Rifle5Img->SetColorAndOpacity(FLinearColor::White);
	}

	if(ProgressSubsystem->RifleSetInfo.NumberOfWeaponsAcquired == 5)
	{

		//Enable Rifle Bonus UI

		RifleBonusBack->SetColorAndOpacity(FLinearColor::White);
		RifleBonusBack->SetRenderOpacity(1);

		RifleBonusBox->SetRenderOpacity(1);

		RifleLockBox->SetRenderOpacity(0);

		if(IsValid(RifleUIData))
		{
			RifleStatName_1->SetText(RifleUIData->Row1Name);
			RifleStatName_2->SetText(RifleUIData->Row2Name);
			RifleStatName_3->SetText(RifleUIData->Row3Name);

			RifleStatValue_1->SetText(RifleUIData->Row1Value);
			RifleStatValue_2->SetText(RifleUIData->Row2Value);
			RifleStatValue_3->SetText(RifleUIData->Row3Value);

			switch (RifleUIData->Row1Color)
			{
			case EUpgradeFieldColor::Green:
				//RifleStatName_1->SetColorAndOpacity(GreenFieldColor);
				RifleStatValue_1->SetColorAndOpacity(GreenFieldColor);
				break;

			case EUpgradeFieldColor::Red:
				//RifleStatName_1->SetColorAndOpacity(RedFieldColor);
				RifleStatValue_1->SetColorAndOpacity(RedFieldColor);
				break;

			case EUpgradeFieldColor::White:
				//RifleStatName_1->SetColorAndOpacity(WhiteFieldColor);
				RifleStatValue_1->SetColorAndOpacity(WhiteFieldColor);
				break;
			}
		}
	}

	//Machinegun UI
	
	MachinegunNumber->SetText(FText::FromString(FString::Printf(TEXT("%d/5"), ProgressSubsystem->MachineGunSetInfo.NumberOfWeaponsAcquired)));
	
	if(ProgressSubsystem->MachineGunSetInfo.HasI)
	{
		Machinegun1Frame->SetColorAndOpacity(CommonColor);
		Machinegun1Img->SetColorAndOpacity(FLinearColor::White);
	}
	if(ProgressSubsystem->MachineGunSetInfo.HasII)
	{
		Machinegun2Frame->SetColorAndOpacity(CommonColor);
		Machinegun2Img->SetColorAndOpacity(FLinearColor::White);
	}
	if(ProgressSubsystem->MachineGunSetInfo.HasIII)
	{
		Machinegun3Frame->SetColorAndOpacity(CommonColor);
		Machinegun3Img->SetColorAndOpacity(FLinearColor::White);
	}
	if(ProgressSubsystem->MachineGunSetInfo.HasIV)
	{
		Machinegun4Frame->SetColorAndOpacity(RareColor);
		Machinegun4Img->SetColorAndOpacity(FLinearColor::White);
	}
	if(ProgressSubsystem->MachineGunSetInfo.HasV)
	{
		Machinegun5Frame->SetColorAndOpacity(LegendaryColor);
		Machinegun5Img->SetColorAndOpacity(FLinearColor::White);
	}

	if(ProgressSubsystem->MachineGunSetInfo.NumberOfWeaponsAcquired == 5)
	{

		//Enable Machinegun Bonus UI

		MachinegunBonusBack->SetColorAndOpacity(FLinearColor::White);
		MachinegunBonusBack->SetRenderOpacity(1);

		MachinegunBonusBox->SetRenderOpacity(1);

		MachinegunLockBox->SetRenderOpacity(0);

		if(IsValid(MachinegunUIData))
		{
			MachinegunStatName_1->SetText(MachinegunUIData->Row1Name);
			MachinegunStatName_2->SetText(MachinegunUIData->Row2Name);
			MachinegunStatName_3->SetText(MachinegunUIData->Row3Name);

			MachinegunStatValue_1->SetText(MachinegunUIData->Row1Value);
			MachinegunStatValue_2->SetText(MachinegunUIData->Row2Value);
			MachinegunStatValue_3->SetText(MachinegunUIData->Row3Value);

			switch (MachinegunUIData->Row1Color)
			{
			case EUpgradeFieldColor::Green:
				//MachinegunStatName_1->SetColorAndOpacity(GreenFieldColor);
				MachinegunStatValue_1->SetColorAndOpacity(GreenFieldColor);
				break;

			case EUpgradeFieldColor::Red:
				//MachinegunStatName_1->SetColorAndOpacity(RedFieldColor);
				MachinegunStatValue_1->SetColorAndOpacity(RedFieldColor);
				break;

			case EUpgradeFieldColor::White:
				//MachinegunStatName_1->SetColorAndOpacity(WhiteFieldColor);
				MachinegunStatValue_1->SetColorAndOpacity(WhiteFieldColor);
				break;
			}
		}
	}

	//Game Stats UI

	//TODO: Hook up game stats ui variables
	
	KillNumber->SetText(FText::FromString(FString::Printf(TEXT("%d"), EnemySubsystem->GetCurrentKillCount())));
	UpgradeNumber->SetText(FText::FromString(FString::Printf(TEXT("%d"), ProgressSubsystem->GetNumberOfUpgradesGotten())));

	//Weapon Stats UI

	int Damage = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::BaseDamage));
	DamageNumber->SetText(FText::FromString(FString::Printf(TEXT("%d"), Damage)));

	int Defense = FMath::RoundToInt(PlayerSubsystem->GetPlayerStat(EPlayerAttributeType::Defense));
	DefenseNumber->SetText(FText::FromString(FString::Printf(TEXT("%d"), Defense)));

	int CritChance = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::CritChance));
	CritChanceNumber->SetText(FText::FromString(FString::Printf(TEXT("%d%%"), CritChance)));
	
	CritDamageNumber->SetText(FText::FromString(FString::Printf(TEXT("%.1fX"), CombatSubsystem->GetWeaponStat(EWeaponAttributeType::CritDamageMultiplier))));
	
	WeakpointDamageNumber->SetText(FText::FromString(FString::Printf(TEXT("%.1fX"), CombatSubsystem->GetWeaponStat(EWeaponAttributeType::WeakPointDamageMultiplier))));

	int Projectiles = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::BulletCount));
	ProjectilesNumber->SetText(FText::FromString(FString::Printf(TEXT("%d"), Projectiles)));

	int FireRate = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::FireRate));
	FireRateNumber->SetText(FText::FromString(FString::Printf(TEXT("%d BPS"), FireRate)));

	int Accuracy = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::Accuracy));
	AccuracyNumber->SetText(FText::FromString(FString::Printf(TEXT("%d"), Accuracy)));
}

void UOverlayMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
}
