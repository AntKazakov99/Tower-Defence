#pragma once
#include "Window.h"

// Отвечает за работу приложения
class Application
{
	// Статус работы приложения
	bool running = true;
	// Главное окно приложения
	Window* mainWindow;

	// Обработка событий
	void EventHandling();

public:
	// Запуск приложения
	void Run();
	// Задает главое окно приложения
	void SetMainWindow(Window* window);

};

