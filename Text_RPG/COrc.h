#pragma once
#include "pch.h"
#include "CMonster.h"

class COrc : public CMonster
{
private:
	string name;
	int health;
	int damage;
public:
	COrc(int level);
	string GetName();
	int GetHealth();
	int GetDamage();
	void Hit(int damage);
	//Item* DropItem();
};