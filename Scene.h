#pragma once

class Scene
{
private:
	enum SCENE {
		TITLE,
		PLAY,
	};
	SCENE scene_;
	
public:
	Scene();
	int getCurrentScene();
	void SceneUpdate();
};


