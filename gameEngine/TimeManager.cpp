#include "pch.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	//ms 
	//::GetTickCount64();//정밀도 떨어진다. 

	//QueryPerformanceFrequency 함수를 호출하여 CPU의 고성능 타이머 주파수를 얻고, 
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(& _frequency));

	//QueryPerformanceCounter 함수를 호출하여 초기 시간 카운트(클럭)를 얻습니다. 이 정보들은 나중에 시간 계산에 사용됩니다.
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount)); //CPU 클럭 
}

void TimeManager::Update()
{

	
	uint64 currentCount;

	/*
	좋은 질문입니다. QueryPerformanceFrequency 함수가 반환하는 주파수는 고성능 타이머의 '틱' 빈도를 나타냅니다.

    '틱'은 타이머가 측정하는 가장 작은 시간 단위입니다. 예를 들어, 타이머의 주파수가 1초에 1000틱이라면,
	이 타이머는 1초 동안 1000번 '틱'하며, 이 타이머의 최소 측정 단위는 1/1000초가 됩니다.

	QueryPerformanceFrequency 함수는 이 '틱'의 빈도, 즉 1초 동안에 몇 번 '틱'하는지를 반환합니다.
	이 값은 시스템 하드웨어에 따라 달라지며, 일반적으로 매우 큰 값이 됩니다.
	이 주파수를 알면, QueryPerformanceCounter 함수가 반환하는 '틱'의 수를 실제 시간 단위로 변환할 수 있습니다.
	
	예를 들어, QueryPerformanceFrequency가 1000 000을 반환하면, 이는 타이머가 1초에 1000000번 '틱'한다는 의미입니다.
	그리고 QueryPerformanceCounter가 500 000을 반환하면, 이는 마지막으로 QueryPerformanceCounter를 호출한 이후에 0.5초가 경과했다는 것을 의미합니다. (500000/1000000 = 0.5)
	
	따라서 QueryPerformanceFrequency의 반환 값은 고성능 타이머의 해상도를 나타내며, 이를 통해 '틱'의 수를 실제 시간 값으로 변환할 수 있습니다.
	
	*/

	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));
	//====================================================================================================

	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency); //그냥 비례식 이용한거임; 
	//델타t초 : 1초 = 1프레임당틱 : 1초당 틱 
	_prevCount = currentCount;//업데이트 해주기 

	_frameCount++;//프레임당개수 
	_frameTime += _deltaTime; //프레임당걸린시간 누적

	if (_frameTime >= 1.f)//1초가 증가됐을때
	{
		_fps = static_cast<uint32>(_frameCount / _frameTime); //프레임개수/누적프레임시간 
		_frameTime = 0.f; //다시밀기
		_frameCount = 0; //다시밀기 
	}
	//====================================================================================================

	/*
	QueryPerformanceCounter 함수를 다시 호출하여 현재의 시간 카운트를 얻습니다.
	그런 다음 초기 시간 카운트와의 차이를 계산하여 경과 시간을 계산하고, 이를 주파수로 나눠서 '초' 단위로 변환합니다.
	이 결과는 _deltaTime에 저장되며, 이 값은 프레임 사이의 시간 간격을 나타냅니다.
	*/
}
