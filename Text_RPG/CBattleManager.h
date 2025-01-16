#pragma once
#include "pch.h"
#include "CPlayer.h"
#include "CMonster.h"
class CBattleManager :
    public CSingleton<CBattleManager>
{
private:
    bool IsPlayerWinner;
    bool IsEndBattle = false;
public:
    void InitBattleManager();
    virtual void Battle(CPlayer& player, CMonster& monster, vector<std::pair<BATTLE_TURN_TYPE, BATTLE_RESULT_TYPE>>& _battleLog);
    virtual bool GetIsPlayerWinner() const;
    virtual bool GetIsEndBattle() const;
};

