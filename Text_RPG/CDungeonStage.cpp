#include "pch.h"
#include "CDungeonStage.h"
#include "CPlayer.h"
#include "CBattleManager.h"
#include "CTimeManager.h"
#include "CStageManager.h"
#include "CVillageStage.h"
#include "CKeyManager.h"

void CDungeonStage::StageInit()
{
	bIsAbleNextStep = false;
	CBattleManager::GetInst()->InitBattleManager();
	this->StageRender();
	TextRenderInit();
}


void CDungeonStage::StageTick()
{
}

void CDungeonStage::StageRender()
{
	const int Max_TextBoxBlockSpace = 28;
	const int Max_MonsterBoxBlockSpace = 69;
	vector<string> RenderText;
	vector<string> MonsterRender;

	int ColorOfPlayerHP = 7;
	int ColorOfMobHP = 7;
	int ColorOfDropItem = 7;
	int ColorOfDamage = 7;

	//몬스터의 랜더용 텍스트를 들고오고, 뒤에 필요한 만큼 공백넣기
	for (int i = 0; i < Monster->GetTextImgSize(); i++)
	{
		MonsterRender.push_back(Monster->GetTextImgLine(i));
		SpaceMaker(MonsterRender[i], Max_MonsterBoxBlockSpace);
	}

	//플레이어와 몬스터의 이름을 넣기
	string strPlayerName = "  " + CPlayer::GetInst()->GetName();
	string strMonsterName ="  " + Monster->GetName();
	SpaceMaker(strPlayerName, Max_TextBoxBlockSpace);
	SpaceMaker(strMonsterName, Max_TextBoxBlockSpace);

	//플레이어의 레벨만 넣기
	string strPlayerLevel = "  Level : " + std::to_string(CPlayer::GetInst()->GetLevel());
	SpaceMaker(strPlayerLevel, Max_TextBoxBlockSpace);

	//플레이어와 몬스터의 현재 체력 넣기
	string strPlayerHealth = std::to_string(CPlayer::GetInst()->GetHealth());
	string strMonsterHealth = std::to_string(Monster->GetHealth());
	SpaceMaker(strPlayerHealth, 11);
	SpaceMaker(strMonsterHealth, 11);

	//플레이어와 몬스터의 공격력 넣기
	string strPlayerDamage = std::to_string(CPlayer::GetInst()->GetDamage());
	string strMonsterDamage = "  Damage : " + std::to_string(Monster->GetDamage());
	SpaceMaker(strPlayerDamage, 17);
	SpaceMaker(strMonsterDamage, Max_TextBoxBlockSpace);

	//전투로그
	vector<string> PlayerHitLog(MaxHitLogSpace, " ");
	vector<string> MonsterHitLog(MaxHitLogSpace, " ");
	int PHLIndex = 0;
	int MHLIndex = 0;

	//공백 맞추기
	for (int i = 0; i < PlayerHitLog.size(); i++)
	{
		SpaceMaker(PlayerHitLog[i], Max_TextBoxBlockSpace);
	}
	for (int i = 0; i < MonsterHitLog.size(); i++)
	{
		SpaceMaker(MonsterHitLog[i], Max_TextBoxBlockSpace);
	}

	//전투가 종료되었는지 확인 - T : 전투종료, F : 전투 진행 중
	if (CBattleManager::GetInst()->GetIsEndBattle() == false)
	{// 전투 진행중

		for (auto it : BattleLog) 
		{
			// 전투 턴 상황 : 포션마시기, 플레이어 공격, 몬스터 공격 3가지 경우
			if (it.first == BATTLE_TURN_TYPE::PLAYER_ATTACK) // 플레이어가 공격함
			{
				ColorOfPlayerHP = 7;
				if (it.second == BATTLE_RESULT_TYPE::ATTACK_SUCCESS)
				{
					PlayerHitLog[PHLIndex] = "  HIT : " + std::to_string(CPlayer::GetInst()->GetDamage());
					ColorOfMobHP = 4;
				}
				else
				{
					PlayerHitLog[PHLIndex] = "  MISS";
				}
				SpaceMaker(PlayerHitLog[PHLIndex], Max_TextBoxBlockSpace);
				PHLIndex = (PHLIndex + 1) % MaxHitLogSpace;

				//다시 첫줄부터 써야하는 경우 : 마지막줄 빼고 나머지는 리셋
				if (PHLIndex == 0)
				{
					for (int i = 0; i < PlayerHitLog.size() - 1; i++)
					{
						PlayerHitLog[i] = "";
						SpaceMaker(PlayerHitLog[i], Max_TextBoxBlockSpace);
					}
				}
			}
			else if (it.first == BATTLE_TURN_TYPE::MONSTER_ATTACK) // 몬스터가 공격함
			{
				ColorOfMobHP = 7;
				if (it.second == BATTLE_RESULT_TYPE::ATTACK_SUCCESS)
				{
					MonsterHitLog[MHLIndex] = "  HIT : " + std::to_string(Monster->GetDamage());
					ColorOfPlayerHP = 4;
				}
				else
				{
					MonsterHitLog[MHLIndex] = "  MISS";
				}
				SpaceMaker(MonsterHitLog[MHLIndex], Max_TextBoxBlockSpace);
				MHLIndex = (MHLIndex + 1) % MaxHitLogSpace;

				//다시 첫줄부터 써야하는 경우 : 마지막줄 빼고 나머지는 리셋
				if (MHLIndex == 0)
				{
					for (int i = 0; i < MonsterHitLog.size() - 1; i++)
					{
						MonsterHitLog[i] = "";
						SpaceMaker(MonsterHitLog[i], Max_TextBoxBlockSpace);
					}
				}
			}
			else // 아이템을 사용
			{
				if (it.second == BATTLE_RESULT_TYPE::USE_HEALTH_POTION) // 힐링포션
				{
					PlayerHitLog[PHLIndex] = "  Use Heal";
					ColorOfPlayerHP = 2;
				}
				else // 어택포션
				{
					PlayerHitLog[PHLIndex] = "  Use Damage Up";
					ColorOfDamage = 2;
				}
				SpaceMaker(PlayerHitLog[PHLIndex], Max_TextBoxBlockSpace);
				PHLIndex = (PHLIndex + 1) % MaxHitLogSpace;
			}
		}
	}
	else
	{//전투 종료
		bool isWin = CBattleManager::GetInst()->GetIsPlayerWinner();
		CPlayer::GetInst()->SetBoolHealAccess(true);

		if (isWin)
		{
			PlayerHitLog = TextRenderWin;

			SpaceMaker(PlayerHitLog[1], Max_TextBoxBlockSpace);
			MonsterHitLog[0] = "Drop Item : " + dropItemName;
			ColorOfDropItem = 6;
		}
		else
		{
			PlayerHitLog = TextRenderLose;
		}
		MonsterHitLog[1] = " Press Spacebar";
		MonsterHitLog[2] = "             to continue";
		for (int i = 0; i < PlayerHitLog.size(); i++)
		{
			SpaceMaker(PlayerHitLog[i], Max_TextBoxBlockSpace);
		}

		SpaceMaker(MonsterHitLog[0], Max_TextBoxBlockSpace);
		SpaceMaker(MonsterHitLog[1], Max_TextBoxBlockSpace);
		SpaceMaker(MonsterHitLog[2], Max_TextBoxBlockSpace);

	}

	std::cout << "\033[2J\033[H";
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("□     Dungeon stage                                                                                                                                                                                  □\n");
	printf("□                                  @@.                              @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s□\n", MonsterRender[0].c_str());
	printf("□                               @@@@@@@@                            @                            @@                            @%s□\n", MonsterRender[1].c_str());
	printf("□                            *@@@!     @@@@                         @%s@@%s@%s□\n", strPlayerName.c_str(), strMonsterName.c_str(), MonsterRender[2].c_str());
	printf("□                            @@          @@                         @                            @@                            @%s□\n", MonsterRender[3].c_str());
	printf("□                            @@ ...,-....@@                         @                            @@                            @%s□\n", MonsterRender[4].c_str());
	printf("□                            @@ @#@##@#@#@@                         @%s@@                            @%s□\n", strPlayerLevel.c_str(), MonsterRender[5].c_str());
	printf("□                            @@ @ *  # @ @@                         @                            @@                            @%s□\n", MonsterRender[6].c_str());
	printf("□                         .  @@,# *  # #,@@                         @                            @@                            @%s□\n", MonsterRender[7].c_str());
	printf("□                       ,,@,,$#@-,=  #,;@@$,,,,,                    @  Health Point : "); setConsoleColor(ColorOfPlayerHP); printf("%s", strPlayerHealth.c_str()); setConsoleColor(7); printf("@@  Health Point : "); setConsoleColor(ColorOfMobHP); printf("%s", strMonsterHealth.c_str()); setConsoleColor(7); printf("@%s□\n", MonsterRender[8].c_str());
	printf("□                    ,,,@$$#@,~@$$@,,@$$@@,@@$#@,,,                 @                            @@                            @%s□\n", MonsterRender[9].c_str());
	printf("□                   ,@@$$  ;$@@@  $$$$  @@@$$ ,$$@@,                @                            @@                            @%s□\n", MonsterRender[10].c_str());
	printf("□                  -@==      =@@--    --@@=      !=@-               @  Damage : "); setConsoleColor(ColorOfDamage); printf("%s", strPlayerDamage.c_str()); setConsoleColor(7); printf("@@%s@%s□\n", strMonsterDamage.c_str(), MonsterRender[11].c_str());
	printf("□                  @@     --- =@@@----@=@@ ---     @@               @                            @@                            @%s□\n", MonsterRender[12].c_str());
	printf("□                 :@@-----@@@-~@===$@== @@-@@@-----$@-              @----------------------------@@----------------------------@%s□\n", MonsterRender[13].c_str());
	printf("□                 @@@@@@@@@@@===   ,=   ===@@@@@@@@@@=              @============================@@============================@%s□\n", MonsterRender[14].c_str());
	printf("□                 @*******@@@-            -@@@******@~ ,~           @%s@@", PlayerHitLog[0].c_str()); setConsoleColor(ColorOfDropItem); printf("%s", MonsterHitLog[0].c_str()); setConsoleColor(7); printf("@% s□\n", MonsterRender[15].c_str());
	printf("□                :@~~~~~~~@@@@~~        ~~#@@@~~~~~~@@~=@~~~        @%s@@%s@%s□\n", PlayerHitLog[1].c_str(), MonsterHitLog[1].c_str(), MonsterRender[16].c_str());
	printf("□                *@@$@@@@@@@**#@~~    ~~@@***@@**@@@@******@:~~~    @%s@@%s@%s□\n", PlayerHitLog[2].c_str(), MonsterHitLog[2].c_str(), MonsterRender[17].c_str());
	printf("□                 @@~;!!$@@@  ;!!@::::@@!!  :@@::@!!!      !!!!@::: @%s@@%s@%s□\n", PlayerHitLog[3].c_str(), MonsterHitLog[3].c_str(), MonsterRender[18].c_str());
	printf("□                 @@::.:=@!@:    !*@@@!!   ~@@@#!!    :::::    !!@@ @%s@@%s@%s□\n", PlayerHitLog[4].c_str(), MonsterHitLog[4].c_str(), MonsterRender[19].c_str());
	printf("□              :::@!!@!@@!:@@::::::@@@:::::@@!@$      @@!@@      @@ @%s@@%s@%s□\n", PlayerHitLog[5].c_str(), MonsterHitLog[5].c_str(), MonsterRender[20].c_str());
	printf("□              @@@@:;@@@@:#@@!!!!!@@!@$!!!!@@ @$     .@@ @@      @@ @%s@@%s@%s□\n", PlayerHitLog[6].c_str(), MonsterHitLog[6].c_str(), MonsterRender[21].c_str());
	printf("□              @@;;;;;@@=;#@@;;;;;@@;@=;;;;@@;@$  ;;;!@@ @@;;;;  @@ @%s@@%s@%s□\n", PlayerHitLog[7].c_str(), MonsterHitLog[7].c_str(), MonsterRender[22].c_str());
	printf("□              @@     @@=;@;;;;;;;;;;;;;;;;;;@@# ;@;;;;; ;;;;;@; @@ @%s@@%s@%s□\n", PlayerHitLog[8].c_str(), MonsterHitLog[8].c_str(), MonsterRender[23].c_str());
	printf("□          ;;; @@    !@@@@@;;:            ~;;@@# @@;;;;; ;;;;;@@ @@ @%s@@%s@%s□\n", PlayerHitLog[9].c_str(), MonsterHitLog[9].c_str(), MonsterRender[24].c_str());
	printf("□         ;@;:;@@;  ;@;;@@@@@#!;;;;;;;;;;;#@@@@@ ;;;;;@@ @@;;;;; @@ @%s@@%s@%s□\n", PlayerHitLog[10].c_str(), MonsterHitLog[10].c_str(), MonsterRender[25].c_str());
	printf("□         :*!!@::@!!@:  @@::::@@:::@@:::@@::::@@      @@ @@      @@ @%s@@%s@%s□\n", PlayerHitLog[11].c_str(), MonsterHitLog[11].c_str(), MonsterRender[26].c_str());
	printf("□          ,::@! :::@!! @@    @@   @@   @@    @@      @@ @@     !@@ @%s@@%s@%s□\n", PlayerHitLog[12].c_str(), MonsterHitLog[12].c_str(), MonsterRender[27].c_str());
	printf("□            !@@!!!!@::!@@    @@   @@   @@    @@!!    !@!@:    !@@: @%s@@%s@%s□\n", PlayerHitLog[13].c_str(), MonsterHitLog[13].c_str(), MonsterRender[28].c_str());
	printf("□           !@:@@@@@:!!@@@:   @@   @@   @@    ~@@@!!  .:::   !!@:~  @%s@@%s@%s□\n", PlayerHitLog[14].c_str(), MonsterHitLog[14].c_str(), MonsterRender[29].c_str());
	printf("□          *@~*@~@@~ ~~@@:-   @@   @@   @@     @@~@@*      **@!~    @%s@@%s@%s□\n", PlayerHitLog[15].c_str(), MonsterHitLog[15].c_str(), MonsterRender[30].c_str());
	printf("□         *@@*@~*@~    @@   . @@   @@   @@     @@,;;@**  ,*@@~.     @%s@@%s@%s□\n", PlayerHitLog[16].c_str(), MonsterHitLog[16].c_str(), MonsterRender[31].c_str());
	printf("□        *@~@@~*@~ -***@@***=*@@ **@@***@@  ***@@===@@@**=@~~       @%s@@%s@%s□\n", PlayerHitLog[17].c_str(), MonsterHitLog[17].c_str(), MonsterRender[32].c_str());
	printf("□       =@-=@-=@$  .@@-------@@@ --@@;;:@@ =@-------@@-!@--         @%s@@%s@%s□\n", PlayerHitLog[18].c_str(), MonsterHitLog[18].c_str(), MonsterRender[33].c_str());
	printf("□      =@-;@-=@#,   -@=      @@@   @@   @@=@@      =@- .-           @%s@@%s@%s□\n", PlayerHitLog[19].c_str(), MonsterHitLog[19].c_str(), MonsterRender[34].c_str());
	printf("□     =@@=#-=@!,     @@=    =@@@===--===@@@=@=    =@-               @%s@@%s@%s□\n", PlayerHitLog[20].c_str(), MonsterHitLog[20].c_str(), MonsterRender[35].c_str());
	printf("□    =@-#@-=@*.      @@@====@-@@@-@==@---@@#-@====@@                @%s@@%s@%s□\n", PlayerHitLog[21].c_str(), MonsterHitLog[21].c_str(), MonsterRender[36].c_str());
	printf("□   $@,!@,=@=.       @@,,,,@@$@,, ,@@~   ,~@$@@,,,,@$               @%s@@%s@%s□\n", PlayerHitLog[22].c_str(), MonsterHitLog[22].c_str(), MonsterRender[37].c_str());
	printf("□  $@,!@,$@$.       *@@    ,@@,    =,      :@@,    @@               @%s@@%s@%s□\n", PlayerHitLog[23].c_str(), MonsterHitLog[23].c_str(), MonsterRender[38].c_str());
	printf("□ :@:!@!=@@.        @@,    *@=     .        @@     ,@$              @%s@@%s@%s□\n", PlayerHitLog[24].c_str(), MonsterHitLog[24].c_str(), MonsterRender[39].c_str());
	printf("□  @#@,@@@,        ;@@     @@.              ,@$     @@              @%s@@%s@%s□\n", PlayerHitLog[25].c_str(), MonsterHitLog[25].c_str(), MonsterRender[40].c_str());
	printf("□  @@@#@$.         @@.    #@:                @@     *@#             @%s@@%s@%s□\n", PlayerHitLog[26].c_str(), MonsterHitLog[26].c_str(), MonsterRender[41].c_str());
	printf("□  @@....         :@@     @@                 .@#     @@             @%s@@%s@%s□\n", PlayerHitLog[27].c_str(), MonsterHitLog[27].c_str(), MonsterRender[42].c_str());
	printf("□  ..            #@@@##  #@.                  @@*  ##@@#;           @%s@@%s@%s□\n", PlayerHitLog[28].c_str(), MonsterHitLog[28].c_str(), MonsterRender[43].c_str());
	printf("□              @@@   @@@@@@                    @@@@@   @@@          @%s@@%s@%s□\n", PlayerHitLog[29].c_str(), MonsterHitLog[29].c_str(), MonsterRender[44].c_str());
	printf("□            #@@*       @@                     @@@       @@@        @%s@@%s@%s□\n", PlayerHitLog[30].c_str(), MonsterHitLog[30].c_str(), MonsterRender[45].c_str());
	printf("□           @@@@@@@@@@@@@@                     @@@@@@@@@@@@@@       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%s□\n", MonsterRender[46].c_str());
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
}

