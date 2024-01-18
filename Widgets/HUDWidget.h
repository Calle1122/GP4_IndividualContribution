#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "HUDWidget.generated.h"

UCLASS(Abstract)
class GP4_API UHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* StageName;
	UPROPERTY(meta = (BindWidget))
	UProgressBar* StageBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* HealthText;
	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;
	UPROPERTY(meta = (BindWidget))
	UProgressBar* DamageBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* AmmoText;
	
	UPROPERTY(meta = (BindWidget))
    UTextBlock* DashTimer;
    UPROPERTY(meta = (BindWidget))
    UProgressBar* DashBar;
	UPROPERTY(meta = (BindWidget))
	UImage* DashIcon;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ParryTimer;
	UPROPERTY(meta = (BindWidget))
	UProgressBar* ParryBar;
	UPROPERTY(meta = (BindWidget))
	UImage* ParryIcon;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ObjectiveText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ArmorText_1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD Widget Variables")
	FLinearColor CooldownColor;

	UFUNCTION(BlueprintCallable, Category = "HUD Widget Functions")
	void ResetDamageBar();

	UFUNCTION(BlueprintCallable, Category = "HUD Widget Functions")
	void UpdateDashUI(float InitialCooldown, float TimeSinceLastDash);
	UFUNCTION(BlueprintCallable, Category = "HUD Widget Functions")
	void SetDashUIState(bool UnderCooldown);
	
	UFUNCTION(BlueprintCallable, Category = "HUD Widget Functions")
	void UpdateParryUI(float InitialCooldown, float TimeSinceLastParry);
	UFUNCTION(BlueprintCallable, Category = "HUD Widget Functions")
	void SetParryUIState(bool UnderCooldown);

	UFUNCTION(BlueprintCallable, Category = "HUD Widget Functions")
	void UpdateShieldUI(float CurrentShield);
	
protected:
	virtual void NativeConstruct() override;

	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};
