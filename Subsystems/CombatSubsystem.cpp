#include "CombatSubsystem.h"

void UCombatSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	WeaponBaselineStruct = FWeaponBaseline();
	WeaponAttributeStruct = FWeaponAttribute();
	WeaponBuffStruct = FWeaponBuff();
}

void UCombatSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

float UCombatSubsystem::GetPlayerDamageOutput(bool WeakpointHit, bool &HitWeakpoint, bool &DidCrit)
{
	float CritPercent = WeaponBaselineStruct.CritChance + WeaponAttributeStruct.CritChance + WeaponBuffStruct.CritChance;
	bool isCrit = (FMath::FRandRange(0.01f, 1) <= CritPercent/100);

	float damageMultiplier = 1;

	if(isCrit)
	{
		damageMultiplier *= (WeaponBaselineStruct.CritDamageMultiplier) + (WeaponAttributeStruct.CritDamageMultiplier) + (WeaponBuffStruct.CritDamageMultiplier);
		DidCrit = true;
	}
	if(WeakpointHit)
	{
		damageMultiplier *= (WeaponBaselineStruct.WeakPointDamageMultiplier) + (WeaponAttributeStruct.WeakPointDamageMultiplier) + (WeaponBuffStruct.WeakPointDamageMultiplier);
		HitWeakpoint = true;
	}

	float baseDamage = WeaponBaselineStruct.BaseDamage + WeaponAttributeStruct.BaseDamage + WeaponBuffStruct.BaseDamage;

	return baseDamage * damageMultiplier;
}

void UCombatSubsystem::UpdateWeaponBaseline(UGunBaseStats* BaseStats)
{
	if(BaseStats == nullptr)
	{
		return;
	}
	
	WeaponBaselineStruct.BaseDamage = BaseStats->BaseDamage;
	WeaponBaselineStruct.BulletSpeed = BaseStats->BulletSpeed;
	WeaponBaselineStruct.ClipSize = BaseStats->ClipSize;
	WeaponBaselineStruct.CritChance = BaseStats->CritChance;
	WeaponBaselineStruct.FireRate = BaseStats->FireRate;
	WeaponBaselineStruct.ReloadTime = BaseStats->ReloadTime;
	WeaponBaselineStruct.BulletLifeTime = BaseStats->BulletLifeTime;
	WeaponBaselineStruct.CritDamageMultiplier = BaseStats->CritDamageMultiplier;
	WeaponBaselineStruct.WeakPointDamageMultiplier = BaseStats->WeakPointDamageMultiplier;
	WeaponBaselineStruct.Accuracy = BaseStats->Accuracy;
	WeaponBaselineStruct.BulletCount = BaseStats->BulletCount;
	WeaponBaselineStruct.BulletRange = BaseStats->BulletRange;

	OnWeaponStatsChanged.Broadcast();
}

