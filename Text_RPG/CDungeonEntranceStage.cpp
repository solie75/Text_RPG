#include "pch.h"
#include "CDungeonEntranceStage.h"
#include "CKeyManager.h"
#include "CPlayer.h"
#include "CStageManager.h"
#include "CVillageStage.h"
#include "CNormalDungeonStage.h"
#include "CBossDungeonStage.h"
#include "CStateStage.h"

void CDungeonEntranceStage::StageTick()
{
	if (bCallRender)
	{
		StageRender();
		bCallRender = false;
	}

	if (iCurTextPart < 5)
	{
		if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::SPACE) == KEY_STATE::TAP)
		{
			++iCurTextPart;
			bCallRender = true;
		}
	}
	else if (iCurTextPart > 4)
	{
		fAccumulateTime += GlobalData.DeltaTime;
		if (bShowArrow == true && fAccumulateTime > fArrowDurationTime)
		{
			bShowArrow = false;
			bCallRender = true;
			fAccumulateTime = 0.f;
		}
		else if(bShowArrow == false && fAccumulateTime > (fArrowDurationTime / 4.0f))
		{
			bShowArrow = true;
			bCallRender = true;
			fAccumulateTime = 0.f;
		}

		if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::RIGHT) == KEY_STATE::TAP)
		{
			++iCurTextPart;
			bCallRender = true;
			if (iCurTextPart > 6)
			{
				iCurTextPart = 5;
			}
		}

		if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::SPACE) == KEY_STATE::TAP)
		{
			if (iCurTextPart == 5)
			{
				CStageManager::GetInst()->ChangeStage(new CNormalDungeonStage);
			}
			else if (iCurTextPart == 6 && CPlayer::GetInst()->GetLevel() > 9)
			{
				CStageManager::GetInst()->ChangeStage(new CBossDungeonStage);
			}
		}
	}

	if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::ESC) == KEY_STATE::TAP)
	{
		CStageManager::GetInst()->ChangeStage(new CVillageStage);
	}

	if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::UP) == KEY_STATE::TAP)
	{
		if (CStageManager::GetInst()->GetIsDoneTutoStage())
		{
			CStageManager::GetInst()->ChangeStage(new CStateStage);
		}
	}
}

void CDungeonEntranceStage::StageInit()
{
	if (CStageManager::GetInst()->GetIsDoneTutoStage())
	{
		iCurTextPart = 5;
	}
	else
	{
		iCurTextPart = 1;
	}
}

void CDungeonEntranceStage::StageRender()
{
	std::cout << "\033[2J\033[H";
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");

	if (iCurTextPart < 5)
	{
		BasicRender();
	}
	else if (iCurTextPart == 5)
	{
		if (bShowArrow)
		{
			PointToNormal();
		}
		else
		{
			BasicRender();
		}
	}
	else if (iCurTextPart > 5)
	{
		if (bShowArrow)
		{
			if (bAccessBoss)
			{
				PointToBossAccess();
			}
			else
			{
				PointToBossNoAccess();
			}
		}
		else
		{
			BasicRender();
		}
	}

	printf("□                           _____________    ________________________________________________________________________________________________________________________________                        □\n"); // 40
	printf("□                          /  ___        |  /                                                                                                                           ___  \\                       □\n"); // 41
	printf("□                         |  /   \\        \\ |                                                                                                                          /   \\  |                      □\n"); // 42

	if (iCurTextPart < 5)
	{
		switch (iCurTextPart)
		{
		case 1 :
			StartTextPart1();
			break;
		case 2:
			StartTextPart2();
			break;
		case 3:
			StartTextPart3();
			break;
		case 4:
			StartTextPart4();
		}
	}
	else if (iCurTextPart == 5)
	{
		DungeonSelectTextPart1();
	}
	else if (iCurTextPart > 5)
	{
		if (bAccessBoss)
		{
			DungeonSelectTextPart2();
		}
		else
		{
			DungeonSelectTextPart3();
		}
	}
	
	if (iCurTextPart < 5)
	{
		printf("□                         |\\|  | /|                                                                                                                       |\\          |\\  | |/|                      □\n"); // 44
		printf("□                         | `---' |                   _/                                                                         Press Space Bar          / \\         | `---' |                      □\n"); // 45
	}
	else
	{
		printf("□                         |\\|  | /|                                다른 던전을 입장하려면 -> 를 누르세요. 마을로 돌아가려면 ESC 를 누르세요               |\\          |\\  | |/|                      □\n"); // 44
		printf("□                         | `---' |                   _/                                                                                                  / \\         | `---' |                      □\n"); // 45
	}

	printf("□                         |       |__________________/ |_________________________________________________________________________________________________/   |________|       |                      □\n"); // 46
	printf("□                          \\_____/                                                                                                                                     \\_____/                       □\n"); // 47
	printf("□                                                                                                                                                                                                    □\n"); // 48

	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
}

