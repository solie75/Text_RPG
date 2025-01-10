#include "pch.h"
#include "CGoblinFactory.h"

std::unique_ptr<CMonster> CGoblinFactory::CreateMonster(int level) const
{
	return std::make_unique<CGoblin>(level);
}