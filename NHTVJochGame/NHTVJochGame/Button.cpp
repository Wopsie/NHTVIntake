#include "Button.h"

Button::Button(float mX, float mY, Vector2f size, Color color, Text text){
	GetShape().setPosition(mX, mY);
	GetShape().setSize(size);
	GetShape().setFillColor(color);
	GetShape().setOrigin(size.x / 2.f, size.y / 2.f);
	collider = GetShape().getGlobalBounds();
}
