#pragma once
#include "VisualElement.h"

// Элемент для отображения текста
class Text :
	public VisualElement
{
	// Изображение текста
	VisualResource* resource = new VisualResource();
	// Отображаемый текст
	string text = "";
	// Путь до файла шрифта
	string fontFile = ".\\Resources\\Fonts\\RetroVille NC.ttf";
	// Размер шрифта
	int fontSize = 12;
	// Шрифт текста
	TTF_Font* font = TTF_OpenFont(fontFile.c_str(), fontSize);
	// Цвет текста
	SDL_Color foreground = { 0, 0, 0 };
	// Максимальная длина строки в пикселях
	int length = 0;

	// Создание изображения из текста
	void CreateSurface();

public:
	Text();
	// Конструктор с предустановкой текста
	Text(const char* text);

	// Возвращает отображаемый текст
	const char* GetText();
	// Задает отображаемый текст
	void SetText(const char* text);
	// Задает путь до шрифта отображаемого текста
	void SetFontFile(const char* file);
	// Возвращает размер шрифта
	int GetFontSize();
	// Задает размер шрифта
	void SetFontSize(int pt);
	// Возвращает цвет текста
	SDL_Color GetForeground();
	// Задает цвет текста
	void SetForeground(SDL_Color foreground);
	//
	int GetLength();

	void SetLength(int Length);

	// Возвращает изображение на основе которого будет отображаться объект
	VisualResource* GetVisualResource() override;
	// Возвращает размер и расположение отображаемой части изображения
	SDL_Rect* GetSourceRectangle() override;

};
