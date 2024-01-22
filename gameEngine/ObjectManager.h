#pragma once
class Object;

class ObjectManager
{
public:
	DECLARE_SINGLE(ObjectManager);

	~ObjectManager();


	//데이터 들고 있는 내용 
public:
	//오브젝트 추가 오브젝트 주소 넘겨주기
	void Add(Object* object);
	//벡터 순회해서 오브젝트 삭제
	void Remove(Object* object);
	//
	void Clear();
public:
	const vector<Object*> GetObjects() { return _objects; }
public:
	//객체 만드는 템플릿(Init포함됨) 
	template<typename T>
	T* CreateObject()
	{
		//type trait로 컴파일 타임에 체크해서 문제 잡아주기
		static_assert(std::is_convertible_v<T*, Object*>);
		
		T* object = new T();
		object->Init();//### 어떻게 이 객체가 Init을 들고있었는지 알지?

		return object;
	}

private:
	vector<Object*> _objects;

};