void CDungeonEntranceStage::BasicRender()
{
	printf("□    ^V^                                                                                                                                                                                             □\n"); // 1
	printf("□                                                                      |~         www                        _______    __    __   __    __    ______    ________    ______    __    __              □\n"); // 2
	printf("□                                                                     /.\\        /#^^\\_     /\\              /       \\  /  |  /  | /  \\  /  |  /      \\  /        |  /      \\  /  \\  /  |             □\n"); // 3
	printf("□                          ^V^                                       /###\\      /##    \\   /# \\             $$$$$$$  | $$ |  $$ | $$  \\ $$ | /$$$$$$  | $$$$$$$$/  /$$$$$$  | $$  \\ $$ |             □\n"); // 4
	printf("□                                                                   /#####\\    /##______\\ /##__\\            $$ |  $$ | $$ |  $$ | $$$  \\$$ | $$ | _$$/  $$ |__     $$ |  $$ | $$$  \\$$ |             □\n"); // 5
	printf("□                                                 ^V^              /#######\\    _\\   |= I I ||__|           $$ |  $$ | $$ |  $$ | $$$$  $$ | $$ |/    | $$    |    $$ |  $$ | $$$$  $$ |             □\n"); // 6
	printf("□           ^V^                                                    ~~| ~~~|~    |_=_-__|'  |[]|             $$ |  $$ | $$ |  $$ | $$ $$ $$ | $$ |$$$$ | $$$$$/     $$ |  $$ | $$ $$ $$ |             □\n"); // 7
	printf("□         ^V^                                                        | [] |_______\\__|/_ _ |= |`.           $$ |__$$ | $$ \\__$$ | $$ |$$$$ | $$ \\__$$ | $$ |_____  $$ \\__$$ | $$ |$$$$ |             □\n"); // 8
	printf("□            ^V^                                                     | -  /= __   __    /-\\|= | :           $$    $$/  $$    $$/  $$ | $$$ | $$    $$/  $$       | $$    $$/  $$ | $$$ |             □\n"); // 9
	printf("□                               _ .  ... ... ...----.... ...-........|.= /- /\\/  /\\/   /=- \\.-' :           $$$$$$$/    $$$$$$/   $$/   $$/   $$$$$$/   $$$$$$$$/   $$$$$$/   $$/   $$/              □\n"); // 10
	printf("□                             ..   .   .      .  .    .     .  ......|. /_.=========._/_.-._\\  .:                                                                                                    □\n"); // 11
	printf("□                            .:  .   .    .    .  .  .    .. .  .....|.= |-.'.- .'.- |  /|\\ ^^|/___                                                                                                  □\n"); // 12
	printf("□                           .: .   .   ..   .    .     . . .. . .....\\.  |=|:|= |:| =| |~|~|=/=_-=/\\.                                                                               ^V^              □\n"); // 13
	printf("□                           '..  .  .. .   .       .  . .. . .. . .....|~|-|:| -|:|  |-|~|~|/=_-_/__\\                                                                                                □\n"); // 14
	printf("□       ^V^                .:. .  . .  . .   .  .  . . . ...:.:... ....|=|=|:|- |:|- | |~|~||]#| I   I                                                                                               □\n"); // 15
	printf("□                         .:.... .   . .'  '.. .   .  . .:.:.:II;,. .. | |-_~__=_~__=|_^^   |]#| I   I                                             ^V^                                               □\n"); // 16
	printf("□                         ':.:.. ...::       ::. . .  ...:.::::.,,,. . |-(=-=-=-=-|````|==  |]!! I__ I                                                                                               □\n"); // 17
	printf("□                        .:::I..:             ::. .:...,:IIHHHHHHMMMHHL|/-'/  IHWW|    |HWW|//======/                                                                                                □\n"); // 18
	printf("□                       .:.:V.:                ::..:` .:HIHHHHHHHHHHHHHH_/`-./`-; |    |HW/=======/                                                                        ^V^                       □\n"); // 19
	printf("□                       :..V.:    ^V^          ... . .:VPHHMHHHMMHHHHHHHH __/_  IH`|------------/                                                                                       ^V^          □\n"); // 20
	printf("□                       ::V..:                  . .   .I`:IIMHHMMHHHHHHHH/    IHWWI                                                                                                                  □\n"); // 21
	printf("□                       :: . :.::                 .ABA.:.:IMHMHMMMHMHHHHV:'. .IHWW                                                                   ^V^                                             □\n"); // 22
	printf("□                       '.  ..:..:.:           '.AVMHMA. :.'VHMMMMHHHHHV:' .  :IHWV                                                                                                                  □\n"); // 23
	printf("□              ^V^       :.  .:...:'.:.:```''.  AVMMHMMA: . 'VMMHHHP.:... .. :IVAI                                                                                                                   □\n"); // 24
	printf("□                       .:.   '... .:`'   .   ..HMMMHMMMA::. .`VHHI:::....  .:IHW'                                                                        ^V^                                        □\n"); // 25
	printf("□                     : .   .'`' .:.V`. .. .  :HMMM: MMMI::I. ..:HHIIPPHI::'.P:HM.                                                                                                  ^V^              □\n"); // 26
	printf("□                     :.  .  .  .. ..:.. .    :AMMM  MMMM..:...:IV`:T::I::.`.:IHIMA                               ^V^                                  ^V^                                           □\n"); // 27
	printf("□         ^V^         'V:.. .. . .. .  .  .   'VMMV .VMMV :....:V:.:..:....::IHHHMH                                                                          ^V^     \\/ |    |/                      □\n"); // 28
	printf("□                       `IHH:.II:.. .:. .  . . . ` :HB`` . . ..PI:.::.:::..:IHHMMV`                                                                               \\/ / \\||/  /_/___/_                □\n"); // 29
	printf("□                        :IP``HHII:.  .  .    . . .'V:. . . ..:IH:.:.::IHIHHMMMMM`                                                                                 \\/   |/ \\/                        □\n"); // 30
	printf("□                        :.`VIIHHMMA:.  .   .   .:  .:.. . .:.II:I:AMMMMMMHMMMMMI                                                                             _\\__\\_\\   |  /_____/_                  □\n"); // 31
	printf("□                        ':.:HIHIMHHA:`!!`I.:              :.`HPHIMMMMHHMHMMMMMV                                                                ^V^                  \\  | /          /               □\n"); // 32
	printf("□       ^V^                V:H:I:MA:W'I :                      .I.VMMMHMHMMMMMM                                                                             __\\_-----`  |{,-----------~              □\n"); // 33
	printf("□                            'I::IVAAAW/                          .VVMMHIMM'`'                                                                                        \\ }{                           □\n"); // 34
	printf("□                             I:: VPAA/                            :MMHIMMI                                                                                            }{{                           □\n"); // 35
	printf("□                            .I::. `H:A                             PHIIMM'                                                                                            }}{                           □\n"); // 36
	printf("□                            :::I.  ':X                             I:.IMM                                                                                             {{}                           □\n"); // 37
	printf("□____________________________:::I:.  .V. , . , . , . , . , . , . , .I:..:MM______________________________________________________________________________________,.-=-~{ .`^- _______________________□\n"); // 38
}

