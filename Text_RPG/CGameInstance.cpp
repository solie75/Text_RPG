#include "pch.h"
#include "CGameInstance.h"
#include "CKeyManager.h"
#include "CTimeManager.h"

CGameInstance::CGameInstance() {};
CGameInstance::~CGameInstance() {};

void CGameInstance::GameInstInit()
{
	CTimeManager::GetInst()->TimeManagerInit();
	CKeyManager::GetInst()->KeyManagerInit();
}

void CGameInstance::GameInstTick()
{
	CTimeManager::GetInst()->TimeManagerTick();
	CKeyManager::GetInst()->KeyManagerTick();
}
