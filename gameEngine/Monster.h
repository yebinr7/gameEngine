#pragma once
#include "Object.h"
class Monster :
    public Object
{
public:
	Monster();
	virtual ~Monster() override;
	//====================================================================================================
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	//====================================================================================================

};

