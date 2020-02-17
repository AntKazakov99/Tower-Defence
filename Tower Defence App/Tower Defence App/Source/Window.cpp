#include "Window.h"

Window::~Window()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void Window::InvokeEventTick(Uint32 deltaTime)
{
	if (Tick)
	{
		Tick(this, deltaTime);
	}
	for (int i = 0; i < timers.size(); i++)
	{
		timers[i]->InvokeEventTick(this, deltaTime);
	}
}

void Window::InvokeWindowEventMoved(SDL_WindowEvent e)
{
	if (LocationChanged)
	{
		LocationChanged(this, e);
	}
}

void Window::InvokeWindowEventSizeChanged(SDL_WindowEvent e)
{
	SDL_GetWindowSize(window, &width, &height);
	if (SizeChanged)
	{
		SizeChanged(this, e);
	}
}

void Window::InvokeWindowEventMinimized(SDL_WindowEvent e)
{
	windowState = WindowState::Minimized;
	if (StateChanged)
	{
		StateChanged(this, e);
	}
}

void Window::InvokeWindowEventMaximized(SDL_WindowEvent e)
{
	windowState = WindowState::Maximized;
	if (StateChanged)
	{
		StateChanged(this, e);
	}
}

void Window::InvokeWindowEventRestored(SDL_WindowEvent e)
{
	windowState = WindowState::Restored;
	if (StateChanged)
	{
		StateChanged(this, e);
	}
}

void Window::InvokeWindowEventEnter(SDL_WindowEvent e)
{
	if (MouseEnter)
	{
		MouseEnter(this, e);
	}
}

void Window::InvokeWindowEventLeave(SDL_WindowEvent e)
{
	if (MouseLeave)
	{
		MouseLeave(this, e);
	}
}

void Window::InvokeWindowEventFocusGained(SDL_WindowEvent e)
{
	if (Activated)
	{
		Activated(this, e);
	}
}

void Window::InvokeWindowEventFocusLost(SDL_WindowEvent e)
{
	if (Deactivated)
	{
		Deactivated(this, e);
	}
}

void Window::InvokeWindowEventClose(SDL_WindowEvent e)
{
	if (Closed)
	{
		Closed(this, e);
	}
}

void Window::InvokeEventKeyDown(SDL_KeyboardEvent e)
{
	if (KeyDown)
	{
		KeyDown(this, e);
	}
}

void Window::InvokeEventKeyUp(SDL_KeyboardEvent e)
{
	if (KeyUp)
	{
		KeyUp(this, e);
	}
}

void Window::InvokeEventTextInput(SDL_TextInputEvent e)
{
	if (TextInput)
	{
		TextInput(this, e);
	}
}

void Window::InvokeEventMouseMotion(SDL_MouseMotionEvent e)
{
	if (MouseMove)
	{
		MouseMove(this, e);
	}
	for (int i = 0; i < vElements.size(); i++)
	{
		if (vElements[i]->GetIsVisible())
		{
			vElements[i]->InvokeEventMouseMotion(this, e);
		}
	}
}

void Window::InvokeEventMouseButtonDown(SDL_MouseButtonEvent e)
{
	if (MouseDown)
	{
		MouseDown(this, e);
	}
	for (int i = 0; i < vElements.size(); i++)
	{
		if (vElements[i]->GetIsVisible())
		{
			vElements[i]->InvokeEventMouseButtonDown(this, e);
		}
	}
}

void Window::InvokeEventMouseButtonUp(SDL_MouseButtonEvent e)
{
	if (MouseUp)
	{
		MouseUp(this, e);
	}
	for (int i = 0; i < vElements.size(); i++)
	{
		if (vElements[i]->GetIsVisible())
		{
			vElements[i]->InvokeEventMouseButtonUp(this, e);
		}
	}
}

void Window::InvokeEventMouseWheel(SDL_MouseWheelEvent e)
{
	if (MouseWheel)
	{
		MouseWheel(this, e);
	}
	for (int i = 0; i < vElements.size(); i++)
	{
		if (vElements[i]->GetIsVisible())
		{
			vElements[i]->InvokeEventMouseWheel(this, e);
		}
	}
}

void Window::SetTick(void Tick(Object* sender, Uint32 deltaTime))
{
	this->Tick = Tick;
}

void Window::SetLocationChanged(void LocationChanged(Object* sender, SDL_WindowEvent e))
{
	this->LocationChanged = LocationChanged;
}

void Window::SetSizeChanged(void SizeChanged(Object* sender, SDL_WindowEvent e))
{
	this->SizeChanged = SizeChanged;
}

void Window::SetStateChanged(void StateChanged(Object* sender, SDL_WindowEvent e))
{
	this->StateChanged = StateChanged;
}

void Window::SetMouseEnter(void MouseEnter(Object* sender, SDL_WindowEvent e))
{
	this->MouseEnter = MouseEnter;
}

void Window::SetMouseLeave(void MouseLeave(Object* sender, SDL_WindowEvent e))
{
	this->MouseLeave = MouseLeave;
}

void Window::SetActivated(void Activated(Object* sender, SDL_WindowEvent e))
{
	this->Activated = Activated;
}

