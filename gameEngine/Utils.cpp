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
		static_cast<int32>(centerPos.x - (width / 2)), //왼쪽상단 x좌표
		static_cast<int32>(centerPos.y - (height / 2)),//왼쪽상단 y좌표
		static_cast<int32>(centerPos.x + (width / 2)), //오른쪽하단 x 좌표
		static_cast<int32>(centerPos.y + (height / 2))); //오른쪽 하단 y좌표 
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
