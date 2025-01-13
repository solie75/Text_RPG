#include "pch.h"
#include "CPlayer.h"
#include <iostream>

CPlayer::CPlayer()
{
	Level = 1;
	MaxHealth = 200;
	Health = MaxHealth;
	Damage = 30;
	Experience = 0;
	MaxExperience = 100;
	Gold = 0;
}

CPlayer::~CPlayer()
{

}

void CPlayer::SetName(string _str)
{
	Name = _str;
}

void CPlayer::IncreaseLevel()
{
	if (Level == MaxLevel) // ���߿� ���� ������ ���� �÷��� ��� ���.
		return;


	Level++;
	
	if (Level == MaxLevel) // ���� : ����ġ0, �ʿ����ġ 0;
	{
		Experience = 0;
		MaxExperience = 0;
	}
	else
	{
		Experience %= MaxExperience;
		MaxExperience *= 1.1;
	}

	MaxHealth += 20;
	Damage += 5;
}

void CPlayer::TakeDamage(int)
{
}

void CPlayer::DisplayStatus()
{
}

void CPlayer::UseItem(int)
{
}

void CPlayer::ExpUp(int _up)
{
	if (Level != MaxLevel) // ���� : ����ġ �ø��ʿ� ����
	{
		Experience += _up;

		//������
		if (Experience >= MaxExperience)
		{
			IncreaseLevel();
		}
	}
}
