#include "pch.h"
#include "CChurchStage.h"
#include "CKeyManager.h"
#include "CStageManager.h"
#include "CVillageStage.h"
#include "CPlayer.h"

void SetConsoleColor(WORD color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
	SetConsoleTextAttribute(hConsole, color);         // 색상 속성 설정
}

CChurchStage::CChurchStage()
{
	//bool b = CStageManager::GetInst()->GetIsDoneTutoStage();
	if (CStageManager::GetInst()->GetIsDoneTutoStage())
	{
		iCurTextPart = 9;
	}
	else
	{
		
	}
	if (!CPlayer::GetInst()->GetBoolHealAccess())
	{
		iCurTextPart = 12;
	}
}

CChurchStage::~CChurchStage()
{
}

void CChurchStage::StageTick()
{
	if (bCallRender)
	{
		StageRender();
		bCallRender = false;
	}

	if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::SPACE) == KEY_STATE::TAP)
	{
		if (iCurTextPart == 12)
		{
			CStageManager::GetInst()->ChangeStage(new CVillageStage);
			CPlayer::GetInst()->SetBoolHealAccess(false);
		}

 		if (iCurTextPart != 11)
		{
			++iCurTextPart;
			bCallRender = true;
		}

		

		/*if (!CStageManager::GetInst()->GetIsDoneTutoStage())
		{
			if (iCurTextPart < 9)
			{
				++iCurTextPart;
				bCallRender = true;
			}
		}*/
	}

	if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::C) == KEY_STATE::TAP && iCurTextPart == 11)
	{
		// 보유 재화 지불 및 회복
		CPlayer::GetInst()->Church_Heal();
		++iCurTextPart;
		bCallRender = true;
	}

	if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::ESC) == KEY_STATE::TAP)
	{
		CStageManager::GetInst()->ChangeStage(new CVillageStage);
	}
}

void CChurchStage::StageInit()
{
}

void CChurchStage::StageRender()
{
	std::cout << "\033[2J\033[H";

	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");

	if (!CStageManager::GetInst()->GetIsDoneTutoStage() && iCurTextPart < 9)
	{
		FirstChurchRender();
		printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
		return;
	}

	if (CPlayer::GetInst()->GetBoolHealAccess())
	{
		BasicRender();
		switch (iCurTextPart)
		{
		case 9:
			TextPart1();
			break;
		case 10:
			TextPart2();
			break;
		case 11:
 			TextPart3();
			break;
		case 12:
			TextPart4();
			break;
		}
	}
	else
	{
		NoAccessToHealRender();
		TextPart5();
	}
	printf("□                         |\\|  | /|                                                                                                                                   |\\  | |/|                      □\n"); // 44
	if (iCurTextPart < 11 && CPlayer::GetInst()->GetBoolHealAccess())
	{
		printf("□                         | `---' |                                                                                                           Press Space Bar         | `---' |                      □\n"); // 45
	}
	else
	{
		printf("□                         | `---' |                                                                                                                                   | `---' |                      □\n"); // 45
	}
	
	printf("□                         |       |___________________________________________________________________________________________________________________________________|       |                      □\n"); // 46
	printf("□                          \\_____/                                                                                                                                     \\_____/                       □\n"); // 47
	printf("□                                                                                                                                                                                                    □\n"); // 48
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
}

