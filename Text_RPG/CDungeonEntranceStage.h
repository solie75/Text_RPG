#pragma once
#include "CStage.h"
class CDungeonEntranceStage :
    public CStage
{
public:
	virtual void StageTick() override;
	virtual void StageInit() override;
	virtual void StageRender() override;

	void BasicRender();
	void PointToBossAccess();
	void PointToBossNoAccess();
	void PointToNormal();

	void StartTextPart1();
	void StartTextPart2();
	void StartTextPart3();
	void StartTextPart4();
	void DungeonSelectTextPart1();
	void DungeonSelectTextPart2();
	void DungeonSelectTextPart3();

private:
	bool bCallRender = true;
	bool isDungeunFirst = true; // 플레이어의 레벨이 1 이고 exp 가 0 이면 isDungeonFirst 를 true 로 지정한다. -> 플레이어 레벨과 경험치 가져오는 것으로 대체
	bool bAccessBoss = false; // 플레이어의 레벨이 10 이상이면 bAccessBoss 가 false -> 플레이어의 레벨을 가져오는 것으로 대체
	int iCurTextPart = 1;
};

