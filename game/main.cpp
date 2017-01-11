#include "core.h"
#include "homer.h"
#include "royd.h"
#include "marge.h"
#include "cementery.h"
#include "scene.h"
#include "UI.h"

int main(int argc, char ** argv)
{
	ReportMemoryLeaks();

	Scene* scene = new Scene();
	Marge* player = new Marge();
	Royd* enemy_1 = new Royd();
	Royd* enemy_2 = new Royd();
	Royd* enemy_3 = new Royd();
	Cementery* cement = new Cementery();
	UI* ui = new UI();
	player->AttachUI(ui);

	//TODO: just testing, need to load enemys when aproaching...
	enemy_1->position.x = 300;
	enemy_1->position.y = 0;
	enemy_1->position.z = 102;

	enemy_2->position.x = 80;
	enemy_2->position.y = 0;
	enemy_2->position.z = 120;

	enemy_3->position.x = 200;
	enemy_3->position.y = 0;
	enemy_3->position.z = 150;
	
	LOG("Core Creation --------------");
	Core* App = new Core();	

	App->scene_manager->current_scene = scene;
	App->scene_manager->AddGameObjectToScene(cement);
	App->scene_manager->AddGameObjectToScene(ui);
	App->scene_manager->AddGameObjectToScene(enemy_1);
	App->scene_manager->AddGameObjectToScene(enemy_2);
	App->scene_manager->AddGameObjectToScene(enemy_3);
	App->scene_manager->AddGameObjectToScene(player);
	App->scene_manager->AddSceneLimitations(2200, -20, 165, 88);

	int main_return = App->GameLoop();

	RELEASE(scene);
	RELEASE(App);

	LOG("Bye :)\n");
	return main_return;
}