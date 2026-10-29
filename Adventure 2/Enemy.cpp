#include "Enemy.h"

Enemy::Enemy(std::string name, int l, int hp, int e, int damage, int D)
{
	InitCharacter(name);
	SetLevel(l);
	SetHp(hp),
	SetDamageMin(damage / 2);
	SetDamageMax(damage + 2);
	SetExp(e);
}

Enemy::Enemy()
{
}

void Enemy::InitEnemy()
{
}

void Enemy::StatsEnemy()
{
	PrintStats();
}

Enemy::~Enemy()
{
}
