#pragma once
class Object;

class ObjectManager
{
public:
	DECLARE_SINGLE(ObjectManager);

	~ObjectManager();


	//������ ��� �ִ� ���� 
public:
	//������Ʈ �߰� ������Ʈ �ּ� �Ѱ��ֱ�
	void Add(Object* object);
	//���� ��ȸ�ؼ� ������Ʈ ����
	void Remove(Object* object);
	//
	void Clear();
public:
	const vector<Object*> GetObjects() { return _objects; }
public:
	//��ü ����� ���ø�(Init���Ե�) 
	template<typename T>
	T* CreateObject()
	{
		//type trait�� ������ Ÿ�ӿ� üũ�ؼ� ���� ����ֱ�
		static_assert(std::is_convertible_v<T*, Object*>);
		
		T* object = new T();
		object->Init();//### ��� �� ��ü�� Init�� ����־����� ����?

		return object;
	}

private:
	vector<Object*> _objects;

};

