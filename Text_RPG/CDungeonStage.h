#pragma once
#include "CStage.h"
#include "CMonster.h"

class CDungeonStage :
    public CStage
{
private:
    int MaxHitLogSpace = 31;
    int StartHitLogSpace = 16;
    vector<string> TextRenderWin;
    vector<string> TextRenderLose;
protected:
    string dropItemName;
    double tickTimer = 1;
    double curTimer = 0;
    bool bIsProcessOnceDo = false;
    std::unique_ptr<CMonster> Monster;
    vector<std::pair<BATTLE_TURN_TYPE, BATTLE_RESULT_TYPE>> BattleLog;
    bool bIsAbleNextStep = false;
public:
    virtual void StageInit() override;
    virtual void StageTick() override;
    virtual void StageRender() override;
    virtual void FinishStage() = 0;
    void SpaceMaker(string&, int);
    void TextRenderInit();
};

