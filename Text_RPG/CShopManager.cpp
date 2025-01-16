#include "pch.h"
#include "CShopManager.h"
#include "CHealthPotion.h"
#include "CAttackBoost.h"
#include "CMonsterLeather.h"
#include "CPlayer.h"

CShopManager::CShopManager()
{
	ShopCoin = 300;
	MaxShopCoin = 500;
	ResalePercent = 0.6f;

	Stuff.insert({ ITEM_TYPE::HEALTH_POTION, new CHealthPotion("Health Potion", 0) });
	Stuff.insert({ ITEM_TYPE::ATTACK_BOOST, new CAttackBoost("Attack Boost", 0) });
}

int CShopManager::GetItemCnt(ITEM_TYPE Item_t)
{
	if (Stuff.find(Item_t) == Stuff.end())
	{
		//doesn't have, in list
		return -1;
	}

	return Stuff[Item_t]->GetCnt();
}

int CShopManager::BuyItem(ITEM_TYPE Item_t)
{
	CItem* Item;
	int SalePrice;
	bool isSale = true; //is not sold in shop

	//items not sold in shop
	if (Stuff.find(Item_t) == Stuff.end())
	{
		switch (Item_t)
		{
		case ITEM_TYPE::MONSTER_LEATHER:
			Item = new CMonsterLeather("Monster Leather", 0);
			isSale = false;
			break;
		default:
			//non type
			return 0;
		}
		SalePrice = Item->GetPrice();
	}
	//items sold in shop
	//resale percent of pirce
	else
	{
		Item = Stuff[Item_t];
		SalePrice = round(Item->GetPrice() * ResalePercent);
	}

	//not enough shopcoin
	if (ShopCoin - SalePrice < 0)
	{
		//can not buy
		return 0;
	}
	ShopCoin -= SalePrice;

	if (isSale)
	{
		Item->IncreaseCnt();
	}

	return SalePrice;
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