#include "pch.h"
#include "CBossMonster.h"
#include "CHealthPotion.h"
#include "CAttackBoost.h"
#include "CMonsterLeather.h"
#include <random>

CBossMonster::CBossMonster(int level)
{
	name = "Dragon";
	
	std::random_device RandomDevice; // 시드값을 얻기 위한 random_device 생성
	std::mt19937 gen(RandomDevice()); // random_device를 통해 난수 생성 엔진을 초기화

	// 체력은 캐릭터 레벨에 비례해서 랜덤하게 생성(레벨*20~레벨*30)
	std::uniform_int_distribution<int> HealthDistribution(level * 20, level * 30);
	health = HealthDistribution(gen) * 1.5;

	// 공격력은 캐릭터 레벨에 비례해서 랜덤하게 생성(레벨*5~레벨*10)
	std::uniform_int_distribution<int> DamageDistribution(level * 5, level * 10);
	damage = DamageDistribution(gen) * 1.5;
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

ITEM_TYPE CBossMonster::DropItem()
{
	std::random_device RandomDevice; // 시드값을 얻기 위한 random_device 생성
	std::mt19937 gen(RandomDevice()); // random_device를 통해 난수 생성 엔진을 초기화

	std::uniform_int_distribution<int> ItemDropDistribution(0, 100);
	int ItemDropProbabiliity = ItemDropDistribution(gen);

	//30% 확률로 아이템 드랍
	if (ItemDropProbabiliity <= 30) 
	{
		if (ItemDropProbabiliity <= 10) // 1/3 확률로 체력 아이템 드랍
		{
			return ITEM_TYPE::HEALTH_POTION;
		}
		else if(ItemDropProbabiliity <=20) // 1/3 확률로 공격력 증가 아이템 드랍
		{
			return ITEM_TYPE::ATTACK_BOOST;
		}
		else // 1/3 확률로 몬스터 가죽 드랍
		{
			return ITEM_TYPE::MONSTER_LEATHER;
		}
	}

	// 아이템을 드랍하지 않음
	return ITEM_TYPE::NONE;
}
