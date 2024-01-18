#include "OverlayUpgradeWidget.h"

#include "GP4/Subsystems/ProgressSubsystem.h"
#include "GP4/Subsystems/UISubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "ListEntries/UpgradeEntry.h"

void UOverlayUpgradeWidget::NativeConstruct()
{
	Super::NativeConstruct();

	LocalPlayer = GetOwningLocalPlayer();
	GameInstance = Cast<UGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	UISubsystem = GameInstance->GetSubsystem<UUISubsystem>();
	PlayerSubsystem = LocalPlayer->GetSubsystem<UPlayerSubsystem>();
	CombatSubsystem = LocalPlayer->GetSubsystem<UCombatSubsystem>();
	EnemySubsystem = GetWorld()->GetSubsystem<UEnemySubsystem>();
	ProgressSubsystem = GetWorld()->GetSubsystem<UProgressSubsystem>();
}

void UOverlayUpgradeWidget::UpgradePicked()
{
	UISubsystem->DisplayedUpgradeWidget = nullptr;

	UISubsystem->SetPlayerHUDVisible(true);
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(FInputModeGameOnly());
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetShowMouseCursor(false);
	RemoveFromParent();
}

void UOverlayUpgradeWidget::AddUpgradeToTileView(TSubclassOf<UUpgradeBase> UpgradeToAdd)
{
	UUpgradeBase* UpgradeItemRef = NewObject<UUpgradeBase>(this, UpgradeToAdd->GetFName(), RF_NoFlags, UpgradeToAdd->GetDefaultObject());

	UpgradeTileView->AddItem(UpgradeItemRef);
	ShownUpgradeClasses.Add(UpgradeToAdd);
}
