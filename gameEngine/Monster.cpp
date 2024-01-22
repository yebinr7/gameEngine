#include "pch.h"
#include "Monster.h"

Monster::Monster()
	:Object(ObjectType::Monster)
{

}

Monster::~Monster()
{
}

void Monster::Init()
{
	_state.hp = 100;
	_state.maxHp = 100;
	_state.speed = 10;
}

void Monster::Update()
{
}

void Monster::Render(HDC hdc)
{
	Utils::DrawRect(hdc, _pos, 50, 50);
}
