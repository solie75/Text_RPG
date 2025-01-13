#pragma once
class CPlayer :
	public CSingleton<CPlayer>
{
	SINGLE(CPlayer)

private:
	string Name;
	int Level;
	int Health;
	int MaxHealth;
	int Damage;
	int Experience;
	int Gold;
	//vector<item*> Inventory;

	//get, set
public:
	void CPlayer();
	void SetName(string);
public:
	void LevelUp();
	void TakeDamage(int);
	void DisplayStatus();
	void UseItem(int);
	void VisitShop();
};

