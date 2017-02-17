#include "core.h"
#include "UI.h"

int main(int argc, char ** argv)
{
	ReportMemoryLeaks();

	LOG("Core Creation --------------");
	Core* App = new Core();	

	int main_return = App->GameLoop();

	RELEASE(App);

	LOG("Bye :)\n");
	return main_return;
}