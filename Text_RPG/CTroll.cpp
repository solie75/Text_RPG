#include "pch.h"
#include "CTroll.h"
#include <random>

CTroll::CTroll(int level)
{
	name = "Troll";
	std::default_random_engine RandomGenerator;
	// ü���� ĳ���� ������ ����ؼ� �����ϰ� ����(����*20~����*30)
	std::uniform_int_distribution<int> HealthDistribution(level * 20, level * 30);
	health = HealthDistribution(RandomGenerator);
	// ���ݷ��� ĳ���� ������ ����ؼ� �����ϰ� ����(����*5~����*10)
	std::uniform_int_distribution<int> DamageDistribution(level * 5, level * 10);
	damage = DamageDistribution(RandomGenerator);
}

string CTroll::GetName()
{
	return name;
}

int CTroll::GetHealth()
{
	return health;
}

int CTroll::GetDamage()
{
	return damage;
}

void CTroll::Hit(int damage)
{
	health -= damage;
}
