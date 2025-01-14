#include "pch.h"
#include "CBattleManager.h"
#include <random>

void CBattleManager::Battle(CPlayer& player, CMonster& monster)
{
	// 랜럼 관련 변수들
	std::default_random_engine RandomGenerator;
	std::uniform_int_distribution<int> ItemUseDistribution(0, 100); // 아이템 사용 난수 생성
	std::uniform_int_distribution<int> MonsterAttackDistribution(0, 100); // 몬스터 공격 난수 생성
	std::uniform_int_distribution<int> PlayerAttackDistribution(0, 100); // 플레이어 공격 난수 생성

	// 몬스터 등장 텍스트
	while (monster.GetHealth() > 0 && player.GetHealth() > 0) // 플레이어 체력이나 몬스터의 체력이 0이될 때가지
	{
		// [플레이어의 턴]
		// 플레이어의 아이템 사용
		int ItemUseProbabiliity = ItemUseDistribution(RandomGenerator);
		if (ItemUseProbabiliity > 75) 
		{
			player.UseItem(ITEM_TYPE::HEALTH_POTION); // 25% 확률로 회복 아이템 사용
		}
		else if (ItemUseProbabiliity > 50)
		{
			player.UseItem(ITEM_TYPE::ATTACK_BOOST); // 25% 확률로 공격력 증가 아이템 사용
		}

		// 플레이어의 공격
		int PlayerAttackProbability = PlayerAttackDistribution(RandomGenerator);
		if (PlayerAttackProbability > 50) // 50% 확률로 공격 성공
		{
			// 공격 성공
			monster.Hit(player.GetDamage()); // 몬스터 데미지 입음
			// 공격 성공 텍스트

			// 지금 공격으로 몬스터가 죽었다면
			if (monster.GetHealth() <= 0)
			{
				break; // 몬스터 턴 스킵
			}
		}
		else
		{
			// 공격 실패
			// 공격 실패 텍스트
		}

		// [몬스터의 턴]
		// 몬스터의 공격
		int MonsterAttackProbability = MonsterAttackDistribution(RandomGenerator);
		if (MonsterAttackProbability > 50) // 50% 확률로 공격 성공
		{
			// 공격 성공
			player.Hit(monster.GetDamage()); // 플레이어 데미지 입음
			// 공격 성공 텍스트
		}
		else
		{
			// 공격 실패
			// 공격 실패 텍스트
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