void UCombatSubsystem::UpgradeWeaponAttribute(EWeaponAttributeType AttributeType, float Amount)
{
	if(Amount == 0)
	{
		return;
	}
	
	switch (AttributeType)
	{
	case EWeaponAttributeType::BaseDamage:

		if((WeaponBaselineStruct.BaseDamage + (WeaponAttributeStruct.BaseDamage + Amount)) < 3)
		{
			WeaponAttributeStruct.BaseDamage = 0 - (WeaponBaselineStruct.BaseDamage - 3);
		}
		else
		{
			WeaponAttributeStruct.BaseDamage += Amount;
		}
		
		break;

	case EWeaponAttributeType::BulletSpeed:

		if((WeaponBaselineStruct.BulletSpeed + (WeaponAttributeStruct.BulletSpeed + Amount)) < 1000)
		{
			WeaponAttributeStruct.BulletSpeed = 0 - (WeaponBaselineStruct.BulletSpeed - 1000);
		}
		else if((WeaponBaselineStruct.BulletSpeed + (WeaponAttributeStruct.BulletSpeed + Amount)) > 25000)
		{
			WeaponAttributeStruct.BulletSpeed = 25000 - WeaponBaselineStruct.BulletSpeed;
		}
		else
		{
			WeaponAttributeStruct.BulletSpeed += Amount;
		}
		
		break;

	case EWeaponAttributeType::ClipSize:

		if((WeaponBaselineStruct.ClipSize + (WeaponAttributeStruct.ClipSize + Amount)) < 1)
		{
			WeaponAttributeStruct.ClipSize = 0 - (WeaponBaselineStruct.ClipSize - 1);
		}
		else
		{
			WeaponAttributeStruct.ClipSize += Amount;
		}
		
		break;

	case EWeaponAttributeType::CritChance:

		if((WeaponBaselineStruct.CritChance + (WeaponAttributeStruct.CritChance + Amount)) < 0)
		{
			WeaponAttributeStruct.CritChance = 0 - (WeaponBaselineStruct.CritChance - 0);
		}
		else if((WeaponBaselineStruct.CritChance + (WeaponAttributeStruct.CritChance + Amount)) > 100)
		{
			WeaponAttributeStruct.CritChance = 100 - WeaponBaselineStruct.CritChance;
		}
		else
		{
			WeaponAttributeStruct.CritChance += Amount;
		}
		
		break;

	case EWeaponAttributeType::FireRate:

		if((WeaponBaselineStruct.FireRate + (WeaponAttributeStruct.FireRate + Amount)) < .1f)
		{
			WeaponAttributeStruct.FireRate = 0 - (WeaponBaselineStruct.FireRate - .1f);
		}
		else
		{
			WeaponAttributeStruct.FireRate += Amount;
		}
		
		break;

	case EWeaponAttributeType::ReloadTime:

		if((WeaponBaselineStruct.ReloadTime + (WeaponAttributeStruct.ReloadTime + Amount)) < .5f)
		{
			WeaponAttributeStruct.ReloadTime = 0 - (WeaponBaselineStruct.ReloadTime - .5f);
		}
		else
		{
			WeaponAttributeStruct.ReloadTime += Amount;
		}
		
		break;

	case EWeaponAttributeType::BulletLifeTime:

		if((WeaponBaselineStruct.BulletLifeTime + (WeaponAttributeStruct.BulletLifeTime + Amount)) < .5f)
		{
			WeaponAttributeStruct.BulletLifeTime = 0 - (WeaponBaselineStruct.BulletLifeTime - .5f);
		}
		else
		{
			WeaponAttributeStruct.BulletLifeTime += Amount;
		}
		
		break;

	case EWeaponAttributeType::CritDamageMultiplier:

		if((WeaponBaselineStruct.CritDamageMultiplier + (WeaponAttributeStruct.CritDamageMultiplier + Amount)) < 1)
		{
			WeaponAttributeStruct.CritDamageMultiplier = 0 - (WeaponBaselineStruct.CritDamageMultiplier - 1);
		}
		else
		{
			WeaponAttributeStruct.CritDamageMultiplier += Amount;
		}
		
		break;

	case EWeaponAttributeType::WeakPointDamageMultiplier:

		if((WeaponBaselineStruct.WeakPointDamageMultiplier + (WeaponAttributeStruct.WeakPointDamageMultiplier + Amount)) < 1)
		{
			WeaponAttributeStruct.WeakPointDamageMultiplier = 0 - (WeaponBaselineStruct.WeakPointDamageMultiplier - 1);
		}
		else
		{
			WeaponAttributeStruct.WeakPointDamageMultiplier += Amount;
		}
		
		break;

	case EWeaponAttributeType::Accuracy:

		if((WeaponBaselineStruct.Accuracy + (WeaponAttributeStruct.Accuracy + Amount)) < 0)
		{
			WeaponAttributeStruct.Accuracy = 0 - (WeaponBaselineStruct.Accuracy - 0);
		}
		else if((WeaponBaselineStruct.Accuracy + (WeaponAttributeStruct.Accuracy + Amount)) > 100)
		{
			WeaponAttributeStruct.Accuracy = 100 - WeaponBaselineStruct.Accuracy;
		}
		else
		{
			WeaponAttributeStruct.Accuracy += Amount;
		}
		
		break;

	case EWeaponAttributeType::BulletCount:

		if((WeaponBaselineStruct.BulletCount + (WeaponAttributeStruct.BulletCount + Amount)) < 1)
		{
			WeaponAttributeStruct.BulletCount = 0 - (WeaponBaselineStruct.BulletCount - 1);
		}
		else
		{
			WeaponAttributeStruct.BulletCount += Amount;
		}
		
		break;

	case EWeaponAttributeType::BulletRange:

		if((WeaponBaselineStruct.BulletRange + (WeaponAttributeStruct.BulletRange + Amount)) < 300)
		{
			WeaponAttributeStruct.BulletRange = 0 - (WeaponBaselineStruct.BulletRange - 300);
		}
		else if((WeaponBaselineStruct.BulletRange + (WeaponAttributeStruct.BulletRange + Amount)) > 100000)
		{
			WeaponAttributeStruct.BulletRange = 100000 - WeaponBaselineStruct.BulletRange;
		}
		else
		{
			WeaponAttributeStruct.BulletRange += Amount;
		}
		
		break;
	}

	OnWeaponStatsChanged.Broadcast();
}