void CDungeonEntranceStage::PointToNormal()
{
	printf("□    ^V^                                                                                                                                                                                             □\n"); // 1
	printf("□                                                                      |~         www                        _______    __    __   __    __    ______    ________    ______    __    __              □\n"); // 2
	printf("□                                                                     /.\\        /#^^\\_     /\\              /       \\  /  |  /  | /  \\  /  |  /      \\  /        |  /      \\  /  \\  /  |             □\n"); // 3
	printf("□                          ^V^                                       /###\\      /##    \\   /# \\             $$$$$$$  | $$ |  $$ | $$  \\ $$ | /$$$$$$  | $$$$$$$$/  /$$$$$$  | $$  \\ $$ |             □\n"); // 4
	printf("□                                                                   /#####\\    /##______\\ /##__\\            $$ |  $$ | $$ |  $$ | $$$  \\$$ | $$ | _$$/  $$ |__     $$ |  $$ | $$$  \\$$ |             □\n"); // 5
	printf("□                                                 ^V^              /#######\\    _\\   |= I I ||__|           $$ |  $$ | $$ |  $$ | $$$$  $$ | $$ |/    | $$    |    $$ |  $$ | $$$$  $$ |             □\n"); // 6
	printf("□           ^V^                                                    ~~| ~~~|~    |_=_-__|'  |[]|             $$ |  $$ | $$ |  $$ | $$ $$ $$ | $$ |$$$$ | $$$$$/     $$ |  $$ | $$ $$ $$ |             □\n"); // 7
	printf("□         ^V^                                                        | [] |_______\\__|/_ _ |= |`.           $$ |__$$ | $$ \\__$$ | $$ |$$$$ | $$ \\__$$ | $$ |_____  $$ \\__$$ | $$ |$$$$ |             □\n"); // 8
	printf("□            ^V^                                                     | -  /= __   __    /-\\|= | :           $$    $$/  $$    $$/  $$ | $$$ | $$    $$/  $$       | $$    $$/  $$ | $$$ |             □\n"); // 9
	printf("□                               _ .  ... ... ...----.... ...-........|.= /- /\\/  /\\/   /=- \\.-' :           $$$$$$$/    $$$$$$/   $$/   $$/   $$$$$$/   $$$$$$$$/   $$$$$$/   $$/   $$/              □\n"); // 10
	printf("□                             ..   .   .      .  .    .     .  ......|. /_.=========._/_.-._\\  .:                                                                                                    □\n"); // 11
	printf("□                            .:  .   .    .    .  .  .    .. .  .....|.= |-.'.- .'.- |  /|\\ ^^|/___                                                                                                  □\n"); // 12
	printf("□                           .: .   .   ..   .    .     . . .. . .....\\.  |=|:|= |:| =| |~|~|=/=_-=/\\.                                                                                    ^V^         □\n"); // 13
	printf("□                           '..  .  .. .   .       .  . .. . .. . .....|~|-|:| -|:|  |-|~|~|/=_-_/__\\                                                                                                □\n"); // 14
	printf("□       ^V^                .:. .  . .  . .   .  .  . . . ...:.:... ....|=|=|:|- |:|- | |~|~||]#| I   I                                                                                               □\n"); // 15
	printf("□                         .:.... .   . .'  '.. .   .  . .:.:.:II;,. .. | |-_~__=_~__=|_^^   |]#| I   I                                          ^V^                                                  □\n"); // 16
	printf("□                         ':.:.. ...::       ::. . .  ...:.::::.,,,. . |-(=-=-=-=-|````|==  |]!! I__ I                                                                                               □\n"); // 17
	printf("□                        .:::I..:             ::. .:...,:IIHHHHHHMMMHHL|/-'/  IHWW|    |HWW|//======/                                                                                                □\n"); // 18
	printf("□                       .:.:V.:                ::..:` .:HIHHHHHHHHHHHHHH_/`-./`-; |    |HW/=======/                                                                    ^V^                           □\n"); // 19
	printf("□                       :..V.:    ^V^          ... . .:VPHHMHHHMMHHHHHHHH __/_  IH`|------------/                                                                                          ^V^       □\n"); // 20
	printf("□                       ::V..:                  . .   .I`:IIMHHMMHHHHHHHH/    IHWWI                                                                                                                  □\n"); // 21
	printf("□                       :: . :.::                 .ABA.:.:IMHMHMMMHMHHHHV:'. .IHWW                                                                   ^V^                                             □\n"); // 22
	printf("□                       '.  ..:..:.:           '.AVMHMA. :.'VHMMMMHHHHHV:' .  :IHWV                                                                                                                  □\n"); // 23
	printf("□              ^V^       :.  .:...:'.:.:```''.  AVMMHMMA: . 'VMMHHHP.:... .. :IVAI                                                                                                                   □\n"); // 24
	printf("□                       .:.   '... .:`'   .   ..HMMMHMMMA::. .`VHHI:::....  .:IHW'                                                                        ^V^                                        □\n"); // 25
	printf("□                     : .   .'`' .:.V`. .. .  :HMMM: MMMI::I. ..:HHIIPPHI::'.P:HM.                                                                                                  ^V^              □\n"); // 26
	printf("□                     :.  .  .  .. ..:.. .    :AMMM  MMMM..:...:IV`:T::I::.`.:IHIMA                               ^V^                                  ^V^                                           □\n"); // 27
	printf("□         ^V^         'V:.. .. . .. .  .  .   'VMMV .VMMV :....:V:.:..:....::IHHHMH                                                                          ^V^     \\/ |    |/                      □\n"); // 28
	printf("□                       `IHH:.II:.. .:. .  . . . ` :HB`` . . ..PI:.::.:::..:IHHMMV`                                                                               \\/ / \\||/  /_/___/_                □\n"); // 29
	printf("□                        :IP``HHII:.  .  .    . . .'V:. . . ..:IH:.:.::IHIHHMMMMM`                                                                                 \\/   |/ \\/                        □\n"); // 30
	printf("□                        :.`VIIHHMMA:.  .   .   .:  .:.. . .:.II:I:AMMMMMMHMMMMMI         #                                                                   _\\__\\_\\   |  /_____/_                  □\n"); // 31
	printf("□                        ':.:HIHIMHHA:`!!`I.:              :.`HPHIMMMMHHMHMMMMMV        #@#                                                     ^V^                  \\  | /          /               □\n"); // 32
	printf("□       ^V^                V:H:I:MA:W'I :                      .I.VMMMHMHMMMMMM       ##@#@#@#@#@#@#@#@#@####... ..                                         __\\_-----`  |{,-----------~              □\n"); // 33
	printf("□                            'I::IVAAAW/                          .VVMMHIMM'`'       #@#$$$$$$$$$$$$$$$$$$$##:::..                                                    \\ }{                           □\n"); // 34
	printf("□                             I:: VPAA/                            :MMHIMMI           ##@#@#@#@#@#@#@#@#@####::: .                                                     }{{                           □\n"); // 35
	printf("□                            .I::. `H:A                             PHIIMM'             #@#                                                                            }}{                           □\n"); // 36
	printf("□                            :::I.  ':X                             I:.IMM                #                                                                            {{}                           □\n"); // 37
	printf("□____________________________:::I:.  .V. , . , . , . , . , . , . , .I:..:MM______________________________________________________________________________________,.-=-~{ .`^- _______________________□\n"); // 38
}

