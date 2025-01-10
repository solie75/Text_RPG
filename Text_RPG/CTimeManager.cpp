#include "pch.h"
#include "CTimeManager.h"

CTimeManager::CTimeManager()
	: PrevCount{}
	, CurCount{}
	, Frequency{}
	, ICallCount(0)
	, FDeltaTime(0.f)
	, FTime(0.f)
{

}

CTimeManager::~CTimeManager()
{

}

void CTimeManager::TimeManagerInit()
{
	// 현재 시스템의 고해상도 타이머의 주파수(1초당 진동수)를 반환
	QueryPerformanceFrequency(&Frequency);

	// 함수가 호출된 시점의 타이머(컴퓨터가 실행되고 시간의 지남 정도를 축적한다.) 값 반환
	QueryPerformanceCounter(&CurCount);
	QueryPerformanceCounter(&PrevCount);
}

void CTimeManager::TimeManagerTick()
{
	QueryPerformanceCounter(&CurCount);

	// Tick 사이 시간
	FDeltaTime = (float)(CurCount.QuadPart - PrevCount.QuadPart) / (float)(Frequency.QuadPart);

	// 누적 시간
	FTime += FDeltaTime;

	//  함수 호출 횟수
	++ICallCount;

	// 이전 카운트 값을 현재 카운트로 갱신
	PrevCount = CurCount;

	// Set Global CB Data
	GlobalData.DeltaTime = FDeltaTime;
	GlobalData.AccumulateTime += FDeltaTime;
}

float CTimeManager::GetDeltaTime()
{
	return FDeltaTime;
}
