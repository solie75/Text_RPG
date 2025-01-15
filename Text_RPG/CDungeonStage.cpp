#include "pch.h"
#include "CDungeonStage.h"
#include "CPlayer.h"
#include "CBattleManager.h"
#include "CTimeManager.h"
#include "CStageManager.h"
#include "CVillageStage.h"

void CDungeonStage::StageInit()
{
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
				if (CBattleManager::GetInst()->GetIsPlayerWinner())
				{
					CPlayer::GetInst()->ExpUp(50);
					Monster->DropItem();
				}
				else
				{
					CPlayer::GetInst()->ExpDown();
				}
				bIsProcessOnceDo = true;
			}

			//CStageManager::GetInst()->ChangeStage(new CVillageStage());
		}

		if(bIsProcessOnceDo == false)
			this->StageRender();
	}
	else
	{
		curTimer += CTimeManager::GetInst()->GetDeltaTime();
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
		}
		else if(BattleLog[i].first == "M")
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

void CDungeonStage::SpaceMaker(string& _str, int _max)
{
	int start = _str.size();
	for (int i = start; i < _max; i++)
	{
		_str += " ";
	}
}