void CDungeonStage::setConsoleColor(WORD color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
	SetConsoleTextAttribute(hConsole, color);         // 색상 속성 설정
}

void CDungeonStage::SpaceMaker(string& _str, int _max)
{
	int start = _str.size();
	for (int i = start; i < _max; i++)
	{
		_str += " ";
	}
}

void CDungeonStage::TextRenderInit()
{
	TextRenderWin.push_back(" ");
	TextRenderWin.push_back(" ");
	TextRenderWin.push_back("  #  $$$         / $$$");
	TextRenderWin.push_back("  'Y  $$$      |  $$$");
	TextRenderWin.push_back("   |  $$$ - d$b|  $$$");

	TextRenderWin.push_back("   |  $$$  $$$$$  $$$");
	TextRenderWin.push_back("   |  $$$V$$# $$bd$$$");
	TextRenderWin.push_back("   Y.  Y$$$# Y  $$$$P");
	TextRenderWin.push_back("    'Y  $$P   Y  $$P");
	TextRenderWin.push_back("      Y__/     Y__/");

	TextRenderWin.push_back(" ");
	TextRenderWin.push_back("    / $$$$$$$$$$$$$");
	TextRenderWin.push_back("    |____   $$$___'");
	TextRenderWin.push_back("         |  $$$");
	TextRenderWin.push_back("         |  $$$");

	TextRenderWin.push_back("         |  $$$");
	TextRenderWin.push_back("         |  $$$");
	TextRenderWin.push_back("         |  $$$");
	TextRenderWin.push_back("     # $$$$$$$$$$$$$");
	TextRenderWin.push_back("    |______________/");

	TextRenderWin.push_back(" ");
	TextRenderWin.push_back("   # $$$,        / $$$");
	TextRenderWin.push_back("   L  $$$$      | $$$");
	TextRenderWin.push_back("   'Y  $$$$,    | $$$");
	TextRenderWin.push_back("    |  $$$$$$$  | $$$");

	TextRenderWin.push_back("   .| $$$Y. $$$$  $$$");
	TextRenderWin.push_back("  ,#  $$$  Y.  $$$$$$");
	TextRenderWin.push_back("  #  $$$     Y.  $$$$");
	TextRenderWin.push_back("  8___/       'Y___/");
	TextRenderWin.push_back(" ");

	TextRenderWin.push_back(" ");


	TextRenderLose.push_back(" ");
	TextRenderLose.push_back("      # $$b");
	TextRenderLose.push_back("     |  $$$");
	TextRenderLose.push_back("     |  $$$");
	TextRenderLose.push_back("     |  $$$");

	TextRenderLose.push_back("     |  O$$$$$$$$$$$D");
	TextRenderLose.push_back("     'Y_____________#");
	TextRenderLose.push_back(" ");
	TextRenderLose.push_back("        .d$$$$$$$$b");
	TextRenderLose.push_back("      #d$Y______ '$$b");

	TextRenderLose.push_back("     | O$$     'Y $$$");
	TextRenderLose.push_back("     | S$B.   ,J J$$B");
	TextRenderLose.push_back("     |  'Y$$$$$$$$MP'");
	TextRenderLose.push_back("      'b__________*");
	TextRenderLose.push_back(" ");

	TextRenderLose.push_back("        d$$$$$$$$$$b");
	TextRenderLose.push_back("     # $$K       ,'");
	TextRenderLose.push_back("     ( 'Y$$$$$$$$$b");
	TextRenderLose.push_back("     'Y________, 'Y$b");
	TextRenderLose.push_back("               )  ,9$");

	TextRenderLose.push_back("     # 0$$$$$$$$$$$P");
	TextRenderLose.push_back("     l____________#");
	TextRenderLose.push_back(" ");
	TextRenderLose.push_back("     # $$$$$$$$$$$$$$");
	TextRenderLose.push_back("     | $$$________,'");

	TextRenderLose.push_back("     | $$$$$$$$$$$$$$");
	TextRenderLose.push_back("     | $$$________,'");
	TextRenderLose.push_back("     | $$$");
	TextRenderLose.push_back("     | $$$$$$$$$$$$$$");
	TextRenderLose.push_back("     Y_____________,'");

	TextRenderLose.push_back("");
}
