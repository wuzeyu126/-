#include "Scene.h"

Scene::Scene()
{
	scene_ = TITLE;
}

int Scene::getCurrentScene()
{
	return scene_;
}

void Scene::SceneUpdate()
{
	
		scene_ = PLAY;
	
}


