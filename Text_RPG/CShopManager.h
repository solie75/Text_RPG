#pragma once

class CShopManager :
    public CSingleton<CShopManager>
{
private:
    int ShopCoin;
    int MaxShopCoin;
    float ResalePercent;
    std::map<ITEM_TYPE, class CItem*> Stuff;
public:
    CShopManager();
    int GetItemCnt(ITEM_TYPE);
public:
    int BuyItem(ITEM_TYPE);
    int SellItem(ITEM_TYPE);
};