#include "EnemyStatsWidget.h"

void UEnemyStatsWidget::InitializeHealthBar(FText Name)
{
	EnemyName->SetText(Name);

	EnemyHealthBar->SetPercent(1);
	EnemyDamageBar->SetPercent(1);
}

void UEnemyStatsWidget::UpdateEnemyHealthBar(float CurrentHealth, float MaxHealth)
{
	EnemyHealthBar->SetPercent(CurrentHealth/MaxHealth);
}

void UEnemyStatsWidget::ResetDamageBar()
{
	EnemyDamageBar->SetPercent(EnemyHealthBar->GetPercent());
}

void UEnemyStatsWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UEnemyStatsWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if(EnemyDamageBar->GetPercent() > EnemyHealthBar->GetPercent())
	{
		EnemyDamageBar->SetPercent(FMath::FInterpConstantTo(EnemyDamageBar->GetPercent(), EnemyHealthBar->GetPercent() - 0.01f, InDeltaTime, .33f));
	}
}
