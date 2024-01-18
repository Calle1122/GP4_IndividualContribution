#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GP4/Upgrade/UpgradeBase.h"
#include "PossiblePlayerUpgrades.generated.h"

UCLASS()
class GP4_API UPossiblePlayerUpgrades : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Upgrade Variables")
	TArray<TSubclassOf<UUpgradeBase>> PossiblePlayerUpgrades;
};
