#include "Window.h"

void Window::Initialize()
{
	// Создает окно
	window = SDL_CreateWindow(
		title.c_str(), 
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		width, 
		height, 
		SDL_WINDOW_SHOWN);
}

void Window::SetTitle(string title)
{
	this->title = title;
}

const char* Window::GetTitle()
{
	return title.c_str();
}

void Window::SetWidth(int width)
{
	this->width = width;
}

const int Window::GetWidth()
{
	return width;
}

void Window::SetHeight(int height)
{
	this->height = height;
}

const int Window::GetHeight()
{
	return height;
}
