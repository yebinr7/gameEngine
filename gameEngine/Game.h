#pragma once
class Game
{
public:
	Game();
	~Game();

public:
	//�ʱ�ȭ �ϴ� �Լ�
	void Init(HWND hwnd);
	//�������� ������Ʈ �ϴ��Լ�
	void Update();
	//�׷��ִ� �Լ�
	void Render();

private:
	HWND _hwnd = {};
	HDC	 _hdc = {};

private:
	//���� ���۸�
	RECT _rect; //���� �׸��� ����
	HDC _hdcBack = {};//�����
	HBITMAP _bmpBack = {};
};

