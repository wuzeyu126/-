#include "Player.h"
#include "Novice.h"

Player::Player()
{
	_Bullet_ = new Bullet;
	player_.posX = 640;
	player_.posY = 360;
	player_.radius = 20;
	player_.speed = 3;
	player_.isAlive = true;
}

Player::~Player()
{
	delete _Bullet_;
}

void Player::Update(char* keys, char* preKeys)
{
	if (keys[DIK_W]) {
		player_.posY -= player_.speed;
	}
	if (keys[DIK_S]) {
		player_.posY += player_.speed;
	}
	if (keys[DIK_A]) {
		player_.posX -= player_.speed;
	}
	if (keys[DIK_D]) {
		player_.posX += player_.speed;
	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && !_Bullet_->Bullet_.isShot) {
		_Bullet_->Bullet_.posX = player_.posX;
		_Bullet_->Bullet_.posY = player_.posY;
		_Bullet_->Bullet_.isShot = true;
	}
	_Bullet_->Update();
}

void Player::Draw()
{
	_Bullet_->Draw();
	Novice::DrawEllipse(player_.posX, player_.posY, player_.radius, player_.radius, 0, WHITE, kFillModeSolid);
}

int Player::getPlayerPosX()
{
	return player_.posX;
}

int Player::getPlayerPosY()
{
	return player_.posY;
}

int Player::getPlayerRadius()
{
	return player_.radius;
}

bool Player::getIsPlayerAlive()
{
	return player_.isAlive;
}
