#pragma once
#include "CItem.h"

class CMonsterLeather
	: public CItem
{
public:
	CMonsterLeather(string _Name, int _Cnt) : CItem(_Name, _Cnt) { SetPrice(5); }
	virtual void Use() override;
};

