#pragma once

#include "CoreMinimal.h"
#include "GP4/Player/PlayerBaseStats.h"
#include "GP4/Player/Structs/PlayerAttribute.h"
#include "GP4/Player/Structs/PlayerAttributeType.h"
#include "GP4/Player/Structs/PlayerBaseline.h"
#include "GP4/Player/Structs/PlayerBuff.h"
#include "PlayerSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerStatsChanged);

UCLASS(BlueprintType)
class GP4_API UPlayerSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	//Structs
	FPlayerBaseline PlayerBaselineStruct;
	FPlayerAttribute PlayerAttributeStruct;
	FPlayerBuff PlayerBuffStruct;

	//Delegates
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "OnPlayerStatsChanged"), Category="Player Subsystem Events")
	FOnPlayerStatsChanged OnPlayerStatsChanged;

	//Functions
	UFUNCTION(BlueprintCallable, Category = "Player Subsystem Functions")
	void UpdatePlayerBaseline(UPlayerBaseStats* BaseStats);

	UFUNCTION(BlueprintCallable, Category = "Player Subsystem Functions")
	void UpgradePlayerAttribute(EPlayerAttributeType AttributeType, float Amount);

	UFUNCTION(BlueprintCallable, Category = "Combat Subsystem Functions")
	void ResetPlayerAttributes();
	
	UFUNCTION(BlueprintCallable, Category = "Player Subsystem Functions")
	float GetPlayerStat(EPlayerAttributeType AttributeType);

	UFUNCTION(BlueprintCallable, Category = "Player Subsystem Functions")
	void AddTemporaryPlayerBuff(EPlayerAttributeType AttributeType, float Amount, float Time);

protected:
	void RemovePlayerBuff(EPlayerAttributeType AttributeType, float Amount);

	FTimerManager* MyTimerManager;

	FTimerHandle StartBuffReset(float Delay, EPlayerAttributeType AttributeType, float Amount);
};
