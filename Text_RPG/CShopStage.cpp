#include "pch.h"
#include "CShopStage.h"
#include "CStage.h"
#include "CStageManager.h"
#include "CKeyManager.h"
#include "CVillageStage.h"
#include "CItem.h"
#include "CShopManager.h"
#include "CStateStage.h"
#include <Windows.h>

void CShopStage::StageInit()
{
	ItemList = CShopManager::GetInst()->GetItemList();
	CurrItem = static_cast<int>(ITEM_TYPE::HEALTH_POTION);
	ColorOfNotify = 6;
	Notification = "";
	SpaceMaker(Notification, 60);
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

	if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::UP) == KEY_STATE::TAP)
	{
		CStageManager::GetInst()->ChangeStage(new CStateStage);
	}

	// 스페이스바를 눌러 판매/구매를 시도했을 때
	if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::SPACE) == KEY_STATE::TAP)
	{
		if (CurPlayer_Mode == BUYSELL_MODE::BUY)
		{
			Notification = CPlayer::GetInst()->BuyItem(static_cast<ITEM_TYPE>(CurrItem));
			if (Notification.size() == 0)
			{
				ColorOfNotify = 6;
				Notification = "Your purchase was successful !";
			}
			else
			{
				ColorOfNotify = 4;
			}
		}
		else
		{
			Notification = CPlayer::GetInst()->SellItem(static_cast<ITEM_TYPE>(CurrItem));
			if (Notification.size() == 0)
			{
				ColorOfNotify = 6;
				Notification = "Your sale has been successful !";
			}
			else
			{
				ColorOfNotify = 4;
			}
		}

		SpaceMaker(Notification, 60);
		bCallRender = true;
	}

	if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::RIGHT) == KEY_STATE::TAP)
	{
		CurrItem++;
		if (CurrItem == ItemList.size())
		{
			CurrItem = 0;
		}
		CurrItemRender();
	}

	if (CKeyManager::GetInst()->GetKeyState(KEY_TYPE::LEFT) == KEY_STATE::TAP)
	{
		CurrItem--;
		if (CurrItem < 0)
		{
			CurrItem = ItemList.size()-1;
		}
		CurrItemRender();
	}
}


void CShopStage::setConsoleColor(WORD color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
	SetConsoleTextAttribute(hConsole, color);         // 색상 속성 설정
}

void CShopStage::CurrItemRender()
{
	switch (CurrItem)
	{
	case static_cast<int>(ITEM_TYPE::HEALTH_POTION):
		if(CurPlayer_Mode == BUYSELL_MODE::BUY)
		{
			//BUY HEALTH POTION RENDER
			BuyRenderPotion();
		}
		else {
			//SELL HEALTH POTION RENDER
			SellRenderPotion();
		}
		break;
	case static_cast<int>(ITEM_TYPE::ATTACK_BOOST):
		if (CurPlayer_Mode == BUYSELL_MODE::BUY)
		{
			//BUY ATTACK BOOST RENDER
			BuyRenderBooster();
		}
		else {
			//SELL ATTACK BOOST RENDER
			SellRenderBooster();
		}
		break;
	case static_cast<int>(ITEM_TYPE::MONSTER_LEATHER):
		//MONSTER LETHER RENDER
		SellRenderMonLeather();
		break;
	default:
		break;
	}
}

void CShopStage::ChangeBUYSELL()
{
	if (CurPlayer_Mode == BUYSELL_MODE::BUY)
	{
		CurPlayer_Mode = BUYSELL_MODE::SELL;
		ItemList = CPlayer::GetInst()->GetItemList();
		CurrItem = 0;
	}
	else if (CurPlayer_Mode == BUYSELL_MODE::SELL)
	{
		CurPlayer_Mode = BUYSELL_MODE::BUY;
		ItemList = CShopManager::GetInst()->GetItemList();
		CurrItem = 0;
	}
	bCallRender = true;
}

void CShopStage::SpaceMaker(string& _str, int _max)
{
	int start = _str.size();
	for (int i = start; i < _max; i++)
	{
		_str += " ";
	}
}

