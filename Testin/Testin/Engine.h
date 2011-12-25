#pragma once

#include <SFML\Graphics.hpp>
#include "ImageManager.h"
#include "Tile.h"
#include "Camera.h"
#include "Graph.h"

class Engine
{
private:
	sf::RenderWindow* window;
	ImageManager imageManager;
	Camera* camera;
	Graph* graph;
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