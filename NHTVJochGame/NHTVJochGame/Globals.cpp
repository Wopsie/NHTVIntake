#include "Globals.h"
#include <iostream>

std::vector<std::function<void()>> updateList;

///add method to update list & return index 
int Globals::AddToUpdateList(std::function<void()> update){
	updateList.push_back(update);
	return updateList.size();
}

void Globals::AddToDrawList(std::function<sf::RectangleShape()> shape){
	drawList.push_back(shape);
}