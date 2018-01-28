#include "Globals.h"
#include <iostream>

std::vector<std::function<void()>> updateList;
std::vector<DrawableObj> objList;
std::vector<Projectile> projectileList;
std::vector<Enemy> enemyList;
int gameState;
int score;
bool playerWon;

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

void Globals::AddEnemy(Enemy & enemy){
	enemyList.push_back(enemy);
}

void Globals::GameOver(bool win, int score){
	gameState = 2;
	enemyList.clear();
	projectileList.clear();
	objList.clear();
	updateList.clear();
	if (win) {
		//You won! 
		//display score
		//go back to start on button press
		cout << "You won!" << endl;
		playerWon = true;
	}else{
		//You lost
		//display score
		//go back to start on button press
		cout << "You lost :(" << endl;
		playerWon = false;
	}
}

void Globals::AddScore(){
	score += 100;
}

void Globals::ResetScore(){
	score = 0;
}

