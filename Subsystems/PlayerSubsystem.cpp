#include "PlayerSubsystem.h"

void UPlayerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	PlayerBaselineStruct = FPlayerBaseline();
	PlayerAttributeStruct = FPlayerAttribute();
	PlayerBuffStruct = FPlayerBuff();
}

void UPlayerSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UPlayerSubsystem::UpdatePlayerBaseline(UPlayerBaseStats* BaseStats)
{
	PlayerBaselineStruct.Defense = BaseStats->Defense;
	PlayerBaselineStruct.Shield = BaseStats->Shield;
	PlayerBaselineStruct.JumpCount = BaseStats->JumpCount;
	PlayerBaselineStruct.JumpForce = BaseStats->JumpForce;
	PlayerBaselineStruct.MaxHealth = BaseStats->MaxHealth;
	PlayerBaselineStruct.MoveSpeed = BaseStats->MoveSpeed;
	PlayerBaselineStruct.DashCount = BaseStats->DashCount;
	PlayerBaselineStruct.DashDistance = BaseStats->DashDistance;
	PlayerBaselineStruct.DashDuration = BaseStats->DashDuration;
	PlayerBaselineStruct.DashCooldown = BaseStats->DashCooldown;

	OnPlayerStatsChanged.Broadcast();
}

void UPlayerSubsystem::UpgradePlayerAttribute(EPlayerAttributeType AttributeType, float Amount)
{
	switch (AttributeType)
	{
	case EPlayerAttributeType::Defense:
		PlayerAttributeStruct.Defense += Amount;
		break;
		
	case EPlayerAttributeType::Shield:
		PlayerAttributeStruct.Shield += Amount;
		break;
		
	case EPlayerAttributeType::MoveSpeed:
		PlayerAttributeStruct.MoveSpeed += Amount;
		break;
		
	case EPlayerAttributeType::JumpCount:
		PlayerAttributeStruct.JumpCount += Amount;
		break;
		
	case EPlayerAttributeType::JumpForce:
		PlayerAttributeStruct.JumpForce += Amount;
		break;
		
	case EPlayerAttributeType::MaxHealth:
		PlayerAttributeStruct.MaxHealth += Amount;
		break;

	case EPlayerAttributeType::DashCount:
		PlayerAttributeStruct.DashCount += Amount;
		break;

	case EPlayerAttributeType::DashDistance:
		PlayerAttributeStruct.DashDistance += Amount;
		break;
		
	case EPlayerAttributeType::DashDuration:
        		PlayerAttributeStruct.DashDuration += Amount;
        		break;
        		
	case EPlayerAttributeType::DashCooldown:
		PlayerAttributeStruct.DashCooldown += Amount;
		break;
		
	default:
		return;
		break;
	}

	OnPlayerStatsChanged.Broadcast();
}

void UPlayerSubsystem::ResetPlayerAttributes()
{
	PlayerAttributeStruct.Defense = 0;
	PlayerAttributeStruct.Shield = 0;
	PlayerAttributeStruct.DashCooldown = 0;
	PlayerAttributeStruct.DashCount = 0;
	PlayerAttributeStruct.DashDistance = 0;
	PlayerAttributeStruct.DashDuration = 0;
	PlayerAttributeStruct.JumpCount = 0;
	PlayerAttributeStruct.JumpForce = 0;
	PlayerAttributeStruct.MaxHealth = 0;
	PlayerAttributeStruct.MoveSpeed = 0;
}

float UPlayerSubsystem::GetPlayerStat(EPlayerAttributeType AttributeType)
{
	switch (AttributeType)
	{
	case EPlayerAttributeType::Defense:
		return PlayerBaselineStruct.Defense + PlayerAttributeStruct.Defense + PlayerBuffStruct.Defense;
		break;
		
	case EPlayerAttributeType::Shield:
		return PlayerBaselineStruct.Shield + PlayerAttributeStruct.Shield + PlayerBuffStruct.Shield;
		break;
		
	case EPlayerAttributeType::MoveSpeed:
		return PlayerBaselineStruct.MoveSpeed + PlayerAttributeStruct.MoveSpeed + PlayerBuffStruct.MoveSpeed;
		break;
		
	case EPlayerAttributeType::JumpCount:
		return PlayerBaselineStruct.JumpCount + PlayerAttributeStruct.JumpCount + PlayerBuffStruct.JumpCount;
		break;
		
	case EPlayerAttributeType::JumpForce:
		return PlayerBaselineStruct.JumpForce + PlayerAttributeStruct.JumpForce + PlayerBuffStruct.JumpForce;
		break;
		
	case EPlayerAttributeType::MaxHealth:
		return PlayerBaselineStruct.MaxHealth + PlayerAttributeStruct.MaxHealth + PlayerBuffStruct.MaxHealth;
		break;
		
	case EPlayerAttributeType::DashCount:
		return PlayerBaselineStruct.DashCount + PlayerAttributeStruct.DashCount + PlayerBuffStruct.DashCount;
		break;

	case EPlayerAttributeType::DashDistance:
		return PlayerBaselineStruct.DashDistance + PlayerAttributeStruct.DashDistance + PlayerBuffStruct.DashDistance;
		break;
		
	case EPlayerAttributeType::DashDuration:
		return PlayerBaselineStruct.DashDuration + PlayerAttributeStruct.DashDuration + PlayerBuffStruct.DashDuration;
		break;
        		
	case EPlayerAttributeType::DashCooldown:
		return PlayerBaselineStruct.DashCooldown + PlayerAttributeStruct.DashCooldown + PlayerBuffStruct.DashCooldown;
		break;
		
	default:
		return 0;
		break;
	}
}

