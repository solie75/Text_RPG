#include "pch.h"
#include "CBossDungeonStage.h"
#include "CSpawnManager.h"
#include "CPlayer.h"
#include "CBattleManager.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CStageManager.h"
#include "CEndingStage.h"
#include "CChurchStage.h"
#include "CShopManager.h"

void CBossDungeonStage::StageInit()
{
	Monster = move(CSpawnManager::GetInst()->GenerateBossMonster(CPlayer::GetInst()->GetLevel()));
	__super::StageInit();
}

void CBossDungeonStage::StageTick()
{
	if (tickTimer <= curTimer)
	{
		curTimer = 0;
		// if == true : ��Ʋ ��
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
		if (CBattleManager::GetInst()->GetIsPlayerWinner())
		{
			CStageManager::GetInst()->ChangeStage(new CEndingStage());
		}
		else
		{
			CStageManager::GetInst()->ChangeStage(new CChurchStage());
		}
	}
}

void CBossDungeonStage::StageRender()
{
	__super::StageRender();
}

void CBossDungeonStage::FinishStage()
{
	if (CBattleManager::GetInst()->GetIsPlayerWinner())
	{
		dropItemName = "Nope";
	}
	else
	{
		CPlayer::GetInst()->ExpDown();
	}
	bIsAbleNextStep = true;
	bIsProcessOnceDo = true;
	CShopManager::GetInst()->CShopManagerInit();
}
