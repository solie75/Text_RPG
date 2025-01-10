#pragma once
#include <memory>
#include "CGoblin.h"
#include "COrc.h"
#include "CTroll.h"
#include "CBossMonster.h"
#include "CGoblinFactory.h"
#include "COrcFactory.h"
#include "CTrollFactory.h"
#include "CBossMonsterFactory.h"

class CSpawnManager :
    public CSingleton<CSpawnManager>
{
private:
    std::unique_ptr<CMonsterFactory> Factory;
public:
    std::unique_ptr<CMonster> GenerateMonster(int level);
    std::unique_ptr<CBossMonster> GenerateBossMonster(int level);
};

