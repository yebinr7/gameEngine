#pragma once
#include "Scene.h"
class DevScene :
    public Scene
{
public:
	DevScene();
	virtual ~DevScene() override;//## 버추얼 소멸자 
public:
	virtual void Init() override;
	virtual void Update()override;
	virtual void Render(HDC hdc)override;

public:
	int _speed = 1000; //스피드 가 중요한 것! 델타타임* 스피드 
	Pos _playerPos{ 300.f,300.f };
};

