#pragma once

#include "CoreMinimal.h"
#include "GP4/Widgets/PauseMenuWidget.h"
#include "SoundSubSystem.generated.h"
UCLASS()
class GP4_API USoundSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Subsystem Variables")
	float SfxVolume = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Subsystem Variables")
	float MusicVolume = 1;
};