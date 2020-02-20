#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "VisualElement.h"
#include "Timer.h"
#include "Object.h"

using namespace std;

// Режимы работы окна
enum WindowMode
{
	Windowed = 0,
	Borderless = SDL_WindowFlags::SDL_WINDOW_FULLSCREEN_DESKTOP,
	Fullscreen = SDL_WindowFlags::SDL_WINDOW_FULLSCREEN
};

// Определяет положение окна (свернуто, восстановлено или развернуто)
enum WindowState
{
	Restored = 0,
	Minimized = SDL_WindowFlags::SDL_WINDOW_MINIMIZED,
	Maximized = SDL_WindowFlags::SDL_WINDOW_MAXIMIZED
};

// Позволяет создавать, настраивать и отображать содержимое окна
class Window:
	public Object,
	public Timer
{
	// SDL реализация окна
	SDL_Window* window = NULL;
	// SDL Параметры рендеринга окна
	SDL_Renderer* renderer = NULL;
	// Список отображаемых элементов
	vector<VisualElement*> vElements;
	// Список таймеров
	vector<Timer*> timers;
	// Идентификатор окна
	int id = 0;
	// Заголовок окна
	string title;
	// Ширина окна
	int width = 1024;
	// Высота окна
	int height = 576;
	// Режим работы окна
	WindowMode windowMode = WindowMode::Windowed;
	// Указывает восстановлено, свернуто или развернуто окно
	WindowState windowState = WindowState::Restored;
	// Статус работы вертикальной синхронизации
	bool vSync = false;
	// Время последнего обновления окна
	Uint32 lastTick = 0;

protected:
	// Происходит при каждом обновлении окна
	function<void(Object*, Uint32 deltaTime)> Update = nullptr;
	// Происходит при изменении расположения окна
	function<void(Object*, SDL_WindowEvent e)> LocationChanged = nullptr;
	// Происходит при изменении размеров окна
	function<void(Object*, SDL_WindowEvent e)> SizeChanged = nullptr;
	// Происходит, когда изменяется свойство WindowState окна
	function<void(Object*, SDL_WindowEvent e)> StateChanged = nullptr;
	// Происходит, когда указатель мыши попадает внутрь границ окна
	function<void(Object*, SDL_WindowEvent e)> MouseEnter = nullptr;
	// Происходит, когда указатель мыши покидает границы данного элемента
	function<void(Object*, SDL_WindowEvent e)> MouseLeave = nullptr;
	// Происходит при перемещении окна на передний план
	function<void(Object*, SDL_WindowEvent e)> Activated = nullptr;
	// Происходит при перемещении окна на задний план
	function<void(Object*, SDL_WindowEvent e)> Deactivated = nullptr;
	// Происходит при закрытии окна
	function<void(Object*, SDL_WindowEvent e)> Closed = nullptr;
	// Происходит при нажатии клавиши
	function<void(Object*, SDL_KeyboardEvent e)> KeyDown = nullptr;
	// Происходит при отпускании клавиши
	function<void(Object*, SDL_KeyboardEvent e)> KeyUp = nullptr;
	// Происходит при вводе текста
	function<void(Object*, SDL_TextInputEvent e)> TextInput = nullptr;
	// Происходит при перемещении указателя мыши
	function<void(Object*, SDL_MouseMotionEvent e)> MouseMove = nullptr;
	// Происходит при нажатии любой кнопки мыши
	function<void(Object*, SDL_MouseButtonEvent e)> MouseDown = nullptr;
	// Происходит при отпускании любой кнопки мыши
	function<void(Object*, SDL_MouseButtonEvent e)> MouseUp = nullptr;
	// Происходит при вращении колесика мыши
	function<void(Object*, SDL_MouseWheelEvent e)> MouseWheel = nullptr;

public:
	~Window();

	// Обработка события SDL_WINDOWEVENT_MOVED
	void InvokeWindowEventMoved(SDL_WindowEvent e);
	// Обработка события SDL_WINDOWEVENT_SIZE_CHANGED
	void InvokeWindowEventSizeChanged(SDL_WindowEvent e);
	// Обработка события SDL_WINDOWEVENT_MINIMIZED
	void InvokeWindowEventMinimized(SDL_WindowEvent e);
	// Обработка события SDL_WINDOWEVENT_MAXIMIZED
	void InvokeWindowEventMaximized(SDL_WindowEvent e);
	// Обработка события SDL_WINDOWEVENT_RESTORED
	void InvokeWindowEventRestored(SDL_WindowEvent e);
	// Обработка SDL_WINDOWEVENT_ENTER
	void InvokeWindowEventEnter(SDL_WindowEvent e);
	// Обработка SDL_WINDOWEVENT_LEAVE
	void InvokeWindowEventLeave(SDL_WindowEvent e);
	// Обработка SDL_WINDOWEVENT_FOCUS_GAINED
	void InvokeWindowEventFocusGained(SDL_WindowEvent e);
	// Обработка SDL_WINDOWEVENT_FOCUS_LOST
	void InvokeWindowEventFocusLost(SDL_WindowEvent e);
	// Обработка SDL_WINDOWEVENT_CLOSE
	void InvokeWindowEventClose(SDL_WindowEvent e);
	// Обработка SDL_KEYDOWN
	void InvokeEventKeyDown(SDL_KeyboardEvent e);
	// Обработка SDL_KEYUP
	void InvokeEventKeyUp(SDL_KeyboardEvent e);
	// Обработка SDL_TEXTINPUT
	void InvokeEventTextInput(SDL_TextInputEvent e);
	// Обработка SDL_MOUSEMOTION
	void InvokeEventMouseMotion(SDL_MouseMotionEvent e);	
	// Обработка SDL_MOUSEBUTTONDOWN
	void InvokeEventMouseButtonDown(SDL_MouseButtonEvent e);
	// Обработка SDL_MOUSEBUTTONUP
	void InvokeEventMouseButtonUp(SDL_MouseButtonEvent e);
	// Обработка SDL_MOUSEWHEEL
	void InvokeEventMouseWheel(SDL_MouseWheelEvent e);

	// Задает метод для обработки события Update
	void SetUpdate(void Update(Object* sender, Uint32 deltaTime));
	// Задает метод для обработки события LocationChanged
	void SetLocationChanged(void LocationChanged(Object* sender, SDL_WindowEvent e));
	// Задает метод для обработки события SizeChanged
	void SetSizeChanged(void SizeChanged(Object* sender, SDL_WindowEvent e));
	// Задает метод для обработки события StateChanged
	void SetStateChanged(void StateChanged(Object* sender, SDL_WindowEvent e));
	// Задает метод для обработки события MouseEnter
	void SetMouseEnter(void MouseEnter(Object* sender, SDL_WindowEvent e));
	// Задает метод для обработки события MouseLeave
	void SetMouseLeave(void MouseLeave(Object* sender, SDL_WindowEvent e));
	// Задает метод для обработки события Activated
	void SetActivated(void Activated(Object* sender, SDL_WindowEvent e));
	// Задает метод для обработки события Deactivated
	void SetDeactivated(void Deactivated(Object* sender, SDL_WindowEvent e));
	// Задает метод для обработки события Closed
	void SetClosed(void Closed(Object* sender, SDL_WindowEvent e));
	// Задает метод для обработки события KeyDown
	void SetKeyDown(void KeyDown(Object* sender, SDL_KeyboardEvent e));
	// Задает метод для обработки события KeyUp
	void SetKeyUp(void KeyUp(Object* sender, SDL_KeyboardEvent e));
	// Задает метод для обработки события TextInput
	void SetTextInput(void TextInput(Object* sender, SDL_TextInputEvent e));
	// Задает метод для обработки события MouseMove
	void SetMouseMove(void MouseMove(Object* sender, SDL_MouseMotionEvent e));
	// Задает метод для обработки события MouseDown
	void SetMouseDown(void MouseDown(Object* sender, SDL_MouseButtonEvent e));
	// Задает метод для обработки события MouseUp
	void SetMouseUp(void MouseUp(Object* sender, SDL_MouseButtonEvent e));
	// Задает метод для обработки события MouseWheel
	void SetMouseWheel(void MouseWheel(Object* sender, SDL_MouseWheelEvent e));

	// Инициализация окна, обновление параметров рендеринга
	void Initialize();
	// Обновляет окно
	void UpdateLayout();
	// Возвращает значение идентификатора окна
	int GetID();
	// Возвращает заголовок окна
	const char* GetTitle();
	// Задает заголовок окна
	void SetTitle(string title);
	// Возвращает ширину окна
	const int GetWidth();
	// Задает ширину окна
	void SetWidth(int width);
	// Возвращает высоту окна
	const int GetHeight();
	// Задает высоту окна
	void SetHeight(int height);
	// Возвращает режим работы окна
	WindowMode GetWindowMode();
	// Задает режим работы окна
	void SetWindowMode(WindowMode windowMode);
	// Возвращает восстановлено, свернуто или развернуто окно
	WindowState GetWindowState();
	// Задает восстановлено, свернуто или развернуто окно
	void SetWindowState(WindowState windowState);
	// Возвращает статус работы вертикальной синхронизации
	bool GetVSync();
	// Задает статус работы вертикальной синхронизации
	void SetVSync(bool isVSync);
	// Добавляет новый элемент в список отображаемых объектов
	void AddVisualElement(VisualElement* vElement);
	// Удаляет элемент из списка отображаемых объектов
	void RemoveVisualElement(VisualElement* vElement);
	// Добавляет новый таймер в список обрабатываемых таймеров
	void AddTimer(Timer* timer);
	// Удаляет таймер из списка обрабатываемых таймеров
	void RemoveTimer(Timer* timer);

};
