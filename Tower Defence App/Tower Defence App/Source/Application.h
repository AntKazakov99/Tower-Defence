#pragma once
#include <iostream>
#include <SDL.h>

using namespace std;

// Отвечает за работу приложения
class Application
{
	// Статус работы приложения
	bool running = true;

	// Обработка событий
	void EventHandling();

public:
	// Запуск приложения
	void Run();

};

