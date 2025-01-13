#pragma once
#include "pch.h"
#include "CItem.h"

class CHealthPotion
	: public CItem
{
private:
	string Name;
	int HealthRestore;
public:
	CHealthPotion(string name, int amount) : Name(name), HealthRestore(amount) {}

	// Inherited via CItem
	void Use(int) override;
};