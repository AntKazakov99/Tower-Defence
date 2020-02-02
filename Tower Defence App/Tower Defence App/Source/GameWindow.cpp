#include "GameWindow.h"

GameWindow::GameWindow()
{
	SetTitle("Tower Defence ver.0.0.1");
	Initialize();

	// Создает объекты башен
	for (int x = 0; x < 16; x++)
	{
		for (int y = 0; y < 11; y++)
		{
			towers[x][y] = new Tower();
			towers[x][y]->SetLocation(50 * x, 50 * y);
			towers[x][y]->SetSize(50, 50);
			AddVisualElement(towers[x][y]);
			towers[x][y]->SetClick(Tower_Click);
		}
	}

	Image* interface = new Image();
	interface->SetVisualResource(new VisualResource(IMG_Load(".\\Resources\\interface.png")));
	AddVisualElement(interface);

	selectTargetImage->SetVisualResource(new VisualResource(IMG_Load(".\\Resources\\target.png")));
	selectTargetImage->SetSize(50, 50);
	selectTargetImage->SetIsVisible(false);
	AddVisualElement(selectTargetImage);

	// Добавляет текст "Текущее здоровье:" на экран
	Text* currentHealthText = new Text("Текущее здоровье: ");
	currentHealthText->SetLocation(815, 11);
	currentHealthText->SetForeground({ 255, 255, 255 });
	AddVisualElement(currentHealthText);

	// Выводит показатель здоровья игрока на экран
	healthText->SetLocation(815 + currentHealthText->GetWidth(), 11);
	healthText->SetForeground({ 220, 0, 0 });
	AddVisualElement(healthText);

	// Добавляет текст "Текущее золото:" на экран
	Text* currentGoldText = new Text("Текущее золото: ");
	currentGoldText->SetLocation(815, 26);
	currentGoldText->SetForeground({ 255, 255, 255 });
	AddVisualElement(currentGoldText);

	// Выводит показатель золота игрока на экран
	goldText->SetLocation(815 + currentGoldText->GetWidth(), 26);
	goldText->SetForeground({ 220, 220, 0 });
	AddVisualElement(goldText);

	// Изображение выделенного элемента
	targetImage->SetLocation(865, 50);
	targetImage->SetSize(100, 100);
	AddVisualElement(targetImage);

	// Название выделенного элемента
	targetTitle->SetLocation(815, 150);
	targetTitle->SetFontSize(14);
	AddVisualElement(targetTitle);

	// Название выделенного элемента
	targetDescription->SetLocation(815, 167);
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

void GameWindow::KeyDown(SDL_KeyboardEvent e)
{
	if (e.keysym.sym == SDLK_ESCAPE)
	{
		SetTarget(NULL);
	}
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
				LoadTowerInfo(towers[x][y], levelMap[y][x], 0);
			}
		}
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
				LoadTowerInfo(towers[x][y], levelMap[y][x], 0);
			}
		}
	}
}

void GameWindow::UpdateInterface()
{
	targetImage->SetIsVisible(false);
	buildArchersTower->SetIsVisible(false);
	buildMageTower->SetIsVisible(false);
	if (target)
	{
		targetImage->SetIsVisible(true);
		targetImage->SetVisualResource(target->GetVisualResource());
		switch (target->GetType())
		{
		case TowerType::None:
			targetTitle->SetText("Земля");
			targetDescription->SetIsVisible(true);
			targetDescription->SetText("Пустой участок земли, пригодный для строительства");
			buildArchersTower->SetIsVisible(true);
			buildMageTower->SetIsVisible(true);
			break;
		case TowerType::Road:
			targetTitle->SetText("Дорога");
			targetDescription->SetIsVisible(true);
			targetDescription->SetText("Отрезок дороги, не предназначен для строительства");
			break;
		case TowerType::ArcherTower:
			targetTitle->SetText("Башня лучников");
			targetDescription->SetText((
				"Уровень: " + to_string(target->GetLevel()) + "\n" +
				"Тип урона: Физ.\n" +
				"Наносимый урон: " + to_string(target->GetDamage()) + "\n" +
				"Скорость атаки: " + to_string(target->GetAttackSpeed())).c_str());
			break;
		case TowerType::MageTower:
			targetTitle->SetText("Башня мага");
			targetDescription->SetText((
				"Уровень: " + to_string(target->GetLevel()) + "\n" +
				"Тип урона: Маг.\n" + 
				"Наносимый урон: " + to_string(target->GetDamage()) + "\n" + 
				"Скорость атаки: " + to_string(target->GetAttackSpeed())).c_str());
			break;
		}
	}
}

void GameWindow::LoadTowerInfo(Tower* tower, TowerType type, int level)
{
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
		tower->SetLevel(1);
		tower->SetDamage(30);
		tower->SetAttackSpeed(100);
		break;
	case TowerType::MageTower:
		tower->SetType(TowerType::MageTower);
		tower->SetVisualResource(magesTile);
		tower->SetLevel(1);
		tower->SetDamage(60);
		tower->SetAttackSpeed(0);
		break;
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
		gWindow->LoadTowerInfo(gWindow->GetTarget(), TowerType::ArcherTower, 1);
		gWindow->UpdateInterface();
	}
}

void BuildMageTower_Click(Object* owner, Object* sender, SDL_MouseButtonEvent e)
{
	GameWindow* gWindow = (GameWindow*)owner;
	if (gWindow->GetGold() >= 200)
	{
		gWindow->SetGold(gWindow->GetGold() - 200);
		gWindow->LoadTowerInfo(gWindow->GetTarget(), TowerType::MageTower, 1);
		gWindow->UpdateInterface();
	}
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