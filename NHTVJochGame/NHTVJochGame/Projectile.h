#pragma once
#include <vector>
//#include <math.h>
#include "DrawableObj.h"

class Projectile {
public:
	Projectile(float, float, float, float);
	void Update();
	void Move();
	void Draw(RenderWindow &win);
	RectangleShape& GetShape() { return shape; };
	float xPos();
	float yPos();
	bool getAlive() { return isAlive; };

private:
	void CheckScreenEdge();
	void CheckBounces();
	float GetMovementDirectionInDegrees(Vector2f);
	void Kill();
	RectangleShape shape;
	FloatRect collider;
	Vector2f velocity;
	float xSize = 30;
	float ySize = 2;
	float speed = 1.f;
	int updateIndex;
	int bounceCount = 0;
	bool isAlive;
};