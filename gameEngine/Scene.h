#pragma once
class Scene
{
public:
	Scene();
	virtual ~Scene();//## ���߾� �Ҹ��� 
public:
	virtual void Init() = 0; //## ���������Լ� �������̽�ȭ �ڽ��� �ʼ��������̵�,
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
};

