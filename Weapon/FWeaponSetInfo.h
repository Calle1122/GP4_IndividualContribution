#pragma once

#include "CoreMinimal.h"
#include "FWeaponSetInfo.generated.h"

class UCombatSubsystem;
enum class EUpgradeIndex : uint8;
class UGunBaseStats;

USTRUCT(BlueprintType)
struct FWeaponSetInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Set Info")
	TObjectPtr<UGunBaseStats> SetBonusData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Set Info")
	int NumberOfWeaponsAcquired = 0;
	
	bool HasI = false;
	bool HasII = false;
	bool HasIII = false;
	bool HasIV = false;
	bool HasV = false;

	void UnlockSetItem(EUpgradeIndex UpgradeIndex, UCombatSubsystem* CombatSubsystem);
	void ActivateSetBonus(UCombatSubsystem* CombatSubsystem);
};
