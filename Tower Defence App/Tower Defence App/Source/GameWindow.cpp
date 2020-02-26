#include "GameWindow.h"

GameWindow::GameWindow()
{
	SetTitle("Tower Defence ver.0.0.1");
	Initialize();
	SetKeyDown(GameWindow_KeyDown);
	SetTick(GameWindowTimer_Tick);
	SetUpdate(GameWindow_Update);

	// Интерфейс боковой панели игры
	Image* interface = new Image();
	interface->SetVisualResource(new VisualResource(IMG_Load(".\\Resources\\interface.png")));
	AddVisualElement(interface);

	// Рамка для выделения объекта
	selectTargetImage->SetVisualResource(new VisualResource(IMG_Load(".\\Resources\\target.png")));
	selectTargetImage->SetZIndex(100);
	selectTargetImage->SetSize(50, 50);
	selectTargetImage->SetZIndex(100);
	selectTargetImage->SetIsVisible(false);
	AddVisualElement(selectTargetImage);

	// Выводит номер текущей волны врагов на экран
	waveText->SetLocation(815, 11 + 15 * 0);
	waveText->SetForeground({ 255, 255, 255 });
	AddVisualElement(waveText);

	// Выводит номер текущей волны врагов на экран
	waveTimeText->SetLocation(815, 11 + 15 * 1);
	waveTimeText->SetForeground({ 255, 255, 255 });
	AddVisualElement(waveTimeText);

	// Выводит показатель здоровья игрока на экран
	healthText->SetLocation(815, 11 + 15 * 2);
	healthText->SetForeground({ 255, 255, 255 });
	AddVisualElement(healthText);

	// Выводит показатель золота игрока на экран
	goldText->SetLocation(815, 11 + 15 * 3);
	goldText->SetForeground({ 255, 255, 255 });
	AddVisualElement(goldText);

	// Изображение выделенного элемента
	targetImage->SetLocation(865, 80);
	targetImage->SetSize(100, 100);
	AddVisualElement(targetImage);

	// Название выделенного элемента
	targetTitle->SetLocation(815, 180);
	targetTitle->SetFontSize(14);
	AddVisualElement(targetTitle);

	// Описание выделенного элемента
	targetDescription->SetLocation(815, 197);
	targetDescription->SetLength(194);
	AddVisualElement(targetDescription);

	// Кнопка постройки башни лучников
	buildArchersTower->SetLocation(815, 300);
	buildArchersTower->SetFontSize(14);
	buildArchersTower->SetLength(194);
	buildArchersTower->SetIsVisible(false);
	buildArchersTower->SetClick(BuildArchersTower_Click);
	AddVisualElement(buildArchersTower);

	// Кнопка постройки башни мага
	buildMageTower->SetLocation(815, 370);
	buildMageTower->SetFontSize(14);
	buildMageTower->SetLength(194);
	buildMageTower->SetIsVisible(false);
	buildMageTower->SetClick(BuildMageTower_Click);
	AddVisualElement(buildMageTower);

	// Кнопка поломки башни
	destroyTower->SetLocation(815, 300);
	destroyTower->SetFontSize(14);
	destroyTower->SetLength(194);
	destroyTower->SetIsVisible(false);
	destroyTower->SetClick(DestroyTowerButton_Click);
	AddVisualElement(destroyTower);

	// Кнопка загрузки первого уровня
	Text* levelOneButton = new Text("Уровень 1");
	levelOneButton->SetLocation(815, 500);
	levelOneButton->SetFontSize(14);
	levelOneButton->SetClick(LevelOneButton_Click);
	AddVisualElement(levelOneButton);

	// Кнопка загрузки второго уровня
	Text* levelTwoButton = new Text("Уровень 2");
	levelTwoButton->SetLocation(815, 517);
	levelTwoButton->SetFontSize(14);
	levelTwoButton->SetClick(LevelTwoButton_Click);
	AddVisualElement(levelTwoButton);

}

