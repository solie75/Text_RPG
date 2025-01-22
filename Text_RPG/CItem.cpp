#include "pch.h"
#include "CItem.h"

string CItem::GetName()
{
    return Name;
}

int CItem::GetPrice()
{
    return Price;
}

int CItem::GetCnt()
{
    return Cnt;
}

void CItem::SetPrice(int _Price)
{
    Price = _Price;
}

void CItem::SetCnt(int _Cnt)
{
    Cnt = _Cnt;
}

void CItem::ReduceCnt()
{
    Cnt--;
}

void CItem::IncreaseCnt()
{
    Cnt++;
}
