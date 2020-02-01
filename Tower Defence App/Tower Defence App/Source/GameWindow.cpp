#include "GameWindow.h"

GameWindow::GameWindow()
{
	SetTitle("Tower Defence ver.0.0.1");
	Initialize();

	// Добавляет текст "Текущее здоровье:" на экран
	Text* currentHealthText = new Text("Текущее здоровье: ");
	currentHealthText->SetLocation(805, 0);
	currentHealthText->SetForeground({ 255, 255, 255 });
	AddVisualElement(currentHealthText);

	// Выводит показатель здоровья игрока на экран
	healthText->SetLocation(805 + currentHealthText->GetWidth(), 0);
	healthText->SetForeground({ 255, 0, 0 });
	AddVisualElement(healthText);

	// Добавляет текст "Текущее золото:" на экран
	Text* currentGoldText = new Text("Текущее золото: ");
	currentGoldText->SetLocation(805, 15);
	currentGoldText->SetForeground({ 255, 255, 255 });
	AddVisualElement(currentGoldText);

	// Выводит показатель золота игрока на экран
	goldText->SetLocation(805 + currentGoldText->GetWidth(), 15);
	goldText->SetForeground({ 255, 255, 0 });
	AddVisualElement(goldText);

}

int GameWindow::GetHealth()
{
	return health;
}

void GameWindow::SetHealth(int Health)
{
	health = Health;
	healthText->SetText(to_string(health).c_str());
}

int GameWindow::GetGold()
{
	return gold;
}

void GameWindow::SetGold(int Gold)
{
	gold = Gold;
	goldText->SetText(to_string(gold).c_str());
}

void GameWindow::UpdateInterface()
{

}