void GameWindow::SpawnEnemies(Uint32 deltaTime)
{
	if (waves.size() >= wave)
	{
		for (int i = 0; i < waves[wave - 1]->spawnTimings.size(); i++)
		{
			if (waves[wave - 1]->spawnTimings[i]->spawnTiming >= GetEnableTime() &&
				waves[wave - 1]->spawnTimings[i]->spawnTiming < GetEnableTime() + deltaTime)
			{
				cout << "Enemy Spawned: " << waves[wave - 1]->spawnTimings[i]->spawnTiming << " Enable time: " << GetEnableTime() << " Delta: " << deltaTime << endl;
			}
		}
	}
}

int GameWindow::GetWavesCount()
{
	return waves.size();
}

int GameWindow::GetWave()
{
	return wave;
}

void GameWindow::SetWave(int Wave)
{
	wave = Wave;
	waveText->SetText(("Волна " + to_string(wave) + " из " + to_string(GetWavesCount())).c_str());
	if (waves.size() >= wave)
	{
		SetInterval(waves[wave - 1]->duration);
	}
}

void GameWindow::UpdateWaveTimeText()
{
	if (GetIsEnabled())
	{
		waveTimeText->SetText(
			((GetEnableTime() / 60000 < 10 ? "0" : "") + to_string(GetEnableTime() / 60000) + ":" +
			(GetEnableTime() % 60000 / 1000  < 10 ? "0" : "") + to_string(GetEnableTime() % 60000 / 1000) + " из " +
			(GetInterval() / 60000 < 10 ? "0" : "") + to_string(GetInterval() / 60000) + ":" +
			((GetInterval() % 60000) / 1000 < 10 ? "0" : "") + to_string((GetInterval() % 60000) / 1000)).c_str());
	}
}

int GameWindow::GetHealth()
{
	return health;
}

void GameWindow::SetHealth(int Health)
{
	health = Health;
	healthText->SetText(("Текущее здоровье: " + to_string(health)).c_str());
}

int GameWindow::GetGold()
{
	return gold;
}

void GameWindow::SetGold(int Gold)
{
	gold = Gold;
	goldText->SetText(("Текущее золото: " + to_string(gold)).c_str());
}

Tower* GameWindow::GetTarget()
{
	return target;
}

void GameWindow::SetTarget(Tower* Target)
{
	target = Target;
	if (target)
	{
		selectTargetImage->SetLocation(target->GetLeft(), target->GetTop());
		selectTargetImage->SetIsVisible(true);
	}
	else
	{
		selectTargetImage->SetIsVisible(false);
	}
	UpdateInterface();
}

