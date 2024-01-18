#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/HorizontalBox.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "DataAssets/SetBonusUIData.h"
#include "OverlayMenuWidget.generated.h"

UCLASS(Abstract)
class GP4_API UOverlayMenuWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	// Variables

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Overlay Menu Variables")
	FLinearColor LegendaryColor;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Overlay Menu Variables")
	FLinearColor RareColor;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Overlay Menu Variables")
	FLinearColor CommonColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Overlay Menu Variables")
	FLinearColor GreenFieldColor;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Overlay Menu Variables")
	FLinearColor RedFieldColor;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Overlay Menu Variables")
	FLinearColor WhiteFieldColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Overlay Menu Variables")
	USetBonusUIData* RifleUIData;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Overlay Menu Variables")
	USetBonusUIData* SniperUIData;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Overlay Menu Variables")
	USetBonusUIData* ShotgunUIData;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Overlay Menu Variables")
	USetBonusUIData* MachinegunUIData;
	
	// UI Fields
	
	UPROPERTY(meta = (BindWidget))
	UImage* Rifle1Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Rifle1Frame;
	UPROPERTY(meta = (BindWidget))
	UImage* Rifle2Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Rifle2Frame;
	UPROPERTY(meta = (BindWidget))
	UImage* Rifle3Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Rifle3Frame;
	UPROPERTY(meta = (BindWidget))
	UImage* Rifle4Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Rifle4Frame;
	UPROPERTY(meta = (BindWidget))
	UImage* Rifle5Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Rifle5Frame;

	UPROPERTY(meta = (BindWidget))
	UImage* Sniper1Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Sniper1Frame;
	UPROPERTY(meta = (BindWidget))
	UImage* Sniper2Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Sniper2Frame;
	UPROPERTY(meta = (BindWidget))
	UImage* Sniper3Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Sniper3Frame;
	UPROPERTY(meta = (BindWidget))
	UImage* Sniper4Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Sniper4Frame;
	UPROPERTY(meta = (BindWidget))
	UImage* Sniper5Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Sniper5Frame;

	UPROPERTY(meta = (BindWidget))
	UImage* Shotgun1Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Shotgun1Frame;
	UPROPERTY(meta = (BindWidget))
	UImage* Shotgun2Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Shotgun2Frame;
	UPROPERTY(meta = (BindWidget))
	UImage* Shotgun3Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Shotgun3Frame;
	UPROPERTY(meta = (BindWidget))
	UImage* Shotgun4Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Shotgun4Frame;
	UPROPERTY(meta = (BindWidget))
	UImage* Shotgun5Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Shotgun5Frame;

	UPROPERTY(meta = (BindWidget))
	UImage* Machinegun1Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Machinegun1Frame;
	UPROPERTY(meta = (BindWidget))
	UImage* Machinegun2Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Machinegun2Frame;
	UPROPERTY(meta = (BindWidget))
	UImage* Machinegun3Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Machinegun3Frame;
	UPROPERTY(meta = (BindWidget))
	UImage* Machinegun4Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Machinegun4Frame;
	UPROPERTY(meta = (BindWidget))
	UImage* Machinegun5Img;
	UPROPERTY(meta = (BindWidget))
	UImage* Machinegun5Frame;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* RifleNumber;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* SniperNumber;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ShotgunNumber;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* MachinegunNumber;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* KillNumber;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* UpgradeNumber;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* DamageNumber;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* DefenseNumber;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* CritChanceNumber;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* CritDamageNumber;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* WeakpointDamageNumber;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ProjectilesNumber;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* FireRateNumber;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* AccuracyNumber;

	UPROPERTY(meta = (BindWidget))
	UImage* RifleBonusBack;
	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* RifleBonusBox;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* RifleStatName_1;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* RifleStatValue_1;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* RifleStatName_2;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* RifleStatValue_2;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* RifleStatName_3;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* RifleStatValue_3;

	UPROPERTY(meta = (BindWidget))
	UImage* SniperBonusBack;
	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* SniperBonusBox;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* SniperStatName_1;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* SniperStatValue_1;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* SniperStatName_2;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* SniperStatValue_2;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* SniperStatName_3;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* SniperStatValue_3;

	UPROPERTY(meta = (BindWidget))
	UImage* ShotgunBonusBack;
	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* ShotgunBonusBox;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ShotgunStatName_1;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ShotgunStatValue_1;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ShotgunStatName_2;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ShotgunStatValue_2;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ShotgunStatName_3;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ShotgunStatValue_3;

	UPROPERTY(meta = (BindWidget))
	UImage* MachinegunBonusBack;
	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* MachinegunBonusBox;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* MachinegunStatName_1;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* MachinegunStatValue_1;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* MachinegunStatName_2;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* MachinegunStatValue_2;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* MachinegunStatName_3;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* MachinegunStatValue_3;

	UPROPERTY(meta = (BindWidget))
	USizeBox* RifleLockBox;
	UPROPERTY(meta = (BindWidget))
	USizeBox* SniperLockBox;
	UPROPERTY(meta = (BindWidget))
	USizeBox* ShotgunLockBox;
	UPROPERTY(meta = (BindWidget))
	USizeBox* MachinegunLockBox;

	// Functions

	UFUNCTION(BlueprintCallable, Category = "Overlay Menu Functions")
	void UpdateOverlayValues();
	
protected:
	virtual void NativeConstruct() override;
};
