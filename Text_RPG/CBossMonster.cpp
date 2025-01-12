#include "pch.h"
#include "CBossMonster.h"
#include <random>

CBossMonster::CBossMonster(int level)
{
	name = "Dragon";
	std::default_random_engine RandomGenerator;
	// 체력은 캐릭터 레벨에 비례해서 랜덤하게 생성(레벨*20~레벨*30)
	std::uniform_int_distribution<int> HealthDistribution(level * 20, level * 30);
	health = HealthDistribution(RandomGenerator) * 1.5;
	// 공격력은 캐릭터 레벨에 비례해서 랜덤하게 생성(레벨*5~레벨*10)
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
	health -= damage;
}
