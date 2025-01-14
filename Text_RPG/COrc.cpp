#include "pch.h"
#include "COrc.h"
#include "CHealthPotion.h"
#include "CAttackBoost.h"
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

	//30% 확률로 아이템 드랍
	if (ItemDropProbabiliity <= 30)
	{
		// 50% 확률로 체력 아이템 드랍
		if (ItemDropProbabiliity <= 15)
		{
			return new CHealthPotion("CHealthPotion", 10);
		}
		else // 50% 확률로 공격력 증가 아이템 드랍
		{
			return new CAttackBoost("CAttackBoost", 10);
		}
	}

	// 아이템을 드랍하지 않음
	return nullptr;
}
