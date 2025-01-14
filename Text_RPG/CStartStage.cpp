#include "pch.h"
#include <string>
#include "CStartStage.h"
#include "CKeyManager.h"
#include "CStageManager.h"
#include "CDungeonStage.h"
#include "CVillageStage.h"
#include "CPlayer.h"

void CStartStage::StageInit()
{

}

void CStartStage::StageTick()
{
	if (bCallRender)
	{
		StageRender();
		bCallRender = false;
	}

	if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::SPACE) == KEY_STATE::TAP)
	{
		CStageManager::GetInst()->ChangeStage(new CVillageStage());
	}
}

void CStartStage::StageRender()
{
	std::cout << "\033[2J\033[H";
	
	string PlayerID;
	CPlayer* Player = CPlayer::GetInst();
	Player->SetName(PlayerID);

	//�� ���߱�� �ӽ� ����Ʈ
	//printf("�����������������������������������������������������������������������������������������������������\n");

	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                               _     _  _______  ___      ___      _______  _______  __   __  _______  __                                                               \n");
	printf("                                                              | | _ | ||       ||   |    |   |    |       ||       ||  |_|  ||       ||  |                                                              \n");
	printf("                                                              | || || ||    ___||   |    |   |    |      _||   _   ||       ||    ___||  |                                                              \n");
	printf("                                                              |       ||   |___ |   |    |   |    |     |  |  | |  ||       ||   |___ |  |                                                              \n");
	printf("                                                              |       ||    ___||   |___ |   |___ |     |_ |  |_|  ||       ||    ___||__|                                                              \n");
	printf("                                                              |   _   ||   |___ |       ||       ||       ||       || ||_|| ||   |___  __                                                               \n");
	printf("                                                              |__| |__||_______||_______||_______||_______||_______||_|   |_||_______||__|                                                              \n");
	printf("                                                                                __   __  _______  ______    _______  __                                                                                 \n");
	printf("                                                                               |  | |  ||       ||    _ |  |       ||  |                                                                                \n");
	printf("                                                                               |  |_|  ||    ___||   | ||  |   _   ||  |                                                                                \n");
	printf("                                                                               |       ||   |___ |   |_||_ |  | |  ||  |                                                                                \n");
	printf("                                                                               |       ||    ___||    __  ||  |_|  ||__|                                                                                \n");
	printf("                                                                               |   _   ||   |___ |   |  | ||       | __                                                                                 \n");
	printf("                                                                               |__| |__||_______||___|  |_||_______||__|                                                                                \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                     Please type your PlayerID                                                                                          \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                         ");std::getline(std::cin, PlayerID);
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                     Press Space Bar to Start!                                                                                          \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        ");
}

