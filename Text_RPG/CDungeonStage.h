#pragma once
#include "CStage.h"
#include "CMonster.h"

class CDungeonStage :
    public CStage
{
private:
    bool bCallRender = true;
protected:
    std::unique_ptr<CMonster> Monster;
public:
    virtual void StageInit() override;
    virtual void StageTick() override;
    virtual void StageRender() override;
    void SpaceMaker(string&, int);
};

