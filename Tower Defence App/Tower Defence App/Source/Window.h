#pragma once
#include <iostream>
#include <SDL.h>

using namespace std;

// Позволяет создавать, настраивать и отображать содержимое окна
class Window
{
	// SDL реализация окна
	SDL_Window* window;
	// Заголовок окна
	string title;
	// Ширина окна
	int width = 1024;
	// Высота окна
	int height = 576;

public:
	// Инициализация окна
	void Initialize();
	// Задает заголовок окна
	void SetTitle(string title);
	// Возвращает заголовок окна
	const char* GetTitle();
	// Задает ширину окна
	void SetWidth(int width);
	// Возвращает ширину окна
	const int GetWidth();
	// Задает высоту окна
	void SetHeight(int height);
	// Возвращает высоту окна
	const int GetHeight();
};

