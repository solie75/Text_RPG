#include "pch.h"
#include "CShopManager.h"
#include "CHealthPotion.h"
#include "CAttackBoost.h"
#include "CMonsterLeather.h"
#include "CPlayer.h"


CShopManager::CShopManager()
{
	CShopManagerInit();
}

void CShopManager::CShopManagerInit()
{
	ShopCoin = 300;
	ResalePercent = 0.6f;
	ItemCnt = 5;

	if(Stuff.empty())
	{
		Stuff.insert({ ITEM_TYPE::HEALTH_POTION, new CHealthPotion("Health Potion", ItemCnt) });
		Stuff.insert({ ITEM_TYPE::ATTACK_BOOST, new CAttackBoost("Attack Boost", ItemCnt) });
	}

	for (auto item : Stuff)
	{
		item.second->SetCnt(ItemCnt);
	}
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

unordered_map<ITEM_TYPE, string> CShopManager::GetItemList()
{
	unordered_map<ITEM_TYPE, string> list;
	for (auto it : Stuff)
	{
		list.insert({ it.first, it.second->GetName() });
	}
	return list;
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
		delete Item;
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

bool CShopManager::SellItem(ITEM_TYPE Item_t)
{
	CItem* Item = Stuff[Item_t];
	if (Item->GetCnt() == 0)
	{
		//out of stock
		return false;
	}

	ShopCoin += Item->GetPrice();
	Item->ReduceCnt();

	return true;
}