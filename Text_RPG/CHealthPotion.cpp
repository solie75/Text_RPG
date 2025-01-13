#include "CHealthPotion.h"
#include "CPlayer.h"

void CHealthPotion::Use(int amount)
{
	CPlayer* Player = CPlayer::GetInst();
	Player->SetHealth(amount);
}
