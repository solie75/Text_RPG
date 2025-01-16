#include "pch.h"
#include "CBattleManager.h"

void CBattleManager::Battle(CPlayer& player, CMonster& monster, vector<std::pair<BATTLE_TURN_TYPE, BATTLE_RESULT_TYPE>>& _battleLog)
{
	// 랜럼 관련 변수들
	std::random_device RandomDevice; // // 시드값을 얻기 위한 random_device 생성
	std::mt19937 gen(RandomDevice()); // random_device를 통해 난수 생성 엔진을 초기화
	std::uniform_int_distribution<int> Distribution(0, 100); // 0~100까지 난수열을 생성하귀 위해 균등 분포 정의

	if (player.GetHealth() > 0 && monster.GetHealth() > 0) // 전투 진행 상황
	{
		// [플레이어의 턴]
		// 플레이어의 아이템 사용
		int ItemUseProbabiliity = Distribution(gen);
		if (_battleLog.empty() || _battleLog.back().first == BATTLE_TURN_TYPE::MONSTER_ATTACK)
		{
			if (ItemUseProbabiliity > 75)
			{
				if (player.GetItemCnt(ITEM_TYPE::HEALTH_POTION) > 0)
				{
					player.UseItem(ITEM_TYPE::HEALTH_POTION); // 25% 확률로 회복 아이템 사용
					_battleLog.push_back(std::make_pair(BATTLE_TURN_TYPE::USE_ITEM, BATTLE_RESULT_TYPE::USE_HEALTH_POTION));
					return;
				}
			}
			else if (ItemUseProbabiliity < 25)
			{
				if (player.GetItemCnt(ITEM_TYPE::ATTACK_BOOST) > 0)
				{
					player.UseItem(ITEM_TYPE::ATTACK_BOOST); // 25% 확률로 회복 아이템 사용
					_battleLog.push_back(std::make_pair(BATTLE_TURN_TYPE::USE_ITEM, BATTLE_RESULT_TYPE::USE_ATTACK_BOOST));
					return;
				};
			}
		}

		// 플레이어의 공격
		int PlayerAttackProbability = Distribution(gen);
		if (_battleLog.empty() || _battleLog.back().first == BATTLE_TURN_TYPE::MONSTER_ATTACK)
		{
			if (PlayerAttackProbability > 50)
			{
				// 공격 성공
				monster.Hit(player.GetDamage());
				_battleLog.push_back(std::make_pair(BATTLE_TURN_TYPE::PLAYER_ATTACK, BATTLE_RESULT_TYPE::ATTACK_SUCCESS));
				return;
			}
			else
			{
				_battleLog.push_back(std::make_pair(BATTLE_TURN_TYPE::PLAYER_ATTACK, BATTLE_RESULT_TYPE::ATTACK_FAIL));
				// 공격 실패
				return;
			}
		}

		// [몬스터의 턴]
		// 몬스터의 공격
		int MonsterAttackProbability = Distribution(gen);
		if (_battleLog.back().first != BATTLE_TURN_TYPE::MONSTER_ATTACK)
		{
			if (MonsterAttackProbability > 50)
			{
				// 공격 성공
				player.Hit(monster.GetDamage());
				_battleLog.push_back(std::make_pair(BATTLE_TURN_TYPE::MONSTER_ATTACK, BATTLE_RESULT_TYPE::ATTACK_SUCCESS));
				return;
			}
			else
			{
				// 공격 실패 
				_battleLog.push_back(std::make_pair(BATTLE_TURN_TYPE::MONSTER_ATTACK, BATTLE_RESULT_TYPE::ATTACK_FAIL));
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
