#pragma once
#include "pch.h"
#include "CMonster.h"

class CTroll : public CMonster
{
private:
	string name;
	int health;
	int damage;
public:
	CTroll(int level);
	virtual string GetName() const override;
	virtual int GetHealth() const override;
	virtual int GetDamage() const override;
	virtual void Hit(int damage) override;
	virtual CItem* DropItem() override;
};
