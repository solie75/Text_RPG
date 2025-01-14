#pragma once
#include "pch.h"
#include "CPlayer.h"
#include "CMonster.h"
class CBattleManager :
    public CSingleton<CBattleManager>
{
private:
    bool IsPlayerWinner;
public:
    virtual void Battle(CPlayer& player, CMonster& monster);
    virtual bool GetIsPlayerWinner() const;
};

