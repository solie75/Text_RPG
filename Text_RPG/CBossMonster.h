#pragma once
#include "pch.h"
#include "CMonster.h"

class CBossMonster : public CMonster
{
private:
	string name;
	int health;
	int damage;
public:
	CBossMonster(int level);
	virtual string GetName() const override;
	virtual int GetHealth() const override;
	virtual int GetDamage() const override;
	virtual void Hit(int damage) override;
	//Item* DropItem();
};