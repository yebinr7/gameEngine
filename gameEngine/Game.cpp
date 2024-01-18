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
	_hwnd = hwnd;//핸들값 받아오기 
	
	_hdc = ::GetDC(hwnd); //윈도우핸들번호에 따른 도화지의 번호 얻어오기 
}

void Game::Update()
{


}

void Game::Render()
{
	::Rectangle(_hdc, 200, 200, 400, 400);

}
