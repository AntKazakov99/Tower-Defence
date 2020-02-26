#include "Enemy.h"

int Enemy::GetHealth()
{
	return health;
}

void Enemy::SetHealth(int health)
{
	this->health = health;
}

int Enemy::GetMovespeed()
{
	return movespeed;
}

void Enemy::SetMovespeed(int Movespeed)
{
	movespeed = Movespeed;
}

bool Enemy::Move(Uint32 deltaTime)
{
	if (paths.size() >= currentPath)
	{
		// ƒвижение
		int move = (int)((25.0 / 1000.0) * ((double)movespeed / 100.0) * ((double)deltaTime + (double)downtime));
		if (move)
		{
			while (move)
			{
				int currentMove = 0;
				if (move >= paths[currentPath - 1]->length - passed)
				{
					currentMove = paths[currentPath - 1]->length - passed;
				}
				else
				{
					currentMove = move;
				}
				switch (paths[currentPath - 1]->direction)
				{
				case Top:
					SetTop(GetTop() - currentMove);
					break;
				case Right:
					SetLeft(GetLeft() + currentMove);
					break;
				case Down:
					SetTop(GetTop() + currentMove);
					break;
				case Left:
					SetLeft(GetLeft() - currentMove);
					break;
				default:
					break;
				}
				move -= currentMove;
				passed += currentMove;
				if (passed >= paths[currentPath - 1]->length)
				{
					currentPath++;
					passed = 0;
					if (paths.size() < currentPath)
					{
						move = 0;
					}
				}
			}
			downtime = 0;
		}
		else
		{
			downtime += deltaTime;
		}
		cout << "Move: " << move << "Downtime: " << downtime << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void Enemy::AddPath(Path* path)
{
	paths.push_back(path);
}
