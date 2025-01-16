#include "pch.h"
#include "CEndingStage.h"
#include "CPlayer.h"

void CEndingStage::StageInit()
{
	PlayerName = CPlayer::GetInst()->GetName();
	StageRender();
}

void CEndingStage::StageTick()
{

}

void CEndingStage::StageRender()
{
	std::cout << "\033[2J\033[H";
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                %s 만세!                                                                          \n", PlayerName.c_str());
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                              __        ______  __    __  ______        __       ______ __     __ ________                                            \n");
	printf("                                             /  |      /      \/  \  /  |/      \         /  |     /      /  |   /  /        |                                          \n");
	printf("                                            $$ |     /$$$$$$  $$  \  $$ /$$$$$$  |      $$ |     $$$$$$/$$ |   $$ $$$$$$$$/                                              \n");
	printf("                                            $$ |     $$ |  $$ $$$  \ $$ $$ | _$$/       $$ |       $$ | $$ |   $$ $$ |__                                                  \n");
	printf("                                            $$ |     $$ |  $$ $$$$  $$ $$ |/    |      $$ |       $$ | $$  \  /$$/$$    |                                                \n");
	printf("                                            $$ |     $$ |  $$ $$ $$ $$ $$ |$$$$ |      $$ |       $$ |  $$  /$$/ $$$$$/                                                  \n");
	printf("                                            $$ |_____$$ \__ $$ $$ |$$$$ $$ \__ $$ |      $$ |_____ _$$ |_  $$ $$/  $$ |_____                                           \n");
	printf("                                            $$       $$    $$/$$ | $$$ $$    $$/       $$       / $$   |  $$$/   $$       |                                              \n");
	printf("                                            $$$$$$$$/ $$$$$$/ $$/   $$/ $$$$$$/        $$$$$$$$/$$$$$$/    $/    $$$$$$$$/                                                 \n");
	printf("                                                                                     __       __ __      __          __    __ ________ _______   ______         \n");
	printf("                                                                                    /  \      /  /  \     /   |       /  |  /  /        /       \  /      \       \n");
	printf("                                                                                    $$  \    /$$ $$  \   /$$/         $$ |  $$ $$$$$$$$/$$$$$$$  /$$$$$$  |           \n");
	printf("                                                                                    $$$  \  /$$$ |$$  \ /$$/          $$ |__$$ $$ |__   $$ |__$$ $$ |  $$ |       \n");
	printf("                                                                                    $$$$  /$$$$ | $$  $$/           $$    $$ $$    |  $$    $$<$$ |  $$ |         \n");
	printf("                                                                                    $$ $$ $$/$$ |  $$$$/            $$$$$$$$ $$$$$/   $$$$$$$  $$ |  $$ |          \n");
	printf("                                                                                    $$ |$$$/ $$ |   $$ |            $$ |  $$ $$ |_____$$ |  $$ $$ \__ $$ |                   \n");
	printf("                                                                                    $$ | $/  $$ |   $$ |            $$ |  $$ $$       $$ |  $$ $$    $$/                                               \n");
	printf("                                                                                    $$/      $$/    $$/             $$/   $$/$$$$$$$$/$$/   $$/ $$$$$$/                                                 \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                 CREDIT                                                                                                 \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                          < 중은이 꿈 이뤄조 >                                                                                          \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                         구조 설계 및 스테이지 제작  팀장 신중은                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                        상점 화면 구성 및 코드 보조  팀원 전보경                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                몬스터 생성 및 배틀  팀원 김채영                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                     던전 및 캐릭터  팀원 장진우                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                     아이템 및 상점  팀원 장세희                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");

}
