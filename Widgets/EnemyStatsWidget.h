#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "EnemyStatsWidget.generated.h"

UCLASS(Abstract)
class GP4_API UEnemyStatsWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* EnemyName;
	UPROPERTY(meta = (BindWidget))
	UProgressBar* EnemyHealthBar;
	UPROPERTY(meta = (BindWidget))
	UProgressBar* EnemyDamageBar;

	UFUNCTION(BlueprintCallable, Category = "Enemy Stats Widget Functions")
	void InitializeHealthBar(FText Name);
	UFUNCTION(BlueprintCallable, Category = "Enemy Stats Widget Functions")
	void UpdateEnemyHealthBar(float CurrentHealth, float MaxHealth);
	UFUNCTION(BlueprintCallable, Category = "Enemy Stats Widget Functions")
	void ResetDamageBar();
	
protected:
	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};
