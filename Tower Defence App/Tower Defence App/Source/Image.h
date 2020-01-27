#pragma once
#include "VisualElement.h"

// Простое изображение
class Image :
	public VisualElement
{
	// Изображение
	VisualResource* resource = NULL;
	// Размер и расположение отображаемой части изображения
	SDL_Rect* srcRect = NULL;
	// Размер и расположение объекта
	SDL_Rect* dstRect = NULL;

public:
	// Задает изображение на основе которого будет отображаться объект
	void SetVisualResource(VisualResource* resource);
	// Задает размер и расположение отображаемой части изображения
	void SetSourceRectangle(SDL_Rect* srcRect);
	// Задает размер и расположение объекта
	void SetDestinationRectangle(SDL_Rect* dstRect);

	// Возвращает изображение на основе которого будет отображаться объект
	VisualResource* GetVisualResource() override;
	// Возвращает размер и расположение отображаемой части изображения
	SDL_Rect* GetSourceRectangle() override;
	// Возвращает размер и расположение объекта
	SDL_Rect* GetDestinationRectangle() override;

};
