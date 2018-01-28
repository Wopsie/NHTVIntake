#pragma once
#include <SFML\Graphics.hpp>
#include <string>


using namespace sf;

class Button {
public:
	Button(float mX, float mY, Vector2f size, Color color, Text text);
	RectangleShape GetShape() { return shape; };
	FloatRect GetCollider() { return collider; };

private:
	RectangleShape shape;
	FloatRect collider;

};