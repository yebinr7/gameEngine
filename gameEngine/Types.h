#pragma once

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;
#include "cmath"

struct State
{
	int32 hp = 0;
	int32 maxHp = 0;
	float speed = 0;
};





////////////////////////////////////////////////////////////////
//															  //
//															  //
// 		          		���� ����    						  //
//															  //
//															  //
////////////////////////////////////////////////////////////////
struct Vector
{
	Vector() {};
	Vector(float x, float y)
		:x(x), y(y)
	{

	}

	Vector operator+(const Vector& other)
	{
		Vector newVec;
		newVec.x = x + other.x;
		newVec.y = y + other.y;
		return newVec;
	}

	Vector operator-(const Vector& other)
	{
		Vector newVec{ x,y };
		newVec.x = x - other.x;
		newVec.y = y - other.y;
		return newVec;
	}

	void operator+=(const Vector& other)
	{
		this->x += other.x;
		this->y += other.x;
	}

	void operator-=(const Vector& other)
	{
		this->x -= other.x;
		this->y -= other.y;
	}

	//��Į�� ���
	Vector operator*(float value)
	{
		Vector newVec;//0,0�ʱ�ȭ
		newVec.x = x * value;
		newVec.y = y * value;

		return newVec;
	}

	void operator*=(float value)
	{
		this->x *= value;
		this->y *= value;
	}

	


	//���� �ٸ� ������ ũ�� �񱳿� ������
	float LengthSquared()
	{
		return x * x + y * y;
	}
	//���� �ٸ� ������ ���� ���ϱ�
	float Length()
	{
		return ::sqrt(LengthSquared());
	}

	//��ֶ����� ���ϱ�
	void Normalize()
	{
		float length = this->Length();
		if (length < 0.00000001f) //���̰� �ʹ� �۴ٸ� ���� 0���� ��������! 
			return;

		x = x / length;
		y = y / length; 
	}



	float x = 0;
	float y = 0;
};

//struct Pos
//{
//	float x = 0;
//	float y = 0;
//};
using Pos = Vector;//���� Pos �����ϰ� Vector�� �̿� 