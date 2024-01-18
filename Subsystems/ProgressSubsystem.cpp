#include "ProgressSubsystem.h"

#include "UISubsystem.h"
#include "Kismet/GameplayStatics.h"

void UProgressSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	ShotGunSetInfo = FWeaponSetInfo();
	RifleSetInfo = FWeaponSetInfo();
	SniperSetInfo = FWeaponSetInfo();
	MachineGunSetInfo = FWeaponSetInfo();
}

void UProgressSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

float UProgressSubsystem::GetCurrentGameProgressPercent()
{
	return CurrentGameProgress;
}

void UProgressSubsystem::IncreaseStageProgressPercent(float Amount)
{
	CurrentGameProgress = FMath::Min(CurrentGameProgress + Amount, 100);

	OnProgressIncrease.Broadcast();

	switch (CurrentStage)
	{
	case EStageType::Denial:
		if(CurrentGameProgress >= 20)
		{
			OnStageCleared.Broadcast(EStageType::Denial);
		}
		break;
	case EStageType::Anger:
		if(CurrentGameProgress >= 40)
		{
			OnStageCleared.Broadcast(EStageType::Anger);
		}
		break;
	case EStageType::Bargain:
		if(CurrentGameProgress >= 60)
		{
			OnStageCleared.Broadcast(EStageType::Bargain);
		}
		break;
	case EStageType::Depression:
		if(CurrentGameProgress >= 80)
		{
			OnStageCleared.Broadcast(EStageType::Depression);
		}
		break;
	case EStageType::Acceptance:
		if(CurrentGameProgress >= 100)
		{
			OnStageCleared.Broadcast(EStageType::Acceptance);
		}
		break;
	default: ;
	}
}

void UProgressSubsystem::SetCurrentStage(EStageType NewStage)
{
	CurrentStage = NewStage;
}

void UProgressSubsystem::NewStageReached()
{
	OnNewStageReached.Broadcast();
}

void UProgressSubsystem::AddUpgradesToPossiblePool(EUpgradeType UpgradeType, TArray<TSubclassOf<UUpgradeBase>> UpgradesToAdd)
{
	
	switch (UpgradeType)
	{
	case EUpgradeType::GunUpgrade:
		for (auto Upgrade : UpgradesToAdd)
		{
			PossibleGunUpgrades.Add(Upgrade);
		}
		break;

	case EUpgradeType::PlayerUpgrade:
		for (auto Upgrade : UpgradesToAdd)
		{
			PossiblePlayerUpgrades.Add(Upgrade);
		}
		break;
	}
}

void UProgressSubsystem::GetNewUpgrade()
{
	int NumberOfUpgrades = FMath::Min(3, PossibleGunUpgrades.Num() + PossiblePlayerUpgrades.Num());
	
	if(NumberOfUpgrades < 1)
	{
		return;
	}

	TArray<TSubclassOf<UUpgradeBase>> SelectedUpgrades;
	
	for ( int i = 0; i < NumberOfUpgrades; i++ )
	{
		TSubclassOf<UUpgradeBase> PickedUpgrade;
		
		switch (i)
		{
			//Get Gun Upgrade
		case 0:
			if(PossibleGunUpgrades.Num() > 0)
			{
				PickedUpgrade = GetUpgradeBasedOnRarity(PossibleGunUpgrades);
				SelectedUpgrades.Add(PickedUpgrade);
				PossibleGunUpgrades.Remove(PickedUpgrade);
			}
			else
			{
				PickedUpgrade = GetUpgradeBasedOnRarity(PossiblePlayerUpgrades);
				SelectedUpgrades.Add(PickedUpgrade);
				PossiblePlayerUpgrades.Remove(PickedUpgrade);
			}
			break;

			//Get Player Upgrade
		case 1:
			if(PossiblePlayerUpgrades.Num() > 0)
			{
				PickedUpgrade = GetUpgradeBasedOnRarity(PossiblePlayerUpgrades);
				SelectedUpgrades.Add(PickedUpgrade);
				PossiblePlayerUpgrades.Remove(PickedUpgrade);
			}
			else
			{
				PickedUpgrade = GetUpgradeBasedOnRarity(PossibleGunUpgrades);
				SelectedUpgrades.Add(PickedUpgrade);
				PossibleGunUpgrades.Remove(PickedUpgrade);
			}
			break;

			//Get Random Upgrade
		default:
			if(PossiblePlayerUpgrades.Num() > 0 && PossibleGunUpgrades.Num() > 0)
			{
				bool GiveGunUpgrade = FMath::RandBool();

				if(GiveGunUpgrade)
				{
					PickedUpgrade = GetUpgradeBasedOnRarity(PossibleGunUpgrades);
					SelectedUpgrades.Add(PickedUpgrade);
					PossibleGunUpgrades.Remove(PickedUpgrade);
				}

				else
				{
					PickedUpgrade = GetUpgradeBasedOnRarity(PossiblePlayerUpgrades);
					SelectedUpgrades.Add(PickedUpgrade);
					PossiblePlayerUpgrades.Remove(PickedUpgrade);
				}
			}

			else if(PossiblePlayerUpgrades.IsEmpty())
			{
				PickedUpgrade = GetUpgradeBasedOnRarity(PossibleGunUpgrades);
				SelectedUpgrades.Add(PickedUpgrade);
				PossibleGunUpgrades.Remove(PickedUpgrade);
			}

			else if(PossibleGunUpgrades.IsEmpty())
			{
				PickedUpgrade = GetUpgradeBasedOnRarity(PossiblePlayerUpgrades);
				SelectedUpgrades.Add(PickedUpgrade);
				PossiblePlayerUpgrades.Remove(PickedUpgrade);
			}
			break;
		}
	}

	for (auto SelectedUpgrade : SelectedUpgrades)
	{
		if(SelectedUpgrade->GetDefaultObject<UUpgradeBase>()->UpgradeType == EUpgradeType::GunUpgrade)
		{
			PossibleGunUpgrades.Add(SelectedUpgrade);
		}
		else if(SelectedUpgrade->GetDefaultObject<UUpgradeBase>()->UpgradeType == EUpgradeType::PlayerUpgrade)
		{
			PossiblePlayerUpgrades.Add(SelectedUpgrade);
		}
	}

	UGameInstance* GameInstance = Cast<UGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	UUISubsystem* UISubsystem = GameInstance->GetSubsystem<UUISubsystem>();

	UISubsystem->SpawnUpgradeUI(SelectedUpgrades);
}

