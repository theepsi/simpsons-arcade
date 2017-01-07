#include "ModuleSceneManager.h"
#include "Scene.h"

ModuleSceneManager::ModuleSceneManager() {

}

ModuleSceneManager::~ModuleSceneManager() {

}

bool ModuleSceneManager::Start() {
	return current_scene->Start();
}

update_status ModuleSceneManager::PreUpdate()
{
	return current_scene->PreUpdate();
}

update_status ModuleSceneManager::Update()
{
	return current_scene->Update();
}

update_status ModuleSceneManager::PostUpdate()
{
	return current_scene->PostUpdate();
}

bool ModuleSceneManager::CleanUp()
{
	LOG("Cleaning Scene objects");
	for (list<GameObject*>::iterator it = current_scene->game_objects.begin(); it != current_scene->game_objects.end(); ++it) {
		((GameObject*)*it)->CleanUp();
		RELEASE(*it);
	}
		

	return true;
}

void ModuleSceneManager::AddGameObjectToScene(GameObject* gameObject)
{
	current_scene->game_objects.push_back(gameObject);
	if (gameObject->type == GameObjectType::PLAYER_ENTITY) {
		players_available.push_back(gameObject);
	}
}

list<GameObject*> ModuleSceneManager::GetGameObjects()
{
	return current_scene->game_objects;
}

list<GameObject*> ModuleSceneManager::GetPlayersAvailable()
{
	return players_available;
}

void ModuleSceneManager::RemovePlayerOnScreen(GameObject* gameObject)
{
	players_available.remove(gameObject);
}

