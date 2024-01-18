#include "UpgradeEntry.h"
#include "GP4/Upgrade/UpgradeBase.h"

void UUpgradeEntry::NativeOnListItemObjectSet(UObject* UpgradeItem)
{
	UUpgradeBase* Item = Cast<UUpgradeBase>(UpgradeItem);
	
	UpgradeIcon->SetBrushFromTexture(Item->UpgradeIcon);
	UpgradeName->SetText(Item->UpgradeName);

	switch (Item->UpgradeRarity)
	{
	case EUpgradeRarity::Common:
		UpgradeType->SetColorAndOpacity(CommonRarityColor);
		UpgradeName->SetColorAndOpacity(CommonRarityColor);
		Frame->SetColorAndOpacity(CommonRarityColor);
		break;

	case EUpgradeRarity::Rare:
		UpgradeType->SetColorAndOpacity(RareRarityColor);
		UpgradeName->SetColorAndOpacity(RareRarityColor);
		Frame->SetColorAndOpacity(RareRarityColor);
		break;

	case EUpgradeRarity::Legendary:
		UpgradeType->SetColorAndOpacity(LegendaryRarityColor);
		UpgradeName->SetColorAndOpacity(LegendaryRarityColor);
		Frame->SetColorAndOpacity(LegendaryRarityColor);
		break;
	}

	switch (Item->UpgradeType)
	{
	case EUpgradeType::GunUpgrade:
		UpgradeType->SetText(FText::FromString("Weapon Upgrade"));
		break;

	case EUpgradeType::PlayerUpgrade:
		UpgradeType->SetText(FText::FromString("Player Upgrade"));
		break;
	}

	ClearLines();
	SetInfoLineText(Item->WeaponUpgradeData, Item->PlayerUpgradeData);
}

void UUpgradeEntry::ClearLines()
{
	StatName_1->SetText(FText::FromString(""));
	StatValue_1->SetText(FText::FromString(""));
	StatName_2->SetText(FText::FromString(""));
	StatValue_2->SetText(FText::FromString(""));
	StatName_3->SetText(FText::FromString(""));
	StatValue_3->SetText(FText::FromString(""));
	StatName_4->SetText(FText::FromString(""));
	StatValue_4->SetText(FText::FromString(""));
	StatName_5->SetText(FText::FromString(""));
	StatValue_5->SetText(FText::FromString(""));
	StatName_6->SetText(FText::FromString(""));
	StatValue_6->SetText(FText::FromString(""));
}

