#include "Tile.h"
#include <SFML\Graphics.hpp>

Tile::Tile(sf::Image& image)
{
	baseSprite.SetImage(image);
}

Tile::~Tile(){}

void Tile::Draw(int x, int y, sf::RenderWindow* rw)
{
	baseSprite.SetPosition(x,y);
	rw->Draw(baseSprite);
}