#pragma once

#include "CoreMinimal.h"
#include "EnemyBaseline.generated.h"

USTRUCT(BlueprintType)
struct FEnemyBaseline
{
	GENERATED_BODY()

	FEnemyBaseline();
	~FEnemyBaseline();

	//Health
	UPROPERTY(EditAnywhere, Category = "Health")
	float MaxHealth = 0;

	//Movement
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 0;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float JumpForce = 0;

	//Defense
	UPROPERTY(EditAnywhere, Category = "Defense")
	float Defense = 0;

	//Damage
	UPROPERTY(EditAnywhere, Category = "Damage")
	float BaseDamage = 0;
};

