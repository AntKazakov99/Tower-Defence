#pragma once
#include <functional>
#include <SDL.h>
#include "Object.h"

using namespace std;

// Объект "Таймер"
class Timer:
	public Object
{
	// Количество тактов в секунде
	const Uint32 TicksPerSecond = 1000;
	// Количество тактов в минуте
	const Uint32 TicksPerMinute = 60000;
	// Количество тактов в часе
	const Uint32 ticksPerHour = 3600000;

	// Время работы таймера
	Uint32 enableTime = 0;
	// Время паузы таймера
	Uint32 pauseTime = 0;
	// Возвращает или задает период между тактами таймера
	Uint32 interval = 0;
	// Отображает начата ли работа таймера
	bool isEnabled = false;
	// Отображает приостановлена ли работа таймера
	bool isPaused = false;


	// Происходит перед каждым обновлением окна
	function<void(Object*, Object*, Uint32)> Tick = nullptr;

public:
	// Обработка цикла обработки окна
	void InvokeEventTick(Object* owner, Uint32 deltaTime);

	// Задает метод для обработки события Tick
	void SetTick(void Tick(Object*, Object*, Uint32));
	// Начинает работу таймера
	void Start();
	// Приостанавливает работу таймера
	void Pause();
	// Останавливает таймер
	void Stop();
	
	// Возвращает время работы таймера
	Uint32 GetEnableTime();
	// Возвращает время паузы таймера
	Uint32 GetPauseTime();
	// Возвращает интервал срабатывания таймера
	Uint32 GetInterval();
	// Задает интервал срабатывания таймера
	void SetInterval(Uint32 Interval);

};
