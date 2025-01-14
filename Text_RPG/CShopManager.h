#pragma once

class CShopManager :
    public CSingleton<CShopManager>
{
private:
    int ShopCoin = 300;
    int MaxShopCoin = 500;
    float ResalePercent = 0.6f;
    std::map<ITEM_TYPE, class CItem*> Stuff;
public:
    int BuyItem(ITEM_TYPE);
    int SellItem(ITEM_TYPE);
};