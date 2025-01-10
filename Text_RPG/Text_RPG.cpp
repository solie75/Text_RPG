// Text_RPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include "CGameInstance.h"

int main()
{
    CGameInstance::GetInst()->GameInstInit();

    while (true)
    {
        CGameInstance::GetInst()->GameInstTick();
    }
}