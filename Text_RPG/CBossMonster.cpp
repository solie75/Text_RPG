#include "pch.h"
#include "CBossMonster.h"
#include "CHealthPotion.h"
#include "CAttackBoost.h"
#include <random>

CBossMonster::CBossMonster(int level)
{
	name = "Dragon";
	std::default_random_engine RandomGenerator;
	// ü���� ĳ���� ������ ����ؼ� �����ϰ� ����(����*20~����*30)
	std::uniform_int_distribution<int> HealthDistribution(level * 20, level * 30);
	health = HealthDistribution(RandomGenerator) * 1.5;
	// ���ݷ��� ĳ���� ������ ����ؼ� �����ϰ� ����(����*5~����*10)
	std::uniform_int_distribution<int> DamageDistribution(level * 5, level * 10);
	damage = DamageDistribution(RandomGenerator) * 1.5;
}

string CBossMonster::GetName() const
{
	return name;
}

int CBossMonster::GetHealth() const
{
	return health;
}

int CBossMonster::GetDamage() const
{
	return damage;
}

void CBossMonster::Hit(int damage)
{
	health = health - damage > 0 ? health - damage : 0;
}

CItem* CBossMonster::DropItem()
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
