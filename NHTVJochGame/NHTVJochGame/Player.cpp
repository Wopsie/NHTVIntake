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
	shotDelay = 10;
	health = 2;
}

void Player::Update(){
	//cooldown shooting
	if (shotDelay < 0) shotDelay = 0;
	else shotDelay--;
	//cooldown i-frames
	if (invincibleTimer < 0) invincibleTimer = 0;
	else invincibleTimer--;

	GetCollider() = GetShape().getGlobalBounds();
	CheckBulletCollisions();
	Move();
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && (shotDelay == 0)) {
		Shoot();
	}
}

///moves player shape & checks if it doesnt go off screen
void Player::Move() {
	GetShape().move(velocity);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && (xPos() - (collider.width / 2)) > 0) {
		velocity.x = -speed;
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
	shotDelay = 30;
}

void Player::TakeDamage(){
	invincibleTimer = 60;
	health--;
	if (health < 0){
		//gameover
		globals.GameOver(false, 10);
	}
}

void Player::CheckBulletCollisions(){
	for (size_t i = 0; i < projectileList.size(); i++){
		if (GetShape().getGlobalBounds().intersects(projectileList[i].GetShape().getGlobalBounds())){
			if (projectileList[i].GetIsEnemy()){
				//cout << "PLAYER COLLISION WITH ENEMY BULLET " << endl;
				if (invincibleTimer == 0) {
					TakeDamage();
					projectileList[i].Kill();
				}
			}
		}
	}
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