void UCombatSubsystem::ResetWeaponAttributes()
{
	WeaponAttributeStruct.Accuracy = 0;
	WeaponAttributeStruct.BaseDamage = 0;
	WeaponAttributeStruct.BulletCount = 0;
	WeaponAttributeStruct.BulletRange = 0;
	WeaponAttributeStruct.BulletSpeed = 0;
	WeaponAttributeStruct.ClipSize = 0;
	WeaponAttributeStruct.CritChance = 0;
	WeaponAttributeStruct.FireRate = 0;
	WeaponAttributeStruct.ReloadTime = 0;
	WeaponAttributeStruct.BulletLifeTime = 0;
	WeaponAttributeStruct.CritDamageMultiplier = 0;
	WeaponAttributeStruct.WeakPointDamageMultiplier = 0;
}

FTimerHandle UCombatSubsystem::StartBuffReset(float Delay, EWeaponAttributeType AttributeType, float Amount)
{
	FTimerHandle TimerHandle;
	MyTimerManager->SetTimer(TimerHandle, FTimerDelegate::CreateUObject(this, &UCombatSubsystem::RemoveWeaponBuff, AttributeType, Amount), Delay, false);
	return TimerHandle;
}

void UCombatSubsystem::AddTemporaryWeaponBuff(EWeaponAttributeType AttributeType, float Amount, float Time)
{
	const float Interval = Time;
	const bool Loop = false;
	FTimerHandle UniqueHandle;
	FTimerDelegate RemoveBuffDelegate = FTimerDelegate::CreateUObject( this, &UCombatSubsystem::RemoveWeaponBuff, AttributeType, Amount );
	
	switch (AttributeType)
	{
	case EWeaponAttributeType::BaseDamage:
		
		WeaponBuffStruct.BaseDamage += Amount;
		
		GetWorld()->GetTimerManager().SetTimer( UniqueHandle, RemoveBuffDelegate, Interval, Loop );
		
		break;

	case EWeaponAttributeType::BulletSpeed:
		
		WeaponBuffStruct.BulletSpeed += Amount;

		StartBuffReset(Time, AttributeType, Amount);
		
		break;

	case EWeaponAttributeType::ClipSize:

		WeaponBuffStruct.ClipSize += Amount;

		StartBuffReset(Time, AttributeType, Amount);
		
		break;

	case EWeaponAttributeType::CritChance:

		WeaponBuffStruct.CritChance += Amount;

		StartBuffReset(Time, AttributeType, Amount);
		
		break;

	case EWeaponAttributeType::FireRate:

		WeaponBuffStruct.FireRate += Amount;

		StartBuffReset(Time, AttributeType, Amount);
		
		break;

	case EWeaponAttributeType::ReloadTime:

		WeaponBuffStruct.ReloadTime += Amount;

		StartBuffReset(Time, AttributeType, Amount);
		
		break;

	case EWeaponAttributeType::BulletLifeTime:

		WeaponBuffStruct.BulletLifeTime += Amount;

		StartBuffReset(Time, AttributeType, Amount);
		
		break;

	case EWeaponAttributeType::CritDamageMultiplier:

		WeaponBuffStruct.CritDamageMultiplier += Amount;

		StartBuffReset(Time, AttributeType, Amount);
		
		break;

	case EWeaponAttributeType::WeakPointDamageMultiplier:

		WeaponBuffStruct.WeakPointDamageMultiplier += Amount;

		StartBuffReset(Time, AttributeType, Amount);
		
		break;

	case EWeaponAttributeType::Accuracy:

		WeaponBuffStruct.Accuracy += Amount;

		StartBuffReset(Time, AttributeType, Amount);
		
		break;

	case EWeaponAttributeType::BulletCount:

		WeaponBuffStruct.BulletCount += Amount;

		StartBuffReset(Time, AttributeType, Amount);
		
		break;

	case EWeaponAttributeType::BulletRange:

		WeaponBuffStruct.BulletRange += Amount;

		StartBuffReset(Time, AttributeType, Amount);
		
		break;
	}

	OnWeaponStatsChanged.Broadcast();
}

