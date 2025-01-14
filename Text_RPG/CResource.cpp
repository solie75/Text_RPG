#include "pch.h"
#include "CResource.h"
// skull
//                           ,--.
//                          {    }
//                          K,   }
//                         /  ~Y`
//                    ,   /   /
//                   {_'-K.__/
//                     `/-.__L._
//                     /  ' /`\_}
//                    /  ' /
//            ____   /  ' /
//     ,-'~~~~    ~~/  ' /_
//   ,'             ``~~~  ',
//  (                        Y
// {                         I
//{      -                    `,
//|       ',                   )
//|        |   ,..__      __. Y
//|    .,_./  Y ' / ^Y   J   )|
//\           |' /   |   |   ||
// \          L_/    . _ (_,.'(
//  \,   ,      ^^""' / |      )
//    \_  \          /,L]     /
//      '-_~-,       ` `   ./`
//         `'{_            )
//             ^^\..___,.--`


//--=[SKULL]=-- by Daniel Au (dcau)
//              ___           _,.---,---.,_
//              |         ,;~'             '~;,
//              |       ,;                     ;,
//     Frontal  |      ;                         ; ,--- Supraorbital Foramen
//      Bone    |     ,'                         /'
//              |    ,;                        /' ;,
//              |    ; ;      .           . <-'  ; |
//              |__  | ;   ______       ______   ;<----- Coronal Suture
//             ___   |  '/~"     ~" . "~     "~\'  |
//             |     |  ~  ,-~~~^~, | ,~^~~~-,  ~  |
//   Maxilla,  |      |   |        }:{        | <------ Orbit
//  Nasal and  |      |   l       / | \       !   |
//  Zygomatic  |      .~  (__,.--" .^. "--.,__)  ~.
//    Bones    |      |    ----;' / | \ `;-<--------- Infraorbital Foramen
//             |__     \__.       \/^\/       .__/
//                ___   V| \                 / |V <--- Mastoid Process
//                |      | |T~\___!___!___/~T| |
//                |      | |`IIII_I_I_I_IIII'| |
//       Mandible |      |  \,III I I I III,/  |
//                |       \   `~~~~~~~~~~'    /
//                |         \   .       . <-x---- Mental Foramen
//                |__         \.    ^    ./
//                              ^~~~^~~~^       -dcau (4/15/95)

//                          ...----....
//                    ..-:"''         ''"-..
//                 .-'                      '-.
//               .'              .     .       '.
//             .'   .          .    .      .    .''.
//           .'  .    .       .   .   .     .   . ..:.
//         .' .   . .  .       .   .   ..  .   . ....::.
//        ..   .   .      .  .    .     .  ..  . ....:IA.
//       .:  .   .    .    .  .  .    .. .  .. .. ....:IA.
//      .: .   .   ..   .    .     . . .. . ... ....:.:VHA.
//      '..  .  .. .   .       .  . .. . .. . .....:.::IHHB.
//     .:. .  . .  . .   .  .  . . . ...:.:... .......:HIHMM.
//    .:.... .   . ."::"'.. .   .  . .:.:.:II;,. .. ..:IHIMMA
//    ':.:..  ..::IHHHHHI::. . .  ...:.::::.,,,. . ....VIMMHM
//   .:::I. .AHHHHHHHHHHAI::. .:...,:IIHHHHHHMMMHHL:. . VMMMM
//  .:.:V.:IVHHHHHHHMHMHHH::..:" .:HIHHHHHHHHHHHHHMHHA. .VMMM.
//  :..V.:IVHHHHHMMHHHHHHHB... . .:VPHHMHHHMMHHHHHHHHHAI.:VMMI
//  ::V..:VIHHHHHHMMMHHHHHH. .   .I":IIMHHMMHHHHHHHHHHHAPI:WMM
//  ::". .:.HHHHHHHHMMHHHHHI.  . .:..I:MHMMHHHHHHHHHMHV:':H:WM
//  :: . :.::IIHHHHHHMMHHHHV  .ABA.:.:IMHMHMMMHMHHHHV:'. .IHWW
//  '.  ..:..:.:IHHHHHMMHV" .AVMHMA.:.'VHMMMMHHHHHV:' .  :IHWV
//   :.  .:...:".:.:TPP"   .AVMMHMMA.:. "VMMHHHP.:... .. :IVAI
//  .:.   '... .:"'   .   ..HMMMHMMMA::. ."VHHI:::....  .:IHW'
//  ...  .  . ..:IIPPIH: ..HMMMI.MMMV:I:.  .:ILLH:.. ...:I:IM
//: .   .'"' .:.V". .. .  :HMMM:IMMMI::I. ..:HHIIPPHI::'.P:HM.
//:.  .  .  .. ..:.. .    :AMMM IMMMM..:...:IV":T::I::.".:IHIMA
//'V:.. .. . .. .  .  .   'VMMV..VMMV :....:V:.:..:....::IHHHMH
//  "IHH:.II:.. .:. .  . . . " :HB"" . . ..PI:.::.:::..:IHHMMV"
//   :IP""HHII:.  .  .    . . .'V:. . . ..:IH:.:.::IHIHHMMMMM"
//   :V:. VIMA:I..  .     .  . .. . .  .:.I:I:..:IHHHHMMHHMMM
//   :"VI:.VWMA::. .:      .   .. .:. ..:.I::.:IVHHHMMMHMMMMI
//   :."VIIHHMMA:.  .   .   .:  .:.. . .:.II:I:AMMMMMMHMMMMMI
//   :..VIHIHMMMI...::.,:.,:!"I:!"I!"I!"V:AI:VAMMMMMMHMMMMMM'
//   ':.:HIHIMHHA:"!!"I.:AXXXVVXXXXXXXA:."HPHIMMMMHHMHMMMMMV
//     V:H:I:MA:W'I :AXXXIXII:IIIISSSSSSXXA.I.VMMMHMHMMMMMM      unknown
//       'I::IVA ASSSSXSSSSBBSBMBSSSSSSBBMMMBS.VVMMHIMM'"'
//        I:: VPAIMSSSSSSSSSBSSSMMBSSSBBMMMMXXI:MMHIMMI
//       .I::. "H:XIIXBBMMMMMMMMMMMMMMMMMBXIXXMMPHIIMM'
//       :::I.  ':XSSXXIIIIXSSBMBSSXXXIIIXXSMMAMI:.IMM
//       :::I:.  .VSSSSSISISISSSBII:ISSSSBMMB:MI:..:MM
//       ::.I:.  ':"SSSSSSSISISSXIIXSSSSBMMB:AHI:..MMM.
//       ::.I:. . ..:"BBSSSSSSSSSSSSBBBMMMB:AHHI::.HMMI
//       :..::.  . ..::":BBBBBSSBBBMMMB:MMMMHHII::IHHMI
//       ':.I:... ....:IHHHHHMMMMMMMMMMMMMMMHHIIIIHMMV"
//         "V:. ..:...:.IHHHMMMMMMMMMMMMMMMMHHHMHHMHP'
//           ':. .:::.:.::III::IHHHHMMMMMHMHMMHHHHM"
//            "::....::.:::..:..::IIIIIHHHHMMMHHMV"
//              "::.::.. .. .  ...:::IIHHMMMMHMV"
//                "V::... . .I::IHHMMV"'
//                  '"VHVHHHAHHHHMMV:"'

