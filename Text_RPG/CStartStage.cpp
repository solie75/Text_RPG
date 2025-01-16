#include "pch.h"
#include <regex>
#include <conio.h>
#include <Windows.h>
#include "CStartStage.h"
#include "CKeyManager.h"
#include "CStageManager.h"
#include "CDungeonEntranceStage.h"
#include "CPlayer.h"

void CStartStage::StageInit()
{

}

void CStartStage::StageTick()
{
	if (bCallRender)
	{
		StageRender();
		bCallRender = false;
	}

	if (bMessiveScolling)
	{
		fAccumulatedTime += GlobalData.DeltaTime;
		if (fAccumulatedTime > fMissiveScollingTime)
		{
			++iCurMissivePart;
			if (iCurMissivePart > 13)
			{
				iCurMissivePart = 13;
				bMessiveScolling = false;
			}
			bCallRender = true;
			fAccumulatedTime = 0.f;
		}
	}
	else
	{
		if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::SPACE) == KEY_STATE::TAP)
		{
			if (iCurMissivePart == 0 && CurScene == START_SCENE::TUTORIAL)
			{
				bMessiveScolling = true;
			}
			else if (iCurMissivePart == 14)
			{
				CStageManager::GetInst()->ChangeStage(new CDungeonEntranceStage);
			}
			else
			{
				ChangeScene();
				bCallRender = true;
			}
		}
		else
		{
			fAccumulatedTime += GlobalData.DeltaTime;
			if (iCurMissivePart == 13 && fAccumulatedTime > (fNoticeTextDurationTime / 4.0f))
			{
				iCurMissivePart = 14;
				bCallRender = true;
				fAccumulatedTime = 0.f;
			}
			else if (iCurMissivePart == 14 && fAccumulatedTime > fNoticeTextDurationTime)
			{
				iCurMissivePart = 13;
				bCallRender = true;
				fAccumulatedTime = 0.f;
			}
		}
	}
}

void CStartStage::StageRender()
{
	std::cout << "\033[2J\033[H";
	switch (CurScene)
	{
	case START_SCENE::START:
		StartScene();
		bCallRender = true;
		break;
	case START_SCENE::TUTORIAL:
		TutorialScene();
		bCallRender = true;
		break;
	}
}

void CStartStage::ChangeScene()
{
	switch (CurScene)
	{
	case START_SCENE::START:
		CurScene = START_SCENE::TUTORIAL;
		break;
	case START_SCENE::TUTORIAL:
		CStageManager::GetInst()->ChangeStage(new CDungeonEntranceStage());
		break;
	}
}

void CStartStage::StartScene()
{
	string PlayerID;
	CPlayer* Player = CPlayer::GetInst();
	WelcomeMessage();
	printf("                                                                               Please type your PlayerID and Press Enter                                                                                \n");
	printf("                                                                            ( alphabet and numbers / 10 characters or less )                                                                            \n");
	printf("                                                                                               ");
	
	do
	{
		PlayerID = GetInputID();
	} while (PlayerID == "");
	
	Player->SetName(PlayerID);

	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                       Press Space Bar to Start!                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	}

