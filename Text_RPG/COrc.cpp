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
	// 체력은 캐릭터 레벨에 비례해서 랜덤하게 생성(레벨*20~레벨*30)
	std::uniform_int_distribution<int> HealthDistribution(level * 20, level * 30);
	health = HealthDistribution(RandomGenerator);
	// 공격력은 캐릭터 레벨에 비례해서 랜덤하게 생성(레벨*5~레벨*10)
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

ITEM_TYPE COrc::DropItem()
{
	std::default_random_engine RandomGenerator;
	std::uniform_int_distribution<int> ItemDropDistribution(0, 100);
	int ItemDropProbabiliity = ItemDropDistribution(RandomGenerator);

	//30% 확률로 아이템 드랍
	if (ItemDropProbabiliity <= 30)
	{
		if (ItemDropProbabiliity <= 10) // 1/3 확률로 체력 아이템 드랍
		{
			return ITEM_TYPE::HEALTH_POTION;
		}
		else if (ItemDropProbabiliity <= 20) // 1/3 확률로 공격력 증가 아이템 드랍
		{
			return ITEM_TYPE::ATTACK_BOOST;
		}
		else // 1/3 확률로 몬스터 가죽 드랍
		{
			return ITEM_TYPE::MONSTER_LEATHER;
		}
	}

	// 아이템을 드랍하지 않음
	return nullptr;
}
