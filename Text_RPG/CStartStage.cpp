#include "pch.h"
#include "CStartStage.h"
#include "CKeyManager.h"
#include "CStageManager.h"
#include "CDungeonStage.h"

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
		CStageManager::GetInst()->ChangeStage(new CDungeonStage());
	}
}

void CStartStage::StageRender()
{
	std::cout << "\033[2J\033[H";
	printf("�����������������������������������������������������������������������������������������������������\n");
	printf("��     Start stage    Press Space Bar to go Dungeon Stage                                                                                                                                             ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("��                                                                                                                                                                                                    ��\n");
	printf("�����������������������������������������������������������������������������������������������������");
}
