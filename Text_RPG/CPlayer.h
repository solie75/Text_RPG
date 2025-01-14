#pragma once
#include "CItem.h"

class CPlayer :
	public CSingleton<CPlayer>
{
	SINGLE(CPlayer)

private:
	string Name;

	int Level;
	const int MaxLevel = 10;

	int Experience;
	int MaxExperience;

	int Health;
	int MaxHealth;

	int Damage;

	int Gold;
	std::map<string, int> Inventory;

	//get, set
public:
	void SetName(string);
	void SetDamage(int);
	int GetDamage(){ return Damage; }
	void SetHealth(int);
	int GetHealth() { return Health; }
public:
	void IncreaseLevel();
	void TakeDamage(int);
	void UseItem(string);
	void ExpUp(int);
};

