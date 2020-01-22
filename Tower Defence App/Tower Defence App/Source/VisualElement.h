#pragma once
#include <vector>
#include <SDL.h>

// Отображаемый объект
class VisualElement
{
	// Текстура объекта
	SDL_Texture* texture = NULL;
	// Размер и расположение отображаемой части текстуры
	SDL_Rect* srcRect = NULL;
	// Размер и расположение объекта при отображении
	SDL_Rect* dstRect = NULL;
	// Порядок отображения элемента в плоскости Z
	int zIndex = 0;
	// Указывает, находится ли указатель мыши над данным элементом
	bool isMouseOver = false;

protected:
	// Происходит, когда указатель мыши попадает внутрь границ данного элемента
	virtual void MouseEnter(SDL_MouseMotionEvent e);
	// Происходит, когда указатель мыши покидает границы данного элемента
	virtual void MouseLeave(SDL_MouseMotionEvent e);
	// Происходит при перемещении указателя мыши над данным элементом
	virtual void MouseMove(SDL_MouseMotionEvent e);
	// Происходит при нажатии любой кнопки мыши в тот момент, когда указатель мыши находится над данным элементом
	virtual void MouseDown(SDL_MouseButtonEvent e);
	// Происходит при отпускании любой кнопки мыши в тот момент, когда указатель мыши находится над данным элементом
	virtual void MouseUp(SDL_MouseButtonEvent e);
	// Происходит при вращении колесика мыши в тот момент, когда указатель мыши находится над данным элементом
	virtual void MouseWheel(SDL_MouseWheelEvent e);

	// Задает текстуру объекта
	void SetTexture(SDL_Texture* texture);
	// Возвращает текстуру объекта
	SDL_Texture* GetTexture();
	// Задает размер и расположение отображаемой части текстуры
	void SetSourceRect(SDL_Rect* srcRect);
	// Возвращает размер и расположение отображаемой части текстуры
	SDL_Rect* GetSourceRect();
	// Задает размер и расположение отображаемой части текстуры
	void SetDestinationRect(SDL_Rect* dstRect);
	// Возвращает размер и расположение объекта при отображении
	SDL_Rect* GetDestinationRect();
	// Возвращает порядок отображения элемента в плоскости Z
	int GetZIndex();

public:
	// Обработка SDL_MOUSEMOTION
	void InvokeEventMouseMotion(SDL_MouseMotionEvent e);
	// Обработка SDL_MOUSEBUTTONDOWN
	void InvokeEventMouseButtonDown(SDL_MouseButtonEvent e);
	// Обработка SDL_MOUSEBUTTONUP
	void InvokeEventMouseButtonUp(SDL_MouseButtonEvent e);
	// Обработка SDL_MOUSEWHEEL
	void InvokeEventMouseWheel(SDL_MouseWheelEvent e);

};

