#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Enemy {
public:
	Enemy(float mX, float mY);
	void Update();
	void Draw(RenderWindow &win);
	RectangleShape& GetShape() { return shape; };
	void Kill();
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