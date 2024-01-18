#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseStats.h"
#include "GameFramework/Character.h"
#include "GP4/Upgrade/DataAssets/PossibleGunUpgrades.h"
#include "GP4/Upgrade/DataAssets/PossiblePlayerUpgrades.h"
#include "PlayerBase.generated.h"

UCLASS()
class GP4_API APlayerBase : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	TObjectPtr<UPlayerBaseStats> PlayerBaseData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Upgrade Data")
	TObjectPtr<UPossibleGunUpgrades> PossibleGunUpgradesData;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Upgrade Data")
	TObjectPtr<UPossiblePlayerUpgrades> PossiblePlayerUpgradesData;
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
