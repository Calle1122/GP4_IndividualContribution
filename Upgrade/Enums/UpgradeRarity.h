#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EUpgradeRarity : uint8 {
	Common = 0							UMETA(DisplayName = "Common Upgrade"),
	Rare = 1						UMETA(DisplayName = "Rare Upgrade"),
	Legendary = 2						UMETA(DisplayName = "Legendary Upgrade")
};