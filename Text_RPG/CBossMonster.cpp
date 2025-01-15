#include "pch.h"
#include "CBossMonster.h"
#include "CHealthPotion.h"
#include "CAttackBoost.h"
#include "CMonsterLeather.h"
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

CItem* CBossMonster::DropItem()
{
	std::default_random_engine RandomGenerator;
	std::uniform_int_distribution<int> ItemDropDistribution(0, 100);
	int ItemDropProbabiliity = ItemDropDistribution(RandomGenerator);

	//30% 확률로 아이템 드랍
	if (ItemDropProbabiliity <= 30) 
	{
		if (ItemDropProbabiliity <= 10) // 1/3 확률로 체력 아이템 드랍
		{
			return new CHealthPotion("Health Potion", 1);
		}
		else if(ItemDropProbabiliity <=20) // 1/3 확률로 공격력 증가 아이템 드랍
		{
			return new CAttackBoost("Attack Boost", 1);
		}
		else // 1/3 확률로 몬스터 가죽 드랍
		{
			return new CMonsterLeather("Monster Leather", 1);
		}
	}

	// 아이템을 드랍하지 않음
	return nullptr;
}
