#pragma once
class CStage
{
public:
	virtual void StageTick() = 0;
	virtual void StageInit() = 0;
	virtual void StageRender() = 0;
};