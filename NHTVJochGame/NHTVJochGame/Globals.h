#pragma once
#include <functional>
#include <vector>
#include <SFML\Graphics.hpp>
//screen resolution
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;

//global "lists" for everything that needs to be done each frame
extern std::vector<std::function<sf::RectangleShape()>> drawList;
extern std::vector<std::function<void()>> updateList;

struct Globals {
	int AddToUpdateList(std::function<void()>);
	void AddToDrawList(std::function<sf::RectangleShape()>);
};
