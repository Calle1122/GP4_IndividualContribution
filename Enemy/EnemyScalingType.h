#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EEnemyScalingType : uint8 {
	MaxHealth = 0					UMETA(DisplayName = "Max Health"),
	Defense = 1						UMETA(DisplayName = "Defense"),
	MoveSpeed = 2					UMETA(DisplayName = "Move Speed"),
	JumpForce = 3					UMETA(DisplayName = "Jump Force"),
	BaseDamage = 4					UMETA(DisplayName = "Base Damage")
};