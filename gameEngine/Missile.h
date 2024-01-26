#pragma once
#include "Object.h"
class Missile :
    public Object
{
public:
	Missile();
	virtual ~Missile() override;
	//====================================================================================================
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	//====================================================================================================

	//플레이어에서 각도 넘겨줌 
	void SetAngle(float angle) { _angle = angle; }
private:
	float _angle = 0.f;
	Object* _target = nullptr;
	//객체 만들어진 시간부터 시간 쌓이기 
	float _cumulTime = 0;
	//Vector _dir = {};//방향벡터 
};

