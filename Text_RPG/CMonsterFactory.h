#pragma once
#include "pch.h"
#include "CMonster.h"
#include <memory>

class CMonsterFactory
{
public:
	virtual std::unique_ptr<CMonster> CreateMonster(int level) const = 0;
	virtual ~CMonsterFactory() = default;
};