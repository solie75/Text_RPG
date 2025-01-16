#include "pch.h"
#include "CEndingStage.h"
#include "CStartStage.h"
#include "CKeyManager.h"
#include <stdlib.h>

void CEndingStage::StageInit()
{
}

void CEndingStage::StageTick()
{
	if (bCallRender)
	{
		StageRender();
		bCallRender = false;
	}

	if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::ESC) == KEY_STATE::TAP) //esc 누르면 게임 종료
	{		

	}

	//CKeyManager::GetInst()->GetKeyState();
	//switch(KEY_TYPE::)

}

	//if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::ESC) == KEY_STATE::TAP) //esc 누르면 콘솔 종료
	//{		
	//	exit(0);
	//}

	//for (int i = 0; KEY_TYPE::ESC != KEY_STATE::TAP; ++i )
	//{
	//	CKeyManager::GetInst()->GetKeyState(i)
	//	CStageManager::GetInst()->ChangeStage(new CStartStage());
	//}



void CEndingStage::StageRender()
{
	std::cout << "\033[2J\033[H";
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
}
