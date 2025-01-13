#include "pch.h"
#include "CGameInstance.h"
#include "CKeyManager.h"
#include "CTimeManager.h"


CGameInstance::CGameInstance()
	: ConsoleWidth(200)
	, ConsoleHeight(50)
{
};
CGameInstance::~CGameInstance() {};

void CGameInstance::GameInstInit()
{
	CTimeManager::GetInst()->TimeManagerInit();
	CKeyManager::GetInst()->KeyManagerInit();

	// Set Console Size
	SetConsoleWindowSize(ConsoleWidth, ConsoleHeight);
	DisableConsoleResize();

	// TEST
	printf("This is GameInstInit Test\n");
}

void CGameInstance::GameInstTick()
{
	CTimeManager::GetInst()->TimeManagerTick();
	CKeyManager::GetInst()->KeyManagerTick();
}

void CGameInstance::SetConsoleWindowSize(int _width, int _height)
{
    HANDLE H_Console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (H_Console == INVALID_HANDLE_VALUE) {
        std::cerr << "Invalid console handle. Error: " << GetLastError() << "\n";
        return;
    }

    // 버퍼 크기 설정
    COORD BufferSize = { static_cast<SHORT>(_width), static_cast<SHORT>(_height) };
    if (!SetConsoleScreenBufferSize(H_Console, BufferSize)) {
        std::cerr << "Failed to set console buffer size. Error: " << GetLastError() << "\n";
        return;
    }

    // 창 크기 설정
    SMALL_RECT WindowSize = { 0, 0, static_cast<SHORT>(_width - 1), static_cast<SHORT>(_height - 1) };
    if (!SetConsoleWindowInfo(H_Console, TRUE, &WindowSize)) {
        std::cerr << "Failed to set console window size. Error: " << GetLastError() << "\n";
        return;
    }

    std::cout << "Console buffer size set to " << _width << "x" << _height << "\n";
}

void CGameInstance::DisableConsoleResize()
{
	// Get Console Handle
	HWND HwndConsole = GetConsoleWindow();

	// Get Window Style
	LONG Style = GetWindowLong(HwndConsole, GWL_STYLE);

	Style &= ~WS_SIZEBOX; // disable resizing window
	Style &= ~WS_MAXIMIZEBOX; // disable maximazebox
	SetWindowLong(HwndConsole, GWL_STYLE, Style);
}
