#pragma once
#include <vector>
#include "DrawableObj.h"
#include "Globals.h"

//#include <SFML\Graphics.hpp>

class Player : public DrawableObj {
public:
	Player(float mX, float mY);
	void Update() override;
	void Move() override;
	void Draw(RenderWindow &win);
	float xPos();
	float yPos();
	float leftBox();
	float rightBox();
	float topBox();
	float botBox();

private:
	void Shoot();
	void TakeDamage();
	float xSize = 20;
	float ySize = 20;
	float speed = 0.05f;
	int updateIndex;
	int shotDelay;
	Globals globals;
};

/*
class Player {
public:
	Player(float mX, float mY); //constructor
	void Update();
	void Shoot();
	void TakeDamage();
	void Destroy();
	void Move();
	void Reset();
	void Draw();
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
	float xSize = 20;
	float ySize = 20;
	float speed = 0.05f;
	int updateIndex;
	void Start();
	void CheckScreenEdge();
};
*/