#include "pch.h"
#include "CPlayer.h"
#include "CItem.h"
#include "CHealthPotion.h"
#include "CAttackBoost.h"
#include "CMonsterLeather.h"
#include "CShopManager.h"

CPlayer::CPlayer()
{
	MaxNameLength = 10;
	Level = 1;
	MaxHealth = 200;
	Health = MaxHealth;
	CharacterDamage = 30;
	Damage = CharacterDamage;
	Experience = 0;
	MaxExperience = 100;
	Gold = 10;

	Inventory.insert({ ITEM_TYPE::HEALTH_POTION, new CHealthPotion("Health Potion", 0) });
	Inventory.insert({ ITEM_TYPE::ATTACK_BOOST, new CAttackBoost("Attack Boost", 0) });
	Inventory.insert({ITEM_TYPE::MONSTER_LEATHER, new CMonsterLeather("Monster Leather", 0)});
}

CPlayer::~CPlayer()
{

}

void CPlayer::SetName(string _str)
{
	Name = _str;

	//시연, 테스트용 마스터 계정, level 10, 체력 1000, 공격력 1000
	if (_str == "master")
		RegisterMaster();
}

int CPlayer::GetItemCnt(ITEM_TYPE Item_t)
{
	if (Inventory.find(Item_t) == Inventory.end())
	{
		//doesn't have, in list
		return -1;
	}

	return Inventory[Item_t]->GetCnt();
}

unordered_map<ITEM_TYPE, string> CPlayer::GetItemList()
{
	unordered_map<ITEM_TYPE, string> list;
	for (auto it : Inventory)
	{
		list.insert({ it.first, it.second->GetName() });
	}
	return list;
}

void CPlayer::RegisterMaster()
{
	Level = 10;
	MaxExperience = 0;
	Damage = 999;
	MaxHealth = 999;
	Health = MaxHealth;
	Gold = 500;
	AddItem(ITEM_TYPE::HEALTH_POTION);
	AddItem(ITEM_TYPE::HEALTH_POTION);
	AddItem(ITEM_TYPE::HEALTH_POTION);
	AddItem(ITEM_TYPE::HEALTH_POTION);
	AddItem(ITEM_TYPE::ATTACK_BOOST);
	AddItem(ITEM_TYPE::ATTACK_BOOST);
	AddItem(ITEM_TYPE::ATTACK_BOOST);
	AddItem(ITEM_TYPE::ATTACK_BOOST);
	AddItem(ITEM_TYPE::MONSTER_LEATHER);
	AddItem(ITEM_TYPE::MONSTER_LEATHER);
	AddItem(ITEM_TYPE::MONSTER_LEATHER);
	AddItem(ITEM_TYPE::MONSTER_LEATHER);
}

void CPlayer::IncreaseLevel()
{
	if (Level == MaxLevel) // 나중에 포션 등으로 레벨 올렸을 경우 대비.
		return;

	Level++;

	if (Level == MaxLevel) // 만렙 : 경험치0, 필요경험치 0;
	{
		Experience = 0;
		MaxExperience = 0;
	}
	else
	{
		Experience %= MaxExperience;
		MaxExperience *= 1.1;
	}

	MaxHealth += 20;
	Health = MaxHealth;
	CharacterDamage += 5;
}

void CPlayer::Hit(int _damage)
{
	Health = Health - _damage > 0 ? Health - _damage : 0;
}

void CPlayer::ResetDamage()
{
	Damage = CharacterDamage;
}

void CPlayer::Church_Heal()
{
	Health += (MaxHealth / 3);
	if (Health > MaxHealth)
	{
		Health = MaxHealth;
	}
	Gold = Gold - (Gold / 3);
}

string CPlayer::GetItemName(ITEM_TYPE _itemType)
{
	return Inventory[_itemType]->GetName();
}

void CPlayer::Heal(int amount)
{
	Health += amount;

	if (Health >= MaxHealth)
		Health = MaxHealth;
}

void CPlayer::IncreaseDamage(int amount)
{
	Damage += amount;
}

void CPlayer::UseItem(ITEM_TYPE Item_t)
{
	Inventory[Item_t]->Use();
}

void CPlayer::ExpUp(int _up)
{

	if (Level != MaxLevel) // 만렙 : 경험치 올릴필요 없음
	{
		Experience += _up;

		//레벨업
		if (Experience >= MaxExperience)
		{
			IncreaseLevel();
		}
	}
}

void CPlayer::ExpDown()
{
	Experience = Experience  -(Experience / 3);
}
void CPlayer::AddItem(ITEM_TYPE Item_t)
{
	Inventory[Item_t]->IncreaseCnt();
}

string CPlayer::BuyItem(ITEM_TYPE Item_t)
{
	int ItemPrice = Inventory[Item_t]->GetPrice();

	if (Gold - ItemPrice < 0)
	{
		//not enough money
		return "You don't have enough gold !";
	}

	bool SellResult = CShopManager::GetInst()->SellItem(Item_t);
	if (!SellResult)
	{
		return "That item is out of stock !";
	}

	AddItem(Item_t);
	PayGold(ItemPrice);
	return "";
}

string CPlayer::SellItem(ITEM_TYPE Item_t)
{
	CItem* Item = Inventory[Item_t];
	if (Item->GetCnt() == 0)
	{
		//doesn't have
		return "You don't have that item !";
	}

	int SalePrice = CShopManager::GetInst()->BuyItem(Item_t);
	if (SalePrice == 0)
	{
		//can not sell(shop problem)
		return "You can't sell any more !";
	}

	Item->ReduceCnt();
	ReceiveGold(SalePrice);
	return "";
}

bool CPlayer::CanPayGold(int Price)
{
	if (Gold - Price < 0)
		return false;
	else
		return true;
}

void CPlayer::PayGold(int Price)
{
	Gold -= Price;
}

void CPlayer::ReceiveGold(int Price)
{
	Gold += Price;
}