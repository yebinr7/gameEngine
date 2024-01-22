#include "pch.h"
#include "inputManager.h"

void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_states.resize(KEY_TYPE_COUNT, KeyState::None);//255�� ��� None���·� �ʱ�ȭ 
}

void InputManager::Update()
{
	BYTE asciiKeys[KEY_TYPE_COUNT] = {};//1����Ʈ 256���� �迭 ������ֱ� 
	if(::GetKeyboardState(asciiKeys) == false)//�� �����Ӹ��� ��� Ű���� ���� ������ �����´�. �̰� �� ���� 
		return;
	
	//::GetKeyboardState�� �迭 ���·� ��� ���� �����Դٸ� 
	//�� �迭�� ��� ��� ���鼭 üũ�Ǿ��ִ��� Ȯ���Ѵ�. 
	for (uint32 key = 0; key < KEY_TYPE_COUNT; key++)
	{//���� 'A' Ű��� 
		if (asciiKeys[key] & 0x80)//��Ʈ �÷��� üũ ::GetKeyboardState���� ���� �������¶�� ! 
		{
			KeyState& state = _states[key];//���Ϳ� key�ε����� ��ҿ� �������� �޾Ƽ�(������������ ���� �޾ƿ°�) 

			//���� �����ӿ� Press���°ų� down ���¿��ٸ� 
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Press;//Press���·� �ٲ� 
			else//���� �����ӿ� up�̰ų� none �̾��ٸ� 
				state = KeyState::Down; //ó�� �������� Down 
		}
		else//���� ���������� ���¶��...(Up����)
		{
			KeyState& state = _states[key];//���� �������� �� Ű�� ���� ���� �������� �޾ƿͼ�  

			// ���� �����ӿ� Ű�� ���� ���¶�� UP
			if (state == KeyState::Press || state == KeyState::Down) 
				state = KeyState::Up; //Press,Down ���� Up ���·� �����, ������Ʈ �Ȱ�  
			else //Up���¿���->None�̵ǰ� None->None���·� ������Ʈ ��
				state = KeyState::None;
		}
	}
	// Mouse
	::GetCursorPos(&_mousePos); // Ŀ���� ��ǥ�� �˾ƿ´�
	::ScreenToClient(_hwnd, &_mousePos);
}
