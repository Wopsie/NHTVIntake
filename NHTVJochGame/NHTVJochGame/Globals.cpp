#include "Globals.h"
#include <iostream>

std::vector<std::function<void()>> updateList;
std::vector<Projectile> projectileList;
std::vector<Enemy> enemyList;
int gameState;
int score;
bool playerWon;

/*
///add method to update list & return index 
int Globals::AddToUpdateList(std::function<void()> update){
	updateList.push_back(update);
	return updateList.size();
}*/

void Globals::AddProjectile(Projectile & bullet){
	projectileList.push_back(bullet);
}

void Globals::AddEnemy(Enemy & enemy){
	enemyList.push_back(enemy);
}

void Globals::GameOver(bool win){
	//set to gameover state
	gameState = 2;
	//clear enemies
	for (size_t i = 0; i < enemyList.size(); i++){
		enemyList[i].Kill();
	}
	//clear projectiles
	for (size_t i = 0; i < projectileList.size(); i++){
		projectileList[i].Kill();
	}
	//clear updatelist
	updateList.clear();
	playerWon = win;
}

void Globals::AddScore(){
	score += 100;
}

void Globals::ResetScore(){
	score = 0;
}

