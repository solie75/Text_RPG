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
	string strPlayerHealth ="  Health Point : " + std::to_string(CPlayer::GetInst()->GetHealth());
	string strMonsterHealth = "  Health Point : " + std::to_string(Monster->GetHealth());
	SpaceMaker(strPlayerHealth, Max_TextBoxBlockSpace);
	SpaceMaker(strMonsterHealth, Max_TextBoxBlockSpace);

	//플레이어와 몬스터의 공격력 넣기
	string strPlayerDamage = "  Damage : " + std::to_string(CPlayer::GetInst()->GetDamage());
	string strMonsterDamage = "  Damage : " + std::to_string(Monster->GetDamage());
	SpaceMaker(strPlayerDamage, Max_TextBoxBlockSpace);
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
				if (it.second == BATTLE_RESULT_TYPE::ATTACK_SUCCESS)
				{
					PlayerHitLog[PHLIndex] = "  HIT : " + std::to_string(CPlayer::GetInst()->GetDamage());
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
				if (it.second == BATTLE_RESULT_TYPE::ATTACK_SUCCESS)
				{
					MonsterHitLog[MHLIndex] = "  HIT : " + std::to_string(Monster->GetDamage());
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
				}
				else // 어택포션
				{
					PlayerHitLog[PHLIndex] = "  Use Damage Up";
				}
				SpaceMaker(PlayerHitLog[PHLIndex], Max_TextBoxBlockSpace);
				PHLIndex = (PHLIndex + 1) % MaxHitLogSpace;
			}
		}
	}
	else
	{//전투 종료
		bool isWin = CBattleManager::GetInst()->GetIsPlayerWinner();

		if (isWin)
		{
			PlayerHitLog = TextRenderWin;

			SpaceMaker(PlayerHitLog[1], Max_TextBoxBlockSpace);
			MonsterHitLog[0] = "Drop Item : " + dropItemName;
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
	RenderText.push_back("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	RenderText.push_back("□     Dungeon stage                                                                                                                                                                                  □\n");
	RenderText.push_back("□                                  @@.                              @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"+ MonsterRender[0] + "□\n");
	RenderText.push_back("□                               @@@@@@@@                            @                            @@                            @"+ MonsterRender[1] + "□\n");
	RenderText.push_back("□                            *@@@!     @@@@                         @" + strPlayerName +        "@@" + strMonsterName +       "@" + MonsterRender[2] + "□\n");
	RenderText.push_back("□                            @@          @@                         @                            @@                            @" + MonsterRender[3] + "□\n");
	RenderText.push_back("□                            @@ ...,-....@@                         @                            @@                            @" + MonsterRender[4] + "□\n");
	RenderText.push_back("□                            @@ @#@##@#@#@@                         @" + strPlayerLevel +       "@@                            @" + MonsterRender[5] + "□\n");
	RenderText.push_back("□                            @@ @ *  # @ @@                         @                            @@                            @" + MonsterRender[6] + "□\n");
	RenderText.push_back("□                         .  @@,# *  # #,@@                         @                            @@                            @" + MonsterRender[7] + "□\n");
	RenderText.push_back("□                       ,,@,,$#@-,=  #,;@@$,,,,,                    @" + strPlayerHealth +      "@@" + strMonsterHealth +     "@" + MonsterRender[8] + "□\n");
	RenderText.push_back("□                    ,,,@$$#@,~@$$@,,@$$@@,@@$#@,,,                 @                            @@                            @" + MonsterRender[9] + "□\n");
	RenderText.push_back("□                   ,@@$$  ;$@@@  $$$$  @@@$$ ,$$@@,                @                            @@                            @" + MonsterRender[10] + "□\n");
	RenderText.push_back("□                  -@==      =@@--    --@@=      !=@-               @" + strPlayerDamage +      "@@" + strMonsterDamage +     "@" + MonsterRender[11] + "□\n");
	RenderText.push_back("□                  @@     --- =@@@----@=@@ ---     @@               @                            @@                            @" + MonsterRender[12] + "□\n");
	RenderText.push_back("□                 :@@-----@@@-~@===$@== @@-@@@-----$@-              @----------------------------@@----------------------------@" + MonsterRender[13] + "□\n");
	RenderText.push_back("□                 @@@@@@@@@@@===   ,=   ===@@@@@@@@@@=              @============================@@============================@" + MonsterRender[14] + "□\n");
	RenderText.push_back("□                 @*******@@@-            -@@@******@~ ,~           @"+ PlayerHitLog[0] +       "@@" + MonsterHitLog[0] +     "@" + MonsterRender[15] + "□\n");
	RenderText.push_back("□                :@~~~~~~~@@@@~~        ~~#@@@~~~~~~@@~=@~~~        @" + PlayerHitLog[1] +      "@@" + MonsterHitLog[1] +     "@" + MonsterRender[16] + "□\n");
	RenderText.push_back("□                *@@$@@@@@@@**#@~~    ~~@@***@@**@@@@******@:~~~    @" + PlayerHitLog[2] +      "@@" + MonsterHitLog[2] +     "@" + MonsterRender[17] + "□\n");
	RenderText.push_back("□                 @@~;!!$@@@  ;!!@::::@@!!  :@@::@!!!      !!!!@::: @" + PlayerHitLog[3] +      "@@" + MonsterHitLog[3] +     "@" + MonsterRender[18] + "□\n");
	RenderText.push_back("□                 @@::.:=@!@:    !*@@@!!   ~@@@#!!    :::::    !!@@ @" + PlayerHitLog[4] +      "@@" + MonsterHitLog[4] +     "@" + MonsterRender[19] + "□\n");
	RenderText.push_back("□              :::@!!@!@@!:@@::::::@@@:::::@@!@$      @@!@@      @@ @" + PlayerHitLog[5] +      "@@" + MonsterHitLog[5] +     "@" + MonsterRender[20] + "□\n");
	RenderText.push_back("□              @@@@:;@@@@:#@@!!!!!@@!@$!!!!@@ @$     .@@ @@      @@ @" + PlayerHitLog[6] +      "@@" + MonsterHitLog[6] +     "@" + MonsterRender[21] + "□\n");
	RenderText.push_back("□              @@;;;;;@@=;#@@;;;;;@@;@=;;;;@@;@$  ;;;!@@ @@;;;;  @@ @" + PlayerHitLog[7] +      "@@" + MonsterHitLog[7] +     "@" + MonsterRender[22] + "□\n");
	RenderText.push_back("□              @@     @@=;@;;;;;;;;;;;;;;;;;;@@# ;@;;;;; ;;;;;@; @@ @" + PlayerHitLog[8] +      "@@" + MonsterHitLog[8] +     "@" + MonsterRender[23] + "□\n");
	RenderText.push_back("□          ;;; @@    !@@@@@;;:            ~;;@@# @@;;;;; ;;;;;@@ @@ @" + PlayerHitLog[9] +      "@@" + MonsterHitLog[9] +     "@" + MonsterRender[24] + "□\n");
	RenderText.push_back("□         ;@;:;@@;  ;@;;@@@@@#!;;;;;;;;;;;#@@@@@ ;;;;;@@ @@;;;;; @@ @" + PlayerHitLog[10] +     "@@" + MonsterHitLog[10] +    "@" + MonsterRender[25] + "□\n");
	RenderText.push_back("□         :*!!@::@!!@:  @@::::@@:::@@:::@@::::@@      @@ @@      @@ @" + PlayerHitLog[11] +     "@@" + MonsterHitLog[11] +    "@" + MonsterRender[26] + "□\n");
	RenderText.push_back("□          ,::@! :::@!! @@    @@   @@   @@    @@      @@ @@     !@@ @" + PlayerHitLog[12] +     "@@" + MonsterHitLog[12] +    "@" + MonsterRender[27] + "□\n");
	RenderText.push_back("□            !@@!!!!@::!@@    @@   @@   @@    @@!!    !@!@:    !@@: @" + PlayerHitLog[13] +     "@@" + MonsterHitLog[13] +    "@" + MonsterRender[28] + "□\n");
	RenderText.push_back("□           !@:@@@@@:!!@@@:   @@   @@   @@    ~@@@!!  .:::   !!@:~  @" + PlayerHitLog[14] +     "@@" + MonsterHitLog[14] +    "@" + MonsterRender[29] + "□\n");
	RenderText.push_back("□          *@~*@~@@~ ~~@@:-   @@   @@   @@     @@~@@*      **@!~    @" + PlayerHitLog[15] +     "@@" + MonsterHitLog[15] +    "@" + MonsterRender[30] + "□\n");
	RenderText.push_back("□         *@@*@~*@~    @@   . @@   @@   @@     @@,;;@**  ,*@@~.     @" + PlayerHitLog[16] +     "@@" + MonsterHitLog[16] +    "@" + MonsterRender[31] + "□\n");
	RenderText.push_back("□        *@~@@~*@~ -***@@***=*@@ **@@***@@  ***@@===@@@**=@~~       @" + PlayerHitLog[17] +     "@@" + MonsterHitLog[17] +    "@" + MonsterRender[32] + "□\n");
	RenderText.push_back("□       =@-=@-=@$  .@@-------@@@ --@@;;:@@ =@-------@@-!@--         @" + PlayerHitLog[18] +     "@@" + MonsterHitLog[18] +    "@" + MonsterRender[33] + "□\n");
	RenderText.push_back("□      =@-;@-=@#,   -@=      @@@   @@   @@=@@      =@- .-           @" + PlayerHitLog[19] +     "@@" + MonsterHitLog[19] +    "@" + MonsterRender[34] + "□\n");
	RenderText.push_back("□     =@@=#-=@!,     @@=    =@@@===--===@@@=@=    =@-               @" + PlayerHitLog[20] +     "@@" + MonsterHitLog[20] +    "@" + MonsterRender[35] + "□\n");
	RenderText.push_back("□    =@-#@-=@*.      @@@====@-@@@-@==@---@@#-@====@@                @" + PlayerHitLog[21] +     "@@" + MonsterHitLog[21] +    "@" + MonsterRender[36] + "□\n");
	RenderText.push_back("□   $@,!@,=@=.       @@,,,,@@$@,, ,@@~   ,~@$@@,,,,@$               @" + PlayerHitLog[22] +     "@@" + MonsterHitLog[22] +    "@" + MonsterRender[37] + "□\n");
	RenderText.push_back("□  $@,!@,$@$.       *@@    ,@@,    =,      :@@,    @@               @" + PlayerHitLog[23] +     "@@" + MonsterHitLog[23] +    "@" + MonsterRender[38] + "□\n");
	RenderText.push_back("□ :@:!@!=@@.        @@,    *@=     .        @@     ,@$              @" + PlayerHitLog[24] +     "@@" + MonsterHitLog[24] +    "@" + MonsterRender[39] + "□\n");
	RenderText.push_back("□  @#@,@@@,        ;@@     @@.              ,@$     @@              @" + PlayerHitLog[25] +     "@@" + MonsterHitLog[25] +    "@" + MonsterRender[40] + "□\n");
	RenderText.push_back("□  @@@#@$.         @@.    #@:                @@     *@#             @" + PlayerHitLog[26] +     "@@" + MonsterHitLog[26] +    "@" + MonsterRender[41] + "□\n");
	RenderText.push_back("□  @@....         :@@     @@                 .@#     @@             @" + PlayerHitLog[27] +     "@@" + MonsterHitLog[27] +    "@" + MonsterRender[42] + "□\n");
	RenderText.push_back("□  ..            #@@@##  #@.                  @@*  ##@@#;           @" + PlayerHitLog[28] +     "@@" + MonsterHitLog[28] +    "@" + MonsterRender[43] + "□\n");
	RenderText.push_back("□              @@@   @@@@@@                    @@@@@   @@@          @" + PlayerHitLog[29] +     "@@" + MonsterHitLog[29] +    "@" + MonsterRender[44] + "□\n");
	RenderText.push_back("□            #@@*       @@                     @@@       @@@        @" + PlayerHitLog[30] +     "@@" + MonsterHitLog[30] +    "@" + MonsterRender[45] + "□\n");
	RenderText.push_back("□           @@@@@@@@@@@@@@                     @@@@@@@@@@@@@@       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" + MonsterRender[46] + "□\n");
	RenderText.push_back("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	


	//랜더 송출
	for (string it : RenderText)
	{
		std::cout << it;
	}
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
