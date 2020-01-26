#include "Window.h"

void Window::Tick(int deltaTime)
{
	// virtual
}

void Window::LocationChanged(SDL_WindowEvent e)
{
	// virtual
}

void Window::SizeChanged(SDL_WindowEvent e)
{
	// virtual
}

void Window::StateChanged(SDL_WindowEvent e)
{
	// virtual
}

void Window::MouseEnter(SDL_WindowEvent e)
{
	// virtual
}

void Window::MouseLeave(SDL_WindowEvent e)
{
	// virtual
}

void Window::Activated(SDL_WindowEvent e)
{
	// virtual
}

void Window::Deactivated(SDL_WindowEvent e)
{
	// virtual
}

void Window::Closed(SDL_WindowEvent e)
{
	// virtual
}

void Window::KeyDown(SDL_KeyboardEvent e)
{
	// virtual
}

void Window::KeyUp(SDL_KeyboardEvent e)
{
	// virtual
}

void Window::TextInput(SDL_TextInputEvent e)
{
	// virtual
}

void Window::MouseMove(SDL_MouseMotionEvent e)
{
	// virtual
}

void Window::MouseDown(SDL_MouseButtonEvent e)
{
	// virtual
}

void Window::MouseUp(SDL_MouseButtonEvent e)
{
	// virtual
}

void Window::MouseWheel(SDL_MouseWheelEvent e)
{
	// virtual
}

Window::~Window()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void Window::InvokeWindowEventMoved(SDL_WindowEvent e)
{
	this->LocationChanged(e);
}

void Window::InvokeWindowEventSizeChanged(SDL_WindowEvent e)
{
	SDL_GetWindowSize(window, &width, &height);
	SizeChanged(e);
}

void Window::InvokeWindowEventMinimized(SDL_WindowEvent e)
{
	windowState = WindowState::Minimized;
	StateChanged(e);
}

void Window::InvokeWindowEventMaximized(SDL_WindowEvent e)
{
	windowState = WindowState::Maximized;
	StateChanged(e);
}

void Window::InvokeWindowEventRestored(SDL_WindowEvent e)
{
	windowState = WindowState::Restored;
	StateChanged(e);
}

void Window::InvokeWindowEventEnter(SDL_WindowEvent e)
{
	this->MouseEnter(e);
}

void Window::InvokeWindowEventLeave(SDL_WindowEvent e)
{
	this->MouseLeave(e);
}

void Window::InvokeWindowEventFocusGained(SDL_WindowEvent e)
{
	this->Activated(e);
}

void Window::InvokeWindowEventFocusLost(SDL_WindowEvent e)
{
	this->Deactivated(e);
}

void Window::InvokeWindowEventClose(SDL_WindowEvent e)
{
	this->Closed(e);
}

void Window::InvokeEventKeyDown(SDL_KeyboardEvent e)
{
	this->KeyDown(e);
}

void Window::InvokeEventKeyUp(SDL_KeyboardEvent e)
{
	this->KeyUp(e);
}

void Window::InvokeEventTextInput(SDL_TextInputEvent e)
{
	this->TextInput(e);
}

void Window::InvokeEventMouseMotion(SDL_MouseMotionEvent e)
{
	this->MouseMove(e);
	for (int i = 0; i < vElements.size(); i++)
	{
		vElements[i]->InvokeEventMouseMotion(e);
	}
}

void Window::InvokeEventMouseButtonDown(SDL_MouseButtonEvent e)
{
	this->MouseDown(e);
	for (int i = 0; i < vElements.size(); i++)
	{
		vElements[i]->InvokeEventMouseButtonDown(e);
	}
}

void Window::InvokeEventMouseButtonUp(SDL_MouseButtonEvent e)
{
	this->MouseUp(e);
	for (int i = 0; i < vElements.size(); i++)
	{
		vElements[i]->InvokeEventMouseButtonUp(e);
	}

}

void Window::InvokeEventMouseWheel(SDL_MouseWheelEvent e)
{
	this->MouseWheel(e);
	for (int i = 0; i < vElements.size(); i++)
	{
		vElements[i]->InvokeEventMouseWheel(e);
	}
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
	int tick = SDL_GetTicks();
	Tick(tick - lastTick);
	for (int i = 0; i < vElements.size(); i++)
	{
		vElements[i]->InvokeEventUpdate(tick - lastTick);
	}
	lastTick = tick;

	SDL_RenderClear(renderer);
	for (int i = 0; i < vElements.size(); i++)
	{
		SDL_Texture* texture = SDL_CreateTextureFromSurface(
			renderer,
			vElements[i]->GetSurface()
		);
		SDL_RenderCopy(
			renderer,
			texture,
			vElements[i]->GetSourceRectangle(),
			vElements[i]->GetDestinationRectangle()
		);
		SDL_DestroyTexture(texture);
	}
	SDL_RenderPresent(renderer);
}

int Window::GetID()
{
	return SDL_GetWindowID(window);
}

void Window::SetTitle(string title)
{
	this->title = title;
	if (window)
	{
		SDL_SetWindowTitle(window, title.c_str());
	}
}

const char* Window::GetTitle()
{
	return title.c_str();
}

void Window::SetWidth(int width)
{
	if (window)
	{
		SDL_SetWindowSize(window, width, height);
	}
}

const int Window::GetWidth()
{
	return width;
}

void Window::SetHeight(int height)
{
	if (height)
	{
		SDL_SetWindowSize(window, width, height);
	}
}

const int Window::GetHeight()
{
	return height;
}

void Window::SetWindowMode(WindowMode windowMode)
{
	this->windowMode = windowMode;
	if (window)
	{
		SDL_SetWindowFullscreen(window, windowMode);
	}
}

WindowMode Window::GetWindowMode()
{
	return windowMode;
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

WindowState Window::GetWindowState()
{
	return windowState;
}

void Window::SetVSync(bool vSync)
{
	this->vSync = vSync;
	Initialize();
}

bool Window::GetVSync()
{
	return vSync;
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
	cout << "vElements size: " << vElements.size();
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
