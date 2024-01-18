#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/RichTextBlock.h"
#include "Components/TextBlock.h"
#include "GP4/Upgrade/UpgradeBase.h"
#include "UpgradeEntry.generated.h"

UCLASS(Abstract)
class GP4_API UUpgradeEntry : public UUserWidget, public IUserObjectListEntry
{

	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	UImage* Frame;
	UPROPERTY(meta = (BindWidget))
	UImage* UpgradeIcon;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* UpgradeType;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* UpgradeName;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* StatName_1;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* StatValue_1;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* StatName_2;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* StatValue_2;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* StatName_3;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* StatValue_3;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* StatName_4;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* StatValue_4;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* StatName_5;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* StatValue_5;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* StatName_6;
	UPROPERTY(meta = (BindWidget))
	URichTextBlock* StatValue_6;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Entry Variables")
	FLinearColor GreenFieldColor;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Entry Variables")
	FLinearColor RedFieldColor;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Entry Variables")
	FLinearColor WhiteFieldColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Entry Variables")
	FLinearColor CommonRarityColor;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Entry Variables")
	FLinearColor RareRarityColor;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Entry Variables")
	FLinearColor LegendaryRarityColor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Entry Variables")
	UUpgradeBase* RelatedUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Entry Variables")
	TSubclassOf<UUpgradeBase> RelatedClass;
	
protected:
	virtual void NativeOnListItemObjectSet(UObject* UpgradeItem) override;

	void ClearLines();
	void SetInfoLineText(UGunBaseStats* GunUpgradeData, UPlayerBaseStats* PlayerUpgradeData);
	void SetLineUI(int LineIndex, FText LineDescription, FText LineValue);
};
