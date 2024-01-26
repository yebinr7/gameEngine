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
	//���� ��ü ��ġ 
	//_player = new Player();
	//_player->Init(); //������ ��Ʈ��� �ʱ�ȭ 

//====================================================================================================
	//�÷��̾� ����� �ڵ� 

	//���⼭ ���ø����� ������Ʈ ��ü �����(�̴�)������ 
	{
		Player* player = GET_SINGLE(ObjectManager)->CreateObject<Player>();
		player->SetPos(Pos{ 400,400 });
		GET_SINGLE(ObjectManager)->Add(player);//�Ŵ������� �־��ֱ�, ���� �ȿ� ���Ե� 
	}
//====================================================================================================
	// ���� ����� �ڵ� 
	for(int32 i =0 ; i<1; i++)
	{
		Monster* monster = GET_SINGLE(ObjectManager)->CreateObject<Monster>();
		monster->SetPos(Pos{static_cast<float>(i + 1) * 100, 100 });//�ø��극�̽� ��Һ�ȯ 
		GET_SINGLE(ObjectManager)->Add(monster);//�Ŵ������� �־��ֱ�, ���� �ȿ� ���Ե� 
	}


//====================================================================================================	
}

void GameScene::Update()
{//### �ϴ� ���͸� �����ϴ� ������� �����Ѵ�.
	 //- �������� ������ ��ü�� �߰��� �� ��� ���� ���Ͱ� �ٲ� �� �ֱ� ������ ������ �ִ�.
	 //- �����ϴ� ����� �̿��� ��, ������ ������ ����� �Ѵ�. 


	//if (_player)//�÷��̾ �����Ѵٸ�
	//	_player->Update();//Ű�Է�, ��ǥ��� ������Ʈ, �̻��� ����� ����? 
	//������Ʈ �Ŵ����� ��� �ִ� ��ü���� �ϴ� ������Ʈ
	const auto objPtrVector = GET_SINGLE(ObjectManager)->GetObjects();
	/*
	std::for_each(objPtrVector.begin(), objPtrVector.end(),
		[=](Object* ptrPara)
		{
			ptrPara->Update();//���;ȿ� �ִ� ��� ��ü ���������� Update()�ϴ� ����
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
