#include "pch.h"
#include "CBossMonsterFactory.h"

std::unique_ptr<CMonster> CBossMonsterFactory::CreateMonster(int level) const
{
    return std::make_unique<CBossMonster>(level);
}
