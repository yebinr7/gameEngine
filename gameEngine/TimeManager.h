#pragma once
//싱글톤-> static을 이용해서 데이터영역에 객체만들고 static메서드로(객체없이 ::로만 접근가능함) 
//pch.h에 Defines.h 있기 때문에 DECLARE_SINGLE 바로 사용 가능 
class TimeManager
{
	DECLARE_SINGLE(TimeManager) //Define 사용가능한 이유는 원래 헤더에서 인클루드해야하는데 pch라서 그냥 되나봄? 
#pragma region 원래는 이렇게..싱글톤
	//public:
//	static TimeManager* GetInstance() //스태틱 메서드 => 객체랑 상관없다.this포인터 없다. 
//	{//메서드를 통해서 외부에서 인터페이스로 접근 가능한것! 
//		/* 1번 방법
//		if (s_instance == nullptr)
//			s_instance = new TimeManager();//데이터영역의 포인터 변수가 힙에 객체 만들어둠 
//
//		return s_instance;
//		*/
//		//2번째 방법
//		static TimeManager s_instance;//데이터 영역에 객체를 만들어 놓고
//		return &s_instance;//그 객체의 주소만 뱉어 주는 방식 ,단점은 소멸 언제 시킬지 모른다. 
//	}
//private:
//	
//	//static TimeManager* s_instance; //첫번째 방식
//	TimeManager(){} //2번째 방식: 타임매니저 다른곳에서 못만들게 private으로 감춰둔다.
#pragma endregion

public:
	void Init();
	void Update();

	//
	uint32 GetFps() { return _fps; }
	// 이전프레임 ~현재시간까지 경과된 시간 델타 타임 
	float GetDeltaTime() { return _deltaTime; }

private:
	uint64 _frequency = 0;//컴퓨터의 주파수 1초에 몇번 
	uint64 _prevCount = 0;//이전 클럭개수
	float _deltaTime = 0.f;//현재프레임시간-이전프레임시간 


private:
	uint32 _frameCount = 0;
	float  _frameTime = 0.f;
	uint32 _fps = 0;


};

