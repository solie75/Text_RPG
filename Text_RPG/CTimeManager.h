#pragma once
class CTimeManager :
    public CSingleton<CTimeManager>
{
	SINGLE(CTimeManager)

private:
	LARGE_INTEGER PrevCount;
	LARGE_INTEGER CurCount;
	LARGE_INTEGER Frequency;

	UINT ICallCount;
	float FDeltaTime;
	float FTime;

public:
	void TimeManagerInit();
	void TimeManagerTick();

	float GetDeltaTime();
};

