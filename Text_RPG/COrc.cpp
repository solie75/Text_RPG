#include "pch.h"
#include "COrc.h"
#include "CHealthPotion.h"
#include "CAttackBoost.h"
#include <random>

COrc::COrc(int level)
{
	name = "Orc";
	std::default_random_engine RandomGenerator;
	// ü���� ĳ���� ������ ����ؼ� �����ϰ� ����(����*20~����*30)
	std::uniform_int_distribution<int> HealthDistribution(level * 20, level * 30);
	health = HealthDistribution(RandomGenerator);
	// ���ݷ��� ĳ���� ������ ����ؼ� �����ϰ� ����(����*5~����*10)
	std::uniform_int_distribution<int> DamageDistribution(level * 5, level * 10);
	damage = DamageDistribution(RandomGenerator);
}

string COrc::GetName()
{
	return name;
}

int COrc::GetHealth()
{
	return health;
}

int COrc::GetDamage()
{
	return damage;
}

void COrc::Hit(int damage)
{
	health -= damage;
}

CItem* COrc::DropItem()
{
	std::default_random_engine RandomGenerator;
	std::uniform_int_distribution<int> ItemDropDistribution(0, 100);
	int ItemDropProbabiliity = ItemDropDistribution(RandomGenerator);

	//30% Ȯ���� ������ ���
	if (ItemDropProbabiliity <= 30)
	{
		// 50% Ȯ���� ü�� ������ ���
		if (ItemDropProbabiliity <= 15)
		{
			return new CHealthPotion("CHealthPotion", 10);
		}
		else // 50% Ȯ���� ���ݷ� ���� ������ ���
		{
			return new CAttackBoost("CAttackBoost", 10);
		}
	}

	// �������� ������� ����
	return nullptr;
}
