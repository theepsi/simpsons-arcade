#ifndef _SCENE_MANAGER
#define _SCENE_MANAGER

#include "Globals.h"
#include "Module.h"
#include "gameObject.h"
#include <list>

using namespace std;

class Player;
class Scene;

class ModuleSceneManager : public Module {
public:
	ModuleSceneManager();
	~ModuleSceneManager();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();

	bool CleanUp();

	Scene* current_scene = nullptr;

	//Scene functions
	void AddGameObjectToScene(GameObject* gameObject);
	list<GameObject*> GetGameObjects();
	list<GameObject*> GetPlayersAvailable();
	void RemovePlayerOnScreen(GameObject* gameObject);
	void PrepareScene();

	void AddSceneLimitations(const int& x_max, const int& x_min, const int& z_max, const int& z_min);
};


#endif

