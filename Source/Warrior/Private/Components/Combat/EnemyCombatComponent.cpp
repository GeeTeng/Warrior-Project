// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/EnemyCombatComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "WarriorGameplayTags.h"


void UEnemyCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}
	// TODO: 格挡的检查
	OverlappedActors.AddUnique(HitActor);
	bool bIsValidBlock = false;
	const bool bIsPlayerBlocking = false;
	const bool bIsMyAttackUnblockable = false;
	if (bIsPlayerBlocking && !bIsMyAttackUnblockable)
	{
		// TODO:检查格挡是否有效
	}
	FGameplayEventData EventData;
	EventData.Instigator = GetOwningPawn();
	EventData.Target = HitActor;
	if (bIsValidBlock)
	{
		// 格挡成功的处理
	}
	else
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
			GetOwningPawn(),
			WarriorGameplayTags::Shared_Event_MeleeHit,
			EventData
		);
	}
}
