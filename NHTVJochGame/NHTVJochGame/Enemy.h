#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Enemy {
public:
	Enemy(float mX, float mY);
	void Update();
	void Draw(RenderWindow &win);
	void Kill();
	void CheckBulletCollisions();
	RectangleShape& GetShape() { return shape; };
	FloatRect& GetCollider() { return collider; };
	float xPos() { return GetShape().getPosition().x; };
	float yPos() { return GetShape().getPosition().y; };
	bool getAlive() { return isAlive; };

private:
	void Move();
	RectangleShape shape;
	FloatRect collider;
	bool isAlive;
	float xSize = 60;
	float ySize = 40;
};