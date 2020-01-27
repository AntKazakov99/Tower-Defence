#pragma once
#include <string>
#include "Window.h"
#include "Text.h"
#include "Image.h"

class GameWindow :
	public Window
{
public:
	// Расположение файла со шрифтами
	string FontFile = ".\\Resources\\Fonts\\RetroVille NC.ttf";

	// Текущее здоровье игрока
	int Health = 30;
	// Текущее золото игрока
	int Gold = 100;

	// Кнопка загрузки первого уровня
	Text* LevelOneButton = new Text();
	// Кнопка загрузки второго уровня
	Text* LevelTwoButton = new Text();
	// Отображение текущего здоровья
	Text* HealthText = new Text();
	// Отображение текущего золота
	Text* GoldText = new Text();
	// Интерфейс игры
	Image* GameInterface = new Image();

	GameWindow();

};

void GoldText_Update(Object* owner, Object* sender, Uint32 deltaTime);

void HealthText_Update(Object* owner, Object* sender, Uint32 deltaTime);

void LevelOneButton_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e);

void LevelTwoButton_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e);
