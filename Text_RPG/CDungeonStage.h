#pragma once
#include "CStage.h"
class CDungeonStage :
    public CStage
{
public:
    virtual void StageInit() override;
    virtual void StageTick() override;
};

