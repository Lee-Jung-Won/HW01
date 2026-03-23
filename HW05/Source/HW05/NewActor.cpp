// Fill out your copyright notice in the Description page of Project Settings.


#include "NewActor.h"
#include "Engine/Engine.h"
#include "KismetMathLibrary.generated.h"
int calculdistance = 0;
float Max_time = 10.6f;
float timegoeson = 0.f;
float timegoeson1 = 0.f;
int howmanytrigger = 0;
int cnt = 0;

// Sets default values
ANewActor::ANewActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickEnabled(false);
}

// Called when the game starts or when spawned
void ANewActor::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0, 50, 0));
	FVector ActorLocation = GetActorLocation();


	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Hello Unreals"));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, FString::Printf(TEXT("Actor : %s"), *GetName()));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, FString::Printf(TEXT("Actor : %s"), *ActorLocation.ToString()));
	}

	SetActorTickEnabled(true);
}

void ANewActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	timegoeson = 0.f;
	timegoeson1 = 0.f;
	howmanytrigger = 0;
	calculdistance = 0;
	cnt = 0;
}

// Called every frame
void ANewActor::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	timegoeson += DeltaTime;
	timegoeson1 += DeltaTime;

	if (timegoeson1 >= 1.f)
	{
		cnt++;
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Green, FString::Printf(TEXT("< Move, Rotate > : %d"), cnt));
			randommove();
			randomrotate();
			Eventtrigger();
		}
		timegoeson1 = 0.f;
	}

	if (timegoeson > Max_time)
	{
		SetActorTickEnabled(false);
		GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString::Printf(TEXT("< TotalEvent Happened : %d"), howmanytrigger));
		GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString::Printf(TEXT("< TotalMoveDistance : %d"), calculdistance));
	}

}

void ANewActor::Eventtrigger()
{
	int rand = FMath::RandRange(0, 1);
	switch (rand)
	{
	case 0:
	break;
	case 1:
		howmanytrigger++;
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("EventTrigger Happened")));
	break;

	}
}

void ANewActor::randommove()
{
	
		FVector ActorLocation = GetActorLocation();
		int num1 = FMath::RandRange(-50, 50);
		int num2 = FMath::RandRange(-50, 50);
		int num3 = FMath::RandRange(0, 50);
		FVector Newloc(num1, num2, num3);
		auto setloc = ActorLocation + Newloc;
		calculdistance += FVector::Distance(ActorLocation, setloc);
		SetActorLocation(setloc);
		ActorLocation = GetActorLocation();
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Blue, FString::Printf(TEXT(" - Actor : %s"), *ActorLocation.ToString()));
		}

}

void ANewActor::randomrotate()
{
	FRotator ActorRoatation = GetActorRotation();
	float rnum1 = FMath::RandRange(-50, 50);
	float rnum2 = FMath::RandRange(-50, 50);
	float rnum3 = FMath::RandRange(-50, 50);
	FRotator Newloc(rnum1, rnum2, rnum3);
	auto setrot = ActorRoatation + Newloc;
	SetActorRotation(setrot);
	ActorRoatation = GetActorRotation();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 7.0f, FColor::Red, FString::Printf(TEXT(" - Actor : %s"), *ActorRoatation.ToString()));
	}
}

