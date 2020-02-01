#pragma once
#include <string>
#include "Window.h"
#include "Text.h"
#include "Image.h"

class GameWindow :
	public Window
{
	// Показатель здоровья игрока
	int health = 30;
	// Показатель золота игрока
	int gold = 100;

	// Отображаемый на экране показатель текущего здоровья
	Text* healthText = new Text(to_string(health).c_str());
	// Отображаемый на экране показатель текущего золота
	Text* goldText = new Text(to_string(gold).c_str());

public:
	GameWindow();

	// Возвращает показатель здоровья
	int GetHealth();
	// Задает показатель здоровья
	void SetHealth(int Health);
	// Возвращает показатель золота
	int GetGold();
	// Задает показатель золота
	void SetGold(int Gold);

};
