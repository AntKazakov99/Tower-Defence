#pragma once
#include <string>
#include "Window.h"
#include "Text.h"
#include "Image.h"

class GameWindow :
	public Window
{

public:
	// Текущее здоровье игрока
	int Health = 30;
	// Текущее золото игрока
	int Gold = 100;

	GameWindow();

};

void GoldText_Update(Object* owner, Object* sender, Uint32 deltaTime);

void HealthText_Update(Object* owner, Object* sender, Uint32 deltaTime);

void LevelOneButton_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e);

void LevelTwoButton_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e);
