#include "Application.h"
#include "GameWindow.h"

int main(int argc, char* argv[])
{
	Application app;
	app.AddWindow(new GameWindow());
	app.Run();
	return 0;
}