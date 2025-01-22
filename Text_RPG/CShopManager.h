#pragma once

class CShopManager :
    public CSingleton<CShopManager>
{
private:
    int ShopCoin;
    int ItemCnt;
    float ResalePercent;
    unordered_map<ITEM_TYPE, class CItem*> Stuff;
public:
    CShopManager();

    void CShopManagerInit();

    int GetItemCnt(ITEM_TYPE);
    unordered_map<ITEM_TYPE, string> GetItemList();

public:
    int BuyItem(ITEM_TYPE);
    bool SellItem(ITEM_TYPE);
};