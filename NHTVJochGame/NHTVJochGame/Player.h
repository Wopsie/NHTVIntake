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

private:
	void Shoot();
	void TakeDamage();
	FloatRect collider;
	float xSize = 20;
	float ySize = 20;
	float speed = 0.05f;
	int updateIndex;
	int shotDelay;
	Globals globals;
};