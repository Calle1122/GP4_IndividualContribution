#pragma once

#include "CoreMinimal.h"
#include "Enums/PlatformType.h"
#include "Enums/StageType.h"
#include "GP4/Upgrade/UpgradeBase.h"
#include "GP4/Weapons/Structs/FWeaponSetInfo.h"
#include "ProgressSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStageCleared, EStageType, ClearedStage);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnProgressIncrease);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNewStageReached);

UCLASS(BlueprintType)
class GP4_API UProgressSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	//Variables
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TSubclassOf<UUpgradeBase>> PossibleGunUpgrades;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TSubclassOf<UUpgradeBase>> PossiblePlayerUpgrades;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	EStageType CurrentStage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FWeaponSetInfo ShotGunSetInfo;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FWeaponSetInfo RifleSetInfo;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FWeaponSetInfo MachineGunSetInfo;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FWeaponSetInfo SniperSetInfo;
	
	//Delegates
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "OnStageCleared"), Category="Progress Subsystem Events")
	FOnStageCleared OnStageCleared;
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "OnProgressIncrease"), Category="Progress Subsystem Events")
	FOnProgressIncrease OnProgressIncrease;
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "OnNewStageReached"), Category="Progress Subsystem Events")
	FOnNewStageReached OnNewStageReached;
	
	//Functions
	UFUNCTION(BlueprintCallable, Category = "Progress Subsystem Functions")
	float GetCurrentGameProgressPercent();
	UFUNCTION(BlueprintCallable, Category = "Progress Subsystem Functions")
	void IncreaseStageProgressPercent(float Amount);
	UFUNCTION(BlueprintCallable, Category = "Progress Subsystem Functions")
	void SetCurrentStage(EStageType NewStage);
	UFUNCTION(BlueprintCallable, Category = "Progress Subsystem Functions")
	void NewStageReached();

	UFUNCTION(BlueprintCallable, Category = "Progress Subsystem Functions")
	void AddUpgradesToPossiblePool(EUpgradeType UpgradeType, TArray<TSubclassOf<UUpgradeBase>> UpgradesToAdd);
	UFUNCTION(BlueprintCallable, Category = "Progress Subsystem Functions")
	void GetNewUpgrade();
	UFUNCTION(BlueprintCallable, Category = "Progress Subsystem Functions")
	int GetNumberOfUpgradesGotten();

	UFUNCTION(BlueprintCallable, Category = "Progress Subsystem Functions")
	void UpdateSetBonusDataAssets(UGunBaseStats* ShotgunSetData, UGunBaseStats* SniperSetData, UGunBaseStats* RifleSetData, UGunBaseStats* MachinegunSetData);

	void UnlockSetItem(EWeaponUpgradeType WeaponType, EUpgradeIndex SetUpgradeIndex);
	void IncrementAmountOfUpgradesGotten();

protected:
	int NumberOfUpgradesGotten;
	float CurrentGameProgress;

	TSubclassOf<UUpgradeBase> GetUpgradeBasedOnRarity(TArray<TSubclassOf<UUpgradeBase>> PossibleUpgradeList);
};
