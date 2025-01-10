#pragma once
#include "pch.h"
#include "CMonster.h"

class CGoblin : public CMonster
{
private:
	string name;
	int health;
	int damage;
public:
	CGoblin(int level);
	string GetName();
	int GetHealth();
	int GetDamage();
	void Hit(int damage);
	//Item* DropItem();
};