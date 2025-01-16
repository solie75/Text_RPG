#include "pch.h"
#include "CStageManager.h"
#include "CStage.h"


CStageManager::CStageManager()
	: CurStage(nullptr)
{

}

CStageManager::~CStageManager()
{
}

void CStageManager::StageManagerInit()
{
	CurStage = nullptr;
	bIsDoneTutorialStage = false;
}

void CStageManager::StageManagerTick()
{
	CurStage->StageTick();
}

CStage* CStageManager::GetCurStage()
{
	return CurStage;
}

void CStageManager::ChangeStage(CStage* _nextStage)
{
	if (nullptr != CurStage)
	{
		delete CurStage;
		CurStage = nullptr;
	}

	CurStage = _nextStage;
	CurStage->StageInit();
}