void CShopStage::StageRender()
{
	std::cout << "\033[2J\033[H";

	shopPotionCnt = CShopManager::GetInst()->GetItemCnt(ITEM_TYPE::HEALTH_POTION);
	shopBoostCnt = CShopManager::GetInst()->GetItemCnt(ITEM_TYPE::ATTACK_BOOST);
	PlayerPotionCnt = CPlayer::GetInst()->GetItemCnt(ITEM_TYPE::HEALTH_POTION);
	PlayerBoostCnt = CPlayer::GetInst()->GetItemCnt(ITEM_TYPE::ATTACK_BOOST);
	PlayerMonLeatherCnt = CPlayer::GetInst()->GetItemCnt(ITEM_TYPE::MONSTER_LEATHER);

	PlayerGold = CPlayer::GetInst()->GetGold();
	PlayerGoldforPrint = std::to_string(PlayerGold) + " \$";
	SpaceMaker(PlayerGoldforPrint, 42);

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

	CurrItemRender();
}


void CShopStage::BuyRenderPotion() //바이 HP포션 랜더
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
	printf("□  	| |"); setConsoleColor(6); printf("  ■| ■|,■■,  "); setConsoleColor(7); printf("| ##       | |@)    @)         | ##       | |            CL   | ##        ||            MMM  MM  MMM  MM  MMM  MM  MM |        ##  ##   ##       ##       ##              □\n");
	printf("□      | |"); setConsoleColor(6); printf("  ■| ■|■--■| "); setConsoleColor(7); printf("| ##       | |@@)  @@@)   #)   | ##       | | nMn.     JMMP   | ##        ||            MMM  MM  MMM  MM  MMM  MM  MM |        ##       ##       ##       ##              □\n");
	printf("□      | |"); setConsoleColor(6); printf("  ■■■|■■'#  "); setConsoleColor(7); printf("| ##       | |@@@)P@@@@) #@8)  | ##       | |  'YMbmvndMMK    | ##        ||            MMM     MMMM  MM  MMMM    MMM |         ####    ####     ##       ##              □\n");
	printf("□      | |"); setConsoleColor(6); printf("  ■| ■|■|     "); setConsoleColor(7); printf("| ##       | |@@@@@@@@@@]#@@@@ | ##       | |    >MMMMMMML    | ##        ||            MMM  MM  MMM  MM  MMMMM  MMMM |            ##   ##       ##       ##              □\n");
	printf("□      | |"); setConsoleColor(6); printf("  ■| ■|■|     "); setConsoleColor(7); printf("| ##       | |@@@@@@@@@@@@@@@@)| ##       | |   /MMMMMMMMML   | ##        ||            MMM  MM  MMM  MM  MMMMM  MMMM |        ##  ##   ##       ##       ##              □\n");
	printf("□      | '-----------------' ##       | '-----------------' ##       | '-----------------' ##        ||            MMM     MMMMM    MMMMMM  MMMM |         ####    ######   ######   ######          □\n");
	printf("□      'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#         ||            MMMMMMMMMMMMMMMMMMMMMMMMMMMM# |                                                   □\n");
	printf("□                                                                                                    ||            Y_____________________________#                                                   □\n");
	printf("□       [     HP POTION     ]          [    Attack Boost   ]          [  Monster leather  ]          ||                                                                                              □\n");
	printf("□        ===================            ===================            ===================           ||                                      "); setConsoleColor(6); printf("Player Gold : % s", PlayerGoldforPrint.c_str()); setConsoleColor(7); printf("□\n");
	printf("□       [    10$  /  %s  ]          [   15$  /  %s   ]          [   You can't buy   ]          ||                                                                                              □\n", zeroBUYPotionCnt.c_str(), zeroBUYBoostCnt.c_str());
	printf("□                                                                                                    ||                  Press 'C' button to change BUY ITME MODE or SELL ITEM MODE                  □\n");
	printf("□       .--------------------.         .--------------------.         .--------------------.         ||                        Press the '←' and '→' keys to select an item                        □\n");
	printf("□      | ,-----------------. |        | ,-----------------. |        | ,-----------------. |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |      EMPTY      | |        | |      EMPTY      | |        | |      EMPTY      | |         ||                                Press Space Bar to BUY the item                               □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                  "); setConsoleColor(ColorOfNotify); printf("%s", Notification.c_str()); setConsoleColor(7); printf("□\n");
	printf("□      | '-----------------' |        | '-----------------' |        | '-----------------' |         ||                                                                                              □\n");
	printf("□       '___________________/          '___________________/          '___________________/          ||                      When you want to go village press the 'ESC' button                      □\n");
	printf("□                                                                                                    ||                                                                                              □\n");
	printf("□       [                   ]          [                   ]          [                   ]          ||                                                                                              □\n");
	printf("□        ===================            ===================            ===================           ||                                                                                              □\n");
	printf("□       [                   ]          [                   ]          [                   ]                                                                                                          □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	Notification = "";
	SpaceMaker(Notification, 60);
}

