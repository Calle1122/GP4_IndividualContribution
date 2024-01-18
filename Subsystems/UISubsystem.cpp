#include "UISubsystem.h"

#include "PlayerSubsystem.h"
#include "GP4/Widgets/OverlayUpgradeWidget.h"
#include "GP4/Widgets/ListEntries/UpgradeEntry.h"
#include "Kismet/GameplayStatics.h"

void UUISubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UUISubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UUISubsystem::UpdatePlayerHUDReference(UHUDWidget* PlayerHudRef)
{
	PlayerHUD = PlayerHudRef;
}

void UUISubsystem::UpdateStatsWidgetReference(UOverlayMenuWidget* StatsWidgetRef)
{
	StatsWidget = StatsWidgetRef;
}

void UUISubsystem::UpdateStageUI(EStageType CurrentStage, float ProgressedAmount)
{
	if(!IsValid(PlayerHUD))
	{
		return;
	}
	
	switch (CurrentStage)
	{
	case EStageType::Denial:
		PlayerHUD->StageName->SetText(FText::FromString("Denial"));
		break;

	case EStageType::Anger:
		PlayerHUD->StageName->SetText(FText::FromString("Anger"));
		break;

	case EStageType::Bargain:
		PlayerHUD->StageName->SetText(FText::FromString("Bargain"));
		break;

	case EStageType::Depression:
		PlayerHUD->StageName->SetText(FText::FromString("Depression"));
		break;

	case EStageType::Acceptance:
		PlayerHUD->StageName->SetText(FText::FromString("Acceptance"));
		break;
	}

	PlayerHUD->StageBar->SetPercent(ProgressedAmount);
}

void UUISubsystem::UpdateHealthBar(float CurrentHealth, float MaxHealth)
{
	if(!IsValid(PlayerHUD))
	{
		return;
	}
	
	FString newHealthString = "";
	newHealthString.Append(FString::FromInt(CurrentHealth));
	newHealthString.Append(" / ");
	newHealthString.Append(FString::FromInt(MaxHealth));
	
	PlayerHUD->HealthText->SetText(FText::FromString(newHealthString));
	PlayerHUD->HealthBar->SetPercent(CurrentHealth/MaxHealth);
}

void UUISubsystem::UpdateObjectiveUI(FText NewObjective)
{
	PlayerHUD->ObjectiveText->SetText(NewObjective);
}

void UUISubsystem::UpdateAmmoCount(int CurrentAmmo, int MaxAmmo)
{
	if(!IsValid(PlayerHUD))
	{
		return;
	}
	
	FString newAmmoString = "";
	newAmmoString.Append(FString::FromInt(CurrentAmmo));
	newAmmoString.Append(" / ");
	newAmmoString.Append(FString::FromInt(MaxAmmo));
	
	PlayerHUD->AmmoText->SetText(FText::FromString(newAmmoString));
}

void UUISubsystem::SetPlayerHUDVisible(bool Visible)
{
	if(Visible)
	{
		PlayerHUD->SetVisibility(ESlateVisibility::Visible);
		CrosshairWidget->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		PlayerHUD->SetVisibility(ESlateVisibility::Hidden);
		CrosshairWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UUISubsystem::SetStatsWidgetVisible(bool Visible)
{
	if(Visible)
	{
		StatsWidget->SetVisibility(ESlateVisibility::Visible);
		StatsWidget->UpdateOverlayValues();
	}
	else
	{
		StatsWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UUISubsystem::SpawnUpgradeUI(TArray<TSubclassOf<UUpgradeBase>> PickableUpgrades)
{
	UOverlayUpgradeWidget* UpgradeWidget = CreateWidget<UOverlayUpgradeWidget>(UGameplayStatics::GetPlayerController(GetWorld(), 0), UpgradeWidgetClass);

	if(!IsValid(UpgradeWidget))
	{
		return;
	}
	
	SetStatsWidgetVisible(false);
	SetPlayerHUDVisible(false);
	
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(FInputModeUIOnly());
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetShowMouseCursor(true);
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->FlushPressedKeys();

	UGameplayStatics::SetGamePaused(GetWorld(), true);

	UpgradeWidget->AddToPlayerScreen(9999);
	DisplayedUpgradeWidget = UpgradeWidget;

	for ( int i = 0; i < PickableUpgrades.Num(); i++ )
	{
		DisplayedUpgradeWidget->AddUpgradeToTileView(PickableUpgrades[i]);
	}
}


