#pragma once
enum class KeyType
{
	//찾기 편하게 매핑해주기 
	LeftMouse = VK_LBUTTON,
	RightMouse = VK_RBUTTON,

	Up = VK_UP,
	Down = VK_DOWN,
	Left = VK_LEFT,
	Right = VK_RIGHT,

	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D',

	SpaceBar = VK_SPACE,

};

enum class KeyState
{
	None,
	Press,
	Down,
	Up,

	End 
};

/// <summary>
/// 키타입 개수와 키상태 개수 이넘으로 관리 
/// </summary>
enum
{
	KEY_TYPE_COUNT = static_cast<int32>(UINT8_MAX) + 1,//256을 나타냄 
	KEY_STATE_COUNT = static_cast<int32>(KeyState::End),
};

class InputManager
{
	DECLARE_SINGLE(InputManager)

public:
	//윈도우창 정보 가져오기 
	void Init(HWND hwnd);
	void Update();

	//누르고 있을 때
	bool GetButton(KeyType key){ return GetState(key) == KeyState::Press; }

	//땐상태에서 눌렀을 때
	bool GetButtonDown(KeyType key) { return GetState(key) == KeyState::Down; }

	//눌렀다가 땔 때 
	bool GetButtonUp(KeyType key) { return GetState(key) == KeyState::Up; }

	//마우스 좌표 얻기
	POINT GetMousePos() { return _mousePos; }


private:
	//현재 프레임에서 모든키상태벡터_states에서 'A' 65번이 어떤상태인지(0,1,2,3)중 반환
	KeyState GetState(KeyType key) { return _states[static_cast<uint8>(key)];}

private:
	HWND _hwnd = 0; 
	vector<KeyState> _states;//이전프레임의 모든 키들의 상태를 담은 벡터
	POINT _mousePos; //현재프레임에서의 마우스 위치 Update()에서 계속갱신되는중
};

