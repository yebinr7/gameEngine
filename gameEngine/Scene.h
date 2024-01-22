#pragma once
class Scene
{
public:
	Scene();
	virtual ~Scene();//## 버추얼 소멸자 
public:
	virtual void Init() = 0; //## 순수가상함수 인터페이스화 자식이 필수오버라이드,
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
};

