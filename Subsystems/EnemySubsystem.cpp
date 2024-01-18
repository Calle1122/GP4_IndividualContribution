#include "EnemySubsystem.h"

void UEnemySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	MeleeEnemyStageScalingStruct = FEnemyBaseline();
	MeleeEnemyTimeScalingStruct = FEnemyBaseline();
	MeleeEnemyEliteScalingStruct = FEnemyBaseline();

	RangedEnemyStageScalingStruct = FEnemyBaseline();
	RangedEnemyTimeScalingStruct = FEnemyBaseline();
	RangedEnemyEliteScalingStruct = FEnemyBaseline();
}

void UEnemySubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UEnemySubsystem::UpgradeEnemyStageScaling(UEnemyBaseStats* AdditiveStageValues, EEnemyTypes EnemyType)
{
	switch (EnemyType)
	{
	case EEnemyTypes::None:
		return;
		break;
	case EEnemyTypes::MeleeEnemy:
		MeleeEnemyStageScalingStruct.Defense += AdditiveStageValues->Defense;
		MeleeEnemyStageScalingStruct.BaseDamage += AdditiveStageValues->BaseDamage;
		MeleeEnemyStageScalingStruct.JumpForce += AdditiveStageValues->JumpForce;
		MeleeEnemyStageScalingStruct.MaxHealth += AdditiveStageValues->MaxHealth;
		MeleeEnemyStageScalingStruct.MoveSpeed += AdditiveStageValues->MoveSpeed;
		break;
	case EEnemyTypes::RangedEnemy:
		RangedEnemyStageScalingStruct.Defense += AdditiveStageValues->Defense;
		RangedEnemyStageScalingStruct.BaseDamage += AdditiveStageValues->BaseDamage;
		RangedEnemyStageScalingStruct.JumpForce += AdditiveStageValues->JumpForce;
		RangedEnemyStageScalingStruct.MaxHealth += AdditiveStageValues->MaxHealth;
		RangedEnemyStageScalingStruct.MoveSpeed += AdditiveStageValues->MoveSpeed;
		break;
	default: ;
	}
}

void UEnemySubsystem::UpgradeEnemyTimeScaling(EEnemyScalingType AttributeType, float Amount, EEnemyTypes EnemyType)
{
	switch (AttributeType)
	{
	case EEnemyScalingType::Defense:
		switch (EnemyType) {
		case EEnemyTypes::None:
			return;
			break;
		case EEnemyTypes::MeleeEnemy:
			MeleeEnemyTimeScalingStruct.Defense += Amount;
			break;
		case EEnemyTypes::RangedEnemy:
			RangedEnemyTimeScalingStruct.Defense += Amount;
			break;
		default: ;
		}
		break;

	case EEnemyScalingType::BaseDamage:
		switch (EnemyType) {
	case EEnemyTypes::None:
		return;
			break;
	case EEnemyTypes::MeleeEnemy:
		MeleeEnemyTimeScalingStruct.BaseDamage += Amount;
			break;
	case EEnemyTypes::RangedEnemy:
		RangedEnemyTimeScalingStruct.BaseDamage += Amount;
			break;
	default: ;
		}
		break;

	case EEnemyScalingType::JumpForce:
		switch (EnemyType) {
	case EEnemyTypes::None:
		return;
			break;
	case EEnemyTypes::MeleeEnemy:
		MeleeEnemyTimeScalingStruct.JumpForce += Amount;
			break;
	case EEnemyTypes::RangedEnemy:
		RangedEnemyTimeScalingStruct.JumpForce += Amount;
			break;
	default: ;
		}
		break;

	case EEnemyScalingType::MaxHealth:
		switch (EnemyType) {
	case EEnemyTypes::None:
		return;
			break;
	case EEnemyTypes::MeleeEnemy:
		MeleeEnemyTimeScalingStruct.MaxHealth += Amount;
			break;
	case EEnemyTypes::RangedEnemy:
		RangedEnemyTimeScalingStruct.MaxHealth += Amount;
			break;
	default: ;
		}
		break;

	case EEnemyScalingType::MoveSpeed:
		switch (EnemyType) {
	case EEnemyTypes::None:
		return;
			break;
	case EEnemyTypes::MeleeEnemy:
		MeleeEnemyTimeScalingStruct.MoveSpeed += Amount;
			break;
	case EEnemyTypes::RangedEnemy:
		RangedEnemyTimeScalingStruct.MoveSpeed += Amount;
			break;
	default: ;
		}
		break;
	}
}

