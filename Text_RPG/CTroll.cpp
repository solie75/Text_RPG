#include "pch.h"
#include "CTroll.h"
#include "CHealthPotion.h"
#include "CAttackBoost.h"
#include <random>

CTroll::CTroll(int level)
{
	name = "Troll";
	std::default_random_engine RandomGenerator;
	// 체력은 캐릭터 레벨에 비례해서 랜덤하게 생성(레벨*20~레벨*30)
	std::uniform_int_distribution<int> HealthDistribution(level * 20, level * 30);
	health = HealthDistribution(RandomGenerator);
	// 공격력은 캐릭터 레벨에 비례해서 랜덤하게 생성(레벨*5~레벨*10)
	std::uniform_int_distribution<int> DamageDistribution(level * 5, level * 10);
	damage = DamageDistribution(RandomGenerator);
}

string CTroll::GetName() const
{
	return name;
}

int CTroll::GetHealth() const
{
	return health;
}

int CTroll::GetDamage() const
{
	return damage;
}

void CTroll::Hit(int damage)
{
	health -= damage;
}

CItem* CTroll::DropItem()
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
