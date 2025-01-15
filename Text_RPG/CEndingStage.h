#pragma once
#include "CStage.h"
class CEndingStage :
    public CStage
{
private:
    bool bCallRender = true;

public:
    virtual void StageInit() override;
    virtual void StageTick() override;
    virtual void StageRender() override;
};

