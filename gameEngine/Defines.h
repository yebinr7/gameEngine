#pragma once
//define���� �����ϰ�! 
#define DECLARE_SINGLE(classname)  		\
public:									\
	static classname* GetInstance() 	\
	{									\
		static classname s_instance;	\
		return &s_instance;				\
	}									\
private:								\
	classname() { }						\


#define GET_SINGLE(classname)  classname::GetInstance() //;�޸�ȵȴ�. 