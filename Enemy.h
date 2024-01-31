#pragma once
#include "struct.h"
#include "Novice.h"

class Enemy
{

	
public:
	_Enemy Enemy_;
	Enemy(int posX, int posY, int radius, int speed);
	~Enemy();
	void Update();
	void Draw();
};

