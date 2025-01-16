#pragma once
#include "pch.h"
#include "CItem.h"

class CMonster
{
protected:
	vector<string> TextImg;
public:
	virtual string GetName() const = 0;
	virtual int GetHealth() const = 0;
	virtual int GetDamage() const = 0;
	virtual void Hit(int damage) = 0;
	virtual ITEM_TYPE DropItem() = 0;
	virtual string GetTextImgLine(int idx) { return TextImg[idx]; };
	int GetTextImgSize() { return TextImg.size(); };
	virtual void ImageInit() = 0;
};