#pragma once

#define SINGLE(type) private: type(); ~type(); friend class CSingleton<type>;

enum class MANAGER_TYPE
{
	KEY,
	TIME,
	STAGE,
	RESOURCE,
	SCRIPT,
	SPAWN,
	BATTLE,
	SHOP,
	END,
};

enum class STAGE_TYPE
{
	START,
	DUNGEON_NORMAL,
	DUNGEON_BOSS,
	VILLAGE,
	SHOP,
	ENDING,
	END,
};

enum class ITEM_TYPE
{
	HEALTH_POTION,
	ATTACK_BOOST,
	MONSTER_LEATHER,
	NONE
};

enum class BATTLE_TURN_TYPE
{
	USE_ITEM,
	PLAYER_ATTACK,
	MONSTER_ATTACK
};
//���� BATTLE_TURN_TYPE�� �� �����Ͽ� ����
enum class BATTLE_RESULT_TYPE
{
	USE_HEALTH_POTION, // USE_ITEM�� ��쿡�� ���
	USE_ATTACK_BOOST, // USE_ITEM�� ��쿡�� ���
	ATTACK_FAIL, // PLAYER_ATTACK �� MONSTER_ATTACK�� ��쿡�� ���
	ATTACK_SUCCESS // PLAYER_ATTACK �� MONSTER_ATTACK�� ��쿡�� ���
};