// parchment
//   ______________________________
// / \                             \.
//|   |                            |.
// \_ |                            |.
//    |                            |.
//    |                            |.
//    |                            |.
//    |                            |.
//    |                            |.
//    |                            |.
//    |                            |.
//    |                            |.
//    |                            |.
//    |                            |.
//    |                            |.
//    |   _________________________|___
//    |  /                            /.
//    \_/dc__________________________/.


// parchment
//     _______________________________________________________
//    /\                                                      \
//(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)
//    \/''''''''''''''''''''''''''''''''''''''''''''''''''''''/
//    (                                                      (
//     )                                                      )
//    (                                                      (
//     )                                                      )
//
//    (                                                      (
//     )                                                      )
//    (                                                      (
//     )                                                      )
//
//    (                                                      (
//     )                                                      )
//    (                                                      (
//     )                                                      )
//
//    (                                                      (
//     )                                                      )
//    (                                                      (
//    /\''''''''''''''''''''''''''''''''''''''''''''''''''''''\    
//(O)===)><><><><><><><><><><><><><><><><><><><><><><><><><><><)==(O)
//    \/______________________________________________________/

// scroll
//     _______________
//()==(              (@==()
//     '______________'|
//       |             |
//       |             |
//     __)_____________|
//()==(               (@==()
//     '--------------'


// scroll
//  .----------------------------------------------------------------.
// /  ___                                                         ___  \
//|  /   \                                                       /   \  |
//| |\_.  |                                                     |    /| |
//|\|  | /|                                                     |\  | |/|
//| `---' |                                                     | `---' |
//|       |                                                     |       |
//|       |-----------------------------------------------------|       |
//\       |                                                     |       /
// \_____/                                                       \_____/
//  `---'                                                         `---'

//  ___________________________________________________________________
// /  ___                                                         ___  \
//|  /   \                                                       /   \  |
//| |\_.  |                                                     |    /| |
//|\|  | /|                                                     |\  | |/|
//| `---' |                                                     | `---' |
//|       |_____________________________________________________|       |
// \_____/                                                       \_____/



// scroll
//                                                               _____
//                                                              /  .  \
//                                                             |\_/|   |
//                                                             |   |  /|
//  .----------------------------------------------------------------' |
// /  .-.                                                              |
//|  /   \                                                             |
//| |\_.  |                                                            |
//|\|  | /|                                                            |
//| `---' |                                                            |
//|       |                                                            |
//|       |                                                           /
//|       |----------------------------------------------------------'
//\       |
// \_____/

// frame
//std::cout << "\033[2J\033[H";
//printf("�����������������������������������������������������������������������������������������������������\n");
//printf("��     Dungeon stage  Test Complete                                                                                                                                                                   ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("��                                                                                                                                                                                                    ��\n");
//printf("�����������������������������������������������������������������������������������������������������");