void UEnemySubsystem::UpgradeEnemyEliteScaling(EEnemyScalingType AttributeType, float Amount, EEnemyTypes EnemyType)
{
	switch (AttributeType)
	{
	case EEnemyScalingType::Defense:
		switch (EnemyType) {
	case EEnemyTypes::None:
		return;
			break;
	case EEnemyTypes::MeleeEnemy:
		MeleeEnemyEliteScalingStruct.Defense += Amount;
			break;
	case EEnemyTypes::RangedEnemy:
		RangedEnemyEliteScalingStruct.Defense += Amount;
			break;
	default: ;
		}
		break;

	case EEnemyScalingType::BaseDamage:
		switch (EnemyType) {
	case EEnemyTypes::None:
		return;
			break;
	case EEnemyTypes::MeleeEnemy:
		MeleeEnemyEliteScalingStruct.BaseDamage += Amount;
			break;
	case EEnemyTypes::RangedEnemy:
		RangedEnemyEliteScalingStruct.BaseDamage += Amount;
			break;
	default: ;
		}
		break;

	case EEnemyScalingType::JumpForce:
		switch (EnemyType) {
	case EEnemyTypes::None:
		return;
			break;
	case EEnemyTypes::MeleeEnemy:
		MeleeEnemyEliteScalingStruct.JumpForce += Amount;
			break;
	case EEnemyTypes::RangedEnemy:
		RangedEnemyEliteScalingStruct.JumpForce += Amount;
			break;
	default: ;
		}
		break;

	case EEnemyScalingType::MaxHealth:
		switch (EnemyType) {
	case EEnemyTypes::None:
		return;
			break;
	case EEnemyTypes::MeleeEnemy:
		MeleeEnemyEliteScalingStruct.MaxHealth += Amount;
			break;
	case EEnemyTypes::RangedEnemy:
		RangedEnemyEliteScalingStruct.MaxHealth += Amount;
			break;
	default: ;
		}
		break;

	case EEnemyScalingType::MoveSpeed:
		switch (EnemyType) {
	case EEnemyTypes::None:
		return;
			break;
	case EEnemyTypes::MeleeEnemy:
		MeleeEnemyEliteScalingStruct.MoveSpeed += Amount;
			break;
	case EEnemyTypes::RangedEnemy:
		RangedEnemyEliteScalingStruct.MoveSpeed += Amount;
			break;
	default: ;
		}
		break;
	}
}

