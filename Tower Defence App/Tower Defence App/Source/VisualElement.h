#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

// Отображаемый объект
class VisualElement
{
	// Показывает находится ли курсор мыши внутри границ элемента
	bool isMouseOver;
	// Состояние нажатия на элемент
	bool isPressed;
	// Порядок отображения элемента в плоскости Z
	int zIndex = 0;

protected:
	// Происходит перед каждым обновлением окна
	function<void(VisualElement*, Uint32)> Update = [](VisualElement*, Uint32) { /*empty*/ };
	// Происходит при клике по объекту
	function<void(VisualElement*, SDL_MouseButtonEvent)> Click = [](VisualElement*, SDL_MouseButtonEvent) { /*empty*/ };
	// Происходит, когда указатель мыши попадает внутрь границ элемента
	function<void(VisualElement*, SDL_MouseMotionEvent)> MouseEnter = [](VisualElement*, SDL_MouseMotionEvent) { /*empty*/ };
	// Происходит, когда указатель мыши покидает границы данного элемента
	function<void(VisualElement*, SDL_MouseMotionEvent)> MouseLeave = [](VisualElement*, SDL_MouseMotionEvent) { /*empty*/ };
	// Происходит при перемещении указателя мыши над данным элементом
	function<void(VisualElement*, SDL_MouseMotionEvent)> MouseMove = [](VisualElement*, SDL_MouseMotionEvent) { /*empty*/ };
	// Происходит при нажатии любой кнопки мыши над данным элементом
	function<void(VisualElement*, SDL_MouseButtonEvent)> MouseDown = [](VisualElement*, SDL_MouseButtonEvent) { /*empty*/ };
	// Происходит при отпускании любой кнопки мыши над данным элементом
	function<void(VisualElement*, SDL_MouseButtonEvent)> MouseUp = [](VisualElement*, SDL_MouseButtonEvent) { /*empty*/ };
	// Происходит при вращении колесика мыши над данным элементом
	function<void(VisualElement*, SDL_MouseWheelEvent)> MouseWheel = [](VisualElement*, SDL_MouseWheelEvent) { /*empty*/ };

public:
	void InvokeEventUpdate(Uint32 deltaTime);
	// Обработка SDL_MOUSEMOTION
	void InvokeEventMouseMotion(SDL_MouseMotionEvent e);
	// Обработка SDL_MOUSEBUTTONDOWN
	void InvokeEventMouseButtonDown(SDL_MouseButtonEvent e);
	// Обработка SDL_MOUSEBUTTONUP
	void InvokeEventMouseButtonUp(SDL_MouseButtonEvent e);
	// Обработка SDL_MOUSEWHEEL
	void InvokeEventMouseWheel(SDL_MouseWheelEvent e);

	// Задает метод для обработки события Update
	void SetUpdate(void Update(VisualElement*, Uint32));
	// Задает метод для обработки события Click
	void SetClick(void Click(VisualElement*, SDL_MouseButtonEvent));
	// Задает метод для обработки события MouseEnter
	void SetMouseEnter(void MouseEnter(VisualElement*, SDL_MouseMotionEvent));
	// Задает метод для обработки события MouseLeave
	void SetMouseLeave(void MouseLeave(VisualElement*, SDL_MouseMotionEvent));
	// Задает метод для обработки события MouseMove
	void SetMouseMove(void MouseMove(VisualElement*, SDL_MouseMotionEvent));
	// Задает метод для обработки события MouseDown
	void SetMouseDown(void MouseDown(VisualElement*, SDL_MouseButtonEvent));
	// Задает метод для обработки события MouseUp
	void SetMouseUp(void MouseUp(VisualElement*, SDL_MouseButtonEvent));
	// Задает метод для обработки события MouseDown
	void SetMouseWheel(void MouseWheel(VisualElement*, SDL_MouseWheelEvent));

	// Возвращает изображение на основе которого будет отображаться объект
	virtual SDL_Surface* GetSurface() = 0;
	// Возвращает размер и расположение отображаемой части изображения
	virtual SDL_Rect* GetSourceRectangle() = 0;
	// Возвращает размер и расположение объекта
	virtual SDL_Rect* GetDestinationRectangle() = 0;
	// Задает порядок отображения элемента в плоскости Z
	void SetZIndex(int zIndex);
	// Возвращает порядок отображения элемента в плоскости Z
	int GetZIndex();

};
