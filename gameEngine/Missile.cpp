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
	//������ ��Ʈ ����ü �ʱ�ȭ 
	_state.hp = 1;
	_state.maxHp = 1;
	_state.speed = 600;
}

void Missile::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	
	//�̻��� ��ġ ������Ʈ
	//������ ���� 
	//_pos.y -= deltaTime * _state.speed;
	/*_pos.y += deltaTime * sin(_angle)*_state.speed;
	_pos.x += deltaTime * cos(_angle)*_state.speed;*/


	//����ź �̻��� 
	if (_target == nullptr)//���� �̻����� Ÿ���� ���ٸ�
	{
		//�̻��� ��ü ������� 
		// 0.2�� �ڿ� Ÿ���� ������Ʈ �Ŵ��� ���� ��ȸ�ϸ鼭
		//������ ������ ������
		_pos.y += deltaTime * sin(_angle) * _state.speed;
		_pos.x += deltaTime * cos(_angle) * _state.speed;


		_cumulTime += deltaTime;
		if (_cumulTime >= 0.2f)
		{
			//���� �̻����� Ÿ�� ���� 
			const auto &objVec = GET_SINGLE(ObjectManager)->GetObjects();

			for (auto obj : objVec)
			{
				//��ȸ�ϸ鼭 �� ���� ������ ���͸� Ÿ������ ����
				if (obj->GetObjectType() == ObjectType::Monster)
				{
					_target = obj; //Ÿ�� ������� �ٷ� ������ 
					break;
				}
				
			}
		}
	}
	else //Ÿ���� �����Ѵٸ� 
	{
		//_target;
		//Ÿ���� ���ؼ� �� ������ �̵� 
		
		//Vector toFrom = _target->GetPos() - this->GetPos();
		//toFrom.Normalize();
		////_dir = toFrom;//�븻�������ؼ� �ֱ�

		//Vector moveDir = toFrom * _state.speed * deltaTime;
		//_pos += moveDir;

		Vector dir = _target->GetPos() - GetPos();
		dir.Normalize();

		// �ǳ�?
		_target->SetPos(_target->GetPos());

		_pos += dir * deltaTime * _state.speed;

		//_pos.x = _pos.x + (_state.speed) * deltaTime * _dir.x;
		//_pos.y = _pos.y + (_state.speed) * deltaTime * _dir.y;
	}

	

	//�浹ó�� ��� �ֵ� ��ĵ
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		if (object == this) //�ڱ� �ڽ��̸� �н�
			continue;

		if (object->GetObjectType() != ObjectType::Monster)//���� �ƴϸ� �н�
			continue;

		//Pos p1 = GetPos();//�̻��� ��ġ
		//Pos p2 = object->GetPos(); //���� ��ġ

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
			//### ��������... 
			GET_SINGLE(ObjectManager)->Remove(object);
			GET_SINGLE(ObjectManager)->Remove(this);
			return;//!���������� ���ٺҰ� �޸� �̹Ƿ� return 
		}
	}
	//�̻��� ���� ó�� 
	if (_pos.y < -1000)
	{
		//�Ҹ� ó�� ? ������Ʈ���� �� �ڽ��� �����Ѵ�? 
		GET_SINGLE(ObjectManager)->Remove(this);
	}

}

void Missile::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 25);
}
