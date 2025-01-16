#include "pch.h"
#include "CEndingStage.h"
#include "CPlayer.h"

void CEndingStage::StageInit()
{
}

void CEndingStage::StageTick()
{
	// TODO : 스테이지 연결하고 나서는 StageInit으로 이동(if문 빼고)
	if (bCallRender)
	{
		PlayerName = CPlayer::GetInst()->GetName();
		StageRender();
		
		bCallRender = false;
	}
}

void CEndingStage::StageRender()
{
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                         %s 만세!                                                                                        \n", PlayerName.c_str());
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                              __        ______  __    __  ______         __       ______ __     __ ________                                            \n");
	printf("                                             /  |      /      \/  \  /  |/      \         /  |     /      /  |   /  /        |                                          \n");
	printf("                                            $$ |     /$$$$$$  $$  \  $$ /$$$$$$  |      $$ |     $$$$$$/$$ |   $$ $$$$$$$$/                                              \n");
	printf("                                            $$ |     $$ |  $$ $$$  \ $$ $$ | _$$/       $$ |       $$ | $$ |   $$ $$ |__                                                  \n");
	printf("                                            $$ |     $$ |  $$ $$$$  $$ $$ |/    |      $$ |       $$ | $$  \  /$$/$$    |                                                \n");
	printf("                                            $$ |     $$ |  $$ $$ $$ $$ $$ |$$$$ |      $$ |       $$ |  $$  /$$/ $$$$$/                                                  \n");
	printf("                                            $$ |_____$$ \__ $$ $$ |$$$$ $$ \__ $$ |      $$ |_____ _$$ |_  $$ $$/  $$ |_____                                           \n");
	printf("                                            $$       $$    $$/$$ | $$$ $$    $$/       $$       / $$   |  $$$/   $$       |                                              \n");
	printf("                                            $$$$$$$$/ $$$$$$/ $$/   $$/ $$$$$$/        $$$$$$$$/$$$$$$/    $/    $$$$$$$$/                                                 \n");
	printf("                                                                                      __       __ __      __           __    __ ________ _______   ______         \n");
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
	printf("                                                                                               역할  팀장 신중은                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                               역할  팀원 전보경                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                몬스터 생성 및 배틀  팀원 김채영                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                     던전 및 캐릭터  팀원 장진우                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                     아이템 및 상점  팀원 장세희                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");

}