void UPlayerSubsystem::AddTemporaryPlayerBuff(EPlayerAttributeType AttributeType, float Amount, float Time)
{
	const float Interval = Time;
	const bool Loop = false;
	FTimerHandle UniqueHandle;
	FTimerDelegate RemoveBuffDelegate = FTimerDelegate::CreateUObject( this, &UPlayerSubsystem::RemovePlayerBuff, AttributeType, Amount );

	switch (AttributeType)
	{
	case EPlayerAttributeType::Defense:
		PlayerBuffStruct.Defense += Amount;
		
		GetWorld()->GetTimerManager().SetTimer( UniqueHandle, RemoveBuffDelegate, Interval, Loop );
		
		break;
		
	case EPlayerAttributeType::Shield:
		PlayerBuffStruct.Shield += Amount;
		
		GetWorld()->GetTimerManager().SetTimer( UniqueHandle, RemoveBuffDelegate, Interval, Loop );
		
		break;
		
	case EPlayerAttributeType::MoveSpeed:
		PlayerBuffStruct.MoveSpeed += Amount;
		
		GetWorld()->GetTimerManager().SetTimer( UniqueHandle, RemoveBuffDelegate, Interval, Loop );
		
		break;
		
	case EPlayerAttributeType::JumpCount:
		PlayerBuffStruct.JumpCount += Amount;
		
		GetWorld()->GetTimerManager().SetTimer( UniqueHandle, RemoveBuffDelegate, Interval, Loop );
		
		break;
		
	case EPlayerAttributeType::JumpForce:
		PlayerBuffStruct.JumpForce += Amount;
		
		GetWorld()->GetTimerManager().SetTimer( UniqueHandle, RemoveBuffDelegate, Interval, Loop );
		
		break;
		
	case EPlayerAttributeType::MaxHealth:
		PlayerBuffStruct.MaxHealth += Amount;
		
		GetWorld()->GetTimerManager().SetTimer( UniqueHandle, RemoveBuffDelegate, Interval, Loop );
		
		break;

	case EPlayerAttributeType::DashCount:
		PlayerBuffStruct.DashCount += Amount;
		
		GetWorld()->GetTimerManager().SetTimer( UniqueHandle, RemoveBuffDelegate, Interval, Loop );
		
		break;

	case EPlayerAttributeType::DashDistance:
		PlayerBuffStruct.DashDistance += Amount;
		
		GetWorld()->GetTimerManager().SetTimer( UniqueHandle, RemoveBuffDelegate, Interval, Loop );
		
		break;

	case EPlayerAttributeType::DashDuration:
		PlayerBuffStruct.DashDuration += Amount;
		
		GetWorld()->GetTimerManager().SetTimer( UniqueHandle, RemoveBuffDelegate, Interval, Loop );
		
		break;

	case EPlayerAttributeType::DashCooldown:
		PlayerBuffStruct.DashCooldown += Amount;
		
		GetWorld()->GetTimerManager().SetTimer( UniqueHandle, RemoveBuffDelegate, Interval, Loop );
		
		break;
		
	default:
		return;
		break;
	}

	OnPlayerStatsChanged.Broadcast();
}

void UPlayerSubsystem::RemovePlayerBuff(EPlayerAttributeType AttributeType, float Amount)
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
	case EPlayerAttributeType::Defense:
		PlayerBuffStruct.Defense += StatAlteration;
		break;
		
	case EPlayerAttributeType::Shield:
		PlayerBuffStruct.Shield += StatAlteration;
		break;
		
	case EPlayerAttributeType::MoveSpeed:
		PlayerBuffStruct.MoveSpeed += StatAlteration;
		break;
		
	case EPlayerAttributeType::JumpCount:
		PlayerBuffStruct.JumpCount += StatAlteration;
		break;
		
	case EPlayerAttributeType::JumpForce:
		PlayerBuffStruct.JumpForce += StatAlteration;
		break;
		
	case EPlayerAttributeType::MaxHealth:
		PlayerBuffStruct.MaxHealth += StatAlteration;
		break;

	case EPlayerAttributeType::DashCount:
		PlayerBuffStruct.DashCount += StatAlteration;
		break;

	case EPlayerAttributeType::DashDistance:
		PlayerBuffStruct.DashDistance += StatAlteration;
		break;
		
	case EPlayerAttributeType::DashDuration:
		PlayerBuffStruct.DashDuration += StatAlteration;
		break;

	case EPlayerAttributeType::DashCooldown:
		PlayerBuffStruct.DashCooldown += StatAlteration;
		break;
		
	default:
		return;
		break;
	}

	OnPlayerStatsChanged.Broadcast();
}

FTimerHandle UPlayerSubsystem::StartBuffReset(float Delay, EPlayerAttributeType AttributeType, float Amount)
{
	FTimerHandle TimerHandle;
	MyTimerManager->SetTimer(TimerHandle, FTimerDelegate::CreateUObject(this, &UPlayerSubsystem::RemovePlayerBuff, AttributeType, Amount), Delay, false);
	return TimerHandle;
}
