#include "FWeaponSetInfo.h"

#include "GP4/Subsystems/CombatSubsystem.h"
#include "GP4/Upgrade/Enums/UpgradeIndex.h"

void FWeaponSetInfo::UnlockSetItem(EUpgradeIndex UpgradeIndex, UCombatSubsystem* CombatSubsystem)
{
	if(NumberOfWeaponsAcquired == 5)
	{
		return;
	}
	
	switch (UpgradeIndex)
	{
	case EUpgradeIndex::I:
		
		if(HasI)
		{
			return;
		}

		HasI = true;
		NumberOfWeaponsAcquired++;
		
		break;

	case EUpgradeIndex::II:

		if(HasII)
		{
			return;
		}

		HasII = true;
		NumberOfWeaponsAcquired++;
		
		break;

	case EUpgradeIndex::III:

		if(HasIII)
		{
			return;
		}

		HasIII = true;
		NumberOfWeaponsAcquired++;
		
		break;

	case EUpgradeIndex::IV:

		if(HasIV)
		{
			return;
		}

		HasIV = true;
		NumberOfWeaponsAcquired++;
		
		break;

	case EUpgradeIndex::V:

		if(HasV)
		{
			return;
		}

		HasV = true;
		NumberOfWeaponsAcquired++;
		
		break;
	}

	if(NumberOfWeaponsAcquired == 5)
	{
		ActivateSetBonus(CombatSubsystem);
	}
}

void FWeaponSetInfo::ActivateSetBonus(UCombatSubsystem* CombatSubsystem)
{
	if(!IsValid(SetBonusData))
	{
		return;
	}
	
	CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::BulletCount, SetBonusData->BulletCount);
	CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::Accuracy, SetBonusData->Accuracy);
	CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::BaseDamage, SetBonusData->BaseDamage);
	CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::BulletRange, SetBonusData->BulletRange);
	CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::BulletSpeed, SetBonusData->BulletSpeed);
	CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::BulletLifeTime, SetBonusData->BulletLifeTime);
	CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::ClipSize, SetBonusData->ClipSize);
	CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::CritChance, SetBonusData->CritChance);
	CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::FireRate, SetBonusData->FireRate);
	CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::ReloadTime, SetBonusData->ReloadTime);
	CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::CritDamageMultiplier, SetBonusData->CritDamageMultiplier);
	CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::WeakPointDamageMultiplier, SetBonusData->WeakPointDamageMultiplier);
}
