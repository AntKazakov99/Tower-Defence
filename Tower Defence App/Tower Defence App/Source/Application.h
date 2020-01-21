#pragma once

#include <SDL.h>

// Отвечает за работу приложения
class Application
{
	// Статус работы приложения
	bool running = true;

public:
	// Запуск приложения
	void Run();

};

