#pragma once
#include "Scene.h"
class EditScene
	:public Scene
{
public:
	EditScene();
	virtual ~EditScene() override;//## ���߾� �Ҹ��� 
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;


private:
	vector<pair<POINT, POINT>> _lines;//������ ���� ����

	//��ó������ ��������?
	bool	_setOrigin		    = true;
	//���� ��ǥ 
	POINT   _lastPos			= {};

};

