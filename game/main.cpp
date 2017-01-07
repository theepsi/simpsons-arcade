#include "core.h"
#include "homer.h"
#include "marge.h"
#include "cementery.h"
#include "scene.h"

int main(int argc, char ** argv)
{
	ReportMemoryLeaks();

	Scene* scene = new Scene();
	Marge* player = new Marge();
	Cementery* cement = new Cementery();

	player->position.x = 0;
	player->position.y = 0;
	player->position.z = 100;
	
	scene->game_objects.push_back(cement);
	scene->game_objects.push_back(player);

	LOG("Core Creation --------------");
	Core* App = new Core();	

	App->scene_manager->current_scene = scene;

	int main_return = App->GameLoop();

	player->CleanUp();
	//TODO: Scene Manager call clean of all their objects
	RELEASE(player);
	RELEASE(cement->section);
	RELEASE(cement);

	RELEASE(scene);
	RELEASE(App);

	LOG("Bye :)\n");
	return main_return;
}