void CStartStage::TutorialScene()
{
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("□                                                                                                                                                                                                    □\n"); // 1
	printf("□                                                                                                                                                                                                    □\n"); // 2
	printf("□                                                                                                                                                                                                    □\n"); // 3
	printf("□                                       /$$$$$$$  /$$$$$$ /$$     /$$/$$$$$$ /$$             /$$      /$$/$$$$$$ /$$$$$$  /$$$$$$ /$$$$$$/$$    /$$/$$$$$$$$                                         □\n"); // 4
	printf("□                                      | $$__  $$/$$__  $|  $$   /$$/$$__  $| $$            | $$$    /$$|_  $$_//$$__  $$/$$__  $|_  $$_| $$   | $| $$_____/                                         □\n"); // 5
	printf("□                                      | $$  \\ $| $$  \\ $$\\  $$ /$$| $$  \\ $| $$            | $$$$  /$$$$ | $$ | $$  \\__| $$  \\__/ | $$ | $$   | $| $$                                               □\n"); // 6
	printf("□                                      | $$$$$$$| $$  | $$ \\  $$$$/| $$$$$$$| $$            | $$ $$/$$ $$ | $$ |  $$$$$$|  $$$$$$  | $$ |  $$ / $$| $$$$$                                            □\n"); // 7
	printf("□                                      | $$__  $| $$  | $$  \\  $$/ | $$__  $| $$            | $$  $$$| $$ | $$  \\____  $$\\____  $$ | $$  \\  $$ $$/| $$__/                                            □\n"); // 8
	printf("□                                      | $$  \\ $| $$  | $$   | $$  | $$  | $| $$            | $$\\  $ | $$ | $$  /$$  \\ $$/$$  \\ $$ | $$   \\  $$$/ | $$                                               □\n"); // 9
	printf("□                                      | $$  | $|  $$$$$$/   | $$  | $$  | $| $$$$$$$$      | $$ \\/  | $$/$$$$$|  $$$$$$|  $$$$$$//$$$$$$  \\  $/  | $$$$$$$$                                         □\n"); // 10
	printf("□                                      |__/  |__/\\______/    |__/  |__/  |__|________/      |__/     |__|______/\\______/ \\______/|______/   \\_/   |________/                                         □\n"); // 11
	switch (iCurMissivePart)
	{
	case 0:
		MessivePart0();
		break;
	case 1:
		MessivePart1();
		break;
	case 2:
		MessivePart2();
		break;
	case 3:
		MessivePart3();
		break;
	case 4:
		MessivePart4();
		break;
	case 5:
		MessivePart5();
		break;
	case 6:
		MessivePart6();
		break;
	case 7:
		MessivePart7();
		break;
	case 8:
		MessivePart8();
		break;
	case 9:
		MessivePart9();
		break;
	case 10:
		MessivePart10();
		break;
	case 11:
		MessivePart11();
		break;
	case 12:
		MessivePart12();
		break;
	case 13:
		MessivePart13();
		break;
	case 14:
		MessivePart14();
		break;
	}
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
}

void CStartStage::WelcomeMessage()
{
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                               _     _  _______  ___      ___      _______  _______  __   __  _______  __                                                               \n");
	printf("                                                              | | _ | ||       ||   |    |   |    |       ||       ||  |_|  ||       ||  |                                                              \n");
	printf("                                                              | || || ||    ___||   |    |   |    |      _||   _   ||       ||    ___||  |                                                              \n");
	printf("                                                              |       ||   |___ |   |    |   |    |     |  |  | |  ||       ||   |___ |  |                                                              \n");
	printf("                                                              |       ||    ___||   |___ |   |___ |     |_ |  |_|  ||       ||    ___||__|                                                              \n");
	printf("                                                              |   _   ||   |___ |       ||       ||       ||       || ||_|| ||   |___  __                                                               \n");
	printf("                                                              |__| |__||_______||_______||_______||_______||_______||_|   |_||_______||__|                                                              \n");
	printf("                                                                                __   __  _______  ______    _______  __                                                                                 \n");
	printf("                                                                               |  | |  ||       ||    _ |  |       ||  |                                                                                \n");
	printf("                                                                               |  |_|  ||    ___||   | ||  |   _   ||  |                                                                                \n");
	printf("                                                                               |       ||   |___ |   |_||_ |  | |  ||  |                                                                                \n");
	printf("                                                                               |       ||    ___||    __  ||  |_|  ||__|                                                                                \n");
	printf("                                                                               |   _   ||   |___ |   |  | ||       | __                                                                                 \n");
	printf("                                                                               |__| |__||_______||___|  |_||_______||__|                                                                                \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");

}

void CStartStage::PressAgainIDPart()
{
	system("cls");
	WelcomeMessage();
	printf("                                                                              Please enter a word of 10 characters or less                                                                              \n");
	printf("                                                                                    Using only alphabets and numbers                                                                                    \n");
	printf("                                                                                             ");
}

