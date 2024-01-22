#pragma once
#include "Scene.h"
class Player;

class GameScene :
    public Scene
{
public:
	GameScene();
	virtual ~GameScene() override;//## 버추얼 소멸자 
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	//class Player* _player = nullptr; //클래스전방선언+포인터 <=한계가있다.
	//여기서 이제 자료구조로 객체들 들고있는 것! 
	vector<Player*> _playerVector;
};