float UEnemySubsystem::GetEnemyScalingStat(UEnemyBaseStats* BaseStats ,EEnemyScalingType AttributeType, bool IsElite, EEnemyTypes EnemyType)
{

	float ReturnValue = 0.f;
	
	switch (AttributeType)
	{
	case EEnemyScalingType::Defense:

		switch (EnemyType) {
		case EEnemyTypes::None:
			return 0.0f;
			break;
		case EEnemyTypes::MeleeEnemy:
			ReturnValue = MeleeEnemyStageScalingStruct.Defense + MeleeEnemyTimeScalingStruct.Defense + BaseStats->Defense;

			if(IsElite)
			{
				ReturnValue += MeleeEnemyEliteScalingStruct.Defense;
			}

			return ReturnValue;
			break;
		case EEnemyTypes::RangedEnemy:
			ReturnValue = RangedEnemyStageScalingStruct.Defense + RangedEnemyTimeScalingStruct.Defense + BaseStats->Defense;

			if(IsElite)
			{
				ReturnValue += RangedEnemyEliteScalingStruct.Defense;
			}

			return ReturnValue;
			break;
		default:return 0.0f ;
		}
		
		
		
		break;

	case EEnemyScalingType::BaseDamage:

		switch (EnemyType) {
	case EEnemyTypes::None:
		return 0.0f;
			break;
	case EEnemyTypes::MeleeEnemy:
		ReturnValue = MeleeEnemyStageScalingStruct.BaseDamage + MeleeEnemyTimeScalingStruct.BaseDamage + BaseStats->BaseDamage;

			if(IsElite)
			{
				ReturnValue += MeleeEnemyEliteScalingStruct.BaseDamage;
			}

			return ReturnValue;
			break;
	case EEnemyTypes::RangedEnemy:
		ReturnValue = RangedEnemyStageScalingStruct.BaseDamage + RangedEnemyTimeScalingStruct.BaseDamage + BaseStats->BaseDamage;

			if(IsElite)
			{
				ReturnValue += RangedEnemyEliteScalingStruct.BaseDamage;
			}

			return ReturnValue;
			break;
	default:return 0.0f ;
		}
		
		break;

	case EEnemyScalingType::JumpForce:

		switch (EnemyType) {
	case EEnemyTypes::None:
		return 0.0f;
			break;
	case EEnemyTypes::MeleeEnemy:
		ReturnValue = MeleeEnemyStageScalingStruct.JumpForce + MeleeEnemyTimeScalingStruct.JumpForce + BaseStats->JumpForce;

			if(IsElite)
			{
				ReturnValue += MeleeEnemyEliteScalingStruct.JumpForce;
			}

			return ReturnValue;
			break;
	case EEnemyTypes::RangedEnemy:
		ReturnValue = RangedEnemyStageScalingStruct.JumpForce + RangedEnemyTimeScalingStruct.JumpForce + BaseStats->JumpForce;

			if(IsElite)
			{
				ReturnValue += RangedEnemyEliteScalingStruct.JumpForce;
			}

			return ReturnValue;
			break;
	default:return 0.0f ;
		}
		
		break;

	case EEnemyScalingType::MaxHealth:
		
		switch (EnemyType) {
	case EEnemyTypes::None:
		return 0.0f;
			break;
	case EEnemyTypes::MeleeEnemy:
		ReturnValue = MeleeEnemyStageScalingStruct.MaxHealth + MeleeEnemyTimeScalingStruct.MaxHealth + BaseStats->MaxHealth;

			if(IsElite)
			{
				ReturnValue += MeleeEnemyEliteScalingStruct.MaxHealth;
			}

			return ReturnValue;
			break;
	case EEnemyTypes::RangedEnemy:
		ReturnValue = RangedEnemyStageScalingStruct.MaxHealth + RangedEnemyTimeScalingStruct.MaxHealth + BaseStats->MaxHealth;

			if(IsElite)
			{
				ReturnValue += RangedEnemyEliteScalingStruct.MaxHealth;
			}

			return ReturnValue;
			break;
	default:return 0.0f ;
		}
		
		break;

	case EEnemyScalingType::MoveSpeed:

		switch (EnemyType) {
	case EEnemyTypes::None:
		return 0.0f;
			break;
	case EEnemyTypes::MeleeEnemy:
		ReturnValue = MeleeEnemyStageScalingStruct.MoveSpeed + MeleeEnemyTimeScalingStruct.MoveSpeed + BaseStats->MoveSpeed;

			if(IsElite)
			{
				ReturnValue += MeleeEnemyEliteScalingStruct.MoveSpeed;
			}

			return ReturnValue;
			break;
	case EEnemyTypes::RangedEnemy:
		ReturnValue = RangedEnemyStageScalingStruct.MoveSpeed + RangedEnemyTimeScalingStruct.MoveSpeed + BaseStats->MoveSpeed;

			if(IsElite)
			{
				ReturnValue += RangedEnemyEliteScalingStruct.MoveSpeed;
			}

			return ReturnValue;
			break;
	default: return 0.0f ;
		}
		
		break;

	default: return 0.f;
	}
}

void UEnemySubsystem::IncrementKillCounter()
{
	KillCounter++;
}

void UEnemySubsystem::ResetKillCounter()
{
	KillCounter = 0;
}

int UEnemySubsystem::GetCurrentKillCount()
{
	return KillCounter;
}
