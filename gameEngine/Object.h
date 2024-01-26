#pragma once

enum class ObjectType
{
	None,
	Player,
	Monster,
	Projectile,
};

class Object
{
public:
	Object();
	Object(ObjectType type);
	virtual ~Object(); //소멸자 버츄얼 

	//====================================================================================================
	//템플릿으로 오브젝트 만들어지자마자 Init 자동으로 되게 해둠 ! 
	virtual void Init() = 0;
	
	virtual void Update() = 0;
	
	virtual void Render(HDC hdc) = 0;
	//====================================================================================================


	//
	ObjectType GetObjectType() {return _type;}

	//
	Pos	 GetPos() { return _pos; }
	//
	void SetPos(Pos pos) { _pos = pos; }

protected:


	ObjectType	_type = ObjectType::None;
	State	    _state = {};
	Pos			_pos = { };
};

