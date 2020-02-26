#pragma once
#include <string>
#include "Window.h"
#include "Text.h"
#include "Tower.h"
#include "Wave.h"
#include "Enemy.h"

class GameWindow :
	public Window
{
	// Номер текущей волны
	int wave = 0;
	// Показатель здоровья игрока
	int health = 0;
	// Показатель золота игрока
	int gold = 0;
	// Выделенный объект
	Tower* target = nullptr;
	// Распоожение точки спавна
	int x = 0;
	int y = 0;
	vector<Path*> paths;

	// Изображение тайла врага
	VisualResource* enemyTile = new VisualResource(IMG_Load(".\\Resources\\enemy.png"));
	// Изображение тайла травы
	VisualResource* grassTile = new VisualResource(IMG_Load(".\\Resources\\grass.png"));
	// Изображение тайла дороги
	VisualResource* roadTile = new VisualResource(IMG_Load(".\\Resources\\road.png"));
	// Изображение тайла башни лучников
	VisualResource* archersTile = new VisualResource(IMG_Load(".\\Resources\\archers.png"));
	// Изображение тайла башни магов
	VisualResource* magesTile = new VisualResource(IMG_Load(".\\Resources\\mages.png"));

	// Список противников
	vector<Enemy*> enemies;
	// Список волн противников
	vector<Wave*> waves;
	// Список башен
	Tower* towers[16][11];
	// Изображение для выделения объекта
	Image* selectTargetImage = new Image();
	// Отображаемый номер текущей волны
	Text* waveText = new Text();
	// Отображаемое время с начала текущей волны
	Text* waveTimeText = new Text();
	// Отображаемый на экране показатель текущего здоровья
	Text* healthText = new Text();
	// Отображаемый на экране показатель текущего золота
	Text* goldText = new Text();
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
	// 
	Text* victoryText = new Text("Победа");
	//
	Text* defeatText = new Text("Поражение");

public:
	GameWindow();

	// Добавление новых противников
	void SpawnEnemies(Uint32 deltaTime);
	// Возвращает общее количество волн на уровне
	int GetWavesCount();
	// Возвращает номер текущей волны противников
	int GetWave();
	// Задает номер текущей волны противников
	void SetWave(int Wave);
	// Обновление значение WaveTimeText
	void UpdateWaveTimeText();
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
	// Добавить нового противника
	void AddEnemy(int Health, int Movespeed, VisualResource* Resource);
	// Удалить противниика
	void RemoveEnemy(Enemy* enemy);
	// Очистить список врагов
	void ClearEnemies();
	// Очистить список волн
	void ClearWaves();
	// Очистить список путей
	void ClearPaths();
	// Перемещение противников
	void MoveEnemies(Uint32 deltatime);
	//  Возвращает количество противников на уровне
	int GetEnemiesCount();
	// Задает победу
	void SetIsWin();
	// Задает поражение
	void SetIsDefeat();

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

// Срабатывание таймера окна
void GameWindowTimer_Tick(Object* owner, Timer* sender, Uint32 deltaTime);

// Срабатывание таймера башни
void TowerTimer_Tick(Object* owner, Timer* sender, Uint32 deltaTime);

// Обновление окна
void GameWindow_Update(Object* sender, Uint32 deltaTime);