#include "ImageManager.h"
#include <vector>
#include <SFML\Graphics.hpp>

ImageManager::ImageManager(){}
ImageManager::~ImageManager(){}

void ImageManager::AddImage(sf::Image& image)
{
	imgList.push_back(image);
}

sf::Image& ImageManager::getImage(int index)
{
	return imgList[index];
}