#pragma once
class SceneManager
{
	DECLARE_SINGLE(SceneManager); //static���� ������ ������ ��ü �����
public:
	void Init();
	void Update();
	void Render(HDC hdc);

	//���Ŵ������� ���� Ÿ�Ժ����� �� 
	void ChangeScene(SceneType sceneType);

	//Clear
	void Clear();

private:
	class Scene* _scene; //���漱�� ���ÿ� �����ϴ� ## 
	SceneType _sceneType = SceneType::None;//���Ŵ����� ���� ��� �ִ� �� 
	

};

