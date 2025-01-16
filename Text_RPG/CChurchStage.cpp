#include "pch.h"
#include "CChurchStage.h"
#include "CKeyManager.h"
#include "CStageManager.h"
#include "CVillageStage.h"
#include "CPlayer.h"

void SetConsoleColor(WORD color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ� ��������
	SetConsoleTextAttribute(hConsole, color);         // ���� �Ӽ� ����
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
		if (!CPlayer::GetInst()->GetBoolHealAccess())
		{
			return;
		}

		if (iCurTextPart < 3)
		{
			++iCurTextPart;
			bCallRender = true;
		}
		else if (iCurTextPart == 4)
		{
			CStageManager::GetInst()->ChangeStage(new CVillageStage);
			CPlayer::GetInst()->SetBoolHealAccess(false);
		}
	}

	if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::C) == KEY_STATE::TAP && iCurTextPart == 3)
	{
		// ���� ��ȭ ���� �� ȸ��
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
	printf("�����������������������������������������������������������������������������������������������������\n");
	BasicRender();
	if (CPlayer::GetInst()->GetBoolHealAccess())
	{
		switch (iCurTextPart)
		{
		case 1:
			TextPart1();
			break;
		case 2:
			TextPart2();
			break;
		case 3:
			TextPart3();
			break;
		case 4:
			TextPart4();
			break;
		}
	}
	else
	{
		TextPart5();
	}
	printf("��                         |\\|  | /|                                                                                                                                   |\\  | |/|                      ��\n"); // 44
	if (iCurTextPart < 3)
	{
		printf("��                         | `---' |                                                                                                           Press Space Bar         | `---' |                      ��\n"); // 45
	}
	else
	{
		printf("��                         | `---' |                                                                                                                                   | `---' |                      ��\n"); // 45
	}
	
	printf("��                         |       |___________________________________________________________________________________________________________________________________|       |                      ��\n"); // 46
	printf("��                          \\_____/                                                                                                                                     \\_____/                       ��\n"); // 47
	printf("��                                                                                                                                                                                                    ��\n"); // 48
	printf("�����������������������������������������������������������������������������������������������������");
}

