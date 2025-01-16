#pragma once
#include "CStage.h"
#include "CShopManager.h"
#include "CPlayer.h"

class CShopStage :
    public CStage
{
public:
    enum BUYSELL_MODE
    {
        BUY,
        SELL
    };
private:
    bool bCallRender = true;
    BUYSELL_MODE CurPlayer_Mode = BUYSELL_MODE::BUY;
    int shopPotionCnt = CShopManager::GetInst()->GetItemCnt(ITEM_TYPE::HEALTH_POTION);
    int shopBoostCnt = CShopManager::GetInst()->GetItemCnt(ITEM_TYPE::ATTACK_BOOST);
    string zeroBUYPotionCnt; //just zero for print, buy potion
    string zeroBUYBoostCnt; //just zero for print, buy boost
    int PlayerPotionCnt = CPlayer::GetInst()->GetItemCnt(ITEM_TYPE::HEALTH_POTION);
    int PlayerBoostCnt = CPlayer::GetInst()->GetItemCnt(ITEM_TYPE::ATTACK_BOOST);
    int PlayerMonLeatherCnt = CPlayer::GetInst()->GetItemCnt(ITEM_TYPE::MONSTER_LEATHER);
    int PlayerGold = CPlayer::GetInst()->GetGold();
    string zeroSELLPotionCnt; // just zero for print, sell potion
    string zeroSELLBoostCnt; // just zero for print, sell boost
    string zeroSELLMonLeatherCnt; //just zero for print, sell monster leather
    string PlayerGoldforPrint; //just zero for print, player gold
    string Notification; // buy&sell result phrase

    unordered_map<ITEM_TYPE, string> ItemList;
    int CurrItem;
    int ColorOfNotify;

public:
    virtual void StageInit() override;
    virtual void StageTick() override;
    virtual void StageRender() override;

private:
    void setConsoleColor(WORD);

    void CurrItemRender();
    void ChangeBUYSELL();
    void SpaceMaker(string&, int);
    void InitVariables();

    void BuyRenderPotion();
    void BuyRenderBooster();
    void SellRenderPotion();
    void SellRenderBooster();
    void SellRenderMonLeather();
};