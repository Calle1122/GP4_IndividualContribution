#include "UpgradeBase.h"
#include "GP4/Subsystems/ProgressSubsystem.h"
#include "GP4/Weapons/WeaponAttributeType.h"

void UUpgradeBase::RegisterPowerUp(UCombatSubsystem* Combat, UPlayerSubsystem* Player, UEnemySubsystem* Enemy, UProgressSubsystem* Progress)
{
	CombatSubsystem = Combat;
	PlayerSubsystem = Player;
	EnemySubsystem = Enemy;

	if(IsValid(WeaponUpgradeData))
	{
		CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::BulletCount, WeaponUpgradeData->BulletCount);
		CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::Accuracy, WeaponUpgradeData->Accuracy);
		CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::BaseDamage, WeaponUpgradeData->BaseDamage);
		CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::BulletRange, WeaponUpgradeData->BulletRange);
		CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::BulletSpeed, WeaponUpgradeData->BulletSpeed);
		CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::BulletLifeTime, WeaponUpgradeData->BulletLifeTime);
		CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::ClipSize, WeaponUpgradeData->ClipSize);
		CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::CritChance, WeaponUpgradeData->CritChance);
		CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::FireRate, WeaponUpgradeData->FireRate);
		CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::ReloadTime, WeaponUpgradeData->ReloadTime);
		CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::CritDamageMultiplier, WeaponUpgradeData->CritDamageMultiplier);
		CombatSubsystem->UpgradeWeaponAttribute(EWeaponAttributeType::WeakPointDamageMultiplier, WeaponUpgradeData->WeakPointDamageMultiplier);
	}
	
	if(IsValid(PlayerUpgradeData))
	{
		PlayerSubsystem->UpgradePlayerAttribute(EPlayerAttributeType::Defense, PlayerUpgradeData->Defense);
		PlayerSubsystem->UpgradePlayerAttribute(EPlayerAttributeType::Shield, PlayerUpgradeData->Shield);
		PlayerSubsystem->UpgradePlayerAttribute(EPlayerAttributeType::DashCooldown, PlayerUpgradeData->DashCooldown);
		PlayerSubsystem->UpgradePlayerAttribute(EPlayerAttributeType::DashCount, PlayerUpgradeData->DashCount);
		PlayerSubsystem->UpgradePlayerAttribute(EPlayerAttributeType::DashDistance, PlayerUpgradeData->DashDistance);
		PlayerSubsystem->UpgradePlayerAttribute(EPlayerAttributeType::DashDuration, PlayerUpgradeData->DashDuration);
		PlayerSubsystem->UpgradePlayerAttribute(EPlayerAttributeType::JumpCount, PlayerUpgradeData->JumpCount);
		PlayerSubsystem->UpgradePlayerAttribute(EPlayerAttributeType::JumpForce, PlayerUpgradeData->JumpForce);
		PlayerSubsystem->UpgradePlayerAttribute(EPlayerAttributeType::MaxHealth, PlayerUpgradeData->MaxHealth);
		PlayerSubsystem->UpgradePlayerAttribute(EPlayerAttributeType::MoveSpeed, PlayerUpgradeData->MoveSpeed);
	}

	Progress->UnlockSetItem(WeaponType, UpgradeIndex);
	Progress->IncrementAmountOfUpgradesGotten();
	
}
