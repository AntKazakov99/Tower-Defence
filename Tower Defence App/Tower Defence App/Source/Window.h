#pragma once
#include <iostream>
#include <SDL.h>

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
class Window
{
	// SDL реализация окна
	SDL_Window* window;
	// SDL Параметры рендеринга окна
	SDL_Renderer* renderer;
	// Идентификатор окна
	int id;
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

protected:
	// Происходит при изменении расположения окна
	virtual void LocationChanged(SDL_WindowEvent e);
	// Происходит при изменении размеров окна
	virtual void SizeChanged(SDL_WindowEvent e);
	// Происходит, когда изменяется свойство WindowState окна
	virtual void StateChanged(SDL_WindowEvent e);
	// Происходит, когда указатель мыши попадает внутрь границ окна
	virtual void MouseEnter(SDL_WindowEvent e);
	// Происходит, когда указатель мыши покидает границы данного элемента
	virtual void MouseLeave(SDL_WindowEvent e);
	// Происходит при перемещении окна на передний план
	virtual void Activated(SDL_WindowEvent e);
	// Происходит при перемещении окна на задний план
	virtual void Deactivated(SDL_WindowEvent e);
	// Происходит при закрытии окна
	virtual void Closed(SDL_WindowEvent e);

	// Происходит при нажатии клавиши
	virtual void KeyDown(SDL_KeyboardEvent e);
	// Происходит при отпускании клавиши
	virtual void KeyUp(SDL_KeyboardEvent e);
	// Происходит при вводе текста
	virtual void TextInput(SDL_TextInputEvent e);

	// Происходит при перемещении указателя мыши
	virtual void MouseMove(SDL_MouseButtonEvent e);
	// Происходит при нажатии любой кнопки мыши
	virtual void MouseDown(SDL_MouseButtonEvent e);
	// Происходит при отпускании любой кнопки мыши
	virtual void MouseUp(SDL_MouseButtonEvent e);
	// Происходит при вращении колесика мыши
	virtual void MouseWheel(SDL_MouseButtonEvent e);

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
	void InvokeEventMouseMotion(SDL_MouseButtonEvent e);
	// Обработка SDL_MOUSEBUTTONDOWN
	void InvokeEventMouseButtonDown(SDL_MouseButtonEvent e);
	// Обработка SDL_MOUSEBUTTONUP
	void InvokeEventMouseButtonUp(SDL_MouseButtonEvent e);
	// Обработка SDL_MOUSEWHEEL
	void InvokeEventMouseWheel(SDL_MouseButtonEvent e);

	// Инициализация окна, обновление параметров рендеринга
	void Initialize();
	// Обновляет окно
	void UpdateLayout();
	// Возвращает значение идентификатора окна
	int GetID();
	// Задает заголовок окна
	void SetTitle(string title);
	// Возвращает заголовок окна
	const char* GetTitle();
	// Задает ширину окна
	void SetWidth(int width);
	// Возвращает ширину окна
	const int GetWidth();
	// Задает высоту окна
	void SetHeight(int height);
	// Возвращает высоту окна
	const int GetHeight();
	// Задает режим работы окна
	void SetWindowMode(WindowMode windowMode);
	// Возвращает режим работы окна
	WindowMode GetWindowMode();
	// Задает восстановлено, свернуто или развернуто окно
	void SetWindowState(WindowState windowState);
	// Возвращает восстановлено, свернуто или развернуто окно
	WindowState GetWindowState();
	// Задает статус работы вертикальной синхронизации
	void SetVSync(bool isVSync);
	// Возвращает статус работы вертикальной синхронизации
	bool GetVSync();

};

