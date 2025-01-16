#pragma once

class CStage;

class CStageManager :
    public CSingleton<CStageManager>
{
    SINGLE(CStageManager)

private:
    //vector<CStage*> VecStage;
    CStage* CurStage;
    bool bIsDoneTutorialStage;
    //CStage* NextStage;

public:
    void StageManagerInit();
    void StageManagerTick();

    bool GetIsDoneTutoStage() { return bIsDoneTutorialStage; }
    void SetIsDoneTutoStage(bool b) { bIsDoneTutorialStage = b; }

    CStage* GetCurStage();
    void ChangeStage(CStage* _nextStage);
};