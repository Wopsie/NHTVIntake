#include <iostream>
#include "Enemy.h"
#include "Globals.h"

Enemy::Enemy(float mX, float mY){
	isAlive = true;
	GetShape().setPosition(mX, mY);
	GetShape().setSize({ xSize, ySize });
	GetShape().setFillColor(sf::Color::Green);
	GetShape().setOrigin(xSize / 2.f, ySize / 2.f);
	GetCollider() = GetShape().getGlobalBounds();
}

void Enemy::Update(){
	GetCollider() = GetShape().getGlobalBounds();
	CheckBulletCollisions();
}

void Enemy::Draw(RenderWindow & win){
	win.draw(GetShape());
}

void Enemy::CheckBulletCollisions(){
	FloatRect intersection;
	for (size_t i = 0; i < projectileList.size(); i++){
		if (projectileList[i].GetCollider().intersects(GetCollider(), intersection)) {
			//valid collision
			cout << "Collision" << endl;
			if (projectileList[i].getAlive() && projectileList[i].GetBounceCount() > 0) {
				//bullet can hurt enemy
				cout << "Destroy enemy" << endl;
			}else {
				//bullet cannot hurt enemy
				cout << "destroy bullet" << endl;
				projectileList[i].Kill();
			}
		}
	}
}


void Enemy::Kill(){
	isAlive = false;
}

