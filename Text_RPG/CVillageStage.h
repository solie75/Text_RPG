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
};

