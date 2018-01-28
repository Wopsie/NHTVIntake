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
	FloatRect GetCollider() { return collider; };
	float xPos();
	float yPos();

private:
	void Shoot();
	void TakeDamage();
	void CheckBulletCollisions();
	FloatRect collider;
	float xSize = 20;
	float ySize = 20;
	float speed = 7.f;
	int updateIndex;
	int shotDelay = 10;
	int invincibleTimer = 60;
	int health = 2;
	Globals globals;
};