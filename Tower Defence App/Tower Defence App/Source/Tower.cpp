#include "Tower.h"

TowerType Tower::GetType()
{
	return type;
}

void Tower::SetType(TowerType Type)
{
	type = Type;
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
	SetInterval(2000 / (attackSpeed / 100));
}

bool Tower::GetIsReady()
{
	return isReady;
}

void Tower::SetIsReady(bool IsReady)
{
	isReady = IsReady;
}
