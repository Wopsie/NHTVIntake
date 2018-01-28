#include <iostream>
#include <SFML\Main.hpp>
#include <functional>
#include "Player.h"
#include "DrawableObj.h"

Player::Player(float mX, float mY) {
	GetShape().setPosition(mX, mY);
	GetShape().setSize({ xSize, ySize });
	GetShape().setFillColor(sf::Color::Blue);
	GetShape().setOrigin(xSize / 2.f, ySize / 2.f);
	collider = GetShape().getGlobalBounds();
	updateIndex = globals.AddToUpdateList([this]() {Update(); });
	//globals.AddToObjList(this->GetBase());
	//globals.AddToObjList(this);
	shotDelay = 10;
}

void Player::Update(){
	GetCollider() = GetShape().getGlobalBounds();
	Move();

	if (shotDelay < 0) shotDelay = 0;
	else shotDelay--;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && (shotDelay == 0)) {
		Shoot();
	}
}

///moves player shape & checks if it doesnt go off screen
void Player::Move() {
	GetShape().move(velocity);

	//cout << collider.left << endl;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && (xPos() - (collider.width / 2)) > 0) {
		velocity.x = -speed;

		//cout << "not colliding with left side" << endl;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && (xPos() + (collider.width / 2)) < WINDOW_WIDTH) {
		velocity.x = speed;
	}else
		velocity.x = 0;
}

///pew
void Player::Shoot() {
	Projectile bullet = Projectile(xPos(), yPos(), velocity.x, -7.f, false);
	globals.AddProjectile(bullet);
	shotDelay = 10;
}

void Player::Draw(RenderWindow & win){
	win.draw(GetShape());
}

///convenient getter methods for position
float Player::xPos() {
	return GetShape().getPosition().x;
}

float Player::yPos(){
	return GetShape().getPosition().y;
}