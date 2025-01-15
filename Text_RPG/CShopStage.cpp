#include "pch.h"
#include "CShopStage.h"
#include "CStage.h"
#include "CStageManager.h"
#include "CKeyManager.h"
#include "CVillageStage.h"

void CShopStage::StageInit()
{
}

void CShopStage::StageTick()
{
	if (bCallRender)
	{
		StageRender();
		bCallRender = false;
	}

	if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::ESC) == KEY_STATE::TAP)
	{
		CStageManager::GetInst()->ChangeStage(new CVillageStage());
	}	

	if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::C) == KEY_STATE::TAP)
	{
		CShopStage::ChangeBUYSELL();
	}	
}


void CShopStage::ChangeBUYSELL()
{
	if (CurPlayer_Mode == BUYSELL_MODE::BUY)
	{
		CurPlayer_Mode = BUYSELL_MODE::SELL;
	}
	else if (CurPlayer_Mode == BUYSELL_MODE::SELL)
	{
		CurPlayer_Mode = BUYSELL_MODE::BUY;
	}
	bCallRender = true;
}

void CShopStage::StageRender()
{
	std::cout << "\033[2J\033[H";

	if (CurPlayer_Mode == BUYSELL_MODE::BUY)
	{
		BuyRender();
	}

	if (CurPlayer_Mode == BUYSELL_MODE::SELL)
	{
		SellRender();
	}


}

void CShopStage::BuyRender()
{
	//줄 맞추기 용 임시 프린트
	//printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");

	printf("========================================================================================================================================================================================================\n");
	printf("||                                                                                                                                                                                                    ||\n");
	printf("||                                                                                                                                                                                                    ||\n");
	printf("||                            MMMM                                                                                                                            dC8bv.   ,vSQDb                         ||\n");
	printf("||        m  m              //    *MMM                                                                                                                         JBQBBbvdBBBBK                          ||\n");
	printf("||         mm              //        **M                     /$$$$$$  /$$   /$$  /$$$$$$  /$$$$$$$  /$$$$$$$  /$$$$$$ /$$  / $$  /$$$$$$                        J0K      ZK          000              ||\n");
	printf("||        m   m   ,,_____ //         //                     /$$__  $$| $$   |$$ /$$__  $$| $$__  $$| $$__  $$|__ $$_/| $$$ | $$ /$$__  $$                        JBbnnnd0C          0 0 0             ||\n");
	printf("||              ,d       *V        //                      | $$  &_/ | $$   |$$| $$  & $$| $$  & $$| $$  & $$  | $$  | $$$$| $$| $$  &__/                      dQP   m    9b        0 0 0             ||\n");
	printf("||            ,P                   $                       |  $$$$$$ | $$$$$$$$| $$  | $$| $$$$$$$/| $$$$$$$/  | $$  | $$ $$ $$| $$ /$$$$                    JP    dBBBb    97       000              ||\n");
	printf("||           #/  nnn                 &      mm  mm          &____  $$| $$__  $$| $$  | $$| $$____/ | $$____/   | $$  | $$  $$$$| $$|_  $$                   KP   BBP   ?QB   ?b                       ||\n");
	printf("||          @   888817nnnnn           &       mm            /$$  & $$| $$  | $$| $$  | $$| $$      | $$        | $$  | $$&  $$$| $$  & $$                  QP   BBr      0P   0D                      ||\n");
	printf("||          R   080 808880808088080,  M     mm  mm         |  $$$$$$/| $$  | $$|  $$$$$$/| $$      | $$      / $$$$$$| $$ &  $$| $$$$$$/                  QB      'TBBQbv       0D                    ||\n");
	printf("||          p    80  680000000@@@&&P  M                     &______/ |__/  |__/ &______/ |__/      |__/     |______/ |__ / &__/&______/                  5BB    Bb      TB0    BBs                    ||\n");
	printf("||           L   80  7008977898000P  //                                                                                                       000        BBB     TMMbnvdBp     BQ                     ||\n");
	printf("||            q    6827777181000P   /p                                                                                                       0 . 0        LBB:      T0P       rBR                     ||\n");
	printf("||              qo,  '''''''''    /p                                                                                                         0 0 0         QBB5              PBZ                      ||\n");
	printf("||                ''QL________=np'                                                                                                           0 ' 0           TBBL_________JBBP                        ||\n");
	printf("||                                                                                                                                            000              'T0808088080P                          ||\n");
	printf("||                                                                                                                                                                                                    ||\n");
	printf("========================================================================================================================================================================================================\n");
	printf("                                                                                                                                                                                                        \n");
	printf("         ,------------------->,         .------------------->.         .------------------->.                       dMMMMMMMMMMMMMMMMMMMMMMMMMMMMb                                                      \n");
	printf("        | ,-----------------. #b       | ,-----------------. #b       | ,-----------------. #b        ||            MMM     MMMM  MM  MMM  MM  MM |         ####    ######   ##       ##                \n");
	printf("    	| |  ■| ■|,■■,  | ##       | |@)    @)         | ##       | |            CL   | ##        ||            MMM  MM  MMM  MM  MMM  MM  MM |        ##  ##   ##       ##       ##                \n");
	printf("        | |  ■| ■|■--■| | ##       | |@@)  @@@)   #)   | ##       | | nMn.     JMMP   | ##        ||            MMM  MM  MMM  MM  MMM  MM  MM |        ##       ##       ##       ##                \n");
	printf("        | |  ■■■|■■'#  | ##       | |@@@)P@@@@) #@8)  | ##       | |  'YMbmvndMMK    | ##        ||            MMM     MMMM  MM  MMMM    MMM |         ####    ####     ##       ##                \n");
	printf("        | |  ■| ■|■|     | ##       | |@@@@@@@@@@]#@@@@ | ##       | |    >MMMMMMML    | ##        ||            MMM  MM  MMM  MM  MMMMM  MMMM |            ##   ##       ##       ##                \n");
	printf("        | |  ■| ■|■|     | ##       | |@@@@@@@@@@@@@@@@)| ##       | |   /MMMMMMMMML   | ##        ||            MMM  MM  MMM  MM  MMMMM  MMMM |        ##  ##   ##       ##       ##                \n");
	printf("        | '-----------------' ##       | '-----------------' ##       | '-----------------' ##        ||            MMM     MMMMM    MMMMMM  MMMM |         ####    ######   ######   ######            \n");
	printf("        'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#         ||            MMMMMMMMMMMMMMMMMMMMMMMMMMMM# |                                                     \n");
	printf("                                                                                                      ||            Y_____________________________#                                                     \n");
	printf("         [      HP POTION     ]         [    Attack Boost   ]          [  Monster leather   ]         ||                                                                                                \n");
	printf("          ====================           ===================            ====================          ||                  press 'C' button to change BUY ITME MODE or SELL ITEM MODE                    \n");
	printf("         [    10$   / 00000   ]         [    15$  / 00000   ]          [   You can't buy    ]         ||                                                                                                \n");
	printf("                                                                                                      ||                      When you want to go village press the 'ESC' button                        \n");
	printf("         .--------------------.         .--------------------.         .--------------------.         ||\n");
	printf("        | ,-----------------. |        | ,-----------------. |        | ,-----------------. |         ||\n");
	printf("        | |                 | |        | |                 | |        | |                 | |         ||\n");
	printf("        | |                 | |        | |                 | |        | |                 | |         ||\n");
	printf("        | |      EMPTY      | |        | |      EMPTY      | |        | |      EMPTY      | |         ||\n");
	printf("        | |                 | |        | |                 | |        | |                 | |         ||\n");
	printf("        | |                 | |        | |                 | |        | |                 | |         ||\n");
	printf("        | '-----------------' |        | '-----------------' |        | '-----------------' |         ||\n");
	printf("         '___________________/          '___________________/          '___________________/          ||\n");
	printf("                                                                                                      ||\n");
	printf("        [                    ]          [                    ]        [                    ]          ||\n");
	printf("         ====================            ====================          ====================           ||\n");
	printf("        [                    ]          [                    ]        [                    ]            \n");
	printf("                                                                                                        \n");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
}


