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
		// if == true : 배틀 중
		if (CBattleManager::GetInst()->GetIsEndBattle() == false)
		{
			CBattleManager::GetInst()->Battle(*CPlayer::GetInst(), *Monster, BattleLog);
		}
		else
		{
			if (bIsProcessOnceDo == false)
			{
				FinishStage();
			}
		}

		if (bIsProcessOnceDo == false)
			StageRender();
	}
	else
	{
		curTimer += CTimeManager::GetInst()->GetDeltaTime();
	}

	if (bIsAbleNextStep && CKeyManager::GetInst()->GetKeyState(KEY_TYPE::SPACE) == KEY_STATE::TAP)
	{
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
		//Monster->DropItem(); 이용해서 인벤토리에 아이템 넣기 & 해당값을 가지고 로그창에 띄우기
		// DropItem()이 있는지 체크하고, 분기점으로 네임 넣기
		//dropItemName = CPlayer::GetInst()->GetInventory(Monster->DropItem())->GetName();
	}
	else
	{
		CPlayer::GetInst()->ExpDown();
	}
	bIsAbleNextStep = true;
	bIsProcessOnceDo = true;
}
