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
		return;//���̸� ���� 

	auto findit = std::find(_objects.begin(), _objects.end(), object);
	if (findit != _objects.end())//��ã������..
		return;

	_objects.push_back(object); 
}

void ObjectManager::Remove(Object* object)
{
	if (object == nullptr)
		return;//ã�� ���� ������Ʈ �� ����

	//����� ���� ������Ʈ�� �ִٸ�...


	//������ �������...������ 
	_objects.erase(std::remove(_objects.begin(), _objects.end(), object), _objects.end());

	//TODO object ����� �� ��������?
	delete object;//### ���� �����Ͱ� ����Ű�� ��ü ����� �� �����͸� _objects���Ϳ��� �����ϴ°� �ȵǳ�?
	
}

void ObjectManager::Clear()
{
	//���;��� Object* �� ���� ��ü �� ������ 
	for_each(_objects.begin(), _objects.end(),
		[](Object* ptrPara)
		{
			delete ptrPara;
		});
	_objects.clear();//���ʹ� size()�� 0������ capacity�� �þ ���� 
}
