#pragma once

#include "CoreMinimal.h"
#include "WeaponBaseline.generated.h"

USTRUCT(BlueprintType)
struct FWeaponBaseline
{
	GENERATED_BODY()

	FWeaponBaseline();
	~FWeaponBaseline();
	
	//Accuracy / Spray
	UPROPERTY(EditAnywhere, Category="Accuracy")
	float Accuracy = 0;
	
	//Ammo
	UPROPERTY(EditAnywhere, Category="Ammo")
	int ClipSize = 0;
	UPROPERTY(EditAnywhere, Category="Ammo")
	float ReloadTime = 0;

	//Shooting
	UPROPERTY(EditAnywhere, Category="Shooting")
	float FireRate = 0;

	//Bullet
	UPROPERTY(EditAnywhere, Category="Bullet")
	int BulletCount = 0;
	UPROPERTY(EditAnywhere, Category="Bullet")
	float BulletSpeed = 0;
	UPROPERTY(EditAnywhere, Category="Bullet")
	float BulletLifeTime = 0;
	UPROPERTY(EditAnywhere, Category="Bullet")
	float BulletRange = 0;

	//Damage
	UPROPERTY(EditAnywhere, Category="Damage")
	float BaseDamage = 0;

	//Crit
	UPROPERTY(EditAnywhere, Category="Crit")
	float CritChance = 0;
	UPROPERTY(EditAnywhere, Category="Crit")
	float CritDamageMultiplier = 0;

	//Weak Point
	UPROPERTY(EditAnywhere, Category="Weak Point")
	float WeakPointDamageMultiplier = 0;
};
