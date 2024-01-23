#include "pch.h"
#include "Player.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Missile.h"
#include "ObjectManager.h"
#include "ResourceManager.h"
#include "LineMesh.h"
Player::Player()
	:Object(ObjectType::Player)//������Ʈ �����ڷ� Ÿ�� �ʱ�ȭ 
{
}

Player::~Player()
{
}

void Player::Init()
{
	// TODO: 
	//������ ��Ʈ��� �ʱ�ȭ 
	_state.hp = 100;
	_state.maxHp = 100;
	_state.speed = 500;

	_pos.x = 400;
	_pos.y = 500;
}

void Player::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();//��� 1������ �� �ð� �޾ƿͼ� 
	//### ��ǲ�Ŵ����� ���� ��ü ���� Ű���� �޾ƿ;� �Ѵ�. 
	if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{
		_pos.x -= _state.speed * deltaTime; //�����ð��� �̵��Ÿ�(�ӷ�) * �ð� => ���� �̵��Ÿ�
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::D))
	{

		_pos.x += _state.speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::W))
	{

		_pos.y -= _state.speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::S))
	{

		_pos.y += _state.speed * deltaTime;
	}
	//�밢���� ��Ʈ2 �� ��ŭ �þ ���� �� �ָ��� 


	//====================================================================================================
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::SpaceBar))
	{
		//TODO: �̻��� �߻� 
		//Missile* missile = new Missile();//�����ٰ� ���? 
		Missile* missile = GET_SINGLE(ObjectManager)->CreateObject<Missile>();
		missile->SetPos(_pos);//��ġ�� �÷��̾��� ��ġ 
		GET_SINGLE(ObjectManager)->Add(missile);//������Ʈ �Ŵ������� �߰��ϱ� 
	}
	//====================================================================================================

}

void Player::Render(HDC hdc)
{
	//�÷��̾� ��� ���� 
	//Utils::DrawCircle(hdc, _pos, 50);
	const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(L"Player");
	if (mesh)
		mesh->Render(hdc, _pos);
}
