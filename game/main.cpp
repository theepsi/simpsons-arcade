#include "core.h"
#include "homer.h"
#include "royd.h"
#include "marge.h"
#include "cementery.h"
#include "scene.h"

int main(int argc, char ** argv)
{
	ReportMemoryLeaks();

	Scene* scene = new Scene();
	Marge* player = new Marge();
	Royd* enemy_1 = new Royd();
	Cementery* cement = new Cementery();

	
	/*scene->game_objects.push_back(cement);
	scene->game_objects.push_back(player);
	scene->game_objects.push_back(enemy_1);*/

	LOG("Core Creation --------------");
	Core* App = new Core();	

	App->scene_manager->current_scene = scene;
	App->scene_manager->AddGameObjectToScene(cement);
	App->scene_manager->AddGameObjectToScene(player);
	App->scene_manager->AddGameObjectToScene(enemy_1);

	int main_return = App->GameLoop();

	player->CleanUp();
	enemy_1->CleanUp();
	//TODO: Scene Manager call clean of all their objects
	RELEASE(player);
	RELEASE(enemy_1);
	RELEASE(cement->section);
	RELEASE(cement);

	RELEASE(scene);
	RELEASE(App);

	LOG("Bye :)\n");
	return main_return;
}