#pragma once

class CStage;

class CStageManager :
    public CSingleton<CStageManager>
{
    SINGLE(CStageManager)

private:
    //vector<CStage*> VecStage;
    CStage* CurStage;
    bool IsDoneTutorialStage;
    //CStage* NextStage;

public:
    void StageManagerInit();
    void StageManagerTick();

    bool GetIsDoneTutoStage() { return IsDoneTutorialStage; }
    void SetIsDoneTutoStage(bool b) { IsDoneTutorialStage = b; }

    CStage* GetCurStage();
    void ChangeStage(CStage* _nextStage);
};