#include "pch.h"
#include "CEndingStage.h"
#include "CStartStage.h"
#include "CKeyManager.h"

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

void CEndingStage::StageRender()
{
}
