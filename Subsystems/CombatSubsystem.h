#pragma once

#include "CoreMinimal.h"
#include "GP4/Weapons/GunBaseStats.h"
#include "GP4/Weapons/WeaponAttribute.h"
#include "GP4/Weapons/WeaponAttributeType.h"
#include "GP4/Weapons/WeaponBaseline.h"
#include "GP4/Weapons/WeaponBuff.h"
#include "CombatSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWeaponStatsChanged);

UCLASS(BlueprintType)
class GP4_API UCombatSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	//Structs
	FWeaponBaseline WeaponBaselineStruct;
	FWeaponAttribute WeaponAttributeStruct;
	FWeaponBuff WeaponBuffStruct;

	//Delegates
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "OnWeaponStatsChanged"), Category="Combat Subsystem Events")
	FOnWeaponStatsChanged OnWeaponStatsChanged;
	
	//Functions
	UFUNCTION(BlueprintCallable, Category = "Combat Subsystem Functions")
	float GetPlayerDamageOutput(bool WeakpointHit, bool &HitWeakpoint, bool &DidCrit);

	UFUNCTION(BlueprintCallable, Category = "Combat Subsystem Functions")
	void UpdateWeaponBaseline(UGunBaseStats* BaseStats);

	UFUNCTION(BlueprintCallable, Category = "Combat Subsystem Functions")
	void UpgradeWeaponAttribute(EWeaponAttributeType AttributeType, float Amount);

	UFUNCTION(BlueprintCallable, Category = "Combat Subsystem Functions")
	void ResetWeaponAttributes();

	UFUNCTION(BlueprintCallable, Category = "Combat Subsystem Functions")
	void AddTemporaryWeaponBuff(EWeaponAttributeType AttributeType, float Amount, float Time);
	
	UFUNCTION(BlueprintCallable, Category = "Combat Subsystem Functions")
	float GetWeaponStat(EWeaponAttributeType AttributeType);

protected:
	void RemoveWeaponBuff(EWeaponAttributeType AttributeType, float Amount);

	FTimerManager* MyTimerManager;

	FTimerHandle StartBuffReset(float Delay, EWeaponAttributeType AttributeType, float Amount);
};
