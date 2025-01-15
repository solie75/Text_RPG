#pragma once
#include "CStage.h"



class CVillageStage :
    public CStage
{
public:
    enum DESTINATION_TYPE
    {
        BASIC,
        CHURCH,
        SHOP,
        DUNJEON,
        //HOUSE,
        END
    };
private:
    bool bCallRender = true;
    bool isDestArrowHide = true;
    DESTINATION_TYPE CurDest_Type = DESTINATION_TYPE::BASIC;
    float fDestArrowShowTime = 1.f;
    float fDestArrowHideTime = 0.25f;
    float fAccumulatedTime = 0.0f;

public:
    virtual void StageInit() override;
    virtual void StageTick() override;
    virtual void StageRender() override;

    void ChangeDestination();

    void BasicRender();
    void PointToChurchRender();
    void PointToShopRender();
    void PointToDungeonRender();

private:
    bool bChangeStartPart = false;
    bool bShowNoriceText = false;
    int iCurStartPart = 1;

    void VillageStartPart0();
    void VillageStartPart1();
    void VillageStartPart2();
    void VillageStartPart3();
    void VillageStartPart4();
    void VillageStartPart5();
    void VillageStartPart6();
    void VillageStartPart7();
    void VillageStartPart8();
    void VillageStartPart9();
    void VillageStartPart10();
    void VillageStartPart11();
    void NoticePart();
};

