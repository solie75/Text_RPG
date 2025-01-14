#include "pch.h"
#include "CNormalDungeonStage.h"
#include "CSpawnManager.h"
#include "CPlayer.h"

void CNormalDungeonStage::StageInit()
{
	Monster = move(CSpawnManager::GetInst()->GenerateMonster(CPlayer::GetInst()->GetLevel()));
	__super::StageInit();
}

void CNormalDungeonStage::StageTick()
{
	__super::StageTick();
}

void CNormalDungeonStage::StageRender()
{
	__super::StageRender();
}
