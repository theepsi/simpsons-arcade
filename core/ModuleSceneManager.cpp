#include "ModuleSceneManager.h"
#include "Scene.h"
#include "../game/marge.h"
#include "../game/royd.h"
#include "../game/cementery.h"
#include "core.h"
#include "ModuleInput.h"
#include "ModuleRender.h"

ModuleSceneManager::ModuleSceneManager() {

}

ModuleSceneManager::~ModuleSceneManager() {

}

bool ModuleSceneManager::Start() {
	//call to prepareScene for the sample Scene.
	PrepareScene();
	return current_scene->Start();
}

update_status ModuleSceneManager::PreUpdate()
{
	if (current_scene != nullptr)
		return current_scene->PreUpdate();
	return UPDATE_CONTINUE;
}

update_status ModuleSceneManager::Update()
{
	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
	{
		PrepareScene();
		current_scene->Start();
	}
		
	if (current_scene != nullptr)
		return current_scene->Update();
	return UPDATE_CONTINUE;
}

update_status ModuleSceneManager::PostUpdate()
{
	if (current_scene != nullptr)
		return current_scene->PostUpdate();
	return UPDATE_CONTINUE;
}

bool ModuleSceneManager::CleanUp()
{
	if(current_scene != nullptr)
	{
		App->collision->CleanUp();
		current_scene->CleanUp();
		RELEASE(current_scene);
	}
	
	return true;
}

void ModuleSceneManager::AddGameObjectToScene(GameObject* gameObject)
{
	if(current_scene!=nullptr)
	{
		current_scene->game_objects.push_back(gameObject);
		if (gameObject->type == GameObjectType::PLAYER_ENTITY) {
			current_scene->players_available.push_back(gameObject);
		}
	}
}

list<GameObject*> ModuleSceneManager::GetGameObjects()
{
	return current_scene->game_objects;
}

list<GameObject*> ModuleSceneManager::GetPlayersAvailable()
{
	return current_scene->players_available;
}

void ModuleSceneManager::RemovePlayerOnScreen(GameObject* gameObject)
{
	current_scene->players_available.remove(gameObject);
}

void ModuleSceneManager::PrepareScene()
{
	App->renderer->camera.x = 0;
	App->renderer->camera.y = 0;
	CleanUp();
	current_scene = new Scene();
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

	AddGameObjectToScene(cement);
	AddGameObjectToScene(ui);
	AddGameObjectToScene(enemy_1);
	AddGameObjectToScene(enemy_2);
	AddGameObjectToScene(enemy_3);
	AddGameObjectToScene(player);
	AddSceneLimitations(1760, -20, 165, 88);
}

void ModuleSceneManager::AddSceneLimitations(const int& x_max, const int& x_min, const int& z_max, const int& z_min)
{
	current_scene->x_max = x_max;
	current_scene->x_min = x_min;
	current_scene->z_max = z_max;
	current_scene->z_min = z_min;
}


