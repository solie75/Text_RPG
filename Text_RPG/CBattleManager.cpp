#include "pch.h"
#include "CBattleManager.h"
#include <random>

void CBattleManager::Battle(CPlayer& player, CMonster& monster)
{
	std::default_random_engine RandomGenerator;
	std::uniform_int_distribution<int> ItemUseDistribution(0, 100);
	std::uniform_int_distribution<int> MonsterAttackDistribution(0, 100);
	std::uniform_int_distribution<int> PlayerAttackDistribution(0, 100);

	std::cout << monster.GetName() << " 몬스터가 등장했다!!" << std::endl;
	while (monster.GetHealth() > 0 && player.GetHealth() > 0) // 플레이어 체력이나 몬스터의 체력이 0이될 때가지
	{
		// [플레이어의 턴]
		// 플레이어의 아이템 사용
		int ItemUseProbabiliity = ItemUseDistribution(RandomGenerator);
		if (ItemUseProbabiliity > 75) 
		{
			player.UseItem("health"); // 25% 확률로 회복 아이템 사용
		}
		else if (ItemUseProbabiliity < 50)
		{
			player.UseItem("attackboost"); // 25% 확률로 회복 아이템 사용
		}

		// 플레이어의 공격
		int PlayerAttackProbability = PlayerAttackDistribution(RandomGenerator);
		if (PlayerAttackProbability > 50)
		{
			// 공격 성공
			monster.Hit(player.GetDamage());
		}
		else
		{
			// 공격 실패
		}

		// [몬스터의 턴]
		// 몬스터의 공격
		int MonsterAttackProbability = MonsterAttackDistribution(RandomGenerator);
		if (MonsterAttackProbability > 50)
		{
			// 공격 성공
			player.TakeDamage(monster.GetDamage());
		}
		else
		{
			// 공격 실패 
		}
	}

	// 승패 결정
	if (monster.GetHealth() <= 0) // 플레이어가 이겼다면
	{
		IsPlayerWinner = true;
	}
	else if (player.GetHealth() <= 0) // 몬스터가 이겼다면
	{
		IsPlayerWinner = false;
	}
}

bool CBattleManager::GetIsPlayerWinner() const
{
	return IsPlayerWinner;
}
