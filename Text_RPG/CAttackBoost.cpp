#include "pch.h"
#include "CAttackBoost.h"
#include "CPlayer.h"

int CAttackBoost::GetAmount()
{
	return Amount;
}

void CAttackBoost::Use()
{
	ReduceCnt();
	CPlayer::GetInst()->IncreaseDamage(Amount);
}