int UProgressSubsystem::GetNumberOfUpgradesGotten()
{
	return NumberOfUpgradesGotten;
}

void UProgressSubsystem::UpdateSetBonusDataAssets(UGunBaseStats* ShotgunSetData, UGunBaseStats* SniperSetData, UGunBaseStats* RifleSetData, UGunBaseStats* MachinegunSetData)
{
	ShotGunSetInfo.SetBonusData = ShotgunSetData;
	SniperSetInfo.SetBonusData = SniperSetData;
	RifleSetInfo.SetBonusData = RifleSetData;
	MachineGunSetInfo.SetBonusData = MachinegunSetData;
}

void UProgressSubsystem::UnlockSetItem(EWeaponUpgradeType WeaponType, EUpgradeIndex SetUpgradeIndex)
{
	UCombatSubsystem* CombatSubsystem = GetWorld()->GetFirstLocalPlayerFromController()->GetSubsystem<UCombatSubsystem>();
	
	switch (WeaponType)
	{
	case EWeaponUpgradeType::None:
		return;
		break;

	case EWeaponUpgradeType::Rifle:
		RifleSetInfo.UnlockSetItem(SetUpgradeIndex, CombatSubsystem);
		break;

	case EWeaponUpgradeType::Sniper:
		SniperSetInfo.UnlockSetItem(SetUpgradeIndex, CombatSubsystem);
		break;

	case EWeaponUpgradeType::ShotGun:
		ShotGunSetInfo.UnlockSetItem(SetUpgradeIndex, CombatSubsystem);
		break;

	case EWeaponUpgradeType::MachineGun:
		MachineGunSetInfo.UnlockSetItem(SetUpgradeIndex, CombatSubsystem);
		break;

	default:
		return;
	}
}

void UProgressSubsystem::IncrementAmountOfUpgradesGotten()
{
	NumberOfUpgradesGotten++;
}

TSubclassOf<UUpgradeBase> UProgressSubsystem::GetUpgradeBasedOnRarity(TArray<TSubclassOf<UUpgradeBase>> PossibleUpgradeList)
{
	//Get item based on rarity
	float LegendaryWeight = 0;
	float RareWeight = 0;
	float CommonWeight = 0;

	TArray<TSubclassOf<UUpgradeBase>> Legendaries;
	TArray<TSubclassOf<UUpgradeBase>> Rares;
	TArray<TSubclassOf<UUpgradeBase>> Commons;

	for (auto GunUpgrade : PossibleUpgradeList)
	{
		switch (GunUpgrade->GetDefaultObject<UUpgradeBase>()->UpgradeRarity) {
		case EUpgradeRarity::Common:
			CommonWeight += GunUpgrade->GetDefaultObject<UUpgradeBase>()->Weight;
			Commons.Add(GunUpgrade);
			break;
		case EUpgradeRarity::Rare:
			RareWeight += GunUpgrade->GetDefaultObject<UUpgradeBase>()->Weight;
			Rares.Add(GunUpgrade);
			break;
		case EUpgradeRarity::Legendary:
			LegendaryWeight += GunUpgrade->GetDefaultObject<UUpgradeBase>()->Weight;
			Legendaries.Add(GunUpgrade);
			break;
		default: return nullptr;
		}
	}

	float TotalWeight = LegendaryWeight + RareWeight + CommonWeight;

	float LegendarySpan = LegendaryWeight / TotalWeight;
	float RareSpan = RareWeight / TotalWeight;
	float CommonSpan = CommonWeight / TotalWeight;

	float IndexPicker = FMath::RandRange(0.0f, 1.0f);

	if(IndexPicker <= LegendarySpan)
	{
		//Give Legendary

		int ItemPicker = FMath::RandRange(0, Legendaries.Num()-1);

		return Legendaries[ItemPicker];
	}
	else if(IndexPicker > LegendarySpan && IndexPicker <= LegendarySpan + RareSpan)
	{
		//Give Rare

		int ItemPicker = FMath::RandRange(0, Rares.Num()-1);

		return Rares[ItemPicker];	
	}
	else if(IndexPicker > LegendarySpan + RareSpan && IndexPicker <= LegendarySpan + RareSpan + CommonSpan)
	{
		//Give Common

		int ItemPicker = FMath::RandRange(0, Commons.Num()-1);

		return Commons[ItemPicker];		
	}
	else
	{
		return nullptr;
	}
}
