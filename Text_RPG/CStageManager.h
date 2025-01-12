#pragma once

class CStage;

class CStageManager :
    public CSingleton<CStageManager>
{
    SINGLE(CStageManager)

private:
    vector<CStage*> VecStage;
    CStage* CurStage;
    CStage* NextStage;

public:
    void StageManagerInit();
    void StageManagerTick();

    CStage* GetStage(STAGE_TYPE _type);
    void ChangeStage(STAGE_TYPE _nextStageType);
};