﻿#include "pch.h"
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

void CPlayer::SetDamage(int amount)
{
	Damage += amount;
}

void CPlayer::SetHealth(int amount)
{
	Health += amount;

	if (Health >= MaxHealth)
		Health = MaxHealth;
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

void CPlayer::Hit(int _damage)
{
	Health = Health - _damage > 0 ? Health - _damage : 0;
}

void CPlayer::UseItem(string _itemName)
{
	if (Inventory.find(_itemName) != Inventory.end())
	{
		Inventory[_itemName] = Inventory[_itemName] > 0 ? Inventory[_itemName]-- : 0;
	}
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
