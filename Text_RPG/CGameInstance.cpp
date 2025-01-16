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

    // ���� ũ�� ����
    COORD BufferSize = { static_cast<SHORT>(_width), static_cast<SHORT>(_height) };
    if (!SetConsoleScreenBufferSize(H_Console, BufferSize)) {
        std::cerr << "Failed to set console buffer size. Error: " << GetLastError() << "\n";
        return;
    }

    // â ũ�� ����
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
	// �ܼ� �ڵ� ��������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE) {
		std::cerr << "Invalid console handle.\n";
		return;
	}

	// �ܼ� Ŀ�� ���� ��������
	CONSOLE_CURSOR_INFO cursorInfo;
	if (!GetConsoleCursorInfo(hConsole, &cursorInfo)) {
		std::cerr << "Failed to get console cursor info.\n";
		return;
	}

	// Ŀ�� �����
	cursorInfo.bVisible = FALSE; // Ŀ�� ��Ȱ��ȭ
	if (!SetConsoleCursorInfo(hConsole, &cursorInfo)) {
		std::cerr << "Failed to set console cursor info.\n";
	}
}

void CGameInstance::DisableMouseInput()
{
	// �ܼ� �Է� �ڵ� ��������
	HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
	if (hConsoleInput == INVALID_HANDLE_VALUE) {
		std::cerr << "Failed to get console input handle." << std::endl;
		return;
	}

	// ���� �ܼ� ��� ��������
	DWORD consoleMode;
	if (!GetConsoleMode(hConsoleInput, &consoleMode)) {
		std::cerr << "Failed to get console mode. Error: " << GetLastError() << std::endl;
		return;
	}

	// ���콺 �Է� ��Ȱ��ȭ
	consoleMode &= ~ENABLE_MOUSE_INPUT; // ���콺 �Է� �÷��� ����
	consoleMode &= ~ENABLE_QUICK_EDIT_MODE; // �巡�׸� ���� Quick Edit ��� ��Ȱ��ȭ
	consoleMode |= ENABLE_EXTENDED_FLAGS;   // Ȯ�� �÷��� Ȱ��ȭ

	// ������ ��� ����
	if (!SetConsoleMode(hConsoleInput, consoleMode)) {
		std::cerr << "Failed to set console mode. Error: " << GetLastError() << std::endl;
		return;
	}
}
