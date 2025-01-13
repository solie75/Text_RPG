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
	printf("¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à\n");
	printf("¡à     Dungeon stage  Test Complete                                                                                                                                                                   ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à                                                                                                                                                                                                    ¡à\n");
	printf("¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à");
}
