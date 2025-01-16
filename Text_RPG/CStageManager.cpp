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
		PrevStage = CurStage;
		delete CurStage;
		CurStage = nullptr;
	}

	CurStage = _nextStage;
	CurStage->StageInit();
}
