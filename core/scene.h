#ifndef _SCENE
#define _SCENE

#include "Module.h"
#include "gameObject.h"
#include <list>

using namespace std;

struct SDL_Texture;

class Scene : public Module {
public:
	Scene() {}
	virtual ~Scene() {}

	bool Start() override
	{
		bool ret = true;
		for (std::list<GameObject*>::iterator it = game_objects.begin(); it != game_objects.end() && ret; ++it)
			if ((*it)->IsEnabled())
				(*it)->Start();
		return ret;
	}

	update_status PreUpdate()
	{
		for (std::list<GameObject*>::iterator it = game_objects.begin(); it != game_objects.end(); ++it)
			if ((*it)->IsEnabled())
				(*it)->PreUpdate();
		return UPDATE_CONTINUE;
	}

	update_status Update()
	{
		for (std::list<GameObject*>::iterator it = game_objects.begin(); it != game_objects.end(); ++it)
			if ((*it)->IsEnabled())
				(*it)->Update();
		return UPDATE_CONTINUE;
	}

	update_status PostUpdate()
	{
		for (std::list<GameObject*>::iterator it = game_objects.begin(); it != game_objects.end(); ++it)
			if ((*it)->IsEnabled())
				(*it)->PostUpdate();
		return UPDATE_CONTINUE;
	}

	bool CleanUp()
	{
		LOG("Cleaning Scene objects");
		for (list<GameObject*>::iterator it = game_objects.begin(); it != game_objects.end(); ++it) {
			(*it)->CleanUp();
			RELEASE(*it);
		}
		game_objects.clear();
		return true;
	}

	list<GameObject*> game_objects;
	list<GameObject*> players_available;

	int x_max;
	int x_min;
	int z_max;
	int z_min;
};

#endif

