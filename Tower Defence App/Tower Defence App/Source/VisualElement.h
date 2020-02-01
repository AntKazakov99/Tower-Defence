#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Object.h"
#include "VisualResource.h"

using namespace std;

// Отображаемый объект
class VisualElement:
	public Object
{
	// Показывает находится ли курсор мыши внутри границ элемента
	bool isMouseOver = false;
	// Состояние нажатия на элемент
	bool isPressed = false;
	// Порядок отображения элемента в плоскости Z
	int zIndex = 0;
	// Размер и расположение объекта
	SDL_Rect* dstRect = NULL;
	// Статус видимости объекта
	bool isVisible = true;

protected:
	// Происходит перед каждым обновлением окна
	function<void(Object*, Object*, Uint32)> Update = [](Object*, Object*, Uint32) { /*empty*/ };
	// Происходит при клике по объекту
	function<void(Object*, Object*, SDL_MouseButtonEvent)> Click = [](Object*, Object*, SDL_MouseButtonEvent) { /*empty*/ };
	// Происходит, когда указатель мыши попадает внутрь границ элемента
	function<void(Object*, Object*, SDL_MouseMotionEvent)> MouseEnter = [](Object*, Object*, SDL_MouseMotionEvent) { /*empty*/ };
	// Происходит, когда указатель мыши покидает границы данного элемента
	function<void(Object*, Object*, SDL_MouseMotionEvent)> MouseLeave = [](Object*, Object*, SDL_MouseMotionEvent) { /*empty*/ };
	// Происходит при перемещении указателя мыши над данным элементом
	function<void(Object*, Object*, SDL_MouseMotionEvent)> MouseMove = [](Object*, Object*, SDL_MouseMotionEvent) { /*empty*/ };
	// Происходит при нажатии любой кнопки мыши над данным элементом
	function<void(Object*, Object*, SDL_MouseButtonEvent)> MouseDown = [](Object*, Object*, SDL_MouseButtonEvent) { /*empty*/ };
	// Происходит при отпускании любой кнопки мыши над данным элементом
	function<void(Object*, Object*, SDL_MouseButtonEvent)> MouseUp = [](Object*, Object*, SDL_MouseButtonEvent) { /*empty*/ };
	// Происходит при вращении колесика мыши над данным элементом
	function<void(Object*, Object*, SDL_MouseWheelEvent)> MouseWheel = [](Object*, Object*, SDL_MouseWheelEvent) { /*empty*/ };

public:
	void InvokeEventUpdate(Object* owner, Uint32 deltaTime);
	// Обработка SDL_MOUSEMOTION
	void InvokeEventMouseMotion(Object* owner, SDL_MouseMotionEvent e);
	// Обработка SDL_MOUSEBUTTONDOWN
	void InvokeEventMouseButtonDown(Object* owner, SDL_MouseButtonEvent e);
	// Обработка SDL_MOUSEBUTTONUP
	void InvokeEventMouseButtonUp(Object* owner, SDL_MouseButtonEvent e);
	// Обработка SDL_MOUSEWHEEL
	void InvokeEventMouseWheel(Object* owner, SDL_MouseWheelEvent e);

	// Задает метод для обработки события Update
	void SetUpdate(void Update(Object* , Object*, Uint32));
	// Задает метод для обработки события Click
	void SetClick(void Click(Object*, Object*, SDL_MouseButtonEvent));
	// Задает метод для обработки события MouseEnter
	void SetMouseEnter(void MouseEnter(Object*, Object*, SDL_MouseMotionEvent));
	// Задает метод для обработки события MouseLeave
	void SetMouseLeave(void MouseLeave(Object*, Object*, SDL_MouseMotionEvent));
	// Задает метод для обработки события MouseMove
	void SetMouseMove(void MouseMove(Object*, Object*, SDL_MouseMotionEvent));
	// Задает метод для обработки события MouseDown
	void SetMouseDown(void MouseDown(Object*, Object*, SDL_MouseButtonEvent));
	// Задает метод для обработки события MouseUp
	void SetMouseUp(void MouseUp(Object*, Object*, SDL_MouseButtonEvent));
	// Задает метод для обработки события MouseDown
	void SetMouseWheel(void MouseWheel(Object*, Object*, SDL_MouseWheelEvent));

	// Возвращает изображение на основе которого будет отображаться объект
	virtual VisualResource* GetVisualResource() = 0;
	// Возвращает размер и расположение отображаемой части изображения
	virtual SDL_Rect* GetSourceRectangle() = 0;

	// Возвращает размер и расположение объекта
	SDL_Rect* GetDestinationRectangle();
	// Задает размер и расположение объекта
	void SetDestinationRectangle(SDL_Rect* dstRect);
	// Задает расположение элемента
	void SetLocation(int left, int top);
	// Возвращает расстояние между левой границей элемента и границей окна
	int GetLeft();
	// Задает расстояние между левой границей элемента и границей окна
	void SetLeft(int left);
	// Возвращает расстояние между верхней границей элемента и границей окна
	int GetTop();
	// Задает расстояние между верхней границей элемента и границей окна
	void SetTop(int top);
	// Задает размер объекта
	void SetSize(int width, int height);
	// Возвращает ширину элемента
	int GetWidth();
	// Задает ширину элемента
	void SetWidth(int width);
	// Возвращает высоту элемента
	int GetHeight();
	// Задает высоту элемента
	void SetHeight(int height);
	// Задает порядок отображения элемента в плоскости Z
	void SetZIndex(int zIndex);
	// Возвращает порядок отображения элемента в плоскости Z
	int GetZIndex();
	// Возвращает состояние видимости элемента
	bool GetIsVisible();
	// Задает состояние видимости элемента
	void SetIsVisible(bool IsVisible);

};
