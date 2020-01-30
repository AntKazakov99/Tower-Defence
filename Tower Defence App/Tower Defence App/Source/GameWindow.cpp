#include "GameWindow.h"

GameWindow::GameWindow()
{
	SetTitle("Tower Defence ver.0.0.1");
	Initialize();

	// Добавление на экран кнопки загрузки первого уровня
	Text* LevelOneButton = new Text("Уровень 1");
	LevelOneButton->SetForeground({ 255, 255, 255 });
	LevelOneButton->SetLocation(805, 100);
	LevelOneButton->SetZIndex(100);
	LevelOneButton->SetClick(LevelOneButton_Click);
	AddVisualElement(LevelOneButton);

	// Добавление на экран кнопки загрузки второго уровня
	Text* LevelTwoButton = new Text("Уровень 2");
	LevelTwoButton->SetForeground({ 255, 255, 255 });
	LevelTwoButton->SetLocation(805, 110);
	LevelTwoButton->SetZIndex(100);
	LevelTwoButton->SetClick(LevelTwoButton_Click);
	AddVisualElement(LevelTwoButton);

	// Добавление на экран текущего здоровья
	Text* HealthText = new Text();
	HealthText->SetForeground({ 255, 0, 0 });
	HealthText->SetLeft(805);
	HealthText->SetZIndex(100);
	HealthText->SetUpdate(HealthText_Update);
	AddVisualElement(HealthText);

	// Добавление на экран текущего золота
	Text* GoldText = new Text();
	GoldText->SetForeground({ 255, 255, 0 });
	GoldText->SetLocation(805, 20);
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

