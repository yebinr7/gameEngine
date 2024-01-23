#include "pch.h"
#include "Game.h"
#include "TimeManager.h" 
#include "inputManager.h"
#include "SceneManager.h"
#include "ResourceManager.h"
Game::Game()
{


}

Game::~Game()
{
	GET_SINGLE(SceneManager)->Clear();
	GET_SINGLE(ResourceManager)->Clear();
	//사실 마지막에 메모리체크
	_CrtDumpMemoryLeaks();
}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;//핸들값 받아오기 
	
	_hdc = ::GetDC(hwnd); //윈도우핸들번호에 따른 도화지의 번호 얻어오기 

	//이중버퍼링 처리코드
	::GetClientRect(hwnd, &_rect); 

	_hdcBack = ::CreateCompatibleDC(_hdc);//_hdc와 호환되는 DC를 생성
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom); //_hdc와 호환되는 비트맵 생성 
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack); //DC와 BMP를 연결 
	DeleteObject(prev);//SelectObject로 연결된 상태니깐 그 반환값은 날려주기 


	GET_SINGLE(TimeManager)->Init();//싱글톤객체로 Init 
	GET_SINGLE(InputManager)->Init(hwnd);
	GET_SINGLE(SceneManager)->Init();
	GET_SINGLE(ResourceManager)->Init();

	GET_SINGLE(SceneManager)->ChangeScene(SceneType::GameScene);//디폴트 씬 설정하기 
}




void Game::Update() //매프레임마다 불림 
{
	GET_SINGLE(TimeManager)->Update();//프레임 계산
	GET_SINGLE(InputManager)->Update();//키입력 관리 
	GET_SINGLE(SceneManager)->Update();//게임세상의 씬들 관리

}

void Game::Render()
{
	uint32 fps = GET_SINGLE(TimeManager)->GetFps();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();
		wstring str = std::format(L"Mouse({0}), ({1}) ms", mousePos.x, mousePos.y);//1000곱하는이유 밀리세컨드
		::TextOut(_hdcBack, 20, 10, str.c_str(), static_cast<int32>(str.size())); //_hdcBack 이중버퍼링용
	}

	//format c++20 방식

	{
		wstring str = std::format(L"FPS({0}), DT({1}) ms", fps, static_cast<int32>(deltaTime * 1000));//1000곱하는이유 밀리세컨드
		::TextOut(_hdcBack, 650, 10, str.c_str(), static_cast<int32>(str.size()));
	}
	

	//====================================================================================================
	//플레이어?
	//몬스터?
	//투자체? 
	GET_SINGLE(SceneManager)->Render(_hdcBack);//도화지 건내주기 


	//Double Buffering 
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);//_hdcBack->_hdc에 옮겨주기 
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);//이렇게 하면 다음 프레임에서 새로 그림을 그리기 전에 이전 프레임의 그림을 지우는 효과를 얻을 수 있습니다.
}
