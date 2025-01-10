#pragma once

#define SINGLE(type) private: type(); ~type(); friend class CSingleton<type>;

enum MANAGER_TYPE
{

};

enum STAGE_TYPE
{

};