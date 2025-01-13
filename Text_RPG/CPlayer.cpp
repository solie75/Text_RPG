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
	if (Level == MaxLevel) // 나중에 포션 등으로 레벨 올렸을 경우 대비.
		return;


	Level++;
	
	if (Level == MaxLevel) // 만렙 : 경험치0, 필요경험치 0;
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
	if (Level != MaxLevel) // 만렙 : 경험치 올릴필요 없음
	{
		Experience += _up;

		//레벨업
		if (Experience >= MaxExperience)
		{
			IncreaseLevel();
		}
	}
}
