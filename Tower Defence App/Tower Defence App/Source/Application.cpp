#include "Application.h"

void Application::EventHandling()
{
	// Содержит информацию о событии
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_EventType::SDL_QUIT:
			cout << "SDL event type: Quit event\n";
			running = false;
			break;
		case SDL_EventType::SDL_DISPLAYEVENT:
			cout << "SDL event type: Display event - ";
			switch (e.display.event)
			{
			case SDL_DisplayEventID::SDL_DISPLAYEVENT_NONE:
				cout << "None\n";
				break;
			case SDL_DisplayEventID::SDL_DISPLAYEVENT_ORIENTATION:
				cout << "Orientation\n";
				break;
			}
			break;
		case SDL_EventType::SDL_WINDOWEVENT:
			cout << "SDL event type: Window event - ";
			switch (e.window.event)
			{
			case SDL_WindowEventID::SDL_WINDOWEVENT_SHOWN:
				cout << "Shown\n";
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_HIDDEN:
				cout << "Hidden\n";
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_EXPOSED:
				cout << "Exposed\n";
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_MOVED:
				cout << "Moved\n";
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_RESIZED:
				cout << "Resized\n";
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_SIZE_CHANGED:
				cout << "Size changed\n";
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_MINIMIZED:
				cout << "Minimized\n";
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_MAXIMIZED:
				cout << "Maximized\n";
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_RESTORED:
				cout << "Restored\n";
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_ENTER:
				cout << "Enter\n";
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_LEAVE:
				cout << "Leave\n";
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_FOCUS_GAINED:
				cout << "Focus gained\n";
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_FOCUS_LOST:
				cout << "Focus lost\n";
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_CLOSE:
				cout << "Close\n";
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_TAKE_FOCUS:
				cout << "Take focus\n";
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_HIT_TEST:
				cout << "Hit test\n";
				break;
			}
			break;
		case SDL_EventType::SDL_KEYDOWN:
			cout << "SDL event type: Key down event\n";
			break;
		case SDL_EventType::SDL_KEYUP:
			cout << "SDL event type: Key up event\n";
			break;
		case SDL_EventType::SDL_TEXTEDITING:
			cout << "SDL event type: Text editing event\n";
			break;
		case SDL_EventType::SDL_TEXTINPUT:
			cout << "SDL event type: Text input event\n";
			break;
		case SDL_EventType::SDL_KEYMAPCHANGED:
			cout << "SDL event type: Key map changing event\n";
			break;
		case SDL_EventType::SDL_MOUSEMOTION:
			cout << "SDL event type: Mouse motion event\n";
			break;
		case SDL_EventType::SDL_MOUSEBUTTONDOWN:
			cout << "SDL event type: Mouse button down event\n";
			break;
		case SDL_EventType::SDL_MOUSEBUTTONUP:
			cout << "SDL event type: Mouse button up event\n";
			break;
		case SDL_EventType::SDL_MOUSEWHEEL:
			cout << "SDL event type: Mouse wheel event\n";
			break;
		case SDL_EventType::SDL_JOYAXISMOTION:
			cout << "SDL event type: Joystick axis motion event\n";
			break;
		case SDL_EventType::SDL_JOYBALLMOTION:
			cout << "SDL event type: Joystick trackball motion event\n";
			break;
		case SDL_EventType::SDL_JOYHATMOTION:
			cout << "SDL event type: Joystick hat position change event\n";
			break;
		case SDL_EventType::SDL_JOYBUTTONDOWN:
			cout << "SDL event type: Joystick button down event\n";
			break;
		case SDL_EventType::SDL_JOYBUTTONUP:
			cout << "SDL event type: Joystick button up event\n";
			break;
		case SDL_EventType::SDL_JOYDEVICEADDED:
			cout << "SDL event type: Joystick device added event\n";
			break;
		case SDL_EventType::SDL_JOYDEVICEREMOVED:
			cout << "SDL event type: Joystick device removed event\n";
			break;
		case SDL_EventType::SDL_CONTROLLERAXISMOTION:
			cout << "SDL event type: Game controller axis motion event\n";
			break;
		case SDL_EventType::SDL_CONTROLLERBUTTONDOWN:
			cout << "SDL event type: Game controller button down event\n";
			break;
		case SDL_EventType::SDL_CONTROLLERBUTTONUP:
			cout << "SDL event type: Game controller button up event\n";
			break;
		case SDL_EventType::SDL_CONTROLLERDEVICEADDED:
			cout << "SDL event type: Game controller device added event\n";
			break;
		case SDL_EventType::SDL_CONTROLLERDEVICEREMOVED:
			cout << "SDL event type: Game controller device removed event\n";
			break;
		case SDL_EventType::SDL_CONTROLLERDEVICEREMAPPED:
			cout << "SDL event type: Game controller device remapped event\n";
			break;

			// Other events

		}
	}
}

Application::Application()
{
	SDL_Init(SDL_INIT_EVERYTHING);
}

void Application::Run()
{
	// Цикл работы приложения
	while (running)
	{
		EventHandling();
	}
}

void Application::SetMainWindow(Window* window)
{
	mainWindow = window;
}
