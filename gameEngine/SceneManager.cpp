#include "pch.h"
#include "SceneManager.h"
#include "DevScene.h"
#include "GameScene.h"
#include "EditScene.h"
void SceneManager::Init()
{
	_scene = nullptr;
}

void SceneManager::Update()
{
	if (_scene) //���Ŵ����� ���� ���� �ִٸ�..
		_scene->Update();//���߾��Լ� ���� ��Ÿ�ӿ� vtable ���� �����İ�ü�� �´� �żҵ� ���� 
		
}

void SceneManager::Render(HDC hdc)
{
	if (_scene) //���Ŵ����� ���� ���� �ִٸ�..
		_scene->Render(hdc);
}

void SceneManager::Clear()
{
	SAFE_DELETE(_scene);
}


void SceneManager::ChangeScene(SceneType sceneType)
{
	if (_sceneType == sceneType)//���� �� ��� ������ ����
		return;

	Scene* newScene = nullptr;//�θ� �������ͷ� ����

	switch (sceneType)
	{
	case SceneType::None:
		break;
	case SceneType::DevScene:
		newScene = new DevScene();
		break;
	case SceneType::GameScene:
		newScene = new GameScene();
		break;
	case SceneType::SceneNum:
		break;
	case SceneType::EditScene:
		newScene = new EditScene();
		break;
	default:
		break;
	}

	//{//### 
	//	if (_scene != nullptr)//���� �Ŵ����� ���� ����־��ٸ�...
	//		delete _scene; //�������Ͱ� ����ִ� ����ü �����
	//	_scene = nullptr;//�������;ȵ� nullptr�� �о��ֱ� 
	//} Defines ���� ��ũ�η� ����� !!
	SAFE_DELETE(_scene);

	_scene = newScene; //���Ŵ����� ��� �ִ� �� �ٲ�ġ�� 
	_sceneType = sceneType; //���Ŵ����� ��Ÿ�Ե� �ٲ�ġ�� 


//====================================================================================================
	newScene->Init();//## ���ο� �� �̴� 
}

