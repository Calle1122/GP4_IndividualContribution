#pragma once

#include "CoreMinimal.h"
#include "Enums/StageType.h"
#include "GP4/Upgrade/UpgradeBase.h"
#include "GP4/Widgets/HUDWidget.h"
#include "GP4/Widgets/OverlayMenuWidget.h"
#include "GP4/Widgets/OverlayUpgradeWidget.h"
#include "GP4/Widgets/PauseMenuWidget.h"
#include "UISubsystem.generated.h"

UCLASS()
class GP4_API UUISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI Subsystem Variables")
	TObjectPtr<UHUDWidget> PlayerHUD;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI Subsystem Variables")
	TObjectPtr<UOverlayMenuWidget> StatsWidget;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI Subsystem Variables")
	TObjectPtr<UOverlayUpgradeWidget> DisplayedUpgradeWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Subsystem Variables")
	TSubclassOf<UOverlayUpgradeWidget> UpgradeWidgetClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI Subsystem Variables")
	TObjectPtr<UUserWidget> CrosshairWidget;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI Subsystem Variables")
	TObjectPtr<UPauseMenuWidget> PauseWidget;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI Subsystem Variables")
	TObjectPtr<UUserWidget> TutorialWidget;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI Subsystem Variables")
	TObjectPtr<UUserWidget> WinGameAnimation;
	
	//Player HUD Functions
	UFUNCTION(BlueprintCallable, Category = "UI Subsystem Functions")
	void UpdatePlayerHUDReference(UHUDWidget* PlayerHudRef);
	UFUNCTION(BlueprintCallable, Category = "UI Subsystem Functions")
	void UpdateStatsWidgetReference(UOverlayMenuWidget* StatsWidgetRef);
	UFUNCTION(BlueprintCallable, Category = "UI Subsystem Functions")
	void UpdateStageUI(EStageType CurrentStage, float ProgressedAmount);
	UFUNCTION(BlueprintCallable, Category = "UI Subsystem Functions")
	void UpdateHealthBar(float CurrentHealth, float MaxHealth);
	UFUNCTION(BlueprintCallable, Category = "UI Subsystem Functions")
	void UpdateObjectiveUI(FText NewObjective);
	UFUNCTION(BlueprintCallable, Category = "UI Subsystem Functions")
	void UpdateAmmoCount(int CurrentAmmo, int MaxAmmo);
	UFUNCTION(BlueprintCallable, Category = "UI Subsystem Functions")
	void SetPlayerHUDVisible(bool Visible);
	UFUNCTION(BlueprintCallable, Category = "UI Subsystem Functions")
	void SetStatsWidgetVisible(bool Visible);

	//Upgrade UI Functions
	void SpawnUpgradeUI(TArray<TSubclassOf<UUpgradeBase>> PickableUpgrades);
};
