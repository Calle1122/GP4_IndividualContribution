#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDamageTaken, float, DamageTaken, bool, HitWeakpoint, bool, DidCrit);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHeal);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthChanged);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnterLowHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnExitLowHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShieldBreak);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnShieldDamaged, float, DamageTaken, bool, HitWeakpoint, bool, DidCrit);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class GP4_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UHealthComponent();

	UPROPERTY(BlueprintReadWrite, Category = "Health Component Variables")
	float MaxHealth;
	UPROPERTY(BlueprintReadWrite, Category = "Health Component Variables",
		meta = (ClampMin = 0.0f, ClampMax = 100.0f),
		meta = (ToolTip = "Threshold in percent used to determine the health state"))
	float LowHealthThreshold = 30.0f;
	
	UPROPERTY(BlueprintReadWrite, Category = "Health Component Variables")
	float MaxShield;
	UPROPERTY(BlueprintReadWrite, Category = "Health Component Variables")
	float ShieldRechargeCooldown;
	UPROPERTY(BlueprintReadWrite, Category = "Health Component Variables")
	float RechargedShieldPerSecond;
	UPROPERTY(BlueprintReadWrite, Category = "Health Component Variables")
	float Defense;

	UPROPERTY(BlueprintReadOnly, Category = "Health Component Variables")
	bool IsInvulnerable;
	UPROPERTY(BlueprintReadOnly, Category = "Health Component Variables")
	float InvulnerabilityTime;
	
	UFUNCTION(BlueprintCallable, Category = "Health Functions")
	void TakeDamage(float dealtDamage, bool hitWeakpoint, bool didCrit);
	UFUNCTION(BlueprintCallable, Category = "Health Functions")
	void DamageCharacter(float DealtDamage, bool HitWeakPoint, bool DidCrit);
	UFUNCTION(BlueprintCallable, Category = "Health Functions")
	void DamageShield(float DealtDamage, bool HitWeakPoint, bool DidCrit);
	UFUNCTION(BlueprintCallable, Category = "Health Functions")
	void Kill();
	UFUNCTION(BlueprintCallable, Category = "Health Functions")
	void Heal(float healAmount);
	UFUNCTION(BlueprintCallable, Category = "Health Functions")
	void MaxHeal();
	UFUNCTION(BlueprintCallable, Category = "Health Functions")
	void RestoreAllShield();
	UFUNCTION(BlueprintCallable, Category = "Health Functions")
	float GetCurrentHealth();
	UFUNCTION(BlueprintCallable, Category = "Health Functions")
	void SetMaxHealth(float newMaxHealth);
	
	UFUNCTION(BlueprintCallable, Category = "Health Functions")
	void GetCurrentShieldInfo(float &CurrentShieldValue, float &TimeUntilShieldRechargeBegins);
	UFUNCTION(BlueprintCallable, Category = "Health Functions")
	void ApplyShieldRechargeCooldown();
	
	UFUNCTION(BlueprintCallable, Category = "Health Functions")
	void MergeInvulnerabilityTime(float TimeLeft);
	
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "OnDeath"), Category = "Health Events")
	FOnDeath OnDeath;
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "OnDamageTaken"), Category = "Health Events")
	FOnDamageTaken OnDamageTaken;
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "OnHeal"), Category = "Health Events")
	FOnHeal OnHeal;
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "OnHealthChanged"), Category = "Health Events")
	FOnHealthChanged OnHealthChanged;
	
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "OnEnterLowHealth"), Category = "Health Events")
	FOnEnterLowHealth OnEnterLowHealth;
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "OnExitLowHealth"), Category = "Health Events")
	FOnExitLowHealth OnExitLowHealth;
	
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "OnShieldBreak"), Category = "Health Events")
	FOnShieldBreak OnShieldBreak;
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "OnShieldDamaged"), Category = "Health Events")
	FOnShieldDamaged OnShieldDamaged;
	
protected:
	
	float CurrentHealth;
	
	float CurrentShield;
	float CurrentShieldRechargeCooldown;
	bool ShouldRechargeShield = true;

	bool IsLowHealth;
	
	virtual void BeginPlay() override;

	void KillOwner();

	void SetHealth(float NewHealth);
	void SetHealthClamped(float NewHealth);
	void HealthChanged();

public:
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
