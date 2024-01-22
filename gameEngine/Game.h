#pragma once
class Game
{
public:
	Game();
	~Game();

public:
	//초기화 하는 함수
	void Init(HWND hwnd);
	//매프레임 업데이트 하는함수
	void Update();
	//그려주는 함수
	void Render();

private:
	HWND _hwnd = {};
	HDC	 _hdc = {};

private:
	//더블 버퍼링
	RECT _rect; //현재 그리는 영역
	HDC _hdcBack = {};//백버퍼
	HBITMAP _bmpBack = {};
};

