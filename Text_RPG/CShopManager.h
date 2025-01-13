#pragma once
class CShopManager :
    public CSingleton<CShopManager>
{
private:
    int ShopCoin;
public:
    void BuyItem(int Index, class CPlayer* Character);
    void SellItem(int Index, class CPlayer* Character);
};