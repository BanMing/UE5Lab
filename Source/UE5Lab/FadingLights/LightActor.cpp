// Copyrint BanMing
#include "UE5Lab/FadingLights/LightActor.h"

#include "Components/BoxComponent.h"
#include "Components/PointLightComponent.h"

// Sets default values
ALightActor::ALightActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create our Default Components
	PointLightComp = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComp"));
	LightTimelineComp = CreateDefaultSubobject<UTimelineComponent>(TEXT("LightTimelineComp"));
	LightOverlapVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("LightOverlapVolume"));

	// Setup our Attachments
	RootComponent = LightOverlapVolume;
	PointLightComp->AttachToComponent(LightOverlapVolume, FAttachmentTransformRules::KeepRelativeTransform);

	// Initialize Brightness Multiplier
	BrightnessMultiplier = 20.0f;
}

// Called when the game starts or when spawned
void ALightActor::BeginPlay()
{
	Super::BeginPlay();

	// Binding our float and color track to their respective functions
	UpdateBrightnessTrack.BindDynamic(this, &ThisClass::UpdateLightBrightness);
	UpdateColorTrack.BindDynamic(this, &ThisClass::UpdateLightColor);

	// If we have a float curve, bind it's graph to our update function
	if (PointLightColorCurve)
	{
		LightTimelineComp->AddInterpFloat(PointLightFloatCurve, UpdateBrightnessTrack);
	}

	// If we have a linear color curve, bind it's graph to our update function
	if (PointLightColorCurve)
	{
		LightTimelineComp->AddInterpLinearColor(PointLightColorCurve, UpdateColorTrack);
	}

	LightOverlapVolume->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
}

// Called every frame
void ALightActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALightActor::UpdateLightBrightness(float BrightnessOutput)
{
	PointLightComp->SetLightBrightness(BrightnessOutput * 20.0f);
}

void ALightActor::UpdateLightColor(FLinearColor ColorOutput)
{
	PointLightComp->SetLightColor(ColorOutput);
}

void ALightActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	LightTimelineComp->Play();
}
