#include "pch.h"
#include "Game.h"
#include "TimeManager.h" 
Game::Game()
{
}

Game::~Game()
{
}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;//�ڵ鰪 �޾ƿ��� 
	
	_hdc = ::GetDC(hwnd); //�������ڵ��ȣ�� ���� ��ȭ���� ��ȣ ������ 
}

void Game::Update()
{


}

void Game::Render()
{
	::Rectangle(_hdc, 200, 200, 400, 400);

}
