#include "Globals.h"
#include <iostream>
#include <SFML\Graphics.hpp>

std::vector<std::function<void()>> updateList;
std::vector<const sf::Drawable*> drawList;
///add method to update list & return index 
int Globals::AddToUpdateList(std::function<void()> update){
	updateList.push_back(update);
	return updateList.size();
}

void Globals::AddDrawableShape(const sf::Drawable &drawable){
	drawList.push_back(&drawable);
}

/*
void Globals::AddDrawable(sf::Drawable * shape){
	drawables.push_back(*shape);
}
*/