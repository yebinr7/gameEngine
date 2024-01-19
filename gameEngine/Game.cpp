#include "pch.h"
#include "Game.h"
#include "TimeManager.h" 
#include "inputManager.h"
Game::Game()
{


}

Game::~Game()
{
	//사실 마지막에 메모리체크
	_CrtDumpMemoryLeaks();
}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;//핸들값 받아오기 
	
	_hdc = ::GetDC(hwnd); //윈도우핸들번호에 따른 도화지의 번호 얻어오기 

	GET_SINGLE(TimeManager)->Init();//싱글톤객체로 Init 
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
		wstring str = std::format(L"Mouse({0}), ({1}) ms", mousePos.x, mousePos.y);//1000곱하는이유 밀리세컨드
		::TextOut(_hdc, 20, 10, str.c_str(), static_cast<int32>(str.size()));
	}

	//format c++20 방식

	{
		wstring str = std::format(L"FPS({0}), DT({1}) ms", fps, static_cast<int32>(deltaTime * 1000));//1000곱하는이유 밀리세컨드
		::TextOut(_hdc, 650, 10, str.c_str(), static_cast<int32>(str.size()));
	}
	::Rectangle(_hdc, 200, 200, 400, 400);



	//====================================================================================================

	//플레이어?
	//몬스터?
	//투자체? 
}
