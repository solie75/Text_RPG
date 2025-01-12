#include "pch.h"
#include "CStageManager.h"
#include "CStartStage.h"
#include "CDungeonStage.h"
#include "CVillageStage.h"
#include "CShopStage.h"
#include "CEndingStage.h"

CStageManager::CStageManager()
	: CurStage(nullptr)
	, NextStage(nullptr)
{

}

CStageManager::~CStageManager()
{
	for (CStage* pStage : VecStage)
	{
		delete pStage;
	}
}

void CStageManager::StageManagerInit()
{
	// init stage
	VecStage.push_back(new CStartStage);
	VecStage.push_back(new CDungeonStage);
	VecStage.push_back(new CVillageStage);
	VecStage.push_back(new CShopStage);
	VecStage.push_back(new CEndingStage);

	CurStage = VecStage[(int)STAGE_TYPE::START];
	NextStage = VecStage[(int)STAGE_TYPE::START];
}

void CStageManager::StageManagerTick()
{
}

CStage* CStageManager::GetStage(STAGE_TYPE _type)
{
	return VecStage[(int)_type];
}

void CStageManager::ChangeStage(STAGE_TYPE _nextStageType)
{
	// Close Cur Stage
	{

	}

	// Open Next Stage
	{

	}

	// Render Next Stage
	{

	}

	CurStage = NextStage;
}
