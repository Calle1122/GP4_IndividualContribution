#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EStageType : uint8 {
	Denial = 0						UMETA(DisplayName = "Denial"),
	Anger = 1						UMETA(DisplayName = "Anger"),
	Bargain = 2						UMETA(DisplayName = "Bargain"),
	Depression = 3					UMETA(DisplayName = "Depression"),
	Acceptance = 4					UMETA(DisplayName = "Acceptance")
};