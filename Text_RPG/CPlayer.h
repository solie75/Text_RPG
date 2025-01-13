#pragma once

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
	//vector<item*> Inventory;

	//get, set
public:
	void SetName(string);
	void SetDamage(int);
	void SetHealth(int);
public:
	int GetInventorySize();
	void IncreaseLevel();
	void TakeDamage(int);
	void UseItem(int);
	void ExpUp(int);
};

