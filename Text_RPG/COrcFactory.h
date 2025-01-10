#pragma once
#include "CMonsterFactory.h"
#include "COrc.h"

class COrcFactory : public CMonsterFactory
{
public:
	std::unique_ptr<CMonster> CreateMonster(int level) const override;
};