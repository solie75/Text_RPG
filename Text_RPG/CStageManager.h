#pragma once

class CStage;

class CStageManager :
    public CSingleton<CStageManager>
{
    SINGLE(CStageManager)

private:
    //vector<CStage*> VecStage;
    CStage* CurStage; // 현재 스테이지
    CStage* PrevStage; // 이전 스테이지
    bool IsDoneTutorialStage = false;
    //CStage* NextStage;

public:
    void StageManagerInit();
    void StageManagerTick();

    bool GetIsDoneTutoStage() { return IsDoneTutorialStage; }
    void SetIsDoneTutoStage(bool b) { IsDoneTutorialStage = b; }

    CStage* GetCurStage();
    CStage* GetPrevStage();
    void ChangeStage(CStage* _nextStage);
    void BackToPrevStage();
};