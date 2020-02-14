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
				running = false;
			break;
		case SDL_EventType::SDL_DISPLAYEVENT:
			switch (e.display.event)
			{
			case SDL_DisplayEventID::SDL_DISPLAYEVENT_NONE:
				break;
			case SDL_DisplayEventID::SDL_DISPLAYEVENT_ORIENTATION:
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
			break;

		case SDL_EventType::SDL_MOUSEMOTION:
			for (int i = 0; i < windows.size(); i++)
			{
				if (e.window.windowID == windows[i]->GetID())
				{
					windows[i]->InvokeEventMouseMotion(e.motion);
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
					windows[i]->InvokeEventMouseWheel(e.wheel);
				}
			}
			break;

		case SDL_EventType::SDL_JOYAXISMOTION:
			break;
		case SDL_EventType::SDL_JOYBALLMOTION:
			break;
		case SDL_EventType::SDL_JOYHATMOTION:
			break;
		case SDL_EventType::SDL_JOYBUTTONDOWN:
			break;
		case SDL_EventType::SDL_JOYBUTTONUP:
			break;
		case SDL_EventType::SDL_JOYDEVICEADDED:
			break;
		case SDL_EventType::SDL_JOYDEVICEREMOVED:
			break;

		case SDL_EventType::SDL_CONTROLLERAXISMOTION:
			break;
		case SDL_EventType::SDL_CONTROLLERBUTTONDOWN:
			break;
		case SDL_EventType::SDL_CONTROLLERBUTTONUP:
			break;
		case SDL_EventType::SDL_CONTROLLERDEVICEADDED:
			break;
		case SDL_EventType::SDL_CONTROLLERDEVICEREMOVED:
			break;
		case SDL_EventType::SDL_CONTROLLERDEVICEREMAPPED:
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
	TTF_Init();
}

void Application::Run()
{
	// Цикл работы приложения
	while (running)
	{
		EventHandling();
		int tick = SDL_GetTicks();
		for (int i = 0; i < windows.size(); i++)
		{
			windows[i]->InvokeEventTick(tick - lastTick);
			windows[i]->UpdateLayout();
		}
		lastTick = tick;
	}
}

void Application::AddWindow(Window* window)
{
	windows.push_back(window);
}
