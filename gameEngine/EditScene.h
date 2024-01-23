#pragma once
#include "Scene.h"
class EditScene
	:public Scene
{
public:
	EditScene();
	virtual ~EditScene() override;//## 버추얼 소멸자 
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;


private:
	vector<pair<POINT, POINT>> _lines;//두점을 가진 벡터 

	//맨처음으로 눌렀는지?
	bool	_setOrigin		    = true;
	//이전 좌표 
	POINT   _lastPos			= {};

};

