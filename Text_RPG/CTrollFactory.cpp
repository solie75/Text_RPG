#include "pch.h"
#include "CTrollFactory.h"

std::unique_ptr<CMonster> CTrollFactory::CreateMonster(int level) const
{
    return std::make_unique<CTroll>(level);
}
