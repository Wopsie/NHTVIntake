#include "Globals.h"
#include <iostream>

std::vector<std::function<void()>> updateList;
std::vector<DrawableObj> objList;
std::vector<Projectile> projectileList;

///add method to update list & return index 
int Globals::AddToUpdateList(std::function<void()> update){
	updateList.push_back(update);
	return updateList.size();
}
void Globals::AddToObjList(DrawableObj & objref){
	objList.push_back(objref);
}

void Globals::AddProjectile(Projectile & bullet){
	projectileList.push_back(bullet);
}
