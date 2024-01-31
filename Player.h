#pragma once
#include "Bullet.h"


class Player:public Bullet
{
private:
	_Player player_;
public:
	Bullet* _Bullet_;
	Player();
	~Player();
	void Update(char* keys,char* preKeys);
	void Draw();
	int getPlayerPosX();
	int getPlayerPosY();
	int getPlayerRadius();
	bool getIsPlayerAlive();
};

