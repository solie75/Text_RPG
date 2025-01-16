#pragma once

class CShopManager :
    public CSingleton<CShopManager>
{
private:
    int ShopCoin;
    int MaxShopCoin;
    float ResalePercent;
    unordered_map<ITEM_TYPE, class CItem*> Stuff;
public:
    CShopManager();

    int GetItemCnt(ITEM_TYPE);
    unordered_map<ITEM_TYPE, string> GetItemList();

public:
    int BuyItem(ITEM_TYPE);
    int SellItem(ITEM_TYPE);
};