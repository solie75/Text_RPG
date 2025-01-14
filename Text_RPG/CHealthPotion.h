#pragma once
#include "CItem.h"

class CHealthPotion
	: public CItem
{
private:
	int Amount = 50;

public:
	CHealthPotion(string _Name, int _Cnt) : CItem(_Name, _Cnt) { SetPrice(10); }
	int GetAmount();

public:
	virtual void Use() override;
};