void CChurchStage::BasicRender()
{																																						                          
	printf("□                                                                                                                                                                                                    □\n"); //2
	printf("□"); SetConsoleColor(6); printf("               \   |   /   "); SetConsoleColor(7); printf("                                                                                             -=-                                                                          □\n"); //3
	printf("□"); SetConsoleColor(6); printf("                 .---.     "); SetConsoleColor(7); printf("                                                                                         (\\  _  /)                                                                       □\n"); //4
	printf("□"); SetConsoleColor(6); printf("            '-.  |   |  .-'"); SetConsoleColor(7); printf("                                                                                         ( \\( )/ )                                                                       □\n"); //5
	printf("□"); SetConsoleColor(6); printf("              ___|   |___  "); SetConsoleColor(7); printf("   :.     --.    .... .    @@ @@@@@                                                      (       )                                                                       □\n"); //6
	printf("□"); SetConsoleColor(6); printf("         -=  [           ] "); SetConsoleColor(7); printf("  -      +.              @@ @@@ * @-                                                      `>   <'                                                                        □\n"); //7
	printf("□"); SetConsoleColor(6); printf("             `---.   .---' "); SetConsoleColor(7); printf("    =          #    .   =@@@@@     @                                                      /     \\                                                                        □\n"); //8
	printf("□"); SetConsoleColor(6); printf("                 |   |     "); SetConsoleColor(7); printf(" :    +                   @@+@    @                                                       `-._.-'                                                                        □\n"); //9
	printf("□"); SetConsoleColor(6); printf("                 |   |     "); SetConsoleColor(7); printf("  .     =             .   .@   @@@                                                                                                                                       □\n"); //10
	printf("□"); SetConsoleColor(6); printf("                 |   |     "); SetConsoleColor(7); printf("   :      =         .    @@    @                                                                                                                                         □\n"); //11
	printf("□"); SetConsoleColor(6); printf("                 |   |     "); SetConsoleColor(7); printf(" $  .      ..          @   @=    @;$                                                                                                                                     □\n"); //12
	printf("□"); SetConsoleColor(6); printf("                 `````     "); SetConsoleColor(7); printf("     .       -     . #     @ @:    ;@$                                                                                                                                   □\n"); //13
	printf("□                             *   .        =   . @*#@. @  :@$  :=#                -=-                           _                                                                                    □\n"); //14
	printf("□                                  .             @  @@ @: * .* :@              (\\  _  /)                      (\\o/)                                                                                  □\n"); //14
	printf("□                     _      =    .             @ .@ *\=     =                  ( \\( )/ )                       /_\\                                                                                   □\n"); //15
	printf("□                   {\\o/}      :     .           -= @@  .@@@@@@@:              (       )                                                                                                             □\n"); //16
	printf("□                    /_\\             .          @  @  @@$=     =:@              `>   <'                                                                                                              □\n"); //17
	printf("□                               =      :        +- @   *:  +.:--@ =.            /     \\                                                                                                              □\n"); //18
	printf("□                                       .       @  @  @#   $ +- .@ =@           `-._.-'                                                                                                              □\n"); //19
	printf("□                                #       .      @ @  @=    = * :  @  -                                                                      .,_                                                      □\n"); //20
	printf("□                                               @ @  @.    .   @  - \\ @                                                                   (. - `,                                                    □\n"); //21
	printf("□                                 *              @ #  *    $ + .@  # # @                           _                                   _.-//-\\ _ )                                                   □\n"); //22
	printf("□      <^\\()/^>                                  @ @: @   $  -  @  =  @@                         (\\o/)                                |^-,_.--`|,\\._ __                                              □\n"); //23
	printf("□       \\/  \\/                      =             @@  @   =   @ @  -                              /_\\                                 ||\\_.-`| |_/ /'  `\\                                            □\n"); //24
	printf("□        /  \\                                         @ @   @ --  #                                                                   | \\ ,-`  |        \\                                            □\n"); //25
	printf("□        `''`                                   .    #.*   * -@  @.                                                                   | ||     |  `-.__/`.                                           □\n"); //26
	printf("□                                   :           .    .@   @  @   =$                                                                    \\||_. - r`     /    `-._                                      □\n"); //27
	printf("□                                                    @@ @   @#  *.@                                                                          `-/'    /         `-.                                   □\n"); //28
	printf("□                                    +              @ .    @@  @:==                                                                  _______,-/_   /'             \\                                  □\n"); //29
	printf("□              _          (`-.                    $ $    @ *  *  @:           .-')          _                                   --'`|       |`  ),' `---.  ,       |                                 □\n"); //30
	printf("□              \\`----.    ) ^_`)       +          @=*   @  @  @$ * *        (`_^ (    .----`/                                  \\..-`--..___|_,/          /       /                                   □\n"); //31
	printf("□       ,__     \\__   `\\_/  ( `                @$ -  @.  @  @$  * =          ` )  \\_/`   __/     __,                                    |    |`,-,...,/      ,'                                      □\n"); //32
	printf("□        \\_\\      \\__  `|   }        :      @+ @ @   @  @* $ @ @             __{   |`  __/      /_/                                     \\    |       /     ,' __  r-'',                              □\n"); //33
	printf("□          \\\\  .--' \\__/    }               @ .@    #  @.@.- +: @           / _{    \\__/ '--.  //                                       |___|/     /  __ /-''  `'`)  |                               □\n"); //34
	printf("□           ))/   \\__,<  /_/             $.@=   +@**@ *+ +  + $             \\_> \\_\\  >__/    \\((                                    _,-'    |    /,-' /     _,.--|  (                                □\n"); //35
	printf("□           ((|  _/_/ `\\ \\_\\_   .    .@@@@.  .@@@     $=+  $@@*                  _/ /` _\\_   |))                                  .-'       )   `(_   / _,.-'  ,-' _,/                               □\n"); //36
	printf("□            `\\_____\\\\  )__\\_\\     .+#-. ==#@. $    @@-   @@    @-              /__(  /______/`                                   `-------'       `--''       `'''                                   □\n"); //37
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n"); //38

	printf("□                                                                                                                                                                                                    □\n"); // 39
	printf("□                           _________________________________________________________________________________________________________________________________________________                        □\n"); // 40
	printf("□                          /  ___                                                                                                                                       ___  \\                       □\n"); // 41
	printf("□                         |  /   \\                                                                                                                                     /   \\  |                      □\n"); // 42
	
}

