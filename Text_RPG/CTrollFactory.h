#pragma once
#include "CMonsterFactory.h"
#include "CTroll.h"

class CTrollFactory : public CMonsterFactory
{
public:
	std::unique_ptr<CMonster> CreateMonster(int level) const override;
};