// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/WarriorBaseAnimInstance.h"
#include "WarriorCharacterAnimInstance.generated.h"

class AWarriorHeroCharacter;
class UCharacterMovementComponent;
class AWarriorBaseCharacter;
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorCharacterAnimInstance : public UWarriorBaseAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	// 这个函数是动画系统的线程安全更新入口，用于在多线程模式下在工作线程中执行动画更新逻辑，从而分担主线程负载、提升性能
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	AWarriorHeroCharacter* OwningCharacter;
	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float GroundSpeed;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAcceleration;
	
};
