// Copyrint BanMing

#pragma once

#include "Components/TimelineComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "LightActor.generated.h"

UCLASS()
class UE5LAB_API ALightActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALightActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
	UCurveFloat* PointLightFloatCurve;

	UPROPERTY(EditAnywhere)
	UCurveLinearColor* PointLightColorCurve;

protected:
	// Function to Update Light's brightness relative to UpdateBrightnessTrack
	UFUNCTION()
	void UpdateLightBrightness(float BrightnessOutput);

	// Function to Update Light's color relative to UpdateColorTrack
	UFUNCTION()
	void UpdateLightColor(FLinearColor ColorOutput);

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// UTimelineComponent to animate the point light component.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UTimelineComponent* LightTimelineComp;

	// BoxComponent which will be used as our proximity overlap volume.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent* LightOverlapVolume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPointLightComponent* PointLightComp;

	UPROPERTY(EditDefaultsOnly)
	float BrightnessMultiplier;

	// Track used for Pointlight brightness
	FOnTimelineFloat UpdateBrightnessTrack;

	// Track used for Pointlight color
	FOnTimelineLinearColor UpdateColorTrack;
};
