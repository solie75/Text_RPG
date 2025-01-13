#pragma once
#include "CDungeonStage.h"
class CBossDungeonStage :
    public CDungeonStage
{
public:
    virtual void StageInit() override;
    virtual void StageTick() override;
    virtual void StageRender() override;
};

