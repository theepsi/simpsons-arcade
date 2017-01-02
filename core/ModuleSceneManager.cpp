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