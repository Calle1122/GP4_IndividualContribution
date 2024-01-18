#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EPlatformType : uint8 {
	FirstPlatform = 0						UMETA(DisplayName = "First Platform"),
	SecondPlatform = 1						UMETA(DisplayName = "Second Platform"),
	ThirdPlatform = 2						UMETA(DisplayName = "Third Platform"),
	ForthPlatform = 3						UMETA(DisplayName = "Forth Platform"),
	FifthPlatform = 4						UMETA(DisplayName = "Fifth Platform")
};