#include<SFML\Window.hpp>
//#include<SFML\Graphics.hpp>
#include <iostream>
#include"Player.h"
#include "Projectile.h"
#include "Globals.h"
using namespace std;
using namespace sf;

int main() {
	RenderWindow window{ VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Reflective lil game" };
	//Globals globals;

	//Projectile bullet = Projectile(WINDOW_WIDTH /2.f, WINDOW_HEIGHT /2.f, 0.05f, 0.05f);
	Player player = Player(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 1.2f);


	//main loop
	while (true) {
		window.clear(Color::Black);

		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;

		//bullet.Update();
		//window.draw(bullet.GetShape());

		//player.Update();
		//window.draw(player.GetShape());
		std::cout << updateList.size() << std::endl;

		for (size_t i = 0; i < updateList.size(); i++){
			updateList[i]();
			window.draw(drawList[i]());
		}
		
		window.display();
	}

	return 0;

}


/*
using namespace std;
using namespace sf;
//screen
const int windowWidth = 800;
const int windowHeight = 600;
//ball
const float ballRadius = 10.0f;
const float ballVelocity = 8.0f;
//paddle
const float paddleWidth = 60.0f;
const float paddleHeight = 20.0f;
const float paddleVelocity = 6.0f;
const float paddleSpeed = 6.0f;

struct Ball
{
	CircleShape shape;
	Vector2f velocity = Vector2f(-ballVelocity, -ballVelocity);

	//constructor
	Ball(float mX, float mY)
	{
		shape.setPosition(mX, mY);
		shape.setRadius(ballRadius);
		shape.setFillColor(Color::Red);
		shape.setOrigin(ballRadius, ballRadius);
	}

	void update() { 
		shape.move(velocity); 

		//horizontal boundary stuff
		if (left() < 0)//if ball hits left side, make velocity positive so ball moves right
			velocity.x = ballVelocity;
		else if (right() > windowWidth)//if ball hits right side, make velocity negative so ball moves left
			velocity.x = -ballVelocity;

		//vertical boundary stuff
		if (top() < 0)
			velocity.y = ballVelocity;
		else if (bottom() > windowHeight)
			velocity.y = -ballVelocity;
	}

	// "collision" property values
	//here the positions relative to the object that should be seen as inside its collision box are stored
	float x()		{ return shape.getPosition().x; }
	float y()		{ return shape.getPosition().y; }
	float left()	{ return x() - shape.getRadius(); }
	float right()	{ return x() + shape.getRadius(); }
	float top()		{ return y() - shape.getRadius(); }
	float bottom()	{ return y() + shape.getRadius(); }
};

struct Paddle
{
	RectangleShape shape;
	Vector2f velocity;

	//constructor	constructor basicly makes new instance of object
	Paddle(float mX, float mY){
		shape.setPosition(mX, mY);
		shape.setSize({paddleWidth, paddleHeight});
		shape.setFillColor(Color::Blue);
		shape.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
	}

	void update(){
		shape.move(velocity);

		if (Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > 0) {
			//left arrow 
			velocity.x = -paddleVelocity;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && right() < windowWidth) {
			//right arrow
			velocity.x = paddleVelocity;
		}else
			velocity.x = 0;
	}

	float x()		{ return shape.getPosition().x; }
	float y()		{ return shape.getPosition().y; }
	float left()	{ return x() - shape.getSize().x / 2.f; }
	float right()	{ return x() + shape.getSize().x / 2.f; }
	float top()		{ return y() - shape.getSize().y / 2.f; }
	float bottom()	{ return y() + shape.getSize().y / 2.f; }
};

///found 
template<class T1, class T2> bool isIntersecting(T1& mA, T2& mB)
{
	return mA.right() >= mB.left() && mA.left() <= mB.right() && mA.bottom() >= mB.top() && mA.top() <= mb.botton();
}

int main(){
	RenderWindow window{ VideoMode(windowWidth, windowHeight), "Arkanoid - 1" };
	window.setFramerateLimit(60);

	Ball ball = Ball(windowWidth / 2, windowHeight / 2);
	Paddle paddle = Paddle(windowWidth / 2, windowHeight / 2);

	while (true){
		window.clear(Color::Black);

		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;
		ball.update();
		window.draw(ball.shape);
		paddle.update();
		window.draw(paddle.shape);

		window.display();
	}

	return 0;

}
*/