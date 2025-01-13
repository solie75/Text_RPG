#pragma once
#include "pch.h"

class CItem
{
private:
	string Name;

public:
	string GetName() { return Name; }

	virtual void Use(int) = 0;
};