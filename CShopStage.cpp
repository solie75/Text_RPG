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
	//มู ธยร฿ฑโ ฟ๋ ภำฝร วมธฐฦฎ
	//printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");

	printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
	printf("กเ                                                                                                                                                                                                    กเ\n");
	printf("กเ                                                                                                                                                                                                    กเ\n");
	printf("กเ                           .dMMMb.                                                                                                                          dC8bv.   ,vSQDb                         กเ\n");
	printf("กเ        m  m              ##  ''YMMM.                                                                                                                        JBQBBbvdBBBBK                          กเ\n");
	printf("กเ         mm              ##       'YMM                     /$$$$$$  /$$   /$$  /$$$$$$  /$$$$$$$  /$$$$$$$  /$$$$$$ /$$  / $$  /$$$$$$                        J0K      ZK          000              กเ\n");
	printf("กเ        m   m   ,onnnnn ##         ##                     /$$__  $$| $$   |$$ /$$__  $$| $$__  $$| $$__  $$|__ $$_/| $$$ | $$ /$$__  $$                        JBbnnnd0C          0 0 0             กเ\n");
	printf("กเ              ,d'     'yV        ##                      | $$  &_/ | $$   |$$| $$  & $$| $$  & $$| $$  & $$  | $$  | $$$$| $$| $$  &__/                      dQP   m    9b        0 0 0             กเ\n");
	printf("กเ            ,P'                  $.                      |  $$$$$$ | $$$$$$$$| $$  | $$| $$$$$$$/| $$$$$$$/  | $$  | $$ $$ $$| $$ /$$$$                    JP    dBBBb    97       000              กเ\n");
	printf("กเ           #/  nnn                Y&.     mm  mm          &____  $$| $$__  $$| $$  | $$| $$____/ | $$____/   | $$  | $$  $$$$| $$|_  $$                   KP   BBP   ?QB   ?b                       กเ\n");
	printf("กเ          @|  888817nnnnn           &.      mm            /$$  & $$| $$  | $$| $$  | $$| $$      | $$        | $$  | $$&  $$$| $$  & $$                  QP   BBr      0P   0D                      กเ\n");
	printf("กเ          M|  080 808880808088080,  MC    mm  mm         |  $$$$$$/| $$  | $$|  $$$$$$/| $$      | $$      / $$$$$$| $$ &  $$| $$$$$$/                  QB      'TBBQbv       0D                    กเ\n");
	printf("กเ          M|   80  680000000@@@&&P  MD                    &______/ |__/  |__/ &______/ |__/      |__/     |______/ |__ / &__/&______/                  5BB    Bb      TB0    BBs                    กเ\n");
	printf("กเ          ML   80  ''Y897P''8000P  ##                                                                                                       000        BBB     TMMbnvdBp     BQ                     กเ\n");
	printf("กเ           Y0.  'Ybc______d000P  ,##                                                                                                       0 . 0        LBB:      T0P       rBR                     กเ\n");
	printf("กเ            ''Yo,  '''''''''   ,##'                                                                                                        0 0 0         QBB5              PBZ                      กเ\n");
	printf("กเ               'YMBbn______.dMP'                                                                                                           0 ' 0           TBBL_________JBBP                        กเ\n");
	printf("กเ                    'YMMMMYP'                                                                                                               000              'T0808088080P                          กเ\n");
	printf("กเ                                                                                                                                                                                                    กเ\n");
	printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
	printf("กเ                                                                                                                                                                                                    กเ\n");
	printf("กเ       ,------------------->,         .------------------->.         .------------------->.                       dMMMMMMMMMMMMMMMMMMMMMMMMMMMMb                                                    กเ\n");
	printf("กเ      | ,-----------------. #b       | ,-----------------. #b       | ,-----------------. #b        ||            MMM     MMMM  MM  MMM  MM  MM |         ####    ######   ##       ##              กเ\n");
	printf("กเ  	| |  กแ| กแ|,กแกแ,  | ##       | |@)    @)         | ##       | |            CL   | ##        ||            MMM  MM  MMM  MM  MMM  MM  MM |        ##  ##   ##       ##       ##              กเ\n");
	printf("กเ      | |  กแ| กแ|กแ--กแ| | ##       | |@@)  @@@)   #)   | ##       | | nMn.     JMMP   | ##        ||            MMM  MM  MMM  MM  MMM  MM  MM |        ##       ##       ##       ##              กเ\n");
	printf("กเ      | |  กแกแกแ|กแกแ'#  | ##       | |@@@)P@@@@) #@8)  | ##       | |  'YMbmvndMMK    | ##        ||            MMM     MMMM  MM  MMMM    MMM |         ####    ####     ##       ##              กเ\n");
	printf("กเ      | |  กแ| กแ|กแ|     | ##       | |@@@@@@@@@@]#@@@@ | ##       | |    >MMMMMMML    | ##        ||            MMM  MM  MMM  MM  MMMMM  MMMM |            ##   ##       ##       ##              กเ\n");
	printf("กเ      | |  กแ| กแ|กแ|     | ##       | |@@@@@@@@@@@@@@@@)| ##       | |   /MMMMMMMMML   | ##        ||            MMM  MM  MMM  MM  MMMMM  MMMM |        ##  ##   ##       ##       ##              กเ\n");
	printf("กเ      | '-----------------' ##       | '-----------------' ##       | '-----------------' ##        ||            MMM     MMMMM    MMMMMM  MMMM |         ####    ######   ######   ######          กเ\n");
	printf("กเ      'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#         ||            MMMMMMMMMMMMMMMMMMMMMMMMMMMM# |                                                   กเ\n");
	printf("กเ                                                                                                    ||            Y_____________________________#                                                   กเ\n");
	printf("กเ       [      HP POTION     ]         [    Attack Boost   ]          [  Monster leather   ]         ||                                                                                              กเ\n");
	printf("กเ        ====================           ===================            ====================          ||                  press 'C' button to change BUY ITME MODE or SELL ITEM MODE                  กเ\n");
	printf("กเ       [    10$   / %s   ]         [    15$  / %s   ]          [   You can't buy    ]         ||                                                                                              กเ\n", zeroBUYPotionCnt.c_str(), zeroBUYBoostCnt.c_str());
	printf("กเ                                                                                                    ||                      When you want to go village press the 'ESC' button                      กเ\n");
	printf("กเ       .--------------------.         .--------------------.         .--------------------.         ||                                                                                              กเ\n");
	printf("กเ      | ,-----------------. |        | ,-----------------. |        | ,-----------------. |         ||                                                                                              กเ\n");
	printf("กเ      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              กเ\n");
	printf("กเ      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              กเ\n");
	printf("กเ      | |      EMPTY      | |        | |      EMPTY      | |        | |      EMPTY      | |         ||                                                                                              กเ\n");
	printf("กเ      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              กเ\n");
	printf("กเ      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              กเ\n");
	printf("กเ      | '-----------------' |        | '-----------------' |        | '-----------------' |         ||                                                                                              กเ\n");
	printf("กเ       '___________________/          '___________________/          '___________________/          ||                                                                                              กเ\n");
	printf("กเ                                                                                                    ||                                                                                              กเ\n");
	printf("กเ      [                    ]          [                    ]        [                    ]          ||                                                                                              กเ\n");
	printf("กเ       ====================            ====================          ====================           ||                                                                                              กเ\n");
	printf("กเ      [                    ]          [                    ]        [                    ]                                                                                                          กเ\n");
	printf("กเ                                                                                                                                                                                                    กเ\n");
	printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
}


