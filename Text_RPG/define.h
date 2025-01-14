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
	ATTACK_BOOST
};