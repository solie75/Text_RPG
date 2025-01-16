#include "pch.h"
#include "CGameInstance.h"
#include "CKeyManager.h"
#include "CTimeManager.h"
#include "CStageManager.h"
#include "CStartStage.h"
#include "CChurchStage.h"
//#include "CStateStage.h"
//#include "CEndingStage.h"
//#include "CDungeonEntranceStage.h."

CGameInstance::CGameInstance()
	: ConsoleWidth(200)
	, ConsoleHeight(50)
{
};
CGameInstance::~CGameInstance() {};

void CGameInstance::GameInstInit()
{
	HideCursor();
	DisableMouseInput();
	SetConsoleWindowSize(ConsoleWidth, ConsoleHeight);
	DisableConsoleResize();

	HWND HwndConsole = GetConsoleWindow();
	SetForegroundWindow(HwndConsole);
	SetFocus(HwndConsole);

	CTimeManager::GetInst()->TimeManagerInit();
	CKeyManager::GetInst()->KeyManagerInit();
	CStageManager::GetInst()->StageManagerInit();
	//CStageManager::GetInst()->ChangeStage(new CStartStage);
	//CStageManager::GetInst()->ChangeStage(new CStateStage);
	CStageManager::GetInst()->ChangeStage(new CChurchStage);
	//CStageManager::GetInst()->ChangeStage(new CDungeonEntranceStage);
	//CStageManager::GetInst()->ChangeStage(new CEndingStage);
}

void CGameInstance::GameInstTick()
{
	CTimeManager::GetInst()->TimeManagerTick();
	CKeyManager::GetInst()->KeyManagerTick();
	CStageManager::GetInst()->StageManagerTick();
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

void CGameInstance::HideCursor()
{
	// 콘솔 핸들 가져오기
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE) {
		std::cerr << "Invalid console handle.\n";
		return;
	}

	// 콘솔 커서 정보 가져오기
	CONSOLE_CURSOR_INFO cursorInfo;
	if (!GetConsoleCursorInfo(hConsole, &cursorInfo)) {
		std::cerr << "Failed to get console cursor info.\n";
		return;
	}

	// 커서 숨기기
	cursorInfo.bVisible = FALSE; // 커서 비활성화
	if (!SetConsoleCursorInfo(hConsole, &cursorInfo)) {
		std::cerr << "Failed to set console cursor info.\n";
	}
}

void CGameInstance::DisableMouseInput()
{
	// 콘솔 입력 핸들 가져오기
	HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
	if (hConsoleInput == INVALID_HANDLE_VALUE) {
		std::cerr << "Failed to get console input handle." << std::endl;
		return;
	}

	// 현재 콘솔 모드 가져오기
	DWORD consoleMode;
	if (!GetConsoleMode(hConsoleInput, &consoleMode)) {
		std::cerr << "Failed to get console mode. Error: " << GetLastError() << std::endl;
		return;
	}

	// 마우스 입력 비활성화
	consoleMode &= ~ENABLE_MOUSE_INPUT; // 마우스 입력 플래그 제거
	consoleMode &= ~ENABLE_QUICK_EDIT_MODE; // 드래그를 통한 Quick Edit 모드 비활성화
	consoleMode |= ENABLE_EXTENDED_FLAGS;   // 확장 플래그 활성화

	// 수정된 모드 설정
	if (!SetConsoleMode(hConsoleInput, consoleMode)) {
		std::cerr << "Failed to set console mode. Error: " << GetLastError() << std::endl;
		return;
	}
}
