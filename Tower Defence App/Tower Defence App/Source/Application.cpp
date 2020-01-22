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
			switch (e.window.event)
			{
			case SDL_WindowEventID::SDL_WINDOWEVENT_SHOWN:
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_HIDDEN:
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_EXPOSED:
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_MOVED:
				for (int i = 0; i < windows.size(); i++)
				{
					if (e.window.windowID == windows[i]->GetID())
					{
						windows[i]->InvokeWindowEventMoved(e.window);
					}
				}
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_RESIZED:
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_SIZE_CHANGED:
				for (int i = 0; i < windows.size(); i++)
				{
					if (e.window.windowID == windows[i]->GetID())
					{
						windows[i]->InvokeWindowEventSizeChanged(e.window);
					}
				}
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_MINIMIZED:
				for (int i = 0; i < windows.size(); i++)
				{
					if (e.window.windowID == windows[i]->GetID())
					{
						windows[i]->InvokeWindowEventMinimized(e.window);
					}
				}
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_MAXIMIZED:
				for (int i = 0; i < windows.size(); i++)
				{
					if (e.window.windowID == windows[i]->GetID())
					{
						windows[i]->InvokeWindowEventMaximized(e.window);
					}
				}
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_RESTORED:
				for (int i = 0; i < windows.size(); i++)
				{
					if (e.window.windowID == windows[i]->GetID())
					{
						windows[i]->InvokeWindowEventRestored(e.window);
					}
				}				
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_ENTER:
				for (int i = 0; i < windows.size(); i++)
				{
					if (e.window.windowID == windows[i]->GetID())
					{
						windows[i]->InvokeWindowEventEnter(e.window);
					}
				}
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_LEAVE:
				for (int i = 0; i < windows.size(); i++)
				{
					if (e.window.windowID == windows[i]->GetID())
					{
						windows[i]->InvokeWindowEventLeave(e.window);
					}
				}
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_FOCUS_GAINED:
				for (int i = 0; i < windows.size(); i++)
				{
					if (e.window.windowID == windows[i]->GetID())
					{
						windows[i]->InvokeWindowEventFocusGained(e.window);
					}
				}
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_FOCUS_LOST:
				for (int i = 0; i < windows.size(); i++)
				{
					if (e.window.windowID == windows[i]->GetID())
					{
						windows[i]->InvokeWindowEventFocusLost(e.window);
					}
				}
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_CLOSE:
				for (int i = 0; i < windows.size(); i++)
				{
					if (e.window.windowID == windows[i]->GetID())
					{
						windows[i]->InvokeWindowEventClose(e.window);
						Window* deletedWindow = windows[i];
						for (int j = 0; j < windows.size(); j++)
						{
							if (windows[j] == deletedWindow)
							{
								windows.erase(windows.cbegin() + j--);
							}
						}
						delete deletedWindow;
					}
				}
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_TAKE_FOCUS:
				break;
			case SDL_WindowEventID::SDL_WINDOWEVENT_HIT_TEST:
				break;
			}
			break;

		case SDL_EventType::SDL_KEYDOWN:
			for (int i = 0; i < windows.size(); i++)
			{
				if (e.window.windowID == windows[i]->GetID())
				{
					windows[i]->InvokeEventKeyDown(e.key);
				}
			}
			break;
		case SDL_EventType::SDL_KEYUP:
			for (int i = 0; i < windows.size(); i++)
			{
				if (e.window.windowID == windows[i]->GetID())
				{
					windows[i]->InvokeEventKeyUp(e.key);
				}
			}
			break;
		case SDL_EventType::SDL_TEXTEDITING:
			cout << "SDL event type: Text editing event\n";
			break;
		case SDL_EventType::SDL_TEXTINPUT:
			for (int i = 0; i < windows.size(); i++)
			{
				if (e.window.windowID == windows[i]->GetID())
				{
					windows[i]->InvokeEventTextInput(e.text);
				}
			}
			break;
		case SDL_EventType::SDL_KEYMAPCHANGED:
			cout << "SDL event type: Key map changing event\n";
			break;

		case SDL_EventType::SDL_MOUSEMOTION:
			for (int i = 0; i < windows.size(); i++)
			{
				if (e.window.windowID == windows[i]->GetID())
				{
					windows[i]->InvokeEventMouseMotion(e.button);
				}
			}
			break;
		case SDL_EventType::SDL_MOUSEBUTTONDOWN:
			for (int i = 0; i < windows.size(); i++)
			{
				if (e.window.windowID == windows[i]->GetID())
				{
					windows[i]->InvokeEventMouseButtonDown(e.button);
				}
			}
			break;
		case SDL_EventType::SDL_MOUSEBUTTONUP:
			for (int i = 0; i < windows.size(); i++)
			{
				if (e.window.windowID == windows[i]->GetID())
				{
					windows[i]->InvokeEventMouseButtonUp(e.button);
				}
			}
			break;
		case SDL_EventType::SDL_MOUSEWHEEL:
			for (int i = 0; i < windows.size(); i++)
			{
				if (e.window.windowID == windows[i]->GetID())
				{
					windows[i]->InvokeEventMouseWheel(e.button);
				}
			}
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
	IMG_Init(
		IMG_InitFlags::IMG_INIT_JPG |
		IMG_InitFlags::IMG_INIT_PNG
	);
}

void Application::Run()
{
	// Цикл работы приложения
	while (running)
	{
		EventHandling();
		for (int i = 0; i < windows.size(); i++)
		{
			windows[i]->UpdateLayout();
		}

	}
}

void Application::AddWindow(Window* window)
{
	windows.push_back(window);
}