string CStartStage::GetInputID()
{
	int cnt = 0;
	string ID = "";
	std::regex e("[a-zA-Z0-9]+");

	while (1)
	{
		if (cnt > CPlayer::GetInst()->GetMaxNameLength())
		{
			PressAgainIDPart();
			cnt = 0;
		}

		char c = _getch();

		switch (c)
		{
		case 3: // exit
			return "exit";
		case 13: // press enter
			return ID;
		default:
			break;
		}

		ID.push_back(c);

		//if korean -> 2byte
		if (_kbhit()) {
			c = _getch();
			ID.push_back(c);
		}

		//no alphabets and numbers
		if(!std::regex_match(ID, e))
		{ 
			PressAgainIDPart();
			cnt = 0;
			ID = "";
			continue;
		}

		printf("%c", c);
		cnt++;
	}
	return ID;
}

void CStartStage::MessivePart0()
{
	printf("□                                                                                                                                                                                                    □\n"); // 12
	printf("□                                                                                                                                                                                                    □\n"); // 13
	printf("□                                                                                                                                                                                                    □\n"); // 14
	printf("□                                                                                                                                                                                                    □\n"); // 15
	printf("□                                                                                                                                                                                                    □\n"); // 16
	printf("□                                                                                                                                                                                                    □\n"); // 17
	printf("□                                                                                                                                                                                                    □\n"); // 18
	printf("□                                                                                                                                                                                                    □\n"); // 19
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                             ___________________________________________________________________________________________________                                                    □\n"); // 
	printf("□                                            (                                                                                                   )                                                   □\n"); // 
	printf("□                                           /|\\                                                                                                   \\                                                  □\n"); // 
	printf("□                                        ()==) )                                                                                                  |@==()                                             □\n"); // 
	printf("□                                           \\|/                                                                                                   /                                                  □\n"); // 
	printf("□                                            (___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                           ( ___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                          /|\\                                                                                                    \\                                                  □\n"); // 
	printf("□                                       ()==) )                                                                                                   |@==()                                             □\n"); // 
	printf("□                                          \\|/                                                                                                    /                                                  □\n"); // 
	printf("□                                           (____________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                              press space bar to open scroll                                                                                        □\n");
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
}

