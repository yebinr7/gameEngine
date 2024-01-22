#include "pch.h"
#include "SceneManager.h"
#include "DevScene.h"
#include "GameScene.h"
void SceneManager::Init()
{
	_scene = nullptr;
}

void SceneManager::Update()
{
	if (_scene) //씬매니저가 가진 씬이 있다면..
		_scene->Update();//버추얼함수 따라서 런타임에 vtable 보고 실형식객체에 맞는 매소드 실행 
		
}

void SceneManager::Render(HDC hdc)
{
	if (_scene) //씬매니저가 가진 씬이 있다면..
		_scene->Render(hdc);
}

void SceneManager::Clear()
{
	SAFE_DELETE(_scene);
}


void SceneManager::ChangeScene(SceneType sceneType)
{
	if (_sceneType == sceneType)//같은 씬 들고 있으면 리턴
		return;

	Scene* newScene = nullptr;//부모 씬포인터로 관리

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
	default:
		break;
	}

	//{//### 
	//	if (_scene != nullptr)//원래 매니저가 씬을 들고있었다면...
	//		delete _scene; //씬포인터가 들고있던 씬객체 지우고
	//	_scene = nullptr;//씬포인터안도 nullptr로 밀어주기 
	//} Defines 에서 매크로로 만들기 !!
	SAFE_DELETE(_scene);

	_scene = newScene; //씬매니저가 들고 있는 씬 바꿔치기 
	_sceneType = sceneType; //씬매니저의 씬타입도 바꿔치기 


//====================================================================================================
	newScene->Init();//## 새로운 씬 이닛 
}

