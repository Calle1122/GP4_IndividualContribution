// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GP4/Player/PlayerBase.h"


// void AEnemyBase::SetIsAttacking(bool bValue)
// {
// 	UE_LOG(LogTemp, Warning, TEXT("IsAttacking: %s"), bValue ? TEXT("True") : TEXT("False"));
// 	bIsAttacking = bValue;
// }

void AEnemyBase::Deactivate()
{
	GetWorldTimerManager().ClearAllTimersForObject(this);
	// SetIsAttacking(false);
	OnPooledCharacterDelegateDespawn.Broadcast(this);
	OnEnemyBaseDespawn.Broadcast(this, EnemyTypes);
	SetActive(false);
}

void AEnemyBase::SetActive(bool IsActive)
{
	bIsActive = IsActive;
	if (IsActive == false)
	{
		OnSetActiveCalled(IsActive); //Blueprint Implementable Event

		SetActorHiddenInGame(!IsActive);
		SetActorTickEnabled(IsActive);
		SetActorEnableCollision(IsActive);
		GetCharacterMovement()->GravityScale = IsActive ? 1.0f : 0.0f; //So It does not fall down before it get spawned
	}

	FTimerHandle TimerHandle;
	if (IsActive == true)
	{
		GetCharacterMovement()->DisableMovement();
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AEnemyBase::InsideSetActive, 2.0f, false, 2.0f);
		
		OnActivated();

	}
	// OnSetActiveCalled(IsActive); //Used to be here
}

void AEnemyBase::InsideSetActive()
{
	//Everything should be true
	
	SetActorHiddenInGame(!bIsActive);
	GetCharacterMovement()->SetDefaultMovementMode();
	SetActorEnableCollision(bIsActive);
	SetActorTickEnabled(bIsActive);
	GetCharacterMovement()->GravityScale = bIsActive ? 1.0f : 0.0f; //So It does not fall down before it get spawned

	OnSetActiveCalled(bIsActive); //Blueprint Implementable Event
}




void AEnemyBase::SetLifeSpan(float LifeTime) { LifeSpan = LifeTime; }

void AEnemyBase::SetPoolIndex(int32 Index) { PoolIndex = Index; }

bool AEnemyBase::IsActive()  { return bIsActive; }

int AEnemyBase::GetPoolIndex() { return PoolIndex; }

EEnemyTypes AEnemyBase::SetEnemyType(EEnemyTypes EnemyType)
{
	return EnemyTypes = EnemyType;
}


void AEnemyBase::DropItem()
{
	if (KnownBuffsToDrop.Num() > 0)
	{
		TSubclassOf<APickupBase> Gacha = KnownBuffsToDrop[FMath::RandRange(0, KnownBuffsToDrop.Num()-1)];

		GetWorld()->SpawnActor<APickupBase>(Gacha, GetActorLocation(), FRotator::ZeroRotator);
	}
}



// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}
// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}
// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}
// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

