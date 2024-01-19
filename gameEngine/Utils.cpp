#include "pch.h"
#include "Utils.h"

void Utils::DrawTexts(HDC hdc, Pos pos, const wstring& str)
{
	::TextOut(hdc, static_cast<int32>(pos.x),
		static_cast<int32>(pos.y), str.c_str(),
		static_cast<int32>(str.size()));
}

void Utils::DrawRect(HDC hdc, Pos centerPos, int32 width, int32 height)
{
	::Rectangle(hdc,
		static_cast<int32>(centerPos.x - (width / 2)), //���ʻ�� x��ǥ
		static_cast<int32>(centerPos.y - (height / 2)),//���ʻ�� y��ǥ
		static_cast<int32>(centerPos.x + (width / 2)), //�������ϴ� x ��ǥ
		static_cast<int32>(centerPos.y + (height / 2))); //������ �ϴ� y��ǥ 
}

void Utils::DrawCircle(HDC hdc, Pos centerPos, int32 radius)
{
	::Ellipse(hdc,
		static_cast<int32>(centerPos.x - radius),
		static_cast<int32>(centerPos.y - radius),
		static_cast<int32>(centerPos.x + radius),
		static_cast<int32>(centerPos.y + radius));
}

void Utils::DrawLine(HDC hdc, Pos fromPos, Pos toPos)
{
	::MoveToEx(hdc, static_cast<int32>(fromPos.x), static_cast<int32>(fromPos.y), nullptr);
	::LineTo(hdc, static_cast<int32>(toPos.x), static_cast<int32>(toPos.y));
;
}
