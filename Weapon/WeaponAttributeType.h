#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EWeaponAttributeType : uint8 {
	ClipSize = 0					UMETA(DisplayName = "Clip Size"),
	ReloadTime = 1					UMETA(DisplayName = "Reload Time"),
	WeakPointDamageMultiplier = 2	UMETA(DisplayName = "Weak Point Damage Multiplier"),
	FireRate = 3					UMETA(DisplayName = "Fire Rate"),
	BulletSpeed = 4					UMETA(DisplayName = "Bullet Speed"),
	BulletLifeTime = 5				UMETA(DisplayName = "Bullet Life Time"),
	BaseDamage = 6					UMETA(DisplayName = "Base Damage"),
	CritChance = 7					UMETA(DisplayName = "Crit Chance"),
	CritDamageMultiplier = 8		UMETA(DisplayName = "Crit Damage Multiplier"),
	Accuracy = 9					UMETA(DisplayName = "Accuracy"),
	BulletCount = 10				UMETA(DisplayName = "BulletCount"),
	BulletRange = 11				UMETA(DisplayName = "BulletRange")
};