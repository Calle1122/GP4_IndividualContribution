#pragma once

#include "CoreMinimal.h"
#include "EnemyBaseStats.h"
#include "GameFramework/Character.h"
#include "Delegates/Delegate.h"
#include "GP4/Pickups/PickupBase.h"
// #include "PlayerBase.generated.h"
#include "EnemyTypes.h"
#include "EnemyBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPooledCharacterDelegateDespawn, AEnemyBase*, EnemyBase);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEnemyBaseDespawn, AEnemyBase*, EnemyBase, EEnemyTypes, EnemyTypes);
UCLASS()
class GP4_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	FText EnemyName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	TObjectPtr<UEnemyBaseStats> EnemyBaseStats;
	
	FOnPooledCharacterDelegateDespawn OnPooledCharacterDelegateDespawn;
	FOnEnemyBaseDespawn OnEnemyBaseDespawn;

	UFUNCTION(BlueprintCallable, Category="Pooled Character Category")
	void Deactivate();

	UFUNCTION(BlueprintImplementableEvent)
	void OnActivated();

	UFUNCTION(BlueprintImplementableEvent, Category = "Enemy Events")
	void OnParry(FHitResult HitResult, FVector Direction);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Enemy Events")
	void OnAttack();

	UFUNCTION(BlueprintCallable, Category="SetActive Category")
	void SetActive(bool IsActive);
	void SetLifeSpan(float LifeTime);
	void SetPoolIndex(int32 Index);
	int GetPoolIndex();

	EEnemyTypes SetEnemyType(EEnemyTypes EnemyType);
	EEnemyTypes EnemyTypes;
	
	void InsideSetActive();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetActiveCalled(bool IsActive);

	UFUNCTION(BlueprintImplementableEvent)
	void WaveEvent();

	bool IsActive();

	float DelayTimer;
	bool bOnlyOnce;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool bIsActive;
	float LifeSpan = 0.0f;
	int32 PoolIndex; // = -1;

	FTimerHandle LifeSpanTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Buff drop Category")
	TArray<TSubclassOf<APickupBase>> KnownBuffsToDrop;

	UFUNCTION(BlueprintCallable, Category= "Just Dropthings Category")
	virtual void DropItem();

public:

	// UFUNCTION()
	// void SetIsAttacking(bool bValue);
	//
	// UPROPERTY(BlueprintReadWrite, EditAnywhere)
	// bool bIsAttacking = false;
	//
	// FTimerHandle AnimationTimerHandle;
	//
	// void StartAttackTimer(float TimerLength);

	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};