#pragma once
class CGameInstance
	: public CSingleton<CGameInstance>
{
	SINGLE(CGameInstance)

public:
	void GameInstInit();
	void GameInstTick();
};

