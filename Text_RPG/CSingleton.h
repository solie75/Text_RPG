#pragma once

typedef void (*EXIT)(void);

template<typename T>
class CSingleton
{
public:
	static T* GetInst()
	{
		static T* instance = new T;
		return instance;
	};

protected:
	CSingleton() {};
	virtual ~CSingleton() {};
};