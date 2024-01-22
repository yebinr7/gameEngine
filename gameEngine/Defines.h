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

//====================================================================================================
#define GET_SINGLE(classname)  classname::GetInstance() //;�޸�ȵȴ�. ->��  
//====================================================================================================


//====================================================================================================
//SAFE DELETE 
#define SAFE_DELETE(ptr)   \
	if (ptr != nullptr)	   \
	{					   \
		delete ptr;		   \
		ptr = nullptr;	   \
	}					   \
	//if (_scene != nullptr)//���� �Ŵ����� ���� ����־��ٸ�...
	//	delete _scene; //�������Ͱ� ����ִ� ����ü �����
	//_scene = nullptr;//�������;ȵ� nullptr�� �о��ֱ� 

//====================================================================================================