void CChurchStage::FirstChurchRender()
{
	printf("□                                                                                                                                                                                                    □\n"); // 1
	printf("□                                                                                                                                                                                                    □\n");	// 2
	printf("□                                                                                                                                                                                                    □\n");	// 3
	printf("□                                                                                                                                                                                                    □\n");	// 4
	printf("□                                                                                                                                                                                                    □\n");	// 5
	printf("□                                                                                                                                                                                                    □\n");	// 6
	printf("□                                                                                                                                                                                                    □\n");	// 7
	printf("□                                                                                                                                                                                                    □\n");	// 8
	printf("□                                                                                                                                                                                                    □\n");	// 9
	printf("□                                                                                                                                                                                                    □\n");	// 10
	printf("□                                                                                                                                                                                                    □\n");	// 1
	printf("□                                                                                                                                                                                                    □\n");	// 2
	printf("□                                                                                                                                                                                                    □\n");	// 3
	printf("□                                                                                                                                                                                                    □\n");	// 4
	printf("□                                                                                                                                                                                                    □\n");	// 5
	printf("□                                                                                                                                                                                                    □\n");	// 6
	printf("□                                                                                                                                                                                                    □\n");	// 7
	printf("□                                                                                                                                                                                                    □\n");	// 8
	printf("□                                                                                                                                                                                                    □\n");	// 9
	printf("□                                                                                                                                                                                                    □\n");	// 0
	printf("□                                                                                                                                                                                                    □\n");	// 1
	printf("□                                                                                                                                                                                                    □\n");	// 2
	printf("□                                                                                                                                                                                                    □\n");	// 3
	switch (iCurTextPart)
	{
	case 1:
		ToChurchTextPart1(); 
		break;
	case 2:
		ToChurchTextPart2();
		break;
	case 3:
		ToChurchTextPart3();
		break;
	case 4:
		ToChurchTextPart4();
		break;
	case 5:
		ToChurchTextPart5();
		break;
	case 6:
		ToChurchTextPart6();
		break;
	case 7:
		ToChurchTextPart7();
		break;
	case 8:
		ToChurchTextPart8();
		break;
	}

	printf("□                                                                                                                                                                                                    □\n");	// 5
	printf("□                                                                                                                                                                                                    □\n");	// 6
	printf("□                                                                                                                                                                                                    □\n");	// 7
	printf("□                                                                                                                                                                                                    □\n");	// 8
	printf("□                                                                                                                                                                                                    □\n");	// 9
	printf("□                                                                                                                                                                                                    □\n");	// 0
	printf("□                                                                                                                                                                                                    □\n");	// 1
	printf("□                                                                                                                                                                                                    □\n");	// 2
	printf("□                                                                                                                                                                                                    □\n");	// 3
	printf("□                                                                                                                                                                                                    □\n");	// 4
	printf("□                                                                                                                                                                                                    □\n");	// 5
	printf("□                                                                                                                                                                                                    □\n");	// 6
	printf("□                                                                                                                                                                                                    □\n");	// 7
	printf("□                                                                                                                                                                                                    □\n");	// 8
	printf("□                                                                                                                                                                                                    □\n");	// 9
	printf("□                                                                                                                                                                                                    □\n");	// 0
	printf("□                                                                                                                                                           Press Space Bar                          □\n");	// 1
	printf("□                                                                                                                                                                                                    □\n");	// 2
	printf("□                                                                                                                                                                                                    □\n");	// 3
	printf("□                                                                                                                                                                                                    □\n");	// 4
	printf("□                                                                                                                                                                                                    □\n");	// 5
	printf("□                                                                                                                                                                                                    □\n");	// 6
	printf("□                                                                                                                                                                                                    □\n");	// 7
	printf("□                                                                                                                                                                                                    □\n");	// 8
}

