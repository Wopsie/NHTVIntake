#pragma once
#include <vector>
//#include <cmath>
#include "DrawableObj.h"


class Projectile {
public:
	Projectile(float, float, float, float);
	void Update();
	void Move();
	RectangleShape& GetShape() { return shape; };
	void Draw(RenderWindow &win);
	float xPos();
	float yPos();
	float leftBox();
	float rightBox();
	float topBox();
	float botBox();

private:
	void CheckScreenEdge();
	RectangleShape shape;
	sf::Vector2f velocity;
	float xSize = 20;
	float ySize = 20;
	float speed = 0.05f;
	int updateIndex;
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