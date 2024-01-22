#pragma once
#include <Windows.h>
#include <string>
using namespace std; 
//빌드 순서 때문에 보험용으로 헤더 추가해논것! 
//====================================================================================================
//자주 사용하는 헬퍼 함수들 만들기 

class Utils
{
public:
	//정적으로 만들어서 데이터영역에 있는 매서드 ::->로 땡겨쓰는 용 
	static void DrawTexts(HDC hdc, Pos pos, const wstring& str); 

	//정적메서드 넣어준 좌표 중심으로 사각형 만들어주세요  
	static void DrawRect(HDC hdc, Pos centerPos, int32 width, int32 height);
	//원의 중심좌표 넣어주면 원그려주는
	static void DrawCircle(HDC hdc, Pos centerPos, int32 radius);
	//MoveToEx -> LineTo 2개 함수로 그려주기 
	static void DrawLine(HDC hdc, Pos fromPos, Pos toPos); 
};



//====================================================================================================
