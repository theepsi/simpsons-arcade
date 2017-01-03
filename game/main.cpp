#include "core.h"
#include "homer.h"
#include "marge.h"
#include "scene.h"

int main(int argc, char ** argv)
{
	ReportMemoryLeaks();

	Scene* scene = new Scene();
	Marge* player = new Marge();

	player->position.x = 0;
	player->position.y = 100;

	scene->game_objects.push_back(player);

	LOG("Core Creation --------------");
	Core* App = new Core();	

	App->scene_manager->current_scene = scene;

	int main_return = App->GameLoop();

	player->CleanUp();
	RELEASE(player);
	RELEASE(scene);
	RELEASE(App);

	LOG("Bye :)\n");
	return main_return;
}