#include <iostream>
#include <cstdlib>
#include "Enemy.h"
#include "Globals.h"

Enemy::Enemy(float mX, float mY){
	isAlive = true;
	GetShape().setPosition(mX, mY);
	GetShape().setSize({ xSize, ySize });
	GetShape().setFillColor(sf::Color::Green);
	GetShape().setOrigin(xSize / 2.f, ySize / 2.f);
	GetCollider() = GetShape().getGlobalBounds();
	xMoveCount = 0;
	goLeft = false;
}

void Enemy::Update(){
	GetCollider() = GetShape().getGlobalBounds();
	CheckBulletCollisions();
	Move();
	Shoot();
}

void Enemy::Move(){

	if (moveTimer < 0) moveTimer = 0;
	else moveTimer--;

	if (moveTimer == 0){
		//Set Velocity right
		if (xMoveCount < 10 && goLeft == false)
			velocity = Vector2f(5, 0);
		else if(xMoveCount < 10 && goLeft == true)
			velocity = Vector2f(-5, 0);
		else if (xMoveCount == 10){
			velocity = Vector2f(0, 15);
			xMoveCount = 0;
			goLeft = !goLeft;
		}
		//move
		GetShape().move(velocity);
		moveTimer = 60;
		xMoveCount++;
	}
}

void Enemy::Shoot(){
	canShoot = rand() % 3500;
	if (canShoot == 0){
		Globals globals;
		//you can shoot
		//cout << "SHOOT" << endl;
		Projectile bullet = Projectile(xPos(), yPos(), 0, 7, true);
		globals.AddProjectile(bullet);
	}
}

void Enemy::Draw(RenderWindow & win){
	win.draw(GetShape());
}

void Enemy::CheckBulletCollisions(){
	FloatRect intersection;
	for (size_t i = 0; i < projectileList.size(); i++){
		if (projectileList[i].GetCollider().intersects(GetCollider(), intersection)) {
			//valid collision
			if (projectileList[i].GetIsEnemy()) {
				//do nothing, friendly fire has no effect
			}else if(projectileList[i].getAlive() && projectileList[i].GetBounceCount() > 0){
				//bullet can hurt enemy
				Kill();
			}else {
				//bullet cannot hurt enemy
				projectileList[i].Kill();
			}
		}
	}
}

void Enemy::Kill(){
	Globals globals;
	globals.AddScore();
	isAlive = false;
}