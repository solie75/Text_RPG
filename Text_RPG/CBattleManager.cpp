#include "pch.h"
#include "CBattleManager.h"
#include <random>

void CBattleManager::Battle(CPlayer& player, CMonster& monster)
{
	std::default_random_engine RandomGenerator;
	std::uniform_int_distribution<int> ItemUseDistribution(0, 100);
	std::uniform_int_distribution<int> MonsterAttackDistribution(0, 100);
	std::uniform_int_distribution<int> PlayerAttackDistribution(0, 100);

	// ���� ���� �ؽ�Ʈ
	while (monster.GetHealth() > 0 && player.GetHealth() > 0) // �÷��̾� ü���̳� ������ ü���� 0�̵� ������
	{
		// [�÷��̾��� ��]
		// �÷��̾��� ������ ���
		int ItemUseProbabiliity = ItemUseDistribution(RandomGenerator);
		if (ItemUseProbabiliity > 75) 
		{
			player.UseItem("health"); // 25% Ȯ���� ȸ�� ������ ���
		}
		else if (ItemUseProbabiliity > 50)
		{
			player.UseItem("attackboost"); // 25% Ȯ���� ȸ�� ������ ���
		}

		// �÷��̾��� ����
		int PlayerAttackProbability = PlayerAttackDistribution(RandomGenerator);
		if (PlayerAttackProbability > 50)
		{
			// ���� ����
			monster.Hit(player.GetDamage()); // ���� ������ ����
			// ���� ���� �ؽ�Ʈ
		}
		else
		{
			// ���� ����
			// ���� ���� �ؽ�Ʈ
		}

		// [������ ��]
		// ������ ����
		int MonsterAttackProbability = MonsterAttackDistribution(RandomGenerator);
		if (MonsterAttackProbability > 50)
		{
			// ���� ����
			player.Hit(monster.GetDamage()); // �÷��̾� ������ ����
			// ���� ���� �ؽ�Ʈ
		}
		else
		{
			// ���� ����
			// ���� ���� �ؽ�Ʈ
		}
	}

	// ���� ����
	if (monster.GetHealth() <= 0) // �÷��̾ �̰�ٸ�
	{
		IsPlayerWinner = true;
	}
	else if (player.GetHealth() <= 0) // ���Ͱ� �̰�ٸ�
	{
		IsPlayerWinner = false;
	}
}

bool CBattleManager::GetIsPlayerWinner() const
{
	return IsPlayerWinner;
}
