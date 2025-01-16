#include "pch.h"
#include "CNormalDungeonStage.h"
#include "CSpawnManager.h"
#include "CPlayer.h"
#include "CBattleManager.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CStageManager.h"
#include "CVillageStage.h"

void CNormalDungeonStage::StageInit()
{
	Monster = move(CSpawnManager::GetInst()->GenerateMonster(CPlayer::GetInst()->GetLevel()));
	__super::StageInit();
}

void CNormalDungeonStage::StageTick()
{
	if (tickTimer <= curTimer)
	{
		curTimer = 0;
		// if == true : ¹èÆ² Áß
		if (CBattleManager::GetInst()->GetIsEndBattle() == false)
		{
			CBattleManager::GetInst()->Battle(*CPlayer::GetInst(), *Monster, BattleLog);
		}
		else
		{
			if (bIsProcessOnceDo == false)
			{
				FinishStage();
				StageRender();
			}
		}

		if (bIsProcessOnceDo == false && CBattleManager::GetInst()->GetIsEndBattle() == false)
			StageRender();
	}
	else
	{
		curTimer += CTimeManager::GetInst()->GetDeltaTime();
	}

	if (bIsAbleNextStep && CKeyManager::GetInst()->GetKeyState(KEY_TYPE::SPACE) == KEY_STATE::TAP)
	{
		if (CBattleManager::GetInst()->GetIsPlayerWinner() == false)
		{
			CPlayer::GetInst()->Defeat_ResetHealth();
		}
		CStageManager::GetInst()->ChangeStage(new CVillageStage());
	}
}

void CNormalDungeonStage::StageRender()
{
	__super::StageRender();
}

void CNormalDungeonStage::FinishStage()
{
	if (CBattleManager::GetInst()->GetIsPlayerWinner())
	{
		CPlayer::GetInst()->ExpUp(50);
		ITEM_TYPE Dropping = Monster->DropItem();
		if (Dropping != ITEM_TYPE::NONE)
		{
			CPlayer::GetInst()->AddItem(Dropping);
			dropItemName = CPlayer::GetInst()->GetItemName(Dropping);
		}
		else
		{
			dropItemName = "Nope";
		}
	}
	else
	{
		CPlayer::GetInst()->ExpDown();
	}
	CPlayer::GetInst()->ResetDamage();
	bIsAbleNextStep = true;
	bIsProcessOnceDo = true;
}
