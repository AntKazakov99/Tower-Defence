#pragma once
#include "Image.h"
#include "Wave.h"
// Объект типа "противник"
class Enemy :
	public Image
{
	// Уровен текущего здоровья противника
	int health = 60;
	// Скорость передвижения противника
	int movespeed = 100;
	// Путь противника
	vector<Path*> paths;
	// Текущий путь
	int currentPath = 1;
	// Пройденное растояние
	int passed = 0;
	// Время без движения
	int downtime = 0;

public:
	// Возвращает уровень текущего здоровья противника
	int GetHealth();
	// Задает уровень текущего здоровья противника
	void SetHealth(int health);
	// Возвращает скорость перемещения противника
	int GetMovespeed();
	// Задает скорость перемещения противника
	void SetMovespeed(int Movespeed);
	// Движение 
	bool Move(Uint32 deltaTime);
	// Добавляет путь в список путей
	void AddPath(Path* path);

};

