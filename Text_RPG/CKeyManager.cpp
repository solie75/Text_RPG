#include "pch.h"
#include "CKeyManager.h"

int arrVK[(unsigned int)KEY_TYPE::END]
=
{
	VK_UP,
	VK_DOWN,
	VK_LEFT,
	VK_RIGHT,
	
	VK_SPACE,
	VK_ESCAPE,
	
	'Z',
	'X',
	'C',
	'V',
	
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
};

CKeyManager::CKeyManager() {}

CKeyManager::~CKeyManager() {}

void CKeyManager::KeyManagerInit()
{
	for (int i = 0; i < (unsigned int)KEY_TYPE::END; ++i)
	{
		VecKey.push_back(tKeyInfo{ (KEY_TYPE)i, KEY_STATE::NONE });
	}
}

void CKeyManager::KeyManagerTick()
{
	for (size_t i = 0; i < VecKey.size(); ++i)
	{
		if (GetAsyncKeyState(arrVK[(UINT)VecKey[i].key]) & 0x8000) // Pressed
		{
			if (false == VecKey[i].bPrev)
			{
				if (VecKey[i].key == KEY_TYPE::SPACE)
				{
					int c = 0;
				}
				VecKey[i].state = KEY_STATE::TAP;
				VecKey[i].bPrev = true;
			}
			else
			{
				VecKey[i].state = KEY_STATE::PRESSED;
			}
		}
		else
		{
			if (false == VecKey[i].bPrev)
			{
				VecKey[i].state = KEY_STATE::NONE;
			}
			else
			{
				VecKey[i].state = KEY_STATE::RELEASE;
				VecKey[i].bPrev = false;
			}
		}
	}

	if (GetFocus()) // 해당 어플리케이션이 포커스 되어있는지 확인
	{
		
	}
	else // 어플리케이션을 벗어난다면 모든 key 를 none 형태로
	{
		/*for (size_t i = 0; i < VecKey.size(); ++i)
		{
			if (KEY_STATE::TAP == VecKey[i].state || KEY_STATE::PRESSED == VecKey[i].state)
			{
				VecKey[i].state = KEY_STATE::RELEASE;
			}
			else if (KEY_STATE::RELEASE == VecKey[i].state)
			{
				VecKey[i].state = KEY_STATE::NONE;
			}
		}*/
	}
}
