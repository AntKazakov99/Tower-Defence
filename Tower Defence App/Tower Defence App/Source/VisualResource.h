#pragma once
#include "SDL.h"

class VisualResource
{
	// Индикатор того изменялся ли Surface
	bool isUpdated = false;
	// Оригинальное изображение
	SDL_Surface* surface = NULL;
	// Текстура с учетом параметров рендеринга
	SDL_Texture* texture = NULL;

public:
	VisualResource();
	VisualResource(SDL_Surface* surface);

	// Возвращает изображение
	SDL_Surface* GetSurface();
	// Задает изображение
	void SetSurface(SDL_Surface* surface);
	// Возвращает текстуру
	SDL_Texture* GetTexture();
	// Задает текстуру
	void UpdateTexture(SDL_Renderer* renderer);
	// Возвращает значение isUpdated
	bool GetIsUpdated();

};

