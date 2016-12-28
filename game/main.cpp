#include "core.h"

int main(int argc, char ** argv)
{
	ReportMemoryLeaks();

	LOG("Core Creation --------------");
	Core* App = new Core();
	
	int main_return = App->GameLoop();

	LOG("Bye :)\n");
	return main_return;
}