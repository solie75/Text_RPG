#include "pch.h"
#include "CSpawnManager.h"
#include <random>

std::unique_ptr<CMonster> CSpawnManager::GenerateMonster(int level)
{
	// 랜럼 관련 변수들
	std::random_device RandomDevice; // 시드값을 얻기 위한 random_device 생성
	std::mt19937 gen(RandomDevice()); // random_device를 통해 난수 생성 엔진을 초기화
	std::uniform_int_distribution<int> Distribution(0, 2); // 0~100까지 난수열을 생성하귀 위해 균등 분포 정의
	
	int MonsterIndex = Distribution(gen); // 몬스터 랜덤 생성

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
