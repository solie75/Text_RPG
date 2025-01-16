#include "pch.h"
#include "CStageManager.h"
#include "CStage.h"
#include "CKeyManager.h"
#include "CPlayer.h"


CStageManager::CStageManager()
	: CurStage(nullptr)
	, IsDoneTutorialStage(false)
{

}

CStageManager::~CStageManager()
{
}

void CStageManager::StageManagerInit()
{
	/*CurStage = nullptr;
	IsDoneTutorialStage = false;*/
}

void CStageManager::StageManagerTick()
{
	CurStage->StageTick();
	if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::Z) == KEY_STATE::TAP)
	{
		CPlayer::GetInst()->RegisterMaster();
	}
}

CStage* CStageManager::GetCurStage()
{
	return CurStage;
}

CStage* CStageManager::GetPrevStage()
{
	return PrevStage;
}

void CStageManager::ChangeStage(CStage* _nextStage)
{
	if (nullptr != CurStage)
	{
		if (nullptr != PrevStage)
		{
			delete PrevStage;
			PrevStage = nullptr;
		}

		PrevStage = CurStage;
		CurStage = nullptr;
	}

	CurStage = _nextStage;
	if (nullptr != CurStage)
	{
		CurStage->StageInit();
	}
}

void CStageManager::BackToPrevStage()
{
	CStage* TempStage;
	TempStage = PrevStage;
	PrevStage = CurStage;
	CurStage = TempStage;
	CurStage->StageInit();

	TempStage = nullptr;
}