void GameWindow::LoadLevel(int Level)
{
	// Создает объекты башен
	for (int x = 0; x < 16; x++)
	{
		for (int y = 0; y < 11; y++)
		{
			if (!towers[x][y])
			{
				towers[x][y] = new Tower();
				towers[x][y]->SetLocation(50 * x, 50 * y);
				towers[x][y]->SetSize(50, 50);
				AddVisualElement(towers[x][y]);
				AddTimer(towers[x][y]);
				towers[x][y]->SetClick(Tower_Click);
				towers[x][y]->SetTick(TowerTimer_Tick);
			}
		}
	}
	Stop();
	SetTarget(NULL);
	if (Level == 1)
	{
		SetGold(100);
		SetHealth(30);

		// Добавить загрузку уровня
		TowerType levelMap[11][16] =
		{
			{TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None},
			{TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None},
			{TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None},
			{TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None},
			{TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None},
			{TowerType::Road, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::Road},
			{TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None},
			{TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None},
			{TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None},
			{TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None},
			{TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None},
		};
		for (int x = 0; x < 16; x++)
		{
			for (int y = 0; y < 11; y++)
			{
				LoadTowerInfo(towers[x][y], levelMap[y][x]);
			}
		}

		// Загрузка таймингов появление противников
		waves.push_back(new Wave());
		waves[waves.size() - 1]->duration = 60000;
		EnemySpawn* enemy1 = new EnemySpawn();
		enemy1->spawnTiming = 0;
		waves[waves.size() - 1]->spawnTimings.push_back(enemy1);
		enemy1 = new EnemySpawn();
		enemy1->spawnTiming = 500;
		waves[waves.size() - 1]->spawnTimings.push_back(enemy1);
		enemy1 = new EnemySpawn();
		enemy1->spawnTiming = 1000;
		waves[waves.size() - 1]->spawnTimings.push_back(enemy1);
		enemy1 = new EnemySpawn();
		enemy1->spawnTiming = 1500;
		waves[waves.size() - 1]->spawnTimings.push_back(enemy1);
		enemy1 = new EnemySpawn();
		enemy1->spawnTiming = 2000;
		waves[waves.size() - 1]->spawnTimings.push_back(enemy1);
		enemy1 = new EnemySpawn();
		enemy1->spawnTiming = 2500;
		waves[waves.size() - 1]->spawnTimings.push_back(enemy1);
		enemy1 = new EnemySpawn();
		enemy1->spawnTiming = 3000;
		waves[waves.size() - 1]->spawnTimings.push_back(enemy1);
		enemy1 = new EnemySpawn();
		enemy1->spawnTiming = 3500;
		waves[waves.size() - 1]->spawnTimings.push_back(enemy1);
		enemy1 = new EnemySpawn();
		enemy1->spawnTiming = 4000;
		waves[waves.size() - 1]->spawnTimings.push_back(enemy1);
		enemy1 = new EnemySpawn();
		enemy1->spawnTiming = 4500;
		waves[waves.size() - 1]->spawnTimings.push_back(enemy1);
		enemy1 = new EnemySpawn();
		enemy1->spawnTiming = 5000;
		waves[waves.size() - 1]->spawnTimings.push_back(enemy1);
	}
	if (Level == 2)
	{
		SetGold(99999);
		SetHealth(30);
		// Добавить загрузку уровня
		TowerType levelMap[11][16] =
		{
			{TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None},
			{TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None},
			{TowerType::Road, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::None, TowerType::None},
			{TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None},
			{TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None},
			{TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None},
			{TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None},
			{TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::None, TowerType::None},
			{TowerType::None, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::Road, TowerType::None, TowerType::None, TowerType::Road, TowerType::Road, TowerType::Road},
			{TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None},
			{TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None, TowerType::None},
		};
		for (int x = 0; x < 16; x++)
		{
			for (int y = 0; y < 11; y++)
			{
				LoadTowerInfo(towers[x][y], levelMap[y][x]);
			}
		}
	}
	SetWave(1);
	Start();
}

void GameWindow::UpdateInterface()
{
	targetImage->SetIsVisible(false);
	targetTitle->SetIsVisible(false);
	targetDescription->SetIsVisible(false);
	buildArchersTower->SetIsVisible(false);
	buildMageTower->SetIsVisible(false);
	destroyTower->SetIsVisible(false);
	if (target)
	{
		targetImage->SetIsVisible(true);
		targetImage->SetVisualResource(target->GetVisualResource());
		targetTitle->SetIsVisible(true);
		targetDescription->SetIsVisible(true);
		switch (target->GetType())
		{
		case TowerType::None:
			targetTitle->SetText("Земля");
			targetDescription->SetText("Пустой участок земли, пригодный для строительства");
			buildArchersTower->SetIsVisible(true);
			buildMageTower->SetIsVisible(true);
			break;
		case TowerType::Road:
			targetTitle->SetText("Дорога");
			targetDescription->SetText("Отрезок дороги, не предназначен для строительства");
			break;
		case TowerType::ArcherTower:
			targetTitle->SetText("Башня лучников");
			targetDescription->SetText((
				"Тип урона: Физ.\nНаносимый урон: " + to_string(target->GetDamage()) + "\n" +
				"Скорость атаки: " + to_string(target->GetAttackSpeed())).c_str());
			destroyTower->SetIsVisible(true);
			destroyTower->SetText("Сломать башню\n(Возврат 50)");
			break;
		case TowerType::MageTower:
			targetTitle->SetText("Башня мага");
			targetDescription->SetText((
				"Тип урона: Маг.\nНаносимый урон: " + to_string(target->GetDamage()) + "\n" + 
				"Скорость атаки: " + to_string(target->GetAttackSpeed())).c_str());
			destroyTower->SetIsVisible(true);
			destroyTower->SetText("Сломать башню\n(Возврат 100)");
			break;
		}
	}
	else
	{
		targetImage->SetIsVisible(false);
		targetTitle->SetIsVisible(false);
		targetDescription->SetIsVisible(false);
	}
}

