#pragma once
#include <vector>
#include <SDL.h>

struct EnemySpawn
{
	// Время появления противника
	Uint32 spawnTiming;
	// Количество здоровья у нового противника
	int EnemyHealth = 60;
	// Скорость передвижения нового противника
	int EnemyMovespeed = 100;
	// Изображение противника
	VisualResource* resource;

};

// Объект содержащий информацию о волне противников
struct Wave
{
	// Длительность волны
	Uint32 duration = 0;
	// Список с таймингами появления противников
	std::vector<EnemySpawn*> spawnTimings;

};
