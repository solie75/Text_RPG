#include "pch.h"
#include "CNormalDungeonStage.h"
#include "CSpawnManager.h"
#include "CPlayer.h"
#include "CBattleManager.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CStageManager.h"
#include "CVillageStage.h"
#include "CShopManager.h"
#include "CChurchStage.h"

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
			CStageManager::GetInst()->ChangeStage(new CVillageStage());
		}
		else
		{
			CStageManager::GetInst()->ChangeStage(new CChurchStage());
		}
		
	}
}

void CNormalDungeonStage::StageRender()
{
	__super::StageRender();
}

void CNormalDungeonStage::FinishStage()
{
	std::random_device RandomDevice; // �õ尪�� ��� ���� random_device ����
	std::mt19937 gen(RandomDevice()); // random_device�� ���� ���� ���� ������ �ʱ�ȭ
	std::uniform_int_distribution<int> GoldDistribution(10, 20);
	int Gold = GoldDistribution(gen);
	if (CBattleManager::GetInst()->GetIsPlayerWinner())
	{
		CPlayer::GetInst()->ExpUp(50);
		ITEM_TYPE Dropping = Monster->DropItem();
		if (Dropping != ITEM_TYPE::NONE)
		{
			CPlayer::GetInst()->AddItem(Dropping);
			CPlayer::GetInst()->ReceiveGold(Gold);
			dropItemName = CPlayer::GetInst()->GetItemName(Dropping);
		}
		else
		{
			dropItemName = "Nope";
		}
		dropItemName += " & " + std::to_string(Gold) + "$";
	}
	else
	{
		CPlayer::GetInst()->ExpDown();
	}
	CPlayer::GetInst()->ResetDamage();
	bIsAbleNextStep = true;
	bIsProcessOnceDo = true;
	CShopManager::GetInst()->CShopManagerInit();
}
