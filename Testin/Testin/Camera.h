#pragma once
#include <SFML\Graphics.hpp>
#include "Tile.h"

class Camera
{
private:
	sf::Vector2f position;
	sf::Vector2f target;
	sf::Vector2i size;
	float speed;

public: 
	Camera(int w, int h, float inSpeed);
	~Camera();
};