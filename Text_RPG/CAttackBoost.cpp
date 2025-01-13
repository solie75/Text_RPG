#include "CAttackBoost.h"
#include "CPlayer.h"

void CAttackBoost::Use(int amount)
{
	CPlayer* Player = CPlayer::GetInst();
	Player->SetDamage(amount);
}