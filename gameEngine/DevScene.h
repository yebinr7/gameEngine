#pragma once
#include "Scene.h"
class DevScene :
    public Scene
{
public:
	DevScene();
	virtual ~DevScene() override;//## ���߾� �Ҹ��� 
public:
	virtual void Init() override;
	virtual void Update()override;
	virtual void Render(HDC hdc)override;

public:
	int _speed = 1000; //���ǵ� �� �߿��� ��! ��ŸŸ��* ���ǵ� 
	Pos _playerPos{ 300.f,300.f };
};

