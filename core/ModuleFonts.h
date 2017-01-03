#ifndef _MODULE_FONTS
#define _MODULE_FONTS

#include "Module.h"
#include "Globals.h"

using namespace std;

struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Rect;

class ModuleFonts : public Module
{
public:
	struct Font {
		SDL_Texture* texture;
		string mask;
		int id;
	};
	ModuleFonts();
	~ModuleFonts();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

	bool Blit(int x, int y, Font* font, const string& text);
	Font* Load(const char* path, const string& mask, int id);

	list<Font*> fonts;
	SDL_Renderer* renderer = nullptr;

};

#endif

