#pragma once
#include "CStage.h"
class CStartStage :
    public CStage
{
public:
    virtual void StageInit() override;
    virtual void StageTick() override;
};

