#pragma once

class CPlayer :
	public CSingleton<CPlayer>
{
	SINGLE(CPlayer)

private:
	string Name;
	int MaxNameLength;

	int Level;
	const int MaxLevel = 10;

	int Experience;
	int MaxExperience;

	int Health;
	int MaxHealth;

	int CharacterDamage;
	int Damage;

	int Gold;
	unordered_map<ITEM_TYPE, class CItem*> Inventory;

	bool bHealAccess = true;

	//get, set
public:
	string GetName() { return Name; }
	void SetName(string);
	int GetMaxNameLength() { return MaxNameLength; }
	int GetDamage() { return Damage; }
	int GetHealth() { return Health; }
	int GetGold() { return Gold; }
	int GetMaxHealth() { return MaxHealth; }
	int GetLevel() { return Level; }
	int GetItemCnt(ITEM_TYPE);
	int GetExp() { return Experience; }
	int GetMaxExp() { return MaxExperience; }
	unordered_map<ITEM_TYPE, string> GetItemList();	
	void RegisterMaster();
	void SetBoolHealAccess(bool _b) { bHealAccess = _b; }
	bool GetBoolHealAccess() { return bHealAccess; }
public:
	void IncreaseLevel();
	void Hit(int);
	void Heal(int);
	void IncreaseDamage(int);
	void UseItem(ITEM_TYPE);
	void ExpUp(int);
	void ExpDown();
	void AddItem(ITEM_TYPE);
	string BuyItem(ITEM_TYPE);
	string SellItem(ITEM_TYPE);
	bool CanPayGold(int);
	void PayGold(int);
	void ReceiveGold(int);
	void ResetDamage();
	void Church_Heal();
	string GetItemName(ITEM_TYPE);
};

