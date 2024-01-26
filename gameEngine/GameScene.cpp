#include "pch.h"
#include "GameScene.h"
#include "Player.h"
#include "Monster.h"
#include "ObjectManager.h"
GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	//씬에 객체 배치 
	//_player = new Player();
	//_player->Init(); //데이터 시트대로 초기화 

//====================================================================================================
	//플레이어 만드는 코드 

	//여기서 템플릿으로 오브잭트 객체 만들기(이닛)도포함 
	{
		Player* player = GET_SINGLE(ObjectManager)->CreateObject<Player>();
		player->SetPos(Pos{ 400,400 });
		GET_SINGLE(ObjectManager)->Add(player);//매니저에도 넣어주기, 벡터 안에 들어가게됨 
	}
//====================================================================================================
	// 몬스터 만드는 코드 
	for(int32 i =0 ; i<1; i++)
	{
		Monster* monster = GET_SINGLE(ObjectManager)->CreateObject<Monster>();
		monster->SetPos(Pos{static_cast<float>(i + 1) * 100, 100 });//컬리브레이스 축소변환 
		GET_SINGLE(ObjectManager)->Add(monster);//매니저에도 넣어주기, 벡터 안에 들어가게됨 
	}


//====================================================================================================	
}

void GameScene::Update()
{//### 일단 벡터를 복사하는 방식으로 진행한다.
	 //- 복사하지 않으면 객체들 추가할 때 계속 원본 벡터가 바뀔 수 있기 때문에 문제가 있다.
	 //- 복사하는 방법을 이용할 시, 삭제를 열심히 해줘야 한다. 


	//if (_player)//플레이어가 존재한다면
	//	_player->Update();//키입력, 좌표등등 업데이트, 미사일 만들고 관리? 
	//오브젝트 매니저가 들고 있는 객체들을 싹다 업데이트
	const auto objPtrVector = GET_SINGLE(ObjectManager)->GetObjects();
	/*
	std::for_each(objPtrVector.begin(), objPtrVector.end(),
		[=](Object* ptrPara)
		{
			ptrPara->Update();//벡터안에 있는 모든 객체 다형성으로 Update()싹다 돌기
		});
	*/
	for (auto obj : objPtrVector)
	{
		obj->Update();
	}
}

void GameScene::Render(HDC hdc)
{
	//if (_player)
	//	_player->Render(hdc);

	const auto &objPtrVector = GET_SINGLE(ObjectManager)->GetObjects();

	for (auto obj : objPtrVector)
	{
		obj->Render(hdc);
	}
}
