﻿#include "pch.h"
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
	this->StageRender();
}

void CDungeonStage::StageTick()
{
	if (tickTimer <= curTimer)
	{
		curTimer = 0;
		// if == true : 배틀 중
		if (CBattleManager::GetInst()->GetIsEndBattle() == false)
		{
			curLogIdx++;
			CBattleManager::GetInst()->Battle(*CPlayer::GetInst(), *Monster, BattleLog);
		}
		else
		{
			if (bIsProcessOnceDo == false)
			{
				FinishStage();
			}
		}

		if(bIsProcessOnceDo == false)
			this->StageRender();
	}
	else
	{
		curTimer += CTimeManager::GetInst()->GetDeltaTime();
	}
	if (bIsAbleNextStep && CKeyManager::GetInst()->GetKeyState(KEY_TYPE::SPACE) == KEY_STATE::TAP)
	{
		//가야할곳 처리
	}
}

void CDungeonStage::StageRender()
{
	const int Max_TextBoxBlockSpace = 26;
	vector<string> RenderText;

	//초기 틀
	std::cout << "\033[2J\033[H";
	RenderText.push_back("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	RenderText.push_back("□     Dungeon stage                                                                                                                                                                                  □\n");
	RenderText.push_back("□                 =@@@@@@@@@@!                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@#               ,    @@@$                                ;@@@@-                       =@@@@@@@@@@@@@@@@@@@@@@@@@@@@       □\n");
	RenderText.push_back("□               *@@###########@=               @                          .#            *@#;$#@@   .#=                          .;@@@@##@@@@,.                   =,                          @       □\n");
	

	//플레이어와 몬스터 이름 넣는 플로우
	string strPlayerName = CPlayer::GetInst()->GetName();
	SpaceMaker(strPlayerName, Max_TextBoxBlockSpace);
	string strMonsterName = Monster->GetName();
	SpaceMaker(strMonsterName, Max_TextBoxBlockSpace);

	RenderText.push_back("□             .*#=,          ,$#=.             @" + strPlayerName + ".#         ...=-    $;    ,$.                        :@@@$$~  ;$$#@@,,                 =," + strMonsterName + "@       □\n");
	RenderText.push_back("□             !#-              -@*             @                          .#       ,,;!$@-     @,,,,~$=                      ,:@#$:        ,=@@@,                =,                          @       □\n");
	
	//플레이어의 레벨 넣는 플로우
	string strPlayerLevel = "레벨:";
	strPlayerLevel += std::to_string(CPlayer::GetInst()->GetLevel());
	SpaceMaker(strPlayerLevel, Max_TextBoxBlockSpace);
	RenderText.push_back("□            ,=;               ,$=,            @" + strPlayerLevel + ".#      ~$=~.;#;     @====*:$-,                   :@@=:            !=@@-               =,                          @       □\n");
	RenderText.push_back("□            ;@:  -,        ~-  ~@!            @                          .#     .*;    :#-   ~@    -****;~,               -@@!.               *@@~              =,                          @       □\n");

	//플레이어와 몬스터의 체력을 넣는 플로우
	string strPlayerHealth = "체력:";
	strPlayerHealth += std::to_string(CPlayer::GetInst()->GetHealth());
	SpaceMaker(strPlayerHealth, Max_TextBoxBlockSpace);
	string strMonsterHealth = "체력:";
	strMonsterHealth += std::to_string(Monster->GetHealth());
	SpaceMaker(strMonsterHealth, Max_TextBoxBlockSpace);
	RenderText.push_back("□            ;=,-:#*:      ;##~ ~@!            @" + strPlayerHealth + ".#  .::*@;     =!.  @@        ,!!;,              *@*.                 !@@~             =," + strMonsterHealth + "@       □\n");
	RenderText.push_back("□            ;: *@*;#!    ;@;!#~~@!            @                          .# .;;;;**-    ~#,  ;@;          ;=,            !@#,                   !@$             =,                          @       □\n");


	//플레이어와 몬스터의 공격력을 넣는 플로우
	string strPlayerDamage = "공격력:";
	strPlayerDamage += std::to_string(CPlayer::GetInst()->GetDamage());
	SpaceMaker(strPlayerDamage, Max_TextBoxBlockSpace);
	string strMonsterDamage = "공격력:";
	strMonsterDamage += std::to_string(Monster->GetDamage());
	SpaceMaker(strMonsterDamage, Max_TextBoxBlockSpace);
	RenderText.push_back("□            ;: *@- ~@!!!!@: ,@=~@!            @" + strPlayerDamage + ".# :=   .!=-    =*.  :@!;        ,=:           ,@#~                    .@@:            =," + strMonsterDamage + "@       □\n");
	RenderText.push_back("□            ;: *@-  ~@@@@~  ,@=~@!            @                          .# ~=    ,=:    -#*   ~:@**;      ;$-   ~!*    =@~  -*:            !**  :@$   ,;*~     =,                          @       □\n");
	RenderText.push_back("□            ;: *$,   -~~-   ,@=~@!            @                          .# ,#;    ,;-    -#;   =@~!=      ,=:   =@@=   @# .=$@#*~        !*@@@* .@@; -=@@;     =,                          @       □\n");
	RenderText.push_back("□            ;::#:            :@$@!            @                          .# ,@@;    !#-    ,$===@, :=       !#-  $@@@= =@, ,@$:$@#~      !@@@-@@* ~@=,$@@@;     =,                          @       □\n");
	RenderText.push_back("□           :##@;  !.      .* ,#@@@:           @                          .# ,$:@;   .*#-   =@-,,,.$#=       .*~  $@-#@$@@ .#@! .;@#~    !@@-, ,@# ,@@#@*;@=,    =,                          @       □\n");
	RenderText.push_back("□          :@;..  *@,      .$  ...;@:          @############################ ,= :@;   ,=#####,  ##$...        !~  $@..@@@@ .#@*.;!;@@~   =@-$#  @#  -@@= :@@:    =############################       □\n");




	//전투 로그
	vector<string> PlayerHitLog(MaxHitLogSpace);
	vector<string> MonsterHitLog(MaxHitLogSpace);
	int PHLIndex = 0;
	int MHLIndex = 0;
	for (int i = 0; i < MaxHitLogSpace; i++)
	{
		SpaceMaker(PlayerHitLog[i], Max_TextBoxBlockSpace);
		SpaceMaker(MonsterHitLog[i], Max_TextBoxBlockSpace);

	}

	//전투가 종료 or 진행에 따라 HitLog칸에 써야할 메세지가 다름.
	if (CBattleManager::GetInst()->GetIsEndBattle() == true)
	{//전투 종료
		bool isWin = CBattleManager::GetInst()->GetIsPlayerWinner();

		if (isWin)
		{
			PlayerHitLog[0] = "  Win!!!";
			SpaceMaker(PlayerHitLog[0], Max_TextBoxBlockSpace);

			PlayerHitLog[1] = " DropItem : " + dropItemName;
			SpaceMaker(PlayerHitLog[1], Max_TextBoxBlockSpace);
			
		}
		else
		{
			PlayerHitLog[0] = "  Lose..";
			SpaceMaker(PlayerHitLog[0], Max_TextBoxBlockSpace);
		}
		
		MonsterHitLog[0] = " Press Spacebar";
		MonsterHitLog[1] = "             to continue";
		SpaceMaker(MonsterHitLog[0], Max_TextBoxBlockSpace);
		SpaceMaker(MonsterHitLog[1], Max_TextBoxBlockSpace);
	}
	else
	{//전투 진행 중
		for (int i = 0; i < BattleLog.size(); i++)
		{
			if (BattleLog[i].first == "P")
			{
				if (BattleLog[i].second == true)
				{
					PlayerHitLog[PHLIndex] = "  HIT";
				}
				else
				{
					PlayerHitLog[PHLIndex] = "  MISS";
				}
				SpaceMaker(PlayerHitLog[PHLIndex], Max_TextBoxBlockSpace);
				PHLIndex = (PHLIndex + 1) % MaxHitLogSpace;

				//다시 첫줄부터 썼을때 = 마지막 줄 빼고 모두 지움.
				if (PHLIndex == 0)
				{
					for (int i = 0; i < PlayerHitLog.size() - 1; i++)
					{
						PlayerHitLog[i] = "";
						SpaceMaker(PlayerHitLog[i], Max_TextBoxBlockSpace);
					}
				}
			}
			else if (BattleLog[i].first == "M")
			{
				if (BattleLog[i].second == true)
				{
					MonsterHitLog[MHLIndex] = "  HIT";
				}
				else
				{
					MonsterHitLog[MHLIndex] = "  MISS";
				}
				SpaceMaker(MonsterHitLog[MHLIndex], Max_TextBoxBlockSpace);
				MHLIndex = (MHLIndex + 1) % MaxHitLogSpace;

				//다시 첫줄부터 썼을때 = 마지막 줄 빼고 모두 지움.
				if (MHLIndex == 0)
				{
					for (int i = 0; i < MonsterHitLog.size() - 1; i++)
					{
						MonsterHitLog[i] = "";
						SpaceMaker(MonsterHitLog[i], Max_TextBoxBlockSpace);
					}
				}
			}
			else
			{
				//물약 사용 : 초기단계는 두가지 뿐,
				//TODO : 물약 종류가 늘어나면 배틀로그의 second의 타입부터 다시 고려하여 짜야함.
				if (BattleLog[i].second == true) // 힐링포션
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
	

	RenderText.push_back("□          :@;    =@,      .$     :@;          @" + PlayerHitLog[0] + ".# ,=  :@@@@@~      #@              !~  $@.  @@;  -@=~@! ;@:  *@*.#@ @@#  ,@=  :@@:    =-" + MonsterHitLog[0] + "@       □\n");
	RenderText.push_back("□           ;@@:   ,        ;   ~@@;           @" + PlayerHitLog[1] + ".# ,=.            #@               !:   $@.  @@   ,@@*   ;@:  =@,   :@@   ,@=  :@$-    =," + MonsterHitLog[1] + "@       □\n");
	RenderText.push_back("□             !:                ~*             @" + PlayerHitLog[2] + ".# ,#;           $@.              ;:    $@.  @@    ,@@*  ;@:  *@-  #@@;   ,@=  :@;     =," + MonsterHitLog[2] + "@       □\n");
	RenderText.push_back("□             !:                :*             @" + PlayerHitLog[3] + ".# ,#=          =#.             ,!:     $@-  @@     -#@@@@@~   =@@@@#*    ,@@* :@;     =," + MonsterHitLog[3] + "@       □\n");
	RenderText.push_back("□             !;               ,$*             @" + PlayerHitLog[4] + ".#  :=          =-             ;#:      *@@. @@      -$$$$~    !$$$$      ,#@*.!@;     =," + MonsterHitLog[4] + "@       □\n");
	RenderText.push_back("□             !@~              -@*             @" + PlayerHitLog[5] + ".#  -$,        ,$,           .;$:        $@~ @@                           .!@=!@#~     =," + MonsterHitLog[5] + "@       □\n");
	RenderText.push_back("□             ~#~    -~  ~~   .;#:             @" + PlayerHitLog[6] + ".#  ,==,       =@,         .~:!-         !@@~@@                            :@@@#~      =," + MonsterHitLog[6] + "@       □\n");
	RenderText.push_back("□              !!.   #@::@@   -@*              @" + PlayerHitLog[7] + ".#   ,!;:,     :!.         ;#:            ;@@@@                           .!@@#~       =," + MonsterHitLog[7] + "@       □\n");
	RenderText.push_back("□              ~$*.  :;;;;;  -!#~              @" + PlayerHitLog[8] + ".#     ,;;;;,            ;;*=              ;;@@   .;;;;;;;;;;;;;;;;;;;:   ,$@$~        =," + MonsterHitLog[8] + "@       □\n");
	RenderText.push_back("□               -$*;.       !=#~               @" + PlayerHitLog[9] + ".#      ,==;,           .$~-$-               @@   ,@@@@@@@@@@@@@@@@@@@@   ,@@*         =," + MonsterHitLog[9] + "@       □\n");
	RenderText.push_back("□                -$@*!;  !!*@*-                @" + PlayerHitLog[10] + ".#      :@;              - -@!               @@   ,@@$:*@@@*::$@@@@:;@@   ,@$-         =," + MonsterHitLog[10] + "@       □\n");
	RenderText.push_back("□                 -#@@@**@@@#.                 @" + PlayerHitLog[11] + ".#      :$-                ,$*               @@    ;@#*$@@@$- =@;#@.=@;   ,@=          =," + MonsterHitLog[11] + "@       □\n");
	RenderText.push_back("□           ~====, $@~----~@$ ,===:            @" + PlayerHitLog[12] + ".#      :!                  :*               @@~   .!@@@*-*@~;#*.$@=@@.   ,@=          =," + MonsterHitLog[12] + "@       □\n");
	RenderText.push_back("□   .$$!   .!@!*@#$@@.     @@$$@=;#:   .!$$,   @" + PlayerHitLog[13] + ".#      :;                  -*               ;@$    ~@@@=-;@#@@- $@@@,    ,@=          =," + MonsterHitLog[13] + "@       □\n");
	RenderText.push_back("□  ##@@@!  :@! ..~#@@#.   #@@$... ;@:  !@@@#!  @" + PlayerHitLog[14] + ".#      :;                  -*                @@     .:@@#@@@@@##@@=,    .#$.          =," + MonsterHitLog[14] + "@       □\n");
	RenderText.push_back("□ @@$ -@@@@@@;      $@@@@@@=      :@@@@@:  $@. @" + PlayerHitLog[15] + ".#     .!;              .$= -=                @@$       ;@@@@@@@@*.      ,@=           =," + MonsterHitLog[15] + "@       □\n");
	RenderText.push_back("□ @#   -@*  ;@*,       @@       ~@@!  !@~   $@.@" + PlayerHitLog[16] + ".#     :@;               ,$ -@*                @#                       .@#-           =," + MonsterHitLog[16] + "@       □\n");
	RenderText.push_back("□@@    -@*   ;@@~              ~@@!   !@-    #.@" + PlayerHitLog[17] + ".#     :@;                  -@*                :@#                     .@@=            =," + MonsterHitLog[17] + "@       □\n");
	RenderText.push_back("□@@    -@*   ;@@~              ~@@!   !@-    #.@" + PlayerHitLog[18] + ".#     :@;                  -@*                :@#                     .@@=            =," + MonsterHitLog[18] + "@       □\n");
	RenderText.push_back("□@@    -@*   ;@@~              ~@@!   !@-    #.@" + PlayerHitLog[19] + ".#     :@;                  -@*                :@#                     .@@=            =," + MonsterHitLog[19] + "@       □\n");
	RenderText.push_back("□@@     ~*     ;@:.          -#@!    ;@~     #@@" + PlayerHitLog[20] + ".#     :$-               .$ ,$*                 #@@$..               .,@@=             =," + MonsterHitLog[20] + "@       □\n");
	RenderText.push_back("□@@     -#!     ;#@~       .~@$!     !#~     #@@" + PlayerHitLog[21] + ".#     :!                .#. ~*                 .$#@@=,,,,      ,,,,~@@$=              =," + MonsterHitLog[21] + "@       □\n");
	RenderText.push_back("□@@      ~=.     -*@:-    -#@!      -=:      #@@" + PlayerHitLog[22] + ".#     :!                .@= ~*                   .$@@@@@#;----;#@@@@@=                =," + MonsterHitLog[22] + "@       □\n");
	RenderText.push_back("□@@      ~@=~~.    ;$@~ .~@*!    .~:$@:      #@@" + PlayerHitLog[23] + ".#    .!!                .@= ~*                 -~~;@@@@@@@@@@@@@@@@@@~~~-             =," + MonsterHitLog[23] + "@       □\n");
	RenderText.push_back("□@@     .!#*$@:     ~!@:!@!      ~#=*$!.     #@@" + PlayerHitLog[24] + ".#    ~@!                .*= ~$,             ,~:@@@@#****************@@@@#~~-          =," + MonsterHitLog[24] + "@       □\n");
	RenderText.push_back("□!@:::::*@! -$:       ;@*;      .*=. ;#!:::::@!@" + PlayerHitLog[25] + ".#    ~@!                 ,= ~@!           -:*@@@!!!:.               !!!!@@@$:-        =," + MonsterHitLog[25] + "@       □\n");
	RenderText.push_back("□ ;*@;;;*@!  ;:        ;.       ,=!  ;@*;;;#!; @" + PlayerHitLog[26] + ".#    ~$-                 ,= ,=!          :$@@;;:                        ;;*@@$~       =," + MonsterHitLog[26] + "@       □\n");
	RenderText.push_back("□  ~#   .*$!!$:                  :$!!$*,   $,  @" + PlayerHitLog[27] + ".#    ~!                  ,#- :!         ;@@!:                             .:*@#*-     =," + MonsterHitLog[27] + "@       □\n");
	RenderText.push_back("□  ~#    .!@@*,                  .*@@*.    $,  @" + PlayerHitLog[28] + ".#    ~!                  ,@* ~!        ;@@:.                                .!@@$-    =," + MonsterHitLog[28] + "@       □\n");
	RenderText.push_back("□  ~#     .--.                    .--.     $,  @" + PlayerHitLog[29] + ".#    ~!                  ,@= ~!       ;@@:                                   .-*@:    =," + MonsterHitLog[29] + "@       □\n");
	RenderText.push_back("□  ~#                                      $,  @" + PlayerHitLog[30] + ".#   ,=!                   -, ~$-      =@~                                      ;@#~   =," + MonsterHitLog[30] + "@       □\n");
	RenderText.push_back("□  .#                                      $,  @" + PlayerHitLog[31] + ".#   -@!                      ~@;      .,                                       .,,    =," + MonsterHitLog[31] + "@       □\n");
	RenderText.push_back("□   .                                      .   @############################    :@######################@*                                                       =###########################@       □\n");
	RenderText.push_back("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");


	//전체 송출
	for (string it : RenderText)
	{
		std::cout << it;
	}
}

void CDungeonStage::FinishStage()
{
	if (CBattleManager::GetInst()->GetIsPlayerWinner())
	{
		CPlayer::GetInst()->ExpUp(50);
	    //Monster->DropItem(); 이용해서 인벤토리에 아이템 넣기 & 해당값을 가지고 로그창에 띄우기
		// DropItem()이 있는지 체크하고, 분기점으로 네임 넣기
		//dropItemName = CPlayer::GetInst()->GetInventory(Monster->DropItem())->GetName();
	}
	else
	{
		CPlayer::GetInst()->ExpDown();
	}
	bIsAbleNextStep = true;
	bIsProcessOnceDo = true;
}

void CDungeonStage::SpaceMaker(string& _str, int _max)
{
	int start = _str.size();
	for (int i = start; i < _max; i++)
	{
		_str += " ";
	}
}
