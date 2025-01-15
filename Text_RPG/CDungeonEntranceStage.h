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
	bool isDungeunFirst = true; // �÷��̾��� ������ 1 �̰� exp �� 0 �̸� isDungeonFirst �� true �� �����Ѵ�. -> �÷��̾� ������ ����ġ �������� ������ ��ü
	bool bAccessBoss = false; // �÷��̾��� ������ 10 �̻��̸� bAccessBoss �� false -> �÷��̾��� ������ �������� ������ ��ü
	int iCurTextPart = 1;
};