void GameWindow::LoadTowerInfo(Tower* tower, TowerType type)
{
	tower->Stop();
	switch (type)
	{
	case TowerType::None:
		tower->SetType(TowerType::None);
		tower->SetVisualResource(grassTile);
		break;
	case TowerType::Road:
		tower->SetType(TowerType::Road);
		tower->SetVisualResource(roadTile);
		break;
	case TowerType::ArcherTower:
		tower->SetType(TowerType::ArcherTower);
		tower->SetVisualResource(archersTile);
		tower->SetDamage(30);
		tower->SetAttackSpeed(200);
		tower->Start();
		break;
	case TowerType::MageTower:
		tower->SetType(TowerType::MageTower);
		tower->SetVisualResource(magesTile);
		tower->SetDamage(60);
		tower->SetAttackSpeed(100);
		tower->Start();
		break;
	}
}

void GameWindow_KeyDown(Object* owner, SDL_KeyboardEvent e)
{
	GameWindow* window = (GameWindow*)owner;
	if (e.keysym.sym == SDLK_ESCAPE)
	{
		window->SetTarget(NULL);
	}
}

void Tower_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e)
{
	GameWindow* gWindow = (GameWindow*)owner;
	Tower* tower = (Tower*)sender;
	gWindow->SetTarget(tower);
	gWindow->UpdateInterface();
}

void BuildArchersTower_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e)
{
	GameWindow* gWindow = (GameWindow*)owner;
	if (gWindow->GetGold() >= 100)
	{
		gWindow->SetGold(gWindow->GetGold() - 100);
		gWindow->LoadTowerInfo(gWindow->GetTarget(), TowerType::ArcherTower);
		gWindow->UpdateInterface();
	}
}

void BuildMageTower_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e)
{
	GameWindow* gWindow = (GameWindow*)owner;
	if (gWindow->GetGold() >= 200)
	{
		gWindow->SetGold(gWindow->GetGold() - 200);
		gWindow->LoadTowerInfo(gWindow->GetTarget(), TowerType::MageTower);
		gWindow->UpdateInterface();
	}
}

void DestroyTowerButton_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e)
{
	GameWindow* gWindow = (GameWindow*)owner;
	switch (gWindow->GetTarget()->GetType())
	{
	case TowerType::ArcherTower:
		gWindow->SetGold(gWindow->GetGold() + 50);
		break;
	case TowerType::MageTower:
		gWindow->SetGold(gWindow->GetGold() + 100);
		break;
	}
	gWindow->LoadTowerInfo(gWindow->GetTarget(), TowerType::None);
	gWindow->UpdateInterface();
}

void LevelOneButton_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e)
{
	GameWindow* gWindow = (GameWindow*)owner;
	gWindow->LoadLevel(1);
}

void LevelTwoButton_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e)
{
	GameWindow* gWindow = (GameWindow*)owner;
	gWindow->LoadLevel(2);
}

void GameWindowTimer_Tick(Object* owner, Timer* sender, Uint32 deltaTime)
{
	GameWindow* window = (GameWindow*)owner;
	// Волны / победа
	if (window->GetWavesCount() > window->GetWave())
	{
		window->SetWave(window->GetWave() + 1);
	}
	else
	{
		window->Stop();
		cout << "Victory!!!!!!";
	}
}

void TowerTimer_Tick(Object* owner, Timer* sender, Uint32 deltaTime)
{
	GameWindow* window = (GameWindow*)owner;
	Tower* tower = (Tower*)sender;
	if (window->GetIsEnabled())
	{
		if (tower->GetType() == TowerType::MageTower)
		{
			cout << "Mage tower shoot" << endl;
		}
		else
		{
			cout << "Archers tower shoot" << endl;
		}
	}
}

void GameWindow_Update(Object* owner, Uint32 deltaTime)
{
	GameWindow* window = (GameWindow*)owner;
	window->UpdateWaveTimeText();
	if (window->GetIsEnabled())
	{
		window->SpawnEnemies(deltaTime);
	}
}
