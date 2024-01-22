#pragma once
class SceneManager
{
	DECLARE_SINGLE(SceneManager); //static으로 데이터 영역에 객체 만들기
public:
	void Init();
	void Update();
	void Render(HDC hdc);

	//씬매니저에서 씬들 타입변경할 때 
	void ChangeScene(SceneType sceneType);

	//Clear
	void Clear();

private:
	class Scene* _scene; //전방선언도 동시에 포함하는 ## 
	SceneType _sceneType = SceneType::None;//씬매니저가 현재 들고 있는 씬 
	

};

