#pragma once

class CGameInstance
	: public CSingleton<CGameInstance>
{
	SINGLE(CGameInstance)

private:
	int ConsoleWidth;
	int ConsoleHeight;

public:
	void GameInstInit();
	void GameInstTick();

	void SetConsoleWindowSize(int _width, int _height);
	//BOOL SetConsoleSize(int cols, int rows);
	void DisableConsoleResize();
};