void CStartStage::MessivePart1()
{
	printf("□                                                                                                                                                                                                    □\n"); // 12
	printf("□                                                                                                                                                                                                    □\n"); // 13
	printf("□                                                                                                                                                                                                    □\n"); // 14
	printf("□                                                                                                                                                                                                    □\n"); // 15
	printf("□                                                                                                                                                                                                    □\n"); // 16
	printf("□                                                                                                                                                                                                    □\n"); // 17
	printf("□                                                                                                                                                                                                    □\n"); // 18
	printf("□                                                                                                                                                                                                    □\n"); // 19
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                             ___________________________________________________________________________________________________                                                    □\n"); // 
	printf("□                                            (                                                                                                   )                                                   □\n"); // 
	printf("□                                           /|\\                                                                                                   \\                                                  □\n"); // 
	printf("□                                        ()==) )                                                                                                  |@==()                                             □\n"); // 
	printf("□                                           \\|/                                                                                                   /                                                  □\n"); // 
	printf("□                                            (___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                           ( ___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                          /|\\                                                                                                    \\                                                  □\n"); // 
	printf("□                                       ()==) )                                                                                                   |@==()                                             □\n"); // 
	printf("□                                          \\|/                                                                                                    /                                                  □\n"); // 
	printf("□                                           (____________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
}

void CStartStage::MessivePart2()
{
	printf("□                                                                                                                                                                                                    □\n"); // 12
	printf("□                                                                                                                                                                                                    □\n"); // 13
	printf("□                                                                                                                                                                                                    □\n"); // 14
	printf("□                                                                                                                                                                                                    □\n"); // 15
	printf("□                                                                                                                                                                                                    □\n"); // 16
	printf("□                                                                                                                                                                                                    □\n"); // 17
	printf("□                                                                                                                                                                                                    □\n"); // 18
	printf("□                                                                                                                                                                                                    □\n"); // 19
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                             ___________________________________________________________________________________________________                                                    □\n"); // 
	printf("□                                            (                                                                                                   )                                                   □\n"); // 
	printf("□                                           /|\\                                                                                                   \\                                                  □\n"); // 
	printf("□                                        ()==) )                                                                                                  |@==()                                             □\n"); // 
	printf("□                                           \\|/                                                                                                   /                                                  □\n"); // 
	printf("□                                            (___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                           ( ___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                          /|\\                                                                                                    \\                                                  □\n"); // 
	printf("□                                       ()==) )                                                                                                   |@==()                                             □\n"); // 
	printf("□                                          \\|/                                                                                                    /                                                  □\n"); // 
	printf("□                                           (____________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
}

void CStartStage::MessivePart3()
{
	printf("□                                                                                                                                                                                                    □\n"); // 12
	printf("□                                                                                                                                                                                                    □\n"); // 13
	printf("□                                                                                                                                                                                                    □\n"); // 14
	printf("□                                                                                                                                                                                                    □\n"); // 15
	printf("□                                                                                                                                                                                                    □\n"); // 16
	printf("□                                                                                                                                                                                                    □\n"); // 17
	printf("□                                                                                                                                                                                                    □\n"); // 18
	printf("□                                                                                                                                                                                                    □\n"); // 19
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                             ___________________________________________________________________________________________________                                                    □\n"); // 
	printf("□                                            (                                                                                                   )                                                   □\n"); // 
	printf("□                                           /|\\                                                                                                   \\                                                  □\n"); // 
	printf("□                                        ()==) )                                                                                                  |@==()                                             □\n"); // 
	printf("□                                           \\|/                                                                                                   /                                                  □\n"); // 
	printf("□                                            (___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                           ( ___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                          /|\\                                                                                                    \\                                                  □\n"); // 
	printf("□                                       ()==) )                                                                                                   |@==()                                             □\n"); // 
	printf("□                                          \\|/                                                                                                    /                                                  □\n"); // 
	printf("□                                           (____________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
}

void CStartStage::MessivePart4()
{
	printf("□                                                                                                                                                                                                    □\n"); // 12
	printf("□                                                                                                                                                                                                    □\n"); // 13
	printf("□                                                                                                                                                                                                    □\n"); // 14
	printf("□                                                                                                                                                                                                    □\n"); // 15
	printf("□                                                                                                                                                                                                    □\n"); // 16
	printf("□                                                                                                                                                                                                    □\n"); // 17
	printf("□                                                                                                                                                                                                    □\n"); // 18
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                             ___________________________________________________________________________________________________                                                    □\n"); // 
	printf("□                                            (                                                                                                   )                                                   □\n"); // 
	printf("□                                           /|\\                                                                                                   \\                                                  □\n"); // 
	printf("□                                        ()==) )                                                                                                  |@==()                                             □\n"); // 
	printf("□                                           \\|/                                                                                                   /                                                  □\n"); // 
	printf("□                                            (___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                           ( ___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                          /|\\                                                                                                    \\                                                  □\n"); // 
	printf("□                                       ()==) )                                                                                                   |@==()                                             □\n"); // 
	printf("□                                          \\|/                                                                                                    /                                                  □\n"); // 
	printf("□                                           (____________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
}

void CStartStage::MessivePart5()
{
	printf("□                                                                                                                                                                                                    □\n"); // 12
	printf("□                                                                                                                                                                                                    □\n"); // 13
	printf("□                                                                                                                                                                                                    □\n"); // 14
	printf("□                                                                                                                                                                                                    □\n"); // 15
	printf("□                                                                                                                                                                                                    □\n"); // 17
	printf("□                                                                                                                                                                                                    □\n"); // 18
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                             ___________________________________________________________________________________________________                                                    □\n"); // 
	printf("□                                            (                                                                                                   )                                                   □\n"); // 
	printf("□                                           /|\\                                                                                                   \\                                                  □\n"); // 
	printf("□                                        ()==) )                                                                                                  |@==()                                             □\n"); // 
	printf("□                                           \\|/                                                                                                   /                                                  □\n"); // 
	printf("□                                            (___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                           ( ___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                          /|\\                                                                                                    \\                                                  □\n"); // 
	printf("□                                       ()==) )                                                                                                   |@==()                                             □\n"); // 
	printf("□                                          \\|/                                                                                                    /                                                  □\n"); // 
	printf("□                                           (____________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
}

void CStartStage::MessivePart6()
{
	printf("□                                                                                                                                                                                                    □\n"); // 12
	printf("□                                                                                                                                                                                                    □\n"); // 13
	printf("□                                                                                                                                                                                                    □\n"); // 14
	printf("□                                                                                                                                                                                                    □\n"); // 15
	printf("□                                                                                                                                                                                                    □\n"); // 17
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                             ___________________________________________________________________________________________________                                                    □\n"); // 
	printf("□                                            (                                                                                                   )                                                   □\n"); // 
	printf("□                                           /|\\                                                                                                   \\                                                  □\n"); // 
	printf("□                                        ()==) )                                                                                                  |@==()                                             □\n"); // 
	printf("□                                           \\|/                                                                                                   /                                                  □\n"); // 
	printf("□                                            (___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                           ( ___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                          /|\\                                                                                                    \\                                                  □\n"); // 
	printf("□                                       ()==) )                                                                                                   |@==()                                             □\n"); // 
	printf("□                                          \\|/                                                                                                    /                                                  □\n"); // 
	printf("□                                           (____________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
}

void CStartStage::MessivePart7()
{
	printf("□                                                                                                                                                                                                    □\n"); // 12
	printf("□                                                                                                                                                                                                    □\n"); // 13
	printf("□                                                                                                                                                                                                    □\n"); // 14
	printf("□                                                                                                                                                                                                    □\n"); // 15
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                             ___________________________________________________________________________________________________                                                    □\n"); // 
	printf("□                                            (                                                                                                   )                                                   □\n"); // 
	printf("□                                           /|\\                                                                                                   \\                                                  □\n"); // 
	printf("□                                        ()==) )                                                                                                  |@==()                                             □\n"); // 
	printf("□                                           \\|/                                                                                                   /                                                  □\n"); // 
	printf("□                                            (___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                           ( ___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                          /|\\                                                                                                    \\                                                  □\n"); // 
	printf("□                                       ()==) )                                                                                                   |@==()                                             □\n"); // 
	printf("□                                          \\|/                                                                                                    /                                                  □\n"); // 
	printf("□                                           (____________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
}

void CStartStage::MessivePart8()
{
	printf("□                                                                                                                                                                                                    □\n"); // 12
	printf("□                                                                                                                                                                                                    □\n"); // 13
	printf("□                                                                                                                                                                                                    □\n"); // 14
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                             ___________________________________________________________________________________________________                                                    □\n"); // 
	printf("□                                            (                                                                                                   )                                                   □\n"); // 
	printf("□                                           /|\\                                                                                                   \\                                                  □\n"); // 
	printf("□                                        ()==) )                                                                                                  |@==()                                             □\n"); // 
	printf("□                                           \\|/                                                                                                   /                                                  □\n"); // 
	printf("□                                            (___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                           ( ___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                          /|\\                                                                                                    \\                                                  □\n"); // 
	printf("□                                       ()==) )                                                                                                   |@==()                                             □\n"); // 
	printf("□                                          \\|/                                                                                                    /                                                  □\n"); // 
	printf("□                                           (____________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
}

void CStartStage::MessivePart9()
{
	printf("□                                                                                                                                                                                                    □\n"); // 12
	printf("□                                                                                                                                                                                                    □\n"); // 13
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                             ___________________________________________________________________________________________________                                                    □\n"); // 
	printf("□                                            (                                                                                                   )                                                   □\n"); // 
	printf("□                                           /|\\                                                                                                   \\                                                  □\n"); // 
	printf("□                                        ()==) )                                                                                                  |@==()                                             □\n"); // 
	printf("□                                           \\|/                                                                                                   /                                                  □\n"); // 
	printf("□                                            (___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                           ( ___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                          /|\\                                                                                                    \\                                                  □\n"); // 
	printf("□                                       ()==) )                                                                                                   |@==()                                             □\n"); // 
	printf("□                                          \\|/                                                                                                    /                                                  □\n"); // 
	printf("□                                           (____________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
}

void CStartStage::MessivePart10()
{
	printf("□                                                                                                                                                                                                    □\n"); // 12
	printf("□                                                                                                                                                                                                    □\n"); // 13
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                             ___________________________________________________________________________________________________                                                    □\n"); // 
	printf("□                                            (                                                                                                   )                                                   □\n"); // 
	printf("□                                           /|\\                                                                                                   \\                                                  □\n"); // 
	printf("□                                        ()==) )                                                                                                  |@==()                                             □\n"); // 
	printf("□                                           \\|/                                                                                                   /                                                  □\n"); // 
	printf("□                                            (___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                           ( ___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                          /|\\                                                                                                    \\                                                  □\n"); // 
	printf("□                                       ()==) )                                                                                                   |@==()                                             □\n"); // 
	printf("□                                          \\|/                                                                                                    /                                                  □\n"); // 
	printf("□                                           (____________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
}

void CStartStage::MessivePart11()
{
	printf("□                                                                                                                                                                                                    □\n"); // 12
	printf("□                                                                                                                                                                                                    □\n"); // 13
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                             ___________________________________________________________________________________________________                                                    □\n"); // 
	printf("□                                            (                                                                                                   )                                                   □\n"); // 
	printf("□                                           /|\\                                                                                                   \\                                                  □\n"); // 
	printf("□                                        ()==) )                                                                                                  |@==()                                             □\n"); // 
	printf("□                                           \\|/                                                                                                   /                                                  □\n"); // 
	printf("□                                            (___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                           ( ___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                          /|\\                                                                                                    \\                                                  □\n"); // 
	printf("□                                       ()==) )                                                                                                   |@==()                                             □\n"); // 
	printf("□                                          \\|/                                                                                                    /                                                  □\n"); // 
	printf("□                                           (____________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
}

void CStartStage::MessivePart12()
{
	printf("□                                                                                                                                                                                                    □\n"); // 12
	printf("□                                                                                                                                                                                                    □\n"); // 13
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                             ___________________________________________________________________________________________________                                                    □\n"); // 
	printf("□                                            (                                                                                                   )                                                   □\n"); // 
	printf("□                                           /|\\                                                                                                   \\                                                  □\n"); // 
	printf("□                                        ()==) )                                                                                                  |@==()                                             □\n"); // 
	printf("□                                           \\|/                                                                                                   /                                                  □\n"); // 
	printf("□                                            (___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                           ( ___________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                          /|\\                                                                                                    \\                                                  □\n"); // 
	printf("□                                       ()==) )                                                                                                   |@==()                                             □\n"); // 
	printf("□                                          \\|/                                                                                                    /                                                  □\n"); // 
	printf("□                                           (____________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
}

void CStartStage::MessivePart13()
{
	printf("□                                                                                                                                                                                                    □\n"); // 12
	printf("□                                                                                                                                                                                                    □\n"); // 13
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                             ___________________________________________________________________________________________________                                                    □\n"); // 
	printf("□                                            (                                                                                                   )                                                   □\n"); // 
	printf("□                                           /|\\                                                                                                   \\                                                  □\n"); // 
	printf("□                                        ()==) )><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><|@==()                                             □\n"); // 
	printf("□                                           \\|/                                                                                                   /                                                  □\n"); // 
	printf("□                                            (...................................................................................................)                                                   □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                     현재 공국은 마왕의 흉악한 주술로 인해 몬스터가 창궐하여,                   |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                           각 성과 도시, 촌락에 근심이 그칠 날이 없다.                          |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |            이에 본국은 몬스터를 토벌하고, 마왕을 소멸시키기 위해 용사를 선발하고자 한다.       |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |          지원하는 자에게는 본 칙서와 체력이 1이 되면 장소를 벗어나는 아티팩터를 수여한다.      |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                             용사 후보들은 즉시 지정된 지역으로 향해,             |             |                                                      □\n"); // 
	printf("□                                            |                                                                                  |             |                                                      □\n"); // 
	printf("□                                            |                                     영웅의 자격을 증명하라!                      +\\            |                                                      □\n"); // 
	printf("□                                            |                                                                                  \\\\.G_.*=.     |                                                      □\n"); //
	printf("□                                            |                           그대들의 힘이 공국의 운명을 결정지을 것이다.             `( '/.\\|    |                                                      □\n"); // 
	printf("□                                            |                                                                                   .>' (_--.    |                                                      □\n"); // 
	printf("□                                            |                                                                                _=/d   ,^\\      |                                                      □\n"); // 
	printf("□                                            |                                                                               ~~ \\)-'   '      |                                                      □\n"); // 
	printf("□                                            |                                                                                  / |           |                                                      □\n"); // 
	printf("□                                            |                                                                                  '  '          |                                                      □\n"); // 
	printf("□                                           ( ```````````````````````````````````````````````````````````````````````````````````````````````````)                                                   □\n"); // 
	printf("□                                          /|\\                                                                                                    \\                                                  □\n"); // 
	printf("□                                       ()==) )><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>|@==()                                             □\n"); // 
	printf("□                                          \\|/                                                                                                    /                                                  □\n"); // 
	printf("□                                           (____________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); //  
}
void CStartStage::MessivePart14()
{
	printf("□                                                                                                                                                                                                    □\n"); // 12
	printf("□                                                                                                                                                                                                    □\n"); // 13
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                             ___________________________________________________________________________________________________                                                    □\n"); // 
	printf("□                                            (                                                                                                   )                                                   □\n"); // 
	printf("□                                           /|\\                                                                                                   \\                                                  □\n"); // 
	printf("□                                        ()==) )><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><|@==()                                             □\n"); // 
	printf("□                                           \\|/                                                                                                   /                                                  □\n"); // 
	printf("□                                            (...................................................................................................)                                                   □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                     현재 공국은 마왕의 흉악한 주술로 인해 몬스터가 창궐하여,                   |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                           각 성과 도시, 촌락에 근심이 그칠 날이 없다.                          |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |            이에 본국은 몬스터를 토벌하고, 마왕을 소멸시키기 위해 용사를 선발하고자 한다.       |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |          지원하는 자에게는 본 칙서와 체력이 1이 되면 장소를 벗어나는 아티팩터를 수여한다.      |                                                      □\n"); // 
	printf("□                                            |                                                                                                |                                                      □\n"); // 
	printf("□                                            |                             용사 후보들은 즉시 지정된 지역으로 향해,             |             |                                                      □\n"); // 
	printf("□                                            |                                                                                  |             |                                                      □\n"); // 
	printf("□                                            |                                     영웅의 자격을 증명하라!                      +\\            |                                                      □\n"); // 
	printf("□                                            |                                                                                  \\\\.G_.*=.     |                                                      □\n"); //
	printf("□                                            |                           그대들의 힘이 공국의 운명을 결정지을 것이다.             `( '/.\\|    |                                                      □\n"); // 
	printf("□                                            |                                                                                   .>' (_--.    |                                                      □\n"); // 
	printf("□                                            |                                                                                _=/d   ,^\\      |                                                      □\n"); // 
	printf("□                                            |                                 Press Space Bar to go Dungeon!                ~~ \\)-'   '      |                                                      □\n"); // 
	printf("□                                            |                                                                                  / |           |                                                      □\n"); // 
	printf("□                                            |                                                                                  '  '          |                                                      □\n"); // 
	printf("□                                           ( ```````````````````````````````````````````````````````````````````````````````````````````````````)                                                   □\n"); // 
	printf("□                                          /|\\                                                                                                    \\                                                  □\n"); // 
	printf("□                                       ()==) )><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>|@==()                                             □\n"); // 
	printf("□                                          \\|/                                                                                                    /                                                  □\n"); // 
	printf("□                                           (____________________________________________________________________________________________________)                                                   □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
	printf("□                                                                                                                                                                                                    □\n"); // 
}