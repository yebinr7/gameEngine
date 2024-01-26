#include "pch.h"
#include "Player.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Missile.h"
#include "ObjectManager.h"
#include "ResourceManager.h"
#include "LineMesh.h"
Player::Player()
	:Object(ObjectType::Player)//오브젝트 생성자로 타입 초기화 
{
}

Player::~Player()
{
}

void Player::Init()
{
	// TODO: 
	//데이터 시트대로 초기화 
	_state.hp = 100;
	_state.maxHp = 100;
	_state.speed = 500;

	_pos.x = 400;
	_pos.y = 500;
}

void Player::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();//방금 1프레임 당 시간 받아와서 
	//### 인풋매니저를 통한 객체 에서 키상태 받아와야 한다. 
	if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{
		_pos.x -= _state.speed * deltaTime; //단위시간당 이동거리(속력) * 시간 => 실제 이동거리
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
	//대각선은 루트2 배 만큼 늘어남 따라서 더 멀리감 

	if (GET_SINGLE(InputManager)->GetButton(KeyType::Q))
	{//각을 어떻게 증가시킴?
		_barrelAngle -= deltaTime* 10; //좌표가 뒤집혔으므로 반대로 
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::E))
	{

		_barrelAngle += deltaTime * 10;
	}


////////////////////////////////////////////////////////////////
//															  //
//															  //
// 		          	미사일 만들기	    						  //
//															  //
//															  //
////////////////////////////////////////////////////////////////
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::SpaceBar))
	{
		//TODO: 미사일 발사 
		//Missile* missile = new Missile();//씬에다가 어떻게? 
		Missile* missile = GET_SINGLE(ObjectManager)->CreateObject<Missile>();
 		missile->SetPos(GetBarrelPos());//위치는 플레이어의 위치 
		missile->SetAngle(_barrelAngle);//각도도 같이 넘겨주기 
		GET_SINGLE(ObjectManager)->Add(missile);//오브젝트 매니저에도 추가하기 
	}


}

void Player::Render(HDC hdc)
{
	//플레이어 라고 생각 
	//Utils::DrawCircle(hdc, _pos, 50);
	const LineMesh* mesh = GET_SINGLE(ResourceManager)->GetLineMesh(L"Player");//리소스 매니저 객체안의 해쉬맵에 저장되어 있는 주소값 빼오기 
	if (mesh)//저장되어 있는 LineMesh 객체의 주소가 존재한다면 
		mesh->Render(hdc, _pos);//그릴 플레이어의 위치 
	
	//선 색깔 바꾸기 
	HPEN hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0)); // PS_SOLID: 실선, 3: 선의 두께, RGB(255, 0, 0): 빨간색
	HGDIOBJ hOldPen = SelectObject(hdc, hPen);

	Utils::DrawLine(hdc, _pos, GetBarrelPos());

	// 선의 속성 복원
	SelectObject(hdc, hOldPen);
	DeleteObject(hPen);
}

Pos Player::GetBarrelPos()
{
	_barrelEndPos = _pos; //
	_barrelEndPos.x += ::cos(_barrelAngle) * _barrelLength;
	_barrelEndPos.y += ::sin(_barrelAngle) * _barrelLength;
	return _barrelEndPos;
}
