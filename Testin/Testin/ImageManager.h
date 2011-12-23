#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

class ImageManager
{
private:

	std::vector<sf::Image> imgList;

public:
	ImageManager();
	~ImageManager();

	void AddImage(sf::Image& image);
	sf::Image& getImage(int index);
};