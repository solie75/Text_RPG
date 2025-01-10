#pragma once
#include "pch.h"

class CMonster
{
public:
	virtual string GetName() const = 0;
	virtual int GetHealth() const = 0;
	virtual int GetDamage() const = 0;
	virtual void Hit(int damage) = 0;
	//virtual Item* DropItem() = 0;
};