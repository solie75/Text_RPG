#pragma once
#include "CStage.h"
#include "CMonster.h"

class CDungeonStage :
    public CStage
{
private:
    bool bCallRender = true;
    int MaxHitLogSpace = 32;
    int StartHitLogSpace = 16;
    double tickTimer = 1;
    double curTimer = 0;
    int curLogIdx = 0;
protected:
    std::unique_ptr<CMonster> Monster;
    vector<std::pair<string, bool>> BattleLog;
public:
    virtual void StageInit() override;
    virtual void StageTick() override;
    virtual void StageRender() override;
    void SpaceMaker(string&, int);
};

