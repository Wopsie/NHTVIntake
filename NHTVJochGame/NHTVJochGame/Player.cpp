#include <iostream>
#include <SFML\Main.hpp>
#include <functional>
#include "Player.h"
#include "Globals.h"
#include "Projectile.h"

Player::Player(float mX, float mY){
	shape.setPosition(mX, mY);
	shape.setSize({ xSize, ySize });
	shape.setFillColor(sf::Color::Blue);
	shape.setOrigin(xSize / 2.f, ySize / 2.f);

	velocity = sf::Vector2f(0, 0);
	Start();
}

void Player::Start(){
	Globals globals;
	updateIndex = globals.AddToUpdateList([this]() {Update(); });
	globals.AddToDrawList([this]() {GetShape(); });
	std::cout << updateIndex << std::endl;
}

void Player::Update(){

	std::cout << "RUNNING PLAYER UPDATE" << std::endl;

	Move();
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
		std::cout << "SHOOTING" << std::endl;
		Shoot();
	}
}

void Player::Shoot(){
	//instantiate new projectile
	Projectile bullet = Projectile(xPos(), yPos(), velocity.x, 0.05f);

}

void Player::Move(){
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

sf::RectangleShape Player::GetShape(){
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