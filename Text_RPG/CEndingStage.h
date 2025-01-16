#pragma once
#include "CStage.h"
class CEndingStage :
    public CStage
{
public:
    virtual void StageInit() override;
    virtual void StageTick() override;
    virtual void StageRender() override;
private:
    bool bCallRender = true;
    string PlayerName = "namename";
};