void Window::SetDeactivated(void Deactivated(Object* sender, SDL_WindowEvent e))
{
	this->Deactivated = Deactivated;
}

void Window::SetClosed(void Closed(Object* sender, SDL_WindowEvent e))
{
	this->Closed = Closed;
}

void Window::SetKeyDown(void KeyDown(Object* sender, SDL_KeyboardEvent e))
{
	this->KeyDown = KeyDown;
}

void Window::SetKeyUp(void KeyUp(Object* sender, SDL_KeyboardEvent e))
{
	this->KeyUp = KeyUp;
}

void Window::SetTextInput(void TextInput(Object* sender, SDL_TextInputEvent e))
{
	this->TextInput = TextInput;
}

void Window::SetMouseMove(void MouseMove(Object* sender, SDL_MouseMotionEvent e))
{
	this->MouseMove = MouseMove;
}

void Window::SetMouseDown(void MouseDown(Object* sender, SDL_MouseButtonEvent e))
{
	this->MouseDown = MouseDown;
}

void Window::SetMouseUp(void MouseUp(Object* sender, SDL_MouseButtonEvent e))
{
	this->MouseDown = MouseDown;
}

void Window::SetMouseWheel(void MouseWheel(Object* sender, SDL_MouseWheelEvent e))
{
	this->MouseDown = MouseDown;
}

void Window::Initialize()
{
	// Создает окно
	if (!window)
	{
		window = SDL_CreateWindow(
			title.c_str(),
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			width,
			height,
			windowMode |
			windowState |
			SDL_WINDOW_SHOWN
		);
	}
	renderer = SDL_CreateRenderer(
		window,
		-1,
		SDL_RendererFlags::SDL_RENDERER_ACCELERATED |
		(vSync ? SDL_RendererFlags::SDL_RENDERER_PRESENTVSYNC : 0)
	);
}

void Window::UpdateLayout()
{
	SDL_RenderClear(renderer);
	for (int i = 0; i < vElements.size(); i++)
	{
		if (vElements[i]->GetVisualResource() && vElements[i]->GetIsVisible())
		{
			if (vElements[i]->GetVisualResource()->GetIsUpdated())
			{
				vElements[i]->GetVisualResource()->UpdateTexture(renderer);
			}
			SDL_RenderCopy(
				renderer,
				vElements[i]->GetVisualResource()->GetTexture(),
				vElements[i]->GetSourceRectangle(),
				vElements[i]->GetDestinationRectangle()
			);
		}
	}
	SDL_RenderPresent(renderer);
}

int Window::GetID()
{
	return SDL_GetWindowID(window);
}

const char* Window::GetTitle()
{
	return title.c_str();
}

void Window::SetTitle(string title)
{
	this->title = title;
	if (window)
	{
		SDL_SetWindowTitle(window, title.c_str());
	}
}

const int Window::GetWidth()
{
	return width;
}

void Window::SetWidth(int width)
{
	if (window)
	{
		SDL_SetWindowSize(window, width, height);
	}
}

const int Window::GetHeight()
{
	return height;
}

void Window::SetHeight(int height)
{
	if (height)
	{
		SDL_SetWindowSize(window, width, height);
	}
}

WindowMode Window::GetWindowMode()
{
	return windowMode;
}

void Window::SetWindowMode(WindowMode windowMode)
{
	this->windowMode = windowMode;
	if (window)
	{
		SDL_SetWindowFullscreen(window, windowMode);
	}
}

WindowState Window::GetWindowState()
{
	return windowState;
}

void Window::SetWindowState(WindowState windowState)
{
	if (window)
	{
		switch (windowState)
		{
		case Restored:
			SDL_RestoreWindow(window);
			break;
		case Minimized:
			SDL_MinimizeWindow(window);
			break;
		case Maximized:
			SDL_MaximizeWindow(window);
			break;
		}
	}
}

bool Window::GetVSync()
{
	return vSync;
}

void Window::SetVSync(bool vSync)
{
	this->vSync = vSync;
	Initialize();
}

void Window::AddVisualElement(VisualElement* vElement)
{
	bool inserted = false;
	for (int i = 0; i < vElements.size(); i++)
	{
		if (!inserted && vElements[i]->GetZIndex() > vElement->GetZIndex())
		{
			vElements.insert(vElements.begin() + i, vElement);
			inserted = true;
		}
	}
	if (!inserted)
	{
		vElements.push_back(vElement);
	}
}

void Window::RemoveVisualElement(VisualElement* vElement)
{
	for (int i = 0; i < vElements.size(); i++)
	{
		if (vElements[i]  == vElement)
		{
			vElements.erase(vElements.begin() + i--);
		}
	}
}

void Window::AddTimer(Timer* timer)
{
	bool inserted = false;
	for (int i = 0; i < timers.size(); i++)
	{
		if (timers[i] == timer)
		{
			inserted = true;
		}
	}
	if (!inserted)
	{
		timers.push_back(timer);
	}
}

void Window::RemoveTimer(Timer* timer)
{
	for (int i = 0; i < timers.size(); i++)
	{
		if (timers[i] == timer)
		{
			timers.erase(timers.begin() + i--);
		}
	}
}
