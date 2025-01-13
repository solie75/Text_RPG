#pragma once
#include "CStage.h"
class CVillageStage :
    public CStage
{
public:
    virtual void StageInit() override;
    virtual void StageTick() override;
    virtual void StageRender() override;
};

