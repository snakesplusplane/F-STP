#pragma once
#include <SFML\Graphics.hpp>
#include "Tile.h"

class Camera
{
private:

	struct myRect
	{
		int X, Y, Width, Height;

		myRect(int inX, int inY, int inWidth, int inHeight)
		{
			X = inX;
			Y = inY;
			Width = inWidth;
			Height = inHeight;
		}
	};
	sf::Vector2f position;
	sf::Vector2f target;
	sf::Vector2i size;
	float speed;

	//myRect viewing;

public: 
	Camera(int w, int h, float inSpeed);
	~Camera();
	void Move(int x, int y);
	void MoveCenter(int x, int y);
	void MoveTowards(int x, int y);
	void MoveCenterTowards(int x, int y);

	void Update();

	sf::Vector2i GetPosition(){return sf::Vector2i((int)position.x, (int)position.y);}
	//sf::Vector2i GetSize(){return sf::Vector2i( (int)viewing.Width, (int)viewing.Height);}
	sf::Vector2i GetTileOffset(int tileSize) {return sf::Vector2i((int)position.x % tileSize, (int)position.y % tileSize);}

	sf::IntRect GetTileBounds(int tileSize);

};