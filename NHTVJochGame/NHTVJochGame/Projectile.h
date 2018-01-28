#pragma once
#include <vector>
#include "DrawableObj.h"

class Projectile {
public:
	Projectile(float, float, float, float);
	void Update();
	void Move();
	void Draw(RenderWindow &win);
	void Kill();
	RectangleShape& GetShape() { return shape; };
	FloatRect& GetCollider() { return collider; };
	float xPos();
	float yPos();
	int GetBounceCount() { return bounceCount; };
	bool getAlive() { return isAlive; };

private:
	void CheckScreenEdge();
	void CheckBounces();
	float GetMovementDirectionInDegrees(Vector2f);
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