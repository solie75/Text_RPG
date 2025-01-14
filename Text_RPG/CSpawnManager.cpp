#include "pch.h"
#include "CSpawnManager.h"
#include <random>

std::unique_ptr<CMonster> CSpawnManager::GenerateMonster(int level)
{
	std::default_random_engine RandomGenerator;
	std::uniform_int_distribution<int> MonsterDistribution(0, 2);
	int MonsterIndex = MonsterDistribution(RandomGenerator);

	switch (MonsterIndex)
	{
	case 0:
		Factory = std::make_unique<CGoblinFactory>();
		break;
	case 1:
		Factory = std::make_unique<COrcFactory>();
		break;
	case 2:
		Factory = std::make_unique<CTrollFactory>();
		break;
	}
	return Factory->CreateMonster(level);
}

std::unique_ptr<CBossMonster> CSpawnManager::GenerateBossMonster(int level)
{
	Factory = std::make_unique<CBossMonsterFactory>();
	// TODO : 나중에 확인 형변환
	auto monster = Factory->CreateMonster(level);

	CBossMonster* boss = dynamic_cast<CBossMonster*>(monster.get());
	if (boss == nullptr) {
		throw std::runtime_error("Generated monster is not a CBossMonster");
	}

	monster.release();
	return std::unique_ptr<CBossMonster>(boss);
}
