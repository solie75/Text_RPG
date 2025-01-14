#pragma once
#include "pch.h"
#include "CMonster.h"
#include "CItem.h"

class CGoblin : public CMonster
{
private:
	string name;
	int health;
	int damage;
public:
	CGoblin(int level);
	virtual string GetName() const override;
	virtual int GetHealth() const override;
	virtual int GetDamage() const override;
	virtual void Hit(int damage) override;
	virtual CItem* DropItem() override;
};
