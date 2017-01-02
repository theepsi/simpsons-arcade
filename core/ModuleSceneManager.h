#ifndef _SCENE_MANAGER
#define _SCENE_MANAGER

#include "Globals.h"
#include "Module.h"
#include "gameObject.h"

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
};


#endif

