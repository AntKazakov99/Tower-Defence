#pragma once
#include <vector>
#include "Window.h"

// Отвечает за работу приложения
class Application
{
	// Список работающих в приложении окон
	std::vector<Window*> windows;
	// Статус работы приложения
	bool running = true;

	// Обработка событий
	void EventHandling();

public:
	Application();

	// Запуск приложения
	void Run();
	// Добавляет новое окно в приложение
	void AddWindow(Window* window);
};

