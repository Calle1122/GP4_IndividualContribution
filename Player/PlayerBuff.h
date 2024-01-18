#pragma once

#include "CoreMinimal.h"
#include "PlayerBuff.generated.h"

USTRUCT(BlueprintType)
struct FPlayerBuff
{
	GENERATED_BODY()

	FPlayerBuff();
	~FPlayerBuff();

	//Health
	UPROPERTY(EditAnywhere, Category = "Health")
	float MaxHealth = 0;

	//Defense
	UPROPERTY(EditAnywhere, Category = "Defense")
	float Shield = 0;
	UPROPERTY(EditAnywhere, Category = "Defense")
	float Defense = 0;

	//Movement
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 0;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float JumpForce = 0;
	UPROPERTY(EditAnywhere, Category = "Movement")
	int JumpCount = 0;

	//Dash
	UPROPERTY(EditAnywhere, Category = "Dash")
	int DashCount = 0;
	UPROPERTY(EditAnywhere, Category = "Dash")
	float DashDistance = 0;
	UPROPERTY(EditAnywhere, Category = "Dash")
	float DashDuration = 0;
	UPROPERTY(EditAnywhere, Category = "Dash")
	float DashCooldown = 0;
};

