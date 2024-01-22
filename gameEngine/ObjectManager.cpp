#include "pch.h"
#include "ObjectManager.h"
#include "Object.h"
ObjectManager::~ObjectManager()
{
	Clear();
}

void ObjectManager::Add(Object* object)
{
	if (object == nullptr)
		return;//널이면 리턴 

	auto findit = std::find(_objects.begin(), _objects.end(), object);
	if (findit != _objects.end())//못찾았으면..
		return;

	_objects.push_back(object); 
}

void ObjectManager::Remove(Object* object)
{
	if (object == nullptr)
		return;//찾고 싶은 오브젝트 가 없네

	//지우고 싶은 오브젝트가 있다면...

	//더럽게 만들어진...리무브 
	_objects.erase(std::remove(_objects.begin(), _objects.end(), object), _objects.end());

	//TODO object 지우는 거 괜찮은가?
	delete object;
}

void ObjectManager::Clear()
{
	//벡터안의 Object* 가 가진 객체 다 날리고 
	for_each(_objects.begin(), _objects.end(),
		[](Object* ptrPara)
		{
			delete ptrPara;
		});
	_objects.clear();//벡터는 size()는 0이지만 capacity는 늘어난 상태 
}
