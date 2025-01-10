#include "pch.h"
#include "COrcFactory.h"

std::unique_ptr<CMonster> COrcFactory::CreateMonster(int level) const
{
    return std::make_unique<COrc>(level);
}
