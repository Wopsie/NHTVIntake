#pragma once
#include <SFML\Window.hpp>
#include <functional>
#include <vector>
#include <SFML\Graphics.hpp>
#include "DrawableObj.h"
#include "Projectile.h"
#include "Enemy.h"
//screen resolution
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr double PI = 3.14159265358979323846;

//global "list" for everything that needs to be done each frame
extern std::vector<std::function<void()>> updateList;
extern std::vector<DrawableObj> objList;
extern std::vector<Projectile> projectileList;
extern std::vector<Enemy> enemyList;

struct Globals {
	int AddToUpdateList(std::function<void()>);
	void AddToObjList(DrawableObj&);
	void AddProjectile(Projectile&);
	void AddEnemy(Enemy&);
};
