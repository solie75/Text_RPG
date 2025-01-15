#include "pch.h"
#include "CPlayer.h"
#include "CItem.h"
#include "CHealthPotion.h"
#include "CAttackBoost.h"
#include "CMonsterLeather.h"
#include "CShopManager.h"

CPlayer::CPlayer()
{
	Level = 1;
	MaxHealth = 200;
	Health = MaxHealth;
	CharacterDamage = 30;
	Damage = CharacterDamage;
	Experience = 0;
	MaxExperience = 100;
	Gold = 0;

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
	Experience /= 30;
}
void CPlayer::AddItem(ITEM_TYPE Item_t)
{
	Inventory[Item_t]->IncreaseCnt();
}

void CPlayer::BuyItem(ITEM_TYPE Item_t)
{
	int ItemPrice = CShopManager::GetInst()->SellItem(Item_t);
	if (ItemPrice == 0)
	{
		//not enough money
		return;
	}

	AddItem(Item_t);
	PayGold(ItemPrice);
}

void CPlayer::SellItem(ITEM_TYPE Item_t)
{
	CItem* Item = Inventory[Item_t];
	if (Item->GetCnt() == 0)
	{
		//doesn't have
		return;
	}

	int SalePrice = CShopManager::GetInst()->BuyItem(Item_t);
	if (SalePrice == 0)
	{
		//can not sell(shop problem)
		return;
	}

	Item->ReduceCnt();
	ReceiveGold(SalePrice);
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