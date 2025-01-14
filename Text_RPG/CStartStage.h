#pragma once
#include "CStage.h"
#include "CStageManager.h"

class CStartStage :
    public CStage
{
private:
    bool bCallRender = true;
public:
    virtual void StageInit() override;
    virtual void StageTick() override;
    virtual void StageRender() override;
};

