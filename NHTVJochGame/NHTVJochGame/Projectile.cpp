#include "Projectile.h"
#include "Globals.h"
#include <iostream>

Projectile::Projectile(float mX, float mY, float velX, float velY) {
	velocity = Vector2f(velX, velY);
	GetShape().setPosition(mX, mY);
	GetShape().setSize({ xSize, ySize });
	GetShape().setFillColor(sf::Color::Red);
	GetShape().setOrigin(xSize / 2.f, ySize / 2.f);
	GetShape().setRotation(GetMovementDirectionInDegrees(velocity));
}

void Projectile::Update(){
	Move();
	CheckScreenEdge();
}

void Projectile::Move(){
	velocity = Vector2f(velocity.x * speed, velocity.y * speed);
	GetShape().move(velocity);
}

void Projectile::CheckScreenEdge()
{
	//horizontal
	if (leftBox() < 0) {
		velocity.x = -velocity.x;
		bounceCount++;
		//speed += 0.0001f;
		GetShape().setRotation(GetMovementDirectionInDegrees(velocity));
	}

	if (rightBox() > WINDOW_WIDTH) {
		velocity.x = -velocity.x;
		bounceCount++;
		//speed += 0.0001f;
		GetShape().setRotation(GetMovementDirectionInDegrees(velocity));
	}

	//vertical
	if (topBox() < 0) {
		velocity.y = -velocity.y;
		bounceCount++;
		//speed += 0.0001f;
		GetShape().setRotation(GetMovementDirectionInDegrees(velocity));
	}

	if (botBox() > WINDOW_HEIGHT) {
		velocity.y = -velocity.y;
		bounceCount++;
		//speed += 0.00001f;
		GetShape().setRotation(GetMovementDirectionInDegrees(velocity));
	}
}

void Projectile::CheckBounces(){
	if (bounceCount > 2) {
		//remove object from memory
		//will be interesting to see what happens to the lists
	}
}

float Projectile::GetMovementDirectionInDegrees(sf::Vector2f vec){
	return (atan2f(vec.y, vec.x) / PI) * 180;
}

void Projectile::Draw(RenderWindow & win){
	win.draw(GetShape());
}

///getter methods for collision
float Projectile::xPos() {
	return GetShape().getPosition().x;
}

float Projectile::yPos() {
	return GetShape().getPosition().y;
}

float Projectile::leftBox() {
	return xPos() - (GetShape().getSize().x / 2.f);
}

float Projectile::rightBox() {
	return xPos() + (GetShape().getSize().x / 2.f);
}

float Projectile::topBox() {
	return yPos() - (GetShape().getSize().y / 2.f);
}

float Projectile::botBox() {
	return yPos() + (GetShape().getSize().y / 2.f);
}

/*
Projectile::Projectile(float mX, float mY, float velX, float velY){
	velocity = sf::Vector2f(velX, velY);
	GetShape().setPosition(mX, mY);
	GetShape().setSize({ xSize, ySize });
	GetShape().setFillColor(sf::Color::Red);
	GetShape().setOrigin(xSize / 2.f, ySize / 2.f);
	float f = leftBox();
	
	Start();
}

void Projectile::Start(){
	Globals globals;
	updateIndex = globals.AddToUpdateList([this]() {Update(); });
	//globals.AddDrawable(GetShape());
}

void Projectile::Destroy(){

}

void Projectile::Update(){
	GetShape().move(velocity);
	CheckScreenEdge();
	//std::cout << "Calling projectile::Update" << std::endl;

	//window.draw(GetShape());
}

void Projectile::CheckScreenEdge()
{
	//horizontal
	if (leftBox() < 0){
		velocity.x = -velocity.x;
	}

	if (rightBox() > WINDOW_WIDTH){
		velocity.x = -velocity.x;
	}

	//vertical
	if (topBox() < 0) {
		velocity.y = -velocity.y;
	}

	if (botBox() > WINDOW_HEIGHT) {
		velocity.y = -velocity.y;
	}
}

///getter methods for collision
float Projectile::xPos(){
	return GetShape().getPosition().x;
}

float Projectile::yPos(){
	return GetShape().getPosition().y;
}

float Projectile::leftBox(){
	return xPos() - (GetShape().getSize().x / 2.f);
}

float Projectile::rightBox(){
	return xPos() + (GetShape().getSize().x / 2.f);
}

float Projectile::topBox(){
	return yPos() - (GetShape().getSize().y / 2.f);
}

float Projectile::botBox(){
	return yPos() + (GetShape().getSize().y / 2.f);
}
*/