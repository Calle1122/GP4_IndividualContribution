#include "HUDWidget.h"

#include "GP4/Subsystems/Enums/StageType.h"

void UHUDWidget::ResetDamageBar()
{
	DamageBar->SetPercent(HealthBar->GetPercent());
}

void UHUDWidget::UpdateDashUI(float InitialCooldown, float TimeSinceLastDash)
{
	float CooldownLeft = InitialCooldown - TimeSinceLastDash;
	
	DashTimer->SetText(FText::FromString(FString::Printf(TEXT("%.1f"), CooldownLeft)));
	DashBar->SetPercent(TimeSinceLastDash/InitialCooldown);
}

void UHUDWidget::SetDashUIState(bool UnderCooldown)
{
	if(UnderCooldown)
	{
		DashTimer->SetVisibility(ESlateVisibility::Visible);
		DashIcon->SetColorAndOpacity(CooldownColor);
	}
	else
	{
		DashTimer->SetText(FText::FromString("0.0"));
		DashTimer->SetVisibility(ESlateVisibility::Hidden);
		DashIcon->SetColorAndOpacity(FLinearColor::White);
	}
}

void UHUDWidget::UpdateParryUI(float InitialCooldown, float TimeSinceLastParry)
{
	float CooldownLeft = InitialCooldown - TimeSinceLastParry;
	
	ParryTimer->SetText(FText::FromString(FString::Printf(TEXT("%.1f"), CooldownLeft)));
	ParryBar->SetPercent(TimeSinceLastParry/InitialCooldown);
}

void UHUDWidget::SetParryUIState(bool UnderCooldown)
{
	if(UnderCooldown)
	{
		ParryTimer->SetVisibility(ESlateVisibility::Visible);
		ParryIcon->SetColorAndOpacity(CooldownColor);
	}
	else
	{
		ParryTimer->SetText(FText::FromString("0.0"));
		ParryTimer->SetVisibility(ESlateVisibility::Hidden);
		ParryIcon->SetColorAndOpacity(FLinearColor::White);
	}
}

void UHUDWidget::UpdateShieldUI(float CurrentShield)
{
	int Shield = FMath::RoundToInt(CurrentShield);
	ArmorText_1->SetText(FText::FromString(FString::Printf(TEXT("%d"), Shield)));
}

void UHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ParryTimer->SetVisibility(ESlateVisibility::Hidden);
	DashTimer->SetVisibility(ESlateVisibility::Hidden);
}

void UHUDWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if(DamageBar->GetPercent() > HealthBar->GetPercent())
	{
		DamageBar->SetPercent(FMath::FInterpConstantTo(DamageBar->GetPercent(), HealthBar->GetPercent() - 0.01f, InDeltaTime, .33f));
	}
}
