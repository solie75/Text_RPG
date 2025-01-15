#pragma once
#include "pch.h"
#include "CItem.h"

class CMonster
{
public:
	virtual string GetName() const = 0;
	virtual int GetHealth() const = 0;
	virtual int GetDamage() const = 0;
	virtual void Hit(int damage) = 0;
	virtual ITEM_TYPE DropItem() = 0;
};