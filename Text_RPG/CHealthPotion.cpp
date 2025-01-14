#include "pch.h"
#include "CHealthPotion.h"
#include "CPlayer.h"

int CHealthPotion::GetAmount()
{
	return Amount;
}

void CHealthPotion::Use()
{
	ReduceCnt();
	CPlayer::GetInst()->Heal(Amount);
}
