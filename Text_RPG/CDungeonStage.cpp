#include "pch.h"
#include "CDungeonStage.h"

void CDungeonStage::StageInit()
{
}

void CDungeonStage::StageTick()
{
	if (bCallRender)
	{
		this->StageRender();
		bCallRender = false;
	}
}

void CDungeonStage::StageRender()
{
	std::cout << "\033[2J\033[H";
	printf("�����������������������������������������������������������������������������������������������������\n");
	printf("��     Dungeon stage  Test Complete                                                                                                                                                                   ��\n");
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
