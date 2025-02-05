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
//위의 BATTLE_TURN_TYPE과 잘 연결하여 쓰기
enum class BATTLE_RESULT_TYPE
{
	USE_HEALTH_POTION, // USE_ITEM일 경우에만 사용
	USE_ATTACK_BOOST, // USE_ITEM일 경우에만 사용
	ATTACK_FAIL, // PLAYER_ATTACK 과 MONSTER_ATTACK의 경우에만 사용
	ATTACK_SUCCESS // PLAYER_ATTACK 과 MONSTER_ATTACK의 경우에만 사용
};