void CShopStage::SellRender()
{
	//줄 맞추기 용 임시 프린트
	//printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");

	printf("========================================================================================================================================================================================================\n");
	printf("||                                                                                                                                                                                                    ||\n");
	printf("||                                                                                                                                                                                                    ||\n");
	printf("||                            MMMM                                                                                                                            dC8bv.   ,vSQDb                         ||\n");
	printf("||        m  m              //    *MMM                                                                                                                         JBQBBbvdBBBBK                          ||\n");
	printf("||         mm              //        **M                     /$$$$$$  /$$   /$$  /$$$$$$  /$$$$$$$  /$$$$$$$  /$$$$$$ /$$  / $$  /$$$$$$                        J0K      ZK          000              ||\n");
	printf("||        m   m   ,,_____ //         //                     /$$__  $$| $$   |$$ /$$__  $$| $$__  $$| $$__  $$|__ $$_/| $$$ | $$ /$$__  $$                        JBbnnnd0C          0 0 0             ||\n");
	printf("||              ,d       *V        //                      | $$  &_/ | $$   |$$| $$  & $$| $$  & $$| $$  & $$  | $$  | $$$$| $$| $$  &__/                      dQP   m    9b        0 0 0             ||\n");
	printf("||            ,P                   $                       |  $$$$$$ | $$$$$$$$| $$  | $$| $$$$$$$/| $$$$$$$/  | $$  | $$ $$ $$| $$ /$$$$                    JP    dBBBb    97       000              ||\n");
	printf("||           #/  nnn                 &      mm  mm          &____  $$| $$__  $$| $$  | $$| $$____/ | $$____/   | $$  | $$  $$$$| $$|_  $$                   KP   BBP   ?QB   ?b                       ||\n");
	printf("||          @   888817nnnnn           &       mm            /$$  & $$| $$  | $$| $$  | $$| $$      | $$        | $$  | $$&  $$$| $$  & $$                  QP   BBr      0P   0D                      ||\n");
	printf("||          R   080 808880808088080,  M     mm  mm         |  $$$$$$/| $$  | $$|  $$$$$$/| $$      | $$      / $$$$$$| $$ &  $$| $$$$$$/                  QB      'TBBQbv       0D                    ||\n");
	printf("||          p    80  680000000@@@&&P  M                     &______/ |__/  |__/ &______/ |__/      |__/     |______/ |__ / &__/&______/                  5BB    Bb      TB0    BBs                    ||\n");
	printf("||           L   80  7008977898000P  //                                                                                                       000        BBB     TMMbnvdBp     BQ                     ||\n");
	printf("||            q    6827777181000P   /p                                                                                                       0 . 0        LBB:      T0P       rBR                     ||\n");
	printf("||              qo,  '''''''''    /p                                                                                                         0 0 0         QBB5              PBZ                      ||\n");
	printf("||                ''QL________=np'                                                                                                           0 ' 0           TBBL_________JBBP                        ||\n");
	printf("||                                                                                                                                            000              'T0808088080P                          ||\n");
	printf("||                                                                                                                                                                                                    ||\n");
	printf("========================================================================================================================================================================================================\n");
	printf("                                                                                                                                                                                                        \n");
	printf("         ,------------------->,         .------------------->.         .------------------->.                                                            dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMb         \n");
	printf("        | ,-----------------. #b       | ,-----------------. #b       | ,-----------------. #b        ||               #####    ##  ##   ##  ##          MMM    MMMM      MMM  MMMMMMM  MMMMMM |        \n");
	printf("    	| |  ■| ■|,■■,  | ##       | |@)    @)         | ##       | |            CL   | ##        ||               ##  ##   ##  ##   ##  ##          MM  MM  MMM  MMMMMMM  MMMMMMM  MMMMMM |        \n");
	printf("        | |  ■| ■|■--■| | ##       | |@@)  @@@)   #)   | ##       | | nMn.     JMMP   | ##        ||               ##  ##   ##  ##   ##  ##          MM  MMMMMMM  MMMMMMM  MMMMMMM  MMMMMM |        \n");
	printf("        | |  ■■■|■■'#  | ##       | |@@@)P@@@@) #@8)  | ##       | |  'YMbmvndMMK    | ##        ||               #####    ##  ##    ####           MMM    MMMM    MMMMM  MMMMMMM  MMMMMM |        \n");
	printf("        | |  ■| ■|■|     | ##       | |@@@@@@@@@@]#@@@@ | ##       | |    >MMMMMMML    | ##        ||               ##  ##   ##  ##     ##            MMMMMM  MMM  MMMMMMM  MMMMMMM  MMMMMM |        \n");
	printf("        | |  ■| ■|■|     | ##       | |@@@@@@@@@@@@@@@@)| ##       | |   /MMMMMMMMML   | ##        ||               ##  ##   ##  ##     ##            MM  MM  MMM  MMMMMMM  MMMMMMM  MMMMMM |        \n");
	printf("        | '-----------------' ##       | '-----------------' ##       | '-----------------' ##        ||               #####     ####      ##            MMM    MMMM      MMM      MMM      MM |        \n");
	printf("        'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#         ||                                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM# |        \n");
	printf("                                                                                                      ||                                                 Y_____________________________________#        \n");
	printf("         [      HP POTION     ]         [    Attack Boost   ]          [  Monster leather   ]         ||                                                                                                \n");
	printf("          ====================           ===================            ====================          ||                  press 'C' button to change BUY ITME MODE or SELL ITEM MODE                    \n");
	printf("         [     6$   / 00000   ]         [    9$   / 00000   ]          [    5$    / 00000   ]         ||                                                                                                \n");
	printf("                                                                                                      ||                      When you want to go village press the 'ESC' button                        \n");
	printf("         .--------------------.         .--------------------.         .--------------------.         ||\n");
	printf("        | ,-----------------. |        | ,-----------------. |        | ,-----------------. |         ||\n");
	printf("        | |                 | |        | |                 | |        | |                 | |         ||\n");
	printf("        | |                 | |        | |                 | |        | |                 | |         ||\n");
	printf("        | |      EMPTY      | |        | |      EMPTY      | |        | |      EMPTY      | |         ||\n");
	printf("        | |                 | |        | |                 | |        | |                 | |         ||\n");
	printf("        | |                 | |        | |                 | |        | |                 | |         ||\n");
	printf("        | '-----------------' |        | '-----------------' |        | '-----------------' |         ||\n");
	printf("         '___________________/          '___________________/          '___________________/          ||\n");
	printf("                                                                                                      ||\n");
	printf("        [                    ]          [                    ]        [                    ]          ||\n");
	printf("         ====================            ====================          ====================           ||\n");
	printf("        [                    ]          [                    ]        [                    ]            \n");
	printf("                                                                                                        \n");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
}