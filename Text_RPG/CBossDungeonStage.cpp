#include "pch.h"
#include "CBossDungeonStage.h"
#include "CSpawnManager.h"
#include "CPlayer.h"

void CBossDungeonStage::StageInit()
{
	Monster = move(CSpawnManager::GetInst()->GenerateBossMonster(CPlayer::GetInst()->GetLevel()));
	__super::StageInit();
}

void CBossDungeonStage::StageTick()
{
	__super::StageTick();
}

void CBossDungeonStage::StageRender()
{
	__super::StageRender();
}