void CDungeonEntranceStage::PointToBossAccess()
{
	printf("□    ^V^                                                                                                                                                                                             □\n"); // 1
	printf("□                                                                      |~         www                        _______    __    __   __    __    ______    ________    ______    __    __              □\n"); // 2
	printf("□                                                                     /.\\        /#^^\\_     /\\              /       \\  /  |  /  | /  \\  /  |  /      \\  /        |  /      \\  /  \\  /  |             □\n"); // 3
	printf("□                          ^V^                                       /###\\      /##    \\   /# \\             $$$$$$$  | $$ |  $$ | $$  \\ $$ | /$$$$$$  | $$$$$$$$/  /$$$$$$  | $$  \\ $$ |             □\n"); // 4
	printf("□                                                                   /#####\\    /##______\\ /##__\\            $$ |  $$ | $$ |  $$ | $$$  \\$$ | $$ | _$$/  $$ |__     $$ |  $$ | $$$  \\$$ |             □\n"); // 5
	printf("□                                                 ^V^              /#######\\    _\\   |= I I ||__|           $$ |  $$ | $$ |  $$ | $$$$  $$ | $$ |/    | $$    |    $$ |  $$ | $$$$  $$ |             □\n"); // 6
	printf("□           ^V^                                                    ~~| ~~~|~    |_=_-__|'  |[]|             $$ |  $$ | $$ |  $$ | $$ $$ $$ | $$ |$$$$ | $$$$$/     $$ |  $$ | $$ $$ $$ |             □\n"); // 7
	printf("□         ^V^                                                        | [] |_______\\__|/_ _ |= |`.           $$ |__$$ | $$ \\__$$ | $$ |$$$$ | $$ \\__$$ | $$ |_____  $$ \\__$$ | $$ |$$$$ |             □\n"); // 8
	printf("□            ^V^                                                     | -  /= __   __    /-\\|= | :           $$    $$/  $$    $$/  $$ | $$$ | $$    $$/  $$       | $$    $$/  $$ | $$$ |             □\n"); // 9
	printf("□                               _ .  ... ... ...----.... ...-........|.= /- /\\/  /\\/   /=- \\.-' :           $$$$$$$/    $$$$$$/   $$/   $$/   $$$$$$/   $$$$$$$$/   $$$$$$/   $$/   $$/              □\n"); // 10
	printf("□                             ..   .   .      .  .    .     .  ......|. /_.=========._/_.-._\\  .:                                                                                                    □\n"); // 11
	printf("□                            .:  .   .    .    .  .  .    .. .  .....|.= |-.'.- .'.- |  /|\\ ^^|/___                                                                                                  □\n"); // 12
	printf("□                           .: .   .   ..   .    .     . . .. . .....\\.  |=|:|= |:| =| |~|~|=/=_-=/\\.          #                                                                         ^V^         □\n"); // 13
	printf("□                           '..  .  .. .   .       .  . .. . .. . .....|~|-|:| -|:|  |-|~|~|/=_-_/__\\        #@#                                                                                     □\n"); // 14
	printf("□       ^V^                .:. .  . .  . .   .  .  . . . ...:.:... ....|=|=|:|- |:|- | |~|~||]#| I   I      ##@#@#@#@#@#@#@#@#@####... ..                                                            □\n"); // 15
	printf("□                         .:.... .   . .'  '.. .   .  . .:.:.:II;,. .. | |-_~__=_~__=|_^^   |]#| I   I     #@#$$$$$$$$$$$$$$$$$$$##:::..       ^V^                                                   □\n"); // 16
	printf("□                         ':.:.. ...::       ::. . .  ...:.::::.,,,. . |-(=-=-=-=-|````|==  |]!! I__ I      ##@#@#@#@#@#@#@#@#@####::: .                                                             □\n"); // 17
	printf("□                        .:::I..:             ::. .:...,:IIHHHHHHMMMHHL|/-'/  IHWW|    |HWW|//======/        #@#                                                                                     □\n"); // 18
	printf("□                       .:.:V.:                ::..:` .:HIHHHHHHHHHHHHHH_/`-./`-; |    |HW/=======/            #                                                      ^V^                            □\n"); // 19
	printf("□                       :..V.:    ^V^          ... . .:VPHHMHHHMMHHHHHHHH __/_  IH`|------------/                                                                                          ^V^       □\n"); // 20
	printf("□                       ::V..:                  . .   .I`:IIMHHMMHHHHHHHH/    IHWWI                                                                                                                  □\n"); // 21
	printf("□                       :: . :.::                 .ABA.:.:IMHMHMMMHMHHHHV:'. .IHWW                                                                   ^V^                                             □\n"); // 22
	printf("□                       '.  ..:..:.:           '.AVMHMA. :.'VHMMMMHHHHHV:' .  :IHWV                                                                                                                  □\n"); // 23
	printf("□              ^V^       :.  .:...:'.:.:```''.  AVMMHMMA: . 'VMMHHHP.:... .. :IVAI                                                                                                                   □\n"); // 24
	printf("□                       .:.   '... .:`'   .   ..HMMMHMMMA::. .`VHHI:::....  .:IHW'                                                                        ^V^                                        □\n"); // 25
	printf("□                     : .   .'`' .:.V`. .. .  :HMMM: MMMI::I. ..:HHIIPPHI::'.P:HM.                                                                                                  ^V^              □\n"); // 26
	printf("□                     :.  .  .  .. ..:.. .    :AMMM  MMMM..:...:IV`:T::I::.`.:IHIMA                               ^V^                                  ^V^                                           □\n"); // 27
	printf("□         ^V^         'V:.. .. . .. .  .  .   'VMMV .VMMV :....:V:.:..:....::IHHHMH                                                                          ^V^     \\/ |    |/                      □\n"); // 28
	printf("□                       `IHH:.II:.. .:. .  . . . ` :HB`` . . ..PI:.::.:::..:IHHMMV`                                                                               \\/ / \\||/  /_/___/_                □\n"); // 29
	printf("□                        :IP``HHII:.  .  .    . . .'V:. . . ..:IH:.:.::IHIHHMMMMM`                                                                                 \\/   |/ \\/                        □\n"); // 30
	printf("□                        :.`VIIHHMMA:.  .   .   .:  .:.. . .:.II:I:AMMMMMMHMMMMMI                                                                             _\\__\\_\\   |  /_____/_                  □\n"); // 31
	printf("□                        ':.:HIHIMHHA:`!!`I.:              :.`HPHIMMMMHHMHMMMMMV                                                                ^V^                  \\  | /          /               □\n"); // 32
	printf("□       ^V^                V:H:I:MA:W'I :                      .I.VMMMHMHMMMMMM                                                                             __\\_-----`  |{,-----------~              □\n"); // 33
	printf("□                            'I::IVAAAW/                          .VVMMHIMM'`'                                                                                        \\ }{                           □\n"); // 34
	printf("□                             I:: VPAA/                            :MMHIMMI                                                                                            }{{                           □\n"); // 35
	printf("□                            .I::. `H:A                             PHIIMM'                                                                                            }}{                           □\n"); // 36
	printf("□                            :::I.  ':X                             I:.IMM                                                                                             {{}                           □\n"); // 37
	printf("□____________________________:::I:.  .V. , . , . , . , . , . , . , .I:..:MM______________________________________________________________________________________,.-=-~{ .`^- _______________________□\n"); // 38
}

