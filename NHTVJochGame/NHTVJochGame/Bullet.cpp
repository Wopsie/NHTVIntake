#include "Bullet.h"

BulletTransform::BulletTransform(float mX, float mY, float xVel)
{
	velocity = sf::Vector2f(xVel, 5.f);
	shape.setPosition(mX, mY);
	shape.setSize({ 50,10 });
	shape.setFillColor(sf::Color::Red);
	shape.setOrigin(5 / 2.f, 1 / 2.f);
}

Bullet::Bullet()
{
}

BulletTransform Bullet::Add(float mX, float mY, float xVel)
{
	BulletTransform transform = BulletTransform::BulletTransform(mX, mY, xVel);
	return transform;
}

///updates all the bullets positions
void Bullet::Update()
{
	
}


