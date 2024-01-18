#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GP4/Upgrade/UpgradeBase.h"
#include "PossibleGunUpgrades.generated.h"

UCLASS()
class GP4_API UPossibleGunUpgrades : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gun Upgrade Variables")
	TArray<TSubclassOf<UUpgradeBase>> PossibleGunUpgrades;
};
