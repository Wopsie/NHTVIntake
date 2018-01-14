#pragma once
#include <vector>
#include <SFML\Graphics.hpp>


struct BulletTransform {
	sf::RectangleShape shape;
	sf::Vector2f velocity;
	sf::Vector2f position;
	float x() {};
	float y() {};
	float left() {};
	float right() {};
	float top() {};
	float bottom() {};

	BulletTransform(float mX, float mY, float xVel);

};


class Bullet {
public:
	Bullet();
	BulletTransform Add(float, float, float);
	void Update();

private:
	//sf::RectangleShape bulletShape;
	//int speed;
	//int damage;
	//std::vector<float, float> position;
	//float myPosition[1];
	//BulletTransform transform;
};