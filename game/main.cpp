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

	LOG("Core Creation --------------");
	Core* App = new Core();	

	App->scene_manager->current_scene = scene;
	App->scene_manager->AddGameObjectToScene(cement);
	App->scene_manager->AddGameObjectToScene(enemy_1);
	App->scene_manager->AddGameObjectToScene(player);
	App->scene_manager->AddSceneLimitations(2200, -20, 165, 88);

	int main_return = App->GameLoop();

	RELEASE(scene);
	RELEASE(App);

	LOG("Bye :)\n");
	return main_return;
}