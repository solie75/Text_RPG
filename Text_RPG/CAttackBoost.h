#pragma once
#include "CItem.h"

class CAttackBoost
	: public CItem
{
private:
	int Amount = 10;

public:
	CAttackBoost(string _Name, int _Cnt) : CItem(_Name, _Cnt) { SetPrice(15); }
	int GetAmount();

public:
	virtual void Use() override;
};