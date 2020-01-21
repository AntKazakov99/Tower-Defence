#include "Window.h"

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
	this->width = width;
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
	this->height = height;
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

void Window::SetVSync(bool vSync)
{
	this->vSync = vSync;
	Initialize();
}

bool Window::GetVSync()
{
	return vSync;
}
