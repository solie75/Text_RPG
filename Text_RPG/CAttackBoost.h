#pragma once
#include "pch.h"
#include "CItem.h"

class CAttackBoost
	: public CItem
{
private:
	string Name;
	int AttackIncrease;
public:
	CAttackBoost(string name, int amount) : Name(name), AttackIncrease(amount) {}

	// Inherited via CItem
	void Use(int) override;
};