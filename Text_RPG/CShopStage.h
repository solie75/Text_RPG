#pragma once
#include "CStage.h"
class CShopStage :
    public CStage
{
public:
    virtual void StageInit() override;
    virtual void StageTick() override;
};

