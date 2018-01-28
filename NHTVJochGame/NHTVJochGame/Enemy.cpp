#include "Enemy.h"
#include "Globals.h"

Enemy::Enemy(float mX, float mY){
	GetShape().setPosition(mX, mY);
	GetShape().setSize({ xSize, ySize });
	GetShape().setFillColor(sf::Color::Blue);
	GetShape().setOrigin(xSize / 2.f, ySize / 2.f);
	collider = GetShape().getGlobalBounds();
}

void Enemy::Update(){

}

void Enemy::Draw(RenderWindow & win){
	win.draw(GetShape());
}
