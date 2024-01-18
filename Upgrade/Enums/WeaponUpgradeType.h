#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EWeaponUpgradeType : uint8 {
	ShotGun = 0								UMETA(DisplayName = "Shot Gun"),
	Rifle = 1								UMETA(DisplayName = "Rifle"),
	MachineGun = 2							UMETA(DisplayName = "Machine Gun"),
	Sniper = 3								UMETA(DisplayName = "Sniper"),
	None = 4								UMETA(DisplayName = "None")
};