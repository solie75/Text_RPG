#include "pch.h"
#include "CStateStage.h"
#include "CPlayer.h"
#include "CKeyManager.h"
#include "CStageManager.h"
#include "CVillageStage.h"
#include "CChurchStage.h"
#include "CShopStage.h"
#include "CStartStage.h"
#include "CDungeonEntranceStage.h"

string CStateStage::SpaceMaker(string myString, int stringSize)
{
	string result="";
	if (myString.length() != stringSize)
	{
		result += myString;
		for (int i = 0; i < stringSize - myString.length(); i++)
		{
			result += " ";
		}
	}
	else
	{
		result = myString;
	}
	

	return result;
}

void CStateStage::StageInit()
{
	// �÷��̾� �ν��Ͻ�
	CPlayer* PlayerInstance = CPlayer::GetInst();
	
	// ��� ���� �ʱ�ȭ
	PlayerName = PlayerInstance->GetName();
	PlayerLevel = PlayerInstance->GetLevel();
	PlayerExperience = PlayerInstance->GetExp();
	PlayerHealth = PlayerInstance->GetHealth();
	PlayerDamage = PlayerInstance->GetDamage();
	PlayerGold = PlayerInstance->GetGold();
	PlayerMaxHealth = PlayerInstance->GetMaxHealth();
	PlayerMaxExperience = PlayerInstance->GetMaxExp();
	PlayerHealthPotionCnt = PlayerInstance->GetItemCnt(ITEM_TYPE::HEALTH_POTION);
	PlayerAttackBoostCnt = PlayerInstance->GetItemCnt(ITEM_TYPE::ATTACK_BOOST);
	PlayerMonsterLeatherCnt = PlayerInstance->GetItemCnt(ITEM_TYPE::MONSTER_LEATHER);

	// ȭ�� ����
	StageRender();
}

void CStateStage::StageTick()
{
	if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::ESC) == KEY_STATE::TAP)
	{
		if (dynamic_cast<CVillageStage*>(CStageManager::GetInst()->GetPrevStage()))
		{
			CStageManager::GetInst()->ChangeStage(new CVillageStage);
		}
		else if (dynamic_cast<CShopStage*>(CStageManager::GetInst()->GetPrevStage()))
		{
			CStageManager::GetInst()->ChangeStage(new CShopStage);
		}
		else if (dynamic_cast<CChurchStage*>(CStageManager::GetInst()->GetPrevStage()))
		{
			CStageManager::GetInst()->ChangeStage(new CChurchStage);
		}
		else if (dynamic_cast<CDungeonEntranceStage*>(CStageManager::GetInst()->GetPrevStage()))
		{
			CStageManager::GetInst()->ChangeStage(new CDungeonEntranceStage);
		}
	}
}

void CStateStage::StageRender()
{
	std::cout << "\033[2J\033[H";
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                         _________________________________________________________________________________ \n");
	printf("                                                        / \                                                                                \.\n");
	printf("                                                       |   |                                                                               |.\n");
	printf("                                                        \_  |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |            �÷��̾� �̸� : %s                                         |.\n", SpaceMaker(PlayerName, 10).c_str());
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |            ���� : %s ( %s / %s )                                            |.\n", SpaceMaker(std::to_string(PlayerLevel), 2).c_str(), SpaceMaker(std::to_string(PlayerExperience), 3).c_str(), SpaceMaker(std::to_string(PlayerMaxExperience), 3).c_str());
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |            ü�� : %s / %s                                                   |.\n", SpaceMaker(std::to_string(PlayerHealth), 3).c_str(), SpaceMaker(std::to_string(PlayerMaxHealth), 3).c_str());
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |            ���ݷ� : %s                                                       |.\n", SpaceMaker(std::to_string(PlayerDamage), 3).c_str());
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |            ��� : %s                                                        |.\n", SpaceMaker(std::to_string(PlayerGold), 4).c_str());
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |            ������ : Health Potion : %s ��                                     |.\n", SpaceMaker(std::to_string(PlayerHealthPotionCnt), 2).c_str());
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                     Attack Boost : %s ��                                      |.\n", SpaceMaker(std::to_string(PlayerAttackBoostCnt), 2).c_str());
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                     Monster Leather : %s ��                                   |.\n", SpaceMaker(std::to_string(PlayerMonsterLeatherCnt), 2).c_str());
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |                                                                               |.\n");
	printf("                                                           |   ____________________________________________________________________________|___\n");
	printf("                                                           |  /                                                                               /.\n");
	printf("                                                            \_/dc_____________________________________________________________________________/.\n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
}
