#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GP4/Upgrade/Enums/UpgradeFieldColor.h"
#include "SetBonusUIData.generated.h"

UCLASS()
class GP4_API USetBonusUIData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Rifle UI Info")
	EUpgradeFieldColor Row1Color;
	
	UPROPERTY(EditAnywhere, Category="Rifle UI Info")
	FText Row1Name;
	UPROPERTY(EditAnywhere, Category="Rifle UI Info")
	FText Row1Value;

	UPROPERTY(EditAnywhere, Category="Rifle UI Info")
	EUpgradeFieldColor Row2Color;
	
	UPROPERTY(EditAnywhere, Category="Rifle UI Info")
	FText Row2Name;
	UPROPERTY(EditAnywhere, Category="Rifle UI Info")
	FText Row2Value;

	UPROPERTY(EditAnywhere, Category="Rifle UI Info")
	EUpgradeFieldColor Row3Color;
	
	UPROPERTY(EditAnywhere, Category="Rifle UI Info")
	FText Row3Name;
	UPROPERTY(EditAnywhere, Category="Rifle UI Info")
	FText Row3Value;
	
};
