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