float UCombatSubsystem::GetWeaponStat(EWeaponAttributeType AttributeType)
{
	switch (AttributeType)
	{
	case EWeaponAttributeType::BaseDamage:

		return WeaponBaselineStruct.BaseDamage + WeaponAttributeStruct.BaseDamage + WeaponBuffStruct.BaseDamage;
		
		break;

	case EWeaponAttributeType::BulletSpeed:

		return WeaponBaselineStruct.BulletSpeed + WeaponAttributeStruct.BulletSpeed + WeaponBuffStruct.BulletSpeed;
		
		break;

	case EWeaponAttributeType::ClipSize:

		return WeaponBaselineStruct.ClipSize + WeaponAttributeStruct.ClipSize + WeaponBuffStruct.ClipSize;
		
		break;

	case EWeaponAttributeType::CritChance:

		return WeaponBaselineStruct.CritChance + WeaponAttributeStruct.CritChance + WeaponBuffStruct.CritChance;
		
		break;

	case EWeaponAttributeType::FireRate:

		return WeaponBaselineStruct.FireRate + WeaponAttributeStruct.FireRate + WeaponBuffStruct.FireRate;
		
		break;

	case EWeaponAttributeType::ReloadTime:

		return WeaponBaselineStruct.ReloadTime + WeaponAttributeStruct.ReloadTime + WeaponBuffStruct.ReloadTime;
		
		break;

	case EWeaponAttributeType::BulletLifeTime:

		return WeaponBaselineStruct.BulletLifeTime + WeaponAttributeStruct.BulletLifeTime + WeaponBuffStruct.BulletLifeTime;
		
		break;

	case EWeaponAttributeType::CritDamageMultiplier:

		return WeaponBaselineStruct.CritDamageMultiplier + WeaponAttributeStruct.CritDamageMultiplier + WeaponBuffStruct.CritDamageMultiplier;
		
		break;

	case EWeaponAttributeType::WeakPointDamageMultiplier:

		return WeaponBaselineStruct.WeakPointDamageMultiplier + WeaponAttributeStruct.WeakPointDamageMultiplier + WeaponBuffStruct.WeakPointDamageMultiplier;
		
		break;

	case EWeaponAttributeType::Accuracy:

		return WeaponBaselineStruct.Accuracy + WeaponAttributeStruct.Accuracy + WeaponBuffStruct.Accuracy;
		
		break;

	case EWeaponAttributeType::BulletCount:

		return WeaponBaselineStruct.BulletCount + WeaponAttributeStruct.BulletCount + WeaponBuffStruct.BulletCount;
		
		break;

	case EWeaponAttributeType::BulletRange:

		return WeaponBaselineStruct.BulletRange + WeaponAttributeStruct.BulletRange + WeaponBuffStruct.BulletRange;
		
		break;

		default: return 0;
	}
}

void UCombatSubsystem::RemoveWeaponBuff(EWeaponAttributeType AttributeType, float Amount)
{
	float StatAlteration = 0;
	
	if(Amount < 0)
	{
		StatAlteration = FMath::Abs(Amount);
	}
	else
	{
		StatAlteration -= Amount;
	}

	switch (AttributeType)
	{
	case EWeaponAttributeType::BaseDamage:

		WeaponBuffStruct.BaseDamage += StatAlteration;
		
		break;

	case EWeaponAttributeType::BulletSpeed:

		WeaponBuffStruct.BulletSpeed += StatAlteration;
		
		break;

	case EWeaponAttributeType::ClipSize:

		WeaponBuffStruct.ClipSize += StatAlteration;
		
		break;

	case EWeaponAttributeType::CritChance:

		WeaponBuffStruct.CritChance += StatAlteration;
		
		break;

	case EWeaponAttributeType::FireRate:

		WeaponBuffStruct.FireRate += StatAlteration;
		
		break;

	case EWeaponAttributeType::ReloadTime:

		WeaponBuffStruct.ReloadTime += StatAlteration;
		
		break;

	case EWeaponAttributeType::BulletLifeTime:

		WeaponBuffStruct.BulletLifeTime += StatAlteration;
		
		break;

	case EWeaponAttributeType::CritDamageMultiplier:

		WeaponBuffStruct.CritDamageMultiplier += StatAlteration;
		
		break;

	case EWeaponAttributeType::WeakPointDamageMultiplier:

		WeaponBuffStruct.WeakPointDamageMultiplier += StatAlteration;
		
		break;

	case EWeaponAttributeType::Accuracy:

		WeaponBuffStruct.Accuracy += StatAlteration;
		
		break;

	case EWeaponAttributeType::BulletCount:

		WeaponBuffStruct.BulletCount += StatAlteration;
		
		break;

	case EWeaponAttributeType::BulletRange:

		WeaponBuffStruct.BulletRange += StatAlteration;
		
		break;
	}
	
	OnWeaponStatsChanged.Broadcast();
}
