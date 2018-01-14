#include <SFML\Main.hpp>
#include "Player.h"
#include "Globals.h"

Player::Player(float mX, float mY){

	shape.setPosition(mX, mY);
	shape.setSize({ xSize, ySize });
	shape.setFillColor(sf::Color::Blue);
	shape.setOrigin(xSize / 2.f, ySize / 2.f);

	velocity = sf::Vector2f(0, 0);
	Start();
}

void Player::Start()
{
}

void Player::Update()
{
	Move();
	
	
}

void Player::Move()
{
	shape.move(velocity);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && leftBox() > 0){
		velocity.x = -speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && rightBox() < WINDOW_WIDTH) {
		velocity.x = speed;
	}
	else
		velocity.x = 0;
}

sf::RectangleShape Player::GetShape()
{
	return shape;
}


///getter methods for collision
float Player::xPos()
{
	return shape.getPosition().x;
}

float Player::yPos()
{
	return shape.getPosition().y;
}

float Player::leftBox()
{
	return xPos() - (shape.getSize().x / 2.f);
}

float Player::rightBox()
{
	return xPos() + (shape.getSize().x / 2.f);
}

float Player::topBox()
{
	return 0.0f;
}

float Player::botBox()
{
	return 0.0f;
}


