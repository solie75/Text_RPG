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
	// ���� �ý����� ���ػ� Ÿ�̸��� ���ļ�(1�ʴ� ������)�� ��ȯ
	QueryPerformanceFrequency(&Frequency);

	// �Լ��� ȣ��� ������ Ÿ�̸�(��ǻ�Ͱ� ����ǰ� �ð��� ���� ������ �����Ѵ�.) �� ��ȯ
	QueryPerformanceCounter(&CurCount);
	QueryPerformanceCounter(&PrevCount);
}

void CTimeManager::TimeManagerTick()
{
	QueryPerformanceCounter(&CurCount);

	// Tick ���� �ð�
	FDeltaTime = (float)(CurCount.QuadPart - PrevCount.QuadPart) / (float)(Frequency.QuadPart);

	// ���� �ð�
	FTime += FDeltaTime;

	//  �Լ� ȣ�� Ƚ��
	++ICallCount;

	// ���� ī��Ʈ ���� ���� ī��Ʈ�� ����
	PrevCount = CurCount;

	// Set Global CB Data
	GlobalData.DeltaTime = FDeltaTime;
	GlobalData.AccumulateTime += FDeltaTime;
}

float CTimeManager::GetDeltaTime()
{
	return FDeltaTime;
}