void CShopStage::SellRender()
{
	//มู ธยร฿ฑโ ฟ๋ ภำฝร วมธฐฦฎ
	//printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");

	printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
	printf("กเ                                                                                                                                                                                                    กเ\n");
	printf("กเ                                                                                                                                                                                                    กเ\n");
	printf("กเ                           .dMMMb.                                                                                                                          dC8bv.   ,vSQDb                         กเ\n");
	printf("กเ        m  m              ##  ''YMMM.                                                                                                                        JBQBBbvdBBBBK                          กเ\n");
	printf("กเ         mm              ##       'YMM                     /$$$$$$  /$$   /$$  /$$$$$$  /$$$$$$$  /$$$$$$$  /$$$$$$ /$$  / $$  /$$$$$$                        J0K      ZK          000              กเ\n");
	printf("กเ        m   m   ,onnnnn ##         ##                     /$$__  $$| $$   |$$ /$$__  $$| $$__  $$| $$__  $$|__ $$_/| $$$ | $$ /$$__  $$                        JBbnnnd0C          0 0 0             กเ\n");
	printf("กเ              ,d'     'yV        ##                      | $$  &_/ | $$   |$$| $$  & $$| $$  & $$| $$  & $$  | $$  | $$$$| $$| $$  &__/                      dQP   m    9b        0 0 0             กเ\n");
	printf("กเ            ,P'                  $.                      |  $$$$$$ | $$$$$$$$| $$  | $$| $$$$$$$/| $$$$$$$/  | $$  | $$ $$ $$| $$ /$$$$                    JP    dBBBb    97       000              กเ\n");
	printf("กเ           #/  nnn                Y&.     mm  mm          &____  $$| $$__  $$| $$  | $$| $$____/ | $$____/   | $$  | $$  $$$$| $$|_  $$                   KP   BBP   ?QB   ?b                       กเ\n");
	printf("กเ          @|  888817nnnnn           &.      mm            /$$  & $$| $$  | $$| $$  | $$| $$      | $$        | $$  | $$&  $$$| $$  & $$                  QP   BBr      0P   0D                      กเ\n");
	printf("กเ          M|  080 808880808088080,  MC    mm  mm         |  $$$$$$/| $$  | $$|  $$$$$$/| $$      | $$      / $$$$$$| $$ &  $$| $$$$$$/                  QB      'TBBQbv       0D                    กเ\n");
	printf("กเ          M|   80  680000000@@@&&P  MD                    &______/ |__/  |__/ &______/ |__/      |__/     |______/ |__ / &__/&______/                  5BB    Bb      TB0    BBs                    กเ\n");
	printf("กเ          ML   80  ''Y897P''8000P  ##                                                                                                       000        BBB     TMMbnvdBp     BQ                     กเ\n");
	printf("กเ           Y0.  'Ybc______d000P  ,##                                                                                                       0 . 0        LBB:      T0P       rBR                     กเ\n");
	printf("กเ            ''Yo,  '''''''''   ,##'                                                                                                        0 0 0         QBB5              PBZ                      กเ\n");
	printf("กเ               'YMBbn______.dMP'                                                                                                           0 ' 0           TBBL_________JBBP                        กเ\n");
	printf("กเ                    'YMMMMYP'                                                                                                               000              'T0808088080P                          กเ\n");
	printf("กเ                                                                                                                                                                                                    กเ\n");
	printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ\n");
	printf("กเ                                                                                                                                                                                                    กเ\n");
	printf("กเ       ,------------------->,         .------------------->.         .------------------->.                                                            dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMb       กเ\n");
	printf("กเ      | ,-----------------. #b       | ,-----------------. #b       | ,-----------------. #b        ||               #####    ##  ##   ##  ##          MMM    MMMM      MMM  MMMMMMM  MMMMMM |      กเ\n");
	printf("กเ  	| |  กแ| กแ|,กแกแ,  | ##       | |@)    @)         | ##       | |            CL   | ##        ||               ##  ##   ##  ##   ##  ##          MM  MM  MMM  MMMMMMM  MMMMMMM  MMMMMM |      กเ\n");
	printf("กเ      | |  กแ| กแ|กแ--กแ| | ##       | |@@)  @@@)   #)   | ##       | | nMn.     JMMP   | ##        ||               ##  ##   ##  ##   ##  ##          MM  MMMMMMM  MMMMMMM  MMMMMMM  MMMMMM |      กเ\n");
	printf("กเ      | |  กแกแกแ|กแกแ'#  | ##       | |@@@)P@@@@) #@8)  | ##       | |  'YMbmvndMMK    | ##        ||               #####    ##  ##    ####           MMM    MMMM    MMMMM  MMMMMMM  MMMMMM |      กเ\n");
	printf("กเ      | |  กแ| กแ|กแ|     | ##       | |@@@@@@@@@@]#@@@@ | ##       | |    >MMMMMMML    | ##        ||               ##  ##   ##  ##     ##            MMMMMM  MMM  MMMMMMM  MMMMMMM  MMMMMM |      กเ\n");
	printf("กเ      | |  กแ| กแ|กแ|     | ##       | |@@@@@@@@@@@@@@@@)| ##       | |   /MMMMMMMMML   | ##        ||               ##  ##   ##  ##     ##            MM  MM  MMM  MMMMMMM  MMMMMMM  MMMMMM |      กเ\n");
	printf("กเ      | '-----------------' ##       | '-----------------' ##       | '-----------------' ##        ||               #####     ####      ##            MMM    MMMM      MMM      MMM      MM |      กเ\n");
	printf("กเ      'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#         ||                                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM# |      กเ\n");
	printf("กเ                                                                                                    ||                                                 Y_____________________________________#      กเ\n");
	printf("กเ       [      HP POTION     ]         [    Attack Boost   ]          [  Monster leather   ]         ||                                                                                              กเ\n");
	printf("กเ        ====================           ===================            ====================          ||                  press 'C' button to change BUY ITME MODE or SELL ITEM MODE                  กเ\n");
	printf("กเ       [     6$   / %s   ]         [    9$   / %s   ]          [    5$   / %s    ]         ||                                                                                                กเ\n", zeroSELLPotionCnt.c_str(), zeroSELLBoostCnt.c_str(), zeroSELLMonLeatherCnt.c_str());
	printf("กเ                                                                                                    ||                      When you want to go village press the 'ESC' button                      กเ\n");
	printf("กเ       .--------------------.         .--------------------.         .--------------------.         ||                                                                                              กเ\n");
	printf("กเ      | ,-----------------. |        | ,-----------------. |        | ,-----------------. |         ||                                                                                              กเ\n");
	printf("กเ      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              กเ\n");
	printf("กเ      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              กเ\n");
	printf("กเ      | |      EMPTY      | |        | |      EMPTY      | |        | |      EMPTY      | |         ||                                                                                              กเ\n");
	printf("กเ      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              กเ\n");
	printf("กเ      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              กเ\n");
	printf("กเ      | '-----------------' |        | '-----------------' |        | '-----------------' |         ||                                                                                              กเ\n");
	printf("กเ       '___________________/          '___________________/          '___________________/          ||                                                                                              กเ\n");
	printf("กเ                                                                                                    ||                                                                                              กเ\n");
	printf("กเ      [                    ]          [                    ]        [                    ]          ||                                                                                              กเ\n");
	printf("กเ       ====================            ====================          ====================           ||                                                                                              กเ\n");
	printf("กเ      [                    ]          [                    ]        [                    ]                                                                                                          กเ\n");
	printf("กเ                                                                                                                                                                                                    กเ\n");
	printf("กเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเกเ");
}