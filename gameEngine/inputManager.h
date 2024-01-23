#pragma once
enum class KeyType
{
	//ã�� ���ϰ� �������ֱ� 
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
/// ŰŸ�� ������ Ű���� ���� �̳����� ���� 
/// </summary>
enum
{
	KEY_TYPE_COUNT = static_cast<int32>(UINT8_MAX) + 1,//256�� ��Ÿ�� 
	KEY_STATE_COUNT = static_cast<int32>(KeyState::End),
};

class InputManager
{
	DECLARE_SINGLE(InputManager)

public:
	//������â ���� �������� 
	void Init(HWND hwnd);
	void Update();

	//������ ���� ��
	bool GetButton(KeyType key){ return GetState(key) == KeyState::Press; }

	//�����¿��� ������ ��
	bool GetButtonDown(KeyType key) { return GetState(key) == KeyState::Down; }

	//�����ٰ� �� �� 
	bool GetButtonUp(KeyType key) { return GetState(key) == KeyState::Up; }

	//���콺 ��ǥ ���
	POINT GetMousePos() { return _mousePos; }


private:
	//���� �����ӿ��� ���Ű���º���_states���� 'A' 65���� ���������(0,1,2,3)�� ��ȯ
	KeyState GetState(KeyType key) { return _states[static_cast<uint8>(key)];}

private:
	HWND _hwnd = 0; 
	vector<KeyState> _states;//������������ ��� Ű���� ���¸� ���� ����
	POINT _mousePos; //���������ӿ����� ���콺 ��ġ Update()���� ��Ӱ��ŵǴ���
};