void CDungeonEntranceStage::PointToBossNoAccess()
{
	printf("□    ^V^                                                                                                                                                                                             □\n"); // 1
	printf("□                                                                      |~         www                        _______    __    __   __    __    ______    ________    ______    __    __              □\n"); // 2
	printf("□                                                                     /.\\        /#^^\\_     /\\              /       \\  /  |  /  | /  \\  /  |  /      \\  /        |  /      \\  /  \\  /  |             □\n"); // 3
	printf("□                          ^V^                                       /###\\      /##    \\   /# \\             $$$$$$$  | $$ |  $$ | $$  \\ $$ | /$$$$$$  | $$$$$$$$/  /$$$$$$  | $$  \\ $$ |             □\n"); // 4
	printf("□                                                                   /#####\\    /##______\\ /##__\\            $$ |  $$ | $$ |  $$ | $$$  \\$$ | $$ | _$$/  $$ |__     $$ |  $$ | $$$  \\$$ |             □\n"); // 5
	printf("□                                                 ^V^              /#######\\    _\\   |= I I ||__|           $$ |  $$ | $$ |  $$ | $$$$  $$ | $$ |/    | $$    |    $$ |  $$ | $$$$  $$ |             □\n"); // 6
	printf("□           ^V^                                                    ~~| ~~~|~    |_=_-__|'  |[]|             $$ |  $$ | $$ |  $$ | $$ $$ $$ | $$ |$$$$ | $$$$$/     $$ |  $$ | $$ $$ $$ |             □\n"); // 7
	printf("□         ^V^                                                        | [] |_______\\__|/_ _ |= |`.           $$ |__$$ | $$ \\__$$ | $$ |$$$$ | $$ \\__$$ | $$ |_____  $$ \\__$$ | $$ |$$$$ |             □\n"); // 8
	printf("□            ^V^                                                     | -  /= __   __    /-\\|= | :           $$    $$/  $$    $$/  $$ | $$$ | $$    $$/  $$       | $$    $$/  $$ | $$$ |             □\n"); // 9
	printf("□                               _ .  ... ... ...----.... ...-........|.= /- /\\/  /\\/   /=- \\.-' :           $$$$$$$/    $$$$$$/   $$/   $$/   $$$$$$/   $$$$$$$$/   $$$$$$/   $$/   $$/              □\n"); // 10
	printf("□                             ..   .   .      .  .    .     .  ......|. /_.=========._/_.-._\\  .:                                                                                                    □\n"); // 11
	printf("□                            .:  .   .    .    .  .  .    .. .  .....|.= |-.'.- .'.- |  /|\\ ^^|/___                                                                                                  □\n"); // 12
	printf("□                           .: .   .   ..   .    .     . . .. . .....\\.  |=|:|= |:| =| |~|~|=/=_-=/\\.                \\\\       //                                                  ^V^                □\n"); // 13
	printf("□                           '..  .  .. .   .       .  . .. . .. . .....|~|-|:| -|:|  |-|~|~|/=_-_/__\\         #       \\\\     //                                                                      □\n"); // 14
	printf("□       ^V^                .:. .  . .  . .   .  .  . . . ...:.:... ....|=|=|:|- |:|- | |~|~||]#| I   I       #@#       \\\\   //                                                                       □\n"); // 15
	printf("□                         .:.... .   . .'  '.. .   .  . .:.:.:II;,. .. | |-_~__=_~__=|_^^   |]#| I   I     ##@#@#@#@#@#@\\\\.//#@#@@#@####... ..      ^V^                                              □\n"); // 16
	printf("□                         ':.:.. ...::       ::. . .  ...:.::::.,,,. . |-(=-=-=-=-|````|==  |]!! I__ I    #@#$$$$$$$$$#@@>X<##@$$$$$$::::::..                                                        □\n"); // 17
	printf("□                        .:::I..:             ::. .:...,:IIHHHHHHMMMHHL|/-'/  IHWW|    |HWW|//======/      ##@#@#@#@#@#@//^\\\\:#@##@#@####::: .                                                       □\n"); // 18
	printf("□                       .:.:V.:                ::..:` .:HIHHHHHHHHHHHHHH_/`-./`-; |    |HW/=======/          #@#       //   \\\\                                            ^V^                        □\n"); // 19
	printf("□                       :..V.:    ^V^          ... . .:VPHHMHHHMMHHHHHHHH __/_  IH`|------------/              #      //     \\\\                                                        ^V^           □\n"); // 20
	printf("□                       ::V..:                  . .   .I`:IIMHHMMHHHHHHHH/    IHWWI                                  //       \\\\                                                                     □\n"); // 21
	printf("□                       :: . :.::                 .ABA.:.:IMHMHMMMHMHHHHV:'. .IHWW                                                                   ^V^                                             □\n"); // 22
	printf("□                       '.  ..:..:.:           '.AVMHMA. :.'VHMMMMHHHHHV:' .  :IHWV                                                                                                                  □\n"); // 23
	printf("□              ^V^       :.  .:...:'.:.:```''.  AVMMHMMA: . 'VMMHHHP.:... .. :IVAI                                                                                                                   □\n"); // 24
	printf("□                       .:.   '... .:`'   .   ..HMMMHMMMA::. .`VHHI:::....  .:IHW'                                                                        ^V^                                        □\n"); // 25
	printf("□                     : .   .'`' .:.V`. .. .  :HMMM: MMMI::I. ..:HHIIPPHI::'.P:HM.                                                                                                  ^V^              □\n"); // 26
	printf("□                     :.  .  .  .. ..:.. .    :AMMM  MMMM..:...:IV`:T::I::.`.:IHIMA                               ^V^                                  ^V^                                           □\n"); // 27
	printf("□         ^V^         'V:.. .. . .. .  .  .   'VMMV .VMMV :....:V:.:..:....::IHHHMH                                                                          ^V^     \\/ |    |/                      □\n"); // 28
	printf("□                       `IHH:.II:.. .:. .  . . . ` :HB`` . . ..PI:.::.:::..:IHHMMV`                                                                               \\/ / \\||/  /_/___/_                □\n"); // 29
	printf("□                        :IP``HHII:.  .  .    . . .'V:. . . ..:IH:.:.::IHIHHMMMMM`                                                                                 \\/   |/ \\/                        □\n"); // 30
	printf("□                        :.`VIIHHMMA:.  .   .   .:  .:.. . .:.II:I:AMMMMMMHMMMMMI                                                                             _\\__\\_\\   |  /_____/_                  □\n"); // 31
	printf("□                        ':.:HIHIMHHA:`!!`I.:              :.`HPHIMMMMHHMHMMMMMV                                                                ^V^                  \\  | /          /               □\n"); // 32
	printf("□       ^V^                V:H:I:MA:W'I :                      .I.VMMMHMHMMMMMM                                                                             __\\_-----`  |{,-----------~              □\n"); // 33
	printf("□                            'I::IVAAAW/                          .VVMMHIMM'`'                                                                                        \\ }{                           □\n"); // 34
	printf("□                             I:: VPAA/                            :MMHIMMI                                                                                            }{{                           □\n"); // 35
	printf("□                            .I::. `H:A                             PHIIMM'                                                                                            }}{                           □\n"); // 36
	printf("□                            :::I.  ':X                             I:.IMM                                                                                             {{}                           □\n"); // 37
	printf("□____________________________:::I:.  .V. , . , . , . , . , . , . , .I:..:MM______________________________________________________________________________________,.-=-~{ .`^- _______________________□\n"); // 38
}


