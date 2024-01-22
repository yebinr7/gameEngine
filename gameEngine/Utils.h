#pragma once
#include <Windows.h>
#include <string>
using namespace std; 
//���� ���� ������ ��������� ��� �߰��س��! 
//====================================================================================================
//���� ����ϴ� ���� �Լ��� ����� 

class Utils
{
public:
	//�������� ���� �����Ϳ����� �ִ� �ż��� ::->�� ���ܾ��� �� 
	static void DrawTexts(HDC hdc, Pos pos, const wstring& str); 

	//�����޼��� �־��� ��ǥ �߽����� �簢�� ������ּ���  
	static void DrawRect(HDC hdc, Pos centerPos, int32 width, int32 height);
	//���� �߽���ǥ �־��ָ� ���׷��ִ�
	static void DrawCircle(HDC hdc, Pos centerPos, int32 radius);
	//MoveToEx -> LineTo 2�� �Լ��� �׷��ֱ� 
	static void DrawLine(HDC hdc, Pos fromPos, Pos toPos); 
};



//====================================================================================================
