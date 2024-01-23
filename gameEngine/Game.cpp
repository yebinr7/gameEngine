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
	//��� �������� �޸�üũ
	_CrtDumpMemoryLeaks();
}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;//�ڵ鰪 �޾ƿ��� 
	
	_hdc = ::GetDC(hwnd); //�������ڵ��ȣ�� ���� ��ȭ���� ��ȣ ������ 

	//���߹��۸� ó���ڵ�
	::GetClientRect(hwnd, &_rect); 

	_hdcBack = ::CreateCompatibleDC(_hdc);//_hdc�� ȣȯ�Ǵ� DC�� ����
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom); //_hdc�� ȣȯ�Ǵ� ��Ʈ�� ���� 
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack); //DC�� BMP�� ���� 
	DeleteObject(prev);//SelectObject�� ����� ���´ϱ� �� ��ȯ���� �����ֱ� 


	GET_SINGLE(TimeManager)->Init();//�̱��水ü�� Init 
	GET_SINGLE(InputManager)->Init(hwnd);
	GET_SINGLE(SceneManager)->Init();
	GET_SINGLE(ResourceManager)->Init();

	GET_SINGLE(SceneManager)->ChangeScene(SceneType::GameScene);//����Ʈ �� �����ϱ� 
}




void Game::Update() //�������Ӹ��� �Ҹ� 
{
	GET_SINGLE(TimeManager)->Update();//������ ���
	GET_SINGLE(InputManager)->Update();//Ű�Է� ���� 
	GET_SINGLE(SceneManager)->Update();//���Ӽ����� ���� ����

}

void Game::Render()
{
	uint32 fps = GET_SINGLE(TimeManager)->GetFps();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();
		wstring str = std::format(L"Mouse({0}), ({1}) ms", mousePos.x, mousePos.y);//1000���ϴ����� �и�������
		::TextOut(_hdcBack, 20, 10, str.c_str(), static_cast<int32>(str.size())); //_hdcBack ���߹��۸���
	}

	//format c++20 ���

	{
		wstring str = std::format(L"FPS({0}), DT({1}) ms", fps, static_cast<int32>(deltaTime * 1000));//1000���ϴ����� �и�������
		::TextOut(_hdcBack, 650, 10, str.c_str(), static_cast<int32>(str.size()));
	}
	

	//====================================================================================================
	//�÷��̾�?
	//����?
	//����ü? 
	GET_SINGLE(SceneManager)->Render(_hdcBack);//��ȭ�� �ǳ��ֱ� 


	//Double Buffering 
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);//_hdcBack->_hdc�� �Ű��ֱ� 
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);//�̷��� �ϸ� ���� �����ӿ��� ���� �׸��� �׸��� ���� ���� �������� �׸��� ����� ȿ���� ���� �� �ֽ��ϴ�.
}
