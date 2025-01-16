#include "pch.h"
#include "CShopStage.h"
#include "CStage.h"
#include "CStageManager.h"
#include "CKeyManager.h"
#include "CVillageStage.h"
#include "CItem.h"
#include "CShopManager.h"

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

	switch (std::to_string(shopPotionCnt).size())
	{
	case 1:
		zeroBUYPotionCnt = "0000";
		break;
	case 2:
		zeroBUYPotionCnt = "000";
		break;
	case 3:
		zeroBUYPotionCnt = "00";
		break;
	case 4:
		zeroBUYPotionCnt = "0";
		break;
	case 5:
		zeroBUYPotionCnt = "";
		break;
	default:
		break;
	}

	switch (std::to_string(shopBoostCnt).size())
	{
	case 1:
		zeroBUYBoostCnt = "0000";
		break;
	case 2:
		zeroBUYBoostCnt = "000";
		break;
	case 3:
		zeroBUYBoostCnt = "00";
		break;
	case 4:
		zeroBUYBoostCnt = "0";
		break;
	case 5:
		zeroBUYBoostCnt = "";
		break;
	default:
		break;
	}

	switch (std::to_string(PlayerPotionCnt).size())
	{
	case 1:
		zeroSELLPotionCnt = "0000";
		break;
	case 2:
		zeroSELLPotionCnt = "000";
		break;
	case 3:
		zeroSELLPotionCnt = "00";
		break;
	case 4:
		zeroSELLPotionCnt = "0";
		break;
	case 5:
		zeroSELLPotionCnt = "";
		break;
	default:
		break;
	}

	switch (std::to_string(PlayerBoostCnt).size())
	{
	case 1:
		zeroSELLBoostCnt = "0000";
		break;
	case 2:
		zeroSELLBoostCnt = "000";
		break;
	case 3:
		zeroSELLBoostCnt = "00";
		break;
	case 4:
		zeroSELLBoostCnt = "0";
		break;
	case 5:
		zeroSELLBoostCnt = "";
		break;
	default:
		break;
	}

	switch (std::to_string(PlayerMonLeatherCnt).size())
	{
	case 1:
		zeroSELLMonLeatherCnt = "0000";
		break;
	case 2:
		zeroSELLMonLeatherCnt = "000";
		break;
	case 3:
		zeroSELLMonLeatherCnt= "00";
		break;
	case 4:
		zeroSELLMonLeatherCnt= "0";
		break;
	case 5:
		zeroSELLMonLeatherCnt= "";
		break;
	default:
		break;
	}

	zeroBUYPotionCnt += std::to_string(shopPotionCnt);
	zeroBUYBoostCnt += std::to_string(shopBoostCnt);
	zeroSELLPotionCnt += std::to_string(PlayerPotionCnt);
	zeroSELLBoostCnt += std::to_string(PlayerBoostCnt);
	zeroSELLMonLeatherCnt += std::to_string(PlayerMonLeatherCnt);

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

	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                           .dMMMb.                                                                                                                          dC8bv.   ,vSQDb                         □\n");
	printf("□        m  m              ##  ''YMMM.                                                                                                                        JBQBBbvdBBBBK                          □\n");
	printf("□         mm              ##       'YMM                     /$$$$$$  /$$   /$$  /$$$$$$  /$$$$$$$  /$$$$$$$  /$$$$$$ /$$  / $$  /$$$$$$                        J0K      ZK          000              □\n");
	printf("□        m   m   ,onnnnn ##         ##                     /$$__  $$| $$   |$$ /$$__  $$| $$__  $$| $$__  $$|__ $$_/| $$$ | $$ /$$__  $$                        JBbnnnd0C          0 0 0             □\n");
	printf("□              ,d'     'yV        ##                      | $$  &_/ | $$   |$$| $$  & $$| $$  & $$| $$  & $$  | $$  | $$$$| $$| $$  &__/                      dQP   m    9b        0 0 0             □\n");
	printf("□            ,P'                  $.                      |  $$$$$$ | $$$$$$$$| $$  | $$| $$$$$$$/| $$$$$$$/  | $$  | $$ $$ $$| $$ /$$$$                    JP    dBBBb    97       000              □\n");
	printf("□           #/  nnn                Y&.     mm  mm          &____  $$| $$__  $$| $$  | $$| $$____/ | $$____/   | $$  | $$  $$$$| $$|_  $$                   KP   BBP   ?QB   ?b                       □\n");
	printf("□          @|  888817nnnnn           &.      mm            /$$  & $$| $$  | $$| $$  | $$| $$      | $$        | $$  | $$&  $$$| $$  & $$                  QP   BBr      0P   0D                      □\n");
	printf("□          M|  080 808880808088080,  MC    mm  mm         |  $$$$$$/| $$  | $$|  $$$$$$/| $$      | $$      / $$$$$$| $$ &  $$| $$$$$$/                  QB      'TBBQbv       0D                    □\n");
	printf("□          M|   80  680000000@@@&&P  MD                    &______/ |__/  |__/ &______/ |__/      |__/     |______/ |__ / &__/&______/                  5BB    Bb      TB0    BBs                    □\n");
	printf("□          ML   80  ''Y897P''8000P  ##                                                                                                       000        BBB     TMMbnvdBp     BQ                     □\n");
	printf("□           Y0.  'Ybc______d000P  ,##                                                                                                       0 . 0        LBB:      T0P       rBR                     □\n");
	printf("□            ''Yo,  '''''''''   ,##'                                                                                                        0 0 0         QBB5              PBZ                      □\n");
	printf("□               'YMBbn______.dMP'                                                                                                           0 ' 0           TBBL_________JBBP                        □\n");
	printf("□                    'YMMMMYP'                                                                                                               000              'T0808088080P                          □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□       ,------------------->,         .------------------->.         .------------------->.                       dMMMMMMMMMMMMMMMMMMMMMMMMMMMMb                                                    □\n");
	printf("□      | ,-----------------. #b       | ,-----------------. #b       | ,-----------------. #b        ||            MMM     MMMM  MM  MMM  MM  MM |         ####    ######   ##       ##              □\n");
	printf("□  	| |  ■| ■|,■■,  | ##       | |@)    @)         | ##       | |            CL   | ##        ||            MMM  MM  MMM  MM  MMM  MM  MM |        ##  ##   ##       ##       ##              □\n");
	printf("□      | |  ■| ■|■--■| | ##       | |@@)  @@@)   #)   | ##       | | nMn.     JMMP   | ##        ||            MMM  MM  MMM  MM  MMM  MM  MM |        ##       ##       ##       ##              □\n");
	printf("□      | |  ■■■|■■'#  | ##       | |@@@)P@@@@) #@8)  | ##       | |  'YMbmvndMMK    | ##        ||            MMM     MMMM  MM  MMMM    MMM |         ####    ####     ##       ##              □\n");
	printf("□      | |  ■| ■|■|     | ##       | |@@@@@@@@@@]#@@@@ | ##       | |    >MMMMMMML    | ##        ||            MMM  MM  MMM  MM  MMMMM  MMMM |            ##   ##       ##       ##              □\n");
	printf("□      | |  ■| ■|■|     | ##       | |@@@@@@@@@@@@@@@@)| ##       | |   /MMMMMMMMML   | ##        ||            MMM  MM  MMM  MM  MMMMM  MMMM |        ##  ##   ##       ##       ##              □\n");
	printf("□      | '-----------------' ##       | '-----------------' ##       | '-----------------' ##        ||            MMM     MMMMM    MMMMMM  MMMM |         ####    ######   ######   ######          □\n");
	printf("□      'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#         ||            MMMMMMMMMMMMMMMMMMMMMMMMMMMM# |                                                   □\n");
	printf("□                                                                                                    ||            Y_____________________________#                                                   □\n");
	printf("□       [      HP POTION     ]         [    Attack Boost   ]          [  Monster leather   ]         ||                                                                                              □\n");
	printf("□        ====================           ===================            ====================          ||                  press 'C' button to change BUY ITME MODE or SELL ITEM MODE                  □\n");
	printf("□       [    10$   / %s   ]         [    15$  / %s   ]          [   You can't buy    ]         ||                                                                                              □\n", zeroBUYPotionCnt.c_str(), zeroBUYBoostCnt.c_str());
	printf("□                                                                                                    ||                      When you want to go village press the 'ESC' button                      □\n");
	printf("□       .--------------------.         .--------------------.         .--------------------.         ||                                                                                              □\n");
	printf("□      | ,-----------------. |        | ,-----------------. |        | ,-----------------. |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |      EMPTY      | |        | |      EMPTY      | |        | |      EMPTY      | |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | '-----------------' |        | '-----------------' |        | '-----------------' |         ||                                                                                              □\n");
	printf("□       '___________________/          '___________________/          '___________________/          ||                                                                                              □\n");
	printf("□                                                                                                    ||                                                                                              □\n");
	printf("□      [                    ]          [                    ]        [                    ]          ||                                                                                              □\n");
	printf("□       ====================            ====================          ====================           ||                                                                                              □\n");
	printf("□      [                    ]          [                    ]        [                    ]                                                                                                          □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
}


