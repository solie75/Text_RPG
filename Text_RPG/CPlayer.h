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

	int CharacterDamage;
	int Damage;

	int Gold;
	std::map<ITEM_TYPE, class CItem*> Inventory;

	//get, set
public:
	string GetName() { return Name; }
	void SetName(string);
	int GetDamage() { return Damage; }
	int GetHealth() { return Health; }
	int GetGold() { return Gold; }
	int GetMaxHealth() { return MaxHealth; }
	int GetLevel() { return Level; }
	int GetItemCnt(ITEM_TYPE);
public:
	void IncreaseLevel();
	void Hit(int);
	void Heal(int);
	void IncreaseDamage(int);
	void UseItem(ITEM_TYPE);
	void ExpUp(int);
	void ExpDown();
	void AddItem(ITEM_TYPE);
	void BuyItem(ITEM_TYPE);
	void SellItem(ITEM_TYPE);
	bool CanPayGold(int);
	void PayGold(int);
	void ReceiveGold(int);
	void ResetDamage();
};

