// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GunBaseStats.generated.h"

/**
 * 
 */
UCLASS()
class GP4_API UGunBaseStats : public UDataAsset
{
	GENERATED_BODY()

public:
	//Accuracy / Spray
	UPROPERTY(EditAnywhere, Category="Accuracy")
	float Accuracy;
	
	//Ammo
	UPROPERTY(EditAnywhere, Category="Ammo")
	int ClipSize;
	UPROPERTY(EditAnywhere, Category="Ammo")
	float ReloadTime;

	//Shooting
	UPROPERTY(EditAnywhere, Category="Shooting")
	float FireRate;

	//Bullet
	UPROPERTY(EditAnywhere, Category="Bullet")
	int BulletCount;
	UPROPERTY(EditAnywhere, Category="Bullet")
	float BulletSpeed;
	UPROPERTY(EditAnywhere, Category="Bullet")
	float BulletLifeTime;
	UPROPERTY(EditAnywhere, Category="Bullet")
	float BulletRange;

	//Damage
	UPROPERTY(EditAnywhere, Category="Damage")
	float BaseDamage;

	//Crit
	UPROPERTY(EditAnywhere, Category="Crit")
	float CritChance;
	UPROPERTY(EditAnywhere, Category="Crit")
	float CritDamageMultiplier;

	//Weak Point
	UPROPERTY(EditAnywhere, Category="Weak Point")
	float WeakPointDamageMultiplier;
};
