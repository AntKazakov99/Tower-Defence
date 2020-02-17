#pragma once
#include "Window.h"

// Отвечает за работу приложения
class Application
{
	// Список работающих в приложении окон
	std::vector<Window*> windows;
	// Статус работы приложения
	bool running = true;
	// Время последнего обновления окна
	int lastTick = SDL_GetTicks();

	// Обработка событий
	void EventHandling();

public:
	Application();

	// Запуск приложения
	void Run();
	// Добавляет новое окно в приложение
	void AddWindow(Window* window);
};

