#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;
using namespace std;

class DrawableObj {
public:
	DrawableObj();
	RectangleShape& GetShape() { return shape; };
	virtual void Update();
	virtual void Move();
	void Draw(RenderWindow &win);
	void Destroy();
	DrawableObj& GetBase() { return *this; };
	Vector2f velocity = Vector2f(0,0);

private:
	RectangleShape shape;
};