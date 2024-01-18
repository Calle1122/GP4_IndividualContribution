#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlayerBaseStats.generated.h"

UCLASS()
class GP4_API UPlayerBaseStats : public UDataAsset
{
	GENERATED_BODY()

public:
	//Health
	UPROPERTY(EditAnywhere, Category = "Health")
	float MaxHealth;

	//Defense
	UPROPERTY(EditAnywhere, Category = "Defense")
	float Shield;
	UPROPERTY(EditAnywhere, Category = "Defense")
	float Defense;

	//Movement
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float JumpForce;
	UPROPERTY(EditAnywhere, Category = "Movement")
	int JumpCount;

	//Dash
	UPROPERTY(EditAnywhere, Category = "Dash")
	int DashCount;
	UPROPERTY(EditAnywhere, Category = "Dash")
	float DashDistance;
	UPROPERTY(EditAnywhere, Category = "Dash")
	float DashDuration;
	UPROPERTY(EditAnywhere, Category = "Dash")
	float DashCooldown;
	
};