void CChurchStage::ToChurchTextPart1()
{
	printf("□                                                                             시야가 점점 흐려진다..... 이렇게 죽게 되는 걸까                                                                        □\n");	// 4
}

void CChurchStage::ToChurchTextPart2()
{
	printf("□                                                              몬스터가 코 앞까지 다가와 무기를 휘두르지만 움직일 힘이 남아있지 않다.                                                                □\n");	// 4
}

void CChurchStage::ToChurchTextPart3()
{
	printf("□                                                            머리가 뭉개지기 바로 직전 세상이 빙글 도는 듯 하더니 주변 환경이 달라져 있었다.                                                         □\n");	// 4
}

void CChurchStage::ToChurchTextPart4()
{
	printf("□                                                                                      아... 이게 그 아티팩트의 효과인가                                                                             □\n");	// 4
}

void CChurchStage::ToChurchTextPart5()
{
	printf("□                                                                  조금 정신을 차리자 멀리서 멧돼지 보다 빠르게 다가오는 사람이 보인다.                                                              □\n");	// 4
}

void CChurchStage::ToChurchTextPart6()
{
	printf("□                                                            그는 다급히 나를 흔들더니 신음소리에 놀라 연신 고개를 숙이고서 이내 업고 뛰기 시작했다.                                                 □\n");	// 4
}

void CChurchStage::ToChurchTextPart7()
{
	printf("□                                                숨을 헐떡이며 뛰는 와중에도 고개를 돌려가며 열심히 소리쳐 대는 모양이었지만 나는 알아듣지 못하고 잠들었다.                                          □\n");	// 4
}

void CChurchStage::ToChurchTextPart8()
{
	printf("□                                                                             용사님! 조금만 참으십쇼! 교회까지 금방 갑니다!!                                                                        □\n");	// 4
}

