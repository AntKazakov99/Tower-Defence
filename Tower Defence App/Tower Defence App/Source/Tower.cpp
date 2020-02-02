#include "Tower.h"

TowerType Tower::GetType()
{
	return type;
}

void Tower::SetType(TowerType Type)
{
	type = Type;
}

int Tower::GetLevel()
{
	return level;
}

void Tower::SetLevel(int Level)
{
	level = Level;
}

int Tower::GetDamage()
{
	return damage;
}

void Tower::SetDamage(int Damage)
{
	damage = Damage;
}

int Tower::GetAttackSpeed()
{
	return attackSpeed;
}

void Tower::SetAttackSpeed(int AttackSpeed)
{
	attackSpeed = AttackSpeed;
}
