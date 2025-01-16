#pragma once
#include "CStage.h"
class CChurchStage :
	public CStage
{
public:
	virtual void StageTick() override;
	virtual void StageInit() override;
	virtual void StageRender() override;

public:
	void BasicRender();
	bool bCallRender = true;

	//void FirstText
};

