#pragma once
#include "ResourceBase.h"
class LineMesh :
    public ResourceBase
{
public:
	void Save(wstring path);
	void Load(wstring path);
	//pos에 그려라 
	void Render(HDC hdc, Pos pos) const;

protected:
	vector<pair<POINT, POINT>> _lines;//POINT2개Pair로들고 있는 벡터 
};

