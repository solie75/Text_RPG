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
	Gold = 0;
}

void CPlayer::SetName(string _str)
{
	Name = _str;
}

void CPlayer::LevelUp()
{
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

void CPlayer::VisitShop()
{
}
