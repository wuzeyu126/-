#pragma once

typedef struct {
	int posX;
	int posY;
	int radius;
	int speed;
	bool isAlive;
}_Player;

typedef struct {
	int posX;
	int posY;
	int radius;
	int speed;
	bool isShot;
}_Bullet;

typedef struct {
	int posX;
	int posY;
	int radius;
	int speed;
	bool isEnemyAlive;
}_Enemy;