void UUpgradeEntry::SetInfoLineText(UGunBaseStats* GunUpgradeData = nullptr, UPlayerBaseStats* PlayerUpgradeData = nullptr)
{
	ULocalPlayer* LocalPlayer = GetOwningLocalPlayer();
	UPlayerSubsystem* PlayerSubsystem = LocalPlayer->GetSubsystem<UPlayerSubsystem>();
	UCombatSubsystem* CombatSubsystem = LocalPlayer->GetSubsystem<UCombatSubsystem>();

	int CurrentLineIndex = 1;
	
	if(IsValid(GunUpgradeData))
	{
		/*
		Upgrade Display Order:
		 
		BulletCount
		BaseDamage
		FireRate
		Clipsize 
		Accuracy
		CritChance
		CritDamageMulti
		WeakpointDamageMulti
		ReloadTime
		BulletRange
		*/

		// POSITIVE STATS:
		
		if(GunUpgradeData->BulletCount > 0)
		{
			int PreviousBulletCount = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::BulletCount));
			int NewBulletCount = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::BulletCount) + GunUpgradeData->BulletCount);
			SetLineUI(CurrentLineIndex, FText::FromString("PROJECTILES"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Positive>%d</>"), PreviousBulletCount, NewBulletCount)));
			CurrentLineIndex++;
		}
		if(GunUpgradeData->BaseDamage > 0)
		{
			int PreviousBaseDamage = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::BaseDamage));
			int NewBaseDamage = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::BaseDamage) + GunUpgradeData->BaseDamage);
			SetLineUI(CurrentLineIndex, FText::FromString("BASE DMG"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Positive>%d</>"), PreviousBaseDamage, NewBaseDamage)));
			CurrentLineIndex++;
		}
		if(GunUpgradeData->FireRate > 0)
		{
			float PreviousFireRate = CombatSubsystem->GetWeaponStat(EWeaponAttributeType::FireRate);
			float NewFireRate = CombatSubsystem->GetWeaponStat(EWeaponAttributeType::FireRate) + GunUpgradeData->FireRate;
			SetLineUI(CurrentLineIndex, FText::FromString("FIRE RATE"), FText::FromString(FString::Printf(TEXT("%.1f -> <RichText.Positive>%.1f</> bps"), PreviousFireRate, NewFireRate)));
			CurrentLineIndex++;
		}
		if(GunUpgradeData->ClipSize > 0)
		{
			int PreviousClipSize = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::ClipSize));
			int NewClipSize = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::ClipSize) + GunUpgradeData->ClipSize);
			SetLineUI(CurrentLineIndex, FText::FromString("CLIP SIZE"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Positive>%d</>"), PreviousClipSize, NewClipSize)));
			CurrentLineIndex++;
		}
		if(GunUpgradeData->Accuracy > 0)
		{
			int PreviousAccuracy = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::Accuracy));
			int NewAccuracy = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::Accuracy) + GunUpgradeData->Accuracy);
			SetLineUI(CurrentLineIndex, FText::FromString("ACCURACY"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Positive>%d</>"), PreviousAccuracy, NewAccuracy)));
			CurrentLineIndex++;
		}
		if(GunUpgradeData->CritChance > 0)
		{
			int PreviousCritChance = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::CritChance));
			int NewCritChance = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::CritChance) + GunUpgradeData->CritChance);
			SetLineUI(CurrentLineIndex, FText::FromString("CRIT CHANCE"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Positive>%d</> %%"), PreviousCritChance, NewCritChance)));
			CurrentLineIndex++;
		}
		if(GunUpgradeData->CritDamageMultiplier > 0)
		{
			float PreviousCritDamageMultiplier = CombatSubsystem->GetWeaponStat(EWeaponAttributeType::CritDamageMultiplier);
			float NewCritDamageMultiplier = CombatSubsystem->GetWeaponStat(EWeaponAttributeType::CritDamageMultiplier) + GunUpgradeData->CritDamageMultiplier;
			SetLineUI(CurrentLineIndex, FText::FromString("CRIT DMG"), FText::FromString(FString::Printf(TEXT("%.1f -> <RichText.Positive>%.1f</> x"), PreviousCritDamageMultiplier, NewCritDamageMultiplier)));
			CurrentLineIndex++;
		}
		if(GunUpgradeData->WeakPointDamageMultiplier > 0)
		{
			float PreviousWeakPointDamageMultiplier = CombatSubsystem->GetWeaponStat(EWeaponAttributeType::WeakPointDamageMultiplier);
			float NewWeakPointDamageMultiplier = CombatSubsystem->GetWeaponStat(EWeaponAttributeType::WeakPointDamageMultiplier) + GunUpgradeData->WeakPointDamageMultiplier;
			SetLineUI(CurrentLineIndex, FText::FromString("WEAKPOINT DMG"), FText::FromString(FString::Printf(TEXT("%.1f -> <RichText.Positive>%.1f</> x"), PreviousWeakPointDamageMultiplier, NewWeakPointDamageMultiplier)));
			CurrentLineIndex++;
		}
		if(GunUpgradeData->ReloadTime < 0)
		{
			float PreviousReloadTime = CombatSubsystem->GetWeaponStat(EWeaponAttributeType::ReloadTime);
			float NewReloadTime = CombatSubsystem->GetWeaponStat(EWeaponAttributeType::ReloadTime) + GunUpgradeData->ReloadTime;
			SetLineUI(CurrentLineIndex, FText::FromString("RELOAD TIME"), FText::FromString(FString::Printf(TEXT("%.1f -> <RichText.Positive>%.1f</> sec"), PreviousReloadTime, NewReloadTime)));
			CurrentLineIndex++;
		}
		if(GunUpgradeData->BulletRange > 0)
		{
			int PreviousBulletRange = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::BulletRange));
			int NewBulletRange = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::BulletRange) + GunUpgradeData->BulletRange);
			SetLineUI(CurrentLineIndex, FText::FromString("BULLET RANGE"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Positive>%d</> m"), PreviousBulletRange, NewBulletRange)));
			CurrentLineIndex++;
		}

		// NEGATIVE STATS:

		if(GunUpgradeData->BulletCount < 0)
		{
			int PreviousBulletCount = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::BulletCount));
			int NewBulletCount = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::BulletCount) + GunUpgradeData->BulletCount);
			SetLineUI(CurrentLineIndex, FText::FromString("PROJECTILES"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Negative>%d</>"), PreviousBulletCount, NewBulletCount)));
			CurrentLineIndex++;
		}
		if(GunUpgradeData->BaseDamage < 0)
		{
			int PreviousBaseDamage = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::BaseDamage));
			int NewBaseDamage = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::BaseDamage) + GunUpgradeData->BaseDamage);
			SetLineUI(CurrentLineIndex, FText::FromString("BASE DMG"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Negative>%d</>"), PreviousBaseDamage, NewBaseDamage)));
			CurrentLineIndex++;
		}
		if(GunUpgradeData->FireRate < 0)
		{
			float PreviousFireRate = CombatSubsystem->GetWeaponStat(EWeaponAttributeType::FireRate);
			float NewFireRate = CombatSubsystem->GetWeaponStat(EWeaponAttributeType::FireRate) + GunUpgradeData->FireRate;
			SetLineUI(CurrentLineIndex, FText::FromString("FIRE RATE"), FText::FromString(FString::Printf(TEXT("%.1f -> <RichText.Negative>%.1f</> bps"), PreviousFireRate, NewFireRate)));
			CurrentLineIndex++;
		}
		if(GunUpgradeData->ClipSize < 0)
		{
			int PreviousClipSize = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::ClipSize));
			int NewClipSize = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::ClipSize) + GunUpgradeData->ClipSize);
			SetLineUI(CurrentLineIndex, FText::FromString("CLIP SIZE"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Negative>%d</>"), PreviousClipSize, NewClipSize)));
			CurrentLineIndex++;
		}
		if(GunUpgradeData->Accuracy < 0)
		{
			int PreviousAccuracy = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::Accuracy));
			int NewAccuracy = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::Accuracy) + GunUpgradeData->Accuracy);
			SetLineUI(CurrentLineIndex, FText::FromString("ACCURACY"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Negative>%d</>"), PreviousAccuracy, NewAccuracy)));
			CurrentLineIndex++;
		}
		if(GunUpgradeData->CritChance < 0)
		{
			int PreviousCritChance = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::CritChance));
			int NewCritChance = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::CritChance) + GunUpgradeData->CritChance);
			SetLineUI(CurrentLineIndex, FText::FromString("CRIT CHANCE"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Negative>%d</> %%"), PreviousCritChance, NewCritChance)));
			CurrentLineIndex++;
		}
		if(GunUpgradeData->CritDamageMultiplier < 0)
		{
			float PreviousCritDamageMultiplier = CombatSubsystem->GetWeaponStat(EWeaponAttributeType::CritDamageMultiplier);
			float NewCritDamageMultiplier = CombatSubsystem->GetWeaponStat(EWeaponAttributeType::CritDamageMultiplier) + GunUpgradeData->CritDamageMultiplier;
			SetLineUI(CurrentLineIndex, FText::FromString("CRIT DMG"), FText::FromString(FString::Printf(TEXT("%.1f -> <RichText.Negative>%.1f</> x"), PreviousCritDamageMultiplier, NewCritDamageMultiplier)));
			CurrentLineIndex++;
		}
		if(GunUpgradeData->WeakPointDamageMultiplier < 0)
		{
			float PreviousWeakPointDamageMultiplier = CombatSubsystem->GetWeaponStat(EWeaponAttributeType::WeakPointDamageMultiplier);
			float NewWeakPointDamageMultiplier = CombatSubsystem->GetWeaponStat(EWeaponAttributeType::WeakPointDamageMultiplier) + GunUpgradeData->WeakPointDamageMultiplier;
			SetLineUI(CurrentLineIndex, FText::FromString("WEAKPOINT DMG"), FText::FromString(FString::Printf(TEXT("%.1f -> <RichText.Negative>%.1f</> x"), PreviousWeakPointDamageMultiplier, NewWeakPointDamageMultiplier)));
			CurrentLineIndex++;
		}
		if(GunUpgradeData->ReloadTime > 0)
		{
			float PreviousReloadTime = CombatSubsystem->GetWeaponStat(EWeaponAttributeType::ReloadTime);
			float NewReloadTime = CombatSubsystem->GetWeaponStat(EWeaponAttributeType::ReloadTime) + GunUpgradeData->ReloadTime;
			SetLineUI(CurrentLineIndex, FText::FromString("RELOAD TIME"), FText::FromString(FString::Printf(TEXT("%.1f -> <RichText.Negative>%.1f</> sec"), PreviousReloadTime, NewReloadTime)));
			CurrentLineIndex++;
		}
		if(GunUpgradeData->BulletRange < 0)
		{
			int PreviousBulletRange = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::BulletRange));
			int NewBulletRange = FMath::RoundToInt(CombatSubsystem->GetWeaponStat(EWeaponAttributeType::BulletRange) + GunUpgradeData->BulletRange);
			SetLineUI(CurrentLineIndex, FText::FromString("BULLET RANGE"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Negative>%d</> m"), PreviousBulletRange, NewBulletRange)));
			CurrentLineIndex++;
		}
	}
	
	if(IsValid(PlayerUpgradeData))
	{
		/*
		Upgrade Display Order:
		 
		MaxHealth
		Shield
		Defense
		MoveSpeed
		*/

		// POSITIVE STATS:

		if(PlayerUpgradeData->MaxHealth > 0)
		{
			int PreviousMaxHealth = FMath::RoundToInt(PlayerSubsystem->GetPlayerStat(EPlayerAttributeType::MaxHealth));
			int NewMaxHealth = FMath::RoundToInt(PlayerSubsystem->GetPlayerStat(EPlayerAttributeType::MaxHealth) + PlayerUpgradeData->MaxHealth);
			SetLineUI(CurrentLineIndex, FText::FromString("MAX HEALTH"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Positive>%d</>"), PreviousMaxHealth, NewMaxHealth)));
			CurrentLineIndex++;
		}
		if(PlayerUpgradeData->Shield > 0)
		{
			int PreviousShield = FMath::RoundToInt(PlayerSubsystem->GetPlayerStat(EPlayerAttributeType::Shield));
			int NewShield = FMath::RoundToInt(PlayerSubsystem->GetPlayerStat(EPlayerAttributeType::Shield) + PlayerUpgradeData->Shield);
			SetLineUI(CurrentLineIndex, FText::FromString("SHIELD"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Positive>%d</>"), PreviousShield, NewShield)));
			CurrentLineIndex++;
		}
		if(PlayerUpgradeData->Defense > 0)
		{
			int PreviousDefense = FMath::RoundToInt(PlayerSubsystem->GetPlayerStat(EPlayerAttributeType::Defense));
			int NewDefense = FMath::RoundToInt(PlayerSubsystem->GetPlayerStat(EPlayerAttributeType::Defense) + PlayerUpgradeData->Defense);
			SetLineUI(CurrentLineIndex, FText::FromString("DEFENSE"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Positive>%d</>"), PreviousDefense, NewDefense)));
			CurrentLineIndex++;
		}
		if(PlayerUpgradeData->MoveSpeed > 0)
		{
			int PreviousMoveSpeed = FMath::RoundToInt(PlayerSubsystem->GetPlayerStat(EPlayerAttributeType::MoveSpeed));
			int NewMoveSpeed = FMath::RoundToInt(PlayerSubsystem->GetPlayerStat(EPlayerAttributeType::MoveSpeed) + PlayerUpgradeData->MoveSpeed);
			SetLineUI(CurrentLineIndex, FText::FromString("MOVE SPEED"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Positive>%d</>"), PreviousMoveSpeed, NewMoveSpeed)));
			CurrentLineIndex++;
		}
		
		// NEGATIVE STATS:

		if(PlayerUpgradeData->MaxHealth < 0)
		{
			int PreviousMaxHealth = FMath::RoundToInt(PlayerSubsystem->GetPlayerStat(EPlayerAttributeType::MaxHealth));
			int NewMaxHealth = FMath::RoundToInt(PlayerSubsystem->GetPlayerStat(EPlayerAttributeType::MaxHealth) + PlayerUpgradeData->MaxHealth);
			SetLineUI(CurrentLineIndex, FText::FromString("MAX HEALTH"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Negative>%d</>"), PreviousMaxHealth, NewMaxHealth)));
			CurrentLineIndex++;
		}
		if(PlayerUpgradeData->Shield < 0)
		{
			int PreviousShield = FMath::RoundToInt(PlayerSubsystem->GetPlayerStat(EPlayerAttributeType::Shield));
			int NewShield = FMath::RoundToInt(PlayerSubsystem->GetPlayerStat(EPlayerAttributeType::Shield) + PlayerUpgradeData->Shield);
			SetLineUI(CurrentLineIndex, FText::FromString("SHIELD"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Negative>%d</>"), PreviousShield, NewShield)));
			CurrentLineIndex++;
		}
		if(PlayerUpgradeData->Defense < 0)
		{
			int PreviousDefense = FMath::RoundToInt(PlayerSubsystem->GetPlayerStat(EPlayerAttributeType::Defense));
			int NewDefense = FMath::RoundToInt(PlayerSubsystem->GetPlayerStat(EPlayerAttributeType::Defense) + PlayerUpgradeData->Defense);
			SetLineUI(CurrentLineIndex, FText::FromString("DEFENSE"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Negative>%d</>"), PreviousDefense, NewDefense)));
			CurrentLineIndex++;
		}
		if(PlayerUpgradeData->MoveSpeed < 0)
		{
			int PreviousMoveSpeed = FMath::RoundToInt(PlayerSubsystem->GetPlayerStat(EPlayerAttributeType::MoveSpeed));
			int NewMoveSpeed = FMath::RoundToInt(PlayerSubsystem->GetPlayerStat(EPlayerAttributeType::MoveSpeed) + PlayerUpgradeData->MoveSpeed);
			SetLineUI(CurrentLineIndex, FText::FromString("MOVE SPEED"), FText::FromString(FString::Printf(TEXT("%d -> <RichText.Negative>%d</>"), PreviousMoveSpeed, NewMoveSpeed)));
			CurrentLineIndex++;
		}
	}
}

void UUpgradeEntry::SetLineUI(int LineIndex, FText LineDescription, FText LineValue)
{
	UTextBlock* UpgradeDescription;
	URichTextBlock* UpgradeValue;
	
	switch (LineIndex)
	{
	case 1:
		UpgradeDescription = StatName_1;
		UpgradeValue = StatValue_1;
		break;
	case 2:
		UpgradeDescription = StatName_2;
		UpgradeValue = StatValue_2;
		break;
	case 3:
		UpgradeDescription = StatName_3;
		UpgradeValue = StatValue_3;
		break;
	case 4:
		UpgradeDescription = StatName_4;
		UpgradeValue = StatValue_4;
		break;
	case 5:
		UpgradeDescription = StatName_5;
		UpgradeValue = StatValue_5;
		break;
	case 6:
		UpgradeDescription = StatName_6;
		UpgradeValue = StatValue_6;
		break;
		default: return;
	}

	UpgradeDescription->SetColorAndOpacity(WhiteFieldColor);

	UpgradeDescription->SetText(LineDescription);
	UpgradeValue->SetText(LineValue);
}

