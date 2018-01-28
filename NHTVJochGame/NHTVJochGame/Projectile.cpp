#include "Projectile.h"
#include "Globals.h"
#include <iostream>
#include <algorithm>

Projectile::Projectile(float mX, float mY, float velX, float velY, bool isEnemy) {
	isAlive = true;
	velocity = Vector2f(velX, velY);
	GetShape().setPosition(mX, mY);
	GetShape().setSize({ xSize, ySize });
	GetShape().setFillColor(sf::Color::Red);
	GetShape().setOrigin(xSize / 2.f, ySize / 2.f);
	GetShape().setRotation(GetMovementDirectionInDegrees(velocity));
	collider = GetShape().getGlobalBounds();
	bounceCount = 0;
	isEnemyBullet = isEnemy;
	if (isEnemy)
		maxBounceCount = 0;
	else
		maxBounceCount = 2;
}

void Projectile::Update(){
	GetCollider() = GetShape().getGlobalBounds();
	Move();
	CheckScreenEdge();
}

void Projectile::Move(){
	velocity = Vector2f(velocity.x * speed, velocity.y * speed);
	GetShape().move(velocity);
}

void Projectile::CheckScreenEdge(){
	//horizontal
	if (xPos() - (collider.width / 2) < 0){
		//cout << "Bouncing on left or something haha" << endl;
		bounceCount++;
		CheckBounces();
		velocity.x = -velocity.x;
		//speed += 0.0001f;
		GetShape().setRotation(GetMovementDirectionInDegrees(velocity));
	}

	if (xPos() + (collider.width / 2) > WINDOW_WIDTH){
		bounceCount++;
		CheckBounces();
		velocity.x = -velocity.x;
		//speed += 0.0001f;
		GetShape().setRotation(GetMovementDirectionInDegrees(velocity));
	}
	//vertical
	if (yPos() - (collider.width / 2) < 0){
		bounceCount++;
		CheckBounces();
		velocity.y = -velocity.y;
		//speed += 0.0001f;
		GetShape().setRotation(GetMovementDirectionInDegrees(velocity));
	}

	if (yPos() + (collider.width / 2) > WINDOW_HEIGHT){
		bounceCount++;
		CheckBounces();
		velocity.y = -velocity.y;
		//speed += 0.00001f;
		GetShape().setRotation(GetMovementDirectionInDegrees(velocity));
	}
}

void Projectile::CheckBounces(){
	//cout << bounceCount << endl;
	if (bounceCount > maxBounceCount) {
		//remove object from memory
		//will be interesting to see what happens to the lists
		Kill();
	}
}

float Projectile::GetMovementDirectionInDegrees(sf::Vector2f vec){
	return (atan2f(vec.y, vec.x) / PI) * 180;
}

void Projectile::Kill(){
	cout << "Killing bullet" << endl;
	isAlive = false;
}

void Projectile::Draw(RenderWindow & win){
	win.draw(GetShape());
}

///getter methods for collision
float Projectile::xPos() {
	return GetShape().getPosition().x;
}

float Projectile::yPos() {
	return GetShape().getPosition().y;
}