#include "pch.h"
#include "COrc.h"
#include "CHealthPotion.h"
#include "CAttackBoost.h"
#include "CMonsterLeather.h"
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

string COrc::GetName() const
{
	return name;
}

int COrc::GetHealth() const
{
	return health;
}

int COrc::GetDamage() const
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
		if (ItemDropProbabiliity <= 10) // 1/3 Ȯ���� ü�� ������ ���
		{
			return new CHealthPotion("Health Potion", 1);
		}
		else if (ItemDropProbabiliity <= 20) // 1/3 Ȯ���� ���ݷ� ���� ������ ���
		{
			return new CAttackBoost("Attack Boost", 1);
		}
		else // 1/3 Ȯ���� ���� ���� ���
		{
			return new CMonsterLeather("Monster Leather", 1);
		}
	}

	// �������� ������� ����
	return nullptr;
}
