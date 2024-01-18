#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TileView.h"
#include "GP4/Upgrade/UpgradeBase.h"
#include "OverlayUpgradeWidget.generated.h"

class UProgressSubsystem;
class UUISubsystem;
UCLASS(Abstract)
class GP4_API UOverlayUpgradeWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	//Upgrade Widget Variables
	UPROPERTY(EditAnywhere, meta = (BindWidget), BlueprintReadOnly)
	UTileView* UpgradeTileView;

	//Upgrade Widget Functions
	UFUNCTION(BlueprintCallable, Category = "Upgrade Widget Functions")
	void UpgradePicked();

	void AddUpgradeToTileView(TSubclassOf<UUpgradeBase> UpgradeToAdd);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Upgrade Overlay Variables")
	TArray<TSubclassOf<UUpgradeBase>> ShownUpgradeClasses;
	
protected:
	virtual void NativeConstruct() override;

	ULocalPlayer* LocalPlayer;
	UGameInstance* GameInstance;
	UUISubsystem* UISubsystem;
	UPlayerSubsystem* PlayerSubsystem;
	UCombatSubsystem* CombatSubsystem;
	UEnemySubsystem* EnemySubsystem;
	UProgressSubsystem* ProgressSubsystem;
};
