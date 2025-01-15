#include "pch.h"
#include "CBattleManager.h"
#include <random>

void CBattleManager::Battle(CPlayer& player, CMonster& monster)
{
	// ���� ���� ������
	std::random_device RandomDevice; // �õ尪�� ��� ���� random_device ����
	std::mt19937 gen(RandomDevice()); // random_device�� ���� ���� ���� ������ �ʱ�ȭ
	std::uniform_int_distribution<int> Distribution(0, 100); // 0~100���� �������� �����ϱ� ���� �յ� ���� ����

	// ���� ���� �ؽ�Ʈ
	while (monster.GetHealth() > 0 && player.GetHealth() > 0) // �÷��̾� ü���̳� ������ ü���� 0�̵� ������
	{
		// [�÷��̾��� ��]
		// �÷��̾��� ������ ���
		int ItemUseProbabiliity = Distribution(gen);
		if (ItemUseProbabiliity > 75) 
		{
			player.UseItem(ITEM_TYPE::HEALTH_POTION); // 25% Ȯ���� ȸ�� ������ ���
		}
		else if (ItemUseProbabiliity > 50)
		{
			player.UseItem(ITEM_TYPE::ATTACK_BOOST); // 25% Ȯ���� ���ݷ� ���� ������ ���
		}

		// �÷��̾��� ����
		int PlayerAttackProbability = Distribution(gen);
		if (PlayerAttackProbability > 50) // 50% Ȯ���� ���� ����
		{
			// ���� ����
			monster.Hit(player.GetDamage()); // ���� ������ ����
			// ���� ���� �ؽ�Ʈ

			// ���� �������� ���Ͱ� �׾��ٸ�
			if (monster.GetHealth() <= 0)
			{
				break; // ���� �� ��ŵ
			}
		}
		else
		{
			// ���� ����
			// ���� ���� �ؽ�Ʈ
		}

		// [������ ��]
		// ������ ����
		int MonsterAttackProbability = Distribution(gen);
		if (MonsterAttackProbability > 50) // 50% Ȯ���� ���� ����
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
