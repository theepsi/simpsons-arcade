#ifndef __CORE_CPP__
#define __CORE_CPP__

#include<list>
#include "Globals.h"
#include "Module.h"
#include "ModuleSceneManager.h"

#include "SDL/include/SDL.h"

#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

class ModuleRender;
class ModuleWindow;
class ModuleTextures;
class ModuleInput;
class ModuleAudio;
class ModuleFadeToBlack;
class ModuleCollision;
class ModuleParticles;
class ModuleFonts;

// Game modules ---

class Core
{
public:

	enum main_states
	{
		MAIN_CREATION,
		MAIN_START,
		MAIN_UPDATE,
		MAIN_FINISH,
		MAIN_EXIT
	};

	Core();
	~Core();

	bool Init();
	update_status Update();
	bool CleanUp();

	int GameLoop();

public:
	ModuleRender* renderer;
	ModuleWindow* window;
	ModuleTextures* textures;
	ModuleInput* input;
	ModuleAudio* audio;
	ModuleFadeToBlack* fade;
	ModuleCollision* collision;
	ModuleParticles* particles;
	ModuleFonts* fonts;

	// Game modules ---
	ModuleSceneManager* scene_manager;

private:
	main_states state;
	std::list<Module*> modules;
};

extern Core* App;

#endif // __CORE_CPP__
