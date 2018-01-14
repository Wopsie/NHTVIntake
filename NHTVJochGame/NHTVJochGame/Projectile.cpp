#include "Projectile.h"
#include "Globals.h"
#include <iostream>


Projectile::Projectile(float mX, float mY, float velX, float velY){
	velocity = sf::Vector2f(velX, velY);
	shape.setPosition(mX, mY);
	shape.setSize({ xSize, ySize });
	shape.setFillColor(sf::Color::Red);
	shape.setOrigin(xSize / 2.f, ySize / 2.f);
	//std::cout << left << std::endl;
	float f = leftBox();

	Start();
}

void Projectile::Destroy()
{
}

void Projectile::Update()
{
	shape.move(velocity);

	CheckScreenEdge();
	//std::cout << "Calling projectile::Update" << std::endl;
}

void Projectile::Start()
{
}

void Projectile::CheckScreenEdge()
{
	//horizontal
	if (leftBox() < 0){
		velocity.x = -velocity.x;
	}

	if (rightBox() > WINDOW_WIDTH){
		velocity.x = -velocity.x;
	}

	if (topBox() < 0) {
		velocity.y = -velocity.y;
	}

	if (botBox() > WINDOW_HEIGHT) {
		velocity.y = -velocity.y;
	}
}

sf::RectangleShape Projectile::GetShape(){
	return shape;
}

///getter methods for collision
float Projectile::xPos(){
	return shape.getPosition().x;
}

float Projectile::yPos(){
	return shape.getPosition().y;
}

float Projectile::leftBox(){
	return xPos() - (shape.getSize().x / 2.f);
}

float Projectile::rightBox(){
	return xPos() + (shape.getSize().x / 2.f);
}

float Projectile::topBox(){
	return yPos() - (shape.getSize().y / 2.f);
}

float Projectile::botBox(){
	return yPos() + (shape.getSize().y / 2.f);
}