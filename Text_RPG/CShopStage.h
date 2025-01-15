#pragma once
#include "CStage.h"
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

public:
    virtual void StageInit() override;
    virtual void StageTick() override;
    virtual void StageRender() override;

    void ChangeBUYSELL();
    void BuyRender();
    void SellRender();
};