void CShopStage::BuyRenderBooster() //바이 공격력부스터 랜더
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
	printf("□  	| |  ■| ■|,■■,  | ##       | |"); setConsoleColor(6); printf("@)    @)         "); setConsoleColor(7); printf("| ##       | |            CL   | ##        ||            MMM  MM  MMM  MM  MMM  MM  MM |        ##  ##   ##       ##       ##              □\n");
	printf("□      | |  ■| ■|■--■| | ##       | |"); setConsoleColor(6); printf("@@)  @@@)   #)   "); setConsoleColor(7); printf("| ##       | | nMn.     JMMP   | ##        ||            MMM  MM  MMM  MM  MMM  MM  MM |        ##       ##       ##       ##              □\n");
	printf("□      | |  ■■■|■■'#  | ##       | |"); setConsoleColor(6); printf("@@@)P@@@@) #@8)  "); setConsoleColor(7); printf("| ##       | |  'YMbmvndMMK    | ##        ||            MMM     MMMM  MM  MMMM    MMM |         ####    ####     ##       ##              □\n");
	printf("□      | |  ■| ■|■|     | ##       | |"); setConsoleColor(6); printf("@@@@@@@@@@]#@@@@ "); setConsoleColor(7); printf("| ##       | |    >MMMMMMML    | ##        ||            MMM  MM  MMM  MM  MMMMM  MMMM |            ##   ##       ##       ##              □\n");
	printf("□      | |  ■| ■|■|     | ##       | |"); setConsoleColor(6); printf("@@@@@@@@@@@@@@@@)"); setConsoleColor(7); printf("| ##       | |   /MMMMMMMMML   | ##        ||            MMM  MM  MMM  MM  MMMMM  MMMM |        ##  ##   ##       ##       ##              □\n");
	printf("□      | '-----------------' ##       | '-----------------' ##       | '-----------------' ##        ||            MMM     MMMMM    MMMMMM  MMMM |         ####    ######   ######   ######          □\n");
	printf("□      'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#         ||            MMMMMMMMMMMMMMMMMMMMMMMMMMMM# |                                                   □\n");
	printf("□                                                                                                    ||            Y_____________________________#                                                   □\n");
	printf("□       [     HP POTION     ]          [    Attack Boost   ]          [  Monster leather  ]          ||                                                                                              □\n");
	printf("□        ===================            ===================            ===================           ||                                      "); setConsoleColor(6); printf("Player Gold : % s", PlayerGoldforPrint.c_str()); setConsoleColor(7); printf("□\n");
	printf("□       [    10$  /  %s  ]          [   15$  /  %s   ]          [   You can't buy   ]          ||                                                                                              □\n", zeroBUYPotionCnt.c_str(), zeroBUYBoostCnt.c_str());
	printf("□                                                                                                    ||                  Press 'C' button to change BUY ITME MODE or SELL ITEM MODE                  □\n");
	printf("□       .--------------------.         .--------------------.         .--------------------.         ||                        Press the '←' and '→' keys to select an item                        □\n");
	printf("□      | ,-----------------. |        | ,-----------------. |        | ,-----------------. |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |      EMPTY      | |        | |      EMPTY      | |        | |      EMPTY      | |         ||                                Press Space Bar to BUY the item                               □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                  "); setConsoleColor(ColorOfNotify); printf("%s", Notification.c_str()); setConsoleColor(7); printf("□\n");
	printf("□      | '-----------------' |        | '-----------------' |        | '-----------------' |         ||                                                                                              □\n");
	printf("□       '___________________/          '___________________/          '___________________/          ||                      When you want to go village press the 'ESC' button                      □\n");
	printf("□                                                                                                    ||                                                                                              □\n");
	printf("□       [                   ]          [                   ]          [                   ]          ||                                                                                              □\n");
	printf("□        ===================            ===================            ===================           ||                                                                                              □\n");
	printf("□       [                   ]          [                   ]          [                   ]                                                                                                          □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	Notification = "";
	SpaceMaker(Notification, 60);
}


