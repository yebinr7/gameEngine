#include "pch.h"
#include "EditScene.h"
#include "InputManager.h"
#include <fstream>

EditScene::EditScene()
{
}

EditScene::~EditScene()
{
}

void EditScene::Init()
{
}

void EditScene::Update()
{
	//왼쪽 마우스 눌렀을 때  
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::LeftMouse))
	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();

		if (_setOrigin)//맨 처음으로 클릭했다면 
		{
			_lastPos = mousePos; 
			_setOrigin = false;
		}
		else //맨처음 아니라면 두번째 점 
		{
			_lines.push_back(make_pair(_lastPos, mousePos)); //이전프레임의 위치, 현재 찍은위치 
			_lastPos = mousePos;//현재위치는 이제 다음프레임에서 이전프레임의 위치 
		}
	}
	//오른쪽 마우스 눌렀을 떄 
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::RightMouse))
		_setOrigin = true;//다시 처음 상태로 
	
	//저장
	if(GET_SINGLE(InputManager)->GetButtonDown(KeyType::S))
	{
		wofstream file; //wide라서 아웃풋 스트림 
		file.open(L"Unit.txt");

		int32 minX = INT32_MAX;
		int32 maxX = INT32_MIN;
		int32 minY = INT32_MAX;
		int32 maxY = INT32_MIN;

		for (auto& line : _lines)
		{
			POINT from = line.first;
			POINT to = line.second;

			minX = min(min(minX, from.x),to.x);//from x tox 에서 최소값
			maxX = max(max(minX, from.x), to.x);//from to x에서 최대값 
			minY = min(min(minY, from.y), to.y); 
			maxY = max(max(minY, from.y), to.y);
		}

		//라인의 중간 좌표 
		int32 midX = (maxX + minX) / 2; 
		int32 midY = (maxY + minY) / 2;


		//라인 개수 
		file << static_cast<int32>(_lines.size()) << endl;

		for (auto& line : _lines)
		{
			POINT from = line.first;
			from.x -= midX; //기준점 보강 
			from.y -= midY; //기준점 보강
			POINT to = line.second;
			to.x -= midX;
			to.y -= midY;

			//c++20 format문법 
			wstring str = std::format(L"({0},{1})->({2},{3})", from.x, from.y, to.x, to.y);
			file << str << endl;
		}
		file.close();
	}


	//로드 
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::D))
	{
		wifstream file;
		file.open(L"Unit.txt");

		//라인 개수
		int32 count;
		file >> count;

		_lines.clear();


		//중앙에서 불러져 오게 보정?
		int32 midX = 400;
		int32 midY = 300;

		for (int32 i = 0; i < count; i++)
		{
			POINT pt1;
			POINT pt2;

			wstring str;
			file >> str; //스트링으로 꺼내오고 

			::swscanf_s(str.c_str(), L"(%d,%d)->(%d,%d)", &pt1.x, &pt1.y, &pt2.x, &pt2.y);
			
			//중앙 처리 
			pt1.x += midX;
			pt1.y += midY;
			pt2.x += midX;
			pt2.y += midY;
			_lines.push_back(make_pair(pt1, pt2));
			_setOrigin = true;
		}

		file.close();
	}

}

void EditScene::Render(HDC hdc)
{
	for (auto& line : _lines)
	{
		POINT pt1 = line.first;
		POINT pt2 = line.second;

		Pos pos1;
		pos1.x = (float)pt1.x;	
		pos1.y = (float)pt1.y;

		Pos pos2;
		pos2.x = (float)pt2.x;
		pos2.y = (float)pt2.y;

		Utils::DrawLine(hdc, pos1, pos2); //벡터에 저장된 순서로 선 그리기
	}
}
