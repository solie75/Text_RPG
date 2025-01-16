#include "pch.h"
#include "CStageManager.h"
#include "CStage.h"


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
