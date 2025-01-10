#include "pch.h"
#include "CGameInstance.h"
#include "CKeyManager.h"
#include "CTimeManager.h"

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
