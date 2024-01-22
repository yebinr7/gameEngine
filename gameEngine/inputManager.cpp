#include "pch.h"
#include "inputManager.h"

void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_states.resize(KEY_TYPE_COUNT, KeyState::None);//255개 모두 None상태로 초기화 
}

void InputManager::Update()
{
	BYTE asciiKeys[KEY_TYPE_COUNT] = {};//1바이트 256개의 배열 만들어주기 
	if(::GetKeyboardState(asciiKeys) == false)//매 프레임마다 모든 키보드 상태 정보를 가져온다. 이게 더 빠름 
		return;
	
	//::GetKeyboardState로 배열 형태로 모든 상태 가져왔다면 
	//그 배열의 모든 요소 돌면서 체크되어있는지 확인한다. 
	for (uint32 key = 0; key < KEY_TYPE_COUNT; key++)
	{//만약 'A' 키라면 
		if (asciiKeys[key] & 0x80)//비트 플레그 체크 ::GetKeyboardState으로 현재 눌린상태라면 ! 
		{
			KeyState& state = _states[key];//벡터에 key인덱스의 요소에 원본으로 받아서(이전프레임의 상태 받아온것) 

			//이전 프레임에 Press상태거나 down 상태였다면 
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Press;//Press상태로 바뀜 
			else//이전 프레임에 up이거나 none 이었다면 
				state = KeyState::Down; //처음 눌렸으니 Down 
		}
		else//현재 눌리지않은 상태라면...(Up상태)
		{
			KeyState& state = _states[key];//이전 프레임의 그 키에 대한 상태 원본으로 받아와서  

			// 이전 프레임에 키를 누른 상태라면 UP
			if (state == KeyState::Press || state == KeyState::Down) 
				state = KeyState::Up; //Press,Down 에서 Up 상태로 덮어쓰기, 업데이트 된거  
			else //Up상태에선->None이되고 None->None상태로 업데이트 됨
				state = KeyState::None;
		}
	}
	// Mouse
	::GetCursorPos(&_mousePos); // 커서의 좌표를 알아온다
	::ScreenToClient(_hwnd, &_mousePos);
}
