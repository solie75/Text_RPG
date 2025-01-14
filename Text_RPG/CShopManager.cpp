#include "pch.h"
#include "CShopManager.h"
#include "CHealthPotion.h"
#include "CAttackBoost.h"
#include "CPlayer.h"

int CShopManager::BuyItem(ITEM_TYPE Item_t)
{
	CItem* Item;
	switch (Item_t)
	{
	case ITEM_TYPE::HEALTH_POTION:
		Item = new CHealthPotion("Health Potion", 1);
		break;
	case ITEM_TYPE::ATTACK_BOOST:
		Item = new CAttackBoost("Attack Boost", 1);
		break;
	default:
		//non type
		return 0;
	}

	int ResalePrice = round(Item->GetPrice() * ResalePercent);
	if (ShopCoin - ResalePrice < 0)
	{
		//can not resell
		return 0;
	}
	ShopCoin -= ResalePrice;

	if (Stuff.find(Item_t) != Stuff.end())
	{
		Item = Stuff[Item_t];
		Item->IncreaseCnt();
	}
	else
	{
		Stuff.insert({ Item_t, Item });
	}
	
	return ResalePrice;
}

int CShopManager::SellItem(ITEM_TYPE Item_t)
{
	if (Stuff.find(Item_t) == Stuff.end())
	{
		//non type
		return 0;
	}

	CItem* Item = Stuff[Item_t];
	if (Item->GetCnt() == 0)
	{
		//out of stock
		return 0;
	}

	if (!CPlayer::GetInst()->CanPayGold(Item->GetPrice()))
	{
		//player doesn't have gold
		return 0;
	}

	int temp = ShopCoin + Item->GetPrice();
	if (temp > MaxShopCoin)
	{
		//no more sell
		return 0;
	}

	ShopCoin = temp;
	Item->ReduceCnt();
	return Item->GetPrice();
}