#pragma once
#include <string>
#include "Window.h"
#include "Text.h"
#include "Tower.h"

class GameWindow :
	public Window
{

	// Показатель здоровья игрока
	int health = 30;
	// Показатель золота игрока
	int gold = 100;
	// Выделенный объект
	Tower* target = nullptr;

	// Изображение тайла травы
	VisualResource* grassTile = new VisualResource(IMG_Load(".\\Resources\\grass.png"));
	// Изображение тайла дороги
	VisualResource* roadTile = new VisualResource(IMG_Load(".\\Resources\\road.png"));
	// Изображение тайла башни лучников
	VisualResource* archersTile = new VisualResource(IMG_Load(".\\Resources\\archers.png"));
	// Изображение тайла башни магов
	VisualResource* magesTile = new VisualResource(IMG_Load(".\\Resources\\mages.png"));

	// Список башен
	Tower* towers[16][11];
	// Изображение для выделения объекта
	Image* selectTargetImage = new Image();
	// Отображаемый на экране показатель текущего здоровья
	Text* healthText = new Text(to_string(health).c_str());
	// Отображаемый на экране показатель текущего золота
	Text* goldText = new Text(to_string(gold).c_str());
	// Изображение выделенного объекта
	Image* targetImage = new Image();
	// Название выделенного элемента
	Text* targetTitle = new Text();
	// Описание выделенного элемента
	Text* targetDescription = new Text();
	// Кнопка постройки башни лучников
	Text* buildArchersTower = new Text("Построить башню лучников\n(Стоимость: 100)");
	// Кнопка постройки башни мага
	Text* buildMageTower = new Text("Построить башню мага\n(Стоимость: 200)");
	// Кнопка поломки башни
	Text* destroyTower = new Text();
	
public:
	GameWindow();

	// Возвращает показатель здоровья
	int GetHealth();
	// Задает показатель здоровья
	void SetHealth(int Health);
	// Возвращает показатель золота
	int GetGold();
	// Задает показатель золота
	void SetGold(int Gold);
	// Возвращает выделенный объект
	Tower* GetTarget();
	// Задает выделенный элемент
	void SetTarget(Tower* Target);
	// Загрузка уровня
	void LoadLevel(int Level);
	// Обновление интерфейса в соответствии с выделенным объектом
	void UpdateInterface();
	// Загрузка информации о башне
	void LoadTowerInfo(Tower* tower, TowerType type);

};

// Обработка нажатия клавиши в окне
void GameWindow_KeyDown(Object* owner, SDL_KeyboardEvent e);

// Нажатие на объект на карте
void Tower_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e);

// Нажатие на кнопку постройки башни
void BuildArchersTower_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e);

// Нажатие на кнопку постройки башни
void BuildMageTower_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e);

// Нажатие на кнопку загрузки второго уровня
void DestroyTowerButton_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e);

// Нажатие на кнопку загрузки первого уровня
void LevelOneButton_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e);

// Нажатие на кнопку загрузки второго уровня
void LevelTwoButton_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e);