void CShopStage::SellRender()
{
	//줄 맞추기 용 임시 프린트
	//printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");

	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□                           .dMMMb.                                                                                                                          dC8bv.   ,vSQDb                         □\n");
	printf("□        m  m              ##  ''YMMM.                                                                                                                        JBQBBbvdBBBBK                          □\n");
	printf("□         mm              ##       'YMM                     /$$$$$$  /$$   /$$  /$$$$$$  /$$$$$$$  /$$$$$$$  /$$$$$$ /$$  / $$  /$$$$$$                        J0K      ZK          000              □\n");
	printf("□        m   m   ,onnnnn ##         ##                     /$$__  $$| $$   |$$ /$$__  $$| $$__  $$| $$__  $$|__ $$_/| $$$ | $$ /$$__  $$                        JBbnnnd0C          0 0 0             □\n");
	printf("□              ,d'     'yV        ##                      | $$  &_/ | $$   |$$| $$  & $$| $$  & $$| $$  & $$  | $$  | $$$$| $$| $$  &__/                      dQP   m    9b        0 0 0             □\n");
	printf("□            ,P'                  $.                      |  $$$$$$ | $$$$$$$$| $$  | $$| $$$$$$$/| $$$$$$$/  | $$  | $$ $$ $$| $$ /$$$$                    JP    dBBBb    97       000              □\n");
	printf("□           #/  nnn                Y&.     mm  mm          &____  $$| $$__  $$| $$  | $$| $$____/ | $$____/   | $$  | $$  $$$$| $$|_  $$                   KP   BBP   ?QB   ?b                       □\n");
	printf("□          @|  888817nnnnn           &.      mm            /$$  & $$| $$  | $$| $$  | $$| $$      | $$        | $$  | $$&  $$$| $$  & $$                  QP   BBr      0P   0D                      □\n");
	printf("□          M|  080 808880808088080,  MC    mm  mm         |  $$$$$$/| $$  | $$|  $$$$$$/| $$      | $$      / $$$$$$| $$ &  $$| $$$$$$/                  QB      'TBBQbv       0D                    □\n");
	printf("□          M|   80  680000000@@@&&P  MD                    &______/ |__/  |__/ &______/ |__/      |__/     |______/ |__ / &__/&______/                  5BB    Bb      TB0    BBs                    □\n");
	printf("□          ML   80  ''Y897P''8000P  ##                                                                                                       000        BBB     TMMbnvdBp     BQ                     □\n");
	printf("□           Y0.  'Ybc______d000P  ,##                                                                                                       0 . 0        LBB:      T0P       rBR                     □\n");
	printf("□            ''Yo,  '''''''''   ,##'                                                                                                        0 0 0         QBB5              PBZ                      □\n");
	printf("□               'YMBbn______.dMP'                                                                                                           0 ' 0           TBBL_________JBBP                        □\n");
	printf("□                    'YMMMMYP'                                                                                                               000              'T0808088080P                          □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□       ,------------------->,         .------------------->.         .------------------->.                                                            dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMb       □\n");
	printf("□      | ,-----------------. #b       | ,-----------------. #b       | ,-----------------. #b        ||               #####    ##  ##   ##  ##          MMM    MMMM      MMM  MMMMMMM  MMMMMM |      □\n");
	printf("□  	| |  ■| ■|,■■,  | ##       | |@)    @)         | ##       | |            CL   | ##        ||               ##  ##   ##  ##   ##  ##          MM  MM  MMM  MMMMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | |  ■| ■|■--■| | ##       | |@@)  @@@)   #)   | ##       | | nMn.     JMMP   | ##        ||               ##  ##   ##  ##   ##  ##          MM  MMMMMMM  MMMMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | |  ■■■|■■'#  | ##       | |@@@)P@@@@) #@8)  | ##       | |  'YMbmvndMMK    | ##        ||               #####    ##  ##    ####           MMM    MMMM    MMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | |  ■| ■|■|     | ##       | |@@@@@@@@@@]#@@@@ | ##       | |    >MMMMMMML    | ##        ||               ##  ##   ##  ##     ##            MMMMMM  MMM  MMMMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | |  ■| ■|■|     | ##       | |@@@@@@@@@@@@@@@@)| ##       | |   /MMMMMMMMML   | ##        ||               ##  ##   ##  ##     ##            MM  MM  MMM  MMMMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | '-----------------' ##       | '-----------------' ##       | '-----------------' ##        ||               #####     ####      ##            MMM    MMMM      MMM      MMM      MM |      □\n");
	printf("□      'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#         ||                                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM# |      □\n");
	printf("□                                                                                                    ||                                                 Y_____________________________________#      □\n");
	printf("□       [      HP POTION     ]         [    Attack Boost   ]          [  Monster leather   ]         ||                                                                                              □\n");
	printf("□        ====================           ===================            ====================          ||                  press 'C' button to change BUY ITME MODE or SELL ITEM MODE                  □\n");
	printf("□       [     6$   / %s   ]         [    9$   / %s   ]          [    5$   / %s    ]         ||                                                                                                □\n", zeroSELLPotionCnt.c_str(), zeroSELLBoostCnt.c_str(), zeroSELLMonLeatherCnt.c_str());
	printf("□                                                                                                    ||                      When you want to go village press the 'ESC' button                      □\n");
	printf("□       .--------------------.         .--------------------.         .--------------------.         ||                                                                                              □\n");
	printf("□      | ,-----------------. |        | ,-----------------. |        | ,-----------------. |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |      EMPTY      | |        | |      EMPTY      | |        | |      EMPTY      | |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | '-----------------' |        | '-----------------' |        | '-----------------' |         ||                                                                                              □\n");
	printf("□       '___________________/          '___________________/          '___________________/          ||                                                                                              □\n");
	printf("□                                                                                                    ||                                                                                              □\n");
	printf("□      [                    ]          [                    ]        [                    ]          ||                                                                                              □\n");
	printf("□       ====================            ====================          ====================           ||                                                                                              □\n");
	printf("□      [                    ]          [                    ]        [                    ]                                                                                                          □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
}