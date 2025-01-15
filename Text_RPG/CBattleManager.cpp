#include "pch.h"
#include "CBattleManager.h"
#include <random>

void CBattleManager::Battle(CPlayer& player, CMonster& monster, vector<std::pair<string, bool>>& _battleLog)
{
	std::random_device rd;
	std::default_random_engine RandomGenerator(rd());
	std::uniform_int_distribution<int> ItemUseDistribution(0, 100);
	std::uniform_int_distribution<int> MonsterAttackDistribution(0, 100);
	std::uniform_int_distribution<int> PlayerAttackDistribution(0, 100);

	// [플레이어의 턴]
	// 플레이어의 아이템 사용
	int ItemUseProbabiliity = ItemUseDistribution(RandomGenerator);
	if (ItemUseProbabiliity > 75)
	{
		player.UseItem(ITEM_TYPE::HEALTH_POTION); // 25% 확률로 회복 아이템 사용
		_battleLog.push_back(std::make_pair("U", true));
	}
	else if (ItemUseProbabiliity < 50)
	{
		player.UseItem(ITEM_TYPE::ATTACK_BOOST); // 25% 확률로 회복 아이템 사용
		_battleLog.push_back(std::make_pair("U", false));
	}

	// 플레이어의 공격
	int PlayerAttackProbability = PlayerAttackDistribution(RandomGenerator);
	if (PlayerAttackProbability > 50)
	{
		// 공격 성공
		monster.Hit(player.GetDamage());
		_battleLog.push_back(std::make_pair("P", true));
	}
	else
	{
		_battleLog.push_back(std::make_pair("P", false));
		// 공격 실패
	}

	// [몬스터의 턴]
	// 몬스터의 공격
	int MonsterAttackProbability = MonsterAttackDistribution(RandomGenerator);
	if (MonsterAttackProbability > 50)
	{
		// 공격 성공
		player.Hit(monster.GetDamage());
		_battleLog.push_back(std::make_pair("M", true));
	}
	else
	{
		// 공격 실패 
		_battleLog.push_back(std::make_pair("M", false));
	}

	if (player.GetHealth() <= 0 || monster.GetHealth() <= 0)
	{
		IsEndBattle = true;
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

bool CBattleManager::GetIsEndBattle() const
{
	return IsEndBattle;
}
