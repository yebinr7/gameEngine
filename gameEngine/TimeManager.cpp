#include "pch.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	//ms 
	//::GetTickCount64();//���е� ��������. 

	//QueryPerformanceFrequency �Լ��� ȣ���Ͽ� CPU�� ���� Ÿ�̸� ���ļ��� ���, 
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(& _frequency));

	//QueryPerformanceCounter �Լ��� ȣ���Ͽ� �ʱ� �ð� ī��Ʈ(Ŭ��)�� ����ϴ�. �� �������� ���߿� �ð� ��꿡 ���˴ϴ�.
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount)); //CPU Ŭ�� 
}

void TimeManager::Update()
{

	
	uint64 currentCount;

	/*
	���� �����Դϴ�. QueryPerformanceFrequency �Լ��� ��ȯ�ϴ� ���ļ��� ���� Ÿ�̸��� 'ƽ' �󵵸� ��Ÿ���ϴ�.

    'ƽ'�� Ÿ�̸Ӱ� �����ϴ� ���� ���� �ð� �����Դϴ�. ���� ���, Ÿ�̸��� ���ļ��� 1�ʿ� 1000ƽ�̶��,
	�� Ÿ�̸Ӵ� 1�� ���� 1000�� 'ƽ'�ϸ�, �� Ÿ�̸��� �ּ� ���� ������ 1/1000�ʰ� �˴ϴ�.

	QueryPerformanceFrequency �Լ��� �� 'ƽ'�� ��, �� 1�� ���ȿ� �� �� 'ƽ'�ϴ����� ��ȯ�մϴ�.
	�� ���� �ý��� �ϵ��� ���� �޶�����, �Ϲ������� �ſ� ū ���� �˴ϴ�.
	�� ���ļ��� �˸�, QueryPerformanceCounter �Լ��� ��ȯ�ϴ� 'ƽ'�� ���� ���� �ð� ������ ��ȯ�� �� �ֽ��ϴ�.
	
	���� ���, QueryPerformanceFrequency�� 1000 000�� ��ȯ�ϸ�, �̴� Ÿ�̸Ӱ� 1�ʿ� 1000000�� 'ƽ'�Ѵٴ� �ǹ��Դϴ�.
	�׸��� QueryPerformanceCounter�� 500 000�� ��ȯ�ϸ�, �̴� ���������� QueryPerformanceCounter�� ȣ���� ���Ŀ� 0.5�ʰ� ����ߴٴ� ���� �ǹ��մϴ�. (500000/1000000 = 0.5)
	
	���� QueryPerformanceFrequency�� ��ȯ ���� ���� Ÿ�̸��� �ػ󵵸� ��Ÿ����, �̸� ���� 'ƽ'�� ���� ���� �ð� ������ ��ȯ�� �� �ֽ��ϴ�.
	
	*/

	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));
	//====================================================================================================

	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency); //�׳� ��ʽ� �̿��Ѱ���; 
	//��Ÿt�� : 1�� = 1�����Ӵ�ƽ : 1�ʴ� ƽ 
	_prevCount = currentCount;//������Ʈ ���ֱ� 

	_frameCount++;//�����Ӵ簳�� 
	_frameTime += _deltaTime; //�����Ӵ�ɸ��ð� ����

	if (_frameTime >= 1.f)//1�ʰ� ����������
	{
		_fps = static_cast<uint32>(_frameCount / _frameTime); //�����Ӱ���/���������ӽð� 
		_frameTime = 0.f; //�ٽùб�
		_frameCount = 0; //�ٽùб� 
	}
	//====================================================================================================

	/*
	QueryPerformanceCounter �Լ��� �ٽ� ȣ���Ͽ� ������ �ð� ī��Ʈ�� ����ϴ�.
	�׷� ���� �ʱ� �ð� ī��Ʈ���� ���̸� ����Ͽ� ��� �ð��� ����ϰ�, �̸� ���ļ��� ������ '��' ������ ��ȯ�մϴ�.
	�� ����� _deltaTime�� ����Ǹ�, �� ���� ������ ������ �ð� ������ ��Ÿ���ϴ�.
	*/
}
