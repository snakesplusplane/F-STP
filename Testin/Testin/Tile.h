#pragma once

#include <SFML\Graphics.hpp>

class Tile
{
private:
	sf::Sprite baseSprite;
public:
	Tile(sf::Image& image);
	~Tile();

	void Draw(int x, int y, sf::RenderWindow* rw);
};