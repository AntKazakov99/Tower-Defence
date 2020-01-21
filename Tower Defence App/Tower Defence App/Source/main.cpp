#include "Application.h"

int main(int argc, char* argv[])
{
	Application app;
	Window* win = new Window();
	win->Initialize();
	app.SetMainWindow(win);
	app.Run();
	return 0;
}