#include "Globals.h"
#include <iostream>
#include <SFML\Graphics.hpp>

std::vector<std::function<void()>> updateList;
std::vector<const sf::Drawable*> drawList;
std::vector<sf::RectangleShape> drawables;
///add method to update list & return index 
int Globals::AddToUpdateList(std::function<void()> update){
	updateList.push_back(update);
	return updateList.size();
}

void Globals::AddDrawableShape(const sf::Drawable &drawable){
	drawList.push_back(&drawable);
}


void Globals::AddDrawable(const sf::Drawable *shape){
	//drawables.push_back(*shape);
}

void Globals::AddRectangle(sf::RectangleShape * rectShape){
	drawables.push_back(*rectShape);
}
