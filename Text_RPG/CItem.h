#pragma once

class CItem
{
private:
	string Name;
	int Cnt;
	int Price=0;

public:
	CItem(string _Name, int _Cnt) : Name(_Name), Cnt(_Cnt) {}
	string GetName();
	int GetPrice();
	int GetCnt();
	void SetPrice(int);

public:
	void ReduceCnt();
	void IncreaseCnt();
	virtual void Use() = 0;
};