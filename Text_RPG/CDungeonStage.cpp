#include "pch.h"
#include "CDungeonStage.h"
#include "CPlayer.h"

void CDungeonStage::StageInit()
{
}

void CDungeonStage::StageTick()
{
	if (bCallRender)
	{
		this->StageRender();
		bCallRender = false;
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
	RenderText.push_back("□             .*#=,          ,$#=.             @                          .#         ...=-    $;    ,$.                        :@@@$$~  ;$$#@@,,                 =,고블린                    @       □\n");
	RenderText.push_back("□             !#-              -@*             @                          .#       ,,;!$@-     @,,,,~$=                      ,:@#$:        ,=@@@,                =,                          @       □\n");
	RenderText.push_back("□            ,=;               ,$=,            @레벨:                     .#      ~$=~.;#;     @====*:$-,                   :@@=:            !=@@-               =,레벨:                     @       □\n");
	RenderText.push_back("□            ;@:  -,        ~-  ~@!            @                          .#     .*;    :#-   ~@    -****;~,               -@@!.               *@@~              =,                          @       □\n");
	RenderText.push_back("□            ;=,-:#*:      ;##~ ~@!            @체력:                     .#  .::*@;     =!.  @@        ,!!;,              *@*.                 !@@~             =,체력:                     @       □\n");
	RenderText.push_back("□            ;: *@*;#!    ;@;!#~~@!            @                          .# .;;;;**-    ~#,  ;@;          ;=,            !@#,                   !@$             =,                          @       □\n");
	RenderText.push_back("□            ;: *@- ~@!!!!@: ,@=~@!            @공격력:                   .# :=   .!=-    =*.  :@!;        ,=:           ,@#~                    .@@:            =,공격력:                   @       □\n");
	RenderText.push_back("□            ;: *@-  ~@@@@~  ,@=~@!            @                          .# ~=    ,=:    -#*   ~:@**;      ;$-   ~!*    =@~  -*:            !**  :@$   ,;*~     =,                          @       □\n");
	RenderText.push_back("□            ;: *$,   -~~-   ,@=~@!            @                          .# ,#;    ,;-    -#;   =@~!=      ,=:   =@@=   @# .=$@#*~        !*@@@* .@@; -=@@;     =,                          @       □\n");
	RenderText.push_back("□            ;::#:            :@$@!            @                          .# ,@@;    !#-    ,$===@, :=       !#-  $@@@= =@, ,@$:$@#~      !@@@-@@* ~@=,$@@@;     =,                          @       □\n");
	RenderText.push_back("□           :##@;  !.      .* ,#@@@:           @                          .# ,$:@;   .*#-   =@-,,,.$#=       .*~  $@-#@$@@ .#@! .;@#~    !@@-, ,@# ,@@#@*;@=,    =,                          @       □\n");
	RenderText.push_back("□          :@;..  *@,      .$  ...;@:          @############################ ,= :@;   ,=#####,  ##$...        !~  $@..@@@@ .#@*.;!;@@~   =@-$#  @#  -@@= :@@:    =############################       □\n");
	RenderText.push_back("□          :@;    =@,      .$     :@;          @공격성공                  .# ,=  :@@@@@~      #@              !~  $@.  @@;  -@=~@! ;@:  *@*.#@ @@#  ,@=  :@@:    =-                          @       □\n");
	RenderText.push_back("□           ;@@:   ,        ;   ~@@;           @                          .# ,=.            #@               !:   $@.  @@   ,@@*   ;@:  =@,   :@@   ,@=  :@$-    =,                          @       □\n");
	RenderText.push_back("□             !:                ~*             @                          .# ,#;           $@.              ;:    $@.  @@    ,@@*  ;@:  *@-  #@@;   ,@=  :@;     =,                          @       □\n");
	RenderText.push_back("□             !:                :*             @                          .# ,#=          =#.             ,!:     $@-  @@     -#@@@@@~   =@@@@#*    ,@@* :@;     =,                          @       □\n");
	RenderText.push_back("□             !;               ,$*             @                          .#  :=          =-             ;#:      *@@. @@      -$$$$~    !$$$$      ,#@*.!@;     =,                          @       □\n");
	RenderText.push_back("□             !@~              -@*             @                          .#  -$,        ,$,           .;$:        $@~ @@                           .!@=!@#~     =,                          @       □\n");
	RenderText.push_back("□             ~#~    -~  ~~   .;#:             @                          .#  ,==,       =@,         .~:!-         !@@~@@                            :@@@#~      =,                          @       □\n");
	RenderText.push_back("□              !!.   #@::@@   -@*              @                          .#   ,!;:,     :!.         ;#:            ;@@@@                           .!@@#~       =,                          @       □\n");
	RenderText.push_back("□              ~$*.  :;;;;;  -!#~              @                          .#     ,;;;;,            ;;*=              ;;@@   .;;;;;;;;;;;;;;;;;;;:   ,$@$~        =,                          @       □\n");
	RenderText.push_back("□               -$*;.       !=#~               @                          .#      ,==;,           .$~-$-               @@   ,@@@@@@@@@@@@@@@@@@@@   ,@@*         =,                          @       □\n");
	RenderText.push_back("□                -$@*!;  !!*@*-                @                          .#      :@;              - -@!               @@   ,@@$:*@@@*::$@@@@:;@@   ,@$-         =,                          @       □\n");
	RenderText.push_back("□                 -#@@@**@@@#.                 @                          .#      :$-                ,$*               @@    ;@#*$@@@$- =@;#@.=@;   ,@=          =,                          @       □\n");
	RenderText.push_back("□           ~====, $@~----~@$ ,===:            @                          .#      :!                  :*               @@~   .!@@@*-*@~;#*.$@=@@.   ,@=          =,                          @       □\n");
	RenderText.push_back("□   .$$!   .!@!*@#$@@.     @@$$@=;#:   .!$$,   @                          .#      :;                  -*               ;@$    ~@@@=-;@#@@- $@@@,    ,@=          =,                          @       □\n");
	RenderText.push_back("□  ##@@@!  :@! ..~#@@#.   #@@$... ;@:  !@@@#!  @                          .#      :;                  -*                @@     .:@@#@@@@@##@@=,    .#$.          =,                          @       □\n");
	RenderText.push_back("□ @@$ -@@@@@@;      $@@@@@@=      :@@@@@:  $@. @                          .#     .!;              .$= -=                @@$       ;@@@@@@@@*.      ,@=           =,                          @       □\n");
	RenderText.push_back("□ @#   -@*  ;@*,       @@       ~@@!  !@~   $@.@                          .#     :@;               ,$ -@*                @#                       .@#-           =,                          @       □\n");
	RenderText.push_back("□@@    -@*   ;@@~              ~@@!   !@-    #.@                          .#     :@;                  -@*                :@#                     .@@=            =,                          @       □\n");
	RenderText.push_back("□@@    -@*   ;@@~              ~@@!   !@-    #.@                          .#     :@;                  -@*                :@#                     .@@=            =,                          @       □\n");
	RenderText.push_back("□@@    -@*   ;@@~              ~@@!   !@-    #.@                          .#     :@;                  -@*                :@#                     .@@=            =                           @       □\n");
	RenderText.push_back("□@@     ~*     ;@:.          -#@!    ;@~     #@@                          .#     :$-               .$ ,$*                 #@@$..               .,@@=             =,                          @       □\n");
	RenderText.push_back("□@@     -#!     ;#@~       .~@$!     !#~     #@@                          .#     :!                .#. ~*                 .$#@@=,,,,      ,,,,~@@$=              =,                          @       □\n");
	RenderText.push_back("□@@      ~=.     -*@:-    -#@!      -=:      #@@                          .#     :!                .@= ~*                   .$@@@@@#;----;#@@@@@=                =,                          @       □\n");
	RenderText.push_back("□@@      ~@=~~.    ;$@~ .~@*!    .~:$@:      #@@                          .#    .!!                .@= ~*                 -~~;@@@@@@@@@@@@@@@@@@~~~-             =,                          @       □\n");
	RenderText.push_back("□@@     .!#*$@:     ~!@:!@!      ~#=*$!.     #@@                          .#    ~@!                .*= ~$,             ,~:@@@@#****************@@@@#~~-          =,                          @       □\n");
	RenderText.push_back("□!@:::::*@! -$:       ;@*;      .*=. ;#!:::::@!@                          .#    ~@!                 ,= ~@!           -:*@@@!!!:.               !!!!@@@$:-        =,                          @       □\n");
	RenderText.push_back("□ ;*@;;;*@!  ;:        ;.       ,=!  ;@*;;;#!; @                          .#    ~$-                 ,= ,=!          :$@@;;:                        ;;*@@$~       =,                          @       □\n");
	RenderText.push_back("□  ~#   .*$!!$:                  :$!!$*,   $,  @                          .#    ~!                  ,#- :!         ;@@!:                             .:*@#*-     =,                          @       □\n");
	RenderText.push_back("□  ~#    .!@@*,                  .*@@*.    $,  @                          .#    ~!                  ,@* ~!        ;@@:.                                .!@@$-    =,                          @       □\n");
	RenderText.push_back("□  ~#     .--.                    .--.     $,  @                          .#    ~!                  ,@= ~!       ;@@:                                   .-*@:    =,                          @       □\n");
	RenderText.push_back("□  ~#                                      $,  @                          .#   ,=!                   -, ~$-      =@~                                      ;@#~   =,                          @       □\n");
	RenderText.push_back("□  .#                                      $,  @                          .#   -@!                      ~@;      .,                                       .,,    =,                          @       □\n");
	RenderText.push_back("□   .                                      .   @############################    :@######################@*                                                       =###########################@       □\n");
	RenderText.push_back("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");

	//플레이어와 몬스터 이름 넣는 플로우
	string strPlayerName = CPlayer::GetInst()->GetName();
	SpaceMaker(strPlayerName, Max_TextBoxBlockSpace);
	string strMonsterName = Monster->GetName();
	SpaceMaker(strMonsterName, Max_TextBoxBlockSpace);
	RenderText[4] = "□             .*#=,          ,$#=.             @" + strPlayerName + ".#         ...=-    $;    ,$.                        :@@@$$~  ;$$#@@,,                 =,"+ strMonsterName +"@       □\n";

	//플레이어의 레벨 넣는 플로우
	string strPlayerLevel = "레벨:";
	strPlayerLevel += std::to_string(CPlayer::GetInst()->GetLevel());
	SpaceMaker(strPlayerLevel, Max_TextBoxBlockSpace);
	RenderText[6] = "□            ,=;               ,$=,            @" + strPlayerLevel + ".#      ~$=~.;#;     @====*:$-,                   :@@=:            !=@@-               =,                          @       □\n";

	//플레이어와 몬스터의 체력을 넣는 플로우
	string strPlayerHealth = "체력:";
	strPlayerHealth += std::to_string(CPlayer::GetInst()->GetHealth());
	SpaceMaker(strPlayerHealth, Max_TextBoxBlockSpace);
	string strMonsterHealth = "체력:";
	strMonsterHealth += std::to_string(Monster->GetHealth());
	SpaceMaker(strMonsterHealth, Max_TextBoxBlockSpace);
	RenderText[8] = "□            ;=,-:#*:      ;##~ ~@!            @" + strPlayerHealth + ".#  .::*@;     =!.  @@        ,!!;,              *@*.                 !@@~             =,"+ strMonsterHealth +"@       □\n";

	//플레이어와 몬스터의 공격력을 넣는 플로우
	string strPlayerDamage = "공격력:";
	strPlayerDamage += std::to_string(CPlayer::GetInst()->GetDamage());
	SpaceMaker(strPlayerDamage, Max_TextBoxBlockSpace);
	string strMonsterDamage = "공격력:";
	strMonsterDamage += std::to_string(Monster->GetDamage());
	SpaceMaker(strMonsterDamage, Max_TextBoxBlockSpace);
	RenderText[10] = "□            ;: *@- ~@!!!!@: ,@=~@!            @" + strPlayerDamage + ".# :=   .!=-    =*.  :@!;        ,=:           ,@#~                    .@@:            =,"+ strMonsterDamage +"@       □\n";


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
