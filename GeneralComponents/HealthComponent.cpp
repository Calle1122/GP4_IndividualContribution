#include "HealthComponent.h"
#include "GameFramework/Actor.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UHealthComponent::TakeDamage(float dealtDamage, bool hitWeakpoint, bool didCrit)
{
	if (IsInvulnerable || dealtDamage <= 0 || CurrentHealth <= 0)
	{
		return;
	}

	if (CurrentShield > 0)
	{
		DamageShield(dealtDamage, hitWeakpoint, didCrit);
	}
	else
	{
		DamageCharacter(dealtDamage, hitWeakpoint, didCrit);
	}
}

void UHealthComponent::DamageCharacter(float DealtDamage, bool HitWeakPoint, bool DidCrit)
{
	SetHealthClamped(CurrentHealth - DealtDamage * ((100 + Defense) / (100 + Defense * 10)));

	OnDamageTaken.Broadcast(DealtDamage, HitWeakPoint, DidCrit);
	
	if (CurrentHealth == 0)
	{
		KillOwner();
	}
}

void UHealthComponent::DamageShield(float DealtDamage, bool HitWeakPoint, bool DidCrit)
{
	CurrentShield = FMath::Max(0, CurrentShield - DealtDamage);

	OnShieldDamaged.Broadcast(DealtDamage, HitWeakPoint, DidCrit);

	if (CurrentShield == 0)
	{
		OnShieldBreak.Broadcast();
	}
}


void UHealthComponent::Kill()
{
	if (CurrentHealth <= 0)
	{
		return;
	}
	
	const float RemainingHealth = CurrentHealth;
	SetHealth(0);
	
	OnDamageTaken.Broadcast(RemainingHealth, false, false);
	KillOwner();
}

void UHealthComponent::Heal(float healAmount)
{
	if (CurrentHealth == MaxHealth)
	{
		return;
	}

	SetHealthClamped(CurrentHealth + healAmount);

	OnHeal.Broadcast();
}

void UHealthComponent::MaxHeal()
{
	if (CurrentHealth == MaxHealth)
	{
		return;
	}

	OnHeal.Broadcast();

	SetHealth(MaxHealth);
}

void UHealthComponent::RestoreAllShield()
{
	CurrentShield = MaxShield;
}

float UHealthComponent::GetCurrentHealth()
{
	return CurrentHealth;
}

void UHealthComponent::SetMaxHealth(float newMaxHealth)
{
	int PreviousMaxHealth = MaxHealth;

	MaxHealth = newMaxHealth;

	if (MaxHealth > PreviousMaxHealth)
	{
		Heal(MaxHealth - PreviousMaxHealth);
	}
	else
	{
		HealthChanged();
	}
}

void UHealthComponent::GetCurrentShieldInfo(float& CurrentShieldValue, float& TimeUntilShieldRechargeBegins)
{
	CurrentShieldValue = CurrentShield;
	TimeUntilShieldRechargeBegins = CurrentShieldRechargeCooldown;
}

void UHealthComponent::ApplyShieldRechargeCooldown()
{
	ShouldRechargeShield = false;
	CurrentShieldRechargeCooldown = ShieldRechargeCooldown;
}

void UHealthComponent::MergeInvulnerabilityTime(float TimeLeft)
{
	if (TimeLeft < InvulnerabilityTime)
	{
		return;
	}
	
	InvulnerabilityTime = TimeLeft;
	
	if (!IsInvulnerable)
	{
		IsInvulnerable = true;
	}
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	SetHealth(MaxHealth);
	CurrentShield = MaxShield;
}

void UHealthComponent::KillOwner()
{
	OnDeath.Broadcast();
}

void UHealthComponent::SetHealth(float NewHealth)
{
	if (NewHealth == CurrentHealth)
	{
		return;
	}
	
	CurrentHealth = NewHealth;
	HealthChanged();
}

void UHealthComponent::SetHealthClamped(float NewHealth)
{
	const float ClampedHealth = FMath::Clamp(NewHealth, 0.0f, MaxHealth);
	SetHealth(ClampedHealth);
}

void UHealthComponent::HealthChanged()
{
	if (IsLowHealth)
	{
		if (CurrentHealth / MaxHealth > LowHealthThreshold / 100.0f)
		{
			IsLowHealth = false;
			OnExitLowHealth.Broadcast();
		}
	}
	else
	{
		if (CurrentHealth / MaxHealth <= LowHealthThreshold / 100.0f)
		{
			IsLowHealth = true;
			OnEnterLowHealth.Broadcast();
		}
	}
	
	OnHealthChanged.Broadcast();
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Shield recharge timer
	if (CurrentShieldRechargeCooldown > 0)
	{
		CurrentShieldRechargeCooldown = FMath::Max(0, CurrentShieldRechargeCooldown - DeltaTime);

		if (CurrentShieldRechargeCooldown == 0)
		{
			ShouldRechargeShield = true;
		}
	}

	// Shield recharge
	if (ShouldRechargeShield)
	{
		CurrentShield = FMath::Min(MaxShield, CurrentShield + (RechargedShieldPerSecond * DeltaTime));
	}

	// Invulnerability
	if (IsInvulnerable)
	{
		InvulnerabilityTime -= DeltaTime;
		if (InvulnerabilityTime <= 0.0f)
		{
			InvulnerabilityTime = 0.0f;
			IsInvulnerable = false;
		}
	}
}

