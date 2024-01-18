#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EUpgradeType : uint8 {
	GunUpgrade = 0							UMETA(DisplayName = "Gun Upgrade"),
	PlayerUpgrade = 1						UMETA(DisplayName = "Player Upgrade")
};