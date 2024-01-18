#pragma once

#include "CoreMinimal.h"
#include "GP4/Enemy/EnemyBaseStats.h"
#include "GP4/Enemy/EnemyTypes.h"
#include "GP4/Enemy/Structs/EnemyBaseline.h"
#include "GP4/Enemy/Structs/EnemyScalingType.h"
#include "EnemySubsystem.generated.h"

UCLASS()
class GP4_API UEnemySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	//Structs
	FEnemyBaseline MeleeEnemyStageScalingStruct;
	FEnemyBaseline MeleeEnemyTimeScalingStruct;
	FEnemyBaseline MeleeEnemyEliteScalingStruct;

	FEnemyBaseline RangedEnemyStageScalingStruct;
	FEnemyBaseline RangedEnemyTimeScalingStruct;
	FEnemyBaseline RangedEnemyEliteScalingStruct;

	//Functions
	UFUNCTION(BlueprintCallable, Category = "Enemy Subsystem Functions")
	void UpgradeEnemyStageScaling(UEnemyBaseStats* AdditiveStageValues, EEnemyTypes EnemyType);
	UFUNCTION(BlueprintCallable, Category = "Enemy Subsystem Functions")
	void UpgradeEnemyTimeScaling(EEnemyScalingType AttributeType, float Amount, EEnemyTypes EnemyType);
	UFUNCTION(BlueprintCallable, Category = "Enemy Subsystem Functions")
	void UpgradeEnemyEliteScaling(EEnemyScalingType AttributeType, float Amount, EEnemyTypes EnemyType);
	
	UFUNCTION(BlueprintCallable, Category = "Enemy Subsystem Functions")
	float GetEnemyScalingStat(UEnemyBaseStats* BaseStats ,EEnemyScalingType AttributeType, bool IsElite, EEnemyTypes EnemyType);

	UFUNCTION(BlueprintCallable, Category = "Enemy Subsystem Functions")
	void IncrementKillCounter();
	UFUNCTION(BlueprintCallable, Category = "Enemy Subsystem Functions")
	void ResetKillCounter();
	UFUNCTION(BlueprintCallable, Category = "Enemy Subsystem Functions")
	int GetCurrentKillCount();
	
protected:
	int KillCounter;
};
