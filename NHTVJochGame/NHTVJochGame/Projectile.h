#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <cmath>

class Projectile {
public:
	//mX mY velX, velY
	Projectile(float, float, float, float);
	void Destroy();
	void Update();
	void Start();
	sf::RectangleShape GetShape();
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
	void CheckScreenEdge();
};