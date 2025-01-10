#pragma once
#include "CMonsterFactory.h"
#include "CBossMonster.h"

class CBossMonsterFactory : public CMonsterFactory
{
public:
	std::unique_ptr<CMonster> CreateMonster(int level) const override;
};