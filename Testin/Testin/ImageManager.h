#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

class ImageManager
{
private:
	int tileSize;
	std::vector<sf::Image> imgList;

public:
	ImageManager();
	~ImageManager();

	void setTileSize(int tileSize) { this->tileSize = tileSize; }

	void AddImage(sf::Image& image);
	sf::Image& getImage(int index);
};