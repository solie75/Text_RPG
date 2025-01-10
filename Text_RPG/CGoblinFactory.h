#pragma once
#include "CMonsterFactory.h"
#include "CGoblin.h"

class CGoblinFactory : public CMonsterFactory
{
public:
	std::unique_ptr<CMonster> CreateMonster(int level) const override;
};