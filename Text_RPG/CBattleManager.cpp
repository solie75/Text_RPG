#include "pch.h"
#include "CBattleManager.h"
#include <random>

void CBattleManager::Battle(CPlayer& player, CMonster& monster, vector<std::pair<string, bool>>& _battleLog)
{
	// 랜럼 관련 변수들
	std::random_device RandomDevice; // // 시드값을 얻기 위한 random_device 생성
	std::mt19937 gen(RandomDevice()); // random_device를 통해 난수 생성 엔진을 초기화
	std::uniform_int_distribution<int> Distribution(0, 100); // 0~100까지 난수열을 생성하귀 위해 균등 분포 정의

	// [플레이어의 턴]
	// 플레이어의 아이템 사용
	if (player.GetHealth() > 0 && monster.GetHealth() > 0)
	{
		int ItemUseProbabiliity = Distribution(gen);
		if (_battleLog.empty() || _battleLog.back().first == "M")
		{
			if (ItemUseProbabiliity > 75)
			{
				if (player.GetItemCnt(ITEM_TYPE::HEALTH_POTION) > 0)
				{
					player.UseItem(ITEM_TYPE::HEALTH_POTION); // 25% 확률로 회복 아이템 사용
					_battleLog.push_back(std::make_pair("U", true));
					return;
				}
			}
			else if (ItemUseProbabiliity < 25)
			{
				if (player.GetItemCnt(ITEM_TYPE::ATTACK_BOOST) > 0)
				{
					player.UseItem(ITEM_TYPE::ATTACK_BOOST); // 25% 확률로 회복 아이템 사용
					_battleLog.push_back(std::make_pair("U", false));
					return;
				};
			}
		}

		// 플레이어의 공격
		int PlayerAttackProbability = Distribution(gen);
		if (_battleLog.empty() || _battleLog.back().first == "M")
		{
			if (PlayerAttackProbability > 50)
			{
				// 공격 성공
				monster.Hit(player.GetDamage());
				_battleLog.push_back(std::make_pair("P", true));
				return;
			}
			else
			{
				_battleLog.push_back(std::make_pair("P", false));
				// 공격 실패
				return;
			}
		}

		// [몬스터의 턴]
		// 몬스터의 공격
		int MonsterAttackProbability = Distribution(gen);
		if (_battleLog.back().first != "M")
		{
			if (MonsterAttackProbability > 50)
			{
				// 공격 성공
				player.Hit(monster.GetDamage());
				_battleLog.push_back(std::make_pair("M", true));
				return;
			}
			else
			{
				// 공격 실패 
				_battleLog.push_back(std::make_pair("M", false));
				return;
			}
		}
	}
	else
	{
		IsEndBattle = true;
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
}

bool CBattleManager::GetIsPlayerWinner() const
{
	return IsPlayerWinner;
}

bool CBattleManager::GetIsEndBattle() const
{
	return IsEndBattle;
}
