#pragma once
#include "Scene.h"
class Player;

class GameScene :
    public Scene
{
public:
	GameScene();
	virtual ~GameScene() override;//## ���߾� �Ҹ��� 
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	//class Player* _player = nullptr; //Ŭ�������漱��+������ <=�Ѱ谡�ִ�.
	//���⼭ ���� �ڷᱸ���� ��ü�� ����ִ� ��! 
	//vector<Player*> _playerVector;
	//Object�Ŵ������� <Object*> ���ͷ� �����Ѵ�. 
};

