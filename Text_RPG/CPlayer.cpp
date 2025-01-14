#include "pch.h"
#include "CPlayer.h"
#include "CItem.h"
#include "CHealthPotion.h"
#include "CAttackBoost.h"
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

}

CPlayer::~CPlayer()
{

}

void CPlayer::SetName(string _str)
{
	Name = _str;
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
	if (Inventory.find(Item_t) != Inventory.end())
	{
		Inventory[Item_t]->Use();
	}
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
void CPlayer::BuyItem(ITEM_TYPE Item_t)
{
	int ItemPrice = CShopManager::GetInst()->SellItem(Item_t);
	if (ItemPrice == 0)
	{
		//not enough money
		return;
	}

	if (Inventory.find(Item_t) == Inventory.end())
	{
		switch (Item_t)
		{
		case ITEM_TYPE::HEALTH_POTION:
			Inventory.insert({ Item_t, new CHealthPotion("Health Potion", 1) });
			break;
		case ITEM_TYPE::ATTACK_BOOST:
			Inventory.insert({ Item_t, new CAttackBoost("Attack Boost", 1) });
			break;
		default:
			//non type
			return;
		}
	}
	else
	{
		Inventory[Item_t]->IncreaseCnt();
	}

	PayGold(ItemPrice);
}

void CPlayer::SellItem(ITEM_TYPE Item_t)
{
	if (Inventory.find(Item_t) == Inventory.end())
	{
		//can not sell(player problem)
		return;
	}

	int ResalePrice = CShopManager::GetInst()->BuyItem(Item_t);
	if (ResalePrice == 0)
	{
		//cna not sell(shop problem)
		return;
	}

	CItem* Item = Inventory[Item_t];
	if (Item->GetCnt() == 1)
	{
		Inventory.erase(Item_t);
	}
	else
	{
		Item->ReduceCnt();
	}

	ReceiveGold(ResalePrice);
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

void CPlayer::ResetDamage()
{
	Damage = CharacterDamage;
}
