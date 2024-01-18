#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EUpgradeIndex : uint8 {
	I = 0								UMETA(DisplayName = "I"),
	II = 1								UMETA(DisplayName = "II"),
	III = 2								UMETA(DisplayName = "III"),
	IV = 3								UMETA(DisplayName = "IV"),
	V = 4								UMETA(DisplayName = "V")
};