#pragma once

#include <SFML\Graphics.hpp>
#include "ImageManager.h"
#include "Tile.h"

class Engine
{
private:
	sf::RenderWindow* window;
	ImageManager imageManager;
	void LoadImages();
	Tile* testTile;
	bool Init();
	void MainLoop();
	void RenderFrame();
	void ProcessInput();
	void Update();

public:
	Engine();
	~Engine();
	void Start();
};