void CChurchStage::NoAccessToHealRender()
{
	printf("□                                                                                                                                                                                                    □\n"); //2
	printf("□                                                                                                                                                                                                    □\n"); //3
	printf("□                 .---.                                                                                                                                                                              □\n"); //4
	printf("□                 |   |                                                                                                                                                                              □\n"); //5
	printf("□              ___|   |___                             @@ @@@@@                                                                                                                                      □\n"); //6
	printf("□             [           ]                          @@ @@@ * @-                                                                                                                                     □\n"); //7
	printf("□             `---.   .---'                         =@@@@@     @                                                                                                                                     □\n"); //8
	printf("□                 |   |                               @@+@    @                                                                                                                                      □\n"); //9
	printf("□                 |   |                               .@   @@@                                                                                                                                       □\n"); //10
	printf("□                 |   |                              @@    @                                                                                                                                         □\n"); //11
	printf("□                 |   |                            @   @=    @;$                                                                                                                                     □\n"); //12
	printf("□                 `````                          #     @ @:    ;@$                                                                                                                                   □\n"); //13
	printf("□                                                @*#@. @  :@$  :=#                                                                                                                                   □\n"); //14
	printf("□                                                @  @@ @: * .* :@                                                                                                                                    □\n"); //14
	printf("□                                               @ .@ *\=     =                                                                                                                                        □\n"); //15
	printf("□                                               -= @@  .@@@@@@@:                                                                                                                                     □\n"); //16
	printf("□                                                @  @  @@$=     =:@                                                                                                                                  □\n"); //17
	printf("□                                               +- @   *:  +.:--@ =.                                                                                                                                 □\n"); //18
	printf("□                                               @  @  @#   $ +- .@ =@                                                                                                                                □\n"); //19
	printf("□                                               @ @  @=    = * :  @  -                                                                      .,_                                                      □\n"); //20
	printf("□                                               @ @  @.    .   @  - \\ @                                                                   (. - `,                                                    □\n"); //21
	printf("□                                                @ #  *    $ + .@  # # @                                                               _.-//-\\ _ )                                                   □\n"); //22
	printf("□                                                 @ @: @   $  -  @  =  @@                                                              |^-,_.--`|,\\._ __                                             □\n"); //23
	printf("□                                                   @@  @   =   @ @  -                                                                 ||\\_.-`| |_/ /'  `\\                                           □\n"); //24
	printf("□                                                      @ @   @ --  #                                                                   | \\ ,-`  |        \\                                           □\n"); //25
	printf("□                                                     #.*   * -@  @.                                                                   | ||     |  `-.__/`.                                          □\n"); //26
	printf("□                                                    .@   @  @   =$                                                                     \\||_. - r`     /    `-._                                     □\n"); //27
	printf("□                                                    @@ @   @#  *.@                                                                          `-/'    /         `-.                                   □\n"); //28
	printf("□                                                   @ .    @@  @:==                                                                  _______,-/_   /'             \\                                  □\n"); //29
	printf("□              _          (`-.                    $ $    @ *  *  @:           .-')          _                                   --'`|       |`  ),' `---.  ,       |                                 □\n"); //30
	printf("□              \\`----.    ) ^_`)                 @=*   @  @  @$ * *        (`_^ (    .----`/                                   \\..-`--..___|_,/          /       /                                   □\n"); //31
	printf("□       ,__     \\__   `\\_/  ( `                @$ -  @.  @  @$  * =          ` )  \\_/`   __/     __,                                    |    |`,-,...,/      ,'                                      □\n"); //32
	printf("□        \\_\\      \\__  `|   }               @+ @ @   @  @* $ @ @             __{   |`  __/      /_/                                     \\    |       /     ,' __  r-'',                              □\n"); //33
	printf("□          \\\\  .--' \\__/    }               @ .@    #  @.@.- +: @           / _{    \\__/ '--.  //                                       |___|/     /  __ /-''  `'`)  |                               □\n"); //34
	printf("□           ))/   \\__,<  /_/             $.@=   +@**@ *+ +  + $             \\_> \\_\\  >__/    \\((                                    _,-'    |    /,-' /     _,.--|  (                                □\n"); //35
	printf("□           ((|  _/_/ `\\ \\_\\_        .@@@@.  .@@@     $=+  $@@*                  _/ /` _\\_   |))                                  .-'       )   `(_   / _,.-'  ,-' _,/                               □\n"); //36
	printf("□            `\\_____\\\\  )__\\_\\     .+#-. ==#@. $    @@-   @@    @-              /__(  /______/`                                   `-------'       `--''       `'''                                   □\n"); //37
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n"); //38

	printf("□                                                                                                                                                                                                    □\n"); // 39
	printf("□                           _________________________________________________________________________________________________________________________________________________                        □\n"); // 40
	printf("□                          /  ___                                                                                                                                       ___  \\                       □\n"); // 41
	printf("□                         |  /   \\                                                                                                                                     /   \\  |                      □\n"); // 42
}

void CChurchStage::TextPart1()
{
	printf("□                         | |\\_.  |                                     교회에 들어서자 십자가로부터 빛이 새어 나오기 시작한다.                                       |    /| |                      □\n"); // 43
}

void CChurchStage::TextPart2()
{
	printf("□                         | |\\_.  |                      "); SetConsoleColor(6); printf("증명의 길을 걷는 자여, 제물을 바치라.그리하면 흐르던 피가 멈추고, 새 살이 돋아 치유되리라."); SetConsoleColor(7);printf("                   |    /| |                      □\n"); // 43
}

void CChurchStage::TextPart3()
{
	printf("□                         | |\\_.  |               현재 보유한 재화의 3할을 바치면 체력이 3할만큼 회복 됩니다. 회복하려면 C 를, 나가려면 ESC를 누르세요.               |    /| |                      □\n"); // 43
}

void CChurchStage::TextPart4()
{
	int playerHp = CPlayer::GetInst()->GetHealth();
	printf("□                         | |\\_.  |                                   치유되었습니다! 현재 체력 : ");  printf("%d", playerHp); printf(", 마을로 돌아가려면 Space를 누르세요."); playerHp < 100 ? printf("  ") : printf(" "); printf("                           |    /| |                      □\n"); // 43
}

void CChurchStage::TextPart5()
{
	printf("□                         | |\\_.  |                                       십자가에서 빛이 나지 않습니다. 나가려면 ESC를 누르세요.                                     |    /| |                      □\n"); // 43
}
