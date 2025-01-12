#include "pch.h"
#include "CGoblin.h"
#include <random>

CGoblin::CGoblin(int level)
{
	name = "Goblin";
	std::default_random_engine RandomGenerator;
	// ü���� ĳ���� ������ ����ؼ� �����ϰ� ����(����*20~����*30)
	std::uniform_int_distribution<int> HealthDistribution(level*20, level*30);
	health = HealthDistribution(RandomGenerator);
	// ���ݷ��� ĳ���� ������ ����ؼ� �����ϰ� ����(����*5~����*10)
	std::uniform_int_distribution<int> DamageDistribution(level * 5, level * 10);
	damage = DamageDistribution(RandomGenerator);
}

string CGoblin::GetName() const
{
	return name;
}

int CGoblin::GetHealth() const
{
	return health;
}

int CGoblin::GetDamage() const
{
	return damage;
}

void CGoblin::Hit(int damage)
{
	health -= damage;
}