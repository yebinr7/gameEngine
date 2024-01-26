#include "pch.h"
#include "Missile.h"
#include "TimeManager.h"
#include "ObjectManager.h"
#include "Player.h"
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
	//각도에 의해 
	//_pos.y -= deltaTime * _state.speed;
	/*_pos.y += deltaTime * sin(_angle)*_state.speed;
	_pos.x += deltaTime * cos(_angle)*_state.speed;*/


	//유도탄 미사일 
	if (_target == nullptr)//현재 미사일의 타겟이 없다면
	{
		//미사일 객체 만들어진 
		// 0.2초 뒤에 타겟을 오브젝트 매니저 벡터 순회하면서
		//조건은 몬스터인 애한테
		_pos.y += deltaTime * sin(_angle) * _state.speed;
		_pos.x += deltaTime * cos(_angle) * _state.speed;


		_cumulTime += deltaTime;
		if (_cumulTime >= 0.2f)
		{
			//현재 미사일의 타겟 설정 
			const auto &objVec = GET_SINGLE(ObjectManager)->GetObjects();

			for (auto obj : objVec)
			{
				//순회하면서 젤 먼저 만나는 몬스터를 타겟으로 설정
				if (obj->GetObjectType() == ObjectType::Monster)
				{
					_target = obj; //타겟 얻었으면 바로 나가기 
					break;
				}
				
			}
		}
	}
	else //타겟이 존재한다면 
	{
		//_target;
		//타겟을 향해서 매 프레임 이동 
		
		//Vector toFrom = _target->GetPos() - this->GetPos();
		//toFrom.Normalize();
		////_dir = toFrom;//노말라이즈해서 넣기

		//Vector moveDir = toFrom * _state.speed * deltaTime;
		//_pos += moveDir;

		Vector dir = _target->GetPos() - GetPos();
		dir.Normalize();

		// 되나?
		_target->SetPos(_target->GetPos());

		_pos += dir * deltaTime * _state.speed;

		//_pos.x = _pos.x + (_state.speed) * deltaTime * _dir.x;
		//_pos.y = _pos.y + (_state.speed) * deltaTime * _dir.y;
	}

	

	//충돌처리 모든 애들 스캔
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		if (object == this) //자기 자신이면 패스
			continue;

		if (object->GetObjectType() != ObjectType::Monster)//몬스터 아니면 패스
			continue;

		//Pos p1 = GetPos();//미사일 위치
		//Pos p2 = object->GetPos(); //몬스터 위치

		/*const float dx = p1.x - p2.x;
		const float dy = p1.y - p2.y;*/

		//float dist = sqrt(dx*dx + dy*dy);
		 
		Pos p1 = GetPos();
		Pos p2 = object->GetPos();

		const float dx = p1.x - p2.x;
		const float dy = p1.y - p2.y;
		float dist = sqrt(dx * dx + dy * dy);

		if (dist < 25)
		{
			//### 괜찮을까... 
			GET_SINGLE(ObjectManager)->Remove(object);
			GET_SINGLE(ObjectManager)->Remove(this);
			return;//!삭제했으니 접근불가 메모리 이므로 return 
		}
	}
	//미사일 삭제 처리 
	if (_pos.y < -1000)
	{
		//소멸 처리 ? 업데이트에서 나 자신을 삭제한다? 
		GET_SINGLE(ObjectManager)->Remove(this);
	}

}

void Missile::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 25);
}
