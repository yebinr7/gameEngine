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
	//���� ���콺 ������ ��  
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::LeftMouse))
	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();

		if (_setOrigin)//�� ó������ Ŭ���ߴٸ� 
		{
			_lastPos = mousePos; 
			_setOrigin = false;
		}
		else //��ó�� �ƴ϶�� �ι�° �� 
		{
			_lines.push_back(make_pair(_lastPos, mousePos)); //������������ ��ġ, ���� ������ġ 
			_lastPos = mousePos;//������ġ�� ���� ���������ӿ��� ������������ ��ġ 
		}
	}
	//������ ���콺 ������ �� 
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::RightMouse))
		_setOrigin = true;//�ٽ� ó�� ���·� 
	
	//����
	if(GET_SINGLE(InputManager)->GetButtonDown(KeyType::S))
	{
		wofstream file; //wide�� �ƿ�ǲ ��Ʈ�� 
		file.open(L"Unit.txt");

		int32 minX = INT32_MAX;
		int32 maxX = INT32_MIN;
		int32 minY = INT32_MAX;
		int32 maxY = INT32_MIN;

		for (auto& line : _lines)
		{
			POINT from = line.first;
			POINT to = line.second;

			minX = min(min(minX, from.x),to.x);//from x tox ���� �ּҰ�
			maxX = max(max(minX, from.x), to.x);//from to x���� �ִ밪 
			minY = min(min(minY, from.y), to.y); 
			maxY = max(max(minY, from.y), to.y);
		}

		//������ �߰� ��ǥ 
		int32 midX = (maxX + minX) / 2; 
		int32 midY = (maxY + minY) / 2;


		//���� ���� 
		file << static_cast<int32>(_lines.size()) << endl;

		for (auto& line : _lines)
		{
			POINT from = line.first;
			from.x -= midX; //������ ���� 
			from.y -= midY; //������ ����
			POINT to = line.second;
			to.x -= midX;
			to.y -= midY;

			//c++20 format���� 
			wstring str = std::format(L"({0},{1})->({2},{3})", from.x, from.y, to.x, to.y);
			file << str << endl;
		}
		file.close();
	}
	//�ε� 
	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::D))
	{
		wifstream file;
		file.open(L"Unit.txt");

		//���� ����
		int32 count;
		file >> count;

		_lines.clear();


		//�߾ӿ��� �ҷ��� ���� ����?
		int32 midX = 400;
		int32 midY = 300;

		for (int32 i = 0; i < count; i++)
		{
			POINT pt1;
			POINT pt2;

			wstring str;
			file >> str; //��Ʈ������ �������� 

			::swscanf_s(str.c_str(), L"(%d,%d)->(%d,%d)", &pt1.x, &pt1.y, &pt2.x, &pt2.y);
			
			//�߾� ó�� 
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

		Utils::DrawLine(hdc, pos1, pos2); //���Ϳ� ����� ������ �� �׸���
	}
}
