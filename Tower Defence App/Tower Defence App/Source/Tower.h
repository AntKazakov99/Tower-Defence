#pragma once
#include "Image.h"

enum class TowerType
{
	None,
	Road,
	ArcherTower,
	MageTower
};

// Тип объекта
class Tower :
	public Image
{
	// Тип башни
	TowerType type = TowerType::None;
	// Уровень башни
	int level = 0;
	// Урон наносимый башней
	int damage = 0;
	// Скорость атаки башни
	int attackSpeed = 0;

public:
	// Возвращает тип объекта
	TowerType GetType();
	// Задает тип объекта
	void SetType(TowerType Type);
	// Возвращает уровень башни
	int GetLevel();
	// Задает уровень башни
	void SetLevel(int Level);
	// Возвращает наносимый башней урон
	int GetDamage();
	// Задает наносимый башней урон
	void SetDamage(int Damage);
	// Возвращает скорость атаки башни
	int GetAttackSpeed();
	// Задает скорость атаки башни
	void SetAttackSpeed(int AttackSpeed);

};
