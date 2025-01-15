#include "pch.h"
#include "CGoblin.h"
#include "CHealthPotion.h"
#include "CAttackBoost.h"
#include "CMonsterLeather.h"
#include <random>

CGoblin::CGoblin(int level)
{
	name = "Goblin";

	std::random_device RandomDevice; // �õ尪�� ��� ���� random_device ����
	std::mt19937 gen(RandomDevice()); // random_device�� ���� ���� ���� ������ �ʱ�ȭ
	
	// ü���� ĳ���� ������ ����ؼ� �����ϰ� ����(����*20~����*30)
	std::uniform_int_distribution<int> HealthDistribution(level*20, level*30);
	health = HealthDistribution(gen);
	
	// ���ݷ��� ĳ���� ������ ����ؼ� �����ϰ� ����(����*5~����*10)
	std::uniform_int_distribution<int> DamageDistribution(level * 5, level * 10);
	damage = DamageDistribution(gen);
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

ITEM_TYPE CGoblin::DropItem()
{
	std::random_device RandomDevice; // �õ尪�� ��� ���� random_device ����
	std::mt19937 gen(RandomDevice()); // random_device�� ���� ���� ���� ������ �ʱ�ȭ

	std::uniform_int_distribution<int> ItemDropDistribution(0, 100);
	int ItemDropProbabiliity = ItemDropDistribution(gen);

	//30% Ȯ���� ������ ���
	if (ItemDropProbabiliity <= 30)
	{
		if (ItemDropProbabiliity <= 10) // 1/3 Ȯ���� ü�� ������ ���
		{
			return ITEM_TYPE::HEALTH_POTION;
		}
		else if (ItemDropProbabiliity <= 20) // 1/3 Ȯ���� ���ݷ� ���� ������ ���
		{
			return ITEM_TYPE::ATTACK_BOOST;
		}
		else // 1/3 Ȯ���� ���� ���� ���
		{
			return ITEM_TYPE::MONSTER_LEATHER;
		}
	}

	// �������� ������� ����
	return ITEM_TYPE::NONE;
}
