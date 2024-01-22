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
	virtual ~Object(); //¼Ò¸êÀÚ ¹öÃò¾ó 

	//====================================================================================================
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

