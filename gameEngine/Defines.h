#pragma once
//define으로 간편하게! 
#define DECLARE_SINGLE(classname)  		\
public:									\
	static classname* GetInstance() 	\
	{									\
		static classname s_instance;	\
		return &s_instance;				\
	}									\
private:								\
	classname() { }						\

//====================================================================================================
#define GET_SINGLE(classname)  classname::GetInstance() //;달면안된다. ->용  
//====================================================================================================


//====================================================================================================
//SAFE DELETE 
#define SAFE_DELETE(ptr)   \
	if (ptr != nullptr)	   \
	{					   \
		delete ptr;		   \
		ptr = nullptr;	   \
	}					   \
	//if (_scene != nullptr)//원래 매니저가 씬을 들고있었다면...
	//	delete _scene; //씬포인터가 들고있던 씬객체 지우고
	//_scene = nullptr;//씬포인터안도 nullptr로 밀어주기 

//====================================================================================================
