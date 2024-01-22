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
	//������ ��Ʈ ����ü �ʱ�ȭ 
	_state.hp = 1;
	_state.maxHp = 1;
	_state.speed = 600;
}

void Missile::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	
	//�̻��� ��ġ ������Ʈ
	_pos.y -= deltaTime * _state.speed;

	//�̻��� ���� ó�� 
	if (_pos.y < -200)
	{
		//�Ҹ� ó�� ? ������Ʈ���� �� �ڽ��� �����Ѵ�? 
		GET_SINGLE(ObjectManager)->Remove(this);
	}

	//�浹ó�� ��� �ֵ� ��ĵ
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		if (object == this) //�ڱ� �ڽ��̸� �н�
			continue;

		if (object->GetObjectType() != ObjectType::Monster)//���� �ƴϸ� �н�
			continue;

		Pos p1 = GetPos();//�̻��� ��ġ
		Pos p2 = object->GetPos(); //���� ��ġ

		const float dx = p1.x - p2.x;
		const float dy = p1.y - p2.y;

		float dist = sqrt(dx*dx + dy*dy);

		if (object->GetObjectType() == ObjectType::Monster && dist < 25)
		{
			//### ��������... 
			GET_SINGLE(ObjectManager)->Remove(object);
			GET_SINGLE(ObjectManager)->Remove(this);
			return;//!���������� ���ٺҰ� �޸� �̹Ƿ� return 
		}
	\
	}

}

void Missile::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 25);
}
