#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet()
{
	Bullet_.posX = -50;
	Bullet_.posY = -50;
	Bullet_.radius = 5;
	Bullet_.speed = 10;
	Bullet_.isShot = false;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (Bullet_.isShot) {
		Bullet_.posY -= Bullet_.speed;
		if (Bullet_.posY <= -20) {
			Bullet_.isShot = false;
		}
	}
}

void Bullet::Draw()
{
	Novice::DrawEllipse(Bullet_.posX, Bullet_.posY, Bullet_.radius, Bullet_.radius, 0, RED, kFillModeSolid);
}
