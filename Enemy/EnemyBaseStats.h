#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnemyBaseStats.generated.h"

UCLASS()
class GP4_API UEnemyBaseStats : public UDataAsset
{
	GENERATED_BODY()

public:
	//Health
	UPROPERTY(EditAnywhere, Category = "Health")
	float MaxHealth;

	//Movement
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float JumpForce;

	//Defense
	UPROPERTY(EditAnywhere, Category = "Defense")
	float Defense;

	//Damage
	UPROPERTY(EditAnywhere, Category = "Damage")
	float BaseDamage;
};
