#pragma once
#include <vector>
//#include <math.h>
#include "DrawableObj.h"

#define _USE_MATH_DEFINES


class Projectile {
public:
	Projectile(float, float, float, float);
	void Update();
	void Move();
	void Draw(RenderWindow &win);
	RectangleShape& GetShape() { return shape; };
	float xPos();
	float yPos();
	float leftBox();
	float rightBox();
	float topBox();
	float botBox();
	bool getAlive() { return isAlive; };

private:
	void CheckScreenEdge();
	void CheckBounces();
	float GetMovementDirectionInDegrees(sf::Vector2f);
	void Kill();
	RectangleShape shape;
	sf::Vector2f velocity;
	float xSize = 30;
	float ySize = 2;
	float speed = 1.f;
	int updateIndex;
	int bounceCount = 0;
	bool isAlive;
};

/*
class Projectile {
public:
	//mX mY velX, velY
	Projectile(float, float, float, float);
	void Destroy();
	void Update();
	void Start();
	sf::RectangleShape& GetShape() { return shape; };
	float xPos();
	float yPos();
	float leftBox();
	float rightBox();
	float topBox();
	float botBox();

private: 
	sf::RectangleShape shape;
	sf::Vector2f velocity;
	float xSize = 45;
	float ySize = 5;
	int updateIndex;
	void CheckScreenEdge();
};*/