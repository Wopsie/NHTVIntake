#pragma once
#include <vector>
#include <SFML\Graphics.hpp>

class Player {
public:
	Player(float mX, float mY); //constructor
	void Update();
	void Shoot();
	void TakeDamage();
	void Destroy();
	void Move();
	void Reset();
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
	float xSize = 20;
	float ySize = 20;
	float speed = 0.05f;
	int updateIndex;
	void Start();
	void CheckScreenEdge();
};