#include "pch.h"
#include "CEndingStage.h"
#include "CPlayer.h"

void CEndingStage::StageInit()
{
}

void CEndingStage::StageTick()
{
	// TODO : �������� �����ϰ� ������ StageInit���� �̵�(if�� ����)
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
	printf("                                                                                         %s ����!                                                                                        \n", PlayerName.c_str());
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
	printf("                                                                                          < ������ �� �̷��� >                                                                                          \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                               ����  ���� ������                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                               ����  ���� ������                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                ���� ���� �� ��Ʋ  ���� ��ä��                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                     ���� �� ĳ����  ���� ������                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");
	printf("                                                                                     ������ �� ����  ���� �弼��                                                                                        \n");
	printf("                                                                                                                                                                                                        \n");

}
