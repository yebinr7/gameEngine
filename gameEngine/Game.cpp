#include "pch.h"
#include "Game.h"
#include "TimeManager.h" 
#include "inputManager.h"
Game::Game()
{


}

Game::~Game()
{
	//��� �������� �޸�üũ
	_CrtDumpMemoryLeaks();
}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;//�ڵ鰪 �޾ƿ��� 
	
	_hdc = ::GetDC(hwnd); //�������ڵ��ȣ�� ���� ��ȭ���� ��ȣ ������ 

	GET_SINGLE(TimeManager)->Init();//�̱��水ü�� Init 
	GET_SINGLE(inputManager)->Init(hwnd);

}

void Game::Update()
{
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(inputManager)->Update();
	

}

void Game::Render()
{
	uint32 fps = GET_SINGLE(TimeManager)->GetFps();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	{
		POINT mousePos = GET_SINGLE(inputManager)->GetMousePos();
		wstring str = std::format(L"Mouse({0}), ({1}) ms", mousePos.x, mousePos.y);//1000���ϴ����� �и�������
		::TextOut(_hdc, 20, 10, str.c_str(), static_cast<int32>(str.size()));
	}

	//format c++20 ���

	{
		wstring str = std::format(L"FPS({0}), DT({1}) ms", fps, static_cast<int32>(deltaTime * 1000));//1000���ϴ����� �и�������
		::TextOut(_hdc, 650, 10, str.c_str(), static_cast<int32>(str.size()));
	}
	::Rectangle(_hdc, 200, 200, 400, 400);



	//====================================================================================================

	//�÷��̾�?
	//����?
	//����ü? 
}
