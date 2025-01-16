#pragma once
#include "pch.h"
#include "CMonster.h"

class COrc : public CMonster
{
private:
	string name;
	int health;
	int damage;
public:
	COrc(int level);
	virtual string GetName() const override;
	virtual int GetHealth() const override;
	virtual int GetDamage() const override;
	virtual void Hit(int damage) override;
	virtual ITEM_TYPE DropItem() override;
	virtual void ImageInit() override;
};
