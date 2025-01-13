#pragma once

class CStage;

class CStageManager :
    public CSingleton<CStageManager>
{
    SINGLE(CStageManager)

private:
    //vector<CStage*> VecStage;
    CStage* CurStage;
    //CStage* NextStage;

public:
    void StageManagerInit();
    void StageManagerTick();

    CStage* GetCurStage();
    void ChangeStage(CStage* _nextStage);
};