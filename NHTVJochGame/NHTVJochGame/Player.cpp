#include <iostream>
#include <SFML\Main.hpp>
#include <functional>
#include "Player.h"
#include "DrawableObj.h"

Player::Player(float mX, float mY) {
	GetShape().setPosition(mX, mY);
	GetShape().setSize({ xSize, ySize });
	GetShape().setFillColor(sf::Color::Blue);
	GetShape().setOrigin(xSize / 2.f, ySize / 2.f);

	updateIndex = globals.AddToUpdateList([this]() {Update(); });
	//globals.AddToObjList(this->GetBase());
	//globals.AddToObjList(this);
}

void Player::Update(){
	Move();

	if (shotDelay < 0) shotDelay = 0;
	else shotDelay--;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && (shotDelay == 0)) {
		Shoot();
	}
}

///moves player shape & checks if it doesnt go off screen
void Player::Move() {
	GetShape().move(velocity);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && leftBox() > 0) {
		velocity.x = -speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && rightBox() < WINDOW_WIDTH) {
		velocity.x = speed;
	}
	else
		velocity.x = 0;
}

///pew
void Player::Shoot() {
	Projectile bullet = Projectile(xPos(), yPos(), velocity.x, -0.05f);
	globals.AddProjectile(bullet);
	shotDelay = 1000;
}

void Player::Draw(RenderWindow & win){
	win.draw(GetShape());
}

///getter methods for collision
float Player::xPos() {
	return GetShape().getPosition().x;
}

float Player::yPos(){
	return GetShape().getPosition().y;
}

float Player::leftBox(){
	return xPos() - (GetShape().getSize().x / 2.f);
}

float Player::rightBox(){
	return xPos() + (GetShape().getSize().x / 2.f);
}

float Player::topBox(){
	return 0.0f;
}

float Player::botBox(){
	return 0.0f;
}

/*
Player::Player(float mX, float mY){
	GetShape().setPosition(mX, mY);
	GetShape().setSize({ xSize, ySize });
	GetShape().setFillColor(sf::Color::Blue);
	GetShape().setOrigin(xSize / 2.f, ySize / 2.f);

	velocity = sf::Vector2f(0, 0);
	Start();
}

void Player::Start(){
	Globals globals;
	updateIndex = globals.AddToUpdateList([this]() {Update(); });
	globals.AddDrawable(GetShape());
	std::cout << updateIndex << std::endl;
}

void Player::Update(){

	//std::cout << "RUNNING PLAYER UPDATE" << std::endl;

	Move();
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
		std::cout << "SHOOTING" << std::endl;
		Shoot();
	}
}

void Player::Shoot(){
	//instantiate new projectile
	Projectile bullet = Projectile(xPos(), yPos(), velocity.x, 0.05f);
}

void Player::Move(){
	GetShape().move(velocity);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && leftBox() > 0){
		velocity.x = -speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && rightBox() < WINDOW_WIDTH) {
		velocity.x = speed;
	}
	else
		velocity.x = 0;
}

/*
sf::RectangleShape Player::GetShape(){
	return shape;
}


///getter methods for collision
float Player::xPos(){
	return GetShape().getPosition().x;
}

float Player::yPos()
{
	return GetShape().getPosition().y;
}

float Player::leftBox()
{
	return xPos() - (GetShape().getSize().x / 2.f);
}

float Player::rightBox()
{
	return xPos() + (GetShape().getSize().x / 2.f);
}

float Player::topBox()
{
	return 0.0f;
}

float Player::botBox()
{
	return 0.0f;
}
*/