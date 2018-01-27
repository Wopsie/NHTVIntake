#pragma once
#include <SFML\Window.hpp>
#include <functional>
#include <vector>
#include <SFML\Graphics.hpp>
#include "DrawableObj.h"
#include "Projectile.h"
//screen resolution
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;

//global "list" for everything that needs to be done each frame
extern std::vector<std::function<void()>> updateList;
extern std::vector<DrawableObj> objList;
extern std::vector<Projectile> projectileList;

struct Globals {
	int AddToUpdateList(std::function<void()>);
	void AddToObjList(DrawableObj&);
	void AddProjectile(Projectile&);
};
