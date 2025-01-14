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
	vector<string> RenderText;
	std::cout << "\033[2J\033[H";
	RenderText.push_back("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	RenderText.push_back("□     Dungeon stage                                                                                                                                                                                  □\n");
	RenderText.push_back("□                 =@@@@@@@@@@!                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@#               ,    @@@$                                ;@@@@-                       =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      □\n");
	RenderText.push_back("□               *@@###########@=               @                          .#            *@#;$#@@   .#=                          .;@@@@##@@@@,.                   =,                           @      □\n");
	RenderText.push_back("□             .*#=,          ,$#=.             @                          .#         ...=-    $;    ,$.                        :@@@$$~  ;$$#@@,,                 =,고블린                     @      □\n");
	RenderText.push_back("□             !#-              -@*             @                          .#       ,,;!$@-     @,,,,~$=                      ,:@#$:        ,=@@@,                =,                           @      □\n");
	RenderText.push_back("□            ,=;               ,$=,            @레벨:                     .#      ~$=~.;#;     @====*:$-,                   :@@=:            !=@@-               =,레벨:                      @      □\n");
	RenderText.push_back("□            ;@:  -,        ~-  ~@!            @                          .#     .*;    :#-   ~@    -****;~,               -@@!.               *@@~              =,                           @      □\n");
	RenderText.push_back("□            ;=,-:#*:      ;##~ ~@!            @체력:                     .#  .::*@;     =!.  @@        ,!!;,              *@*.                 !@@~             =,체력:                      @      □\n");
	RenderText.push_back("□            ;: *@*;#!    ;@;!#~~@!            @                          .# .;;;;**-    ~#,  ;@;          ;=,            !@#,                   !@$             =,                           @      □\n");
	RenderText.push_back("□            ;: *@- ~@!!!!@: ,@=~@!            @공격력:                   .# :=   .!=-    =*.  :@!;        ,=:           ,@#~                    .@@:            =,공격력:                    @      □\n");
	RenderText.push_back("□            ;: *@-  ~@@@@~  ,@=~@!            @                          .# ~=    ,=:    -#*   ~:@**;      ;$-   ~!*    =@~  -*:            !**  :@$   ,;*~     =,                           @      □\n");
	RenderText.push_back("□            ;: *$,   -~~-   ,@=~@!            @                          .# ,#;    ,;-    -#;   =@~!=      ,=:   =@@=   @# .=$@#*~        !*@@@* .@@; -=@@;     =,                           @      □\n");
	RenderText.push_back("□            ;::#:            :@$@!            @                          .# ,@@;    !#-    ,$===@, :=       !#-  $@@@= =@, ,@$:$@#~      !@@@-@@* ~@=,$@@@;     =,                           @      □\n");
	RenderText.push_back("□           :##@;  !.      .* ,#@@@:           @                          .# ,$:@;   .*#-   =@-,,,.$#=       .*~  $@-#@$@@ .#@! .;@#~    !@@-, ,@# ,@@#@*;@=,    =,                           @      □\n");
	RenderText.push_back("□          :@;..  *@,      .$  ...;@:          @############################ ,= :@;   ,=#####,  ##$...        !~  $@..@@@@ .#@*.;!;@@~   =@-$#  @#  -@@= :@@:    =#############################      □\n");
	RenderText.push_back("□          :@;    =@,      .$     :@;          @공격성공                  .# ,=  :@@@@@~      #@              !~  $@.  @@;  -@=~@! ;@:  *@*.#@ @@#  ,@=  :@@:    =-                           @      □\n");
	RenderText.push_back("□           ;@@:   ,        ;   ~@@;           @                          .# ,=.            #@               !:   $@.  @@   ,@@*   ;@:  =@,   :@@   ,@=  :@$-    =,                           @      □\n");
	RenderText.push_back("□             !:                ~*             @                          .# ,#;           $@.              ;:    $@.  @@    ,@@*  ;@:  *@-  #@@;   ,@=  :@;     =,                           @      □\n");
	RenderText.push_back("□             !:                :*             @                          .# ,#=          =#.             ,!:     $@-  @@     -#@@@@@~   =@@@@#*    ,@@* :@;     =,                           @      □\n");
	RenderText.push_back("□             !;               ,$*             @                          .#  :=          =-             ;#:      *@@. @@      -$$$$~    !$$$$      ,#@*.!@;     =,                           @      □\n");
	RenderText.push_back("□             !@~              -@*             @                          .#  -$,        ,$,           .;$:        $@~ @@                           .!@=!@#~     =,                           @      □\n");
	RenderText.push_back("□             ~#~    -~  ~~   .;#:             @                          .#  ,==,       =@,         .~:!-         !@@~@@                            :@@@#~      =,                           @      □\n");
	RenderText.push_back("□              !!.   #@::@@   -@*              @                          .#   ,!;:,     :!.         ;#:            ;@@@@                           .!@@#~       =,                           @      □\n");
	RenderText.push_back("□              ~$*.  :;;;;;  -!#~              @                          .#     ,;;;;,            ;;*=              ;;@@   .;;;;;;;;;;;;;;;;;;;:   ,$@$~        =,                           @      □\n");
	RenderText.push_back("□               -$*;.       !=#~               @                          .#      ,==;,           .$~-$-               @@   ,@@@@@@@@@@@@@@@@@@@@   ,@@*         =,                           @      □\n");
	RenderText.push_back("□                -$@*!;  !!*@*-                @                          .#      :@;              - -@!               @@   ,@@$:*@@@*::$@@@@:;@@   ,@$-         =,                           @      □\n");
	RenderText.push_back("□                 -#@@@**@@@#.                 @                          .#      :$-                ,$*               @@    ;@#*$@@@$- =@;#@.=@;   ,@=          =,                           @      □\n");
	RenderText.push_back("□           ~====, $@~----~@$ ,===:            @                          .#      :!                  :*               @@~   .!@@@*-*@~;#*.$@=@@.   ,@=          =,                           @      □\n");
	RenderText.push_back("□   .$$!   .!@!*@#$@@.     @@$$@=;#:   .!$$,   @                          .#      :;                  -*               ;@$    ~@@@=-;@#@@- $@@@,    ,@=          =,                           @      □\n");
	RenderText.push_back("□  ##@@@!  :@! ..~#@@#.   #@@$... ;@:  !@@@#!  @                          .#      :;                  -*                @@     .:@@#@@@@@##@@=,    .#$.          =,                           @      □\n");
	RenderText.push_back("□ @@$ -@@@@@@;      $@@@@@@=      :@@@@@:  $@. @                          .#     .!;              .$= -=                @@$       ;@@@@@@@@*.      ,@=           =,                           @      □\n");
	RenderText.push_back("□ @#   -@*  ;@*,       @@       ~@@!  !@~   $@.@                          .#     :@;               ,$ -@*                @#                       .@#-           =,                           @      □\n");
	RenderText.push_back("□@@    -@*   ;@@~              ~@@!   !@-    #.@                          .#     :@;                  -@*                :@#                     .@@=            =,                           @      □\n");
	RenderText.push_back("□@@    -@*   ;@@~              ~@@!   !@-    #.@                          .#     :@;                  -@*                :@#                     .@@=            =,                           @      □\n");
	RenderText.push_back("□@@    -@*   ;@@~              ~@@!   !@-    #.@                          .#     :@;                  -@*                :@#                     .@@=            =,                           @      □\n");
	RenderText.push_back("□@@     ~*     ;@:.          -#@!    ;@~     #@@                          .#     :$-               .$ ,$*                 #@@$..               .,@@=             =,                           @      □\n");
	RenderText.push_back("□@@     -#!     ;#@~       .~@$!     !#~     #@@                          .#     :!                .#. ~*                 .$#@@=,,,,      ,,,,~@@$=              =,                           @      □\n");
	RenderText.push_back("□@@      ~=.     -*@:-    -#@!      -=:      #@@                          .#     :!                .@= ~*                   .$@@@@@#;----;#@@@@@=                =,                           @      □\n");
	RenderText.push_back("□@@      ~@=~~.    ;$@~ .~@*!    .~:$@:      #@@                          .#    .!!                .@= ~*                 -~~;@@@@@@@@@@@@@@@@@@~~~-             =,                           @      □\n");
	RenderText.push_back("□@@     .!#*$@:     ~!@:!@!      ~#=*$!.     #@@                          .#    ~@!                .*= ~$,             ,~:@@@@#****************@@@@#~~-          =,                           @      □\n");
	RenderText.push_back("□!@:::::*@! -$:       ;@*;      .*=. ;#!:::::@!@                          .#    ~@!                 ,= ~@!           -:*@@@!!!:.               !!!!@@@$:-        =,                           @      □\n");
	RenderText.push_back("□ ;*@;;;*@!  ;:        ;.       ,=!  ;@*;;;#!; @                          .#    ~$-                 ,= ,=!          :$@@;;:                        ;;*@@$~       =,                           @      □\n");
	RenderText.push_back("□  ~#   .*$!!$:                  :$!!$*,   $,  @                          .#    ~!                  ,#- :!         ;@@!:                             .:*@#*-     =,                           @      □\n");
	RenderText.push_back("□  ~#    .!@@*,                  .*@@*.    $,  @                          .#    ~!                  ,@* ~!        ;@@:.                                .!@@$-    =,                           @      □\n");
	RenderText.push_back("□  ~#     .--.                    .--.     $,  @                          .#    ~!                  ,@= ~!       ;@@:                                   .-*@:    =,                           @      □\n");
	RenderText.push_back("□  ~#                                      $,  @                          .#   ,=!                   -, ~$-      =@~                                      ;@#~   =,                           @      □\n");
	RenderText.push_back("□  .#                                      $,  @                          .#   -@!                      ~@;      .,                                       .,,    =,                           @      □\n");
	RenderText.push_back("□   .                                      .   @############################    :@######################@*                                                       =############################@      □\n");
	RenderText.push_back("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□");

	string strPlayerName = "Texter";
	for (int i = strPlayerName.size(); i < 26; i++)
	{
		strPlayerName += " ";
	}
	RenderText[4] = "□             .*#=,          ,$#=.             @" + strPlayerName + ".#         ...=-    $;    ,$.                        :@@@$$~  ;$$#@@,,                 =,고블린                     @      □\n";

	string strPlayerLevel = "레벨:";
	strPlayerLevel += std::to_string(CPlayer::GetInst()->GetLevel());
	for (int i = strPlayerLevel.size(); i < 26; i++)
	{
		strPlayerLevel += " ";
	}
	RenderText[6] = "□            ,=;               ,$=,            @" + strPlayerLevel + ".#      ~$=~.;#;     @====*:$-,                   :@@=:            !=@@-               =,레벨:                      @      □\n";

	string strPlayerHealth = "체력:";
	strPlayerHealth += std::to_string(CPlayer::GetInst()->GetHealth());
	for (int i = strPlayerHealth.size(); i < 26; i++)
	{
		strPlayerHealth += " ";
	}
	RenderText[8] = "□            ;=,-:#*:      ;##~ ~@!            @" + strPlayerHealth + ".#  .::*@;     =!.  @@        ,!!;,              *@*.                 !@@~             =,체력:                      @      □\n";

	string strPlayerDamage = "공격력:";
	strPlayerDamage += std::to_string(CPlayer::GetInst()->GetDamage());
	for (int i = strPlayerDamage.size(); i < 26; i++)
	{
		strPlayerDamage += " ";
	}
	RenderText[10] = "□            ;: *@- ~@!!!!@: ,@=~@!            @"+ strPlayerDamage + ".# :=   .!=-    =*.  :@!;        ,=:           ,@#~                    .@@:            =,공격력:                    @      □\n";


	for (string it : RenderText)
	{
		std::cout << it;
	}
}
