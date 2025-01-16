#pragma once
#include "pch.h"
#include "CStage.h"
class CStateStage :
	public CStage
{
public:
	virtual void StageInit() override;
	virtual void StageTick() override;
	virtual void StageRender() override;
	string SpaceMaker(string myString, int stringSize);

private:
	string PlayerName;
	int PlayerLevel;
	int PlayerExperience;
	int PlayerHealth;
	int PlayerDamage;
	int PlayerGold;
	int PlayerMaxHealth;
	int PlayerMaxExperience;
};