void CShopStage::SellRenderPotion() // 셀 HP포션 랜더
{
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
	printf("□  	| |"); setConsoleColor(6); printf("  ■| ■|,■■,  "); setConsoleColor(7); printf("| ##       | |@)    @)         | ##       | |            CL   | ##        ||               ##  ##   ##  ##   ##  ##          MM  MM  MMM  MMMMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | |"); setConsoleColor(6); printf("  ■| ■|■--■| "); setConsoleColor(7); printf("| ##       | |@@)  @@@)   #)   | ##       | | nMn.     JMMP   | ##        ||               ##  ##   ##  ##   ##  ##          MM  MMMMMMM  MMMMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | |"); setConsoleColor(6); printf("  ■■■|■■'#  "); setConsoleColor(7); printf("| ##       | |@@@)P@@@@) #@8)  | ##       | |  'YMbmvndMMK    | ##        ||               #####    ##  ##    ####           MMM    MMMM    MMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | |"); setConsoleColor(6); printf("  ■| ■|■|     "); setConsoleColor(7); printf("| ##       | |@@@@@@@@@@]#@@@@ | ##       | |    >MMMMMMML    | ##        ||               ##  ##   ##  ##     ##            MMMMMM  MMM  MMMMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | |"); setConsoleColor(6); printf("  ■| ■|■|     "); setConsoleColor(7); printf("| ##       | |@@@@@@@@@@@@@@@@)| ##       | |   /MMMMMMMMML   | ##        ||               ##  ##   ##  ##     ##            MM  MM  MMM  MMMMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | '-----------------' ##       | '-----------------' ##       | '-----------------' ##        ||               #####     ####      ##            MMM    MMMM      MMM      MMM      MM |      □\n");
	printf("□      'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#         ||                                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM# |      □\n");
	printf("□                                                                                                    ||                                                 Y_____________________________________#      □\n");
	printf("□       [     HP POTION     ]          [    Attack Boost   ]          [  Monster leather  ]          ||                                                                                              □\n");
	printf("□        ===================            ===================            ===================           ||                                      "); setConsoleColor(6); printf("Player Gold : % s", PlayerGoldforPrint.c_str()); setConsoleColor(7); printf("□\n");
	printf("□       [    6$   /  %s  ]          [   9$   /  %s   ]          [    5$   /  %s  ]          ||                                                                                              □\n", zeroSELLPotionCnt.c_str(), zeroSELLBoostCnt.c_str(), zeroSELLMonLeatherCnt.c_str());
	printf("□                                                                                                    ||                  Press 'C' button to change BUY ITME MODE or SELL ITEM MODE                  □\n");
	printf("□       .--------------------.         .--------------------.         .--------------------.         ||                        Press the '←' and '→' keys to select an item                        □\n");
	printf("□      | ,-----------------. |        | ,-----------------. |        | ,-----------------. |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |      EMPTY      | |        | |      EMPTY      | |        | |      EMPTY      | |         ||                               Press Space Bar to SELL the item                               □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                  "); setConsoleColor(ColorOfNotify); printf("%s", Notification.c_str()); setConsoleColor(7); printf("□\n");
	printf("□      | '-----------------' |        | '-----------------' |        | '-----------------' |         ||                                                                                              □\n");
	printf("□       '___________________/          '___________________/          '___________________/          ||                      When you want to go village press the 'ESC' button                      □\n");
	printf("□                                                                                                    ||                                                                                              □\n");
	printf("□       [                   ]          [                   ]          [                   ]          ||                                                                                              □\n");
	printf("□        ===================            ===================            ===================           ||                                                                                              □\n");
	printf("□       [                   ]          [                   ]          [                   ]                                                                                                          □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	Notification = "";
	SpaceMaker(Notification, 60);
}

void CShopStage::SellRenderBooster() // 셀 공격력 부스터 랜더
{
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
	printf("□  	| |  ■| ■|,■■,  | ##       | |"); setConsoleColor(6); printf("@)    @)         "); setConsoleColor(7); printf("| ##       | |            CL   | ##        ||               ##  ##   ##  ##   ##  ##          MM  MM  MMM  MMMMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | |  ■| ■|■--■| | ##       | |"); setConsoleColor(6); printf("@@)  @@@)   #)   "); setConsoleColor(7); printf("| ##       | | nMn.     JMMP   | ##        ||               ##  ##   ##  ##   ##  ##          MM  MMMMMMM  MMMMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | |  ■■■|■■'#  | ##       | |"); setConsoleColor(6); printf("@@@)P@@@@) #@8)  "); setConsoleColor(7); printf("| ##       | |  'YMbmvndMMK    | ##        ||               #####    ##  ##    ####           MMM    MMMM    MMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | |  ■| ■|■|     | ##       | |"); setConsoleColor(6); printf("@@@@@@@@@@]#@@@@ "); setConsoleColor(7); printf("| ##       | |    >MMMMMMML    | ##        ||               ##  ##   ##  ##     ##            MMMMMM  MMM  MMMMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | |  ■| ■|■|     | ##       | |"); setConsoleColor(6); printf("@@@@@@@@@@@@@@@@)"); setConsoleColor(7); printf("| ##       | |   /MMMMMMMMML   | ##        ||               ##  ##   ##  ##     ##            MM  MM  MMM  MMMMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | '-----------------' ##       | '-----------------' ##       | '-----------------' ##        ||               #####     ####      ##            MMM    MMMM      MMM      MMM      MM |      □\n");
	printf("□      'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#         ||                                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM# |      □\n");
	printf("□                                                                                                    ||                                                 Y_____________________________________#      □\n");
	printf("□       [     HP POTION     ]          [    Attack Boost   ]          [  Monster leather  ]          ||                                                                                              □\n");
	printf("□        ===================            ===================            ===================           ||                                      "); setConsoleColor(6); printf("Player Gold : % s", PlayerGoldforPrint.c_str()); setConsoleColor(7); printf("□\n");
	printf("□       [    6$   /  %s  ]          [   9$   /  %s   ]          [    5$   /  %s  ]          ||                                                                                              □\n", zeroSELLPotionCnt.c_str(), zeroSELLBoostCnt.c_str(), zeroSELLMonLeatherCnt.c_str());
	printf("□                                                                                                    ||                  Press 'C' button to change BUY ITME MODE or SELL ITEM MODE                  □\n");
	printf("□       .--------------------.         .--------------------.         .--------------------.         ||                        Press the '←' and '→' keys to select an item                        □\n");
	printf("□      | ,-----------------. |        | ,-----------------. |        | ,-----------------. |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |      EMPTY      | |        | |      EMPTY      | |        | |      EMPTY      | |         ||                               Press Space Bar to SELL the item                               □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                  "); setConsoleColor(ColorOfNotify); printf("%s", Notification.c_str()); setConsoleColor(7); printf("□\n");
	printf("□      | '-----------------' |        | '-----------------' |        | '-----------------' |         ||                                                                                              □\n");
	printf("□       '___________________/          '___________________/          '___________________/          ||                      When you want to go village press the 'ESC' button                      □\n");
	printf("□                                                                                                    ||                                                                                              □\n");
	printf("□       [                   ]          [                   ]          [                   ]          ||                                                                                              □\n");
	printf("□        ===================            ===================            ===================           ||                                                                                              □\n");
	printf("□       [                   ]          [                   ]          [                   ]                                                                                                          □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	Notification = "";
	SpaceMaker(Notification, 60);
}



void CShopStage::SellRenderMonLeather() // 셀 몬스터가죽 랜더
{
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
	printf("□  	| |  ■| ■|,■■,  | ##       | |@)    @)         | ##       | |"); setConsoleColor(6); printf("            CL   "); setConsoleColor(7); printf("| ##        ||               ##  ##   ##  ##   ##  ##          MM  MM  MMM  MMMMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | |  ■| ■|■--■| | ##       | |@@)  @@@)   #)   | ##       | |"); setConsoleColor(6); printf(" nMn.     JMMP   "); setConsoleColor(7); printf("| ##        ||               ##  ##   ##  ##   ##  ##          MM  MMMMMMM  MMMMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | |  ■■■|■■'#  | ##       | |@@@)P@@@@) #@8)  | ##       | |"); setConsoleColor(6); printf("  'YMbmvndMMK    "); setConsoleColor(7); printf("| ##        ||               #####    ##  ##    ####           MMM    MMMM    MMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | |  ■| ■|■|     | ##       | |@@@@@@@@@@]#@@@@ | ##       | |"); setConsoleColor(6); printf("    >MMMMMMML    "); setConsoleColor(7); printf("| ##        ||               ##  ##   ##  ##     ##            MMMMMM  MMM  MMMMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | |  ■| ■|■|     | ##       | |@@@@@@@@@@@@@@@@)| ##       | |"); setConsoleColor(6); printf("   /MMMMMMMMML   "); setConsoleColor(7); printf("| ##        ||               ##  ##   ##  ##     ##            MM  MM  MMM  MMMMMMM  MMMMMMM  MMMMMM |      □\n");
	printf("□      | '-----------------' ##       | '-----------------' ##       | '-----------------' ##        ||               #####     ####      ##            MMM    MMMM      MMM      MMM      MM |      □\n");
	printf("□      'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#        'YMMMMMMMMMMMMMMMMMMMM#         ||                                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM# |      □\n");
	printf("□                                                                                                    ||                                                 Y_____________________________________#      □\n");
	printf("□       [     HP POTION     ]          [    Attack Boost   ]          [  Monster leather  ]          ||                                                                                              □\n");
	printf("□        ===================            ===================            ===================           ||                                      "); setConsoleColor(6); printf("Player Gold : % s", PlayerGoldforPrint.c_str()); setConsoleColor(7); printf("□\n");
	printf("□       [    6$   /  %s  ]          [   9$   /  %s   ]          [    5$   /  %s  ]          ||                                                                                              □\n", zeroSELLPotionCnt.c_str(), zeroSELLBoostCnt.c_str(), zeroSELLMonLeatherCnt.c_str());
	printf("□                                                                                                    ||                  Press 'C' button to change BUY ITME MODE or SELL ITEM MODE                  □\n");
	printf("□       .--------------------.         .--------------------.         .--------------------.         ||                        Press the '←' and '→' keys to select an item                        □\n");
	printf("□      | ,-----------------. |        | ,-----------------. |        | ,-----------------. |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |      EMPTY      | |        | |      EMPTY      | |        | |      EMPTY      | |         ||                               Press Space Bar to SELL the item                               □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                                                                              □\n");
	printf("□      | |                 | |        | |                 | |        | |                 | |         ||                                  "); setConsoleColor(ColorOfNotify); printf("%s", Notification.c_str()); setConsoleColor(7); printf("□\n");
	printf("□      | '-----------------' |        | '-----------------' |        | '-----------------' |         ||                                                                                              □\n");
	printf("□       '___________________/          '___________________/          '___________________/          ||                      When you want to go village press the 'ESC' button                      □\n");
	printf("□                                                                                                    ||                                                                                              □\n");
	printf("□       [                   ]          [                   ]          [                   ]          ||                                                                                              □\n");
	printf("□        ===================            ===================            ===================           ||                                                                                              □\n");
	printf("□       [                   ]          [                   ]          [                   ]                                                                                                          □\n");
	printf("□                                                                                                                                                                                                    □\n");
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	Notification = "";
	SpaceMaker(Notification, 60);
}