void CDungeonEntranceStage::StartTextPart1()
{
	printf("□                         | |\\_.  |       |/                                               던전 입구에 도착했다.                                          \\           |    /| |                      □\n"); // 43
}

void CDungeonEntranceStage::StartTextPart2()
{
	printf("□                         | |\\_.  |       |/                                    해골 모양의 성이라니... 기괴하기 짝이 없다.                               \\           |    /| |                      □\n"); // 43
}

void CDungeonEntranceStage::StartTextPart3()
{
	printf("□                         | |\\_.  |       |/                           해골 머리의 뿔처럼 생긴 성에는 덜 자란 용이 있다고 했던가                          \\           |    /| |                      □\n"); // 43
}

void CDungeonEntranceStage::StartTextPart4()
{
	printf("□                         | |\\_.  |       |/                           지금의 내가 잡을 수 있을까... 일단 던전에 들어가 보자.                             \\           |    /| |                      □\n"); // 43
}

void CDungeonEntranceStage::DungeonSelectTextPart1()
{
	printf("□                         | |\\_.  |       |/                                      일반 던전에 입장하려면 Space 를 누르세요.                               \\           |    /| |                      □\n"); // 43
}

void CDungeonEntranceStage::DungeonSelectTextPart2()
{
	printf("□                         | |\\_.  |       |/                                      보스 던전에 입장하려면 Space 를 누르세요.                               \\           |    /| |                      □\n"); // 43
}

void CDungeonEntranceStage::DungeonSelectTextPart3()
{
	printf("□                         | |\\_.  |       |/                                         아직 보스 던전에 입장할 수 없습니다.                                 \\           |    /| |                      □\n"); // 43
}