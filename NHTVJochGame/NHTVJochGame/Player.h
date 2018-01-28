#pragma once
#include <vector>
#include "DrawableObj.h"
#include "Globals.h"


class Player : public DrawableObj {
public:
	Player(float mX, float mY);
	void Update() override;
	void Move() override;
	void Draw(RenderWindow &win);
	FloatRect GetCollider() { return collider; };
	void ResetHealth() { health = 2; };
	float xPos();
	float yPos();

private:
	void Shoot();
	void TakeDamage();
	void CheckBulletCollisions();
	FloatRect collider;
	float xSize = 30;
	float ySize = 30;
	float speed = 7.f;
	int updateIndex;
	int shotDelay = 10;
	int invincibleTimer = 60;
	int health = 2;
	Globals globals;
};