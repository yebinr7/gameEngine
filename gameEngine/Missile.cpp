#include "pch.h"
#include "Missile.h"
#include "TimeManager.h"
#include "ObjectManager.h"
Missile::Missile()
	:Object(ObjectType::Projectile)
{
}

Missile::~Missile()
{
}

void Missile::Init()
{
	//TODO: Data
	//데이터 시트 구조체 초기화 
	_state.hp = 1;
	_state.maxHp = 1;
	_state.speed = 600;
}

void Missile::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	
	//미사일 위치 업데이트
	_pos.y -= deltaTime * _state.speed;

	//미사일 삭제 처리 
	if (_pos.y < -200)
	{
		//소멸 처리 ? 업데이트에서 나 자신을 삭제한다? 
		GET_SINGLE(ObjectManager)->Remove(this);
	}

	//충돌처리 모든 애들 스캔
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		if (object == this) //자기 자신이면 패스
			continue;

		if (object->GetObjectType() != ObjectType::Monster)//몬스터 아니면 패스
			continue;

		Pos p1 = GetPos();//미사일 위치
		Pos p2 = object->GetPos(); //몬스터 위치

		const float dx = p1.x - p2.x;
		const float dy = p1.y - p2.y;

		float dist = sqrt(dx*dx + dy*dy);

		if (object->GetObjectType() == ObjectType::Monster && dist < 25)
		{
			//### 괜찮을까... 
			GET_SINGLE(ObjectManager)->Remove(object);
			GET_SINGLE(ObjectManager)->Remove(this);
			return;//!삭제했으니 접근불가 메모리 이므로 return 
		}
	\
	}

}

void Missile::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 25);
}