void CChurchStage::BasicRender()
{																																						                          
	printf("��                                                                                                                                                                                                    ��\n"); //2
	printf("��               \   |   /                                                                                                -=-                                                                          ��\n"); //3
	printf("��                 .---.                                                                                              (\\  _  /)                                                                       ��\n"); //4
	printf("��            '-.  |   |  .-'                                                                                         ( \\( )/ )                                                                       ��\n"); //5
	printf("��              ___|   |___     :.     --.    .... .    @@ @@@@@                                                      (       )                                                                       ��\n"); //6
	printf("��         -=  [           ]   -      +.              @@ @@@ * @-                                                      `>   <'                                                                        ��\n"); //7
	printf("��             `---.   .---'     =          #    .   =@@@@@     @                                                      /     \\                                                                        ��\n"); //8
	printf("��                 |   |      :    +                   @@+@    @                                                       `-._.-'                                                                        ��\n"); //9
	printf("��                 |   |       .     =             .   .@   @@@                                                                                                                                       ��\n"); //10
	printf("��                 |   |        :      =         .    @@    @                                                                                                                                         ��\n"); //11
	printf("��                 |   |      $  .      ..          @   @=    @;$                                                                                                                                     ��\n"); //12
	printf("��                 `````          .       -     . #     @ @:    ;@$                                                                                                                                   ��\n"); //13
	printf("��                             *   .        =   . @*#@. @  :@$  :=#                -=-                           _                                                                                    ��\n"); //14
	printf("��                                  .             @  @@ @: * .* :@              (\\  _  /)                      (\\o/)                                                                                  ��\n"); //14
	printf("��                     _      =    .             @ .@ *\=     =                  ( \\( )/ )                       /_\\                                                                                   ��\n"); //15
	printf("��                   {\\o/}      :     .           -= @@  .@@@@@@@:              (       )                                                                                                             ��\n"); //16
	printf("��                    /_\\             .          @  @  @@$=     =:@              `>   <'                                                                                                              ��\n"); //17
	printf("��                               =      :        +- @   *:  +.:--@ =.            /     \\                                                                                                              ��\n"); //18
	printf("��                                       .       @  @  @#   $ +- .@ =@           `-._.-'                                                                                                              ��\n"); //19
	printf("��                                #       .      @ @  @=    = * :  @  -                                                                      .,_                                                      ��\n"); //20
	printf("��                                               @ @  @.    .   @  - \\ @                                                                   (. - `,                                                    ��\n"); //21
	printf("��                                 *              @ #  *    $ + .@  # # @                           _                                   _.-//-\\ _ )                                                   ��\n"); //22
	printf("��      <^\\()/^>                                  @ @: @   $  -  @  =  @@                         (\\o/)                                |^-,_.--`|,\\._ __                                              ��\n"); //23
	printf("��       \\/  \\/                      =             @@  @   =   @ @  -                              /_\\                                 ||\\_.-`| |_/ /'  `\\                                            ��\n"); //24
	printf("��        /  \\                                         @ @   @ --  #                                                                   | \\ ,-`  |        \\                                            ��\n"); //25
	printf("��        `''`                                   .    #.*   * -@  @.                                                                   | ||     |  `-.__/`.                                           ��\n"); //26
	printf("��                                   :           .    .@   @  @   =$                                                                    \\||_. - r`     /    `-._                                      ��\n"); //27
	printf("��                                                    @@ @   @#  *.@                                                                          `-/'    /         `-.                                   ��\n"); //28
	printf("��                                    +              @ .    @@  @:==                                                                  _______,-/_   /'             \\                                  ��\n"); //29
	printf("��              _          (`-.                    $ $    @ *  *  @:           .-')          _                                   --'`|       |`  ),' `---.  ,       |                                 ��\n"); //30
	printf("��              \\`----.    ) ^_`)       +          @=*   @  @  @$ * *        (`_^ (    .----`/                                  \\..-`--..___|_,/          /       /                                   ��\n"); //31
	printf("��       ,__     \\__   `\\_/  ( `                @$ -  @.  @  @$  * =          ` )  \\_/`   __/     __,                                    |    |`,-,...,/      ,'                                      ��\n"); //32
	printf("��        \\_\\      \\__  `|   }        :      @+ @ @   @  @* $ @ @             __{   |`  __/      /_/                                     \\    |       /     ,' __  r-'',                              ��\n"); //33
	printf("��          \\\\  .--' \\__/    }               @ .@    #  @.@.- +: @           / _{    \\__/ '--.  //                                       |___|/     /  __ /-''  `'`)  |                               ��\n"); //34
	printf("��           ))/   \\__,<  /_/             $.@=   +@**@ *+ +  + $             \\_> \\_\\  >__/    \\((                                    _,-'    |    /,-' /     _,.--|  (                                ��\n"); //35
	printf("��           ((|  _/_/ `\\ \\_\\_   .    .@@@@.  .@@@     $=+  $@@*                  _/ /` _\\_   |))                                  .-'       )   `(_   / _,.-'  ,-' _,/                               ��\n"); //36
	printf("��            `\\_____\\\\  )__\\_\\     .+#-. ==#@. $    @@-   @@    @-              /__(  /______/`                                   `-------'       `--''       `'''                                   ��\n"); //37
	printf("�����������������������������������������������������������������������������������������������������\n"); //38

	printf("��                                                                                                                                                                                                    ��\n"); // 39
	printf("��                           _________________________________________________________________________________________________________________________________________________                        ��\n"); // 40
	printf("��                          /  ___                                                                                                                                       ___  \\                       ��\n"); // 41
	printf("��                         |  /   \\                                                                                                                                     /   \\  |                      ��\n"); // 42
	
}

void CChurchStage::TextPart1()
{
	printf("��                         | |\\_.  |                                     ��ȸ�� ���� ���ڰ��κ��� ���� ���� ������ �����Ѵ�.                                       |    /| |                      ��\n"); // 43
}

void CChurchStage::TextPart2()
{
	printf("��                         | |\\_.  |                      "); SetConsoleColor(6); printf("������ ���� �ȴ� �ڿ�, ������ ��ġ��.�׸��ϸ� �帣�� �ǰ� ���߰�, �� ���� ���� ġ���Ǹ���."); SetConsoleColor(7);printf("                   |    /| |                      ��\n"); // 43
}

void CChurchStage::TextPart3()
{
	printf("��                         | |\\_.  |               ���� ������ ��ȭ�� 3���� ��ġ�� ü���� 3�Ҹ�ŭ ȸ�� �˴ϴ�. ȸ���Ϸ��� C ��, �������� ESC�� ��������.               |    /| |                      ��\n"); // 43
}

void CChurchStage::TextPart4()
{
	int playerHp = CPlayer::GetInst()->GetHealth();
	printf("��                         | |\\_.  |                                   ġ���Ǿ����ϴ�! ���� ü�� : ");  printf("%d", playerHp); printf(", ������ ���ư����� Space�� ��������."); playerHp < 100 ? printf("  ") : printf(" "); printf("                           |    /| |                      ��\n"); // 43
}

void CChurchStage::TextPart5()
{
	printf("��                         | |\\_.  |                                       ���ڰ����� ���� ���� �ʽ��ϴ�. �������� ESC�� ��������.                                     |    /| |                      ��\n"); // 43
}

void CChurchStage::TextPart6()
{
	
}