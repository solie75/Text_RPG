#pragma once
#include "CDungeonStage.h"
class CNormalDungeonStage :
    public CDungeonStage
{
public:
    virtual void StageInit() override;
    virtual void StageTick() override;
};

