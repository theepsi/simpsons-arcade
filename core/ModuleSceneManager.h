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

	Scene* current_scene;

	//Scene functions
	void AddGameObjectToScene(GameObject* gameObject);
	list<GameObject*> GetGameObjects();
	list<GameObject*> GetPlayersAvailable();
	void RemovePlayerOnScreen(GameObject* gameObject);

	list<GameObject*> players_available;
};


#endif

