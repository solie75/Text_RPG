// Text_RPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "CGameInstance.h"

int main()
{
    // Set Console Title
    system("title TEXT_RPG");             

    CGameInstance::GetInst()->GameInstInit();

    while (true)
    {
        CGameInstance::GetInst()->GameInstTick();
    }
}