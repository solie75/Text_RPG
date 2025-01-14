#pragma once
#include "CStage.h"
#include "CStageManager.h"

class CStartStage :
    public CStage
{
public:
    enum class START_SCENE
    {
        START,
        TUTORIAL,
        END,
    };

private:
    bool bCallRender = true;
    START_SCENE CurScene = START_SCENE::START;
public:
    virtual void StageInit() override;
    virtual void StageTick() override;
    virtual void StageRender() override;

    void StartScene();
    void TutorialScene();

    void ChangeScene();

    // tutorial animation
private:
    bool bMessiveScolling = false;
    int iCurMissivePart = 0;
    float fMissiveScollingTime = 0.05f;
    float fAccumulatedTime = 0.0f;
    float fNoticeTextDurationTime = 1.0f;

    void MessivePart0();
    void MessivePart1();
    void MessivePart2();
    void MessivePart3();
    void MessivePart4();
    void MessivePart5();
    void MessivePart6();
    void MessivePart7();
    void MessivePart8();
    void MessivePart9();
    void MessivePart10();
    void MessivePart11();
    void MessivePart12();
    void MessivePart13();
    void MessivePart14();
};

