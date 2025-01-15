#include "pch.h"
#include "CSpawnManager.h"
#include <random>

std::unique_ptr<CMonster> CSpawnManager::GenerateMonster(int level)
{
	// ���� ���� ������
	std::random_device RandomDevice; // �õ尪�� ��� ���� random_device ����
	std::mt19937 gen(RandomDevice()); // random_device�� ���� ���� ���� ������ �ʱ�ȭ
	std::uniform_int_distribution<int> Distribution(0, 2); // 0~100���� �������� �����ϱ� ���� �յ� ���� ����
	
	int MonsterIndex = Distribution(gen); // ���� ���� ����

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
	// TODO : ���߿� Ȯ�� ����ȯ
	auto monster = Factory->CreateMonster(level);

	CBossMonster* boss = dynamic_cast<CBossMonster*>(monster.get());
	if (boss == nullptr) {
		throw std::runtime_error("Generated monster is not a CBossMonster");
	}

	monster.release();
	return std::unique_ptr<CBossMonster>(boss);
}
