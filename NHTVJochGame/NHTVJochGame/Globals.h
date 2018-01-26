#pragma once
#include <functional>
#include <vector>
#include <SFML\Graphics.hpp>
//screen resolution
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;

//global "list" for everything that needs to be done each frame
extern std::vector<std::function<void()>> updateList;
extern std::vector<const sf::Drawable*> drawList;
extern std::vector<sf::RectangleShape> drawables;


struct Globals {
	int AddToUpdateList(std::function<void()>);
	void AddDrawableShape(const sf::Drawable &drawable);
	void AddDrawable(const sf::Drawable *shape);
	void AddRectangle(sf::RectangleShape * rectShape);
};
