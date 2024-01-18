#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EUpgradeFieldColor : uint8 {
	Green = 0						UMETA(DisplayName = "Green"),
	Red = 1							UMETA(DisplayName = "Red"),
	White = 2						UMETA(DisplayName = "White")
};