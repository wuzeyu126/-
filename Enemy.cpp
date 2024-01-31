#include "Enemy.h"

Enemy::Enemy(int posX, int posY, int radius, int speed)
{
	Enemy_.posX = posX;
	Enemy_.posY = posY;
	Enemy_.radius = radius;
	Enemy_.speed = speed;
	Enemy_.isEnemyAlive = true;
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	Enemy_.posX += Enemy_.speed;
	if (Enemy_.posX >= 1280 - Enemy_.radius || Enemy_.posX <= Enemy_.radius) {
		Enemy_.speed *= -1;
	}
}

void Enemy::Draw()
{
	Novice::DrawEllipse(Enemy_.posX, Enemy_.posY, Enemy_.radius, Enemy_.radius, 0, GREEN, kFillModeSolid);
}
