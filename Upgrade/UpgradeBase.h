#pragma once

#include "CoreMinimal.h"
#include "Enums/UpgradeIndex.h"
#include "Enums/UpgradeRarity.h"
#include "Enums/UpgradeType.h"
#include "Enums/WeaponUpgradeType.h"
#include "GP4/Subsystems/CombatSubsystem.h"
#include "GP4/Subsystems/EnemySubsystem.h"
#include "GP4/Subsystems/PlayerSubsystem.h"
#include "UObject/Object.h"
#include "UpgradeBase.generated.h"

class UProgressSubsystem;

UCLASS(Blueprintable, BlueprintType)
class GP4_API UUpgradeBase : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Upgrade Item Variables")
	bool ShouldEnableAutoFire;

	//Rarity Weight
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Upgrade Item Variables")
	int Weight;
	
	//UI Related
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Upgrade Item Variables")
	UTexture2D* UpgradeIcon;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Upgrade Item Variables")
	EUpgradeType UpgradeType;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Upgrade Item Variables")
	EWeaponUpgradeType WeaponType;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Upgrade Item Variables")
	EUpgradeIndex UpgradeIndex;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Upgrade Item Variables")
	EUpgradeRarity UpgradeRarity;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Upgrade Item Variables")
	FText UpgradeName;
	
	//Subsystem References
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Upgrade Base Variables")
	UCombatSubsystem* CombatSubsystem;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Upgrade Base Variables")
	UPlayerSubsystem* PlayerSubsystem;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Upgrade Base Variables")
	UEnemySubsystem* EnemySubsystem;

	//Upgrade Data
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Upgrade Data Variables")
	TObjectPtr<UGunBaseStats> WeaponUpgradeData;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Upgrade Data Variables")
	TObjectPtr<UPlayerBaseStats> PlayerUpgradeData;

	//Functions
	UFUNCTION(BlueprintCallable, Category = "Powerup Events")
	void RegisterPowerUp(UCombatSubsystem* Combat, UPlayerSubsystem* Player, UEnemySubsystem* Enemy, UProgressSubsystem* Progress);
};
