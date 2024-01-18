#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EPlayerAttributeType : uint8 {
	MaxHealth = 0					UMETA(DisplayName = "Max Health"),
	Shield = 1						UMETA(DisplayName = "Shield"),
	Defense = 2						UMETA(DisplayName = "Defense"),
	MoveSpeed = 3					UMETA(DisplayName = "Move Speed"),
	JumpForce = 4					UMETA(DisplayName = "Jump Force"),
	JumpCount = 5					UMETA(DisplayName = "Jump Count"),
	DashCount = 6					UMETA(DisplayName = "Dash Count"),
	DashDistance = 7				UMETA(DisplayName = "Dash Distance"),
	DashDuration = 8				UMETA(DisplayName = "Dash Duration"),
	DashCooldown = 9				UMETA(DisplayName = "Dash Cooldown")
};