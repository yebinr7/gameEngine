#pragma once
#include "ResourceBase.h"
class LineMesh :
    public ResourceBase
{
public:
	void Save(wstring path);
	void Load(wstring path);
	//pos�� �׷��� 
	void Render(HDC hdc, Pos pos) const;

protected:
	vector<pair<POINT, POINT>> _lines;//POINT2��Pair�ε�� �ִ� ���� 
};

