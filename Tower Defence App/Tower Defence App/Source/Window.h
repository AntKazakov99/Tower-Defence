#pragma once
#include <iostream>
#include <SDL.h>

using namespace std;

// Режимы работы окна
enum WindowMode
{
	Windowed = 0,
	Borderless = SDL_WindowFlags::SDL_WINDOW_FULLSCREEN_DESKTOP,
	Fullscreen = SDL_WindowFlags::SDL_WINDOW_FULLSCREEN
};

// Позволяет создавать, настраивать и отображать содержимое окна
class Window
{
	// SDL реализация окна
	SDL_Window* window;
	// SDL Параметры рендеринга окна
	SDL_Renderer* renderer;
	// Заголовок окна
	string title;
	// Ширина окна
	int width = 1024;
	// Высота окна
	int height = 576;
	// Режим работы окна
	WindowMode windowMode = WindowMode::Windowed;
	// Статус работы вертикальной синхронизации
	bool vSync = false;

public:
	// Инициализация окна, обновление параметров рендеринга
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
	// Задает режим работы окна
	void SetWindowMode(WindowMode windowMode);
	// Возвращает режим работы окна
	WindowMode GetWindowMode();
	// Задает статус работы вертикальной синхронизации
	void SetVSync(bool isVSync);
	// Возвращает статус работы вертикальной синхронизации
	bool GetVSync();

};

