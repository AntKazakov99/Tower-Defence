#include "GameWindow.h"

GameWindow::GameWindow()
{
	SetTitle("Tower Defence ver.0.0.1");
	Initialize();

	// Добавление на экран кнопки загрузки первого уровня
	LevelOneButton->SetFontFile(FontFile.c_str());
	LevelOneButton->SetLeft(805);
	LevelOneButton->SetZIndex(100);
	LevelOneButton->SetText("Уровень 1");
	LevelOneButton->SetTop(100);
	LevelOneButton->SetClick(LevelOneButton_Click);
	AddVisualElement(LevelOneButton);

	// Добавление на экран кнопки загрузки второго уровня
	LevelTwoButton->SetFontFile(FontFile.c_str());
	LevelTwoButton->SetLeft(805);
	LevelTwoButton->SetZIndex(100);
	LevelTwoButton->SetText("Уровень 2");
	LevelTwoButton->SetTop(110);
	LevelTwoButton->SetClick(LevelTwoButton_Click);
	AddVisualElement(LevelTwoButton);

	// Добавление на экран текущего здоровья
	HealthText->SetFontFile(FontFile.c_str());
	HealthText->SetForeground({ 255, 0, 0 });
	HealthText->SetLeft(805);
	HealthText->SetZIndex(100);
	HealthText->SetUpdate(HealthText_Update);
	AddVisualElement(HealthText);

	// Добавление на экран текущего золота
	GoldText->SetFontFile(FontFile.c_str());
	GoldText->SetForeground({ 255, 255, 0 });
	GoldText->SetLeft(805);
	GoldText->SetTop(20);
	GoldText->SetZIndex(100);
	GoldText->SetUpdate(GoldText_Update);
	AddVisualElement(GoldText);

}

void GoldText_Update(Object* owner, Object* sender, Uint32 deltaTime)
{
	GameWindow* window = (GameWindow*)owner;
	Text* text = (Text*)sender;
	text->SetText(("Текущее золото: " + to_string(window->Gold)).c_str());
}

void HealthText_Update(Object* owner, Object* sender, Uint32 deltaTime)
{
	GameWindow* window = (GameWindow*)owner;
	Text* text = (Text*)sender;
	text->SetText(("Текущее здоровье: " + to_string(window->Health)).c_str());
}

void LevelOneButton_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e)
{

}

void LevelTwoButton_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e)
{

}

