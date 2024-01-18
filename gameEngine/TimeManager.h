#pragma once
//�̱���-> static�� �̿��ؼ� �����Ϳ����� ��ü����� static�޼����(��ü���� ::�θ� ���ٰ�����) 
//pch.h�� Defines.h �ֱ� ������ DECLARE_SINGLE �ٷ� ��� ���� 
class TimeManager
{
	DECLARE_SINGLE(TimeManager) //Define ��밡���� ������ ���� ������� ��Ŭ����ؾ��ϴµ� pch�� �׳� �ǳ���? 
#pragma region ������ �̷���..�̱���
	//public:
//	static TimeManager* GetInstance() //����ƽ �޼��� => ��ü�� �������.this������ ����. 
//	{//�޼��带 ���ؼ� �ܺο��� �������̽��� ���� �����Ѱ�! 
//		/* 1�� ���
//		if (s_instance == nullptr)
//			s_instance = new TimeManager();//�����Ϳ����� ������ ������ ���� ��ü ������ 
//
//		return s_instance;
//		*/
//		//2��° ���
//		static TimeManager s_instance;//������ ������ ��ü�� ����� ����
//		return &s_instance;//�� ��ü�� �ּҸ� ��� �ִ� ��� ,������ �Ҹ� ���� ��ų�� �𸥴�. 
//	}
//private:
//	
//	//static TimeManager* s_instance; //ù��° ���
//	TimeManager(){} //2��° ���: Ÿ�ӸŴ��� �ٸ������� ������� private���� ����д�.
#pragma endregion

public:
	void Init();
	void Update();

	//
	uint32 GetFps() { return _fps; }
	// ���������� ~����ð����� ����� �ð� ��Ÿ Ÿ�� 
	float GetDeltaTime() { return _deltaTime; }

private:
	uint64 _frequency = 0;//
	uint64 _prevCount = 0;
	float _deltaTime = 0.f;


private:
	uint32 _frameCount = 0;
	float  _frameTime = 0.f;
	uint32 _fps = 0;
};

