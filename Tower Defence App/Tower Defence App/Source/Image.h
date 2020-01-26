#pragma once
#include "VisualElement.h"

// Простое изображение
class Image :
	public VisualElement
{
	// Изображение
	SDL_Surface* surface;
	// Размер и расположение отображаемой части изображения
	SDL_Rect* srcRect;
	// Размер и расположение объекта
	SDL_Rect* dstRect;

public:
	// Задает изображение на основе которого будет отображаться объект
	void SetSurface(SDL_Surface* surface);
	// Задает размер и расположение отображаемой части изображения
	void SetSourceRectangle(SDL_Rect* srcRect);
	// Задает размер и расположение объекта
	void SetDestinationRectangle(SDL_Rect* dstRect);

	// Возвращает изображение на основе которого будет отображаться объект
	SDL_Surface* GetSurface() override;
	// Возвращает размер и расположение отображаемой части изображения
	SDL_Rect* GetSourceRectangle() override;
	// Возвращает размер и расположение объекта
	SDL_Rect* GetDestinationRectangle() override;

};
